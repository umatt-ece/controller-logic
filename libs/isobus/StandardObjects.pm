package StandardObjects;

use strict;
use warnings;

use Exporter 'import';
our @ISA = 'Exporter';
our @EXPORT = ('@standard_types');

sub ParseType_0_WorkingSet($$$);
sub ParseType_1_DataMask($$$);
sub ParseType_2_AlarmMask($$$);
sub ParseType_3_Container($$$);
sub ParseType_4_SoftKeyMask($$$);
sub ParseType_5_Key($$$);
sub ParseType_6_Button($$$);
sub ParseType_7_InputBoolean($$$);
sub ParseType_8_InputString($$$);
sub ParseType_9_InputNumber($$$);
sub ParseType_10_InputList($$$);
sub ParseType_11_OutputString($$$);
sub ParseType_12_OutputNumber($$$);
sub ParseType_13_Line($$$);
sub ParseType_14_Rectangle($$$);
sub ParseType_15_Ellipse($$$);
sub ParseType_16_OutputPolygon($$$);
sub ParseType_17_OutputMeter($$$);
sub ParseType_18_LinearBargraph($$$);
sub ParseType_19_ArchedBarGraph($$$);
sub ParseType_20_PictureGraphic($$$);
sub ParseType_21_NumberVariable($$$);
sub ParseType_22_StringVariable($$$);
sub ParseType_23_FontAttributes($$$);
sub ParseType_24_LineAttributes($$$);
sub ParseType_25_FillAttributes($$$);
sub ParseType_26_InputAttributes($$$);
sub ParseType_27_ObjectPointer($$$);
sub ParseType_28_Macro($$$);
sub ParseType_29_AuxFunctionType1($$$);
sub ParseType_30_AuxInputType1($$$);
sub ParseType_31_AuxFunctionType2($$$);
sub ParseType_32_AuxInputType2($$$);
sub ParseType_33_AuxControlDesignatorType2ObjectPointer($$$);
sub ParseType_34_WindowMask($$$);
sub ParseType_35_KeyGroup($$$);
sub ParseType_36_GraphicsContext($$$);
sub ParseType_37_OutputList($$$);
sub ParseType_38_ExtendedInputAttributes($$$);
sub ParseType_39_ColourMap($$$);
sub ParseType_40_ObjectLabelReferenceList($$$);


####################################################
#  B.1  ParseType_0_WorkingSet
####################################################
#  Subroutine to parse Working Set objects
####################################################
sub ParseType_0_WorkingSet($$$)
{
   my $object_id = shift;
   my $type = shift;
   my $file = shift;

   my $output;
   my $buffer;
   my @references;

   # Add 'Object ID' and 'Type' to raw data
   $output .= pack('vC', $object_id, $type);

   # Read the fixed-size data fields ('Background Colour' 'Selectable' 'Active Mask' 'Number of objects to follow' 'Number of macros to follow' and 'Number of languages to follow')
   read($file, $buffer, 7);
   $output .= $buffer;

   # Add 'Active Mask' to references  if the Working Set is selectable
   push(@references, unpack('v', substr($buffer, 2, 2)))  if(unpack('C', substr($buffer, 1, 1)) == 1);

   # Store off copy of values
   my $object_cnt = unpack('C', substr($buffer, 4, 1));
   my $macro_cnt = unpack('C', substr($buffer, 5, 1));
   my $language_cnt = unpack('C', substr($buffer, 6, 1));

   # Determine length of remaining data in this object
   my $length = $object_cnt * 6 + $macro_cnt * 2 + $language_cnt * 2;

   # Read the remaining data
   read($file, $buffer, $length);
   $output .= $buffer;

   # Add Child Objects to references
   while($object_cnt--)
   {
      push(@references, unpack('v', substr($buffer, 0, 2, '')));
      substr($buffer, 0, 4, '');
   }

   # Return hash reference containing pertinent data
   return { 'object_id' => $object_id,
            'raw' => $output,
            'refs' => \@references,
            'type' => $type,
            'length' => length $output
          };
}


####################################################
#  B.2  ParseType_1_DataMask
####################################################
#  Subroutine to parse Data Mask objects
####################################################
sub ParseType_1_DataMask($$$)
{
   my $object_id = shift;
   my $type = shift;
   my $file = shift;

   my $output;
   my $buffer;
   my @references;

   # Add 'Object ID' and 'Type' to raw data
   $output .= pack('vC', $object_id, $type);

   # Read the fixed-size data fields ('Background Colour' 'Soft Key Mask' 'Number of objects to follow' and 'Number of macros to follow')
   read($file, $buffer, 5);
   $output .= $buffer;

   # Add 'Soft Key Mask' to references if not the NULL Object ID
   my $soft_key_mask = unpack('v', substr($buffer, 1, 2));
   push(@references, $soft_key_mask)  if($soft_key_mask != 0xffff);

   # Store off copy of values
   my $object_cnt = unpack('C', substr($buffer, 3, 1));
   my $macro_cnt = unpack('C', substr($buffer, 4, 1));

   # Determine length of remaining data in this object
   my $length = $object_cnt * 6 + $macro_cnt * 2;

   # Read the remaining data
   read($file, $buffer, $length);
   $output .= $buffer;

   # Add Child Objects to references
   while($object_cnt--)
   {
      push(@references, unpack('v', substr($buffer, 0, 2, '')));
      substr($buffer, 0, 4, '');
   }

   # Return hash reference containing pertinent data
   return { 'object_id' => $object_id,
            'raw' => $output,
            'refs' => \@references,
            'type' => $type,
            'length' => length $output
          };
}


####################################################
#  B.3  ParseType_2_AlarmMask
####################################################
#  Subroutine to parse Alarm Mask objects
####################################################
sub ParseType_2_AlarmMask($$$)
{
   my $object_id = shift;
   my $type = shift;
   my $file = shift;

   my $output;
   my $buffer;
   my @references;

   # Add 'Object ID' and 'Type' to raw data
   $output .= pack('vC', $object_id, $type);

   # Read the fixed-size data fields ('Background Colour' 'Soft Key Mask' 'Priority' 'Acoustic signal' 'Number of objects to follow' and 'Number of macros to follow')
   read($file, $buffer, 7);
   $output .= $buffer;

   # Add 'Soft Key Mask' to references if not the NULL Object ID
   my $soft_key_mask = unpack('v', substr($buffer, 1, 2));
   push(@references, $soft_key_mask)  if($soft_key_mask != 0xffff);

   # Store off copy of values
   my $object_cnt = unpack('C', substr($buffer, 5, 1));
   my $macro_cnt = unpack('C', substr($buffer, 6, 1));

   # Determine length of remaining data in this object
   my $length = $object_cnt * 6 + $macro_cnt * 2;

   # Read the remaining data
   read($file, $buffer, $length);
   $output .= $buffer;

   # Add Child Objects to references
   while($object_cnt--)
   {
      push(@references, unpack('v', substr($buffer, 0, 2, '')));
      substr($buffer, 0, 4, '');
   }

   # Return hash reference containing pertinent data
   return { 'object_id' => $object_id,
            'raw' => $output,
            'refs' => \@references,
            'type' => $type,
            'length' => length $output
          };
}


####################################################
#  B.4  ParseType_3_Container
####################################################
#  Subroutine to parse Container objects
####################################################
sub ParseType_3_Container($$$)
{
   my $object_id = shift;
   my $type = shift;
   my $file = shift;

   my $output;
   my $buffer;
   my @references;

   # Add 'Object ID' and 'Type' to raw data
   $output .= pack('vC', $object_id, $type);

   # Read the fixed-size data fields ('Width' 'Height' 'Hidden' 'Number of objects to follow' and 'Number of macros to follow')
   read($file, $buffer, 7);
   $output .= $buffer;

   # Store off copy of values
   my $object_cnt = unpack('C', substr($buffer, 5, 1));
   my $macro_cnt = unpack('C', substr($buffer, 6, 1));

   # Determine length of remaining data in this object
   my $length = $object_cnt * 6 + $macro_cnt * 2;

   # Read the remaining data
   read($file, $buffer, $length);
   $output .= $buffer;

   # Add Child Objects to references
   while($object_cnt--)
   {
      push(@references, unpack('v', substr($buffer, 0, 2, '')));
      substr($buffer, 0, 4, '');
   }

   # Return hash reference containing pertinent data
   return { 'object_id' => $object_id,
            'raw' => $output,
            'refs' => \@references,
            'type' => $type,
            'length' => length $output
          };
}


####################################################
#  B.5  ParseType_4_SoftKeyMask
####################################################
#  Subroutine to parse Soft Key Mask objects
####################################################
sub ParseType_4_SoftKeyMask($$$)
{
   my $object_id = shift;
   my $type = shift;
   my $file = shift;

   my $output;
   my $buffer;
   my @references;

   # Add 'Object ID' and 'Type' to raw data
   $output .= pack('vC', $object_id, $type);

   # Read the fixed-size data fields ('Background Colour' 'Number of objects to follow' and 'Number of macros to follow')
   read($file, $buffer, 3);
   $output .= $buffer;

   # Store off copy of values
   my $object_cnt = unpack('C', substr($buffer, 1, 1));
   my $macro_cnt = unpack('C', substr($buffer, 2, 1));

   # Determine length of remaining data in this object
   my $length = $object_cnt * 2 + $macro_cnt * 2;

   # Read the remaining data
   read($file, $buffer, $length);
   $output .= $buffer;

   # Add Child Objects to references
   while($object_cnt--)
   {
      push(@references, unpack('v', substr($buffer, 0, 2, '')));
   }

   # Return hash reference containing pertinent data
   return { 'object_id' => $object_id,
            'raw' => $output,
            'refs' => \@references,
            'type' => $type,
            'length' => length $output
          };
}


####################################################
#  B.6  ParseType_5_Key
####################################################
#  Subroutine to parse Key objects
####################################################
sub ParseType_5_Key($$$)
{
   my $object_id = shift;
   my $type = shift;
   my $file = shift;

   my $output;
   my $buffer;
   my @references;

   # Add 'Object ID' and 'Type' to raw data
   $output .= pack('vC', $object_id, $type);

   # Read the fixed-size data fields ('Background Colour' 'Key code' 'Number of objects to follow' and 'Number of macros to follow')
   read($file, $buffer, 4);
   $output .= $buffer;

   # Store off copy of values
   my $object_cnt = unpack('C', substr($buffer, 2, 1));
   my $macro_cnt = unpack('C', substr($buffer, 3, 1));

   # Determine length of remaining data in this object
   my $length = $object_cnt * 6 + $macro_cnt * 2;

   # Read the remaining data
   read($file, $buffer, $length);
   $output .= $buffer;

   # Add Child Objects to references
   while($object_cnt--)
   {
      push(@references, unpack('v', substr($buffer, 0, 2, '')));
      substr($buffer, 0, 4, '');
   }

   # Return hash reference containing pertinent data
   return { 'object_id' => $object_id,
            'raw' => $output,
            'refs' => \@references,
            'type' => $type,
            'length' => length $output
          };
}


####################################################
#  B.7  ParseType_6_Button
####################################################
#  Subroutine to parse Button objects
####################################################
sub ParseType_6_Button($$$)
{
   my $object_id = shift;
   my $type = shift;
   my $file = shift;

   my $output;
   my $buffer;
   my @references;

   # Add 'Object ID' and 'Type' to raw data
   $output .= pack('vC', $object_id, $type);

   # Read the fixed-size data fields ('Width' 'Height' 'Background Colour' 'Border Colour' 'Key code' 'Options' 'Number of objects to follow' and 'Number of macros to follow')
   read($file, $buffer, 10);
   $output .= $buffer;

   # Store off copy of values
   my $object_cnt = unpack('C', substr($buffer, 8, 1));
   my $macro_cnt = unpack('C', substr($buffer, 9,1));

   # Determine length of remaining data in this object
   my $length = $object_cnt * 6 + $macro_cnt * 2;

   # Read the remaining data
   read($file, $buffer, $length);
   $output .= $buffer;

   # Add Child Objects to references
   while($object_cnt--)
   {
      push(@references, unpack('v', substr($buffer, 0, 2, '')));
      substr($buffer, 0, 4, '');
   }

   # Return hash reference containing pertinent data
   return { 'object_id' => $object_id,
            'raw' => $output,
            'refs' => \@references,
            'type' => $type,
            'length' => length $output
          };
}


####################################################
#  B.8.2  ParseType_7_InputBoolean
####################################################
#  Subroutine to parse Input Boolean objects
####################################################
sub ParseType_7_InputBoolean($$$)
{
   my $object_id = shift;
   my $type = shift;
   my $file = shift;

   my $output;
   my $buffer;
   my @references;

   # Add 'Object ID' and 'Type' to raw data
   $output .= pack('vC', $object_id, $type);

   # Read the fixed-size data fields ('Background Colour' 'Width' 'Foreground Colour' 'Variable Reference' 'Value' 'Enabled' and 'Number of macros to follow')
   read($file, $buffer, 10);
   $output .= $buffer;

   # Add 'Foreground Colour' to references
   push(@references, unpack('v', substr($buffer, 3, 2)));

   # Add 'Variable Reference' to references if not the NULL Object ID
   my $variable_reference = unpack('v', substr($buffer, 5, 2));
   push(@references, $variable_reference)  if($variable_reference != 0xffff);

   # Store off copy of values
   my $macro_cnt = unpack('C', substr($buffer, 9, 1));

   # Determine length of remaining data in this object
   my $length = $macro_cnt * 2;

   # Read the remaining data
   read($file, $buffer, $length);
   $output .= $buffer;

   # Return hash reference containing pertinent data
   return { 'object_id' => $object_id,
            'raw' => $output,
            'refs' => \@references,
            'type' => $type,
            'length' => length $output
          };
}


####################################################
#  B.8.3  ParseType_8_InputString
####################################################
#  Subroutine to parse Input String objects
####################################################
sub ParseType_8_InputString($$$)
{
   my $object_id = shift;
   my $type = shift;
   my $file = shift;

   my $output;
   my $buffer;
   my @references;

   # Add 'Object ID' and 'Type' to raw data
   $output .= pack('vC', $object_id, $type);

   # Read the fixed-size data fields ('Width' 'Height' 'Background Colour' 'Font attributes'
   #   'Input attributes' 'Options' 'Variable Reference' 'Justification' 'Length')
   read($file, $buffer, 14);
   $output .= $buffer;

   # Add 'Font attributes' to references
   push(@references, unpack('v', substr($buffer, 5, 2)));

   # Add 'Input attributes' to references if not the NULL Object ID
   my $input_attributes = unpack('v', substr($buffer, 7, 2));
   push(@references, $input_attributes)  if($input_attributes != 0xffff);

   # Add 'Variable Reference' to references if not the NULL Object ID
   my $variable_reference = unpack('v', substr($buffer, 10, 2));
   push(@references, $variable_reference)  if($variable_reference != 0xffff);

   # Determine length of the 'Value' string in this object
   my $string_len = unpack('C', substr($buffer, 13, 1));

   # Read the fields ('Value' 'Enabled' and 'Number of macros to follow')
   read($file, $buffer, $string_len + 2);
   $output .= $buffer;

   # Determine length of remaining data in this object
   my $macro_cnt = unpack('C', substr($buffer, $string_len + 1, 1));
   my $length = $macro_cnt * 2;

   # Read the remaining data
   read($file, $buffer, $length);
   $output .= $buffer;

   # Return hash reference containing pertinent data
   return { 'object_id' => $object_id,
            'raw' => $output,
            'refs' => \@references,
            'type' => $type,
            'length' => length $output
          };
}


####################################################
#  B.8.4  ParseType_9_InputNumber
####################################################
#  Subroutine to parse Input Number objects
####################################################
sub ParseType_9_InputNumber($$$)
{
   my $object_id = shift;
   my $type = shift;
   my $file = shift;

   my $output;
   my $buffer;
   my @references;

   # Add 'Object ID' and 'Type' to raw data
   $output .= pack('vC', $object_id, $type);

   # Read the fixed-size data fields ('Width' 'Height' 'Background Colour' 'Font attributes'
   #   'Options' 'Variable Reference' 'Value' 'Min. value' 'Max. value' 'Offset' 'Scale'
   #   '# of decimals' 'Format' 'Justification' 'Options 2' and 'Number of macros to follow')
   read($file, $buffer, 35);
   $output .= $buffer;

   # Add 'Font attributes' to references
   push(@references, unpack('v', substr($buffer, 5, 2)));

   # Add 'Variable Reference' to references if not the NULL Object ID
   my $variable_reference = unpack('v', substr($buffer, 8, 2));
   push(@references, $variable_reference)  if($variable_reference != 0xffff);

   # Determine length of remaining data in this object
   my $macro_cnt = unpack('C', substr($buffer, 34, 1));
   my $length = $macro_cnt * 2;

   # Read the remaining data
   read($file, $buffer, $length);
   $output .= $buffer;

   # Return hash reference containing pertinent data
   return { 'object_id' => $object_id,
            'raw' => $output,
            'refs' => \@references,
            'type' => $type,
            'length' => length $output
          };
}


####################################################
#  B.8.5  ParseType_10_InputList
####################################################
#  Subroutine to parse Input List objects
####################################################
sub ParseType_10_InputList($$$)
{
   my $object_id = shift;
   my $type = shift;
   my $file = shift;

   my $output;
   my $buffer;
   my @references;

   # Add 'Object ID' and 'Type' to raw data
   $output .= pack('vC', $object_id, $type);

   # Read the fixed-size data fields ('Width' 'Height' 'Variable Reference' 'Value' 'Number of list items' 'Options' and 'Number of macros to follow')
   read($file, $buffer, 10);
   $output .= $buffer;

   # Add 'Variable Reference' to references if not the NULL Object ID
   my $variable_reference = unpack('v', substr($buffer, 4, 2));
   push(@references, $variable_reference)  if($variable_reference != 0xffff);

   # Determine length of remaining data in this object
   my $object_cnt = unpack('C', substr($buffer, 7, 1));
   my $macro_cnt = unpack('C', substr($buffer, 9, 1));
   my $length = $object_cnt * 2 + $macro_cnt * 2;

   # Read the remaining data
   read($file, $buffer, $length);
   $output .= $buffer;

   # Add List Items to references
   while($object_cnt--)
   {
      # Add List Item to references if not the NULL Object ID
      my $list_item = unpack('v', substr($buffer, 0, 2, ''));
      push(@references, $list_item)  if($list_item != 0xffff);
   }

   # Return hash reference containing pertinent data
   return { 'object_id' => $object_id,
            'raw' => $output,
            'refs' => \@references,
            'type' => $type,
            'length' => length $output
          };
}


####################################################
#  B.9.2  ParseType_11_OutputString
####################################################
#  Subroutine to parse Output String objects
####################################################
sub ParseType_11_OutputString($$$)
{
   my $object_id = shift;
   my $type = shift;
   my $file = shift;

   my $output;
   my $buffer;
   my @references;

   # Add 'Object ID' and 'Type' to raw data
   $output .= pack('vC', $object_id, $type);

   # Read the fixed-size data fields ('Width' 'Height' 'Background Colour' 'Font attributes' 'Options'
   #   'Variable Reference' 'Justification' and 'Length')
   read($file, $buffer, 13);
   $output .= $buffer;

   # Add 'Font attributes' to references
   push(@references, unpack('v', substr($buffer, 5, 2)));

   # Add 'Variable Reference' to references if not the NULL Object ID
   my $variable_reference = unpack('v', substr($buffer, 8, 2));
   push(@references, $variable_reference)  if($variable_reference != 0xffff);

   # Determine length of the 'Value' string in this object
   my $string_len = unpack('v', substr($buffer, 11, 2));

   # Read the next data fields ('Value' and 'Number of macros to follow')
   read($file, $buffer, $string_len + 1);
   $output .= $buffer;

   # Determine length of remaining data in this object
   my $macro_cnt = unpack('C', substr($buffer, $string_len, 1));
   my $length = $macro_cnt * 2;

   # Read the remaining data
   read($file, $buffer, $length);
   $output .= $buffer;

   # Return hash reference containing pertinent data
   return { 'object_id' => $object_id,
            'raw' => $output,
            'refs' => \@references,
            'type' => $type,
            'length' => length $output
          };
}


####################################################
#  B.9.3  ParseType_12_OutputNumber
####################################################
#  Subroutine to parse Output Number objects
####################################################
sub ParseType_12_OutputNumber($$$)
{
   my $object_id = shift;
   my $type = shift;
   my $file = shift;

   my $output;
   my $buffer;
   my @references;

   # Add 'Object ID' and 'Type' to raw data
   $output .= pack('vC', $object_id, $type);

   # Read the fixed-size data fields ('Width' 'Height' 'Background Colour' 'Font attributes'
   #   'Options' 'Variable Reference' 'Value' 'Offset' 'Scale' '# of decimals' 'Format'
   #   'Justification' and 'Number of macros to follow')
   read($file, $buffer, 26);
   $output .= $buffer;

   # Add 'Font attributes' to references
   push(@references, unpack('v', substr($buffer, 5, 2)));

   # Add 'Variable Reference' to references if not the NULL Object ID
   my $variable_reference = unpack('v', substr($buffer, 8, 2));
   push(@references, $variable_reference)  if($variable_reference != 0xffff);

   # Determine length of remaining data in this object
   my $macro_cnt = unpack('C', substr($buffer, 25, 1));
   my $length = $macro_cnt * 2;

   # Read the remaining data
   read($file, $buffer, $length);
   $output .= $buffer;

   # Return hash reference containing pertinent data
   return { 'object_id' => $object_id,
            'raw' => $output,
            'refs' => \@references,
            'type' => $type,
            'length' => length $output
          };
}


####################################################
#  B.9.4  ParseType_37_OutputList
####################################################
#  Subroutine to parse Output List objects
####################################################
sub ParseType_37_OutputList($$$)
{
   my $object_id = shift;
   my $type = shift;
   my $file = shift;

   my $output;
   my $buffer;
   my @references;

   # Add 'Object ID' and 'Type' to raw data
   $output .= pack('vC', $object_id, $type);

   # Read the fixed-size data fields ('Width' 'Height' 'Variable Reference'
   #   'Value' 'Number of list items' and 'Number of macros to follow')
   read($file, $buffer, 9);
   $output .= $buffer;

   # Add 'Variable Reference' to references if not the NULL Object ID
   my $variable_reference = unpack('v', substr($buffer, 4, 2));
   push(@references, $variable_reference)  if($variable_reference != 0xffff);

   # Determine length of remaining data in this object
   my $object_cnt = unpack('C', substr($buffer, 7, 1));
   my $macro_cnt = unpack('C', substr($buffer, 8, 1));
   my $length = $object_cnt * 2 + $macro_cnt * 2;

   # Read the remaining data
   read($file, $buffer, $length);
   $output .= $buffer;

   # Add List Items to references
   while($object_cnt--)
   {
      # Add List Item to references if not the NULL Object ID
      my $list_item = unpack('v', substr($buffer, 0, 2, ''));
      push(@references, $list_item)  if($list_item != 0xffff);
   }

   # Return hash reference containing pertinent data
   return { 'object_id' => $object_id,
            'raw' => $output,
            'refs' => \@references,
            'type' => $type,
            'length' => length $output
          };
}


####################################################
#  B.10.2  ParseType_13_Line
####################################################
#  Subroutine to parse Line objects
####################################################
sub ParseType_13_Line($$$)
{
   my $object_id = shift;
   my $type = shift;
   my $file = shift;

   my $output;
   my $buffer;
   my @references;

   # Add 'Object ID' and 'Type' to raw data
   $output .= pack('vC', $object_id, $type);

   # Read the fixed-size data fields ('Line attributes' 'Width' 'Height'
   #   'Line Direction' and 'Number of macros to follow')
   read($file, $buffer, 8);
   $output .= $buffer;

   # Add 'Line attributes' to references
   push(@references, unpack('v', substr($buffer, 0, 2)));

   # Determine length of remaining data in this object
   my $macro_cnt = unpack('C', substr($buffer, 7, 1));
   my $length = $macro_cnt * 2;

   # Read the remaining data
   read($file, $buffer, $length);
   $output .= $buffer;

   # Return hash reference containing pertinent data
   return { 'object_id' => $object_id,
            'raw' => $output,
            'refs' => \@references,
            'type' => $type,
            'length' => length $output
          };
}


####################################################
#  B.10.3  ParseType_14_Rectangle
####################################################
#  Subroutine to parse Rectangle objects
####################################################
sub ParseType_14_Rectangle($$$)
{
   my $object_id = shift;
   my $type = shift;
   my $file = shift;

   my $output;
   my $buffer;
   my @references;

   # Add 'Object ID' and 'Type' to raw data
   $output .= pack('vC', $object_id, $type);

   # Read the fixed-size data fields ('Line attributes' 'Width' 'Height'
   #   'Line suppression' 'Fill attributes' and 'Number of macros to follow')
   read($file, $buffer, 10);
   $output .= $buffer;

   # Add 'Line attributes' to references
   push(@references, unpack('v', substr($buffer, 0, 2)));

   # Add 'Fill attributes' to references if not the NULL Object ID
   my $fill_attributes = unpack('v', substr($buffer, 7, 2));
   push(@references, $fill_attributes)  if($fill_attributes != 0xffff);

   # Determine length of remaining data in this object
   my $macro_cnt = unpack('C', substr($buffer, 9, 1));
   my $length = $macro_cnt * 2;

   # Read the remaining data
   read($file, $buffer, $length);
   $output .= $buffer;

   # Return hash reference containing pertinent data
   return { 'object_id' => $object_id,
            'raw' => $output,
            'refs' => \@references,
            'type' => $type,
            'length' => length $output
          };
}


####################################################
#  B.10.4  ParseType_15_Ellipse
####################################################
#  Subroutine to parse Ellipse objects
####################################################
sub ParseType_15_Ellipse($$$)
{
   my $object_id = shift;
   my $type = shift;
   my $file = shift;

   my $output;
   my $buffer;
   my @references;

   # Add 'Object ID' and 'Type' to raw data
   $output .= pack('vC', $object_id, $type);

   # Read the fixed-size data fields ('Line attributes' 'Width' 'Height' 'Ellipse type'
   #   'Start angle' 'End angle' 'Fill attributes' and 'Number of macros to follow')
   read($file, $buffer, 12);
   $output .= $buffer;

   # Add 'Line attributes' to references
   push(@references, unpack('v', substr($buffer, 0, 2)));

   # Add 'Fill attributes' to references if not the NULL Object ID
   my $fill_attributes = unpack('v', substr($buffer, 9, 2));
   push(@references, $fill_attributes)  if($fill_attributes != 0xffff);

   # Determine length of remaining data in this object
   my $macro_cnt = unpack('C', substr($buffer, 11, 1));
   my $length = $macro_cnt * 2;

   # Read the remaining data
   read($file, $buffer, $length);
   $output .= $buffer;

   # Return hash reference containing pertinent data
   return { 'object_id' => $object_id,
            'raw' => $output,
            'refs' => \@references,
            'type' => $type,
            'length' => length $output
          };
}


####################################################
#  B.10.5  ParseType_16_OutputPolygon
####################################################
#  Subroutine to parse Output Polygon objects
####################################################
sub ParseType_16_OutputPolygon($$$)
{
   my $object_id = shift;
   my $type = shift;
   my $file = shift;

   my $output;
   my $buffer;
   my @references;

   # Add 'Object ID' and 'Type' to raw data
   $output .= pack('vC', $object_id, $type);

   # Read the fixed-size data fields ('Width' 'Height' 'Line attributes' 'Fill attributes'
   #   'Polygon type' 'Number of points' and 'Number of macros to follow')
   read($file, $buffer, 11);
   $output .= $buffer;

   # Add 'Line attributes' to references
   push(@references, unpack('v', substr($buffer, 4, 2)));

   # Add 'Fill attributes' to references if not the NULL Object ID
   my $fill_attributes = unpack('v', substr($buffer, 6, 2));
   push(@references, $fill_attributes)  if($fill_attributes != 0xffff);

   # Determine length of remaining data in this object
   my $point_cnt = unpack('C', substr($buffer, 9, 1));
   my $macro_cnt = unpack('C', substr($buffer, 10, 1));
   my $length = $point_cnt * 4 + $macro_cnt * 2;

   # Read the remaining data
   read($file, $buffer, $length);
   $output .= $buffer;

   # Return hash reference containing pertinent data
   return { 'object_id' => $object_id,
            'raw' => $output,
            'refs' => \@references,
            'type' => $type,
            'length' => length $output
          };
}


####################################################
#  B.11.2  ParseType_17_OutputMeter
####################################################
#  Subroutine to parse Output Meter objects
####################################################
sub ParseType_17_OutputMeter($$$)
{
   my $object_id = shift;
   my $type = shift;
   my $file = shift;

   my $output;
   my $buffer;
   my @references;

   # Add 'Object ID' and 'Type' to raw data
   $output .= pack('vC', $object_id, $type);

   # Read the fixed-size data fields ('Width' 'Needle colour' 'Border colour' 'Arc and tick colour'
   #   'Options' '# of ticks' 'Start angle' 'End angle' 'Min. value' 'Max. value' 'Variable reference'
   #   'Value' and 'Number of macros to follow')
   read($file, $buffer, 18);
   $output .= $buffer;

   # Add 'Variable reference' to references if not the NULL Object ID
   my $variable_reference = unpack('v', substr($buffer, 13, 2));
   push(@references, $variable_reference)  if($variable_reference != 0xffff);

   # Determine length of remaining data in this object
   my $macro_cnt = unpack('C', substr($buffer, 17, 1));
   my $length = $macro_cnt * 2;

   # Read the remaining data
   read($file, $buffer, $length);
   $output .= $buffer;

   # Return hash reference containing pertinent data
   return { 'object_id' => $object_id,
            'raw' => $output,
            'refs' => \@references,
            'type' => $type,
            'length' => length $output
          };
}


####################################################
#  B.11.3  ParseType_18_LinearBargraph
####################################################
#  Subroutine to parse Linear Bargraph objects
####################################################
sub ParseType_18_LinearBargraph($$$)
{
   my $object_id = shift;
   my $type = shift;
   my $file = shift;

   my $output;
   my $buffer;
   my @references;

   # Add 'Object ID' and 'Type' to raw data
   $output .= pack('vC', $object_id, $type);

   # Read the fixed-size data fields ('Width' 'Height' 'Colour'
   #   'Target line colour' 'Options' '# of ticks' 'Min. value'
   #   'Max. value' 'Variable reference' 'Value'
   #   'Target value variable reference' 'Target value' and 'Number of macros to follow')
   read($file, $buffer, 21);
   $output .= $buffer;

   # Add 'Variable reference' to references if not the NULL Object ID
   my $variable_reference = unpack('v', substr($buffer, 12, 2));
   push(@references, $variable_reference)  if($variable_reference != 0xffff);

   # Add 'Target value variable reference' to references if not the NULL Object ID
   my $target_variable_reference = unpack('v', substr($buffer, 16, 2));
   push(@references, $target_variable_reference)  if($target_variable_reference != 0xffff);

   # Determine length of remaining data in this object
   my $macro_cnt = unpack('C', substr($buffer, 20, 1));
   my $length = $macro_cnt * 2;

   # Read the remaining data
   read($file, $buffer, $length);
   $output .= $buffer;

   # Return hash reference containing pertinent data
   return { 'object_id' => $object_id,
            'raw' => $output,
            'refs' => \@references,
            'type' => $type,
            'length' => length $output
          };
}


####################################################
#  B.11.4  ParseType_19_ArchedBarGraph
####################################################
#  Subroutine to parse Arched Bargraph objects
####################################################
sub ParseType_19_ArchedBarGraph($$$)
{
   my $object_id = shift;
   my $type = shift;
   my $file = shift;

   my $output;
   my $buffer;
   my @references;

   # Add 'Object ID' and 'Type' to raw data
   $output .= pack('vC', $object_id, $type);

   # Read the fixed-size data fields ('Width' 'Height' 'Colour'
   #   'Target line colour' 'Options' 'Start angle' 'End angle'
   #   'Bar graph width' 'Min. value' 'Max. value'
   #   'Variable reference' 'Value' 'Target value variable reference'
   #   'Target value' and 'Number of macros to follow')
   read($file, $buffer, 24);
   $output .= $buffer;

   # Add 'Variable reference' to references if not the NULL Object ID
   my $variable_reference = unpack('v', substr($buffer, 15, 2));
   push(@references, $variable_reference)  if($variable_reference != 0xffff);

   # Add 'Target value variable reference' to references if not the NULL Object ID
   my $target_variable_reference = unpack('v', substr($buffer, 19, 2));
   push(@references, $target_variable_reference)  if($target_variable_reference != 0xffff);

   # Determine length of remaining data in this object
   my $macro_cnt = unpack('C', substr($buffer, 23, 1));
   my $length = $macro_cnt * 2;

   # Read the remaining data
   read($file, $buffer, $length);
   $output .= $buffer;

   # Return hash reference containing pertinent data
   return { 'object_id' => $object_id,
            'raw' => $output,
            'refs' => \@references,
            'type' => $type,
            'length' => length $output
          };
}


####################################################
#  B.12  ParseType_20_PictureGraphic
####################################################
#  Subroutine to parse Picture Graphic objects
####################################################
sub ParseType_20_PictureGraphic($$$)
{
   my $object_id = shift;
   my $type = shift;
   my $file = shift;

   my $output;
   my $buffer;
   my @references;

   # Add 'Object ID' and 'Type' to raw data
   $output .= pack('vC', $object_id, $type);

   # Read the fixed-size data fields ('Width' 'Actual width' 'Actual height'
   #   'Format' 'Options' 'Transparency colour' '# of bytes in raw data'
   #   and 'Number of macros to follow')
   read($file, $buffer, 14);
   $output .= $buffer;

   # Determine length of remaining data in this object
   my $data_length = unpack('V', substr($buffer, 9, 4));
   my $macro_cnt = unpack('C', substr($buffer, 13, 1));
   my $length = $data_length + $macro_cnt * 2;

   # Read the remaining data
   read($file, $buffer, $length);
   $output .= $buffer;

   # Return hash reference containing pertinent data
   return { 'object_id' => $object_id,
            'raw' => $output,
            'refs' => \@references,
            'type' => $type,
            'length' => length $output
          };
}


####################################################
#  B.13.2  ParseType_21_NumberVariable
####################################################
#  Subroutine to parse Number Variable objects
####################################################
sub ParseType_21_NumberVariable($$$)
{
   my $object_id = shift;
   my $type = shift;
   my $file = shift;

   my $output;
   my $buffer;
   my @references;

   # Add 'Object ID' and 'Type' to raw data
   $output .= pack('vC', $object_id, $type);

   # Read the fixed-size data fields ('Value')
   read($file, $buffer, 4);
   $output .= $buffer;

   # Return hash reference containing pertinent data
   return { 'object_id' => $object_id,
            'raw' => $output,
            'refs' => \@references,
            'type' => $type,
            'length' => length $output
          };
}


####################################################
#  B.13.3  ParseType_22_StringVariable
####################################################
#  Subroutine to parse String Variable objects
####################################################
sub ParseType_22_StringVariable($$$)
{
   my $object_id = shift;
   my $type = shift;
   my $file = shift;

   my $output;
   my $buffer;
   my @references;

   # Add 'Object ID' and 'Type' to raw data
   $output .= pack('vC', $object_id, $type);

   # Read the fixed-size data fields ('Length')
   read($file, $buffer, 2);
   $output .= $buffer;

   # Determine length of remaining data in this object
   my $length = unpack('v', $buffer);

   # Read the remaining data
   read($file, $buffer, $length);
   $output .= $buffer;

   # Return hash reference containing pertinent data
   return { 'object_id' => $object_id,
            'raw' => $output,
            'refs' => \@references,
            'type' => $type,
            'length' => length $output
          };
}


####################################################
#  B.14.2  ParseType_23_FontAttributes
####################################################
#  Subroutine to parse Font Attribute objects
####################################################
sub ParseType_23_FontAttributes($$$)
{
   my $object_id = shift;
   my $type = shift;
   my $file = shift;

   my $output;
   my $buffer;
   my @references;

   # Add 'Object ID' and 'Type' to raw data
   $output .= pack('vC', $object_id, $type);

   # Read the fixed-size data fields ('Font colour' 'Font size'
   #   'Font type' 'Font style' and 'Number of macros to follow')
   read($file, $buffer, 5);
   $output .= $buffer;

   # Determine length of remaining data in this object
   my $macro_cnt = unpack('C', substr($buffer, 4, 1));
   my $length = $macro_cnt * 2;

   # Read the remaining data
   read($file, $buffer, $length);
   $output .= $buffer;

   # Return hash reference containing pertinent data
   return { 'object_id' => $object_id,
            'raw' => $output,
            'refs' => \@references,
            'type' => $type,
            'length' => length $output
          };
}


####################################################
#  B.14.3  ParseType_24_LineAttributes
####################################################
#  Subroutine to parse Line Attribute objects
####################################################
sub ParseType_24_LineAttributes($$$)
{
   my $object_id = shift;
   my $type = shift;
   my $file = shift;

   my $output;
   my $buffer;
   my @references;

   # Add 'Object ID' and 'Type' to raw data
   $output .= pack('vC', $object_id, $type);

   # Read the fixed-size data fields ('Line colour' 'Line width'
   #   'Line art' and 'Number of macros to follow')
   read($file, $buffer, 5);
   $output .= $buffer;

   # Determine length of remaining data in this object
   my $macro_cnt = unpack('C', substr($buffer, 4,1));
   my $length = $macro_cnt * 2;

   # Read the remaining data
   read($file, $buffer, $length);
   $output .= $buffer;

   # Return hash reference containing pertinent data
   return { 'object_id' => $object_id,
            'raw' => $output,
            'refs' => \@references,
            'type' => $type,
            'length' => length $output
          };
}


####################################################
#  B.14.4  ParseType_25_FillAttributes
####################################################
#  Subroutine to parse Fill Attribute objects
####################################################
sub ParseType_25_FillAttributes($$$)
{
   my $object_id = shift;
   my $type = shift;
   my $file = shift;

   my $output;
   my $buffer;
   my @references;

   # Add 'Object ID' and 'Type' to raw data
   $output .= pack('vC', $object_id, $type);

   # Read the fixed-size data fields ('Fill type' 'Fill colour'
   #   'Fill pattern' and 'Number of macros to follow')
   read($file, $buffer, 5);
   $output .= $buffer;

   # Add 'Variable reference' to references if not the NULL Object ID
   my $fill_pattern = unpack('v', substr($buffer, 2, 2));
   push(@references, $fill_pattern)  if($fill_pattern != 0xffff);

   # Determine length of remaining data in this object
   my $macro_cnt = unpack('C', substr($buffer, 4,1));
   my $length = $macro_cnt * 2;

   # Read the remaining data
   read($file, $buffer, $length);
   $output .= $buffer;

   # Return hash reference containing pertinent data
   return { 'object_id' => $object_id,
            'raw' => $output,
            'refs' => \@references,
            'type' => $type,
            'length' => length $output
          };
}


####################################################
#  B.14.5  ParseType_26_InputAttributes
####################################################
#  Subroutine to parse Input Attribute objects
####################################################
sub ParseType_26_InputAttributes($$$)
{
   my $object_id = shift;
   my $type = shift;
   my $file = shift;

   my $output;
   my $buffer;
   my @references;

   # Add 'Object ID' and 'Type' to raw data
   $output .= pack('vC', $object_id, $type);

   # Read the fixed-size data fields ('Validation type' and 'Length')
   read($file, $buffer, 2);
   $output .= $buffer;

   # Read the data fields ('Validation string' and 'Number of macros to follow')
   my $string_len = unpack('C', substr($buffer, 1, 1));
   read($file, $buffer, $string_len + 1);
   $output .= $buffer;

   # Determine length of remaining data in this object
   my $macro_cnt = unpack('C', substr($buffer, $string_len, 1));
   my $length = $macro_cnt * 2;

   # Read the remaining data
   read($file, $buffer, $length);
   $output .= $buffer;

   # Return hash reference containing pertinent data
   return { 'object_id' => $object_id,
            'raw' => $output,
            'refs' => \@references,
            'type' => $type,
            'length' => length $output
          };
}


####################################################
#  B.14.6  ParseType_38_ExtendedInputAttributes
####################################################
#  Subroutine to parse Extended Input Attribute objects
####################################################
sub ParseType_38_ExtendedInputAttributes($$$)
{
   my $object_id = shift;
   my $type = shift;
   my $file = shift;

   my $output;
   my $buffer;
   my @references;

   # Add 'Object ID' and 'Type' to raw data
   $output .= pack('vC', $object_id, $type);

   # Read the fixed-size data fields ('Validation type' and 'Number of code planes to follow')
   read($file, $buffer, 2);
   $output .= $buffer;

   # For each code plane
   my $codePlane_cnt = unpack('C', substr($buffer, 1, 1));
   while($codePlane_cnt--)
   {
      # Read the fixed-size data fields ('Code plane number' and
      #   'Number of character ranges to follow')
      read($file, $buffer, 2);
      $output .= $buffer;

      # For each character range
      my $charRange_cnt = unpack('C', substr($buffer, 1, 1));
      while($charRange_cnt--)
      {
         # Copy the range
         read($file, $buffer, 4);
         $output .= $buffer;
      }
   }

   # Return hash reference containing pertinent data
   return { 'object_id' => $object_id,
            'raw' => $output,
            'refs' => \@references,
            'type' => $type,
            'length' => length $output
          };
}


####################################################
#  B.15  ParseType_27_ObjectPointer
####################################################
#  Subroutine to parse Object Pointer objects
####################################################
sub ParseType_27_ObjectPointer($$$)
{
   my $object_id = shift;
   my $type = shift;
   my $file = shift;

   my $output;
   my $buffer;
   my @references;

   # Add 'Object ID' and 'Type' to raw data
   $output .= pack('vC', $object_id, $type);

   # Read the fixed-size data fields ('Value')
   read($file, $buffer, 2);
   $output .= $buffer;

   # Add 'Value' to references if not the NULL Object ID
   my $value = unpack('v', $buffer);
   push(@references, $value)  if($value != 0xffff);

   # Return hash reference containing pertinent data
   return { 'object_id' => $object_id,
            'raw' => $output,
            'refs' => \@references,
            'type' => $type,
            'length' => length $output
          };
}


####################################################
#  B.16  ParseType_28_Macro
####################################################
#  Subroutine to parse Macro objects
####################################################
sub ParseType_28_Macro($$$)
{
   my $object_id = shift;
   my $type = shift;
   my $file = shift;

   my $output;
   my $buffer;
   my @references;

   # Add 'Object ID' and 'Type' to raw data
   $output .= pack('vC', $object_id, $type);

   # Read the fixed-size data fields ('# of bytes to follow')
   read($file, $buffer, 2);
   $output .= $buffer;

   # Read the remaining data
   read($file, $buffer, unpack('v', $buffer));
   $output .= $buffer;

   # Return hash reference containing pertinent data
   return { 'object_id' => $object_id,
            'raw' => $output,
            'refs' => \@references,
            'type' => $type,
            'length' => length $output
          };
}


####################################################
#  B.17  ParseType_39_ColourMap
####################################################
#  Subroutine to parse Colour Map objects
####################################################
sub ParseType_39_ColourMap($$$)
{
   my $object_id = shift;
   my $type = shift;
   my $file = shift;

   my $output;
   my $buffer;
   my @references;

   # Add 'Object ID' and 'Type' to raw data
   $output .= pack('vC', $object_id, $type);

   # Read the fixed-size data fields ('Number of colour indexes to follow')
   read($file, $buffer, 2);
   $output .= $buffer;

   # Read the remaining data
   read($file, $buffer, unpack('v', $buffer));
   $output .= $buffer;

   # Return hash reference containing pertinent data
   return { 'object_id' => $object_id,
            'raw' => $output,
            'refs' => \@references,
            'type' => $type,
            'length' => length $output
          };
}


####################################################
#  B.18  ParseType_36_GraphicsContext
####################################################
#  Subroutine to parse Graphics Context objects
####################################################
sub ParseType_36_GraphicsContext($$$)
{
   my $object_id = shift;
   my $type = shift;
   my $file = shift;

   my $output;
   my $buffer;
   my @references;

   # Add 'Object ID' and 'Type' to raw data
   $output .= pack('vC', $object_id, $type);

   # Read the fixed-size data fields ('Viewport Width' 'Viewport Height' 'Viewport X' 'Viewport Y'
   #   'Canvas Width' 'Canvas Height' 'Viewport Zoom' 'Graphics Cursor X' 'Graphics Cursor Y'
   #   'Foreground Colour' 'Background Colour' 'Font Attributes Object' 'Line Attributes Object'
   #   'Fill Attributes Object' 'Format' 'Options' and 'Transparency Colour')
   read($file, $buffer, 31);
   $output .= $buffer;

   # Add 'Font Attributes Object' to references if not the NULL Object ID
   my $font_attributes = unpack('v', substr($buffer, 22, 2));
   push(@references, $font_attributes)  if($font_attributes != 0xffff);

   # Add 'Line Attributes Object' to references if not the NULL Object ID
   my $line_attributes = unpack('v', substr($buffer, 24, 2));
   push(@references, $line_attributes)  if($line_attributes != 0xffff);

   # Add 'Fill Attributes Object' to references if not the NULL Object ID
   my $fill_attributes = unpack('v', substr($buffer, 26, 2));
   push(@references, $fill_attributes)  if($fill_attributes != 0xffff);

   # Return hash reference containing pertinent data
   return { 'object_id' => $object_id,
            'raw' => $output,
            'refs' => \@references,
            'type' => $type,
            'length' => length $output
          };
}


####################################################
#  B.19  ParseType_34_WindowMask
####################################################
#  Subroutine to parse Window Mask objects
####################################################
sub ParseType_34_WindowMask($$$)
{
   my $object_id = shift;
   my $type = shift;
   my $file = shift;

   my $output;
   my $buffer;
   my @references;

   # Add 'Object ID' and 'Type' to raw data
   $output .= pack('vC', $object_id, $type);

   # Read the fixed-size data fields ('Width' 'Height' 'Window Type' 'Background Colour'
   #   'Options' 'Name' 'Window Title' 'Window Icon' 'Number of object references to follow'
   #   'Number of objects to follow' and 'Number of macros to follow')
   read($file, $buffer, 14);
   $output .= $buffer;

   # Add 'Name' to references
   push(@references, unpack('v', substr($buffer, 5, 2)));

   # Add 'Window Title' to references if not the NULL Object ID
   my $window_title = unpack('v', substr($buffer, 7, 2));
   push(@references, $window_title)  if($window_title != 0xffff);

   # Add 'Window Icon' to references if not the NULL Object ID
   my $window_icon = unpack('v', substr($buffer, 9, 2));
   push(@references, $window_icon)  if($window_icon != 0xffff);

   # Determine length of remaining data in this object
   my $objRef_cnt = unpack('C', substr($buffer, 11, 1));
   my $object_cnt = unpack('C', substr($buffer, 12, 1));
   my $macro_cnt = unpack('C', substr($buffer, 13, 1));
   my $length = $objRef_cnt * 2 + $object_cnt * 6 + $macro_cnt * 2;

   # Read the remaining data
   read($file, $buffer, $length);
   $output .= $buffer;

   # Add referenced objects
   while($objRef_cnt--)
   {
      # Add referenced object to references if not the NULL Object ID
      my $object_reference = unpack('v', substr($buffer, 0, 2, ''));
      push(@references, $object_reference)  if($object_reference != 0xffff);
   }

   # Add child objects
   while($object_cnt--)
   {
      # Add referenced object to references
      push(@references, unpack('v', substr($buffer, 0, 2, '')));
      substr($buffer, 0, 4, '');
   }

   # Return hash reference containing pertinent data
   return { 'object_id' => $object_id,
            'raw' => $output,
            'refs' => \@references,
            'type' => $type,
            'length' => length $output
          };
}


####################################################
#  B.20  ParseType_35_KeyGroup
####################################################
#  Subroutine to parse Key Group objects
####################################################
sub ParseType_35_KeyGroup($$$)
{
   my $object_id = shift;
   my $type = shift;
   my $file = shift;

   my $output;
   my $buffer;
   my @references;

   # Add 'Object ID' and 'Type' to raw data
   $output .= pack('vC', $object_id, $type);

   # Read the fixed-size data fields ('Options' 'Name' 'Key Group Icon'
   #   'Number of objects to follow' and 'Number of macros to follow')
   read($file, $buffer, 7);
   $output .= $buffer;

   # Add 'Name' to references
   push(@references, unpack('v', substr($buffer, 1, 2)));

   # Add 'Key Group Icon' to references if not the NULL Object ID
   my $key_group_icon = unpack('v', substr($buffer, 3, 2));
   push(@references, $key_group_icon)  if($key_group_icon != 0xffff);

   # Determine length of remaining data in this object
   my $object_cnt = unpack('C', substr($buffer, 5, 1));
   my $macro_cnt = unpack('C', substr($buffer, 6, 1));
   my $length = $object_cnt * 2 + $macro_cnt * 2;

   # Read the remaining data
   read($file, $buffer, $length);
   $output .= $buffer;

   # Add referenced objects
   while($object_cnt--)
   {
      push(@references, unpack('v', substr($buffer, 0, 2, '')));
   }

   # Return hash reference containing pertinent data
   return { 'object_id' => $object_id,
            'raw' => $output,
            'refs' => \@references,
            'type' => $type,
            'length' => length $output
          };
}


####################################################
#  B.21  ParseType_40_ObjectLabelReferenceList
####################################################
#  Subroutine to parse Object Label Reference List objects
####################################################
sub ParseType_40_ObjectLabelReferenceList($$$)
{
   my $object_id = shift;
   my $type = shift;
   my $file = shift;

   my $output;
   my $buffer;
   my @references;

   # Add 'Object ID' and 'Type' to raw data
   $output .= pack('vC', $object_id, $type);

   # Read the fixed-size data fields ('Number of labelled objects')
   read($file, $buffer, 2);
   $output .= $buffer;

   # Determine length of remaining data in this object
   my $object_cnt = unpack('v', $buffer);
   my $length = $object_cnt * 7;

   # Read the remaining data
   read($file, $buffer, $length);
   $output .= $buffer;

   # Add referenced objects
   while($object_cnt--)
   {
      # Ignore 'Object ID' of object being labelled
      substr($buffer, 0, 2, '');

      # Add 'String variable reference' to references if not the NULL Object ID
      my $string_variable = unpack('v', substr($buffer, 0, 2, ''));
      push(@references, $string_variable)  if($string_variable != 0xffff);

      # Ignore 'Font Type'
      substr($buffer, 0, 1, '');

      # Add 'Graphical reference' to references if not the NULL Object ID
      my $graphical_reference = unpack('v', substr($buffer, 0, 2, ''));
      push(@references, $graphical_reference)  if($graphical_reference != 0xffff);
   }

   # Return hash reference containing pertinent data
   return { 'object_id' => $object_id,
            'raw' => $output,
            'refs' => \@references,
            'type' => $type,
            'length' => length $output
          };
}


####################################################
#  J.2.2  ParseType_29_AuxFunctionType1
####################################################
#  Subroutine to parse Aux Function Type 1 objects
####################################################
sub ParseType_29_AuxFunctionType1($$$)
{
   my $object_id = shift;
   my $type = shift;
   my $file = shift;

   my $output;
   my $buffer;
   my @references;

   # Add 'Object ID' and 'Type' to raw data
   $output .= pack('vC', $object_id, $type);

   # Read the fixed-size data fields ('Background colour' 'Function type' and 'Number of objects to follow')
   read($file, $buffer, 3);
   $output .= $buffer;

   # Determine length of remaining data in this object
   my $object_cnt = unpack('C', substr($buffer, 2, 1));
   my $length = $object_cnt * 6;

   # Read the remaining data
   read($file, $buffer, $length);
   $output .= $buffer;

   # Add referenced objects
   while($object_cnt--)
   {
      push(@references, unpack('v', substr($buffer, 0, 2, '')));
      substr($buffer, 0, 4, '');
   }

   # Return hash reference containing pertinent data
   return { 'object_id' => $object_id,
            'raw' => $output,
            'refs' => \@references,
            'type' => $type,
            'length' => length $output
          };
}


####################################################
#  J.2.3  ParseType_31_AuxFunctionType2
####################################################
#  Subroutine to parse Aux Function Type 2 objects
####################################################
sub ParseType_31_AuxFunctionType2($$$)
{
   my $object_id = shift;
   my $type = shift;
   my $file = shift;

   my $output;
   my $buffer;
   my @references;

   # Add 'Object ID' and 'Type' to raw data
   $output .= pack('vC', $object_id, $type);

   # Read the fixed-size data fields ('Background colour' 'Function attributes' and 'Number of objects to follow')
   read($file, $buffer, 3);
   $output .= $buffer;

   # Determine length of remaining data in this object
   my $object_cnt = unpack('C', substr($buffer, 2, 1));
   my $length = $object_cnt * 6;

   # Read the remaining data
   read($file, $buffer, $length);
   $output .= $buffer;

   # Add referenced objects
   while($object_cnt--)
   {
      push(@references, unpack('v', substr($buffer, 0, 2, '')));
      substr($buffer, 0, 4, '');
   }

   # Return hash reference containing pertinent data
   return { 'object_id' => $object_id,
            'raw' => $output,
            'refs' => \@references,
            'type' => $type,
            'length' => length $output
          };
}


####################################################
#  J.2.4  ParseType_30_AuxInputType1
####################################################
#  Subroutine to parse Aux Input Type 1 objects
####################################################
sub ParseType_30_AuxInputType1($$$)
{
   my $object_id = shift;
   my $type = shift;
   my $file = shift;

   my $output;
   my $buffer;
   my @references;

   # Add 'Object ID' and 'Type' to raw data
   $output .= pack('vC', $object_id, $type);

   # Read the fixed-size data fields ('Background colour' 'Function type' 'Input ID' and 'Number of objects to follow')
   read($file, $buffer, 4);
   $output .= $buffer;

   # Determine length of remaining data in this object
   my $object_cnt = unpack('C', substr($buffer, 3, 1));
   my $length = $object_cnt * 6;

   # Read the remaining data
   read($file, $buffer, $length);
   $output .= $buffer;

   # Add referenced objects
   while($object_cnt--)
   {
      push(@references, unpack('v', substr($buffer, 0, 2, '')));
      substr($buffer, 0, 4, '');
   }

   # Return hash reference containing pertinent data
   return { 'object_id' => $object_id,
            'raw' => $output,
            'refs' => \@references,
            'type' => $type,
            'length' => length $output
          };
}


####################################################
#  J.2.5  ParseType_32_AuxInputType2
####################################################
#  Subroutine to parse Aux Input Type 2 objects
####################################################
sub ParseType_32_AuxInputType2($$$)
{
   my $object_id = shift;
   my $type = shift;
   my $file = shift;

   my $output;
   my $buffer;
   my @references;

   # Add 'Object ID' and 'Type' to raw data
   $output .= pack('vC', $object_id, $type);

   # Read the fixed-size data fields ('Background colour' 'Function attributes' and 'Number of objects to follow')
   read($file, $buffer, 3);
   $output .= $buffer;

   # Determine length of remaining data in this object
   my $object_cnt = unpack('C', substr($buffer, 2, 1));
   my $length = $object_cnt * 6;

   # Read the remaining data
   read($file, $buffer, $length);
   $output .= $buffer;

   # Add referenced objects
   while($object_cnt--)
   {
      push(@references, unpack('v', substr($buffer, 0, 2, '')));
      substr($buffer, 0, 4, '');
   }

   # Return hash reference containing pertinent data
   return { 'object_id' => $object_id,
            'raw' => $output,
            'refs' => \@references,
            'type' => $type,
            'length' => length $output
          };
}


####################################################
#  J.2.7  ParseType_33_AuxControlDesignatorType2ObjectPointer
####################################################
#  Subroutine to parse Auxiliary Control Type 2 Object Pointer objects
####################################################
sub ParseType_33_AuxControlDesignatorType2ObjectPointer($$$)
{
   my $object_id = shift;
   my $type = shift;
   my $file = shift;

   my $output;
   my $buffer;
   my @references;

   # Add 'Object ID' and 'Type' to raw data
   $output .= pack('vC', $object_id, $type);

   # Read the fixed-size data fields ('Pointer Type' and 'Auxiliary Object ID')
   read($file, $buffer, 3);
   $output .= $buffer;

   # Return hash reference containing pertinent data
   return { 'object_id' => $object_id,
            'raw' => $output,
            'refs' => \@references,
            'type' => $type,
            'length' => length $output
          };
}


####################################################
# @standard_types is an array that associates object
# types with parser functions.
####################################################
our @standard_types = (
    { 'type'    => 0,
      'parser'  => \&ParseType_0_WorkingSet,
      'scaling' => 'SoftKeyMask'
    },
    { 'type'    => 1,
      'parser'  => \&ParseType_1_DataMask,
      'scaling' => 'DataMask'
    },
    { 'type'    => 2,
      'parser'  => \&ParseType_2_AlarmMask,
      'scaling' => 'DataMask'
    },
    { 'type'    => 3,
      'parser'  => \&ParseType_3_Container,
      'scaling' => 'Parent'
    },
    { 'type'    => 4,
      'parser'  => \&ParseType_4_SoftKeyMask,
      'scaling' => 'SoftKeyMask'
    },
    { 'type'    => 5,
      'parser'  => \&ParseType_5_Key,
      'scaling' => 'SoftKeyMask'
    },
    { 'type'    => 6,
      'parser'  => \&ParseType_6_Button,
      'scaling' => 'Parent'
    },
    { 'type'    => 7,
      'parser'  => \&ParseType_7_InputBoolean,
      'scaling' => 'Parent'
    },
    { 'type'    => 8,
      'parser'  => \&ParseType_8_InputString,
      'scaling' => 'Parent'
    },
    { 'type'    => 9,
      'parser'  => \&ParseType_9_InputNumber,
      'scaling' => 'Parent'
    },
    { 'type'    => 10,
      'parser'  => \&ParseType_10_InputList,
      'scaling' => 'Parent'
    },
    { 'type'    => 11,
      'parser'  => \&ParseType_11_OutputString,
      'scaling' => 'Parent'
    },
    { 'type'    => 12,
      'parser'  => \&ParseType_12_OutputNumber,
      'scaling' => 'Parent'
    },
    { 'type'    => 13,
      'parser'  => \&ParseType_13_Line,
      'scaling' => 'Parent'
    },
    { 'type'    => 14,
      'parser'  => \&ParseType_14_Rectangle,
      'scaling' => 'Parent'
    },
    { 'type'    => 15,
      'parser'  => \&ParseType_15_Ellipse,
      'scaling' => 'Parent'
    },
    { 'type'    => 16,
      'parser'  => \&ParseType_16_OutputPolygon,
      'scaling' => 'Parent'
    },
    { 'type'    => 17,
      'parser'  => \&ParseType_17_OutputMeter,
      'scaling' => 'Parent'
    },
    { 'type'    => 18,
      'parser'  => \&ParseType_18_LinearBargraph,
      'scaling' => 'Parent'
    },
    { 'type'    => 19,
      'parser'  => \&ParseType_19_ArchedBarGraph,
      'scaling' => 'Parent'
    },
    { 'type'    => 20,
      'parser'  => \&ParseType_20_PictureGraphic,
      'scaling' => 'Parent'
    },
    { 'type'    => 21,
      'parser'  => \&ParseType_21_NumberVariable,
      'scaling' => 'None'
    },
    { 'type'    => 22,
      'parser'  => \&ParseType_22_StringVariable,
      'scaling' => 'None'
    },
    { 'type'    => 23,
      'parser'  => \&ParseType_23_FontAttributes,
      'scaling' => 'Parent'
    },
    { 'type'    => 24,
      'parser'  => \&ParseType_24_LineAttributes,
      'scaling' => 'Parent'
    },
    { 'type'    => 25,
      'parser'  => \&ParseType_25_FillAttributes,
      'scaling' => 'Parent'
    },
    { 'type'    => 26,
      'parser'  => \&ParseType_26_InputAttributes,
      'scaling' => 'Parent'
    },
    { 'type'    => 27,
      'parser'  => \&ParseType_27_ObjectPointer,
      'scaling' => 'Parent'
    },
    { 'type'    => 28,
      'parser'  => \&ParseType_28_Macro,
      'scaling' => 'None'
    },
    { 'type'    => 29,
      'parser'  => \&ParseType_29_AuxFunctionType1,
      'scaling' => 'SoftKeyMask'
    },
    { 'type'    => 30,
      'parser'  => \&ParseType_30_AuxInputType1,
      'scaling' => 'SoftKeyMask'
    },
    { 'type'    => 31,
      'parser'  => \&ParseType_31_AuxFunctionType2,
      'scaling' => 'SoftKeyMask',
      'function' => { 0 => {'EnumName' => "AuxType_Boolean_Latching"}, 
                      1 => {'EnumName' => "AuxType_Analog" },
                      2 => {'EnumName' => "AuxType_Boolean_Momentary" },
                      3 => {'EnumName' => "AuxType_Analog_ReturnToCenter" },
                      4 => {'EnumName' => "AuxType_Analog_ReturnToZero" },
                      5 => {'EnumName' => "AuxType_DualBoolean_BothLatching" },
                      6 => {'EnumName' => "AuxType_DualBoolean_BothMomentary" },
                      7 => {'EnumName' => "AuxType_DualBoolean_LatchUpMomentaryDown" },
                      8 => {'EnumName' => "AuxType_DualBoolean_LatchDownMomentaryUp" },
                      9 => {'EnumName' => "AuxType_Combined_Analog_ReturnToCenter_DualBoolean_Latching" },
                      10 => {'EnumName' => "AuxType_Combined_Analog_DualBoolean_Latching" },
                      11 => {'EnumName' => "AuxType_QuadratureBoolean_NonLatching" },
                      12 => {'EnumName' => "AuxType_QuadratureAnalog" },
                      13 => {'EnumName' => "AuxType_QuadratureAnalog_ReturnToCenter" },
                      14 => {'EnumName' => "AuxType_BidirectionalEncoder" }
                  }
    },
    { 'type'    => 32,
      'parser'  => \&ParseType_32_AuxInputType2,
      'scaling' => 'SoftKeyMask',
      'function' => { 0 => {'EnumName' => "AuxType_Boolean_Latching" }, 
                      1 => {'EnumName' => "AuxType_Analog" },
                      2 => {'EnumName' => "AuxType_Boolean_Momentary" },
                      3 => {'EnumName' => "AuxType_Analog_ReturnToCenter" },
                      4 => {'EnumName' => "AuxType_Analog_ReturnToZero" },
                      5 => {'EnumName' => "AuxType_DualBoolean_BothLatching" },
                      6 => {'EnumName' => "AuxType_DualBoolean_BothMomentary" },
                      7 => {'EnumName' => "AuxType_DualBoolean_LatchUpMomentaryDown" },
                      8 => {'EnumName' => "AuxType_DualBoolean_LatchDownMomentaryUp" },
                      9 => {'EnumName' => "AuxType_Combined_Analog_ReturnToCenter_DualBoolean_Latching" },
                      10 => {'EnumName' => "AuxType_Combined_Analog_DualBoolean_Latching" },
                      11 => {'EnumName' => "AuxType_QuadratureBoolean_NonLatching" },
                      12 => {'EnumName' => "AuxType_QuadratureAnalog" },
                      13 => {'EnumName' => "AuxType_QuadratureAnalog_ReturnToCenter" },
                      14 => {'EnumName' => "AuxType_BidirectionalEncoder" }
                  }
    },
    { 'type'    => 33,
      'parser'  => \&ParseType_33_AuxControlDesignatorType2ObjectPointer,
      'scaling' => 'SoftKeyMask'
    },
    { 'type'    => 34,
      'parser'  => \&ParseType_34_WindowMask,
      'scaling' => 'DataMask'
    },
    { 'type'    => 35,
      'parser'  => \&ParseType_35_KeyGroup,
      'scaling' => 'SoftKeyMask'
    },
    { 'type'    => 36,
      'parser'  => \&ParseType_36_GraphicsContext,
      'scaling' => 'Parent'
    },
    { 'type'    => 37,
      'parser'  => \&ParseType_37_OutputList,
      'scaling' => 'Parent'
    },
    { 'type'    => 38,
      'parser'  => \&ParseType_38_ExtendedInputAttributes,
      'scaling' => 'Parent'
    },
    { 'type'    => 39,
      'parser'  => \&ParseType_39_ColourMap,
      'scaling' => 'Parent'
    },
    { 'type'    => 40,
      'parser'  => \&ParseType_40_ObjectLabelReferenceList,
      'scaling' => 'SoftKeyMask'
    },
);

1;
