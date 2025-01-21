package ParseIOP;

use strict;
use warnings;

# Add Perl module directory to include path
BEGIN
{
   use File::Spec;
   my ($volume,$directories,$file) = File::Spec->splitpath(File::Spec->rel2abs($0));
   unshift(@INC, File::Spec->catfile($volume, $directories));
}

use StandardObjects;

use Exporter 'import';
our @ISA = 'Exporter';
our @EXPORT = ('ParseHeader', 'ParseIOP', 'CombineIOPs', 'SortObjects', 'GetAuxFunctionNames');

my %ObjectInfo;

sub SortObjects_Recursive($$$$$);
sub AddUserDefinedFields($$);


################################################################################
#
# \details  Subroutine ensures that %ObjectInfo is populated
#
################################################################################
sub LoadObjectInfo()
{
   # if %ObjectInfo isn't already populated
   if(scalar(keys(%ObjectInfo)) == 0)
   {
      # If there is a ProprietaryObjects package (in ProprietaryObjects.pm)
      # then use that package. If it doesn't exist the script will not try to
      # use it.
      my $proprietaryObjects = eval "use ProprietaryObjects; 1" ? 1 : 0;

      our @proprietary_types;

      # Install standard type parsers
      foreach my $typeref (@standard_types)
      {
         $ObjectInfo{$typeref->{type}} = {'Parser'      => $typeref->{'parser'},
                                          'ScalingType' => $typeref->{'scaling'},
                                          'Function'    => $typeref->{'function'}};
      }

      # Install proprietary type parsers if available
      if($proprietaryObjects && @proprietary_types)
      {
         foreach my $typeref (@proprietary_types // ())
         {
            $ObjectInfo{$typeref->{type}} = {'Parser'      => $typeref->{'parser'},
                                             'ScalingType' => $typeref->{'scaling'},
                                             'Function'    => $typeref->{'function'}};
         }
      }
   }
}


################################################################################
#
# \details  Subroutine reads rest of input into unknown object
#
################################################################################
sub UnknownObject($$$)
{
   my ($object_id, $type, $file) = @_;

   my $output;
   my $buffer;
   my @references;

   $output .= pack('vC', $object_id, $type);

   # Get the remainder of the file up to 100 bytes at a time
   while(read($file, $buffer, 100) != 0)
   {
      # Add read data to output and increment length
      $output .= $buffer;
   }

   # Cause length() to return size in bytes
   use bytes;

   return { 'raw'       => $output,
            'refs'      => \@references,
            'type'      => $type,
	         'length'    => length($output)
          };
}


################################################################################
#
# \details  Subroutine parses iop.h file into hash of define names
#
# \param  $iop_file  Input stream containing IOP.h data to parse
#
################################################################################
sub ParseHeader($)
{
   my ($h_file) = @_;
   my %defines;

   # Parse the IOP.h file
   foreach my $line (<$h_file>)
   {
      # Remove newline and carriage return characters
      $line =~ s/[\r\n]//g;

      # Skip blank lines && such
      if($line !~ /#define[ \t]+([A-Za-z_][A-Za-z0-9_]*)[ \t]+(.*)[ \t]*/)
      {
         next;
      }

      # Split into parts
      my ($null, $define, $value) = split(/#define[ \t]+([A-Za-z_][A-Za-z0-9_]*)[ \t]+([\r\n -\.0-~\xa0-\xff]*)[ \t]*/, $line);

      # Add key/value pair
      $defines{$define} = $value;
   }

   return \%defines;
}


################################################################################
#
# \details  Subroutine parses iop file into hash of objects (by object_id)
#
# \param  $iop_file  Input stream containing IOP data to parse
#
################################################################################
sub ParseIOP($)
{
   my ($iop_file) = @_;
   my %objects;
   my $buf;

   # Ensure that ObjectInfo is populated before processing
   LoadObjectInfo();

   # Parse the IOP file
   # Read the first three bytes of the object so the correct parser can be called
   while(read($iop_file, $buf, 3) != 0)
   {
      my ($object_id, $type) = unpack('vC', $buf);
      # If the object type is known call the correct parser
      if(defined $ObjectInfo{$type}->{'Parser'})
      {
         $objects{$object_id} = $ObjectInfo{$type}->{'Parser'}->($object_id, $type, $iop_file);
      }
      # Otherwise treat the rest of the file as an unknown object
      else
      {
         $objects{$object_id} = UnknownObject($object_id, $type, $iop_file);
      }
   }

   return \%objects;
}


# Sort objects into the different scaling bins
################################################################################
#
# \details  Subroutine organizes objects into scaling "bins"
#
# \param  $objects  scalar value returned from ParseIOP
#
################################################################################
sub SortObjects($$$)
{
   my ($objects, $container, $fields) = @_;
   my $scaling_type;

   # For each object in the hash
   foreach my $object_id (keys %$objects)
   {
      # Determine the scaling type (bin)
      my $scaling_type = $ObjectInfo{$objects->{$object_id}->{'type'}}->{'ScalingType'};

      # Sort object recursively
      SortObjects_Recursive($objects, $objects->{$object_id}, $container, $scaling_type, $fields);
   }
}

################################################################################
#
# \details  Subroutine recursively adds user defined fields to hash
#
# \param  $hash    Hash reference of location to add fields
# \param  $fields  Hash reference to field key/value pairs to add to hash
#
################################################################################
sub AddUserDefinedFields($$)
{
   my ($hash, $fields) = @_;

   if(ref($fields) eq 'HASH')
   {
      foreach my $key (keys %$fields)
      {
         # If the key is not yet created for this object
         if(!(exists $hash->{$key}))
         {
            # Create an empty hash reference for the object
            $hash->{$key} = {};
         }

         # Add the given key/value pair
         AddUserDefinedFields($hash->{$key}, $fields->{$key});
      }
   }
   else
   {
      $hash = $fields;
   }
}


#####################################################
##  SortObjects_Recursive
#####################################################
##  Subroutine sorts objects into different scaling
##  parts.
#####################################################
sub SortObjects_Recursive($$$$$)
{
   my ($objects, $object, $container, $scaling_type, $fields) = @_;

   # If the object hasn't already been categorized
   if(!(exists $container->{$object->{'raw'}}))
   {
      # Create an empty hash reference for the object
      $container->{$object->{'raw'}} = {};
      # Create an empty hash reference for the object scaling type(s)
      $container->{$object->{'raw'}}->{'ScalingType'} = {};
      # Create an self reference
      $container->{$object->{'raw'}}->{'Object'} = $object;
   }

   # Add user-defined fields
   AddUserDefinedFields($container->{$object->{'raw'}}, $fields);

   # If the scaling type did not change
   if( ($scaling_type ne 'Parent')                                            &&
       ( ($ObjectInfo{$object->{'type'}}->{'ScalingType'} eq 'Parent')      ||
         ($ObjectInfo{$object->{'type'}}->{'ScalingType'} eq $scaling_type) ) )
   {
      # Add the scaling type
      $container->{$object->{'raw'}}->{'ScalingType'}->{$scaling_type} = 1;

      # Recursive call to scale child objects
      foreach my $object_id (@{$object->{'refs'}})
      {
         if($object_id != hex('FFFF'))
         {
            SortObjects_Recursive($objects, $objects->{$object_id}, $container, $scaling_type, $fields);
         }
      }
   }
}

################################################################################
#
#  \details  Subroutine combines a list of IOP files into one IOP file (where
#            the last item in the list overwrites any previous objects with
#            identical object IDs).
#
################################################################################
sub CombineIOPs(@)
{
   my @iop_files = @_;

   my %combined_iop;

   # For each IOP file
   foreach my $iop_file (@iop_files)
   {
      # Copy each object ID into the combined file
      foreach my $object_id (keys %$iop_file)
      {
         # Copy the contents of each object
         $combined_iop{$object_id} = $iop_file->{$object_id};
      }
   }

   return \%combined_iop;
}

################################################################################
#
#  \details  Subroutine takes Object Type and Function Type and returns a hash
#            reference containing a `Status` and `SetValue` keys.
#
################################################################################
sub GetAuxFunctionNames($$)
{
   my ($object_type, $function_type) = @_;

   return $ObjectInfo{$object_type}->{'Function'}->{$function_type};
}


1;