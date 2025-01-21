#!/usr/bin/perl
################################################################################
#
#  File:  ConvertIOP.pl
#
#  Description:  This script parses a binary .iop file and the associated .iop.h
#                file that contains defines that name objects by object ID and
#                outputs a file containing all object pool data in the structures
#                required by the VTClient library.
#
#  Copyright (C) 2014  DISTek Integration, Inc.  All Rights Reserved.
#
################################################################################
use strict;
use warnings;

BEGIN
{
   use File::Spec;
   my ($volume,$directories,$file) = File::Spec->splitpath(File::Spec->rel2abs($0));
   unshift(@INC, File::Spec->catfile($volume, $directories));
}

use ParseIOP;
use IO::Handle qw();
use Getopt::Long;

sub ParseHeadersByGrouping(@);
sub ParseInputFileFormat($);
sub ParseFilesIntoGrouping(@);
sub CombineIntoFullPools($);
sub ConvertRawToHex($);


my @InputFiles;
my $OutputFile;
my @GroupingHeaders;
my $Label = "Label";
my $DefaultLanguage = "en";
my $MaxArraySize;
my $ByteSize = 8;
my $ModelID;
my $Debug;
my $Help;

my $USAGE = "ConvertIOP.pl options:\n" .
            "   -i=[<grouping>|][<language>:]<input_filename>\n" .
            "      Input .iop files with optional grouping and language info\n" .
            "         examples:  -i=\"200|en:MyFile.iop\"\n" .
            "                    -i=\"de:MyFile_de.iop\"\n\n" .
            "   -o=<output_filename>\n" .
            "      Output filename prefix.  The .c and .h will be added automatically\n" .
            "         example:   -o=App1_ObjectPool\n\n" .
            "   -g=[<grouping>|]<define_file>\n" .
            "      File containing #defines for the object IDs in the .iop files\n" .
            "         examples:  -g=\"200|MyFile.iop.h\"\n" .
            "                    -g=MyFile.iop.h\n\n" .
            "   -l=<label>\n" .
            "      Label to prefix all variables with\n" .
            "         default:  Label\n" .
            "         example:   -l=App1\n\n" .
            "   -d=<default_language>\n" .
            "      Default Language to use when VT reports unsupported language code\n" .
            "         default:  en\n" .
            "         example:   -d=de\n\n" .
            "   -s=<maximum_array_size>\n" .
            "      Maximum array size.  Used to limit individual arrays to support locating in 16-bit compilers.\n" .
            "         default:  no limit\n" .
            "         example:   -s=65536\n\n" .
#            "   -b=<bits_per_byte>\n" .
#            "      Number of bits per byte\n" .
#            "         default:  8\n\n" .
            "   -m=<model_id>\n" .
            "      Proprietary model_id used for unique auxiliary input controller identification.\n" .
            "         example:  -m=0x01EF\n\n" .
            "   -? or --help\n" .
            "      Display the script usage\n";

# Parse the options
GetOptions('i=s'    => \@InputFiles,
           'o=s'    => \$OutputFile,
           'g=s'    => \@GroupingHeaders,
           'l=s'    => \$Label,
           'd=s'    => \$DefaultLanguage,
           's=i'    => \$MaxArraySize,
           'b=i'    => \$ByteSize,
           'm=s'    => \$ModelID,
           'help|?' => \$Help);

# If there are unrecognized parameters
if(scalar @ARGV)
{
   # Notify the user
   print "\nThe following parameters were not recognized:\n   " . join("\n   ", @ARGV) . "\n\n";
   print "Pass -? for script usage\n";
   exit(1);
}

if( ($Help)                    ||
    (!defined($OutputFile))    ||
    (scalar(@InputFiles) == 0) )
{
   die $USAGE;
}

# If the output file is specified
open my $c_file, '>', $OutputFile . ".c" or die "Could not open $OutputFile.c\n";
open my $h_file, '>', $OutputFile . ".h" or die "Could not open $OutputFile.h\n";


# Parse grouping header files
my $Define_Groupings = ParseHeadersByGrouping(@GroupingHeaders);

# Parse the files into the user-defined groupings
my $IOP_Groupings = ParseFilesIntoGrouping(@InputFiles);
my %Groupings;
my %Languages;
my %Defines;

# Combine the files in each grouping
foreach my $grouping (keys %{$IOP_Groupings})
{
   # Combine into full pools for each language
   CombineIntoFullPools($IOP_Groupings->{$grouping});
}

# Associate define names to the corresponding Object IDs
foreach my $grouping (keys %{$Define_Groupings})
{
   # If there is a matching IOP grouping name
   if(exists $IOP_Groupings->{$grouping})
   {
      # Associate define names for each language in the grouping
      foreach my $language (keys %{$IOP_Groupings->{$grouping}})
      {
         # Associate the define name to the corresponding Object ID
         foreach my $define (keys %{$Define_Groupings->{$grouping}->{''}->{'Defines'}})
         {
            # Ignore known non-object_id defines
            if( ($define ne "ISO_DESIGNATOR_WIDTH")  &&
                ($define ne "ISO_DESIGNATOR_HEIGHT") &&
                ($define ne "ISO_MASK_SIZE")         &&
                ($define ne "ISO_VERSION_LABEL")     &&
                ($define ne "MASK_WIDTH")            &&
                ($define ne "MASK_HEIGHT")           )
            {
               $Defines{$define} = $Define_Groupings->{$grouping}->{''}->{'Defines'}->{$define};
               # If the Object ID in the define is found in the .iop file
               if(exists $IOP_Groupings->{$grouping}->{$language}->{"Objects"}->{$Define_Groupings->{$grouping}->{''}->{'Defines'}->{$define}})
               {
                  # Associate the define name to the object ID
                  $IOP_Groupings->{$grouping}->{$language}->{"Objects"}->{$Define_Groupings->{$grouping}->{''}->{'Defines'}->{$define}}->{'define'} = $define;
               }
            }
         }
      }
   }
}

# Mark unique objects according to scaling type, grouping, and language.
my %Container;
foreach my $grouping (keys %{$IOP_Groupings})
{
   my $group = $IOP_Groupings->{$grouping};
   $Groupings{$grouping} = 1;

   foreach my $language (keys %{$group})
   {
      $Languages{$language} = 1;
      SortObjects($IOP_Groupings->{$grouping}->{$language}->{"Objects"}, \%Container, {'Groupings' => {$grouping => 1}, 'Languages' => {$language => 1}});
   }
}

# Error checking
# \todo  Add way to specify scaling type on command line
foreach my $object (keys %Container)
{
   # Check for multiple scaling types
   if(scalar(keys %{$Container{$object}->{'ScalingType'}}) > 1)
   {
      my $object_id = $Container{$object}->{'Object'}->{'object_id'};
      print STDERR "Multiple scaling types required for Object ID: $object_id.  Applying no scaling.\n";
      $Container{$object}->{'ScalingType'} = {'None' => 1};
   }
   # Check for unscaled objects
   elsif(scalar(keys %{$Container{$object}->{'ScalingType'}}) == 0)
   {
      my $object_id = $Container{$object}->{'Object'}->{'object_id'};
      print STDERR "Unreferenced object. Object ID: $object_id.  Applying no scaling.\n";
      $Container{$object}->{'ScalingType'} = {'None' => 1};
   }
}

# Break into Object Pool parts
my %ObjectPoolParts;
my $AllGroupings = join("|", sort {$a cmp $b} keys %Groupings) . "|";
my $AllLanguages = join(":", sort {$a cmp $b} keys %Languages) . ":";
foreach my $object (keys %Container)
{
   my $groupings = $Container{$object}->{'Groupings'};
   my $languages = $Container{$object}->{'Languages'};
   my $scaling_type = $Container{$object}->{'ScalingType'};

   # Determine groupings
   my $temp = join("|", sort {$a cmp $b} keys %{$groupings}) . "|";
   if($AllGroupings eq $temp)
   {
      $temp = "";
      $groupings = {};
   }
   my $key = $temp;

   # Determine languages
   $temp = join(":", sort {$a cmp $b} keys %{$languages}) . ":";
   if($AllLanguages eq $temp)
   {
      $temp = "";
      $languages = {};
   }
   $key .= $temp;

   # Add scaling type to key
   $key .= join("?", keys %{$scaling_type});

   # If the key is not yet created for this object
   if(!(exists $ObjectPoolParts{$key}))
   {
      # Create an empty hash reference for the object
      $ObjectPoolParts{$key} = {'Objects'     => {},
                                'Length'      => 0,
                                'Groupings'   => $groupings,
                                'Languages'   => $languages,
                                'ScalingType' => "ScaleFactor_" . join("", keys %{$scaling_type})};
#      $ObjectPoolParts{$key} = {'Raw'         => "",
#      $ObjectPoolParts{$key} = "";
   }

   if($ByteSize == 8)
   {
      # Store raw data independently (allows for commenting each raw-data entry
      $ObjectPoolParts{$key}->{'Objects'}->{$Container{$object}->{'Object'}->{'object_id'}} = $Container{$object};
   }
   else
   {
      # Combine all raw data to simplify printing array
      $ObjectPoolParts{$key}->{'Raw'} .= $Container{$object}->{'Object'}->{'raw'};
   }
   $ObjectPoolParts{$key}->{'Length'} += $Container{$object}->{'Object'}->{'length'};
}


# Print the C file header
print $c_file "/******************************************************************************/\n";
print $c_file "/*\n";
print $c_file "   WARNING:  This file is auto-generated using ConvertIOP.pl.  Any modifications\n";
print $c_file "             to this file will be overwritten the next time the script is run.\n";
#print $c_file "\n";
#print $c_file "   This file contains Object Pool data in the following groupings:\n";
#my @grouping_text;
#foreach my $grouping (keys %{$IOP_Groupings})
#{
#   my $file_text = "";
#   $file_text .= "      Grouping " . $grouping . " contains the following files:\n";
#   foreach my $language (keys %{$IOP_Groupings->{$grouping}})
#   {
#      $file_text .= "         " . $language . " => " . $IOP_Groupings->{$grouping}->{$language}->{'Filename'} . "\n";
#   }
#   push(@grouping_text, $file_text);
#}
#print $c_file join("\n", @grouping_text);
print $c_file "*/\n";
print $c_file "/******************************************************************************/\n\n\n";
print $c_file "#include \"Platform.h\"\n";
print $c_file "#include \"Foundation.h\"\n";
print $c_file "#include \"VTClient.h\"\n";
print $c_file "#include \"$OutputFile.h\"\n\n\n";


# Print the H file header
print $h_file "/******************************************************************************/\n";
print $h_file "/*\n";
print $h_file "   WARNING:  This file is auto-generated using ConvertIOP.pl.  Any modifications\n";
print $h_file "             to this file will be overwritten the next time the script is run.\n";
print $h_file "*/\n";
print $h_file "/******************************************************************************/\n\n\n";

# Print the Object ID #defines to the H file
print $h_file "// Named defines for Object Pool objects:\n";
foreach my $define (sort {$Defines{$a} <=> $Defines{$b}} keys %Defines)
{
   print $h_file sprintf("#define %-40s ((ObjectID_T)%5s)\n", $define, $Defines{$define});
}
print $h_file "\n\n";


# Output object pool part arrays
foreach my $object_pool_part (sort {$a cmp $b} keys %ObjectPoolParts)
{
   my $variable_name = $object_pool_part;
   my $scaling_type = $ObjectPoolParts{$object_pool_part}->{'ScalingType'};
   my @part_objects;
   my $length = 0;
   my $index = "";

   # Replace '|'s with '_'s
   $variable_name =~ s/\|/_/g;

   # Replace ':'s with '_'s
   $variable_name =~ s/:/_/g;

   # Prepend with user-defined label
   $variable_name = $Label . '_' . $variable_name . "_array";

   # Create hash reference to store Variable Names and their corresponding sizes
   $ObjectPoolParts{$object_pool_part}->{'VariableName'} = {};

   # If the total length of this object pool part exceeds the MaxArraySize
   if(defined($MaxArraySize) && ($ObjectPoolParts{$object_pool_part}->{'Length'} > $MaxArraySize))
   {
      # Set the index to indicate this
      $index = 0;
   }

   # Print the object pool part array
   if($ByteSize == 8)
   {
      foreach my $object_id (sort {$a<=>$b} keys %{$ObjectPoolParts{$object_pool_part}->{'Objects'}})
      {
         my $define_name = "";
         if(exists $ObjectPoolParts{$object_pool_part}->{'Objects'}->{$object_id}->{'Object'}->{'define'})
         {
            $define_name = " - " . $ObjectPoolParts{$object_pool_part}->{'Objects'}->{$object_id}->{'Object'}->{'define'};
         }

         my @byte_array = ConvertRawToHex($ObjectPoolParts{$object_pool_part}->{'Objects'}->{$object_id}->{'Object'}->{'raw'});

         # If $MaxArraySize is passed in
         if(defined($MaxArraySize))
         {
            # If this object doesn't fit within the $MaxArraySize
            if(scalar(@byte_array) > $MaxArraySize)
            {
               # Notify user and quit
               die "ObjectID: $object_id  Size: " . scalar(@byte_array) . "  is too large to fit within specified Maximum array size: $MaxArraySize\n";
            }

            # If this object doesn't fit within the current object pool part (combined size is > $MaxArraySize)
            if(scalar(@byte_array) + $length > $MaxArraySize)
            {
               # Print this part
               $ObjectPoolParts{$object_pool_part}->{'VariableName'}->{$variable_name . $index} = $length;
               print $c_file "static const MinAddressable_T " . $variable_name . $index . "[] =\n{\n" . join(",\n\n", @part_objects) . "\n};\n\n";
               @part_objects = ();
               $length = 0;
               $index++;
            }
         }
         $length += scalar(@byte_array);

         # Limit line length
         my @byte_array_lines;
         while(scalar @byte_array > 0)
         {
            push(@byte_array_lines, "0x" . join(", 0x", splice(@byte_array, 0, 16)));  # \todo  Should the "16" be a command line parameter?
         }
         push(@part_objects, "   /* " . sprintf("%5d%s", $object_id, $define_name) . " */\n   " . join(",\n   ", @byte_array_lines));
      }
      $ObjectPoolParts{$object_pool_part}->{'VariableName'}->{$variable_name . $index} = $length;
      print $c_file "static const MinAddressable_T " . $variable_name . $index . "[] =\n{\n" . join(",\n\n", @part_objects) . "\n};\n\n";
   }
   else
   {
      die "Script does not yet support non 8-bit devices\n\n";
#      # Get 8-bit bytes
#      my @raw_data = ConvertRawToHex($ObjectPoolParts{$object_pool_part}->{'Objects'}->{'raw'});
#
#      # Convert based on
#      foreach my
#      push(@part_objects, "   /* " . $object_id . " */\n   " . join(", ", ));
   }
}

# Output the Object Pools by object pool grouping
my %Auxiliary_Inputs;
my %Auxiliary_Functions;
# Determine object pool name
my $object_pool_name = $Label;
foreach my $grouping (sort {$a cmp $b} keys %Groupings)
{
   # Determine object pool part name
   my $part_name = $Label;
   if($grouping ne "")
   {
      $object_pool_name .= "_" . $grouping;
      $part_name .= "_" . $grouping;
   }
   $part_name .= "_Parts";

   # Determine parts used by this grouping
   my @object_pool_parts;
   foreach my $object_pool_part (sort {$a cmp $b} keys %ObjectPoolParts)
   {
      # If this part is used for all groupings (blank), or this part is used in this grouping
      if( !(scalar keys %{$ObjectPoolParts{$object_pool_part}->{'Groupings'}})          ||
          (exists ($ObjectPoolParts{$object_pool_part}->{'Groupings'}->{$grouping})) )
      {
         # Determine the variable name and scaling type
         my $scaling_type = $ObjectPoolParts{$object_pool_part}->{'ScalingType'};
         foreach my $variable_name (sort {$a cmp $b} keys %{$ObjectPoolParts{$object_pool_part}->{'VariableName'}})
         {
            # If this is a language part
            if(scalar keys %{$ObjectPoolParts{$object_pool_part}->{'Languages'}})
            {
               # Add language part for each language in which the part is used to the pool
               foreach my $language (sort {$a cmp $b} keys %{$ObjectPoolParts{$object_pool_part}->{'Languages'}})
               {
                  push(@object_pool_parts, "MAKE_ObjectPoolLanguagePart_T(" . $variable_name . ", " . $scaling_type . ", \"" . $language . "\")");
               }
            }
            else
            {
               # Add non-language part to the pool
               push(@object_pool_parts, "MAKE_ObjectPoolPart_T(" . $variable_name. ", " . $scaling_type . ")");
            }
         }
      }
   }

   # Print the grouping parts
   print $c_file "static const ObjectPoolPart_T " . $part_name . "[] =\n{\n   " . join(",\n   ", @object_pool_parts) . "\n};\n\n";

   foreach my $auxiliary_inputs (sort {$a cmp $b} keys %ObjectPoolParts)
   {
      # If this part is used for all groupings (blank), or this part is used in this grouping
      if( !(scalar keys %{$ObjectPoolParts{$auxiliary_inputs}->{'Groupings'}})          ||
          (exists ($ObjectPoolParts{$auxiliary_inputs}->{'Groupings'}->{$grouping})) )
      {
         # Go through objects in object pool
         foreach my $object_id (sort {$a<=>$b} keys %{$ObjectPoolParts{$auxiliary_inputs}->{'Objects'}})
         {
            # Get object id of the auxiliary input
            my $aux_object = $ObjectPoolParts{$auxiliary_inputs}->{'Objects'}->{$object_id}->{'Object'}->{'define'};

            # Convert raw data into hex and splice auxiliary function type out
            my @byte_array = ConvertRawToHex($ObjectPoolParts{$auxiliary_inputs}->{'Objects'}->{$object_id}->{'Object'}->{'raw'});
            my $aux_function_type = hex($byte_array[4]) & 0x0F;

            # Get type of object
            my $object_type = $ObjectPoolParts{$auxiliary_inputs}->{'Objects'}->{$object_id}->{'Object'}->{'type'};

            # Make sure object type is Auxiliary Input Type 2
            if($object_type == 32)
            {
               # Get functions associated to this auxiliary function type
               my $aux_function = GetAuxFunctionNames($object_type, $aux_function_type);
               # Put data into hash
               if(!defined($Auxiliary_Inputs{$object_id}))
               {
                  $Auxiliary_Inputs{$object_id}->{'Object'} = $aux_object;
                  $Auxiliary_Inputs{$object_id}->{'Function_id'} = {};
               }
               $Auxiliary_Inputs{$object_id}->{'Function_id'}->{$aux_function_type} = $aux_function->{'EnumName'};
            }
         }
      }
   }

   foreach my $auxiliary_functions (sort {$a cmp $b} keys %ObjectPoolParts)
   {
      # If this part is used for all groupings (blank), or this part is used in this grouping
      if( !(scalar keys %{$ObjectPoolParts{$auxiliary_functions}->{'Groupings'}})          ||
          (exists ($ObjectPoolParts{$auxiliary_functions}->{'Groupings'}->{$grouping})) )
      {
         # Go through objects in object pool
         foreach my $object_id (sort {$a<=>$b} keys %{$ObjectPoolParts{$auxiliary_functions}->{'Objects'}})
         {
            # Get object id of the auxiliary function
            my $aux_object = $ObjectPoolParts{$auxiliary_functions}->{'Objects'}->{$object_id}->{'Object'}->{'define'};

            # Convert raw data into hex and splice auxiliary function type out
            my @byte_array = ConvertRawToHex($ObjectPoolParts{$auxiliary_functions}->{'Objects'}->{$object_id}->{'Object'}->{'raw'});
            my $aux_function_type = hex($byte_array[4]) & 0x0F;

            # Get type of object
            my $object_type = $ObjectPoolParts{$auxiliary_functions}->{'Objects'}->{$object_id}->{'Object'}->{'type'};

            # Make sure object type is Auxiliary Function Type 2
            if($object_type == 31)
            {
               # Get functions associated to this auxiliary function type
               my $aux_function = GetAuxFunctionNames($object_type, $aux_function_type);
               # Put data into hash
               if(!defined($Auxiliary_Functions{$object_id}))
               {
                  $Auxiliary_Functions{$object_id}->{'Object'} = $aux_object;
                  $Auxiliary_Functions{$object_id}->{'Function_id'} = {};
               }
               $Auxiliary_Functions{$object_id}->{'Function_id'}->{$aux_function_type} = $aux_function->{'EnumName'};
            }
         }
      }
   }
}

# Print out Auxiliaries
if(scalar keys(%Auxiliary_Inputs) > 0)
{
   # Print the auxiliary inputs
   my @aux_input_list;
   my $fail = 0;
   foreach my $auxiliary_inputs (sort keys %Auxiliary_Inputs)
   {
      push(@aux_input_list, "MAKE_AuxiliaryInput_T(" . $Auxiliary_Inputs{$auxiliary_inputs}->{'Object'} . ", " . join('', values %{$Auxiliary_Inputs{$auxiliary_inputs}->{'Function_id'}}) . ")");

      # Determine if there a multiple Auxiliary Inputs with different function types
      if(scalar keys %{$Auxiliary_Inputs{$auxiliary_inputs}->{'Function_id'}} > 1)
      {
         print(STDERR "Object ID '" . $auxiliary_inputs . "' has multiple Function Types: " . join(', ', keys %{$Auxiliary_Inputs{$auxiliary_inputs}->{'Function_id'}}) . "\n");
         $fail = 1;
      }
   }

   # If there were multiple Auxiliary Inputs with different function types
   if($fail)
   {
      # Exit the program
      exit 1;
   }
   print $c_file "static AuxiliaryInput_T " . $object_pool_name . "_AuxiliaryInputs" . "[" . scalar keys(%Auxiliary_Inputs) ."] =\n{\n   " . join(",\n   ", @aux_input_list) . "\n};\n\n";

   # If a model id was not provided
   if(!defined $ModelID)
   {
      # Notify user and quit
      die "ModelID not provided. Must provide a unique model identification.\n";
   }
   # Print the auxiliary input list
   print $c_file "AuxiliaryInputList_T " . $object_pool_name . "_AuxiliaryInputArray = MAKE_AuxiliaryInputList_T(PRIORITY_MAX, " . $object_pool_name . "_AuxiliaryInputs, (ModelIdentificationCode_T)" . $ModelID . ");\n\n";
   # Extern the auxiliary input array
   print $h_file "extern AuxiliaryInput_T " . $object_pool_name . "_AuxiliaryInputs[" . scalar keys(%Auxiliary_Inputs) . "];\n";
   # Extern the auxiliary input list
   print $h_file "extern AuxiliaryInputList_T " . $object_pool_name . "_AuxiliaryInputArray;\n";
}

if(scalar keys(%Auxiliary_Functions) > 0)
{
   my @preferred_assignments;

   # Print the auxiliary functions
   my @aux_function_list;
   my $fail = 0;
   foreach my $auxiliary_functions (sort keys %Auxiliary_Functions)
   {
      # Push data into array
      push(@preferred_assignments, "MAKE_PreferredAssignment_T()");
      push(@aux_function_list, "MAKE_AuxiliaryFunction_T(" . $Auxiliary_Functions{$auxiliary_functions}->{'Object'} . ", " . join('', values %{$Auxiliary_Functions{$auxiliary_functions}->{'Function_id'}}) . ")");

      # Determine if there a multiple Auxiliary Functions with different function types
      if(scalar keys %{$Auxiliary_Functions{$auxiliary_functions}->{'Function_id'}} > 1)
      {
         print(STDERR "Object ID '" . $auxiliary_functions . "' has multiple Function Types: " . join(', ', keys %{$Auxiliary_Functions{$auxiliary_functions}->{'Function_id'}}) . "\n");
         $fail = 1;
      }
   }

   # If there were multiple Auxiliary Functions with different function types
   if($fail)
   {
      # Exit the program
      exit 1;
   }
   print $c_file "static AuxiliaryFunction_T " . $object_pool_name . "_AuxiliaryFunctions" . "[" . scalar keys(%Auxiliary_Functions) ."] =\n{\n   " . join(",\n   ", @aux_function_list) . "\n};\n\n";
   # Print the preferred assignment list
   print $c_file "static PreferredAssignment_T " . $object_pool_name . "_PreferredAssignment" . "[" . scalar keys(%Auxiliary_Functions) ."] =\n{\n   " . join(",\n   ", @preferred_assignments) . "\n};\n\n";
   # Print the auxiliary function list
   print $c_file "AuxiliaryFunctionList_T " . $object_pool_name . "_AuxiliaryFunctionArray = MAKE_AuxiliaryFunctionList_T(PRIORITY_MAX, " . $object_pool_name . "_AuxiliaryFunctions, " . $object_pool_name . "_PreferredAssignment" . ");\n\n";
   # Print the auxiliary function list
   print $h_file "extern AuxiliaryFunctionList_T " . $object_pool_name . "_AuxiliaryFunctionArray;\n\n";
}

# Output the Object Pools by object pool grouping
foreach my $grouping (sort {$a cmp $b} keys %Groupings)
{
   # Determine object pool name
   my $object_pool_name = $Label;
   if($grouping ne "")
   {
      $object_pool_name .= "_" . $grouping;
   }
   my $part_name = $object_pool_name . "_Parts";

   # Local variables for storing values for object pools
   my $ISO_MASK_SIZE         = "ISO_MASK_SIZE";
   my $ISO_DESIGNATOR_WIDTH  = "ISO_DESIGNATOR_WIDTH";
   my $ISO_DESIGNATOR_HEIGHT = "ISO_DESIGNATOR_HEIGHT";
   my $ISO_VERSION_LABEL     = "ISO_VERSION_LABEL";

   # Use iop.h values for each grouping (if available)
   if(exists $Define_Groupings->{$grouping}->{''}->{'Defines'}->{'ISO_MASK_SIZE'})
   {
      $ISO_MASK_SIZE = $Define_Groupings->{$grouping}->{''}->{'Defines'}->{'ISO_MASK_SIZE'};
   }
   if(exists $Define_Groupings->{$grouping}->{''}->{'Defines'}->{'ISO_DESIGNATOR_WIDTH'})
   {
      $ISO_DESIGNATOR_WIDTH = $Define_Groupings->{$grouping}->{''}->{'Defines'}->{'ISO_DESIGNATOR_WIDTH'};
   }
   if(exists $Define_Groupings->{$grouping}->{''}->{'Defines'}->{'ISO_DESIGNATOR_HEIGHT'})
   {
      $ISO_DESIGNATOR_HEIGHT = $Define_Groupings->{$grouping}->{''}->{'Defines'}->{'ISO_DESIGNATOR_HEIGHT'};
   }
   if(exists $Define_Groupings->{$grouping}->{''}->{'Defines'}->{'ISO_VERSION_LABEL'})
   {
      $ISO_VERSION_LABEL = $Define_Groupings->{$grouping}->{''}->{'Defines'}->{'ISO_VERSION_LABEL'};
   }

   # If there are multiple languages
   if((scalar keys %Languages) > 1)
   {
      # Print the language pool
      print $c_file "ObjectPool_T " . $object_pool_name . "_ObjectPool = MAKE_ObjectPoolLanguage_T(" . $part_name . ", " . $ISO_MASK_SIZE . ", " . $ISO_DESIGNATOR_WIDTH . ", " . $ISO_DESIGNATOR_HEIGHT . ", " . $ISO_VERSION_LABEL . ", \"" . $DefaultLanguage . "\");\n";
   }
   else
   {
      # Print the object pool
      print $c_file "ObjectPool_T " . $object_pool_name . "_ObjectPool = MAKE_ObjectPool_T(" . $part_name . ", " . $ISO_MASK_SIZE . ", " . $ISO_DESIGNATOR_WIDTH . ", " . $ISO_DESIGNATOR_HEIGHT . ", " . $ISO_VERSION_LABEL . ");\n";
   }
   # Extern the pool
   print $h_file "extern ObjectPool_T " . $object_pool_name . "_ObjectPool;\n";

}


# Close the output files
close $c_file;
close $h_file;

print STDERR "Conversion complete.\n";


################################################################################
#
#  \details  Subroutine parses the input file syntax into its parts
#
################################################################################
sub ParseInputFileFormat($)
{
   my ($input_file) = @_;

   my $index;
   my $iop_grouping = "";
   my $language = "";

   # Determine IOP grouping (if any)
   $index = index($input_file, "|");
   if($index >= 0)
   {
      $iop_grouping = substr($input_file, 0, $index);
      $input_file = substr($input_file, $index+1);
   }

   # Determine Language (if any)
   $index = index($input_file, ":");
   if($index >= 0)
   {
      $language = substr($input_file, 0, $index);
      $input_file = substr($input_file, $index+1);
   }

   return ($iop_grouping, $language, $input_file);
}


################################################################################
#
#  \details  Subroutine takes array of input files (raw syntax) and returns
#            hash reference of files parsed into their groupings.
#
################################################################################
sub ParseHeadersByGrouping(@)
{
   my @header_files = @_;

   my %groupings;

   # Parse IOP files into groupings/languages
   foreach my $header_file (@header_files)
   {
      my ($grouping, $language, $filename) = ParseInputFileFormat($header_file);

      # If the grouping doesn't already exist
      if(!(exists $groupings{$grouping}))
      {
         # Define the grouping to point to an empty hash reference
         $groupings{$grouping} = {};
      }

      # If the language doesn't already exist in this grouping (shouldn't)
      if(!(exists $groupings{$grouping}->{$language}))
      {
         # Define the language to point to an empty hash reference
         $groupings{$grouping}->{$language} = {};
      }

      # Parse the input file
      open my $input_filehandle, '<', $filename or die "Could not open $filename\n";
      binmode $input_filehandle;
      $groupings{$grouping}->{$language}->{"Defines"} = ParseHeader($input_filehandle);
      close $input_filehandle;
   }

   return \%groupings;
}


################################################################################
#
#  \details  Subroutine takes array of input files (raw syntax) and returns
#            hash reference of files parsed into their groupings.
#
################################################################################
sub ParseFilesIntoGrouping(@)
{
   my @input_files = @_;

   my %iop_groupings;

   # Parse IOP files into groupings/languages
   foreach my $input_file (@input_files)
   {
      my ($iop_grouping, $language, $filename) = ParseInputFileFormat($input_file);

      # If the grouping doesn't already exist
      if(!(exists $iop_groupings{$iop_grouping}))
      {
         # Define the grouping to point to an empty hash reference
         $iop_groupings{$iop_grouping} = {};
      }

      # If the language doesn't already exist in this grouping (shouldn't)
      if(!(exists $iop_groupings{$iop_grouping}->{$language}))
      {
         # Define the language to point to an empty hash reference
         $iop_groupings{$iop_grouping}->{$language} = {};
      }

      $iop_groupings{$iop_grouping}->{$language}->{"Language"} = $language;
      $iop_groupings{$iop_grouping}->{$language}->{"Filename"} = $filename;

      # Parse the input file
      open my $input_filehandle, '<', $filename or die "Could not open $filename\n";
      binmode $input_filehandle;
      $iop_groupings{$iop_grouping}->{$language}->{"Objects"} = ParseIOP($input_filehandle);
      close $input_filehandle;
   }

   return \%iop_groupings;
}


################################################################################
#
#  \details  Subroutine combines the files in a grouping to make full pools
#            for each language.
#
################################################################################
sub CombineIntoFullPools($)
{
   my ($grouping) = @_;

   my @iop_files;

   # Parse IOP files into groupings/languages
   foreach my $language (keys %{$grouping})
   {
      push(@iop_files, $grouping->{$language}->{"Objects"});
   }

   # Combine all the pools
   my $combined_pool = CombineIOPs(@iop_files);

   # Update each language pool to be a complete pool
   foreach my $language (keys %{$grouping})
   {
      $grouping->{$language}->{"Objects"} = CombineIOPs($combined_pool, $grouping->{$language}->{"Objects"});
   }
}


################################################################################
#
#  \details  Subroutine converts raw binary into list of bytes.
#
################################################################################
sub ConvertRawToHex($)
{
   my ($raw_data) = @_;
   my @converted_data;

   my @nybbles = split(//, unpack('H*', $raw_data));

   while(scalar @nybbles > 0)
   {
      push(@converted_data, join("", splice(@nybbles, 0, 2)));
   }

   return @converted_data;
}

################################################################################
#
#   Copyright (C) 2014  DISTek Integration, Inc.  All Rights Reserved.
#
#   Developed by:
#      DISTek(R) Integration, Inc.
#      6612 Chancellor Drive Suite 600
#      Cedar Falls, IA 50613
#      Tel: 319-859-3600
#
################################################################################
