#ifndef VTCLIENT_H
#define VTCLIENT_H
/******************************************************************************/
/*!
   \file
      VTClient API
   \copyright
      Copyright (C) 2016  DISTek Integration, Inc.  All Rights Reserved.
*/
/******************************************************************************/
//! Version of the VTClient Library  (Product,Major,minor,build)
#define VTCLIENT_VERSION SoftwareVersion("VTClient",2,4,0)
//##############################################################################
// Note:  The following macros are for easily initializing the Functionalities_T
//        structure in the Foundation library with the functionalities and
//        Functionality Generations provided by the VTClient library.
//
// EACH APPLICATION MUST REPORT THE CORRECT FUNCTIONALITIES IN ORDER TO PASS THE
// AEF CONFORMANCE TESTS REQUIRED FOR CERTIFICATION
//##############################################################################
/******************************************************************************/
/*!
   \brief  Initializes the Functionalities_T structure for a Universal Terminal
           Working Set
*/
/******************************************************************************/
#define MAKE_Functionalities_T__UniversalTerminal_WorkingSet() MAKE_Functionalities_T ( Functionality_UniversalTerminal_WorkingSet, (FunctionalityGeneration_T)3, 0, (ISOBUS_PacketData_T)0x00, (ISOBUS_PacketData_T)0x00 )
/******************************************************************************/
/*!
   \brief  Initializes the Functionalities_T structure for a Aux-N (Input)
   \param  boolean_latching                                        Provides Aux-N Latching Boolean input
   \param  analog                                                  Provides Aux-N Analog input
   \param  boolean_momentary                                       Provides Aux-N Non-Latching Boolean input
   \param  analog_return_to_center                                 Provides Aux-N Analog return to 50% input
   \param  analog_return_to_zero                                   Provides Aux-N Analog return to 0% input
   \param  dual_boolean_both_latching                              Provides Aux-N Dual Boolean Both Latching input
   \param  dual_boolean_both_momentary                             Provides Aux-N Dual Boolean Both Non-Latching input
   \param  dual_boolean_latch_up_momentary_down                    Provides Aux-N Dual Boolean Latching (Up) Momentary (Down) input
   \param  dual_boolean_latch_down_momentary_up                    Provides Aux-N Dual Boolean Latching (Down) Momentary (Up) input
   \param  combined_analog_return_to_center_dual_boolean_latching  Provides Aux-N Combined Analog return to 50% with Dual Boolean Latching input
   \param  combined_analog_dual_boolean_latching                   Provides Aux-N Combined Analog (maintains position) with Dual Boolean Latching input
   \param  quadrature_boolean_nonlatching                          Provides Aux-N Quadrature Boolean Non-Latching input
   \param  quadrature_analog                                       Provides Aux-N Quadrature Analog (maintains position) input
   \param  quadrature_analog_return_to_center                      Provides Aux-N Quadrature Analog return to 50% input
   \param  bidirectional_encoder                                   Provides Aux-N Bidirectional Encoder input
*/
/******************************************************************************/
#define MAKE_Functionalities_T__Aux_N_Inputs(boolean_latching,analog,boolean_momentary,analog_return_to_center,analog_return_to_zero,dual_boolean_both_latching,dual_boolean_both_momentary,dual_boolean_latch_up_momentary_down,dual_boolean_latch_down_momentary_up,combined_analog_return_to_center_dual_boolean_latching,combined_analog_dual_boolean_latching,quadrature_boolean_nonlatching,quadrature_analog,quadrature_analog_return_to_center,bidirectional_encoder) \
 MAKE_Functionalities_T \
 ( \
 Functionality_Aux_N_Inputs, \
 (FunctionalityGeneration_T)1, \
 2, \
 ( \
 (ISOBUS_PacketData_T)(boolean_latching << 0) | \
 (ISOBUS_PacketData_T)(analog << 1) | \
 (ISOBUS_PacketData_T)(boolean_momentary << 2) | \
 (ISOBUS_PacketData_T)(analog_return_to_center << 3) | \
 (ISOBUS_PacketData_T)(analog_return_to_zero << 4) | \
 (ISOBUS_PacketData_T)(dual_boolean_both_latching << 5) | \
 (ISOBUS_PacketData_T)(dual_boolean_both_momentary << 6) | \
 (ISOBUS_PacketData_T)(dual_boolean_latch_up_momentary_down << 7) \
 ), \
 ( \
 (ISOBUS_PacketData_T)(dual_boolean_latch_down_momentary_up << 0) | \
 (ISOBUS_PacketData_T)(combined_analog_return_to_center_dual_boolean_latching << 1) | \
 (ISOBUS_PacketData_T)(combined_analog_dual_boolean_latching << 2) | \
 (ISOBUS_PacketData_T)(quadrature_boolean_nonlatching << 3) | \
 (ISOBUS_PacketData_T)(quadrature_analog << 4) | \
 (ISOBUS_PacketData_T)(quadrature_analog_return_to_center << 5) | \
 (ISOBUS_PacketData_T)(bidirectional_encoder << 6) \
 ) \
 )
/******************************************************************************/
/*!
   \brief  Initializes the Functionalities_T structure for a Aux-N (Function)
   \param  boolean_latching                                        Supports Aux-N Latching Boolean function
   \param  analog                                                  Supports Aux-N Analog function
   \param  boolean_momentary                                       Supports Aux-N Non-Latching Boolean function
   \param  analog_return_to_center                                 Supports Aux-N Analog return to 50% function
   \param  analog_return_to_zero                                   Supports Aux-N Analog return to 0% function
   \param  dual_boolean_both_latching                              Supports Aux-N Dual Boolean Both Latching function
   \param  dual_boolean_both_momentary                             Supports Aux-N Dual Boolean Both Non-Latching function
   \param  dual_boolean_latch_up_momentary_down                    Supports Aux-N Dual Boolean Latching (Up) Momentary (Down) function
   \param  dual_boolean_latch_down_momentary_up                    Supports Aux-N Dual Boolean Latching (Down) Momentary (Up) function
   \param  combined_analog_return_to_center_dual_boolean_latching  Supports Aux-N Combined Analog return to 50% with Dual Boolean Latching function
   \param  combined_analog_dual_boolean_latching                   Supports Aux-N Combined Analog (maintains position) with Dual Boolean Latching function
   \param  quadrature_boolean_nonlatching                          Supports Aux-N Quadrature Boolean Non-Latching function
   \param  quadrature_analog                                       Supports Aux-N Quadrature Analog (maintains position) function
   \param  quadrature_analog_return_to_center                      Supports Aux-N Quadrature Analog return to 50% function
   \param  bidirectional_encoder                                   Supports Aux-N Bidirectional Encoder function
*/
/******************************************************************************/
#define MAKE_Functionalities_T__Aux_N_Functions(boolean_latching,analog,boolean_momentary,analog_return_to_center,analog_return_to_zero,dual_boolean_both_latching,dual_boolean_both_momentary,dual_boolean_latch_up_momentary_down,dual_boolean_latch_down_momentary_up,combined_analog_return_to_center_dual_boolean_latching,combined_analog_dual_boolean_latching,quadrature_boolean_nonlatching,quadrature_analog,quadrature_analog_return_to_center,bidirectional_encoder) \
 MAKE_Functionalities_T \
 ( \
 Functionality_Aux_N_Functions, \
 (FunctionalityGeneration_T)1, \
 2, \
 ( \
 (ISOBUS_PacketData_T)(boolean_latching << 0) | \
 (ISOBUS_PacketData_T)(analog << 1) | \
 (ISOBUS_PacketData_T)(boolean_momentary << 2) | \
 (ISOBUS_PacketData_T)(analog_return_to_center << 3) | \
 (ISOBUS_PacketData_T)(analog_return_to_zero << 4) | \
 (ISOBUS_PacketData_T)(dual_boolean_both_latching << 5) | \
 (ISOBUS_PacketData_T)(dual_boolean_both_momentary << 6) | \
 (ISOBUS_PacketData_T)(dual_boolean_latch_up_momentary_down << 7) \
 ), \
 ( \
 (ISOBUS_PacketData_T)(dual_boolean_latch_down_momentary_up << 0) | \
 (ISOBUS_PacketData_T)(combined_analog_return_to_center_dual_boolean_latching << 1) | \
 (ISOBUS_PacketData_T)(combined_analog_dual_boolean_latching << 2) | \
 (ISOBUS_PacketData_T)(quadrature_boolean_nonlatching << 3) | \
 (ISOBUS_PacketData_T)(quadrature_analog << 4) | \
 (ISOBUS_PacketData_T)(quadrature_analog_return_to_center << 5) | \
 (ISOBUS_PacketData_T)(bidirectional_encoder << 6) \
 ) \
 )
//! Object Pool Object ID
typedef uint16_t ObjectID_T;
//! Type to store number of pixels
typedef int32_t Pixel_T;
//! Type to store color
typedef uint8_t Colour_T;
//! Type for storing Angle
typedef uint16_t Angle_T;
//! Type to store number of softkeys
typedef uint8_t SoftKeyCount_T;
//! Value indicating a NULL object ID
#define NULL_OBJECT_ID ((ObjectID_T)0xFFFF)
//! Value indicating a NULL object ID for Callbacks
#define EVERY_OBJECT_ID NULL_OBJECT_ID
//! Command/Parameter byte of ECU to VT messages
typedef enum
{
   ECU_SOFT_KEY_ACTIVATION_RESPONSE = 0, // Response
   ECU_BUTTON_ACTIVATION_RESPONSE = 1, // Response
   ECU_POINTING_EVENT_RESPONSE = 2, // Response
   ECU_VT_SELECT_INPUT_OBJECT_RESPONSE = 3, // Response
   ECU_VT_ESC_RESPONSE = 4, // Response
   ECU_VT_CHANGE_NUMERIC_VALUE_RESPONSE = 5, // Response
   ECU_VT_CHANGE_ACTIVE_MASK_RESPONSE = 6, // Response
   ECU_VT_CHANGE_SOFT_KEY_MASK_RESPONSE = 7, // Response
   ECU_VT_CHANGE_STRING_VALUE_RESPONSE = 8, // Response
   ECU_VT_ON_USER_LAYOUT_HIDE_SHOW_RESPONSE = 9, // Response
   ECU_OBJECT_POOL_TRANSFER_MESSAGE = 17, // no VT reply
   ECU_END_OF_OBJECT_POOL_MESSAGE = 18, // ECU command, VT will reply
   ECU_AUXILIARY_ASSIGNMENT_TYPE_1_RESPONSE = 32,
   ECU_AUXILIARY_INPUT_TYPE_1_STATUS = 33, // global, no reply
   ECU_PREFERRED_ASSIGNMENT_COMMAND = 34, // ECU command, VT will reply
   ECU_AUXILIARY_INPUT_TYPE_2_MAINTENANCE_MESSAGE = 35, // ECU command, global, no reply
   ECU_AUXILIARY_ASSIGNMENT_TYPE_2_RESPONSE = 36,
   ECU_AUXILIARY_INPUT_STATUS_TYPE_2_ENABLE_RESPONSE = 37, // Response
   ECU_AUXILIARY_INPUT_TYPE_2_STATUS_MESSAGE = 38, // Aux Input (In learn mode)
   ECU_ESC_COMMAND = 146, // ECU command, VT will reply
   ECU_HIDE_SHOW_OBJECT_COMMAND = 160, // ECU command, VT will reply
   ECU_ENABLE_DISABLE_OBJECT_COMMAND = 161, // ECU command, VT will reply
   ECU_SELECT_INPUT_OBJECT_COMMAND = 162, // ECU command, VT will reply
   ECU_CONTROL_AUDIO_SIGNAL_COMMAND = 163, // ECU command, VT will reply
   ECU_SET_AUDIO_VOLUME_COMMAND = 164, // ECU command, VT will reply
   ECU_CHANGE_CHILD_LOCATION_COMMAND = 165, // ECU command, VT will reply
   ECU_CHANGE_SIZE_COMMAND = 166, // ECU command, VT will reply
   ECU_CHANGE_BACKGROUND_COLOUR_COMMAND = 167, // ECU command, VT will reply
   ECU_CHANGE_NUMERIC_VALUE_COMMAND = 168, // ECU command, VT will reply
   ECU_CHANGE_END_POINT_COMMAND = 169, // ECU command, VT will reply
   ECU_CHANGE_FONT_ATTRIBUTES_COMMAND = 170, // ECU command, VT will reply
   ECU_CHANGE_LINE_ATTRIBUTES_COMMAND = 171, // ECU command, VT will reply
   ECU_CHANGE_FILL_ATTRIBUTES_COMMAND = 172, // ECU command, VT will reply
   ECU_CHANGE_ACTIVE_MASK_COMMAND = 173, // ECU command, VT will reply
   ECU_CHANGE_SOFT_KEY_MASK_COMMAND = 174, // ECU command, VT will reply
   ECU_CHANGE_ATTRIBUTE_COMMAND = 175, // ECU command, VT will reply
   ECU_CHANGE_PRIORITY_COMMAND = 176, // ECU command, VT will reply
   ECU_CHANGE_LIST_ITEM_COMMAND = 177, // ECU command, VT will reply
   ECU_DELETE_OBJECT_POOL_COMMAND = 178, // ECU command, VT will reply
   ECU_CHANGE_STRING_VALUE_COMMAND = 179, // ECU command, VT will reply
   ECU_CHANGE_CHILD_POSITION_COMMAND = 180, // ECU command, VT will reply
   ECU_CHANGE_OBJECT_LABEL_COMMAND = 181, // ECU command, VT will reply
   ECU_CHANGE_POLYGON_POINT_COMMAND = 182, // ECU command, VT will reply
   ECU_CHANGE_POLYGON_SCALE_COMMAND = 183, // ECU command, VT will reply
   ECU_GRAPHICS_CONTEXT_COMMAND = 184, // ECU command, VT will reply
   ECU_GET_ATTRIBUTE_VALUE_MESSAGE = 185, // ECU command, VT will reply
   ECU_SELECT_COLOUR_MAP_COMMAND = 186, // ECU command, VT will reply
   ECU_IDENTIFY_VT_MESSAGE = 187, // ECU command, global, VT reply
   ECU_LOCK_UNLOCK_MASK_COMMAND = 189, // ECU command, VT will reply
   ECU_EXECUTE_MACRO_COMMAND = 190, // ECU command, VT will reply
   ECU_GET_MEMORY_MESSAGE = 192, // ECU command, VT will reply (init)
   ECU_GET_SUPPORTED_WIDECHARS_MESSAGE = 193, // ECU command, VT will reply
   ECU_GET_NUMBER_OF_SOFT_KEYS_MESSAGE = 194, // ECU command, VT will reply (init)
   ECU_GET_TEXT_FONT_DATA_MESSAGE = 195, // ECU command, VT will reply (init)
   ECU_GET_WINDOW_MASK_DATA_MESSAGE = 196, // ECU command, VT will reply
   ECU_GET_SUPPORTED_OBJECTS_MESSAGE = 197, // ECU command, VT will reply
   ECU_GET_HARDWARE_MESSAGE = 199, // ECU command, VT will reply (init)
   ECU_STORE_VERSION_COMMAND = 208, // ECU command, VT will reply
   ECU_LOAD_VERSION_COMMAND = 209, // ECU command, VT will reply
   ECU_DELETE_VERSION_COMMAND = 210, // ECU command, VT will reply
   ECU_GET_VERSIONS_COMMAND = 223, // ECU command, VT will reply in 224 (init)
   ECU_WORKING_SET_MAINTENANCE_MESSAGE = 255 // ECU command, no reply
} ECU_CommandParameter_T;
//! Command/Parameter byte of VT to ECU messages
typedef enum
{
   VT_SOFT_KEY_ACTIVATION_MESSAGE = 0, // VT command, ECU response optional
   VT_BUTTON_ACTIVATION_MESSAGE = 1, // VT command, ECU response optional
   VT_POINTING_EVENT_MESSAGE = 2, // VT command, ECU response optional
   VT_SELECT_INPUT_OBJECT_MESSAGE = 3, // VT command, ECU response optional
   VT_ESC_MESSAGE = 4, // VT command, ECU response optional
   VT_CHANGE_NUMERIC_VALUE_MESSAGE = 5, // VT command, ECU response optional
   VT_CHANGE_ACTIVE_MASK_MESSAGE = 6, // VT command, ECU response optional
   VT_CHANGE_SOFT_KEY_MASK_MESSAGE = 7, // VT command, ECU response optional
   VT_CHANGE_STRING_VALUE_MESSAGE = 8, // VT command, ECU response optional
   VT_ON_USER_LAYOUT_HIDE_SHOW_MESSAGE = 9, // VT command, ECU response optional
   VT_CONTROL_AUDIO_SIGNAL_TERMINATION_MESSAGE = 10, // VT command, no response
   VT_AUXILIARY_ASSIGNMENT_TYPE_1_COMMAND = 32, // VT command, ECU will reply
   VT_PREFERRED_ASSIGNMENT_RESPONSE = 34, // VT response
   VT_AUXILIARY_ASSIGNMENT_TYPE_2_COMMAND = 36, // VT command, ECU will reply
   VT_AUXILIARY_INPUT_STATUS_TYPE_2_ENABLE_COMMAND = 37, // VT command, ECU will reply
   VT_AUXILIARY_INPUT_TYPE_2_STATUS_MESSAGE = 38, // Aux Input (Not in learn mode)
   VT_GET_MEMORY_RESPONSE = 192, // VT response
   VT_GET_VERSIONS_RESPONSE = 224, // ECU reply to VT command 223
   VT_STATUS_MESSAGE = 254 // VT command, global
} VT_CommandParameter_T;
//! VT Object Pool object type
typedef enum
{
   Object_WorkingSetObject = 0,
   Object_DataMaskObject = 1,
   Object_AlarmMaskObject = 2,
   Object_ContainerObject = 3,
   Object_SoftKeyMaskObject = 4,
   Object_KeyObject = 5,
   Object_ButtonObject = 6,
   Object_InputBooleanObject = 7,
   Object_InputStringObject = 8,
   Object_InputNumberObject = 9,
   Object_InputListObject = 10,
   Object_OutputStringObject = 11,
   Object_OutputNumberObject = 12,
   Object_LineObject = 13,
   Object_RectangleObject = 14,
   Object_EllipseObject = 15,
   Object_PolygonObject = 16,
   Object_MeterObject = 17,
   Object_LinearBarGraphObject = 18,
   Object_ArchedBarGraphObject = 19,
   Object_PictureGraphicObject = 20,
   Object_NumberVariableObject = 21,
   Object_StringVariableObject = 22,
   Object_FontAttributesObject = 23,
   Object_LineAttributesObject = 24,
   Object_FillAttributesObject = 25,
   Object_InputAttributesObject = 26,
   Object_ObjectPointerObject = 27,
   Object_MacroObject = 28,
   Object_AuxiliaryFunctionType1Object = 29,
   Object_AuxiliaryInputType1Object = 30,
   Object_AuxiliaryFunctionType2Object = 31,
   Object_AuxiliaryInputType2Object = 32,
   Object_AuxiliaryControlDesignatorType2ObjectPointersObject = 33,
   Object_WindowMaskObject = 34,
   Object_KeyGroupObject = 35,
   Object_GraphicsContextObject = 36,
   Object_OutputListObject = 37,
   Object_ExtendedInputAttributesObject = 38,
   Object_ColourMapObject = 39,
   Object_ObjectLabelReferenceListObject = 40,
   Object_Proprietary_240 = 240,
   Object_Proprietary_241 = 241,
   Object_Proprietary_242 = 242,
   Object_Proprietary_243 = 243,
   Object_Proprietary_244 = 244,
   Object_Proprietary_245 = 245,
   Object_Proprietary_246 = 246,
   Object_Proprietary_247 = 247,
   Object_Proprietary_248 = 248,
   Object_Proprietary_249 = 249,
   Object_Proprietary_250 = 250,
   Object_Proprietary_251 = 251,
   Object_Proprietary_252 = 252,
   Object_Proprietary_253 = 253,
   Object_Proprietary_254 = 254
} Object_T;
/******************************************************************************/
// Annex B  Object definitions
/******************************************************************************/
/******************************************************************************/
// B.1 Working Set object
/******************************************************************************/
/******************************************************************************/
// B.2 Data Mask object
/******************************************************************************/
/******************************************************************************/
// B.3 Alarm Mask object
/******************************************************************************/
//! Type indicating priority of alarm mask
typedef uint8_t AlarmPriority_T;
//! Operator is in danger or urgent machine malfunction
#define ALARM_HIGH_PRIORITY ((AlarmPriority_T)0)
//! Normal alarm, machine is malfunctioning
#define ALARM_MEDIUM_PRIORITY ((AlarmPriority_T)1)
//! Low priority, information only
#define ALARM_LOW_PRIORITY ((AlarmPriority_T)2)
//! Acoustic signal type
typedef uint8_t AcousticSignal_T;
//! Highest priority
#define ACOUSTIC_SIGNAL_HIGH_PRIORITY ((AcousticSignal_T)0)
//! Medium priority
#define ACOUSTIC_SIGNAL_MEDIUM_PRIORITY ((AcousticSignal_T)1)
//! Lowest priority
#define ACOUSTIC_SIGNAL_LOW_PRIORITY ((AcousticSignal_T)2)
//! None (silent)
#define ACOUSTIC_SIGNAL_NONE ((AcousticSignal_T)3)
/******************************************************************************/
// B.4 Container object
/******************************************************************************/
/******************************************************************************/
// B.5 Soft Key Mask object
/******************************************************************************/
/******************************************************************************/
// B.6 Key object
/******************************************************************************/
//! \brief  Key code assigned by ECU.  VT reports this code in the Soft Key Activation message.
//! \note   Key code zero (0) is reserved for use for the ACK means.
typedef uint8_t KeyCode_T;
/******************************************************************************/
// B.7 Button object
/******************************************************************************/
/******************************************************************************/
// B.8 Input field objects
/******************************************************************************/
/******************************************************************************/
// B.8.2 Input Boolean object
/******************************************************************************/
/******************************************************************************/
// B.8.3 Input String object
/******************************************************************************/
/******************************************************************************/
// B.8.4 Input Number object
/******************************************************************************/
/******************************************************************************/
// B.8.5 Input List object
/******************************************************************************/
//! Type to store list indecies
typedef uint8_t ListIndex_T;
/******************************************************************************/
// B.9 Output field objects
/******************************************************************************/
/******************************************************************************/
// B.9.2 Output String object
/******************************************************************************/
/******************************************************************************/
// B.9.3 Output Number object
/******************************************************************************/
/******************************************************************************/
// B.9.4 Output List object
/******************************************************************************/
/******************************************************************************/
// B.10 Output Shape Objects
/******************************************************************************/
/******************************************************************************/
// B.10.2 Line object
/******************************************************************************/
//! Type for storing line direction
typedef uint8_t LineDirection_T;
//! Line is drawn from top left to bottom right of enclosing virtual rectangle
#define LINE_DOWN_RIGHT ((LineDirection_T)0)
//! Line is drawn from top left to bottom right of enclosing virtual rectangle
#define LINE_UP_LEFT LINE_DOWN_RIGHT
//! Line is drawn from bottom left to top right of enclosing virtual rectangle
#define LINE_DOWN_LEFT ((LineDirection_T)1)
//! Line is drawn from bottom left to top right of enclosing virtual rectangle
#define LINE_UP_RIGHT LINE_UP_RIGHT
/******************************************************************************/
// B.10.3 Rectangle object
/******************************************************************************/
//! Type indicating which rectangle border lines are suppressed
typedef uint8_t LineSuppression_T;
//! Suppress Top Line (smallest Y value)
#define SUPPRESS_TOP_LINE ((LineSuppression_T)0x01)
//! Suppress Right Side Line (largest X value)
#define SUPPRESS_RIGHT_LINE ((LineSuppression_T)0x02)
//! Suppress Bottom Line (largest Y value)
#define SUPPRESS_BOTTOM_LINE ((LineSuppression_T)0x04)
//! Suppress Left Side Line (smallest X value)
#define SUPPRESS_LEFT_LINE ((LineSuppression_T)0x08)
/******************************************************************************/
// B.10.4 Ellipse object
/******************************************************************************/
//! Type indicating the type of ellipse
typedef uint8_t EllipseType_T;
//! Closed/Fillable Ellipse (ignores start/end angles)
#define ELLIPSE_CLOSED ((EllipseType_T)0)
//! Open/Non-fillable Ellipse
#define ELLIPSE_OPEN ((EllipseType_T)1)
//! \brief  Closed ellipse segment (fillable - think Pac-Man)
//! \note   If the start and end angles are the same, a single line with (width=border width) shall be drawn from the centre point to the point on the border defined by the start and end angles.  However, the standard is unclear whether or not the ellipse should be filled.
#define ELLIPSE_CLOSED_SEGMENT ((EllipseType_T)2)
//! Closed ellipse section (fillable - thing truncated)
#define ELLIPSE_CLOSED_SECTION ((EllipseType_T)3)
/******************************************************************************/
// B.10.5 Polygon object
/******************************************************************************/
//! Type indicating the type of Polygon
typedef uint8_t PolygonType_T;
//! Convex.  On any given horizontal line, only two points on the polygon are encountered
#define POLYGON_CONVEX ((PolygonType_T)0)
//! Non-Convex.  On any given horizontal line, more than two points on the polygon edges can be encountered but the polygon edges do not cross.
#define POLYGON_NONCONVEX ((PolygonType_T)1)
//! Complex.  On any given horizontal line, more than two points on the polygon edges can be encountered and the polygon edges may cross.
#define POLYGON_COMPLEX ((PolygonType_T)2)
//! Open.  This type cannot be filled.
#define POLYGON_OPEN ((PolygonType_T)3)
/******************************************************************************/
// B.11 Output Graphic Objects
/******************************************************************************/
/******************************************************************************/
// B.11.2 Meter object
/******************************************************************************/
/******************************************************************************/
// B.11.3 Linear Bar Graph object
/******************************************************************************/
/******************************************************************************/
// B.11.4 Arched Bar Graph object
/******************************************************************************/
/******************************************************************************/
// B.12 Picture Graphic object
/******************************************************************************/
//! Picture Graphic options
typedef uint8_t PictureGraphicOptions_T;
//! If transparent, pixels in the bitmap that have the transparency colour show the background or objects underneath.
#define PICTURE_GRAPHIC_TRANSPARENT ((PictureGraphicOptions_T)0x01)
//! Flash style and rate determined by VT design.
#define PICTURE_GRAPHIC_FLASHING ((PictureGraphicOptions_T)0x02)
//! Either the data section is raw data, or run-length encoded.
#define PICTURE_GRAPHIC_RUN_LENGTH_ENCODED ((PictureGraphicOptions_T)0x04)
/******************************************************************************/
// B.13 Variable Objects
/******************************************************************************/
/******************************************************************************/
// B.13.2 Number Variable object
/******************************************************************************/
/******************************************************************************/
// B.13.3 String Variable object
/******************************************************************************/
/******************************************************************************/
// B.14 Attribute Objects
/******************************************************************************/
/******************************************************************************/
// B.14.2 Font Attributes object
/******************************************************************************/
//! Font Size.  If proportional fonts, this indicates the font height in pixels.
typedef uint8_t FontSize_T;
//! Non-proportional font.  6 pixels wide by 8 pixels high
#define FONT_6x8 ((FontSize_T)0)
//! Non-proportional font.  8 pixels wide by 8 pixels high
#define FONT_8x8 ((FontSize_T)1)
//! Non-proportional font.  8 pixels wide by 12 pixels high
#define FONT_8x12 ((FontSize_T)2)
//! Non-proportional font.  12 pixels wide by 16 pixels high
#define FONT_12x16 ((FontSize_T)3)
//! Non-proportional font.  16 pixels wide by 16 pixels high
#define FONT_16x16 ((FontSize_T)4)
//! Non-proportional font.  16 pixels wide by 24 pixels high
#define FONT_16x24 ((FontSize_T)5)
//! Non-proportional font.  24 pixels wide by 32 pixels high
#define FONT_24x32 ((FontSize_T)6)
//! Non-proportional font.  32 pixels wide by 32 pixels high
#define FONT_32x32 ((FontSize_T)7)
//! Non-proportional font.  32 pixels wide by 48 pixels high
#define FONT_32x48 ((FontSize_T)8)
//! Non-proportional font.  48 pixels wide by 64 pixels high
#define FONT_48x64 ((FontSize_T)9)
//! Non-proportional font.  64 pixels wide by 64 pixels high
#define FONT_64x64 ((FontSize_T)10)
//! Non-proportional font.  64 pixels wide by 96 pixels high
#define FONT_64x96 ((FontSize_T)11)
//! Non-proportional font.  96 pixels wide by 128 pixels high
#define FONT_96x128 ((FontSize_T)12)
//! Non-proportional font.  128 pixels wide by 128 pixels high
#define FONT_128x128 ((FontSize_T)13)
//! Non-proportional font.  128 pixels wide by 192 pixels high
#define FONT_128x192 ((FontSize_T)14)
//! Type indicating the ISO 8859 font type (ignored for WideStrings)
typedef uint8_t FontType_T;
//! ISO 8859-1  (ISO Latin 1)
#define FONT_ISO8859_1 ((FontType_T)0)
//! ISO 8859-15  (ISO Latin 9)
#define FONT_ISO8859_15 ((FontType_T)1)
//! \brief  ISO 8859-2  (ISO Latin 2)
//! \note   VTv4 and later
#define FONT_ISO8859_2 ((FontType_T)2)
//! \brief  ISO 8859-4  (ISO Latin 4)
//! \note   VTv4 and later
#define FONT_ISO8859_4 ((FontType_T)4)
//! \brief  ISO 8859-5  (Cyrillic)
//! \note   VTv4 and later
#define FONT_ISO8859_5 ((FontType_T)5)
//! \brief  ISO 8859-7  (Greek)
//! \note   VTv4 and later
#define FONT_ISO8859_7 ((FontType_T)7)
//! Font Style.  These may be combined
typedef uint8_t FontStyle_T;
//! Bold text
#define FONT_BOLD ((FontStyle_T)0x01)
//! Crossed out text
#define FONT_CROSSED_OUT ((FontStyle_T)0x02)
//! Underlined text
#define FONT_UNDERLINED ((FontStyle_T)0x04)
//! Italicized text
#define FONT_ITALIC ((FontStyle_T)0x08)
//! \brief  Inverted text
//! \note   Inverting exchanges background and pen colours.  Background transparency still applies.
#define FONT_INVERTED ((FontStyle_T)0x10)
//! Flashing between Inverted and styles set in other bits.
#define FONT_FLASH_INVERTED ((FontStyle_T)0x20)
//! \brief  Flash both the background and the foreground between Hidden and styles set in other bits.
//! \note   This bit has priority over FONT_FLASH_INVERTED
#define FONT_FLASH_HIDDEN ((FontStyle_T)0x40)
//! \brief  Proportional font rendering
//! \note   VTv4 and later
#define FONT_PROPORTIONAL ((FontStyle_T)0x80)
/******************************************************************************/
// B.14.3 Line Attributes object
/******************************************************************************/
/******************************************************************************/
// B.14.4 Fill Attributes object
/******************************************************************************/
//! Fill Attributes Fill Type
typedef enum FillType_E
{
   //! No fill
   FILL_NO_FILL = 0,
   //! Fill with line colour
   FILL_LINE_COLOUR = 1,
   //! Fill with specified colour in fill colour attribute
   FILL_ATTRIBUTE = 2,
   //! Fill with pattern given by fill pattern attribute
   FILL_PATTERN = 3
} FillType_T;
/******************************************************************************/
// B.14.5 Input Attributes object
/******************************************************************************/
/******************************************************************************/
// B.14.6 Extended Input Attributes object
/******************************************************************************/
/******************************************************************************/
// B.15 Object Pointer object
/******************************************************************************/
/******************************************************************************/
// B.16 Macro object
/******************************************************************************/
//! \todo  Should this just be ObjectID_T?
typedef uint8_t MacroID_T;
/******************************************************************************/
// B.17 Colour Map object
/******************************************************************************/
/******************************************************************************/
// B.18 Graphics Context object
/******************************************************************************/
//! Graphics Context zoom multiplier
typedef float32_t GraphicsZoom_T;
/******************************************************************************/
// B.19 Window Mask object
/******************************************************************************/
//! Options for the Window Mask object
typedef uint8_t WindowMaskOptions_T;
//! Available.  If not set, this window is not available for use at the present time, even though defined.  The VT shall not allow the operator to map it and if already mapped, shall blank out the window cell(s) that it occupies.
#define WINDOW_MASK_AVAILABLE ((WindowMaskOptions_T)0x01)
//! Transparent.  If set, the background colour attribute shall not be used and the Window shall be transparent
#define WINDOW_MASK_TRANSPARENT ((WindowMaskOptions_T)0x02)
/******************************************************************************/
// B.20 Key Group object
/******************************************************************************/
//! Options for the Key Group object
typedef uint8_t KeyGroupOptions_T;
//! Available.  If not set, this object is not available for use at the present time, even though defined.  The VT shall not allow the operator to map it and, if already mapped, shall blank out the key cell(s) that is occupies.
#define KEY_GROUP_AVAILABLE ((KeyGroupOptions_T)0x01)
//! Transparent.  If set, the VT shall ignore the background colour attribute in all child Key Objects and shall set the background colour as desired.
#define KEY_GROUP_TRANSPARENT ((KeyGroupOptions_T)0x02)
/******************************************************************************/
// B.21 Object Label Reference List object
/******************************************************************************/
/******************************************************************************/
// Annex C  Object transport protocol
/******************************************************************************/
/******************************************************************************/
// C.2.3  Object pool transfer message (transport protocol)
/******************************************************************************/
/******************************************************************************/
// C.2.4  End of Object Pool message
/******************************************************************************/
/******************************************************************************/
// C.2.5  End of Object Pool response
/******************************************************************************/
/******************************************************************************/
// Annex D  Technical data messages
/******************************************************************************/
/******************************************************************************/
// D.2  Get Memory message
/******************************************************************************/
/******************************************************************************/
// D.3  Get Memory response
/******************************************************************************/
//! VT version
typedef uint8_t VT_Version_T;
//! Get Memory Status
typedef uint8_t GetMemory_Status_T;
//! There can be enough memory
#define VT_GET_MEMORY_STATUS_ENOUGH_MEMORY ((GetMemory_Status_T)0x00)
//! There is not enough memory available.  Do not transmit object pool
#define VT_GET_MEMORY_STATUS_NOT_ENOUGH_MEMORY ((GetMemory_Status_T)0x01)
//! Data parsed from the "Get Memory Response" message
typedef struct GetMemory_Response_S
{
   //! VT Version
   VT_Version_T Version;
   //! Get Memory Status
   GetMemory_Status_T Status;
} GetMemory_Response_T;
/******************************************************************************/
// D.4  Get Number of Soft Keys message
/******************************************************************************/
/******************************************************************************/
// D.5  Get Number of Soft Keys response
/******************************************************************************/
//! Data from "Get Number of Soft Keys response"
typedef struct GetSoftKeys_Response_S
{
   //! Number of pixels on the X-axis for a Soft Key descriptor
   Pixel_T X_Pixels;
   //! Number of pixels on the Y-axis for a Soft Key descriptor
   Pixel_T Y_Pixels;
   //! Number of Physical Soft Keys
   SoftKeyCount_T Physical;
   //! \brief  Number of possible virtual Soft Keys in a Soft Key Mask
   //! \note  v3 and prior: 6 to 64 (inclusive)
   //! \note  v4 and later: 64
   SoftKeyCount_T Virtual;
   //! Number of Physical Soft Keys used by the VT for navigation among Virtual Soft Keys (VTv4 and later)
   SoftKeyCount_T Navigation;
} GetSoftKeys_Response_T;
/******************************************************************************/
// D.6  Get Text Font Data message
/******************************************************************************/
/******************************************************************************/
// D.7  Get Text Font Data response
/******************************************************************************/
//! \brief  Bitfield indicating supported non-proportional font sizes
//! \note   The bits are shifted slightly from what's in the standard for easier comparison.  This is interpreted correctly in the message handler.
typedef uint16_t SupportedFonts_T;
//! 6x8 font size supported.
#define VT_SMALLFONT_6x8 ((SupportedFonts_T)1 << (SupportedFonts_T)FONT_6x8)
//! 8x8 font size supported.
#define VT_SMALLFONT_8x8 ((SupportedFonts_T)1 << (SupportedFonts_T)FONT_8x8)
//! 8x12 font size supported.
#define VT_SMALLFONT_8x12 ((SupportedFonts_T)1 << (SupportedFonts_T)FONT_8x12)
//! 12x16 font size supported.
#define VT_SMALLFONT_12x16 ((SupportedFonts_T)1 << (SupportedFonts_T)FONT_12x16)
//! 16x16 font size supported.
#define VT_SMALLFONT_16x16 ((SupportedFonts_T)1 << (SupportedFonts_T)FONT_16x16)
//! 16x24 font size supported.
#define VT_SMALLFONT_16x24 ((SupportedFonts_T)1 << (SupportedFonts_T)FONT_16x24)
//! 24x32 font size supported.
#define VT_SMALLFONT_24x32 ((SupportedFonts_T)1 << (SupportedFonts_T)FONT_24x32)
//! 32x32 font size supported.
#define VT_SMALLFONT_32x32 ((SupportedFonts_T)1 << (SupportedFonts_T)FONT_32x32)
//! 32x48 font size supported.
#define VT_LARGEFONT_32x48 ((SupportedFonts_T)1 << (SupportedFonts_T)FONT_32x48)
//! 48x64 font size supported.
#define VT_LARGEFONT_48x64 ((SupportedFonts_T)1 << (SupportedFonts_T)FONT_48x64)
//! 64x64 font size supported.
#define VT_LARGEFONT_64x64 ((SupportedFonts_T)1 << (SupportedFonts_T)FONT_64x64)
//! 64x96 font size supported.
#define VT_LARGEFONT_64x96 ((SupportedFonts_T)1 << (SupportedFonts_T)FONT_64x96)
//! 96x128 font size supported.
#define VT_LARGEFONT_96x128 ((SupportedFonts_T)1 << (SupportedFonts_T)FONT_96x128)
//! 128x128 font size supported.
#define VT_LARGEFONT_128x128 ((SupportedFonts_T)1 << (SupportedFonts_T)FONT_128x128)
//! 128x192 font size supported.
#define VT_LARGEFONT_128x192 ((SupportedFonts_T)1 << (SupportedFonts_T)FONT_128x192)
//! Data from "Get Text Font Data response"
typedef struct GetTextFont_Response_S
{
   //! Supported font sizes
   SupportedFonts_T Sizes;
   //! Supported font styles
   FontStyle_T Styles;
} GetTextFont_Response_T;
/******************************************************************************/
// D.8  Get Hardware message
/******************************************************************************/
/******************************************************************************/
// D.9  Get Hardware response
/******************************************************************************/
//! Values for supported graphic modes (colour depth)
typedef enum VT_GraphicType_E
{
   //! VT supports colour codes 0 and 1 and monochrome Picture Graphic objects only
   VT_Monochrome,
   //! VT supportes colour codes 0 to 15 and monochrome and 16 colour Picture Graphic objects
   VT_16_Colour,
   //! VT supportes colour codes 0 to 255 and monochrome and all formats of Picture Graphic objects
   VT_256_Colour
} VT_GraphicType_T;
//! Supported Hardware Features
typedef uint8_t VT_Features_T;
//! VT has a touch screen and supports Pointing Event message
#define VT_FEATURE_TOUCH_SCREEN ((VT_Features_T)0x01)
//! VT has a pointing device and supports Pointing Event message
#define VT_FEATURE_POINTING_DEVICE ((VT_Features_T)0x02)
//! VT has multiple frequency audio output
#define VT_FEATURE_AUDIO_OUTPUT ((VT_Features_T)0x04)
//! VT has adjustable volume audio output
#define VT_FEATURE_ADJUSTABLE_VOLUME ((VT_Features_T)0x08)
//! \brief  VT supports simultaneous activations of all combinations of Physical Soft Keys
//! \note VTv4 and later
#define VT_FEATURE_SIMULTANEOUS_PHYSICAL_SOFT_KEYS ((VT_Features_T)0x10)
//! \brief  VT supports simultaneous activations of all combinations of Buttons
//! \note VTv4 and later
#define VT_FEATURE_SIMULTANEOUS_BUTTONS ((VT_Features_T)0x20)
//! \brief  VT reports drag operation via Pointing Event message (TouchScreen or PointingDevice shall be set to 1)
//! \note VTv4 and later
#define VT_FEATURE_DRAG_OPERATIONS ((VT_Features_T)0x40)
//! \brief  VT supports intermediate coordinates during a drag operation (DragOperations shall be set to 1)
//! \note VTv4 and later
#define VT_FEATURE_INTERMEDIATE_DRAG ((VT_Features_T)0x80)
//! Data from "Get Hardware response"
typedef struct GetHardware_Response_S
{
   //! \brief  Max time from power cycle to transmission of first "VT Status message" (0xFF when not available)
   //! \todo  VTv4 and later?  Just the 0xFF bit, or whole parameter?
   Time_T BootTime;
   //! Supported graphic modes
   VT_GraphicType_T GraphicType;
   //! Supported Hardware Features
   VT_Features_T Features;
   //! Number of X-axis pixels in data mask
   Pixel_T DataMask_X_Pixels;
   //! Number of Y-axis pixels in data mask
   Pixel_T DataMask_Y_Pixels;
} GetHardware_Response_T;
/******************************************************************************/
// D.10  Get Supported WideChars message
/******************************************************************************/
//! Type to indicate the WideChar Code Plane
typedef uint8_t WideChar_CodePlane_T;
//! Type to indicate a WideChar value (within a codeplane)
typedef uint16_t WideChar_T;
/******************************************************************************/
// D.11  Get Supported WideChars response (transport protocol)
/******************************************************************************/
//! Get Supported WideChars Error Code
typedef uint8_t GetSupportedWideChars_ErrorCode_T;
//! Error Code Bit 0: 1 = Too many ranges (more than 255 sub-ranges in the requested range)
#define GET_WIDE_CHARS_ERROR_TOO_MANY_RANGES ((GetSupportedWideChars_ErrorCode_T)0x01)
//! Error Code Bit 4: 1 = Any other error
#define GET_WIDE_CHARS_ERROR_ANY_OTHER_ERROR ((GetSupportedWideChars_ErrorCode_T)0x10)
//! Data from "Get Supported WideChars response"  (VTv4 and later)
typedef struct GetSupportedWideChars_Response_S
{
   //! WideChar Code Plane
   WideChar_CodePlane_T CodePlane;
   //! First WideChar in inquiry range
   WideChar_T FirstWideChar;
   //! Last WideChar in inquiry range
   WideChar_T LastWideChar;
   //! Error Codes (0 = no errors)
   GetSupportedWideChars_ErrorCode_T ErrorCode;
   //! Indicates the number of entries in the WideChar range array.  Set to zero if Error codes is not equal to 0.
   Size_T NumberOfRanges;
   //! Each entry in the array consists of two WideChars: first WideChar, last WideChar.
   Pipe_ReadHandle_T WideCharRanges;
} GetSupportedWideChars_Response_T;
/******************************************************************************/
// D.12  Get Window Mask Data message
/******************************************************************************/
/******************************************************************************/
// D.13  Get Window Mask Data response
/******************************************************************************/
//! Data from "Get Window Mask Data response"  (VTv4 and later)
typedef struct GetWindowMask_Response_S
{
   //! Background colour of VT's User-Layout Data Masks
   Colour_T UserLayoutBackgroundColour;
   //! Background colour of VT's Key Cells when on a User-Layout Soft Key Mask
   Colour_T KeyCellBackgroundColour;
} GetWindowMask_Response_T;
/******************************************************************************/
// D.14  Get Supported Objects message
/******************************************************************************/
/******************************************************************************/
// D.15  Get Supported Objects response
/******************************************************************************/
//! Data from "Get Supported Objects response"  (VTv4 and later)
typedef struct GetSupportedObjects_Response_S
{
   //! Number of bytes in SupportedObjects
   Size_T NumberOfBytes;
   //! Numerically ascending sorted list of all Object Types supported by the VT
   Pipe_ReadHandle_T SupportedObjects;
} GetSupportedObjects_Response_T;
/******************************************************************************/
// Annex E  Non-volatile memory operations commands
/******************************************************************************/
/******************************************************************************/
// E.2  Get Versions message
/******************************************************************************/
/******************************************************************************/
// E.3  Get Versions response (transport protocol)
/******************************************************************************/
//! Get Version response
typedef struct GetVersions_Response_S
{
   //! Number of Version Labels in the response (7 bytes/characters each)
   Size_T NumberOfVersions;
   //! Pipe handle to the list of received Version Labels
   Pipe_ReadHandle_T Versions;
} GetVersions_Response_T;
/******************************************************************************/
// E.4  Store Version command
/******************************************************************************/
/******************************************************************************/
// E.5  Store Version response
/******************************************************************************/
//! Store Version Error Code
typedef uint8_t StoreVersion_ErrorCode_T;
//! Error Code Bit 1: 1 = Version label is not correct
#define STORE_VERSION_ERROR_INVALID_VERSION_LABEL ((StoreVersion_ErrorCode_T)0x02)
//! Error Code Bit 2: 1 = Insufficient memory available
#define STORE_VERSION_ERROR_INSUFFICIENT_MEMORY ((StoreVersion_ErrorCode_T)0x04)
//! Error Code Bit 3: 1 = General error
#define STORE_VERSION_ERROR_GENERAL_ERROR ((StoreVersion_ErrorCode_T)0x08)
//! Store Version response
typedef struct StoreVersion_Response_S
{
   //! Error Codes (0 = no errors)
   StoreVersion_ErrorCode_T error_code;
} StoreVersion_Response_T;
/******************************************************************************/
// E.6  Load Version command
/******************************************************************************/
/******************************************************************************/
// E.7  Load Version response
/******************************************************************************/
//! Load Version Error Code
typedef uint8_t LoadVersion_ErrorCode_T;
//! Error Code byte: 0 = no errors
#define LOAD_VERSION_NO_ERROR ((LoadVersion_ErrorCode_T)0x00)
//! Error Code Bit 0: 1 = Unsuccessfully loaded, file system error or pool data corruption
#define LOAD_VERSION_ERROR_UNSUCCESSFULLY_LOADED ((LoadVersion_ErrorCode_T)0x01)
//! Error Code Bit 1: 1 = Version label is not correct or Version label unknown
#define LOAD_VERSION_ERROR_INVALID_VERSION_LABEL ((LoadVersion_ErrorCode_T)0x02)
//! Error Code Bit 2: 1 = Insufficient memory available
#define LOAD_VERSION_ERROR_INSUFFICIENT_MEMORY ((LoadVersion_ErrorCode_T)0x04)
//! Error Code Bit 3: 1 = General error
#define LOAD_VERSION_ERROR_GENERAL_ERROR ((LoadVersion_ErrorCode_T)0x08)
//! Load Version response
typedef struct LoadVersion_Response_S
{
   //! Error Codes (0 = no errors)
   LoadVersion_ErrorCode_T error_code;
} LoadVersion_Response_T;
/******************************************************************************/
// E.8  Delete Version command
/******************************************************************************/
/******************************************************************************/
// E.9  Delete Version response
/******************************************************************************/
//! Delete Version Error Code
typedef uint8_t DeleteVersion_ErrorCode_T;
//! Error Code Bit 1: 1 = Version label is not correct
#define DELETE_VERSION_ERROR_INVALID_VERSION_LABEL ((DeleteVersion_ErrorCode_T)0x02)
//! Error Code Bit 3: 1 = General error
#define DELETE_VERSION_ERROR_GENERAL_ERROR ((DeleteVersion_ErrorCode_T)0x08)
//! Delete Version response
typedef struct DeleteVersion_Response_S
{
   //! Error Codes (0 = no errors)
   DeleteVersion_ErrorCode_T error_code;
} DeleteVersion_Response_T;
/******************************************************************************/
// Annex F  Command and Macro messages
/******************************************************************************/
/******************************************************************************/
// F.2  Hide/Show Object command
/******************************************************************************/
//! Enumeration to indicate whether or not an object is visible
typedef enum ShowHide_Status_E
{
   //! Object is not visible
   Object_Hidden = 0,
   //! Object is visible
   Object_Shown = 1
} ShowHide_Status_T;
/******************************************************************************/
// F.3  Hide/Show Object response
/******************************************************************************/
//! Hide/Show Error Code
typedef uint8_t HideShowObject_ErrorCode_T;
//! Error Code Bit 0: 1 = References to missing objects
#define HIDE_SHOW_ERROR_REFERENCE_TO_MISSING_OBJECT ((HideShowObject_ErrorCode_T)0x01)
//! Error Code Bit 1: 1 = Invalid object ID
#define HIDE_SHOW_ERROR_INVALID_OBJECT_ID ((HideShowObject_ErrorCode_T)0x02)
//! Error Code Bit 2: 1 = Command error
#define HIDE_SHOW_ERROR_COMMAND_ERROR ((HideShowObject_ErrorCode_T)0x04)
//! Error Code Bit 4: 1 = Any other error
#define HIDE_SHOW_ERROR_ANY_OTHER_ERROR ((HideShowObject_ErrorCode_T)0x10)
//! Hide/Show Object response
typedef struct HideShowObject_Response_S
{
   //! Object ID
   ObjectID_T object_id;
   //! Object visibility
   ShowHide_Status_T hide_show_status;
   //! Error Codes (0 = no errors)
   HideShowObject_ErrorCode_T error_code;
} HideShowObject_Response_T;
/******************************************************************************/
// F.4  Enable/Disable Object command
/******************************************************************************/
//! Enumeration to indicate whether or not an object is enabled
typedef enum EnableDisable_Status_E
{
   //! Object is disabled
   Object_Disabled = 0,
   //! Object is enabled
   Object_Enabled = 1
} EnableDisable_Status_T;
/******************************************************************************/
// F.5  Enable/Disable Object response
/******************************************************************************/
//! Enable/Disable Error Code
typedef uint8_t EnableDisableObject_ErrorCode_T;
//! Error Code Bit 1: 1 = Invalid object ID
#define ENABLE_DISABLE_ERROR_INVALID_OBJECT_ID ((EnableDisableObject_ErrorCode_T)0x02)
//! Error Code Bit 2: 1 = Command error
#define ENABLE_DISABLE_ERROR_COMMAND_ERROR ((EnableDisableObject_ErrorCode_T)0x04)
//! Error Code Bit 3: 1 = Could not complete. Operator input is active on this object.
#define ENABLE_DISABLE_ERROR_OPERATOR_INPUT_ACTIVE ((EnableDisableObject_ErrorCode_T)0x08)
//! Error Code Bit 4: 1 = Any other error
#define ENABLE_DISABLE_ERROR_ANY_OTHER_ERROR ((EnableDisableObject_ErrorCode_T)0x10)
//! Enable/Disable Object response
typedef struct EnableDisableObject_Response_S
{
   //! Object ID
   ObjectID_T object_id;
   //! Object Enabled state
   EnableDisable_Status_T enable_disable_status;
   //! Error Codes (0 = no errors)
   EnableDisableObject_ErrorCode_T error_code;
} EnableDisableObject_Response_T;
/******************************************************************************/
// F.6  Select Input Object command
/******************************************************************************/
//! Selection State of Input Object
typedef enum Object_SelectionState_E
{
   //! Object is not selected
   Object_NotSelected = 0,
   //! Object is selected (but not opened for input)
   Object_Selected = 1,
   //! Object is selected and opened for input
   Object_SelectedAndOpenForEdit = 2
} Object_SelectionState_T;
/******************************************************************************/
// F.7  Select Input Object response
/******************************************************************************/
//! Select Input Object Error Code
typedef uint8_t SelectInputObject_ErrorCode_T;
//! Error Code Bit 0: 1 = Object is disabled
#define SELECT_INPUT_ERROR_OBJECT_DISABLED ((SelectInputObject_ErrorCode_T)0x01)
//! Error Code Bit 1: 1 = Invalid object ID
#define SELECT_INPUT_ERROR_INVALID_OBJECT_ID ((SelectInputObject_ErrorCode_T)0x02)
//! Error Code Bit 2: 1 = Object is not on the active mask or object is in a hidden container
#define SELECT_INPUT_ERROR_OBJECT_NOT_VISIBLE ((SelectInputObject_ErrorCode_T)0x04)
//! Error Code Bit 3: 1 = Could not complete. Another Input field is currently being modified, or a button or Soft Key is currently being held.
#define SELECT_INPUT_ERROR_OPERATOR_INPUT_ACTIVE ((SelectInputObject_ErrorCode_T)0x08)
//! Error Code Bit 4: 1 = Any other error
#define SELECT_INPUT_ERROR_ANY_OTHER_ERROR ((SelectInputObject_ErrorCode_T)0x10)
//! Error Code Bit 5: 1 = Invalid Option value
#define SELECT_INPUT_ERROR_INVALID_OPTION ((SelectInputObject_ErrorCode_T)0x20)
//! Select Input Object response
typedef struct SelectInputObject_Response_S
{
   //! Object ID
   ObjectID_T object_id;
   //! Input Selection State
   Object_SelectionState_T SelectState;
   //! Error Codes (0 = no errors)
   SelectInputObject_ErrorCode_T error_code;
} SelectInputObject_Response_T;
/******************************************************************************/
// F.8  ESC command
/******************************************************************************/
/******************************************************************************/
// F.9  ESC response
/******************************************************************************/
//! ESC Error Code
typedef uint8_t Esc_ErrorCode_T;
//! Error Code Bit 0: 1 = No input field is open for input, ESC ignored.
#define ESC_ERROR_IGNORED ((Esc_ErrorCode_T)0x01)
//! Error Code Bit 4: 1 = Any other error
#define ESC_ERROR_ANY_OTHER_ERROR ((Esc_ErrorCode_T)0x10)
//! ESC response
typedef struct Esc_Response_S
{
   //! Object ID where input was aborted if no error code
   ObjectID_T object_id;
   //! Error Codes (0 = no errors)
   Esc_ErrorCode_T error_code;
} Esc_Response_T;
/******************************************************************************/
// F.10  Control Audio Signal command
/******************************************************************************/
//! Number of Audio Signal activations (how many times to repeat)
typedef uint8_t AudioSignalActivation_T;
/******************************************************************************/
// F.11  Control Audio Signal response
/******************************************************************************/
//! Control Audio Signal Error Code
typedef uint8_t ControlAudioSignal_ErrorCode_T;
//! Error Code Bit 0: 1 = Audio device is busy
#define AUDIO_SIGNAL_ERROR_IGNORED ((ControlAudioSignal_ErrorCode_T)0x01)
//! Error Code Bit 4: 1 = Any other error
#define AUDIO_SIGNAL_ERROR_ANY_OTHER_ERROR ((ControlAudioSignal_ErrorCode_T)0x10)
//! Control Audio Signal response
typedef struct ControlAudioSignal_Response_S
{
   //! Error Codes (0 = no errors)
   ControlAudioSignal_ErrorCode_T error_code;
} ControlAudioSignal_Response_T;
/******************************************************************************/
// F.12  Set Audio Volume command
/******************************************************************************/
//! Volume as % of max value (0-100)
typedef uint8_t AudioVolume_T;
/******************************************************************************/
// F.13  Set Audio Volume response
/******************************************************************************/
//! Set Audio Volume Error Code
typedef uint8_t SetAudioVolume_ErrorCode_T;
//! Error Code Bit 0: 1 = Audio device is busy
#define AUDIO_VOLUME_ERROR_IGNORED ((SetAudioVolume_ErrorCode_T)0x01)
//! Error Code Bit 4: 1 = Any other error
#define AUDIO_VOLUME_ERROR_ANY_OTHER_ERROR ((SetAudioVolume_ErrorCode_T)0x10)
//! Set Audio Volume response
typedef struct SetAudioVolume_Response_S
{
   //! Error Codes (0 = no error)
   SetAudioVolume_ErrorCode_T error_code;
} SetAudioVolume_Response_T;
/******************************************************************************/
// F.14  Change Child Location command
/******************************************************************************/
/******************************************************************************/
// F.15  Change Child Location response
/******************************************************************************/
//! Change Child Location Error Code
typedef uint8_t ChangeChildLocation_ErrorCode_T;
//! Error Code Bit 0: 1 = Invalid Parent Object ID
#define CHANGE_CHILD_LOCATION_ERROR_INVALID_PARENT_OBJECT_ID ((ChangeChildLocation_ErrorCode_T)0x01)
//! Error Code Bit 1: 1 = Invalid Object ID
#define CHANGE_CHILD_LOCATION_ERROR_INVALID_OBJECT_ID ((ChangeChildLocation_ErrorCode_T)0x02)
//! Error Code Bit 4: 1 = Any other error
#define CHANGE_CHILD_LOCATION_ERROR_ANY_OTHER_ERROR ((ChangeChildLocation_ErrorCode_T)0x10)
//! Change Child Location response
typedef struct ChangeChildLocation_Response_S
{
   //! Parent Object ID
   ObjectID_T parent_object_id;
   //! Object ID of object to move
   ObjectID_T object_id;
   //! Error Codes (0 = no error)
   ChangeChildLocation_ErrorCode_T error_code;
} ChangeChildLocation_Response_T;
/******************************************************************************/
// F.16  Change Child Position command
/******************************************************************************/
/******************************************************************************/
// F.17  Change Child Position response
/******************************************************************************/
//! Change Child Position Error Code
typedef uint8_t ChangeChildPosition_ErrorCode_T;
//! Error Code Bit 0: 1 = Invalid Parent Object ID
#define CHANGE_CHILD_POSITION_ERROR_INVALID_PARENT_OBJECT_ID ((ChangeChildPosition_ErrorCode_T)0x01)
//! Error Code Bit 1: 1 = Invalid Object ID
#define CHANGE_CHILD_POSITION_ERROR_INVALID_OBJECT_ID ((ChangeChildPosition_ErrorCode_T)0x02)
//! Error Code Bit 4: 1 = Any other error
#define CHANGE_CHILD_POSITION_ERROR_ANY_OTHER_ERROR ((ChangeChildPosition_ErrorCode_T)0x10)
//! Change Child Position response
typedef struct ChangeChildPosition_Response_S
{
   //! Parent Object ID
   ObjectID_T parent_object_id;
   //! Object ID of object to move
   ObjectID_T object_id;
   //! Error Codes (0 = no error)
   ChangeChildPosition_ErrorCode_T error_code;
} ChangeChildPosition_Response_T;
/******************************************************************************/
// F.18  Change Size command
/******************************************************************************/
/******************************************************************************/
// F.19  Change Size response
/******************************************************************************/
//! Change Size Error Code
typedef uint8_t ChangeSize_ErrorCode_T;
//! Error Code Bit 0: 1 = Invalid Object ID
#define CHANGE_SIZE_ERROR_INVALID_OBJECT_ID ((ChangeSize_ErrorCode_T)0x01)
//! Error Code Bit 4: 1 = Any other error
#define CHANGE_SIZE_ERROR_ANY_OTHER_ERROR ((ChangeSize_ErrorCode_T)0x10)
//! Change Size response
typedef struct ChangeSize_Response_S
{
   //! Object ID of object to size
   ObjectID_T object_id;
   //! Error Codes (0 = no error)
   ChangeSize_ErrorCode_T error_code;
} ChangeSize_Response_T;
/******************************************************************************/
// F.20  Change Background Colour command
/******************************************************************************/
/******************************************************************************/
// F.21  Change Background Colour response
/******************************************************************************/
//! Change Background Colour Error Code
typedef uint8_t ChangeBackgroundColour_ErrorCode_T;
//! Error Code Bit 0: 1 = Invalid Object ID
#define CHANGE_BACKGROUND_COLOUR_ERROR_INVALID_OBJECT_ID ((ChangeBackgroundColour_ErrorCode_T)0x01)
//! Error Code Bit 1: 1 = Invalid colour code
#define CHANGE_BACKGROUND_COLOUR_ERROR_INVALID_COLOUR_CODE ((ChangeBackgroundColour_ErrorCode_T)0x02)
//! Error Code Bit 4: 1 = Any other error
#define CHANGE_BACKGROUND_COLOUR_ERROR_ANY_OTHER_ERROR ((ChangeBackgroundColour_ErrorCode_T)0x10)
//! Change Background Colour response
typedef struct ChangeBackgroundColour_Response_S
{
   //! Object ID
   ObjectID_T object_id;
   //! New Background colour
   Colour_T new_color;
   //! Error Codes (0 = no error)
   ChangeBackgroundColour_ErrorCode_T error_code;
} ChangeBackgroundColour_Response_T;
/******************************************************************************/
// F.22  Change Numeric Value command
/******************************************************************************/
//! Stores generic numeric value
typedef uint32_t NumericValue_T;
/******************************************************************************/
// F.23  Change Numeric Value response
/******************************************************************************/
//! Change Numeric Value Error Code
typedef uint8_t ChangeNumericValue_ErrorCode_T;
//! Error Code Bit 0: 1 = Invalid Object ID
#define CHANGE_NUMERIC_VALUE_ERROR_INVALID_OBJECT_ID ((ChangeNumericValue_ErrorCode_T)0x01)
//! Error Code Bit 1: 1 = Invalid value
#define CHANGE_NUMERIC_VALUE_ERROR_INVALID_VALUE ((ChangeNumericValue_ErrorCode_T)0x02)
//! Error Code Bit 2: 1 = Value in use (e.g. open for input)
#define CHANGE_NUMERIC_VALUE_ERROR_VALUE_IN_USE ((ChangeNumericValue_ErrorCode_T)0x04)
//! Error Code Bit 4: 1 = Any other error
#define CHANGE_NUMERIC_VALUE_ERROR_ANY_OTHER_ERROR ((ChangeNumericValue_ErrorCode_T)0x10)
//! Change Numeric Value response
typedef struct ChangeNumericValue_Response_S
{
   //! Object ID
   ObjectID_T object_id;
   //! Value: Size depends on object type. Objects of size 1 byte are found in byte 5.
   //! Objects of size 2 bytes are found in Bytes 5-6. Values greater than 1 byte are
   //! transmitted little endian (LSB first).
   //! \todo - If the object type is less than 4-bytes, are the remaining bytes sent as 0?
   NumericValue_T value;
   //! Error Codes (0 = no error)
   ChangeNumericValue_ErrorCode_T error_code;
} ChangeNumericValue_Response_T;
/******************************************************************************/
// F.24  Change String Value command
/******************************************************************************/
/******************************************************************************/
// F.25  Change String Value response
/******************************************************************************/
//! Change String Value Error Code
typedef uint8_t ChangeStringValue_ErrorCode_T;
//! Error Code Bit 1: 1 = Invalid Object ID
#define CHANGE_STRING_VALUE_ERROR_INVALID_OBJECT_ID ((ChangeStringValue_ErrorCode_T)0x02)
//! Error Code Bit 2: 1 = String too long
#define CHANGE_STRING_VALUE_ERROR_STRING_TOO_LONG ((ChangeStringValue_ErrorCode_T)0x04)
//! Error Code Bit 3: 1 = Any other error
#define CHANGE_STRING_VALUE_ERROR_ANY_OTHER_ERROR ((ChangeStringValue_ErrorCode_T)0x08)
//! Error Code Bit 4: 1 = Value in use (e.g. open for input)
#define CHANGE_STRING_VALUE_ERROR_VALUE_IN_USE ((ChangeStringValue_ErrorCode_T)0x10)
//! Change String Value response
typedef struct ChangeStringValue_Response_S
{
   //! Object ID of the object to change
   ObjectID_T object_id;
   //! Error Codes (0 = no error)
   ChangeStringValue_ErrorCode_T error_code;
} ChangeStringValue_Response_T;
/******************************************************************************/
// F.26  Change End Point command
/******************************************************************************/
/******************************************************************************/
// F.27  Change End Point response
/******************************************************************************/
//! Change End Point Error Code
typedef uint8_t ChangeEndPoint_ErrorCode_T;
//! Error Code Bit 0: 1 = Invalid Object ID
#define CHANGE_END_POINT_ERROR_INVALID_OBJECT_ID ((ChangeEndPoint_ErrorCode_T)0x01)
//! Error Code Bit 1: 1 = Invalid Line Direction
#define CHANGE_END_POINT_ERROR_INVALID_LINE_DIRECTION ((ChangeEndPoint_ErrorCode_T)0x02)
//! Error Code Bit 4: 1 = Any other error
#define CHANGE_END_POINT_ERROR_ANY_OTHER_ERROR ((ChangeEndPoint_ErrorCode_T)0x10)
//! Change End Point response
typedef struct ChangeEndPoint_Response_S
{
   //! Object ID
   ObjectID_T object_id;
   //! Error Codes (0 = no error)
   ChangeEndPoint_ErrorCode_T error_code;
} ChangeEndPoint_Response_T;
/******************************************************************************/
// F.28  Change Font Attributes command
/******************************************************************************/
/******************************************************************************/
// F.29  Change Font Attributes response
/******************************************************************************/
//! Change Font Attributes Error Code
typedef uint8_t ChangeFontAttributes_ErrorCode_T;
//! Error Code Bit 0: 1 = Invalid object ID
#define CHANGE_FONT_ATTRIBUTES_ERROR_INVALID_OBJECT_ID ((ChangeFontAttributes_ErrorCode_T)0x01)
//! Error Code Bit 1: 1 = Invalid colour
#define CHANGE_FONT_ATTRIBUTES_ERROR_INVALID_COLOUR ((ChangeFontAttributes_ErrorCode_T)0x02)
//! Error Code Bit 2: 1 = Invalid size
#define CHANGE_FONT_ATTRIBUTES_ERROR_INVALID_SIZE ((ChangeFontAttributes_ErrorCode_T)0x04)
//! Error Code Bit 3: 1 = Invalid type
#define CHANGE_FONT_ATTRIBUTES_ERROR_INVALID_TYPE ((ChangeFontAttributes_ErrorCode_T)0x08)
//! Error Code Bit 4: 1 = Invalid style
#define CHANGE_FONT_ATTRIBUTES_ERROR_INVALID_STYLE ((ChangeFontAttributes_ErrorCode_T)0x10)
//! Error Code Bit 5: 1 = Any other error
#define CHANGE_FONT_ATTRIBUTES_ERROR_ANY_OTHER_ERROR ((ChangeFontAttributes_ErrorCode_T)0x20)
//! Change Font Attributes response
typedef struct ChangeFontAttributes_Response_S
{
   //! Object ID
   ObjectID_T object_id;
   //! Error Codes (0 = no error)
   ChangeFontAttributes_ErrorCode_T error_code;
} ChangeFontAttributes_Response_T;
/******************************************************************************/
// F.30  Change Line Attributes command
/******************************************************************************/
//! \brief    Type for passing Line Art
//! \details  Bit pattern art for line.  Each bit represents a paintbrush spot.
//!           Zero (0) bits are skipped (background colour) and one (1) bits
//!           are drawn in the line colour.  Each bit is the size of the current
//!           paintbrush.  For example, 00110011 would represent two skipped
//!           paintbrush spots followed by two paintbrush spots drawn and so on.
typedef uint16_t LineArt_T;
/******************************************************************************/
// F.31  Change Line Attributes response
/******************************************************************************/
//! Change Line Attributes Error Code
typedef uint8_t ChangeLineAttributes_ErrorCode_T;
//! Error Code Bit 0: 1 = Invalid Object ID
#define CHANGE_LINE_ATTRIBUTES_ERROR_INVALID_OBJECT_ID ((ChangeLineAttributes_ErrorCode_T)0x01)
//! Error Code Bit 1: 1 = Invalid colour
#define CHANGE_LINE_ATTRIBUTES_ERROR_INVALID_COLOUR ((ChangeLineAttributes_ErrorCode_T)0x02)
//! Error Code Bit 2: 1 = Invalid width
#define CHANGE_LINE_ATTRIBUTES_ERROR_INVALID_WIDTH ((ChangeLineAttributes_ErrorCode_T)0x04)
//! Error Code Bit 4: 1 = Any other error
#define CHANGE_LINE_ATTRIBUTES_ERROR_ANY_OTHER_ERROR ((ChangeLineAttributes_ErrorCode_T)0x10)
//! Change Line Attributes response
typedef struct ChangeLineAttributes_Response_S
{
   //! Object ID
   ObjectID_T object_id;
   //! Error Codes (0 = no error)
   ChangeLineAttributes_ErrorCode_T error_code;
} ChangeLineAttributes_Response_T;
/******************************************************************************/
// F.32  Change Fill Attributes command
/******************************************************************************/
/******************************************************************************/
// F.33  Change Fill Attributes response
/******************************************************************************/
//! Change Fill Attributes Error Code
typedef uint8_t ChangeFillAttributes_ErrorCode_T;
//! Error Code Bit 0: 1 = Invalid Object ID
#define CHANGE_FILL_ATTRIBUTES_ERROR_INVALID_OBJECT_ID ((ChangeFillAttributes_ErrorCode_T)0x01)
//! Error Code Bit 1: 1 = Invalid type
#define CHANGE_FILL_ATTRIBUTES_ERROR_INVALID_TYPE ((ChangeFillAttributes_ErrorCode_T)0x02)
//! Error Code Bit 2: 1 = Invalid colour
#define CHANGE_FILL_ATTRIBUTES_ERROR_INVALID_COLOUR ((ChangeFillAttributes_ErrorCode_T)0x04)
//! Error Code Bit 3: 1 = Invalid pattern object ID
#define CHANGE_FILL_ATTRIBUTES_ERROR_INVALID_PATTERN_OBJECT ((ChangeFillAttributes_ErrorCode_T)0x08)
//! Error Code Bit 4: 1 = Any other error
#define CHANGE_FILL_ATTRIBUTES_ERROR_ANY_OTHER_ERROR ((ChangeFillAttributes_ErrorCode_T)0x10)
//! Change Fill Attributes response
typedef struct ChangeFillAttributes_Response_S
{
   //! Object ID
   ObjectID_T object_id;
   //! Error Codes (0 = no error)
   ChangeFillAttributes_ErrorCode_T error_code;
} ChangeFillAttributes_Response_T;
/******************************************************************************/
// F.34  Change Active Mask command
/******************************************************************************/
/******************************************************************************/
// F.35  Change Active Mask response
/******************************************************************************/
//! Change Active Mask Error Code
typedef uint8_t ChangeActiveMask_ErrorCode_T;
//! Error Code Bit 0: 1 = Invalid Working Set Object ID
#define CHANGE_ACTIVE_MASK_ERROR_INVALID_WORKING_SET ((ChangeActiveMask_ErrorCode_T)0x01)
//! Error Code Bit 1: 1 = Invalid Mask Object ID
#define CHANGE_ACTIVE_MASK_ERROR_INVALID_MASK ((ChangeActiveMask_ErrorCode_T)0x02)
//! Error Code Bit 4: 1 = Any other error
#define CHANGE_ACTIVE_MASK_ERROR_ANY_OTHER_ERROR ((ChangeActiveMask_ErrorCode_T)0x10)
//! Change Active Mask response
typedef struct ChangeActiveMask_Response_S
{
   //! New Active Mask Object ID
   ObjectID_T new_mask_object_id;
   //! Error Codes (0 = no error)
   ChangeActiveMask_ErrorCode_T error_code;
} ChangeActiveMask_Response_T;
/******************************************************************************/
// F.36  Change Soft Key Mask command
/******************************************************************************/
//! Type of Mask (Data or Alarm)
typedef enum MaskType_E
{
   //! Data Mask
   Mask_DataMask = 1,
   //! Alarm Mask
   Mask_AlarmMask = 2
} MaskType_T;
/******************************************************************************/
// F.37  Change Soft Key Mask response
/******************************************************************************/
//! Change Soft Key Mask Error Code
typedef uint8_t ChangeSoftKeyMask_ErrorCode_T;
//! Error Code Bit 0: 1 = Invalid Data or Alarm Mask Object ID
#define CHANGE_SOFT_KEY_MASK_ERROR_INVALID_DATA_ALARM_MASK ((ChangeSoftKeyMask_ErrorCode_T)0x01)
//! Error Code Bit 1: 1 = Invalid Soft Key Mask Object ID
#define CHANGE_SOFT_KEY_MASK_ERROR_INVALID_SOFT_KEY_MASK ((ChangeSoftKeyMask_ErrorCode_T)0x02)
//! Error Code Bit 2: 1 = Missing Objects
#define CHANGE_SOFT_KEY_MASK_ERROR_MISSING_OBJECTS ((ChangeSoftKeyMask_ErrorCode_T)0x04)
//! Error Code Bit 3: 1 = Mask or child object has errors
#define CHANGE_SOFT_KEY_MASK_ERROR_MASK_OR_OBJECT_ERRORS ((ChangeSoftKeyMask_ErrorCode_T)0x08)
//! Error Code Bit 4: 1 = Any other error
#define CHANGE_SOFT_KEY_MASK_ERROR_ANY_OTHER_ERROR ((ChangeSoftKeyMask_ErrorCode_T)0x10)
//! Change Soft Key Mask response
typedef struct ChangeSoftKeyMask_Response_S
{
   //! Data or Alarm Mask Object ID
   ObjectID_T mask_object_id;
   //! Soft Key Mask Object ID
   ObjectID_T soft_key_mask_object_id;
   //! Error Codes (0 = no error)
   ChangeSoftKeyMask_ErrorCode_T error_code;
} ChangeSoftKeyMask_Response_T;
/******************************************************************************/
// F.38  Change Attribute command
/******************************************************************************/
//! Attribute ID
typedef uint8_t AttributeID_T;
//! Attribute Value
typedef uint32_t AttributeValue_T;
/******************************************************************************/
// F.39  Change Attribute response
/******************************************************************************/
//! Change Attribute Error Code
typedef uint8_t ChangeAttribute_ErrorCode_T;
//! Error Code Bit 0: 1 = Invalid Object ID
#define CHANGE_ATTRUBUTE_ERROR_INVALID_OBJECT_ID ((ChangeAttribute_ErrorCode_T)0x01)
//! Error Code Bit 1: 1 = Invalid Attribute ID
#define CHANGE_ATTRUBUTE_ERROR_INVALID_ATTRIBUTE_ID ((ChangeAttribute_ErrorCode_T)0x02)
//! Error Code Bit 2: 1 = Invalid value
#define CHANGE_ATTRUBUTE_ERROR_INVALID_VALUE ((ChangeAttribute_ErrorCode_T)0x04)
//! Error Code Bit 3: 1 = Value in use (e.g. open for input)
#define CHANGE_ATTRUBUTE_ERROR_VALUE_IN_USE ((ChangeAttribute_ErrorCode_T)0x08)
//! Error Code Bit 4: 1 = Any other error
#define CHANGE_ATTRUBUTE_ERROR_ANY_OTHER_ERROR ((ChangeAttribute_ErrorCode_T)0x10)
//! Change Attribute response
typedef struct ChangeAttribute_Response_S
{
   //! Object ID
   ObjectID_T object_id;
   //! Attribute ID (AID)
   AttributeID_T attribute_id;
   //! Error Codes (0 = no error)
   ChangeAttribute_ErrorCode_T error_code;
} ChangeAttribute_Response_T;
/******************************************************************************/
// F.40  Change Priority command
/******************************************************************************/
/******************************************************************************/
// F.41  Change Priority response
/******************************************************************************/
//! Change Priority Error Code
typedef uint8_t ChangePriority_ErrorCode_T;
//! Error Code Bit 0: 1 = Invalid Object ID
#define CHANGE_PRIORITY_ERROR_INVALID_OBJECT_ID ((ChangePriority_ErrorCode_T)0x01)
//! Error Code Bit 1: 1 = Invalid priority
#define CHANGE_PRIORITY_ERROR_INVALID_PRIORITY ((ChangePriority_ErrorCode_T)0x02)
//! Error Code Bit 4: 1 = Any other error
#define CHANGE_PRIORITY_ERROR_ANY_OTHER_ERROR ((ChangePriority_ErrorCode_T)0x10)
//! Change Priority response
typedef struct ChangePriority_Response_S
{
   //! Object ID of Alarm Mask
   ObjectID_T object_id;
   //! New priority
   AlarmPriority_T new_priority;
   //! Error Codes (0 = no error)
   ChangePriority_ErrorCode_T error_code;
} ChangePriority_Response_T;
/******************************************************************************/
// F.42  Change List Item command
/******************************************************************************/
/******************************************************************************/
// F.43  Change List Item response
/******************************************************************************/
//! Change List Item Error Code
typedef uint8_t ChangeListItem_ErrorCode_T;
//! Error Code Bit 0: 1 = Invalid Input List object ID or Output List object ID
#define CHANGE_LIST_ITEM_ERROR_INVALID_LIST_OBJECT_ID ((ChangeListItem_ErrorCode_T)0x01)
//! Error Code Bit 1: 1 = Invalid List Index
#define CHANGE_LIST_ITEM_ERROR_INVALID_LIST_INDEX ((ChangeListItem_ErrorCode_T)0x02)
//! Error Code Bit 2: 1 = Invalid New List Item Object ID
#define CHANGE_LIST_ITEM_ERROR_INVALID_ITEM_OBJECT_ID ((ChangeListItem_ErrorCode_T)0x04)
//! Error Code Bit 3: 1 = Value in use (e.g. open for input)
#define CHANGE_LIST_ITEM_ERROR_VALUE_IN_USE ((ChangeListItem_ErrorCode_T)0x08)
//! Error Code Bit 4: 1 = Any other error
#define CHANGE_LIST_ITEM_ERROR_ANY_OTHER_ERROR ((ChangeListItem_ErrorCode_T)0x10)
//! Change List Item response
typedef struct ChangeListItem_Response_S
{
   //! Object ID of an Input List object or Output List object
   ObjectID_T object_id;
   //! List Index (items are numbered 0-n)
   ListIndex_T list_index;
   //! New Object ID or NULL_OBJECT_ID to set empty item
   ObjectID_T new_object_id;
   //! Error Codes (0 = no error)
   ChangeListItem_ErrorCode_T error_code;
} ChangeListItem_Response_T;
/******************************************************************************/
// F.44  Delete Object Pool command
/******************************************************************************/
/******************************************************************************/
// F.45  Delete Object Pool response
/******************************************************************************/
/******************************************************************************/
// F.46  Lock/Unlock Mask command
/******************************************************************************/
//! Command for locking/unlocking Data Mask or Window Mask
typedef enum MaskCommand_E
{
   //! Unlock Data Mask or Window Mask
   Mask_Unlock = 0,
   //! Lock Data Mask or Window Mask
   Mask_Lock = 1
} MaskCommand_T;
/******************************************************************************/
// F.47  Lock/Unlock Mask response
/******************************************************************************/
//! Lock/Unlock Mask Error Code
typedef uint8_t LockUnlockMask_ErrorCode_T;
//! Error Code Bit 0: 1 = Command ignored, no mask is visible or given Object ID does not match the visible mask
#define LOCK_UNLOCK_MASK_ERROR_MASK_NOT_VISIBLE ((LockUnlockMask_ErrorCode_T)0x01)
//! Error Code Bit 1: 1 = Lock command ignored, already locked
#define LOCK_UNLOCK_MASK_ERROR_ALREADY_LOCKED ((LockUnlockMask_ErrorCode_T)0x02)
//! Error Code Bit 2: 1 = Unlock command ignored, not locked
#define LOCK_UNLOCK_MASK_ERROR_ALREADY_UNLOCKED ((LockUnlockMask_ErrorCode_T)0x04)
//! Error Code Bit 3: 1 = Lock command ignored, an Alarm Mask is active
#define LOCK_UNLOCK_MASK_ERROR_ALARM_MASK_ACTIVE ((LockUnlockMask_ErrorCode_T)0x08)
//! Error Code Bit 4: 1 = Unsolicited unlock, timeout occurred
#define LOCK_UNLOCK_MASK_ERROR_TIMEOUT ((LockUnlockMask_ErrorCode_T)0x10)
//! Error Code Bit 5: 1 = Unsolicited unlock, the active mask changed
#define LOCK_UNLOCK_MASK_ERROR_ACTIVE_MASK_CHANGED ((LockUnlockMask_ErrorCode_T)0x20)
//! Error Code Bit 6: 1 = Unsolicited unlock, operator induced, or any other error
#define LOCK_UNLOCK_MASK_ERROR_OPERATOR_INDUCED ((LockUnlockMask_ErrorCode_T)0x40)
//! Error Code Bit 7: 1 = Any other error
#define LOCK_UNLOCK_MASK_ERROR_ANY_OTHER_ERROR ((LockUnlockMask_ErrorCode_T)0x80)
//! Lock/Unlock Mask response
typedef struct LockUnlockMask_Response_S
{
   //! Command:
   MaskCommand_T command;
   //! Error Codes (0 = no error)
   LockUnlockMask_ErrorCode_T error_code;
} LockUnlockMask_Response_T;
/******************************************************************************/
// F.48  Execute Macro command
/******************************************************************************/
/******************************************************************************/
// F.49  Execute Macro response
/******************************************************************************/
//! Execute Macro Error Code
typedef uint8_t ExecuteMacro_ErrorCode_T;
//! Error Code Bit 0: 1 = Object ID does not exist
#define EXECUTE_MACRO_ERROR_OBJECT_DOES_NOT_EXIST ((ExecuteMacro_ErrorCode_T)0x01)
//! Error Code Bit 1: 1 = Object ID is not a Macro object
#define EXECUTE_MACRO_ERROR_OBJECT_NOT_A_MACRO ((ExecuteMacro_ErrorCode_T)0x02)
//! Error Code Bit 2: 1 = Any other error
#define EXECUTE_MACRO_ERROR_ANY_OTHER_ERROR ((ExecuteMacro_ErrorCode_T)0x04)
//! Execute Macro response
typedef struct ExecuteMacro_Response_S
{
   //! Object ID of Macro object
   MacroID_T macro_id;
   //! Error Codes (0 = no error)
   ExecuteMacro_ErrorCode_T error_code;
} ExecuteMacro_Response_T;
/******************************************************************************/
// F.50  Change Object Label command
/******************************************************************************/
/******************************************************************************/
// F.51  Change Object Label response
/******************************************************************************/
//! Change Object Label Error Code
typedef uint8_t ChangeObjectLabel_ErrorCode_T;
//! Error Code Bit 0: 1 = Invalid object id
#define CHANGE_OBJECT_LABEL_ERROR_INVALID_OBJECT_ID ((ChangeObjectLabel_ErrorCode_T)0x01)
//! Error Code Bit 1: 1 = Invalid String Variable object id
#define CHANGE_OBJECT_LABEL_ERROR_INVALID_STRING_VARIABLE ((ChangeObjectLabel_ErrorCode_T)0x02)
//! Error Code Bit 2: 1 = Invalid font type
#define CHANGE_OBJECT_LABEL_ERROR_INVALID_FONT_TYPE ((ChangeObjectLabel_ErrorCode_T)0x04)
//! Error Code Bit 3: 1 = Any other error
#define CHANGE_OBJECT_LABEL_ERROR_ANY_OTHER_ERROR1 ((ChangeObjectLabel_ErrorCode_T)0x08)
//! Error Code Bit 4: 1 = Designator references invalid objects
#define CHANGE_OBJECT_LABEL_ERROR_DESIGNATOR_REFERENCES_INVALID ((ChangeObjectLabel_ErrorCode_T)0x10)
//! Error Code Bit 5: 1 = Any other error
#define CHANGE_OBJECT_LABEL_ERROR_ANY_OTHER_ERROR2 ((ChangeObjectLabel_ErrorCode_T)0x20)
//! Change Object Label response
typedef struct ChangeObjectLabel_Response_S
{
   //! Error Codes (0 = no error)
   ChangeObjectLabel_ErrorCode_T error_code;
} ChangeObjectLabel_Response_T;
/******************************************************************************/
// F.52  Change Polygon Point command
/******************************************************************************/
//! Index of a Polygon Point
typedef uint8_t PolygonPointIndex_T;
/******************************************************************************/
// F.53  Change Polygon Point response
/******************************************************************************/
//! Change Polygon Point Error Code
typedef uint8_t ChangePolygonPoint_ErrorCode_T;
//! Error Code Bit 0: 1 = Invalid object ID
#define CHANGE_POLYGON_POINT_ERROR_INVALID_OBJECT_ID ((ChangePolygonPoint_ErrorCode_T)0x01)
//! Error Code Bit 1: 1 = Invalid point index
#define CHANGE_POLYGON_POINT_ERROR_INVALID_POINT_INDEX ((ChangePolygonPoint_ErrorCode_T)0x02)
//! Error Code Bit 2: 1 = Any other error
#define CHANGE_POLYGON_POINT_ERROR_ANY_OTHER_ERROR ((ChangePolygonPoint_ErrorCode_T)0x04)
//! Change Polygon Point response
typedef struct ChangePolygonPoint_Response_S
{
   //! Object ID of the Polygon object to change
   ObjectID_T object_id;
   //! Error Codes (0 = no error)
   ChangePolygonPoint_ErrorCode_T error_code;
} ChangePolygonPoint_Response_T;
/******************************************************************************/
// F.54  Change Polygon Scale command
/******************************************************************************/
/******************************************************************************/
// F.55  Change Polygon Scale response
/******************************************************************************/
//! Change Polygon Scale Error Code
typedef uint8_t ChangePolygonScale_ErrorCode_T;
//! Error Code Bit 0: 1 = Invalid object ID
#define CHANGE_POLYGON_SCALE_ERROR_INVALID_OBJECT_ID ((ChangePolygonScale_ErrorCode_T)0x01)
//! Error Code Bit 4: 1 = Any other error
#define CHANGE_POLYGON_SCALE_ERROR_ANY_OTHER_ERROR ((ChangePolygonScale_ErrorCode_T)0x10)
//! Change Polygon Scale response
typedef struct ChangePolygonScale_Response_S
{
   //! Object ID of Polygon object
   ObjectID_T object_id;
   //! New width attribute
   Pixel_T new_width_attribute;
   //! New height attribute
   Pixel_T new_heigh_attribute;
   //! Error Codes (0 = no error)
   ChangePolygonScale_ErrorCode_T error_code;
} ChangePolygonScale_Response_T;
/******************************************************************************/
// F.56  Graphics Context command
/******************************************************************************/
//! Graphics Context Subcommands
typedef enum GraphicsContext_Subcommand_E
{
   GraphicsContext_SetGraphicsCursor = 0,
   GraphicsContext_MoveGraphicsCursor = 1,
   GraphicsContext_SetForegroundColour = 2,
   GraphicsContext_SetBackgroundColour = 3,
   GraphicsContext_SetLineAttributes = 4,
   GraphicsContext_SetFillAttributes = 5,
   GraphicsContext_SetFontAttributes = 6,
   GraphicsContext_EraseRectangle = 7,
   GraphicsContext_DrawPoint = 8,
   GraphicsContext_DrawLine = 9,
   GraphicsContext_DrawRectangle = 10,
   GraphicsContext_DrawClosedEllipse = 11,
   GraphicsContext_DrawPolygon = 12,
   GraphicsContext_DrawText = 13,
   GraphicsContext_PanViewport = 14,
   GraphicsContext_ZoomViewport = 15,
   GraphicsContext_PanAndZoomViewport = 16,
   GraphicsContext_ChangeViewportSize = 17,
   GraphicsContext_DrawVtObject = 18,
   GraphicsContext_CopyCanvasToPictureGraphic = 19,
   GraphicsContext_CopyViewportToPictureGraphic = 20
} GraphicsContext_Subcommand_T;
/******************************************************************************/
// F.57  Graphics Context response
/******************************************************************************/
//! Graphics Context Error Code
typedef uint8_t GraphicsContext_ErrorCode_T;
//! Error Code Bit 0: 1 = Invalid object ID or object is not a Graphics Context object
#define GRAPHICS_CONTEXT_ERROR_INVALID_OBJECT_ID ((GraphicsContext_ErrorCode_T)0x01)
//! Error Code Bit 1: 1 = Invalid command id
#define GRAPHICS_CONTEXT_ERROR_INVALID_COMMAND_ID ((GraphicsContext_ErrorCode_T)0x02)
//! Error Code Bit 2: 1 = Invalid parameter
#define GRAPHICS_CONTEXT_ERROR_INVALID_PARAMETER ((GraphicsContext_ErrorCode_T)0x04)
//! Error Code Bit 3: 1 = Command will produce invalid results
#define GRAPHICS_CONTEXT_ERROR_INVALID_RESULTS ((GraphicsContext_ErrorCode_T)0x08)
//! Error Code Bit 4: 1 = Any other error
#define GRAPHICS_CONTEXT_ERROR_ANY_OTHER_ERROR ((GraphicsContext_ErrorCode_T)0x10)
//! Graphics Context response
typedef struct GraphicsContext_Response_S
{
   //! Object ID of a Graphics Context object
   ObjectID_T object_id;
   //! Sub-command ID
   GraphicsContext_Subcommand_T sub_command_id;
   //! Error codes (0 = no errors)
   GraphicsContext_ErrorCode_T error_code;
} GraphicsContext_Response_T;
/******************************************************************************/
// F.58  Get Attribute Value command
/******************************************************************************/
/******************************************************************************/
// F.59  Get Attribute Value response
/******************************************************************************/
//! Get Attribute Value Error Code
typedef uint8_t GetAttributeValue_ErrorCode_T;
//! Error Code Bit 0: 1 = Invalid object ID
#define GET_ATTRIBUTE_VALUE_ERROR_INVALID_OBJECT_ID ((GetAttributeValue_ErrorCode_T)0x01)
//! Error Code Bit 1: 1 = Invalid Attribute ID
#define GET_ATTRIBUTE_VALUE_ERROR_INVALID_ATTRIBUTE_ID ((GetAttributeValue_ErrorCode_T)0x02)
//! Error Code Bit 4: 1 = Any other error
#define GET_ATTRIBUTE_VALUE_ERROR_ANY_OTHER_ERROR ((GetAttributeValue_ErrorCode_T)0x10)
//! Get Attribute Value response
typedef struct GetAttributeValue_Response_S
{
   //! Object ID
   ObjectID_T object_id;
   //! Attribute ID of the Object
   AttributeID_T attribute_id;
   //! Error Codes (0 = no error)
   GetAttributeValue_ErrorCode_T error_code;
   //! Current value of the attribute. Size depends on attribute data type.
   //! Values greater than 1 byte are transmitted little endian (LSB first):
   //! Boolean: 1 byte for TRUE/FALSE
   //! Integer: 1, 2 or 4 bytes as defined in object tables
   //! Float: 4 bytes
   //! Bitmask: 1 byte
   AttributeValue_T value;
} GetAttributeValue_Response_T;
/******************************************************************************/
// F.60  Select Colour Map command
/******************************************************************************/
/******************************************************************************/
// F.61  Select Colour Map response
/******************************************************************************/
//! Select Colour Map Error Code
typedef uint8_t SelectColourMap_ErrorCode_T;
//! Error Code Bit 0: 1 = Invalid object id
#define SELECT_COLOUR_MAP_ERROR_INVALID_OBJECT_ID ((SelectColourMap_ErrorCode_T)0x01)
//! Error Code Bit 1: 1 = Invalid Colour Map
#define SELECT_COLOUR_MAP_ERROR_INVALID_ATTRIBUTE_ID ((SelectColourMap_ErrorCode_T)0x02)
//! Error Code Bit 2: 1 = Any other error
#define SELECT_COLOUR_MAP_ERROR_ANY_OTHER_ERROR ((SelectColourMap_ErrorCode_T)0x04)
//! Select Colour Map response
typedef struct SelectColourMap_Response_S
{
   //! Object ID of the Colour Map object
   ObjectID_T object_id;
   //! Error Codes (0 = no error)
   SelectColourMap_ErrorCode_T error_code;
} SelectColourMap_Response_T;
/******************************************************************************/
// F.62  Identify VT message
/******************************************************************************/
/******************************************************************************/
// F.63  Identify VT response
/******************************************************************************/
/******************************************************************************/
// Annex G  Status Messages
/******************************************************************************/
/******************************************************************************/
// G.2  VT Status message
/******************************************************************************/
//! Type for storing Status Message busy codes.
typedef uint8_t StatusBusyCodes_T;
//! VT is busy updating visible mask
#define VT_BUSY_UPDATING_VISIBLE_MASK ((StatusBusyCodes_T)0x01)
//! VT is busy saving data to non-volatile memory
#define VT_BUSY_SAVING_DATA_TO_NONVOLATILE_MEMORY ((StatusBusyCodes_T)0x02)
//! VT is busy executing a command
#define VT_BUSY_EXECUTING_A_COMMAND ((StatusBusyCodes_T)0x04)
//! VT is busy executing a Macro
#define VT_BUSY_EXECUTING_A_MACRO ((StatusBusyCodes_T)0x08)
//! \brief  VT is busy parsing an object pool
//! \note   VTv3 and later
#define VT_BUSY_PARSING_AN_OBJECT_POOL ((StatusBusyCodes_T)0x10)
//! Reserved, sent as zero
#define VT_BUSY_RESERVED ((StatusBusyCodes_T)0x20)
//! \brief  Auxiliary controls learn mode active
//! \note   VTv3 and later
#define VT_BUSY_AUX_CONTROL_LEARNING_MODE_ACTIVE ((StatusBusyCodes_T)0x40)
//! VT is out of memory
#define VT_BUSY_OUT_OF_MEMORY ((StatusBusyCodes_T)0x80)
/******************************************************************************/
// G.3  Working Set Maintenance message
/******************************************************************************/
/******************************************************************************/
// Annex H  Activation messages
/******************************************************************************/
/******************************************************************************/
// H.2  Soft Key Activation message
/******************************************************************************/
//! Activation code for buttons/softkeys
typedef enum KeyButton_ActivationCode_E
{
   //! Softkey or Button Released (State change)
   KeyButton_Released = 0,
   //! Softkey or Button Pressed (State change)
   KeyButton_Pressed = 1,
   //! Softkey or Button Held (Not state change)
   KeyButton_Held = 2,
   //! Softkey or Button press aborted (finger moved off button without releasing)
   KeyButton_Aborted = 3
} KeyButton_ActivationCode_T;
//! Soft Key Activation message
typedef struct SoftKeyActivation_S
{
   //! Object ID of Key Object
   ObjectID_T key_object_id;
   //! Object ID of visible Data Mask, Alarm Mask, or in the case where the Soft Key is in a visible Key Group, the Object ID of the Key Group Object
   ObjectID_T parent_object_id;
   //! Key activation code
   KeyButton_ActivationCode_T key_activation_code;
   //! Soft key code
   KeyCode_T soft_key_code;
} SoftKeyActivation_T;
/******************************************************************************/
// H.4  Button Activation message
/******************************************************************************/
//! Button Activation message
typedef struct ButtonActivation_S
{
   //! Object ID of Button Object
   ObjectID_T key_object_id;
   //! Object ID of parent Data Mask or in the case where the Button is in a visible Window Mask object, the Object ID of the Window Mask object
   ObjectID_T parent_object_id;
   //! Key activation code
   KeyButton_ActivationCode_T key_activation_code;
   //! Button key code
   KeyCode_T button_key_code;
} ButtonActivation_T;
/******************************************************************************/
// H.6  Pointing Event message
/******************************************************************************/
//! Pointing Event Touch State
typedef enum PointingEvent_TouchState_E
{
   //! Screen Location Released (State change)
   TouchState_Released = 0,
   //! Screen Location Pressed (State change)
   TouchState_Pressed = 1,
   //! Screen Location Held (Not state change)
   TouchState_Held = 2
} PointingEvent_TouchState_T;
//! Pointing Event message
typedef struct PointingEvent_S
{
   //! X Position in pixels relative to top left corner of Data Mask area
   Pixel_T x_position;
   //! Y Position in pixels relative to top left corner of Data Mask area
   Pixel_T y_position;
   //! Touch State
   PointingEvent_TouchState_T touch_state;
} PointingEvent_T;
/******************************************************************************/
// H.8  VT Select Input Object message
/******************************************************************************/
//! VT Select Input Object message
typedef struct VtSelectInputObject_S
{
   //! Object ID
   ObjectID_T object_id;
   //! Selection State
   Object_SelectionState_T SelectionState;
} VtSelectInputObject_T;
/******************************************************************************/
// H.10  VT ESC message
/******************************************************************************/
//! VT ESC Error Code
typedef uint8_t VT_ESC_ErrorCode_T;
//! Error Code Bit 0: 1 = No input field is selected (this bit is only used when the VT has a permanent ESC means)
#define VT_ESC_ERROR_INVALID_OBJECT_ID ((VT_ESC_ErrorCode_T)0x01)
//! Error Code Bit 4: 1 = Any other error
#define VT_ESC_ERROR_ANY_OTHER_ERROR ((VT_ESC_ErrorCode_T)0x10)
//! VT ESC message
typedef struct VtEsc_S
{
   //! Object ID where input was aborted if no error code
   ObjectID_T escape_objectID;
   //! Error code: (0 = no error)
   VT_ESC_ErrorCode_T escape_error_code;
} VtEsc_T;
/******************************************************************************/
// H.12  VT Change Numeric Value message
/******************************************************************************/
//! VT Change Numeric Value message
typedef struct VtChangeNumericValue_S
{
   //! Object ID
   ObjectID_T object_id;
   //! Value: Size depends on object type. Objects of size 1 byte are
   //! found in Byte 5. Objects of size 2 bytes are found in Bytes 5-6.
   //! Values greater than 1 byte are transmitted little endian (LSB first).
   //! Unused bytes shall be filled with zero.
   //! Input Boolean:    1 byte for TRUE/FALSE
   //! Input Number:     4 bytes for integer input
   //! Input List:       1 byte for list index
   //! Number variable:  4 bytes for integer value
   NumericValue_T value;
} VtChangeNumericValue_T;
/******************************************************************************/
// H.14  VT Change Active Mask message
/******************************************************************************/
//! VT Change Active Mask Error Code
typedef uint8_t VT_ChangeActiveMask_ErrorCode_T;
//! Error Code Bit 2: 1 = Missing objects
#define VT_CHANGE_ACTIVE_MASK_ERROR_MISSING_OBJECTS ((VT_ChangeActiveMask_ErrorCode_T)0x04)
//! Error Code Bit 3: 1 = mask or child object has errors
#define VT_CHANGE_ACTIVE_MASK_ERROR_MASK_OR_CHILD_ERRORS ((VT_ChangeActiveMask_ErrorCode_T)0x08)
//! Error Code Bit 4: 1 = Any other error
#define VT_CHANGE_ACTIVE_MASK_ERROR_ANY_OTHER_ERROR ((VT_ChangeActiveMask_ErrorCode_T)0x10)
//! Error Code Bit 5: 1 = Pool being deleted
#define VT_CHANGE_ACTIVE_MASK_ERROR_POOL_DELETED ((VT_ChangeActiveMask_ErrorCode_T)0x20)
//! VT Change Active Mask message
typedef struct VtChangeActiveMask_S
{
   //! Active mask object ID
   ObjectID_T active_mask_object_id;
   //! Object ID containing error
   ObjectID_T obj_id_with_error;
   //! Parent object ID of error object ID
   ObjectID_T parent_obj_id_with_error;
   //! Error code(s): (0 = no error)
   VT_ChangeActiveMask_ErrorCode_T error_code;
} VtChangeActiveMask_T;
/******************************************************************************/
// H.16  VT Change Soft Key Mask message
/******************************************************************************/
//! VT Change Soft Key Mask Error Code
typedef uint8_t VT_ChangeSoftKeyMask_ErrorCode_T;
//! Error Code Bit 2: 1 = Missing objects
#define VT_CHANGE_SOFT_KEY_MASK_ERROR_MISSING_OBJECTS ((VT_ChangeSoftKeyMask_ErrorCode_T)0x04)
//! Error Code Bit 3: 1 = mask or child object has errors
#define VT_CHANGE_SOFT_KEY_MASK_ERROR_MASK_OR_CHILD_ERRORS ((VT_ChangeSoftKeyMask_ErrorCode_T)0x08)
//! Error Code Bit 4: 1 = Any other error
#define VT_CHANGE_SOFT_KEY_MASK_ERROR_ANY_OTHER_ERROR ((VT_ChangeSoftKeyMask_ErrorCode_T)0x10)
//! VT Change Soft Key Mask message
typedef struct VtChangeSoftKeyMask_S
{
   //! Data or Alarm Mask Object ID
   ObjectID_T mask_object_id;
   //! New Soft Key Mask Object ID
   ObjectID_T soft_key_mask_id;
   //! Error Code(s): (0 = no error)
   VT_ChangeSoftKeyMask_ErrorCode_T error_code;
} VtChangeSoftKeyMask_T;
/******************************************************************************/
// H.18  VT Change String Value message
/******************************************************************************/
//! VT Change String Value message (transport protocol)
typedef struct VtChangeStringValue_S
{
   //! Object ID of the Input String object or String Variable object
   ObjectID_T object_id;
   //! Total number of bytes in the string to transfer
   Size_T length;
   //! Entered string value
   Pipe_ReadHandle_T data;
} VtChangeStringValue_T;
/******************************************************************************/
// H.20  VT On User-Layout Hide/Show message
/******************************************************************************/
//! VT On User-Layout Hide/Show message
typedef struct VtOnUserLayoutHideShow_S
{
   //! Object ID of Window Mask, or Key Group, Data Mask or Soft Key Mask object
   ObjectID_T mask_1_object_id;
   //! Object ID of Window Mask, or Key Group, Data Mask or Soft Key Mask object
   //! or NULL Object ID
   ObjectID_T mask_2_object_id;
   //! Status: Bit 0 = State (0 = hidden, 1 = shown)
   ShowHide_Status_T Mask1_Status;
   //! Status: Bit 0 = State (0 = hidden, 1 = shown)
   ShowHide_Status_T Mask2_Status;
} VtOnUserLayoutHideShow_T;
/******************************************************************************/
// H.21  VT On User-Layout Hide/Show response
/******************************************************************************/
/******************************************************************************/
// H.22  VT Control Audio Signal Termination message
/******************************************************************************/
//! Cause of an Audio Termination
typedef uint8_t AudioTerminationCause_T;
//! Error Code Bit 0: 1 = Audio was terminated (bit shall always be set)
#define AUDIO_TERMINATED ((AudioTerminationCause_T)0x01)
//! VT Control Audio Signal Termination message
typedef struct VtControlAudioSignalTermination_S
{
   //! Audio Termination Cause
   AudioTerminationCause_T termination_cause;
} VtControlAudioSignalTermination_T;
/******************************************************************************/
// Annex H Application callbacks
/******************************************************************************/
/******************************************************************************/
// Annex J  Auxiliary Control
/******************************************************************************/
/******************************************************************************/
// J.2.6  Auxiliary Function Type 2 types
/******************************************************************************/
//! Indicates the Auxiliary function type
typedef enum AuxFunctionTypeID_E
{
   //! Boolean - Latching (maintains position) On/Off
   AuxType_Boolean_Latching = 0,
   //! Analog (maintains position setting)
   AuxType_Analog = 1,
   //! Boolean - Non-Latching (momentary) Increase value
   AuxType_Boolean_Momentary = 2,
   //! Analog - return to 50 % Left/Right
   AuxType_Analog_ReturnToCenter = 3,
   //! Analog - return to 0 % Increase value
   AuxType_Analog_ReturnToZero = 4,
   //! Dual Boolean - Both Latching (Maintain positions) On/Off/On
   AuxType_DualBoolean_BothLatching = 5,
   //! Dual Boolean - Both Non-Latching (Momentary) Increase/Off/Decrease; Raise/Off/Lower
   AuxType_DualBoolean_BothMomentary = 6,
   //! Dual Boolean - Latching (Up)(Momentary down)
   AuxType_DualBoolean_LatchUpMomentaryDown = 7,
   //! Dual Boolean - Latching (Down)(Momentary up)
   AuxType_DualBoolean_LatchDownMomentaryUp = 8,
   //! Combined Analog - return to 50% with Dual Boolean - Latching
   AuxType_Combined_Analog_ReturnToCenter_DualBoolean_Latching = 9,
   //! Combined Analog - maintains position setting with Dual Boolean - Latching
   AuxType_Combined_Analog_DualBoolean_Latching = 10,
   //! Quadrature Boolean - Non-Latching
   AuxType_QuadratureBoolean_NonLatching = 11,
   //! Quadrature Analog (maintains position setting)
   AuxType_QuadratureAnalog = 12,
   //! Quadrature Anaolog return to 50%
   AuxType_QuadratureAnalog_ReturnToCenter = 13,
   //! Bidirectional Encoder
   AuxType_BidirectionalEncoder = 14,
   //! Remove Assignment
   AuxType_RemoveAssignment = 31
} AuxFunctionTypeID_T;
/******************************************************************************/
// J.7.5  Auxiliary Assignment Type 2 command
/******************************************************************************/
//! this message requires transport protocol (14 bytes)
typedef struct AuxiliaryAssignmentType2_S
{
   //! Auxiliary Input Unit
   ISOBUS_Name_T AuxInputUnit;
   //! Preferred Assignment
   bool_t StoreAsPreferred;
   //! Auxiliary Function Type
   AuxFunctionTypeID_T AuxFunctionType;
   //! Object ID of Auxiliary Input
   ObjectID_T AuxInputObjectID;
   //! Object ID of Auxiliary Function
   ObjectID_T AuxFunctionObjectID;
} AuxiliaryAssignmentType2_T;
/******************************************************************************/
// J.7.6  Auxiliary Assignment Type 2 response
/******************************************************************************/
//! Aux Assignment error codes
typedef uint8_t AuxiliaryAssignmentType2_Error_T;
//! Error Code Bit 0: 0 = no errors
#define AUX_ASSIGNMENT_TYPE_2_ERROR_NO_ERRORS ((AuxiliaryAssignmentType2_Error_T)0x00)
//! Error Code Bit 0: 1 = error, Assignment not accepted
#define AUX_ASSIGNMENT_TYPE_2_ERROR_ASSIGNMENT_NOT_ACCEPTED ((AuxiliaryAssignmentType2_Error_T)0x01)
/******************************************************************************/
// J.7.7  Preferred Assignment command
/******************************************************************************/
//! Manufacturer defined Model Identification Code
typedef uint16_t ModelIdentificationCode_T;
//! Value of unassigned model identification
#define NULL_MODEL_ID ((ModelIdentificationCode_T)0xFFFF)
/******************************************************************************/
// J.7.8  Preferred Assignment response
/******************************************************************************/
//! Preferred Assignment error codes
typedef uint8_t PreferredAssignment_Error_T;
//! Error Code Bit 0: 1 = Auxiliary Input Unit(s) not valid
#define PREFERRED_ASSIGNMENT_ERROR_INVALID_AUX_INPUT_UNIT ((PreferredAssignment_Error_T)0x01)
//! Error Code Bit 1: 1 = Function Object ID(s) not valid
#define PREFERRED_ASSIGNMENT_ERROR_INVALID_AUX_FUNCTION ((PreferredAssignment_Error_T)0x02)
//! Error Code Bit 2: 1 = Input Object ID(s) not valid
#define PREFERRED_ASSIGNMENT_ERROR_INVALID_AUX_INPUT ((PreferredAssignment_Error_T)0x04)
//! Error Code Bit 3: 1 = Duplicate Object ID of Auxiliary Function
#define PREFERRED_ASSIGNMENT_ERROR_DUPLICATE_AUX_FUNCTION ((PreferredAssignment_Error_T)0x08)
//! Error Code Bit 4: 1 = Any other error
#define PREFERRED_ASSIGNMENT_ERROR_ANY_OTHER_ERROR ((PreferredAssignment_Error_T)0x10)
//! Preferred Assignment Response
typedef struct PreferredAssignment_Response_S
{
   //! Error Codes (0 = no errors)
   PreferredAssignment_Error_T ErrorCodes;
   //! Aux Function Object ID of faulty assignment  (NULL if no errors)
   ObjectID_T AuxFunctionObjectID;
} PreferredAssignment_Response_T;
/******************************************************************************/
// J.7.9  Auxiliary Input Type 2 Status message
/******************************************************************************/
//! Aux Input Operating State
typedef uint8_t AuxInputOperatingState_T;
//! Error Code Bit 0: 0 = Learn Mode Not Active
#define AUX_INPUT_OPERATING_STATE_LEARN_MODE_NOT_ACTIVE ((AuxInputOperatingState_T)0x00)
//! Error Code Bit 0: 1 = Learn Mode Active
#define AUX_INPUT_OPERATING_STATE_LEARN_MODE_ACTIVE ((AuxInputOperatingState_T)0x01)
//! Error Code Bit 1: 1 = Input activated in learn mode, bit 0 must be 1
#define AUX_INPUT_OPERATING_STATE_INPUT_ACTIVATED_IN_LEARN_MODE ((AuxInputOperatingState_T)0x02)
//! Aux Input Value
typedef uint16_t AuxInputValue_T;
//! Auxiliary Input Type 2 Status
typedef struct AuxiliaryInputType2Status_Message_S
{
   //! Auxiliary Input Unit
   NameTableIndex_T AuxInputUnit;
   //! Aux Input Object ID
   ObjectID_T AuxInputObjectID;
   //! Value 1 (see Table J.5)
   AuxInputValue_T Value1;
   //! Value 2 (see Table J.5)
   AuxInputValue_T Value2;
   //! Operating State
   AuxInputOperatingState_T OperatingState;
} AuxiliaryInputType2Status_Message_T;
/******************************************************************************/
// J.7.10  Auxiliary Input Type 2 Maintenance message
/******************************************************************************/
//! Aux Input Status
typedef enum AuxInputStatus_E
{
   //! Initializing, pool is not currently available for assignment
   AuxInput_Initializing = 0,
   //! Ready, pool has been loaded into the VT and is available for assignments
   AuxInput_Ready = 1
} AuxInputStatus_T;
//! Auxiliary Input Type 2 Maintenance message
typedef struct AuxiliaryInputType2Maintenance_Message_S
{
   //! Auxiliary Input Unit
   NameTableIndex_T AuxInputUnit;
   //! Model Identification Code of the Auxiliary Input Unit (Manufacturer defined)
   ModelIdentificationCode_T ModelID;
   //! Status
   AuxInputStatus_T Status;
} AuxiliaryInputType2Maintenance_Message_T;
/******************************************************************************/
// J.7.11  Auxiliary Input Status Type 2 Enable command
/******************************************************************************/
//! Auxilary Input Status Type 2 Enable command
typedef struct AuxiliaryInputStatusType2Enable_Command_S
{
   //! Object ID of Auxiliary Input
   ObjectID_T AuxInputObjectID;
   //! Enable/Disable Aux Input Status message
   EnableDisable_Status_T Enable;
} AuxiliaryInputStatusType2Enable_Command_T;
/******************************************************************************/
// J.7.12  Auxiliary Input Status Type 2 Enable response
/******************************************************************************/
//! Auxiliary Input Status errors
typedef uint8_t AuxiliaryInputStatusType2_Error_T;
//! Aux Input Status Type 2 Enable error bit 0:  No error
#define AUX_INPUT_STATUS_TYPE_2_ENABLE_ERROR_NO_ERRORS ((AuxiliaryInputStatusType2_Error_T)0x00)
//! Aux Input Status Type 2 Enable error bit 0:  Invalid Auxiliary Input Object ID
#define AUX_INPUT_STATUS_TYPE_2_ENABLE_ERROR_INVALID_AUX_INPUT_OBJECT ((AuxiliaryInputStatusType2_Error_T)0x01)
//! Aux Input Status Type 2 Enable error bit 1:  any other error
#define AUX_INPUT_STATUS_TYPE_2_ENABLE_ERROR_ANY_OTHER_ERROR ((AuxiliaryInputStatusType2_Error_T)0x02)
/******************************************************************************/
// Annex J Callbacks
/******************************************************************************/
//! Provides application callbacks for Aux control messaging
typedef struct AuxControl_Callbacks_S
{
   //! Aux Assignment Type 2 command  (VT to Aux Function ECU - assigns input unit/objectID)
   void (*AuxiliaryAssignmentType2_Command) (const AuxiliaryAssignmentType2_T *);
   //! Preferred Assignment response
   void (*PreferredAssignment_Response) (const PreferredAssignment_Response_T *);
   //! Aux Input Type 2 Status (sent from Aux Input ECU to Aux Function ECU)
   void (*AuxiliaryInputType2Status_Message) (const AuxiliaryInputType2Status_Message_T *);
   //! Aux Input Type 2 Maintenance (sent from Aux Input ECU)
   void (*AuxiliaryInputType2Maintenance_Message) (const AuxiliaryInputType2Maintenance_Message_T *);
   //! Aux Input Status Type 2 Enable command (sent from VT to Aux Input ECU)
   void (*AuxiliaryInputStatusType2Enable_Command)(const AuxiliaryInputStatusType2Enable_Command_T *);
} AuxControl_Callbacks_T;
/******************************************************************************/
// Application message/response callbacks
/******************************************************************************/
//! This structure allows the user to specify callbacks for received messages
typedef struct Op_Callbacks_S
{
   // Annex F
   //! Application Callback for Hide/Show Object response
   struct LinkedList_List_S HideShowObject_Response; // 160 - ECU command, VT will reply
   //! Application Callback for Enable/Disable Object response
   struct LinkedList_List_S EnableDisableObject_Response; // 161 - ECU command, VT will reply
   //! Application Callback for Select Input Object response
   struct LinkedList_List_S SelectInputObject_Response; // 162 - ECU command, VT will reply
   //! Application Callback for ESC response  (ESC originated from ECU)
   struct LinkedList_List_S Esc_Response; // 146 - ECU command, VT will reply
   //! Application Callback for Change Child Location response
   struct LinkedList_List_S ChangeChildLocation_Response; // 165 - ECU command, VT will reply
   //! Application Callback for Change Child Position response
   struct LinkedList_List_S ChangeChildPosition_Response; // 180 - ECU command, VT will reply
   //! Application Callback for Change Size response
   struct LinkedList_List_S ChangeSize_Response; // 166 - ECU command, VT will reply
   //! Application Callback for Change Background Colour response
   struct LinkedList_List_S ChangeBackgroundColour_Response; // 167 - ECU command, VT will reply
   //! Application Callback for Change Numeric Value response
   struct LinkedList_List_S ChangeNumericValue_Response; // 168 - ECU command, VT will reply
   //! Application Callback for Change String Value response
   struct LinkedList_List_S ChangeStringValue_Response; // 179 - ECU command, VT will reply
   //! Application Callback for Change End Point response
   struct LinkedList_List_S ChangeEndPoint_Response; // 169 - ECU command, VT will reply
   //! Application Callback for Change Font Attributes response
   struct LinkedList_List_S ChangeFontAttributes_Response; // 170 - ECU command, VT will reply
   //! Application Callback for Change Line Attributes response
   struct LinkedList_List_S ChangeLineAttributes_Response; // 171 - ECU command, VT will reply
   //! Application Callback for Change Fill Attributes response
   struct LinkedList_List_S ChangeFillAttributes_Response; // 172 - ECU command, VT will reply
   //! Application Callback for Change Active Mask response
   struct LinkedList_List_S ChangeActiveMask_Response; // 173 - ECU command, VT will reply
   //! Application Callback for Change Soft Key Mask response
   struct LinkedList_List_S ChangeSoftKeyMask_Response; // 174 - ECU command, VT will reply
   //! Application Callback for Change Attribute response
   struct LinkedList_List_S ChangeAttribute_Response; // 175 - ECU command, VT will reply
   //! Application Callback for Change Priority response
   struct LinkedList_List_S ChangePriority_Response; // 176 - ECU command, VT will reply
   //! Application Callback for Change List Item response
   struct LinkedList_List_S ChangeListItem_Response; // 177 - ECU command, VT will reply
   //! Application Callback for Change Polygon Point response
   struct LinkedList_List_S ChangePolygonPoint_Response; // 182 - ECU command, VT will reply
   //! Application Callback for Change Polygon Scale response
   struct LinkedList_List_S ChangePolygonScale_Response; // 183 - ECU command, VT will reply
   //! Application Callback for Graphics Context response
   struct LinkedList_List_S GraphicsContext_Response; // 184 - ECU command, VT will reply
   //! Application Callback for Get Attribute Value response
   struct LinkedList_List_S GetAttributeValue_Response; // 185 - ECU command, VT will reply
   //! Application Callback for Select Colour Map response
   struct LinkedList_List_S SelectColourMap_Response; // 186 - ECU command, VT will reply
   // Annex H
   //! Application Callback for Soft Key Activation
   struct LinkedList_List_S SoftKeyActivation;
   //! Application Callback for Button Activation
   struct LinkedList_List_S ButtonActivation;
   //! Application Callback for Select Input Object (originating from operator)
   struct LinkedList_List_S VtSelectInputObject;
   //! Application Callback for ESC (ESC originated from operator)
   struct LinkedList_List_S VtEsc;
   //! Application Callback for Change Numeric Value (originating from operator)
   struct LinkedList_List_S VtChangeNumericValue;
   //! Application Callback for Change Active Mask (originating from operator)
   struct LinkedList_List_S VtChangeActiveMask;
   //! Application Callback for Change Soft Key Mask (originating from operator)
   struct LinkedList_List_S VtChangeSoftKeyMask;
   //! Application Callback for Change String Value (originating from operator)
   struct LinkedList_List_S VtChangeStringValue;
   //! Application Callback for On User-Layout Hide/Show (originating from operator)
   struct LinkedList_List_S VtOnUserLayoutHideShow;
}Op_Callbacks_T;
//! Make an OP_Callback_T structure
#define MAKE_Op_Callbacks_T() {0}
//! Type to indicate how to scale an object pool part (by data mask size or soft key size)
typedef enum ObjectPool_ScaleFactor_E
{
   //! Do not scale this object pool part
   ScaleFactor_None,
   //! Scale based on the Data Mask size
   ScaleFactor_DataMask,
   //! Scale based on the Soft Key size
   ScaleFactor_SoftKeyMask
} ObjectPool_ScaleFactor_T;
////////////////////////////////////////////////////////////////////////////////
// Object Pool Definition
////////////////////////////////////////////////////////////////////////////////
//! Stores Object Pool information
typedef struct ObjectPoolPart_S
{
   //! Object Pool Data
   MemoryPointer_T Data;
   //! Size of Object Pool Data
   Size_T Size;
   //! How to scale this part
   ObjectPool_ScaleFactor_T ScaleFactor;
   //! Language specific part ("   " if not specific)
   char Language[3];
//   //! Function to determine final OP size after scaling
//   uint32_t (*Size)(VT_Metrics_T *metrics);
} ObjectPoolPart_T;
/******************************************************************************/
/*!
   \brief   Make a non-language specific object pool part
   \param  object_pool   Array of object pool data
   \param  scale_factor  Determines Data Mask, Soft Key, or no scaling
*/
/******************************************************************************/
#define MAKE_ObjectPoolPart_T(object_pool,scale_factor) {{ MAKE_MemoryPointer_T(object_pool) }, SIZEOF(object_pool), scale_factor, "  "}
/******************************************************************************/
/*!
   \brief   Make a language specific object pool part
   \param  object_pool   Array of object pool data
   \param  scale_factor  Determines Data Mask, Soft Key, or no scaling
   \param  language      Two character ISO 639 language code
*/
/******************************************************************************/
#define MAKE_ObjectPoolLanguagePart_T(object_pool,scale_factor,language) {{ MAKE_MemoryPointer_T(object_pool) }, SIZEOF(object_pool), scale_factor, language}
//! Combines Object Pool Parts into a complete Object Pool
typedef struct ObjectPool_S
{
   //! Data for each part of the object pool
   ObjectPoolPart_T const *Parts;
   //! Number of parts to the object pool
   Size_T NumParts;
   //! Designed data mask size
   Pixel_T DataMask_XY;
   //! Designed softkey mask width
   Pixel_T SoftKey_X;
   //! Designed softkey mask height
   Pixel_T SoftKey_Y;
   //! App's object pool version string
   char VersionLabel[8];
   //! Default language for this object pool.
   char DefaultLanguage[3];
   //! Array of Vt object pool callbacks
   Op_Callbacks_T OpCallbackList;
} ObjectPool_T;
/******************************************************************************/
/*!
   \brief   Make a non-language specific object pool
   \param  object_pool_parts  Array of object pool parts
   \param  data_mask_size     Designed data mask size
   \param  softkey_x          Designed soft key width
   \param  softkey_y          Designed soft key height
   \param  version            Object pool version label
*/
/******************************************************************************/
#define MAKE_ObjectPool_T(object_pool_parts,data_mask_size,softkey_x,softkey_y,version) {object_pool_parts, SIZEOF(object_pool_parts)/SIZEOF(ObjectPoolPart_T), data_mask_size, softkey_x, softkey_y, version, "  ", MAKE_Op_Callbacks_T()}
/******************************************************************************/
/*!
   \brief   Make a non-language specific object pool
   \param  object_pool_parts  Array of object pool parts
   \param  data_mask_size     Designed data mask size
   \param  softkey_x          Designed soft key width
   \param  softkey_y          Designed soft key height
   \param  version            Object pool version label
   \param  language           Default language (if selected VT language is not supported)
*/
/******************************************************************************/
#define MAKE_ObjectPoolLanguage_T(object_pool_parts,data_mask_size,softkey_x,softkey_y,version,language) {object_pool_parts, SIZEOF(object_pool_parts) / SIZEOF(ObjectPoolPart_T), data_mask_size, softkey_x, softkey_y, version, language, MAKE_Op_Callbacks_T()}
////////////////////////////////////////////////////////////////////////////////
// Annex D - Technical Data Messages
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// VT Metrics state/storage types
////////////////////////////////////////////////////////////////////////////////
//! States for tracking metrics request state machine
typedef enum VT_MetricsState_E
{
   VT_METRICS_IDLE,
   VT_METRICS_SEND_REQUEST,
   VT_METRICS_REQUEST_SENT,
   VT_METRICS_WAIT_RESPONSE
} VT_MetricsState_T;
//! Bitfield indicating received messages
typedef uint8_t VT_MetricsMessages_T;
//! Bit to indicate that the VT Version Number is known
#define VT_RECEIVED_VT_VERSION ((VT_MetricsMessages_T)0x01)
//! Bit to indicate that the VT Language Command has been received
#define VT_RECEIVED_LANGUAGE ((VT_MetricsMessages_T)0x02)
//! Bit to indicate that the VT Number Of Soft Keys is known
#define VT_RECEIVED_NUMBER_SOFT_KEYS ((VT_MetricsMessages_T)0x04)
//! Bit to indicate that the VT Text Font Data is known
#define VT_RECEIVED_TEXT_FONT_DATA ((VT_MetricsMessages_T)0x08)
//! Bit to indicate that the VT Hardware is known
#define VT_RECEIVED_HARDWARE ((VT_MetricsMessages_T)0x10)
//! Bit to indicate that the VT supported Wide Chars is known
#define VT_RECEIVED_WIDE_CHARS ((VT_MetricsMessages_T)0x20)
//! Bit to indicate that the VT Window Mask Data is known
#define VT_RECEIVED_WINDOW_MASK_DATA ((VT_MetricsMessages_T)0x40)
//! Bit to indicate that the VT Supported Objects is known
#define VT_RECEIVED_SUPPORTED_OBJECTS ((VT_MetricsMessages_T)0x80)
//! Minimum metrics required to send pool
#define VT_MINIMUM_METRICS (VT_RECEIVED_LANGUAGE | VT_RECEIVED_VT_VERSION | VT_RECEIVED_NUMBER_SOFT_KEYS | VT_RECEIVED_TEXT_FONT_DATA | VT_RECEIVED_HARDWARE)
//! VTv2 supported messages
#define VT_V2_BITMASK (VT_MINIMUM_METRICS)
//! VTv3 supported messages
#define VT_V3_BITMASK VT_V2_BITMASK
//! VTv4 supported messages
#define VT_V4_BITMASK (VT_V3_BITMASK/* | VT_RECEIVED_WIDE_CHARS*/ | VT_RECEIVED_WINDOW_MASK_DATA | VT_RECEIVED_SUPPORTED_OBJECTS)
//! Macro to determine if a metric is needed
#define VT_MetricNeeded(expected_metrics,metric) (((expected_metrics) & (metric)) != ((VT_MetricsMessages_T)0))
//! Type used to track retries for requested metrics
typedef uint8_t VT_MetricsRetries_T;
//! Structure to store VT metrics
typedef struct VT_Metrics_S
{
   //! Localization Information
   Language_T Language;
   //! VT Version (from Get Memory Response)
   GetMemory_Response_T GetMemory;
   //! Soft Key information
   GetSoftKeys_Response_T SoftKeys;
   //! Supported Fonts/styles
   GetTextFont_Response_T Font;
   //! VT Hardware information
   GetHardware_Response_T Hardware;
   // Get Supported WideChars...
   // \note   VTv4 and later
//! \todo  Add Wide Char support
   //! \brief  Get Window Mask Data
   //! \note   VTv4 and later
   GetWindowMask_Response_T WindowMask;
   //! Supported Object Types
   //! \note   VTv4 and later
   GetSupportedObjects_Response_T SupportedObjects;
   //! Indicates whether Metrics are needed
   VT_MetricsState_T State;
   //! Bit Mask Indicating Supported VT messaging
   VT_MetricsMessages_T ExpectedMetrics;
   //! Bit Mask Indicating Received VT messaging
   VT_MetricsMessages_T ReceivedMetrics;
   //! Bit Mask Indicating current message we're waiting for
   VT_MetricsMessages_T CurrentMetric;
   //! Tracks how many times a particular metric has been requested
   VT_MetricsRetries_T Retries;
   //! Tracks Metrics Response Timeouts
   SoftwareTimer_T ResponseTimer;
} VT_Metrics_T;
////////////////////////////////////////////////////////////////////////////////
// Annex G - Status Messages
////////////////////////////////////////////////////////////////////////////////
//! Structure for VT Status message
typedef struct VT_Status_S
{
   //! Name Table Index of active Working Set Master ("owns" VT)
   NameTableIndex_T ActiveWorkingSet;
   //! Object ID of the visible Data/Alarm Mask of the active Working Set
   ObjectID_T VisibleDataAlarmMask;
   //! Object ID of the visible Soft Key Mask of the active Working Set.
   ObjectID_T VisibleSoftKeyMask;
   //! VT Busy Codes
   StatusBusyCodes_T BusyCodes;
   //! VT function code of current command being executed (valid only if command or Macro busy code is set)
   ISOBUS_PacketData_T VTFunctionCode;
   //! Timer tracking when to consider VT failed
   SoftwareTimer_T Timer;
   //! Source address of the VT
   NameTableIndex_T Source;
} VT_Status_T;
////////////////////////////////////////////////////////////////////////////////
// Connection Management
////////////////////////////////////////////////////////////////////////////////
//! Structure for Working Set Maintenance
typedef struct VT_Connection_S
{
   //! Timer tracking when to send Working Set Maintenance message
   SoftwareTimer_T Timer;
   //! Indicates whether the connection is active
   bool_t IsConnected;
   //! Indicates whether the application wants a connection
   bool_t ConnectionWanted;
   //! Indicates if this is the first working set maintenance message
   ISOBUS_PacketData_T BitMask;
} VT_Connection_T;
//! Enumeration to track Object Pool state
typedef enum VT_ObjectPoolState_S
{
   VT_OP_IDLE,
   VT_OP_WAIT_CONNECTED,
   VT_OP_WAIT_METRICS,
   VT_OP_SEND_LOAD_VERSION,
   VT_OP_LOAD_VERSION_SENT,
   VT_OP_WAIT_LOAD_VERSION_RESPONSE,
   VT_OP_SEND_GET_MEMORY,
   VT_OP_GET_MEMORY_SENT,
   VT_OP_WAIT_GET_MEMORY_RESPONSE,
   VT_OP_START_OP,
   VT_OP_WAIT_OP_COMPLETE,
   VT_OP_SEND_END_OP,
   VT_OP_END_OP_SENT,
   VT_OP_WAIT_END_OP_RESPONSE,
   VT_OP_OPERATOR_INTERACTION,
   VT_OP_SEND_DELETE_OP,
   VT_OP_DELETE_OP_SENT,
   VT_OP_WAIT_DELETE_OP_RESPONSE,
   VT_OP_SET_WAIT_AFTER_DISCONNECT,
   VT_OP_WAIT_AFTER_DISCONNECT
} VT_ObjectPoolState_T;
//! Enumeration to track scaling state
//lint -e788  Suppress warnings for enumeration constants not used within defaulted switch
// Each object has its own function for scaling, and only cases related to that object are used.
typedef enum VT_ScalingState_S
{
   VT_Scaling_Idle,
   VT_Scaling_GetObjectType,
   VT_Scaling_Init,
   // States for Working Set Object
   VT_Scaling_WorkingSet_Fixed_1,
   VT_Scaling_WorkingSet_BackgroundColour,
   VT_Scaling_WorkingSet_Fixed_2,
   VT_Scaling_WorkingSet_ChildObjects,
   VT_Scaling_WorkingSet_ChildMacros,
   VT_Scaling_WorkingSet_LanguageCodes,
   // States for Data Mask Object
   VT_Scaling_DataMask_Fixed_1,
   VT_Scaling_DataMask_BackgroundColour,
   VT_Scaling_DataMask_Fixed_2,
   VT_Scaling_DataMask_ChildObjects,
   VT_Scaling_DataMask_ChildMacros,
   // States for Alarm Mask Object
   VT_Scaling_AlarmMask_Fixed_1,
   VT_Scaling_AlarmMask_BackgroundColour,
   VT_Scaling_AlarmMask_Fixed_2,
   VT_Scaling_AlarmMask_ChildObjects,
   VT_Scaling_AlarmMask_ChildMacros,
   // States for Container Object
   VT_Scaling_Container_Fixed_1,
   VT_Scaling_Container_Width,
   VT_Scaling_Container_Height,
   VT_Scaling_Container_Fixed_2,
   VT_Scaling_Container_ChildObjects,
   VT_Scaling_Container_ChildMacros,
   // States for Soft Key Mask Object
   VT_Scaling_SoftKeyMask_Fixed_1,
   VT_Scaling_SoftKeyMask_BackgroundColour,
   VT_Scaling_SoftKeyMask_Fixed_2,
   VT_Scaling_SoftKeyMask_ChildObjects,
   VT_Scaling_SoftKeyMask_ChildMacros,
   // States for Key Object
   VT_Scaling_Key_Fixed_1,
   VT_Scaling_Key_BackgroundColour,
   VT_Scaling_Key_Fixed_2,
   VT_Scaling_Key_ChildObjects,
   VT_Scaling_Key_ChildMacros,
   // States for Button Object
   VT_Scaling_Button_Fixed_1,
   VT_Scaling_Button_Width,
   VT_Scaling_Button_Height,
   VT_Scaling_Button_BackgroundColour,
   VT_Scaling_Button_BorderColour,
   VT_Scaling_Button_KeyCode,
   VT_Scaling_Button_Options,
   VT_Scaling_Button_Fixed_2,
   VT_Scaling_Button_ChildObjects,
   VT_Scaling_Button_ChildMacros,
   // States for Input Boolean Object
   VT_Scaling_InputBoolean_Fixed_1,
   VT_Scaling_InputBoolean_BackgroundColour,
   VT_Scaling_InputBoolean_Width,
   VT_Scaling_InputBoolean_Fixed_2,
   VT_Scaling_InputBoolean_ChildMacros,
   // States for Input String Object
   VT_Scaling_InputString_Fixed_1,
   VT_Scaling_InputString_Width,
   VT_Scaling_InputString_Height,
   VT_Scaling_InputString_BackgroundColour,
   VT_Scaling_InputString_Fixed_2,
   VT_Scaling_InputString_Options,
   VT_Scaling_InputString_Fixed_3,
   VT_Scaling_InputString_Justification,
   VT_Scaling_InputString_Length,
   VT_Scaling_InputString_Value,
   VT_Scaling_InputString_Fixed_4,
   VT_Scaling_InputString_ChildMacros,
   // States for Input Number Object
   VT_Scaling_InputNumber_Fixed_1,
   VT_Scaling_InputNumber_Width,
   VT_Scaling_InputNumber_Height,
   VT_Scaling_InputNumber_BackgroundColour,
   VT_Scaling_InputNumber_FontAttribute,
   VT_Scaling_InputNumber_Options,
   VT_Scaling_InputNumber_Fixed_2,
   VT_Scaling_InputNumber_Justification,
   VT_Scaling_InputNumber_Options2,
   VT_Scaling_InputNumber_Fixed_3,
   VT_Scaling_InputNumber_ChildMacros,
   // States for Input List Object
   VT_Scaling_InputList_Fixed_1,
   VT_Scaling_InputList_Width,
   VT_Scaling_InputList_Height,
   VT_Scaling_InputList_Fixed_2,
   VT_Scaling_InputList_Options,
   VT_Scaling_InputList_Fixed_3,
   VT_Scaling_InputList_ListItems,
   VT_Scaling_InputList_ChildMacros,
   // States for Output String Object
   VT_Scaling_OutputString_Fixed_1,
   VT_Scaling_OutputString_Width,
   VT_Scaling_OutputString_Height,
   VT_Scaling_OutputString_BackgroundColour,
   VT_Scaling_OutputString_FontAttributes,
   VT_Scaling_OutputString_Options,
   VT_Scaling_OutputString_VariableReference,
   VT_Scaling_OutputString_Justification,
   VT_Scaling_OutputString_Length,
   VT_Scaling_OutputString_Value,
   VT_Scaling_OutputString_MacroCount,
   VT_Scaling_OutputString_Macros,
   // States for Output Number Object
   VT_Scaling_OutputNumber_Fixed_1,
   VT_Scaling_OutputNumber_Width,
   VT_Scaling_OutputNumber_Height,
   VT_Scaling_OutputNumber_BackgroundColour,
   VT_Scaling_OutputNumber_FontAttributes,
   VT_Scaling_OutputNumber_Options,
   VT_Scaling_OutputNumber_Fixed_2,
   VT_Scaling_OutputNumber_Justification,
   VT_Scaling_OutputNumber_MacroCount,
   VT_Scaling_OutputNumber_Macros,
   // States for Line Object
   VT_Scaling_Line_Fixed_1,
   VT_Scaling_Line_Width,
   VT_Scaling_Line_Height,
   VT_Scaling_Line_Fixed_2,
   VT_Scaling_Line_ChildMacros,
   // States for Rectangle Object
   VT_Scaling_Rectangle_Fixed_1,
   VT_Scaling_Rectangle_Width,
   VT_Scaling_Rectangle_Height,
   VT_Scaling_Rectangle_LineSuppression,
   VT_Scaling_Rectangle_FillAttributes,
   VT_Scaling_Rectangle_MacroCount,
   VT_Scaling_Rectangle_Macros,
   // States for Ellipse Object
   VT_Scaling_Ellipse_Fixed_1,
   VT_Scaling_Ellipse_Width,
   VT_Scaling_Ellipse_Height,
   VT_Scaling_Ellipse_Fixed_2,
   VT_Scaling_Ellipse_MacroCount,
   VT_Scaling_Ellipse_Macros,
   // States for Polygon Object
   VT_Scaling_Polygon_Fixed_1,
   VT_Scaling_Polygon_Width,
   VT_Scaling_Polygon_Height,
   VT_Scaling_Polygon_Fixed_2,
   VT_Scaling_Polygon_GetCounts,
   VT_Scaling_Polygon_Points,
   VT_Scaling_Polygon_Macros,
   // States for Meter Object
   VT_Scaling_Meter_Fixed_1,
   VT_Scaling_Meter_Width,
   VT_Scaling_Meter_NeedleColour,
   VT_Scaling_Meter_BorderColour,
   VT_Scaling_Meter_ArcAndTickColour,
   VT_Scaling_Meter_Options,
   VT_Scaling_Meter_Fixed_2,
   VT_Scaling_Meter_ChildMacros,
   // States for Linear Bar Graph Object
   VT_Scaling_LinearBarGraph_Fixed_1,
   VT_Scaling_LinearBarGraph_Width,
   VT_Scaling_LinearBarGraph_Height,
   VT_Scaling_LinearBarGraph_Colour,
   VT_Scaling_LinearBarGraph_TargetLineColour,
   VT_Scaling_LinearBarGraph_Options,
   VT_Scaling_LinearBarGraph_Fixed_2,
   VT_Scaling_LinearBarGraph_ChildMacros,
   // States for Arched Bar Graph Object
   VT_Scaling_ArchedBarGraph_Fixed_1,
   VT_Scaling_ArchedBarGraph_Width,
   VT_Scaling_ArchedBarGraph_Height,
   VT_Scaling_ArchedBarGraph_Colour,
   VT_Scaling_ArchedBarGraph_TargetLineColour,
   VT_Scaling_ArchedBarGraph_Options,
   VT_Scaling_ArchedBarGraph_Fixed_2,
   VT_Scaling_ArchedBarGraph_BarGraphWidth,
   VT_Scaling_ArchedBarGraph_Fixed_3,
   VT_Scaling_ArchedBarGraph_ChildMacros,
   // States for Picture Graphic Object
   VT_Scaling_PictureGraphic_Fixed_1,
   VT_Scaling_PictureGraphic_Width,
   VT_Scaling_PictureGraphic_Fixed_2,
   VT_Scaling_PictureGraphic_Options,
   VT_Scaling_PictureGraphic_TransparencyColour,
   VT_Scaling_PictureGraphic_Fixed_3,
   VT_Scaling_PictureGraphic_RawDataBytes,
   VT_Scaling_PictureGraphic_ChildMacros,
   // States for Number Variable Object
   VT_Scaling_NumberVariable_Fixed_1,
   // States for String Variable Object
   VT_Scaling_StringVariable_Fixed_1,
   VT_Scaling_StringVariable_Length,
   VT_Scaling_StringVariable_Value,
   // States for Font Attributes Object
   VT_Scaling_FontAttributes_Fixed_1,
   VT_Scaling_FontAttributes_FontColour,
   VT_Scaling_FontAttributes_ItsComplicated,
   VT_Scaling_FontAttributes_Macros,
   // States for Line Attributes Object
   VT_Scaling_LineAttributes_Fixed_1,
   VT_Scaling_LineAttributes_LineColour,
   VT_Scaling_LineAttributes_LineWidth,
   VT_Scaling_LineAttributes_Fixed_2,
   VT_Scaling_LineAttributes_ChildMacros,
   // States for Fill Attributes Object
   VT_Scaling_FillAttributes_Fixed_1,
   VT_Scaling_FillAttributes_FillColour,
   VT_Scaling_FillAttributes_Fixed_2,
   VT_Scaling_FillAttributes_ChildMacros,
   // States for Input Attributes Object
   VT_Scaling_InputAttributes_Fixed_1,
   VT_Scaling_InputAttributes_ValidationString,
   VT_Scaling_InputAttributes_Fixed_2,
   VT_Scaling_InputAttributes_ChildMacros,
   // States for Object Pointer Object
   VT_Scaling_ObjectPointer_Fixed_1,
   // States for Macro Object
   VT_Scaling_MacroObject_Fixed_1,
   VT_Scaling_MacroObject_BytesToFollow,
   // States for Auxiliary Function Type 1 Object
   VT_Scaling_AuxiliaryFunctionType1_Fixed_1,
   VT_Scaling_AuxiliaryFunctionType1_BackgroundColour,
   VT_Scaling_AuxiliaryFunctionType1_Fixed_2,
   VT_Scaling_AuxiliaryFunctionType1_ChildObjects,
   // States for Auxiliary Input Type 1 Object
   VT_Scaling_AuxiliaryInputType1_Fixed_1,
   VT_Scaling_AuxiliaryInputType1_BackgroundColour,
   VT_Scaling_AuxiliaryInputType1_Fixed_2,
   VT_Scaling_AuxiliaryInputType1_ChildObjects,
   // States for Auxiliary Function Type 2 Object
   VT_Scaling_AuxiliaryFunctionType2_Fixed_1,
   VT_Scaling_AuxiliaryFunctionType2_BackgroundColour,
   VT_Scaling_AuxiliaryFunctionType2_Fixed_2,
   VT_Scaling_AuxiliaryFunctionType2_ChildObjects,
   // States for Auxiliary Input Type 2 Object
   VT_Scaling_AuxiliaryInputType2_Fixed_1,
   VT_Scaling_AuxiliaryInputType2_BackgroundColour,
   VT_Scaling_AuxiliaryInputType2_Fixed_2,
   VT_Scaling_AuxiliaryInputType2_ChildObjects,
   // States for Auxiliary Control Designator Type 2 Object Pointers Object
   VT_Scaling_AuxiliaryControlDesignatorType2ObjectPointer_Fixed_1,
   // States for Window Mask Object
   VT_Scaling_WindowMaskObject_Fixed_1,
   VT_Scaling_WindowMaskObject_BackgroundColour,
   VT_Scaling_WindowMaskObject_Options,
   VT_Scaling_WindowMaskObject_Fixed_2,
   VT_Scaling_WindowMaskObject_ChildObjectReferences,
   VT_Scaling_WindowMaskObject_ChildObjects,
   VT_Scaling_WindowMaskObject_ChildMacros,
   // States for Key Group Object
   VT_Scaling_KeyGroup_Fixed_1,
   VT_Scaling_KeyGroup_Options,
   VT_Scaling_KeyGroup_Fixed_2,
   VT_Scaling_KeyGroup_Objects,
   VT_Scaling_KeyGroup_Macros,
   // States for Graphics Context Object
   VT_Scaling_GraphicsContextObject_Fixed_1,
   VT_Scaling_GraphicsContextObject_ViewportWidth,
   VT_Scaling_GraphicsContextObject_ViewportHeight,
   VT_Scaling_GraphicsContextObject_Fixed_2,
   VT_Scaling_GraphicsContextObject_ViewportZoom,
   VT_Scaling_GraphicsContextObject_Fixed_3,
   VT_Scaling_GraphicsContextObject_ForegroundColour,
   VT_Scaling_GraphicsContextObject_BackgroundColour,
   VT_Scaling_GraphicsContextObject_Fixed_4,
   VT_Scaling_GraphicsContextObject_Format,
   VT_Scaling_GraphicsContextObject_Options,
   VT_Scaling_GraphicsContextObject_TransparencyColour,
   // States for Output List Object
   VT_Scaling_OutputList_Fixed_1,
   VT_Scaling_OutputList_Width,
   VT_Scaling_OutputList_Height,
   VT_Scaling_OutputList_Fixed_2,
   VT_Scaling_OutputList_ListItems,
   VT_Scaling_OutputList_Macros,
   // States for Extended Input Attributes Object
   VT_Scaling_ExtendedInputAttribute_Fixed_1,
   VT_Scaling_ExtendedInputAttribute_CodePlanes,
   // States for Colour Map Object
   VT_Scaling_ColourMapObject_Fixed_1,
   VT_Scaling_ColourMapObject_ColourIndexes,
   // States for Object Label Reference List Object
   VT_Scaling_ObjectLabelReferenceListObject_Fixed_1,
   VT_Scaling_ObjectLabelReferenceListObject_LabelledObjects,
   // State to indicate that object parsing is complete
   VT_Scaling_NextObject
} VT_ScalingState_T;
//! Type to store numerator and denominator for scaling type
typedef struct VT_ScaleFactor_S
{
   //! Numerator of scale factor
   Pixel_T numerator;
   //! Denominator of scale factor
   Pixel_T denominator;
} VT_ScaleFactor_T;
//! Structure containing all data required for scaling an object pool
typedef struct VT_Scaling_S
{
   //! State of the scaling state machine
   VT_ScalingState_T State;
   //! Read handle to pipe containing the raw pool data
   Pipe_ReadHandle_T RawPool;
   //! Write handle to pipe to put the scaled pool data into
   Pipe_WriteHandle_T ScaledPool;
   //! Type of the object currently being scaled
   Object_T CurrentObject;
   //! Current Object Pool part
   Size_T Part;
   //! Total number of raw pool bytes that have been converted
   Size_T BytesConverted;
   //! Generic variable to store state information
   Size_T i;
   //! Generic variable to store state information
   Size_T j;
   //! Generic variable to store state information
   Size_T k;
   //! Scaling type of current object
   ObjectPool_ScaleFactor_T ScalingType;
   //! Pointer to current scale factor
   VT_ScaleFactor_T *CurrentFactor;
   //! X Offset for centering soft keys
   Pixel_T X_Offset;
   //! Y Offset for centering soft keys
   Pixel_T Y_Offset;
   //! Array of Scale Factors based on Scaling Type
   VT_ScaleFactor_T ScaleFactor[3];
   //! Colour Depth of the VT
   VT_GraphicType_T ColourDepth;
   //! Supported Font sizes and styles
   GetTextFont_Response_T Fonts;
   //! Reported verson of the connected VT
   VT_Version_T VTVersion;
} VT_Scaling_T;
//! Structure containing data for reading memory device
typedef struct VT_Memory_S
{
   //! Object Pool part currently being loaded
   Size_T Part;
   //! Pipe handle to write raw pool data into
   Pipe_WriteHandle_T WriteHandle;
} VT_Memory_T;
//! Structure for Object Pool status
typedef struct VT_ObjectPool_S
{
   //! Object Pool state
   VT_ObjectPoolState_T State;
   //! Timer to make sure we receive responses
   SoftwareTimer_T ResponseTimer;
   //! Object pool to send
   ObjectPool_T const *Pool;
   //! Track memory state
   VT_Memory_T Memory;
   //! Scaling state
   VT_Scaling_T Scaling;
   //! Array of auxiliary control callbacks
   AuxControl_Callbacks_T *AuxCallbackList;
   //! Flag to indicate if current pool load is language parts only
   bool_t LanguageOnly;
   //! Flag to indicate a language change has been detected.
   bool_t LanguageChange;
   //! Currently selected language.
   char CurrentLanguage[2];
   //! Pool size for current language
   Size_T PoolSize;
} VT_ObjectPool_T;
////////////////////////////////////////////////////////////////////////////////
// VT Definition
////////////////////////////////////////////////////////////////////////////////
//! Stores known data for a VT
typedef struct VT_S
{
   //! Mutex for VT data
   Mutex_T Mutex;
   //! Data for the VT Status messages (ISO 11783-6 Annex G)
   VT_Status_T Status;
   //! Data for VT connection management
   VT_Connection_T Connection;
   //! Data for the various Technical Data messages (ISO 11783-6 Annex D)
   VT_Metrics_T Metrics;
   //! Loaded Object Pool
   //! \todo  This structure should change later
   VT_ObjectPool_T ObjectPool;
} VT_T;
//! Structure containing state information for all active VTs
typedef struct ActiveVtList_S
{
   //! Mutex containing priority info used for all VTs
   Mutex_T Mutex;
   //! Maximum number of active VTs
   const Size_T MaxVTs;
   //! Pointer to array of VTs
   VT_T * const List;
} ActiveVtList_T;
/******************************************************************************/
/*!
   \brief    Macro used to initialize an ActiveVtList_T
   \details  This macro is used to create an ActiveVtList_T that uses a
             previously declared array of ActiveVT_T.
   \param    vt_array  Name of the array of Active VTs
   \param    priority  Task priority to use for all VTs
*/
/******************************************************************************/
#define MAKE_ActiveVtList_T(vt_array,priority) { MAKE_Mutex_T(priority), sizeof(vt_array)/sizeof(VT_T), vt_array }
/******************************************************************************/
//! Structure to hold auxiliary input on the input side
typedef struct AuxiliaryInput_S
{
   //! Pointer to mutex containing priority info used for an auxiliary input
   Mutex_T *Mutex;
   //! Object id of the auxiliary input
   ObjectID_T AuxInputObjectID;
   //! Auxiliary function type
   AuxFunctionTypeID_T AuxFunctionType;
   //! Value 1 from auxiliary input
   AuxInputValue_T Value1;
   //! Value 2 from auxiliary input
   AuxInputValue_T Value2;
   //! Previous Value 1 from auxiliary input
   AuxInputValue_T PreviousValue1;
   //! Previous Value 2 from auxiliary input
   AuxInputValue_T PreviousValue2;
   //! Boolean to track if auxiliary input is enabled or disabled
   EnableDisable_Status_T Enabled;
   //! Timer to track timeout (1 second or 200 milliseconds) since last Auxiliary Input Type 2 Status message was sent
   SoftwareTimer_T StatusTimer;
   //! Timer to track minimum timeout (50 milliseconds) since last Auxiliary Input Type 2 Status message was sent due to input change
   SoftwareTimer_T MinChangeTimer;
} AuxiliaryInput_T;
/******************************************************************************/
/*!
   \brief   Macro used to initialize an AuxiliaryInput_T
   \details This macro is used to create an AuxiliaryInput_T that holds the data of an auxiliary input
   \param   input_id       ObjectID_T of the auxiliary input
   \param   auxiliary_type AuxFunctionTypeID_T of the auxiliary input
*/
/******************************************************************************/
#define MAKE_AuxiliaryInput_T(input_id,auxiliary_type) { NULL, input_id, auxiliary_type, (AuxInputValue_T)0, (AuxInputValue_T)0, (AuxInputValue_T)0, (AuxInputValue_T)0, FALSE, MAKE_SoftwareTimer_T(), MAKE_SoftwareTimer_T() }
//! Structure containing state information for all auxiliary inputs
typedef struct AuxiliaryInputList_S
{
   //! Mutex containing priority info used for all auxiliary inputs
   Mutex_T Mutex;
   //! Auxiliary Maintenance Status
   AuxInputStatus_T Status;
   //! Timer to track timeout (100 milliseconds) since last Auxiliary Input Type 2 Maintenance message was sent
   SoftwareTimer_T MaintenanceTimer;
   //! Manufacturer defined model identification code
   ModelIdentificationCode_T model_id;
   //! Pointer to auxiliary input array
   AuxiliaryInput_T *AuxiliaryInputArray;
   //! Size of auxiliary input array
   Size_T Size;
} AuxiliaryInputList_T;
/******************************************************************************/
/*!
   \brief   Macro used to initialize an AuxiliaryInputList_T
   \details This macro is used to create an AuxiliaryInputList_T that uses previously declared arrays of AvailableInput_T.
   \param   auxiliary_input_array   Name of the array of AvailableInput_T
   \param   priority                Task priority to use for all available inputs
   \param   model_id                Manufacturer defined Model Identification Code
*/
/******************************************************************************/
#define MAKE_AuxiliaryInputList_T(priority,auxiliary_input_array,model_id) { MAKE_Mutex_T(priority), AuxInput_Initializing, MAKE_SoftwareTimer_T(), model_id, auxiliary_input_array, sizeof(auxiliary_input_array)/sizeof(AuxiliaryInput_T) }
//! Stores Preferred Assignment Data from the user
typedef struct PreferredAssignment_S
{
   //! indicates the NAME being referenced
   ISOBUS_Name_T Name;
   //! Manufacturer defined model identification code
   ModelIdentificationCode_T ModelID;
   //! Object ID of auxiliary input assigned to this function(NULL_OBJECT_ID if unassigned)
   ObjectID_T AuxInputObjectID;
} PreferredAssignment_T;
/******************************************************************************/
/*!
\brief   Macro used to initialize an Preferred_Assignment_T structure
*/
/******************************************************************************/
#define MAKE_PreferredAssignment_T() {{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF}, NULL_MODEL_ID, NULL_OBJECT_ID}
//! Structure to hold user store preferred assignment callback
typedef struct PreferredAssignments_Updated_Callback_S
{
   //! User Preferred Assignment Callback
   void(*StorePreferredAssignmentFunction)(void);
} PreferredAssignments_Updated_Callback_T;
/******************************************************************************/
/*!
\brief   Macro used to initialize an PreferredAssignments_Updated_Callback_T structure
\details This macro is used to create an element of an PreferredAssignments_Updated_Callback_T
\param   preferredassignmentdata_function         Preferred assignment data user handler
*/
/******************************************************************************/
#define MAKE_PreferredAssignments_Updated_Callback_T(preferredassignmentdata_function) { preferredassignmentdata_function }
//! Structure to hold user callbacks
typedef struct AuxiliaryFunction_Callback_S
{
   //! AssignmentType2_Command callback
   void(*AssignmentFunction)(const AuxiliaryAssignmentType2_T *cb_data, bool_t assigned);
   //! InputType2Maintenance_Message callback
   void(*MaintenanceFunction)(const AuxiliaryInputType2Maintenance_Message_T *cb_data);
   //! InputType2Status_Message callback
   void(*StatusFunction)(const AuxiliaryInputType2Status_Message_T *cb_data);
} AuxiliaryFunction_Callback_T;
/******************************************************************************/
/*!
\brief   Macro used to initialize an AuxiliaryFunction_Callback_T structure
\details This macro is used to create an element of an AuxiliaryFunction_Callback_T
\param   assign_function         AssignmentType2_Command user handler
\param   maintenance_function    InputType2Maintenance_Message user handler
\param   status_function         InputType2Status_Message user handler
*/
/******************************************************************************/
#define MAKE_AuxFunction_Callback_T(assign_function,maintenance_function,status_function) { assign_function, maintenance_function, status_function }
//! Structure to hold state information for an auxiliary function
typedef struct AuxiliaryFunction_S
{
   //! Auxiliary input unit assigned to this function.  (GLOBAL_DEST if not assigned)
   NameTableIndex_T AuxInputUnit;
   //! Preferred auxiliary input unit assigned to this function.  (GLOBAL_DEST if not assigned)
   NameTableIndex_T PreferredAuxInputUnit;
   //! Object ID of auxiliary input assigned to this function (NULL_OBJECT_ID if unassigned)
   ObjectID_T AuxInputObjectID;
   //! Object ID of the auxiliary function
   ObjectID_T AuxFunctionObjectID;
   //! Auxiliary function type
   AuxFunctionTypeID_T AuxFunctionType;
   //! Value 1 from auxiliary function
   AuxInputValue_T Value1;
   //! Value 2 from auxiliary function
   AuxInputValue_T Value2;
   //! Previous Value 1 from auxiliary function
   AuxInputValue_T PreviousValue1;
   //! Previous Value 2 from auxiliary function
   AuxInputValue_T PreviousValue2;
   //! Timer to track timeout (300 milliseconds) since last Auxiliary Input Type 2 Maintenance message was received
   SoftwareTimer_T MaintenanceTimer;
   //! Timer to track timeout (300 milliseconds) since last status (momentary) message was received
   SoftwareTimer_T StatusTimer;
   //! Callback function pointer for user callbacks
   const AuxiliaryFunction_Callback_T *EndUserCallback;
} AuxiliaryFunction_T;
/******************************************************************************/
/*!
   \brief   Macro used to initialize an AuxiliaryFuction_T structure
   \details This macro is used to create an element of an AuxiliaryFunction_T list
   \param   function_id    Auxiliary function ID
   \param   auxiliary_type AuxFunctionTypeID_T associated with this auxiliary function ID
*/
/******************************************************************************/
#define MAKE_AuxiliaryFunction_T(function_id,auxiliary_type) { GLOBAL_DEST, GLOBAL_DEST, NULL_OBJECT_ID, function_id, auxiliary_type, (AuxInputValue_T)0, (AuxInputValue_T)0, (AuxInputValue_T)0, (AuxInputValue_T)0, MAKE_SoftwareTimer_T(), MAKE_SoftwareTimer_T(), NULL }
//! Structure containing state information for all active assignments
typedef struct AuxiliaryFunctionList_S
{
   //! Mutex containing priority info used for all auxiliary assignments
   Mutex_T Mutex;
   //! Watchdog timer to track task anomalies
   SoftwareTimer_T WatchdogTimer;
   //! Pointer to auxiliary function array
   AuxiliaryFunction_T *AuxiliaryFunctionArray;
   //! Size of auxiliary function array
   Size_T Size;
   //! Flag to send the PreferredAssignmentCommand
   bool_t SendPreferredAssignment;
   //! Callback function pointer for user preferred assignment callback
   const PreferredAssignments_Updated_Callback_T *StorePreferredAssignmentCallback;
   //! Array of user preferred assignment data
   PreferredAssignment_T *PreferredAssignment;
   //! Callback function pointer for user callbacks
   const AuxiliaryFunction_Callback_T *EndUserCallback;
} AuxiliaryFunctionList_T;
/******************************************************************************/
/*!
   \brief   Macro used to initialize an AuxiliaryFunctionList_T
   \details This macro is used to create an AuxiliaryFunctionList_T that uses previously declared arrays of AuxiliaryFunction_T.
   \param   priority                  Task priority to use for all auxiliary assignments
   \param   auxiliaryfunction_array   Name of the array of auxiliary assignments
   \param   preferredassignment_array Name of the array of preferred assignments
*/
/******************************************************************************/
#define MAKE_AuxiliaryFunctionList_T(priority,auxiliaryfunction_array,preferredassignment_array) { MAKE_Mutex_T(priority), MAKE_SoftwareTimer_T(), auxiliaryfunction_array, sizeof(auxiliaryfunction_array)/sizeof(AuxiliaryFunction_T), FALSE, NULL, preferredassignment_array }
// End User Inputs
//! Auxiliary Input off bitfield value
#define AUX_OFF ((AuxInputValue_T)0x0000)
//! Auxiliary Input on bitfield value
#define AUX_ON ((AuxInputValue_T)0x0001)
// VTClient Values
//! Auxiliary Function (boolean) off bitfield value
#define OFF_CENTER_NOTPRESSED ((AuxInputValue_T)0x0000)
//! Auxiliary Function (boolean) up bitfield value
#define ON_MOMENTARY_FORWARD_UP_PRESSED ((AuxInputValue_T)0x0001)
//! Auxiliary Function (boolean) held up bitfield value
#define HELD_FORWARD_UP ((AuxInputValue_T)0x0002)
//! Auxiliary Function (boolean) down bitfield value
#define ON_MOMENTARY_BACKWARD_DOWN ((AuxInputValue_T)0x0004)
//! Auxiliary Function (boolean) held down bitfield value
#define HELD_BACKWARD_DOWN ((AuxInputValue_T)0x0008)
//! Auxiliary Function (analog) latched forward bitfield value
#define ANALOG_LATCHED_FORWARD ((AuxInputValue_T)0xFB00)
//! Auxiliary Function (analog) latched backward bitfield value
#define ANALOG_LATCHED_BACKWARD ((AuxInputValue_T)0xFB01)
//! Auxiliary Function (quadrature) up bitfield value
#define QUAD_TRANSITION_UP ((AuxInputValue_T)0x0001)
//! Auxiliary Function (quadrature) held up bitfield value
#define QUAD_HELD_UP ((AuxInputValue_T)0x0002)
//! Auxiliary Function (quadrature) down bitfield value
#define QUAD_TRANSITION_DOWN ((AuxInputValue_T)0x0004)
//! Auxiliary Function (quadrature) held down bitfield value
#define QUAD_HELD_DOWN ((AuxInputValue_T)0x0008)
//! Auxiliary Function (quadrature) right bitfield value
#define QUAD_TRANSITION_RIGHT ((AuxInputValue_T)0x0010)
//! Auxiliary Function (quadrature) held right bitfield value
#define QUAD_HELD_RIGHT ((AuxInputValue_T)0x0020)
//! Auxiliary Function (quadrature) left bitfield value
#define QUAD_TRANSITION_LEFT ((AuxInputValue_T)0x0040)
//! Auxiliary Function (quadrature) held left bitfield value
#define QUAD_HELD_LEFT ((AuxInputValue_T)0x0080)
/******************************************************************************/
//! Contains all Foundation Functionality information for an ISOBUS App
typedef struct VTClient_S
{
   //! Pointer to mutex containing priority info used for a VTClient
   Mutex_T Mutex;
   //! Pointer to the foundation layer
   Foundation_T *Foundation;
   //! Language Command Handler
   LanguageCallback_T LanguageCallback;
   //! Active VT List
   ActiveVtList_T ActiveVTs;
   //! Struct for registering a message handler for the VT to ECU message
   struct Transport_MessageHandler_Node_S VTClient_MessageHandler_Node;
   //! Struct for registering a message handler for the ECU to VT message
   struct Transport_MessageHandler_Node_S VTClient_ECUtoVT_Node;
   //! Struct for registering a request handler for the VT to ECU message
   struct Request_Node_S Request_VTtoECU_Node;
   //! Struct for registering a request handler for the ECU to VT message
   struct Request_Node_S Request_ECUtoVT_Node;
   //! Struct for registering a handler to process ACKs to the ECU to VT message
   struct Acknowledge_Node_S Acknowledge_ECUtoVT_Node;
   //! Active Auxiliary Assignments
   AuxiliaryFunctionList_T *AuxiliaryFunctionList;
   //! Available Auxiliary Inputs
   AuxiliaryInputList_T *AuxiliaryInputList;
   //! Pointer to Auxilary VT (Function Instance 0)
   VT_T *AuxiliaryVT;
   struct
   {
      //  Vt
      // Annex H
      //! Application Callback for Pointing Event
      void(*PointingEvent_Message) (struct VTClient_S *vt_client, const VT_T *vt, const PointingEvent_T *);
      //! Application Callback for Signaling Termination of Audio Signal
      void(*VtControlAudioSignalTermination_Message)(struct VTClient_S *vt_client, const VT_T *vt, const VtControlAudioSignalTermination_T *);
      // Annex G
      //  void (*Vt_Status_Message_cb)               (const VT_Status_T *);
      // Ecu
      // Annex D
      //! Application Callback for Get Memory response
      void(*GetMemory_Response) (struct VTClient_S *vt_client, const VT_T *vt, const GetMemory_Response_T *);
      //! Application Callback for Get Number of Soft Keys response
      void(*GetNumberOfSoftKeys_Response) (struct VTClient_S *vt_client, const VT_T *vt, const GetSoftKeys_Response_T *);
      //! Application Callback for Get Text Font Data response
      void(*GetTextFontData_Response) (struct VTClient_S *vt_client, const VT_T *vt, const GetTextFont_Response_T *);
      //! Application Callback for Get Hardware response
      void(*GetHardware_Response) (struct VTClient_S *vt_client, const VT_T *vt, const GetHardware_Response_T *);
      //! Application Callback for Get Supported Wide-Chars response
      void(*GetSupportedWideChars_Response) (struct VTClient_S *vt_client, const VT_T *vt, /*      GetWideChars_Response_T*/ void *);
      //! Application Callback for Get Window Mask Data response
      void(*GetWindowMaskData_Response) (struct VTClient_S *vt_client, const VT_T *vt, const GetWindowMask_Response_T *);
      //! Application Callback for Get Supported Objects response
      void(*GetSupportedObjects_Response) (struct VTClient_S *vt_client, const VT_T *vt, /*      GetSupportedObjects_Response_T*/ void *);
      // Annex E
      //! Application Callback for Get Versions response
      void(*GetVersions_Response) (struct VTClient_S *vt_client, const VT_T *vt, GetVersions_Response_T *); // 224 - VT Response
      //! Application Callback for Store Version response
      void(*StoreVersion_Response) (struct VTClient_S *vt_client, const VT_T *vt, const StoreVersion_Response_T *); // 208 - VT Response
      //! Application Callback for Load Version response
      void(*LoadVersion_Response) (struct VTClient_S *vt_client, const VT_T *vt, const LoadVersion_Response_T *); // 209 - VT Response
      //! Application Callback for Delete Version response
      void(*DeleteVersion_Response) (struct VTClient_S *vt_client, const VT_T *vt, const DeleteVersion_Response_T *); // 210 - VT Response
      // Annex F
      //! Application Callback for Control Audio Signal response
      void(*ControlAudioSignal_Response) (struct VTClient_S *vt_client, const VT_T *vt, const ControlAudioSignal_Response_T *); // 163 - ECU command, VT will reply
      //! Application Callback for Set Audio Volume response
      void(*SetAudioVolume_Response) (struct VTClient_S *vt_client, const VT_T *vt, const SetAudioVolume_Response_T *); // 164 - ECU command, VT will reply
      // //! Application Callback for Delete Object Pool response
      //  void(*DeleteObjectPool_Response)          (const DeleteObjectPool_Response_T *);
      //! Application Callback for Lock/Unlock Mask response
      void(*LockUnlockMask_Response) (struct VTClient_S *vt_client, const VT_T *vt, const LockUnlockMask_Response_T *); // 189 - ECU command, VT will reply
      //! Application Callback for Execute Macro response
      void(*ExecuteMacro_Response) (struct VTClient_S *vt_client, const VT_T *vt, const ExecuteMacro_Response_T *); // 190 - ECU command, VT will reply
      //! Application Callback for Change Object Label response
      void(*ChangeObjectLabel_Response) (struct VTClient_S *vt_client, const VT_T *vt, const ChangeObjectLabel_Response_T *); // 181 - ECU command, VT will reply
      // //! Application Callback for Identify VT response
      //  void(*IdentifyVt_Response)                ();
   } VtCallbackList; //!< Structure containing registered callbacks used for messages received from all active VTs.
} VTClient_T;
/******************************************************************************/
/*!
   \brief  Macro for initializing VTClient_T structure
   \param  foundation_ptr     Pointer to the corresponding Foundation_T structure
   \param  vt_array           Name of VT_T array
   \param  aux_function_list  Auxiliary function array
   \param  aux_input_list     Auxiliary input array
   \param  priority           Maximum task priority that accesses this structure
*/
/******************************************************************************/
#define MAKE_VTClient_T(foundation_ptr,vt_array,aux_function_list,aux_input_list,priority) \
 { \
 MAKE_Mutex_T(priority), \
 foundation_ptr, \
 MAKE_LanguageCallback_T(), \
 MAKE_ActiveVtList_T(vt_array, priority), \
 MAKE_Transport_MessageHandler_Node_S(0xE600,NULL,Filter_GlobalOrWorkingSetOrDestinationSpecificToMe,NULL,NULL,1785), \
 MAKE_Transport_MessageHandler_Node_S(0xE700,NULL,Filter_GlobalOrWorkingSetOrDestinationSpecificToMe,NULL,NULL,20), \
 MAKE_Request_Node_S(0xE600, Request_AutoAcknowledgePositive, NULL, NULL), \
 MAKE_Request_Node_S(0xE700, Request_AutoAcknowledgePositive, NULL, NULL), \
 MAKE_Acknowledge_Node_S(0xE700, FALSE, 0xFF, NULL, NULL, NULL), \
 aux_function_list, \
 aux_input_list, \
 NULL, \
 { \
 NULL, \
 NULL, \
 NULL, \
 NULL, \
 NULL, \
 NULL, \
 NULL, \
 NULL, \
 NULL, \
 NULL, \
 NULL, \
 NULL, \
 NULL, \
 NULL, \
 NULL, \
 NULL, \
 NULL, \
 NULL \
 } \
 }
/******************************************************************************/
// Annex C  Object transport protocol
/******************************************************************************/
/******************************************************************************/
// Annex D  Technical data messages
/******************************************************************************/
/******************************************************************************/
//! D.2  Get Memory message
/******************************************************************************/
/*!
   \details  The Get Memory message allows the Working Set to determine if the
             VT is out of memory and also determines the VT version.
   \param    vt_client        VTClient structure containing all active VTs
   \param    vt               VT instance
   \param    callback         Callback when message is sent
   \param    memory_required  Number of bytes in object pool
   \return  bool_t
   \retval  TRUE   Message was sent
   \retval  FALSE  Message was not sent  (try again later)
*/
/******************************************************************************/
extern bool_t GetMemory_Message(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, Size_T memory_required);
/******************************************************************************/
//! D.4  Get Number of Soft Keys message
/******************************************************************************/
/*!
   \details  The Get Number of Soft Keys message supplies the Working Set with
             the available divisions of the X and Y axes for Soft Key
             descriptors, the available virtual Soft Keys and the number of
             physical Soft Keys.
   \param    vt_client  VTClient structure containing all active VTs
   \param    vt         VT instance
   \param    callback   Callback when message is sent
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t GetNumberOfSoftKeys_Message(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback);
/******************************************************************************/
//! D.6  Get Text Font Data message
/******************************************************************************/
/*!
   \details  The Get Text Font Data message provides the Working Set with the
             characteristics of fonts, type sizes, type attributes and colour
             capabilities.
   \param    vt_client  VTClient structure containing all active VTs
   \param    vt         VT instance
   \param    callback   Callback when message is sent
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t GetTextFontData_Message(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback);
/******************************************************************************/
//! D.8  Get Hardware message
/******************************************************************************/
/*!
   \details  The Get Hardware message informs the Working Set as to the hardware
             design of the VT.
   \param    vt_client  VTClient structure containing all active VTs
   \param    vt         VT instance
   \param    callback   Callback when message is sent
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t GetHardware_Message(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback);
/******************************************************************************/
//! D.10  Get Supported WideChars message
/******************************************************************************/
/*!
   \details  The Get Suppored WideChars message supplies the Working Set with a
             list of the WideChars supported by the VT.
   \note  VTv4 and later
   \param    vt_client        VTClient structure containing all active VTs
   \param    vt               VT instance
   \param    callback         Callback when message is sent
   \param    codeplane        Code Plane of the wide char range requested
   \param    first_wide_char  First WideChar in inquiry range
   \param    last_wide_char   Last WideChar in inquiry range
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t GetSupportedWideChars_Message(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, WideChar_CodePlane_T codeplane, WideChar_T first_wide_char, WideChar_T last_wide_char);
/******************************************************************************/
//! D.12  Get Window Mask Data message
/******************************************************************************/
/*!
   \details  The Get Window Mask Data message provides the Working Set with the
             background colour of User-Layout Data Mask and background colour of
             the Key Cells on a User-Layout Soft Key Mask.
   \note  VTv4 and later
   \param    vt_client  VTClient structure containing all active VTs
   \param    vt         VT instance
   \param    callback   Callback when message is sent
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t GetWindowMaskData_Message(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback);
/******************************************************************************/
//! D.14  Get Supported Objects message
/******************************************************************************/
/*!
   \details  The Get Supported Objects message is used by the Working Set to get
             the list of all object types supported by the VT.
   \note  VTv4 and later
   \param    vt_client  VTClient structure containing all active VTs
   \param    vt         VT instance
   \param    callback   Callback when message is sent
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t GetSupportedObjects_Message(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback);
/******************************************************************************/
// Annex E  Non-volatile memory operations commands
/******************************************************************************/
/******************************************************************************/
//! E.2  Get Versions message
/******************************************************************************/
/*!
   \brief    Requests list of object pool versions stored on the VT
   \details  The Get Versions message allows the Working Set to query the VT for
             existing version labels associated with the requesting Working Set.
   \param    vt_client  VTClient structure containing all active VTs
   \param    vt         VT instance
   \param    callback   Callback when message is sent
   \return  bool_t
   \retval  TRUE   Message was sent
   \retval  FALSE  Message was not sent  (try again later)
*/
/******************************************************************************/
extern bool_t GetVersions_Message(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback);
/******************************************************************************/
//! E.4  Store Version command
/******************************************************************************/
/*!
   \brief    Stores current object pool state with supplied version label
   \details  The Store Version command allows a Working Set to store the copy of
             the actual object pool into the non-volatile storage of the VT.
             This message can be sent at any time. The copy is stored as the
             version indicated by version label.  If a copy with the same
             version label already exists in the non-volatile storage area, it
             is overwritten.  All objects are stored as they are (with current
             attributes, input values, etc.). If the version label contains no
             string (all blanks) the last stored version in non-volatile storage
             shall be overwritten; alternatively, if there is no version stored
             up to that point, an error shall be indicated by the VT.
   \param    vt_client  VTClient structure containing all active VTs
   \param    vt         VT instance
   \param    callback   Callback when message is sent
   \param    version    Version label
   \return  bool_t
   \retval  TRUE   Message was sent
   \retval  FALSE  Message was not sent  (try again later)
*/
/******************************************************************************/
extern bool_t StoreVersion_Command(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, const char *version);
/******************************************************************************/
//! E.6  Load Version command
/******************************************************************************/
/*!
   \brief    Loads object pool with supplied version label on the VT
   \details  The Load Version command allows a Working Set to load a copy of an
             object pool from the non-volatile storage of the VT.  If an object
             pool is already loaded it is overwritten.  If the message is
             acknowledged positive by the VT, the Working Set may proceed as if
             all objects had been transmitted normally.  If the version label
             contains no string (all blanks), the last stored version in
             non-volatile storage shall be loaded.
             When the VT receives the Load Version command, it shall set the
             "parsing" bit in the VT Status message to 1 until it has finished
             parsing the object pool and sends the Load Version Response
             message.
             The Working Set Master shall wait for the Load Version response
             until three consecutive VT Status messages have been received where
             the "parsing" bit is set to 0.  At that time, if the Load Version
             response has not been received by the Working Set Master, then it
             shall assume that the Load Version command was not received by the
             VT.  Three messages are waited for, to avoid race conditions
             created by a VT Status message that could already be in a transmit
             queue and which does not correctly identify the parsing state.
   \param    vt_client  VTClient structure containing all active VTs
   \param    vt         VT instance
   \param    callback   Callback when message is sent
   \param    version    Version label
   \return  bool_t
   \retval  TRUE   Message was sent
   \retval  FALSE  Message was not sent  (try again later)
*/
/******************************************************************************/
extern bool_t LoadVersion_Command(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, const char *version);
/******************************************************************************/
//! E.8  Delete Version command
/******************************************************************************/
/*!
   \brief    Deletes object pool with supplied version label from the VT
   \details  The Delete Version command allows a Working Set to delete a version
             of an object pool in the non-volatile storage of the VT.  If a copy
             of this version is in the volatile memory at the same time, it is
             preserved there - this message affects non-volatile storage only.
             If the version label contains no string (all blanks) the last
             stored version in non-volatile storage is to be deleted.  For
             deleting the object pool from volatile memory, see F.44.
   \param    vt_client  VTClient structure containing all active VTs
   \param    vt         VT instance
   \param    callback   Callback when message is sent
   \param    version    Version label
   \return  bool_t
   \retval  TRUE   Message was sent
   \retval  FALSE  Message was not sent  (try again later)
*/
/******************************************************************************/
extern bool_t DeleteVersion_Command(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, const char *version);
/******************************************************************************/
// Annex F  Command and Macro messages
/******************************************************************************/
/******************************************************************************/
//! F.2  Hide/Show Object command
/******************************************************************************/
/*!
   \brief    Function sends Vt Command(160) HIDE/SHOW OBJECT to the VT.
   \details  Sends a destination specific HIDE/SHOW OBJECT command to the VT. If a
             callback is provided, it will be called when the VT reply is received.
   \param    vt_client  pointer to the application's VTClient data structure
   \param    vt         pointer to the application's active data structure
   \param    callback   Callback when message is sent
   \param    object_id  Object ID
   \param    show_flag  Object_Hidden or Object_Shown
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t HideShowObject_Command(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T object_id, ShowHide_Status_T show_flag);
/******************************************************************************/
//! F.4  Enable/Disable Object command
/******************************************************************************/
/*!
   \brief    Function sends Vt Command(161) ENABLE/DISABLE OBJECT to the VT.
   \details  Sends a destination specific ENABLE/DISABLE OBJECT command to the VT.
             If a callback is provided, it will be called when the VT reply is
             received.
   \param    vt_client    pointer to the application's VTClient data structure
   \param    vt           pointer to the application's active data structure
   \param    callback     Callback when message is sent
   \param    object_id    Object ID
   \param    enable_flag  0 = Disable, 1 = Enable
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t EnableDisableObject_Command(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T object_id, EnableDisable_Status_T enable_flag);
/******************************************************************************/
//! F.6  Select Input Object command
/******************************************************************************/
/*!
   \brief    Function sends Vt Command(162) SELECT INPUT OBJECT to the VT.
   \details  Sends a destination specific SELECT INPUT OBJECT command to the VT.
             If a callback is provided, it will be called when the VT reply is
             received.
   \param    vt_client  pointer to the application's VTClient data structure
   \param    vt         pointer to the application's active data structure
   \param    callback   Callback when message is sent
   \param    object_id  Object ID - NULL Object ID indicates that no object
                        shall be selected (i.e. focus is removed)
   \param    option     Object_NotSelected:  Object is not selected
                        Object_Selected:  Set Focus to object referenced by
                           Object ID
                        Object_SelectedAndOpenForEdit:  Activate for data input
                           object referenced by Object ID (invalid for Button
                           Object or Key Object) NOTE Value 0 available only on
                           VT Version 4 and later.
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t SelectInputObject_Command(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T object_id, Object_SelectionState_T option);
/******************************************************************************/
//! F.8  ESC command
/******************************************************************************/
/*!
   \brief    Function sends Vt Command(146) ECU ESC to the VT.
   \details  Sends a destination specific ECU ESC command to the VT. If a callback
             is provided, it will be called when the VT reply is received.
   \param    vt_client  pointer to the application's VTClient data structure
   \param    vt         pointer to the application's active data structure
   \param    callback   Callback when message is sent
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t Esc_Command(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback);
/******************************************************************************/
//! F.10  Control Audio Signal command
/******************************************************************************/
/*!
   \brief    Function sends Vt Command(163) CONTROL AUDIO SIGNAL to the VT.
   \details  Sends a destination specific CONTROL AUDIO SIGNAL command to the VT.
             If a callback is provided, it will be called when the VT reply is
             received.
   \param    vt_client    pointer to the application's VTClient data structure
   \param    vt           pointer to the application's active data structure
   \param    callback     Callback when message is sent
   \param    activations  Activations 0 = Terminates any audio in process from
                          the originating ECU (Frequency and Duration values are ignored).
                          1-255 = Number of Audio Activations.
   \param    frequency    Frequency in Hz. If the Frequency specified is outside
                          the VT capabilities for production of sound (also applies to
                          non-multiple frequency devices) then the VT limits the frequency to
                          the reproducible range
   \param    on_time      On-time duration in ms. If the duration specified is less
                          than the VT capabilities for timing, the VT shall time the audio to
                          the VT's smallest controlled value
   \param    off_time     Off-time duration in ms. If the duration specified is
                          less than the VT capabilities for timing, the VT shall time the
                          audio to the VT's smallest controlled value
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t ControlAudioSignal_Command(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, AudioSignalActivation_T activations, Frequency_T frequency, Time_T on_time, Time_T off_time);
/******************************************************************************/
//! F.12  Set Audio Volume command
/******************************************************************************/
/*!
   \brief    Function sends Vt Command(164) SET AUDIO VOLUME to the VT.
   \details  Sends a destination specific SET AUDIO VOLUME command to the VT. If
             a callback is provided, it will be called when the VT reply is received.
   \param    vt_client  pointer to the application's VTClient data structure
   \param    vt         pointer to the application's active data structure
   \param    callback   Callback when message is sent
   \param    percent    Percent (0 to 100 %) of maximum volume
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t SetAudioVolume_Command(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, AudioVolume_T percent);
/******************************************************************************/
//! F.14  Change Child Location command
/******************************************************************************/
/*!
   \brief    Function sends Vt Command(165) CHANGE CHILD LOCATION to the VT.
   \details  Sends a destination specific CHANGE CHILD LOCATION command to the VT.
             If a callback is provided, it will be called when the VT reply is received.
   \param    vt_client          pointer to the application's VTClient data structure
   \param    vt                 pointer to the application's active data structure
   \param    callback           Callback when message is sent
   \param    parent_obj_id      Parent Object ID
   \param    child_obj_id       Object ID of object to move
   \param    change_x_position  Relative change in X position
   \param    change_y_position  Relative change in Y position
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t ChangeChildLocation_Command(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T parent_obj_id, ObjectID_T child_obj_id, Pixel_T change_x_position, Pixel_T change_y_position);
/******************************************************************************/
//! F.16  Change Child Position command (transport protocol)
/******************************************************************************/
/*!
   \brief    Function sends Vt Command(180) CHANGE CHILD POSITION to the VT.
   \details  Sends a destination specific CHANGE CHILD POSITION command to the VT.
             If a callback is provided, it will be called when the VT reply is received.
   \param    vt_client       pointer to the application's VTClient data structure
   \param    vt              pointer to the application's active data structure
   \param    callback        Callback when message is sent
   \param    parent_obj_id   Parent Object ID
   \param    object_id       Object ID of object to move
   \param    new_x_position  New X position relative to the top left corner of
                             parent object
   \param    new_y_position  New Y position relative to the top left corner of
                             parent object
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t ChangeChildPosition_Command(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_MessageCallback_T *callback, ObjectID_T parent_obj_id, ObjectID_T object_id, Pixel_T new_x_position, Pixel_T new_y_position);
/******************************************************************************/
//! F.18  Change Size command
/******************************************************************************/
/*!
   \brief    Function sends Vt Command(166) CHANGE SIZE to the VT.
   \details  Sends a destination specific CHANGE SIZE command to the VT. If a
             callback is provided, it will be called when the VT reply is received.
   \param    vt_client   pointer to the application's VTClient data structure
   \param    vt          pointer to the application's active data structure
   \param    callback    Callback when message is sent
   \param    object_id   Object ID of object to size
   \param    new_width   New width
   \param    new_height  New height
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t ChangeSize_Command(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T object_id, Pixel_T new_width, Pixel_T new_height);
/******************************************************************************/
//! F.20  Change Background Colour command
/******************************************************************************/
/*!
   \brief    Function sends Vt Command(167) CHANGE BACKGROUND COLOUR to the VT.
   \details  Sends a destination specific CHANGE BACKGROUND COLOUR command to the VT.
             If a callback is provided, it will be called when the VT reply is received.
   \param    vt_client  pointer to the application's VTClient data structure
   \param    vt         pointer to the application's active data structure
   \param    callback   Callback when message is sent
   \param    object_id  Object ID of object to change
   \param    color      New Background colour
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t ChangeBackgroundColour_Command(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T object_id, Colour_T color);
/******************************************************************************/
//! F.22  Change Numeric Value command
/******************************************************************************/
/*!
   \brief    Function sends Vt Command(168) CHANGE NUMERIC VALUE to the VT.
   \details  Sends a destination specific CHANGE NUMERIC VALUE command to the VT.
             If a callback is provided, it will be called when the VT reply is received.
   \param    vt_client  pointer to the application's VTClient data structure
   \param    vt         pointer to the application's active data structure
   \param    callback   Callback when message is sent
   \param    object_id  Object ID of object to change
   \param    value      New value for value attribute. Size depends on object type.
                        Objects of size 1 byte are found in Byte 5. Objects of size 2 bytes
                        are found in Bytes 5-6. Values greater than 1 byte are transmitted
                        little endian (LSB first). Unused bytes shall be filled with zero.
                        Boolean input object: 1 byte for TRUE/FALSE
                        Number input object: 4 bytes for integer input List input object:
                        1 byte for list index List output object: 1 byte for list index
                        Number output object: 4 bytes for integer output Meter: 2 bytes for
                        integer value Linear bar graph: 2 bytes for integer value Arched bar
                        graph: 2 bytes for integer value Number variable: 4 bytes for integer
                        value Object pointer: 2 bytes for Object ID
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t ChangeNumericValue_Command(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T object_id, NumericValue_T value);
/******************************************************************************/
//! F.24  Change String Value command (transport protocol)
/******************************************************************************/
/*!
   \brief    Function sends Vt Command(179) CHANGE STRING VALUE to the VT.
   \details  Sends a destination specific CHANGE STRING VALUE command to the VT.
             If a callback is provided, it will be called when the VT reply is received.
   \param    vt_client      pointer to the application's VTClient data structure
   \param    vt             pointer to the application's active data structure
   \param    callback       Callback when message is sent
   \param    object_id      Object ID of the object to change
   \param    string_length  Total number of bytes in the string to transfer
   \param    string         Pointer to a string
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t ChangeStringValue_Command(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_MessageCallback_T *callback, ObjectID_T object_id, Size_T string_length, const char *string);
/******************************************************************************/
//! F.26  Change End Point command
/******************************************************************************/
/*!
   \brief    Function sends Vt Command(169) CHANGE END POINT to the VT.
   \details  Sends a destination specific CHANGE END POINT command to the VT. If
             a callback is provided, it will be called when the VT reply is received.
   \param    vt_client  pointer to the application's VTClient data structure
   \param    vt         pointer to the application's active data structure
   \param    callback   Callback when message is sent
   \param    object_id  Object ID of a Line object to change
   \param    width      Width in pixels
   \param    height     Height in pixels
   \param    direction  Line Direction (refer to Line object attributes)
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t ChangeEndPoint_Command(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T object_id, Pixel_T width, Pixel_T height, LineDirection_T direction);
/******************************************************************************/
//! F.28  Change Font Attributes command
/******************************************************************************/
/*!
   \brief    Function sends Vt Command(170) CHANGE FONT ATTRIBUTES to the VT.
   \details  Sends a destination specific CHANGE FONT ATTRIBUTES command to the VT.
             If a callback is provided, it will be called when the VT reply is received.
   \param    vt_client  pointer to the application's VTClient data structure
   \param    vt         pointer to the application's active data structure
   \param    callback   Callback when message is sent
   \param    object_id  Object ID of object to change
   \param    color      Font colour
   \param    size       Font size
   \param    type       Font type
   \param    style      Font style
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t ChangeFontAttributes_Command(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T object_id, Colour_T color, FontSize_T size, FontType_T type, FontStyle_T style);
/******************************************************************************/
//! F.30  Change Line Attributes command
/******************************************************************************/
/*!
   \brief    Function sends Vt Command(171) CHANGE LINE ATTRIBUTES to the VT.
   \details  Sends a destination specific CHANGE LINE ATTRIBUTES command to the VT.
             If a callback is provided, it will be called when the VT reply is received.
   \param    vt_client  pointer to the application's VTClient data structure
   \param    vt         pointer to the application's active data structure
   \param    callback   Callback when message is sent
   \param    object_id  Object ID of object to change
   \param    color      Line Colour
   \param    width      Line Width
   \param    line_art   Line Art
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t ChangeLineAttributes_Command(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T object_id, Colour_T color, Pixel_T width, LineArt_T line_art);
/******************************************************************************/
//! F.32  Change Fill Attributes command
/******************************************************************************/
/*!
   \brief    Function sends Vt Command(172) CHANGE FILL ATTRIBUTES to the VT.
   \details  Sends a destination specific CHANGE FILL ATTRIBUTES command to the VT.
             If a callback is provided, it will be called when the VT reply is received.
   \param    vt_client   pointer to the application's VTClient data structure
   \param    vt          pointer to the application's active data structure
   \param    callback    Callback when message is sent
   \param    object_id   Object ID of object to change
   \param    type        Fill Type
   \param    color       Fill Colour
   \param    pattern_id  Fill Pattern object ID
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t ChangeFillAttributes_Command(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T object_id, FillType_T type, Colour_T color, ObjectID_T pattern_id);
/******************************************************************************/
//! F.34  Change Active Mask command
/******************************************************************************/
/*!
   \brief    Function sends Vt Command(173) CHANGE ACTIVE MASK to the VT.
   \details  Sends a destination specific CHANGE ACTIVE MASK command to the VT.
             If a callback is provided, it will be called when the VT reply is received.
   \param    vt_client    pointer to the application's VTClient data structure
   \param    vt           pointer to the application's active data structure
   \param    callback     Callback when message is sent
   \param    object_id    Working Set Object ID
   \param    new_mask_id  New Active Mask Object ID
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t ChangeActiveMask_Command(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T object_id, ObjectID_T new_mask_id);
/******************************************************************************/
//! F.36  Change Soft Key Mask command
/******************************************************************************/
/*!
   \brief    Function sends Vt Command(174) CHANGE ACTIVE MASK to the VT.
   \details  Sends a destination specific CHANGE ACTIVE MASK command to the VT.
             If a callback is provided, it will be called when the VT reply is received.
   \param    vt_client        pointer to the application's VTClient data structure
   \param    vt               pointer to the application's active data structure
   \param    callback         Callback when message is sent
   \param    mask_type        Mask Type (1 = Data, 2 = Alarm)
   \param    mask_object_id   Data or Alarm Mask Object ID
   \param    new_soft_key_id  New Soft Key Mask Object ID
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t ChangeSoftKeyMask_Command(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T mask_object_id, ObjectID_T new_soft_key_id, MaskType_T mask_type);
/******************************************************************************/
//! F.38  Change Attribute command
/******************************************************************************/
/*!
   \brief    Function sends Vt Command(175) CHANGE ATTRIBUTE to the VT.
   \details  Sends a destination specific CHANGE ATTRIBUTE command to the VT. If
             a callback is provided, it will be called when the VT reply is received.
   \param    vt_client     pointer to the application's VTClient data structure
   \param    vt            pointer to the application's active data structure
   \param    callback      Callback when message is sent
   \param    object_id     Object ID of object to change
   \param    attribute_id  Attribute ID (AID)
   \param    attribute     New value for attribute. Size depends on attribute data
                           type. Values greater than 1 byte are transmitted little endian (LSB
                           first): Boolean: 1 byte for TRUE/FALSE Integer: 1, 2 or 4 bytes as
                           defined in object tables, Float: 4 bytes, Bitmask: 1 byte
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t ChangeAttribute_Command(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T object_id, NumericValue_T attribute, AttributeID_T attribute_id);
/******************************************************************************/
//! F.40  Change Priority command
/******************************************************************************/
/*!
   \brief    Function sends Vt Command(176) CHANGE PRIORITY to the VT.
   \details  Sends a destination specific CHANGE PRIORITY command to the VT. If a
             callback is provided, it will be called when the VT reply is received.
   \param    vt_client  pointer to the application's VTClient data structure
   \param    vt         pointer to the application's active data structure
   \param    callback   Callback when message is sent
   \param    object_id  Object ID of Alarm Mask
   \param    priority   New priority
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t ChangePriority_Command(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T object_id, AlarmPriority_T priority);
/******************************************************************************/
//! F.42  Change List Item command
/******************************************************************************/
/*!
   \brief    Function sends Vt Command(177) CHANGE LIST ITEM to the VT.
   \details  Sends a destination specific CHANGE LIST ITEM command to the VT. If a
             callback is provided, it will be called when the VT reply is received.
   \param    vt_client      pointer to the application's VTClient data structure
   \param    vt             pointer to the application's active data structure
   \param    callback       Callback when message is sent
   \param    object_id      Object ID of an Input List object or Output List object
   \param    list_index     List Index (items are numbered 0-n)
   \param    new_object_id  New object ID or NULL_OBJECT_ID to set empty item
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t ChangeListItem_Command(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T object_id, ListIndex_T list_index, ObjectID_T new_object_id);
/******************************************************************************/
//! F.44  Delete Object Pool command
/******************************************************************************/
/*!
   \brief    Sends Delete Object Pool command
   \param    vt_client  VTClient structure containing all active VTs
   \param    vt         VT instance
   \param    callback   Callback when message is sent
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t DeleteObjectPool_Command(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback);
/******************************************************************************/
//! F.46  Lock/Unlock Mask command
/******************************************************************************/
/*!
   \brief    Function sends Vt Command(189) LOCK/UNLOCK MASK to the VT.
   \details  Sends a destination specific LOCK/UNLOCK MASK command to the VT. If a
             callback is provided, it will be called when the VT reply is received.
   \param    vt_client  pointer to the application's VTClient data structure
   \param    vt         pointer to the application's active data structure
   \param    callback   Callback when message is sent
   \param    command    Command: 0 = Unlock Data Mask or Window Mask,
                                 1 = Lock Data Mask or Window Mask
   \param    object_id  Object ID of the Data Mask or Window Mask to Lock. If
                        this does not match the visible mask, the command fails with a
                        response code
   \param    timeout    Lock timeout in ms or zero for no timeout. Once this period
                        expires, the VT shall automatically release the lock if the Working
                        Set has not done so. This attribute does not apply to an Unlock command
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t LockUnlockMask_Command(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, MaskCommand_T command, ObjectID_T object_id, Time_T timeout);
/******************************************************************************/
//! F.48  Execute Macro command
/******************************************************************************/
/*!
   \brief    Function sends Vt Command(190) EXECUTE MACRO to the VT.
   \details  Sends a destination specific EXECUTE MACRO command to the VT. If a
             callback is provided, it will be called when the VT reply is received.
   \param    vt_client  pointer to the application's VTClient data structure
   \param    vt         pointer to the application's active data structure
   \param    callback   Callback when message is sent
   \param    macro      Object ID of Macro object
   \return  bool_t
   \retval  TRUE if the message is sent or queued to be sent
   \retval  FALSE if the message was not sent
*/
/******************************************************************************/
extern bool_t ExecuteMacro_Command(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, MacroID_T macro);
/******************************************************************************/
//! F.50  Change Object Label command
/******************************************************************************/
/*!
   \brief    Function sends Vt Command(181) CHANGE OBJECT LABEL to the VT.
   \details  Sends a destination specific CHANGE OBJECT LABEL command to the VT.
             If a callback is provided, it will be called when the VT reply is received.
   \param    vt_client       pointer to the application's VTClient data structure
   \param    vt              pointer to the application's active data structure
   \param    callback        Callback when message is sent
   \param    object_id       Object ID of object to associate label with
   \param    string_obj_id   Object ID of a String Variable object that contains
                             the label string (32 characters maximum) or NULL_OBJECT_ID if no text is
                             supplied
   \param    font_type       Font type (ignored if String Variable object reference
                             is NULL Object ID or the string contains a WideString)
   \param    graphic_obj_id  Object ID of an object to be used as a graphic
                             representation of the object label or NULL_OBJECT_ID if no designator
                             supplied. When the VT draws this object it shall be clipped to the
                             size of a Soft Key designator
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t ChangeObjectLabel_Command(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T object_id, ObjectID_T string_obj_id, FontType_T font_type, ObjectID_T graphic_obj_id);
/******************************************************************************/
//! F.52  Change Polygon Point command
/******************************************************************************/
/*!
   \brief    Function sends Vt Command(182) CHANGE POLYGON POINT to the VT.
   \details  Sends a destination specific CHANGE POLYGON POINT command to the VT.
             If a callback is provided, it will be called when the VT reply is received.
   \param    vt_client    pointer to the application's VTClient data structure
   \param    vt           pointer to the application's active data structure
   \param    callback     Callback when message is sent
   \param    object_id    Object ID of the Polygon object to change
   \param    point_index  Point index of the point to replace
   \param    new_x_value  New X value of a point relative to the top left corner
                          of the polygon
   \param    new_y_value  New Y value of a point relative to the top left corner
                          of the polygon
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t ChangePolygonPoint_Command(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T object_id, PolygonPointIndex_T point_index, Pixel_T new_x_value, Pixel_T new_y_value);
/******************************************************************************/
//! F.54  Change Polygon Scale command
/******************************************************************************/
/*!
   \brief    Function sends Vt Command(183) CHANGE POLYGON SCALE to the VT.
   \details  Sends a destination specific CHANGE POLYGON SCALE command to the VT.
             If a callback is provided, it will be called when the VT reply is received.
   \param    vt_client   pointer to the application's VTClient data structure
   \param    vt          pointer to the application's active data structure
   \param    callback    Callback when message is sent
   \param    object_id   Object ID of a Polygon object to scale
   \param    new_width   New width attribute
   \param    new_height  New height attribute
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t ChangePolygonScale_Command(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T object_id, Pixel_T new_width, Pixel_T new_height);
/******************************************************************************/
//! F.56  Graphics Context command  (Set Graphics Cursor)
/******************************************************************************/
/*!
   \brief    Alters the Graphics Cursor X/Y to an absolute position
   \details  This command alters the graphics cursor X/Y attributes of the
             object to the provided absolute position.
   \param    vt_client   VTClient data structure
   \param    vt          VT to interact with
   \param    callback    Callback when message is sent
   \param    object_id   Object ID of the Graphics Context object to modify
   \param    x_position  New cursor X position
   \param    y_position  New cursor Y position
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t GraphicsContext_SetGraphicsCursor_Command(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T object_id, Pixel_T x_position, Pixel_T y_position); // 184-0
/******************************************************************************/
//! F.56  Graphics Context command  (Move Graphics Cursor)
/******************************************************************************/
/*!
   \brief    Alters the Graphics Cursor X/Y to a relative position
   \details  This command alters the graphics cursor X/Y attributes of the
             object by moving it relative to its current position.
   \param    vt_client  VTClient data structure
   \param    vt         VT to interact with
   \param    callback   Callback when message is sent
   \param    object_id  Object ID of the Graphics Context object to modify
   \param    x_offset   Cursor X offset
   \param    y_offset   Cursor Y offset
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t GraphicsContext_MoveGraphicsCursor_Command(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T object_id, Pixel_T x_offset, Pixel_T y_offset); // 184-1
/******************************************************************************/
//! F.56  Graphics Context command  (Set Foreground Colour)
/******************************************************************************/
/*!
   \brief    Modifies the foreground colour attribute (cursor not moved)
   \details  This command modifies the foreground colour attribute.  The
             graphics cursor is not moved.
   \param    vt_client  VTClient data structure
   \param    vt         VT to interact with
   \param    callback   Callback when message is sent
   \param    object_id  Object ID of the Graphics Context object to modify
   \param    colour     New Foreground Colour
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t GraphicsContext_SetForegroundColour_Command(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T object_id, Colour_T colour); // 184-2
/******************************************************************************/
//! F.56  Graphics Context command  (Set Background Colour)
/******************************************************************************/
/*!
   \brief    Modifies the background colour attribute (cursor not moved)
   \details  This command modifies the background colour attribute.  The
             graphics cursor is not moved.
   \param    vt_client  VTClient data structure
   \param    vt         VT to interact with
   \param    callback   Callback when message is sent
   \param    object_id  Object ID of the Graphics Context object to modify
   \param    colour     New Background Colour
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t GraphicsContext_SetBackgroundColour_Command(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T object_id, Colour_T colour); // 184-3
/******************************************************************************/
//! F.56  Graphics Context command  (Set Line Attributes Object ID)
/******************************************************************************/
/*!
   \brief    Modifies the Line Attribute (cursor not moved)
   \details  This command modifies the Line object attribute.  All drawing
             commands that follow use the new attribute value.  For line
             suppression, set the object ID to NULL Object ID.  The graphics
             cursor is not moved.
   \param    vt_client        VTClient data structure
   \param    vt               VT to interact with
   \param    callback         Callback when message is sent
   \param    object_id        Object ID of the Graphics Context object to modify
   \param    line_attributes  New Line Attributes
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t GraphicsContext_SetLineAttributes_Command(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T object_id, ObjectID_T line_attributes); // 184-4
/******************************************************************************/
//! F.56  Graphics Context command  (Set Fill Attributes Object ID)
/******************************************************************************/
/*!
   \brief    Modifies the Fill Attribute (cursor not moved)
   \details  This command modifies the fill object attribute.  All drawing
             commands that follow use the new attribute value.  For no filling,
             set the object ID to NULL Object ID.  The graphics cursor is not
             moved.
   \param    vt_client        VTClient data structure
   \param    vt               VT to interact with
   \param    callback         Callback when message is sent
   \param    object_id        Object ID of the Graphics Context object to modify
   \param    fill_attributes  New Fill Attributes
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t GraphicsContext_SetFillAttributes_Command(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T object_id, ObjectID_T fill_attributes); // 184-5
/******************************************************************************/
//! F.56  Graphics Context command  (Set Font Attributes Object ID)
/******************************************************************************/
/*!
   \brief    Modifies the Font Attribute (cursor not moved)
   \details  This command modifies the font object attribute.  All drawing
             commands that follow use the new attribute value.  If text is not
             being used, the object can be set to NULL Object ID.  The graphics
             cursor is not moved.
   \param    vt_client        VTClient data structure
   \param    vt               VT to interact with
   \param    callback         Callback when message is sent
   \param    object_id        Object ID of the Graphics Context object to modify
   \param    font_attributes  New Font Attributes
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t GraphicsContext_SetFontAttributes_Command(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T object_id, ObjectID_T font_attributes); // 184-6
/******************************************************************************/
//! F.56  Graphics Context command  (Erase Rectangle)
/******************************************************************************/
/*!
   \brief    Fill rectangle with background color (Cursor moved to bottom right)
   \details  Fills the rectangle at the graphics cursor using the current
             background colour.  For this command, the Fill Attributes Object is
             not used regardless of the state of Options bit 1.  The graphics
             cursor is moved to the bottom right pixel of the rectangle.
   \param    vt_client  VTClient data structure
   \param    vt         VT to interact with
   \param    callback   Callback when message is sent
   \param    object_id  Object ID of the Graphics Context object to modify
   \param    width      Rectangle width
   \param    height     Rectangle height
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t GraphicsContext_EraseRectangle_Command(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T object_id, Pixel_T width, Pixel_T height); // 184-7
/******************************************************************************/
//! F.56  Graphics Context command  (Draw Point)
/******************************************************************************/
/*!
   \brief    Sets pixel to foreground colour (moves cursor to point)
   \details  Sets the pixel to the foreground colour.  The graphics cursor is
             moved to the defined point.
   \param    vt_client  VTClient data structure
   \param    vt         VT to interact with
   \param    callback   Callback when message is sent
   \param    object_id  Object ID of the Graphics Context object to modify
   \param    x_offset   Relative x location
   \param    y_offset   Relative y location
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t GraphicsContext_DrawPoint_Command(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T object_id, Pixel_T x_offset, Pixel_T y_offset); // 184-8
/******************************************************************************/
//! F.56  Graphics Context command  (Draw Line)
/******************************************************************************/
/*!
   \brief    Draws line from cursor to point (moves cursor to end point)
   \details  Draws a line from the graphics cursor to the specified end pixels
             using the foreground colour.  The Line Object drawing rules apply
             with respect to the end pixel location and Line Attributes.  The
             graphics cursor is moved to the specified end pixel.
   \param    vt_client  VTClient data structure
   \param    vt         VT to interact with
   \param    callback   Callback when message is sent
   \param    object_id  Object ID of the Graphics Context object to modify
   \param    x_offset   Relative x location
   \param    y_offset   Relative y location
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t GraphicsContext_DrawLine_Command(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T object_id, Pixel_T x_offset, Pixel_T y_offset); // 184-9
/******************************************************************************/
//! F.56  Graphics Context command  (Draw Rectangle)
/******************************************************************************/
/*!
   \brief    Draws rectangle using line/fill attributes (Cursor moved to bottom right)
   \details  Draws a rectangle at the graphics cursor.  The Rectangle Object
             drawing rules apply.  If a Line Attributes object is currently
             defined, the border is drawn.  If a fill attribute object is
             currently defined, the rectangle is filled.  The graphics cursor is
             moved tothe bottom right pixel of the rectangle.
   \param    vt_client  VTClient data structure
   \param    vt         VT to interact with
   \param    callback   Callback when message is sent
   \param    object_id  Object ID of the Graphics Context object to modify
   \param    width      Rectangle width
   \param    height     Rectangle height
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t GraphicsContext_DrawRectangle_Command(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T object_id, Pixel_T width, Pixel_T height); // 184-10
/******************************************************************************/
//! F.56  Graphics Context command  (Draw Closed Ellipse)
/******************************************************************************/
/*!
   \brief    Draws closed ellipse using line/fill attributes (Cursor moved to bottom right)
   \details  Draws a closed ellipse bounded by the rectangle defined by the
             current graphics cursor location and the width and height given.
             The Ellipse Object drawing rules apply.  If a Line Attributes
             object is currently defined, the border is drawn.  If a fill
             attribute object is currently defined, the ellipse is filled.  The
             graphics cursor is moved to the bottom right pixel of the bounding
             rectangle.
   \param    vt_client  VTClient data structure
   \param    vt         VT to interact with
   \param    callback   Callback when message is sent
   \param    object_id  Object ID of the Graphics Context object to modify
   \param    width      Ellipse width
   \param    height     Ellipse height
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t GraphicsContext_DrawClosedEllipse_Command(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T object_id, Pixel_T width, Pixel_T height); // 184-11
/******************************************************************************/
//! F.56  Graphics Context command  (Draw Polygon)
/******************************************************************************/
/*!
   \brief    Draws a polygon using line/fill attributes (Cursor moved to last point)
   \details  Draws a polygon from the graphics cursor to the first point, then
             to the second point, and so on.  The polygon is closed if the last
             point has the offset 0,0.  This is because offset 0,0 gives the
             coordinates of the original graphics cursor which was used as the
             first point in the polygon.  If the data does not close the
             polygon, no automatic closing is performed and filling is ignored.
             Foreground colour is used for the border colour.  The Polygon
             Object drawing rules apply.  If a Line Attributes object is
             currently defined, the border is drawn.  If a fill object is
             currently defined and the polygon is closed, the polygon is filled.
             The graphics cursor is moved to the last point in the list.
   \param    vt_client  VTClient data structure
   \param    vt         VT to interact with
   \param    callback   Callback when message is sent
   \param    object_id  Object ID of the Graphics Context object to modify
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t GraphicsContext_DrawPolygon_Command(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T object_id); // 184-12
/******************************************************************************/
//! F.56  Graphics Context command  (Draw Text)
/******************************************************************************/
/*!
   \brief    Draws text using Font Attributes (Cursor moved to bottom right)
   \details  Draws the given text using the Font Attributes object.  Any
             flashing bits in the Font Style of the Font Attributes object are
             ignored.  If opaque, the background colour attribute is used.  The
             graphics cursor is moved to the bottom right corner of the extent
             of the text.
   \param    vt_client  VTClient data structure
   \param    vt         VT to interact with
   \param    callback   Callback when message is sent
   \param    object_id  Object ID of the Graphics Context object to modify
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t GraphicsContext_DrawText_Command(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T object_id); // 184-13
/******************************************************************************/
//! F.56  Graphics Context command  (Pan Viewport)
/******************************************************************************/
/*!
   \brief    Modifies viewport location (Cursor not moved)
   \details  This command modifies the viewport X and Y attributes and forces a
             redraw of the object, allowing "panning" of the underlying object
             contents.  The graphics cursor is not moved.
   \param    vt_client   VTClient data structure
   \param    vt          VT to interact with
   \param    callback    Callback when message is sent
   \param    object_id   Object ID of the Graphics Context object to modify
   \param    viewport_x  Relative x location
   \param    viewport_y  Relative y location
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t GraphicsContext_PanViewport_Command(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T object_id, Pixel_T viewport_x, Pixel_T viewport_y); // 184-14
/******************************************************************************/
//! F.56  Graphics Context command  (Zoom Viewport)
/******************************************************************************/
/*!
   \brief    Modifies viewport magnification (Cursor not moved)
   \details  This command allows magnification of the viewport contents.  See
             section on zooming for meaning of the zoom value.  The graphics
             cursor is not moved.
   \param    vt_client  VTClient data structure
   \param    vt         VT to interact with
   \param    callback   Callback when message is sent
   \param    object_id  Object ID of the Graphics Context object to modify
   \param    zoom       Magnification
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t GraphicsContext_ZoomViewport_Command(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T object_id, GraphicsZoom_T zoom); // 184-15
/******************************************************************************/
//! F.56  Graphics Context command  (Pan and Zoom Viewport)
/******************************************************************************/
/*!
   \brief    Modifies viewport location and magnification (Cursor not moved)
   \details  This command allows both panning and zooming at the same time
             combining commands 14 and 15.
   \param    vt_client   VTClient data structure
   \param    vt          VT to interact with
   \param    callback    Callback when message is sent
   \param    object_id   Object ID of the Graphics Context object to modify
   \param    viewport_x  Relative x location
   \param    viewport_y  Relative y location
   \param    zoom        Magnification
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t GraphicsContext_PanAndZoomViewport_Command(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T object_id, Pixel_T viewport_x, Pixel_T viewport_y, GraphicsZoom_T zoom); // 184-16
/******************************************************************************/
//! F.56  Graphics Context command  (Change Viewport Size)
/******************************************************************************/
/*!
   \brief    Changes the size of the viewport (Cursor not moved)
   \details  This command changes the size of the viewport and can be compared
             to the normal Change Size command.
   \note     The size of the object (i.e. the memory used) cannot be changed.
             The graphics cursor is not moved.
   \param    vt_client  VTClient data structure
   \param    vt         VT to interact with
   \param    callback   Callback when message is sent
   \param    object_id  Object ID of the Graphics Context object to modify
   \param    width      Viewport width
   \param    height     Viewport height
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t GraphicsContext_ChangeViewportSize_Command(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T object_id, Pixel_T width, Pixel_T height); // 184-17
/******************************************************************************/
//! F.56  Graphics Context command  (Draw VT Object)
/******************************************************************************/
/*!
   \brief    Draws arbitrary object (Cursor moved to bottom right)
   \details  This command draws the VT Object specified by the Object ID in
             Bytes 5-6 at the current graphics cursor location (top left corner).
             Any drawable object may be specified with the exception of the
             Graphics Context object specified in Bytes 2-3 or any object that
             contains this Graphics Context object (circular references are not
             allowed).  The object shall be drawn using the current value and
             state of that object at the time the command was specified (for
             instance, enabled or disabled), except flashing bitmaps which are
             drawn regardless of their flashing state.  A focus indicator,
             however, shall not be drawn even if the specified object (or any
             child object) has focus at that time.  Also, if the object is being
             edited by the operator, it shall be drawn as if it is not being
             edited, using the last accepted value of the object (not a
             temporary value that the operator is still entering).  The graphics
             cursor is moved to the bottom right corner of the object that was
             drawn.  Normal VT Object transparency rules apply when drawing the
             VT Object onto the canvas.  Any colours outside the colours allowed
             by this Graphics Context Object (see Table B.41) shall be treated
             as transparent.
   \param    vt_client       VTClient data structure
   \param    vt              VT to interact with
   \param    callback        Callback when message is sent
   \param    object_id       Object ID of the Graphics Context object to modify
   \param    object_to_draw  Object ID of the object to draw
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t GraphicsContext_DrawVtObject_Command(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T object_id, ObjectID_T object_to_draw); // 184-18
/******************************************************************************/
//! F.56  Graphics Context command  (Copy Canvas to Picture Graphic)
/******************************************************************************/
/*!
   \brief    Copies Canvas to Picture Graphic object (Cursor not moved)
   \details  This command copies the current canvas of the Graphics Context
             Object into the Picture Graphic Object specified by the Object ID
             in bytes 5-6.  If the Picture Graphic is smaller than the canvas,
             then it shall be clipped to fit within the Picture Graphic.  If the
             Picture Graphic is larger than the canvas, then the extra pixels in
             the Picture Graphic are not changed.  Colours in the Canvas that
             are set to the transparency colour in the Graphics Context Object
             are not copied and the corresponding pixels in the Picture Graphic
             are not changed.  The picture graphic shall have at least the same
             number of colours as the Graphics Context Object.  Any colours
             outside the colours allowed by this Picture Graphic Object (see
             Table B.41) shall be treated as transparent.
   \param    vt_client        VTClient data structure
   \param    vt               VT to interact with
   \param    callback         Callback when message is sent
   \param    object_id        Object ID of the Graphics Context object to modify
   \param    picture_graphic  Object in which to store copy of canvas
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t GraphicsContext_CopyCanvasToPictureGraphic_Command(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T object_id, ObjectID_T picture_graphic); // 184-19
/******************************************************************************/
//! F.56  Graphics Context command  (Copy Viewport to Picture Graphic)
/******************************************************************************/
/*!
   \brief    Copies Viewport to Picture Graphic object (Cursor not moved)
   \details  This command copies the current Viewport (zoomed or panned) of the
             Graphics Context Object into the Picture Graphic Object specified
             by the Object ID in bytes 5-6.  If the Picture Graphic is smaller
             than the Viewport, then it shall be clipped to fit within the
             Picture Graphic.  If the Picture Graphic is larger than the
             Viewport, then the extra pixels in the Picture Graphic are not
             changed.  Colours in the Viewport that are set to the transparency
             colour in the Graphics Context Object are not copied and the
             corresponding pixels in the Picture Graphic are not changed.  The
             picture graphic shall have at least the same number of colours as
             the Graphics Context Object.  Any colours outside the colours
             allowed by this Picture Graphic Object (see Table B.41) shall be
             treated as transparent.
   \param    vt_client        VTClient data structure
   \param    vt               VT to interact with
   \param    callback         Callback when message is sent
   \param    object_id        Object ID of the Graphics Context object to modify
   \param    picture_graphic  Object in which to store copy of canvas
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t GraphicsContext_CopyViewportToPictureGraphic_Command(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T object_id, ObjectID_T picture_graphic); // 184-20
/******************************************************************************/
//! F.58  Get Attribute Value message
/******************************************************************************/
/*!
   \brief    Function sends Vt Command(185) GET ATTRIBUTE VALUE to the VT.
   \details  Sends a destination specific GET ATTRIBUTE VALUE command to the VT.
             If a callback is provided, it will be called when the VT reply is received.
   \param    vt_client     pointer to the application's VTClient data structure
   \param    vt            pointer to the application's active data structure
   \param    callback      Callback when message is sent
   \param    object_id     Object ID
   \param    attribute_id  Attribute ID of the Object
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t GetAttributeValue_Message(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T object_id, AttributeID_T attribute_id);
/******************************************************************************/
//! F.60  Select Colour Map command
/******************************************************************************/
/*!
   \brief    Function sends Vt Command(186) SELECT COLOUR MAP to the VT.
   \details  Sends a destination specific SELECT COLOUR MAP command to the VT. If
             a callback is provided, it will be called when the VT reply is received.
   \param    vt_client  pointer to the application's VTClient data structure
   \param    vt         pointer to the application's active data structure
   \param    callback   Callback when message is sent
   \param    object_id  Object ID of the Colour Map object, or NULL_OBJECT_ID to restore
                        the default color table
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t SelectColourMap_Command(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T object_id);
/******************************************************************************/
//! F.62  Identify VT message
/******************************************************************************/
/*!
   \brief    Function sends Vt Command(187) IDENTIFY VT to the VT.
   \details  Sends a destination specific IDENTIFY VT command to the VT. If a
             callback is provided, it will be called when the VT reply is received.
   \param    vt_client  pointer to the application's VTClient data structure
   \param    vt         pointer to the application's active data structure
   \param    callback   Callback when message is sent
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t IdentifyVt_Message(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback);
/******************************************************************************/
// Annex G  Status Messages
/******************************************************************************/
/******************************************************************************/
// Annex H  Activation messages
/******************************************************************************/
/******************************************************************************/
//! H.3  Soft Key Activation response  (optional)
/******************************************************************************/
/*!
   \brief    Sends optional response to Soft Key Activation message
   \details  Optionally, in response to Soft Key Activation message
   \param    vt_client         pointer to the application's VTClient data structure
   \param    vt                pointer to the application's active data structure
   \param    callback          Callback when message is sent
   \param    message_contents  Contents of received message
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t SoftKeyActivation_Response(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, const SoftKeyActivation_T *message_contents);
/******************************************************************************/
//! H.5  Button Activation response  (optional)
/******************************************************************************/
/*!
   \brief    Sends optional response to Button Activation message
   \details  Optionally, in response to Button Activation message
   \param    vt_client         pointer to the application's VTClient data structure
   \param    vt                pointer to the application's active data structure
   \param    callback          Callback when message is sent
   \param    message_contents  Contents of received message
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t ButtonActivation_Response(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, const ButtonActivation_T *message_contents);
/******************************************************************************/
//! H.7  Pointing Event response  (optional)
/******************************************************************************/
/*!
   \brief    Sends optional response to Pointing Event message
   \details  Optionally, in response to Pointing Event message
   \param    vt_client         pointer to the application's VTClient data structure
   \param    vt                pointer to the application's active data structure
   \param    callback          Callback when message is sent
   \param    message_contents  Contents of received message
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t PointingEvent_Response(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, const PointingEvent_T *message_contents);
/******************************************************************************/
//! H.9  VT Select Input Object response  (optional)
/******************************************************************************/
/*!
   \brief    Sends optional response to VT Select Input Object message
   \details  The ECU uses this message to optionally respond to the VT Select
             Input Object message
   \param    vt_client         pointer to the application's VTClient data structure
   \param    vt                pointer to the application's active data structure
   \param    callback          Callback when message is sent
   \param    message_contents  Contents of received message
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t VtSelectInputObject_Response(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, const VtSelectInputObject_T *message_contents);
/******************************************************************************/
//! H.11  VT ESC response (optional)
/******************************************************************************/
/*!
   \brief    Sends optional response to VT ESC message
   \details  The ECU uses this message to optionally respond to the VT ESC
             message.
   \param    vt_client         pointer to the application's VTClient data structure
   \param    vt                pointer to the application's active data structure
   \param    callback          Callback when message is sent
   \param    message_contents  Contents of received message
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t VtEsc_Response(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, const VtEsc_T *message_contents);
/******************************************************************************/
//! H.13  VT Change Numeric Value response (optional)
/******************************************************************************/
/*!
   \brief    Sends optional response to VT Change Numeric Value message
   \details  The ECU uses this message to optionally respond to the VT Change
             Numeric Value message.
   \param    vt_client         pointer to the application's VTClient data structure
   \param    vt                pointer to the application's active data structure
   \param    callback          Callback when message is sent
   \param    message_contents  Contents of received message
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t VtChangeNumericValue_Response(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, const VtChangeNumericValue_T *message_contents);
/******************************************************************************/
//! H.15  VT Change Active Mask response (optional)
/******************************************************************************/
/*!
   \brief    Sends optional response to VT Change Active Mask message
   \details  The ECU uses this message to optionally respond to the VT Change
             Active Mask message.
   \param    vt_client         pointer to the application's VTClient data structure
   \param    vt                pointer to the application's active data structure
   \param    callback          Callback when message is sent
   \param    message_contents  Contents of received message
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t VtChangeActiveMask_Response(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, const VtChangeActiveMask_T *message_contents);
/******************************************************************************/
//! H.17  VT Change Soft Key Mask response (optional)
/******************************************************************************/
/*!
   \brief    Sends optional response to VT Change Soft Key Mask message
   \details  The ECU uses this message to optionally respond to the VT Change
             Soft Key Mask message.
   \param    vt_client         pointer to the application's VTClient data structure
   \param    vt                pointer to the application's active data structure
   \param    callback          Callback when message is sent
   \param    message_contents  Contents of received message
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t VtChangeSoftKeyMask_Response(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, const VtChangeSoftKeyMask_T *message_contents);
/******************************************************************************/
//! H.19  VT Change String Value response (optional)
/******************************************************************************/
/*!
   \brief    Sends optional response to VT Change String Value message
   \details  The ECU uses this message to optionally respond to the VT Change
             String Value message.
   \param    vt_client         pointer to the application's VTClient data structure
   \param    vt                pointer to the application's active data structure
   \param    callback          Callback when message is sent
   \param    message_contents  Contents of received message
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t VtChangeStringValue_Response(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, const VtChangeStringValue_T *message_contents);
/******************************************************************************/
//! H.21  VT On User-Layout Hide/Show response (mandatory)
/******************************************************************************/
/*!
   \brief    Send VT On User-Layout Hide/Show response
   \details  This message applies to Version 4 and later VTs. It is an exception
             to the other responses specified in this annex in that it is not
             optional but mandatory: it shall always be sent in response to a VT
             On User-Layout Hide/Show message.
   \param    vt_client         pointer to the application's VTClient data structure
   \param    vt                pointer to the application's active data structure
   \param    callback          Callback when message is sent
   \param    message_contents  Contents of received message
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t VtOnUserLayoutHideShow_Response(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, const VtOnUserLayoutHideShow_T *message_contents);
/******************************************************************************/
// Annex J  Auxiliary Control
/******************************************************************************/
//! J.7.6  Auxiliary Assignment Type 2 response  (Aux Function)
extern bool_t AuxiliaryAssignmentType2_Response(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, const AuxiliaryAssignmentType2_T *message_contents, AuxiliaryAssignmentType2_Error_T errors);
//! J.7.9  Auxiliary Input Type 2 Status message  (Aux Input)
extern bool_t AuxiliaryInputType2Status_Message(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, const ObjectID_T aux_input, AuxInputValue_T value_1, AuxInputValue_T value_2, AuxInputOperatingState_T operating_state);
//! J.7.10  Auxiliary Input Type 2 Maintenance message  (Aux Input)
extern bool_t AuxiliaryInputType2Maintenance_Message(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ModelIdentificationCode_T model_id, AuxInputStatus_T status);
//! J.7.12  Auxiliary Input Status Type 2 Enable response  (Aux Input)
extern bool_t AuxiliaryInputStatusType2Enable_Response(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, const AuxiliaryInputStatusType2Enable_Command_T *message_contents, AuxiliaryInputStatusType2_Error_T errors);
/******************************************************************************/
// F.14  Change Child Location command (Scaled)
/******************************************************************************/
/*!
   \brief    Wrapper function for ChangeChildLocation_Command.
   \details  Determines the type of scaling to be used for the object pool part and
             calls ChangeChildLocation_Command with the appropriate X and Y values.
   \param    vt_client            Pointer to the application's VTClient data structure
   \param    vt                   Pointer to the application's active data structure
   \param    callback             Callback when message is sent
   \param    parent_obj_id        Parent Object ID
   \param    child_obj_id         Object ID of object to move
   \param    change_x_position    Relative change in X position
   \param    change_y_position    Relative change in Y position
   \param    scaling_type         Indicates how to scale this object pool part
   \return   bool_t
   \retval   TRUE if ChangeChildLocation_Command_Scaled was successful
   \retval   FALSE if ChangeChildLocation_Command_Scaled was not successful
*/
/******************************************************************************/
extern bool_t ChangeChildLocation_Command_Scaled(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T parent_obj_id, ObjectID_T child_obj_id, Pixel_T change_x_position, Pixel_T change_y_position, ObjectPool_ScaleFactor_T scaling_type);
/******************************************************************************/
// F.16  Change Child Position command (Scaled)
/******************************************************************************/
/*!
   \brief    Wrapper function for ChangeChildPosition_Command.
   \details  Determines the type of scaling to be used for the object pool part and
             calls ChangeChildPosition_Command with the appropriate X and Y values.
   \param    vt_client          Pointer to the application's VTClient data structure
   \param    vt                 Pointer to the application's active data structure
   \param    callback           Callback when message is sent
   \param    parent_obj_id      Parent Object ID
   \param    object_id          Object ID of object to move
   \param    new_x_position     New X position relative to the top left corner of
                                parent object
   \param    new_y_position     New Y position relative to the top left corner of
                                parent object
   \param    scaling_type       Indicates how to scale this object pool part
   \return   bool_t
   \retval   TRUE if ChangeChildPosition_Command_Scaled was successful
   \retval   FALSE if ChangeChildPosition_Command_Scaled was not successful
*/
/******************************************************************************/
extern bool_t ChangeChildPosition_Command_Scaled(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_MessageCallback_T *callback, ObjectID_T parent_obj_id, ObjectID_T object_id, Pixel_T new_x_position, Pixel_T new_y_position, ObjectPool_ScaleFactor_T scaling_type);
/******************************************************************************/
// F.18  Change Size command (Scaled)
/******************************************************************************/
/*!
   \brief    Wrapper function for ChangeSize_Command.
   \details  Determines the type of scaling to be used for changing an object pool
             part size and calls ChangeSize_Command with the appropriate width and
             height values.
   \param    vt_client        Pointer to the application's VTClient data structure
   \param    vt               Pointer to the application's active data structure
   \param    callback         Callback when message is sent
   \param    object_id        Object ID of the object to change size
   \param    new_width        New width
   \param    new_height       New height
   \param    scaling_type     Indicates how to scale this object pool part
   \return   bool_t
   \retval   TRUE if ChangeSize_Command_Scaled was successful
   \retval   FALSE if ChangeSize_Command_Scaled was not successful
*/
/******************************************************************************/
extern bool_t ChangeSize_Command_Scaled(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T object_id, Pixel_T new_width, Pixel_T new_height, ObjectPool_ScaleFactor_T scaling_type);
/******************************************************************************/
// F.26  Change End Point command (Scaled)
/******************************************************************************/
/*!
   \brief    Wrapper function for ChangeEndPoint_Command.
   \details  Determines the type of scaling to be used for changing a line endpoint
             and calls ChangeEndPoint_Command with the appropriate width and height
             values.
   \param    vt_client       Pointer to the application's VTClient data structure
   \param    vt              Pointer to the application's active data structure
   \param    callback        Callback when message is sent
   \param    object_id       Object ID of a Line object to change
   \param    width           Width in pixels
   \param    height          Height in pixels
   \param    direction       Line Direction (refer to Line object attributes)
   \param    scaling_type    Indicates how to scale this object pool part
   \return   bool_t
   \retval   TRUE if ChangeEndPoint_Command_Scaled was successful
   \retval   FALSE if ChangeEndPoint_Command_Scaled was not successful
*/
/******************************************************************************/
extern bool_t ChangeEndPoint_Command_Scaled(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T object_id, Pixel_T width, Pixel_T height, LineDirection_T direction, ObjectPool_ScaleFactor_T scaling_type);
/******************************************************************************/
// F.30  Change Line Attributes command (Scaled)
/******************************************************************************/
/*!
   \brief    Wrapper function for ChangeLineAttributes_Command.
   \details  Determines the type of scaling to be used for changing line attributes
             and calls ChangeFontAttributes_Command with the appropriate size value.
   \param    vt_client     Pointer to the application's VTClient data structure
   \param    vt            Pointer to the application's active data structure
   \param    callback      Callback when message is sent
   \param    object_id     Object ID of object to change
   \param    color         Line Colour
   \param    width         Line Width
   \param    line_art      Line Art
   \param    scaling_type  Indicates how to scale this object pool part
   \return   bool_t
   \retval   TRUE if ChangeLineAttributes_Command_Scaled was successful
   \retval   FALSE if ChangeLinteAttributes_Command_Scaled was not successful
*/
/******************************************************************************/
extern bool_t ChangeLineAttributes_Command_Scaled(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T object_id, Colour_T color, Pixel_T width, LineArt_T line_art, ObjectPool_ScaleFactor_T scaling_type);
/******************************************************************************/
// F.52  Change Polygon Point command (Scaled)
/******************************************************************************/
/*!
   \brief    Wrapper function for ChangePolygonPoint_Command.
   \details  Determines the type of scaling to be used when changing the start
             point of a polygon and calls ChangePolygonPoint_Command with the
             appropriate (x,y) values.
   \param    vt_client       Pointer to the application's VTClient data structure
   \param    vt              Pointer to the application's active data structure
   \param    callback        Callback when message is sent
   \param    object_id       Object ID of the Polygon object to change
   \param    point_index     Point index of the point to replace
   \param    new_x_value     New X value of a point relative to the top left corner
                             of the polygon
   \param    new_y_value     New Y value of a point relative to the top left corner
                             of the polygon
   \param    scaling_type    Indicates how to scale this object pool part
   \return   bool_t
   \retval   TRUE if ChangePolygonPoint_Command_Scaled was successful
   \retval   FALSE if ChangePolygonPoint_Command_Scaled was not successful
*/
/******************************************************************************/
extern bool_t ChangePolygonPoint_Command_Scaled(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T object_id, PolygonPointIndex_T point_index, Pixel_T new_x_value, Pixel_T new_y_value, ObjectPool_ScaleFactor_T scaling_type);
/******************************************************************************/
// F.54  Change Polygon Scale command (Scaled)
/******************************************************************************/
/*!
   \brief    Wrapper function for ChangePolygonScale_Command.
   \details  Determines the type of scaling to be used when changing the scale
             of a polygon and calls ChangePolygonScale_Command with the
             appropriate width and height values.
   \param    vt_client       Pointer to the application's VTClient data structure
   \param    vt              Pointer to the application's active data structure
   \param    callback        Callback when message is sent
   \param    object_id       Object ID of a Polygon object to scale
   \param    new_width       New width attribute
   \param    new_height      New height attribute
   \param    scaling_type    Indicates how to scale this object pool part
   \return   bool_t
   \retval   TRUE if ChangePolygonScale_Command_Scaled was successful
   \retval   FALSE if ChangePolygonScale_Command_Scaled was not successful
*/
/******************************************************************************/
extern bool_t ChangePolygonScale_Command_Scaled(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T object_id, Pixel_T new_width, Pixel_T new_height, ObjectPool_ScaleFactor_T scaling_type);
/******************************************************************************/
//! F.56  Graphics Context command  (Zoom Viewport) (Scaled)
/******************************************************************************/
/*!
   \brief    Modifies viewport magnification (Cursor not moved)
   \details  Determines the type of scaling to be used when zooming the
             viewport and calls GraphicsContext_PanAndZoomViewport_Command with the
             appropriate zoom value.
   \param    vt_client       VTClient data structure
   \param    vt              VT to interact with
   \param    callback        Callback when message is sent
   \param    object_id       Object ID of the Graphics Context object to modify
   \param    zoom            Magnification
   \param    scaling_type    Indicates how to scale this object pool part
   \return   bool_t
   \retval   TRUE if the message was queued to be sent
   \retval   FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t GraphicsContext_ZoomViewport_Command_Scaled(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T object_id, GraphicsZoom_T zoom, ObjectPool_ScaleFactor_T scaling_type);
/******************************************************************************/
// F.56 Subcommand 16:  Pan and Zoom Viewport (Scaled)
/******************************************************************************/
/*!
   \brief    Wrapper function for GraphicsContext_PanAndZoomViewport_Command.
   \details  Determines the type of scaling to be used when panning and zooming the
             viewport and calls GraphicsContext_PanAndZoomViewport_Command with the
             appropriate zoom value.
   \param    vt_client       VTClient data structure
   \param    vt              VT to interact with
   \param    callback        Callback when message is sent
   \param    object_id       Object ID of the Graphics Context object to modify
   \param    viewport_x      Relative x location
   \param    viewport_y      Relative y location
   \param    zoom            Magnification
   \param    scaling_type    Indicates how to scale this object pool part
   \return   bool_t
   \retval   TRUE if GraphicsContext_PanAndZoomViewport_Command_Scaled was successful
   \retval   FALSE if GraphicsContext_PanAndZoomViewport_Command_Scaled was not successful
*/
/******************************************************************************/
extern bool_t GraphicsContext_PanAndZoomViewport_Command_Scaled(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T object_id, Pixel_T viewport_x, Pixel_T viewport_y, GraphicsZoom_T zoom, ObjectPool_ScaleFactor_T scaling_type);
/******************************************************************************/
// F.56 Subcommand 17:  Change Viewport Size (Scaled)
/******************************************************************************/
/*!
   \brief    Wrapper function for GraphicsContext_ChangeViewportSize_Command.
   \details  Determines the type of scaling to be used when changing the viewport
             size and calls GraphicsContext_ChangeViewportSize_Command with the
             appropriate width and height values.
   \param    vt_client       VTClient data structure
   \param    vt              VT to interact with
   \param    callback        Callback when message is sent
   \param    object_id       Object ID of the Graphics Context object to modify
   \param    width           Width of the viewport
   \param    height          Height of the viewport
   \param    scaling_type    Indicates how to scale this object pool part
   \return   bool_t
   \retval   TRUE if GraphicsContext_ChangeViewportSize_Command_Scaled was successful
   \retval   FALSE if GraphicsContext_ChangeViewportSize_Command_Scaled was not successful
*/
/******************************************************************************/
extern bool_t GraphicsContext_ChangeViewportSize_Command_Scaled(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T object_id, Pixel_T width, Pixel_T height, ObjectPool_ScaleFactor_T scaling_type);
/******************************************************************************/
/*!
   \brief    Find active VT structure for given Name Table Index
   \details  Finds matching VT for given Name Table Index.
   \param    vt_client            [In]  VTClient structure containing all active VTs
   \param    vt_name_table_index  [in]  Name Table Index of VT
   \param    vt                   [Out] Pointer to VT_T pointer (populated if found)
   \return  bool_t
   \retval  TRUE   VT found (and **vt populated)
   \retval  FALSE  VT not found
*/
/******************************************************************************/
extern bool_t VT_FindVT(const VTClient_T *vt_client, const NameTableIndex_T vt_name_table_index, VT_T **vt);
/******************************************************************************/
/*!
   \brief    Find the next active VT on the bus
   \details  Finds the next active VT in the list
   \param    vt_client  [In]  VTClient structure containing all active VTs
   \param    vt         [Out] Pointer to VT_T pointer (populated if found)
   \return  bool_t
   \retval  TRUE   VT found (and **vt populated)
   \retval  FALSE  VT not found
*/
/******************************************************************************/
extern bool_t VT_NextVT(const VTClient_T *vt_client, VT_T **vt);
/******************************************************************************/
/*!
   \brief    Connect to the VT
   \details  Connects to a VT (start sending Working Set Maintenance)
   \param    vt_client    VTClient structure containing all active VTs
   \param    vt           VT to connect to
   \return  bool_t
   \retval  TRUE   Connection started
   \retval  FALSE  Connection not started
*/
/******************************************************************************/
extern bool_t VT_Connect(const VTClient_T *vt_client, VT_T *vt);
/******************************************************************************/
/*!
   \brief    Gracefully disconnect from the VT
   \details  Disconnects from a VT
   \param    vt_client    VTClient structure containing all active VTs
   \param    vt           VT to connect to
   \return  bool_t
   \retval  TRUE   Disonnection started
   \retval  FALSE  Disonnection not started
*/
/******************************************************************************/
extern bool_t VT_Disconnect(VTClient_T *vt_client, VT_T *vt);
/******************************************************************************/
/*!
   \brief    Send an object pool to the VT
   \details  Sends an object pool to the VT
   \param    vt_client    VTClient structure containing all active VTs
   \param    vt           VT to send object pool to
   \param    object_pool  Object Pool to send
   \return  bool_t
   \retval  TRUE   Connection started
   \retval  FALSE  Connection not started
*/
/******************************************************************************/
extern bool_t VT_SendObjectPool(const VTClient_T *vt_client, VT_T *vt, const ObjectPool_T *object_pool);
/******************************************************************************/
/*!
   \brief    Removes an object pool from the VT
   \details  Removes Object Pool from the VT's volatile memory
   \param    vt_client    VTClient structure containing all active VTs
   \param    vt           VT to connect to
   \return  bool_t
   \retval  TRUE   Disonnection started
   \retval  FALSE  Disonnection not started
*/
/******************************************************************************/
extern bool_t VT_DeleteObjectPool(VTClient_T *vt_client, VT_T *vt);
/******************************************************************************/
/*!
   \brief    Initializes the VTClient_T structure
   \details  Initializes VTClient_T structure
   \param    vt_client  VTClient structure containing all active VTs
*/
/******************************************************************************/
extern void VTClient_Init(VTClient_T *vt_client);
/******************************************************************************/
/*!
   \brief    Uninitializes the VTClient_T structure
   \details  Uninitializes VTClient_T structure
   \param    vt_client  VTClient structure containing all active VTs
*/
/******************************************************************************/
extern void VTClient_Uninit(VTClient_T *vt_client);
/******************************************************************************/
/*!
   \brief    Runs the VTClient tasks
   \param    vt_client  VTClient structure containing all active VTs
*/
/******************************************************************************/
extern void VTClient_Task(VTClient_T *vt_client);
/******************************************************************************/
/*!
//!\details Function for handling boolean inputs with 4 bits (left/right/down/up) to determine auxiliary input value.
//!         Supports the following auxiliary types:
//!
//!            * boolean latching (Aux Function Type ID 0)
//!            * boolean momentary (Aux Function Type ID 2)
//!            * dual boolean both latching (Aux Function Type ID 5)
//!            * dual boolean both nonlatching (Aux Function Type ID 6)
//!            * dual boolean latch up momentary down (Aux Function Type ID 7)
//!            * dual boolean latch down momentary up (Aux Function Type ID 8)
//!            * quadrature boolean non latching (Aux Function Type ID 11)
//!
//!\param   input    AuxiliaryInput_T to be updated
//!\param   left     Current left value
//!\param   right    Current right value
//!\param   down     Current backward value
//!\param   up       Current forward value
*/
/******************************************************************************/
extern void AuxInput_Boolean(AuxiliaryInput_T *input, AuxInputValue_T left, AuxInputValue_T right, AuxInputValue_T down, AuxInputValue_T up);
/******************************************************************************/
/*!
//!\details Function for scaling and handling an analog input of a given max with respect to 0xFAFF to determine auxiliary input value
//!         Supports the following auxiliary types:
//!
//!            * analog (Aux Function Type ID 1)
//!            * analog return to center (Aux Function Type ID 3)
//!            * analog return to zero (Aux Function Type ID 4)
//!            * combined analog return to center dual boolean latching (Aux Function Type ID 9)
//!            * combined analog dual boolean latching (Aux Function Type ID 10)
//!
//!\param   input    AuxiliaryInput_T to be updated
//!\param   value    The current analog value
*/
/******************************************************************************/
extern void AuxInput_Analog(AuxiliaryInput_T *input, AuxInputValue_T value);
/******************************************************************************/
/*!
//!\details Function for scaling and handling a quadrature analog input of a given max with respect to 0xFAFF to determine auxiliary input value
//!         Supports the following auxiliary types:
//!
//!            * quadrature analog (Aux Function Type ID 12)
//!            * quadrature analog return to center (Aux Function Type ID 13)
//!
//!\param   input    AuxiliaryInput_T to be updated
//!\param   value1   The current up/down quadrature analog value
//!\param   value2   The current left/right quadrature analog value
*/
/******************************************************************************/
extern void AuxInput_QuadratureAnalog(AuxiliaryInput_T *input, AuxInputValue_T value1, AuxInputValue_T value2);
/******************************************************************************/
/*!
//!\details Function for scaling and handling a bidirectional encoder input of a given max with respect to 0xFFFF to determine auxiliary input value
//!         Supports the following auxiliary types:
//!
//!            * bidirectional encoder (Aux Function Type ID 14)
//!
//!\param   input        AuxiliaryInput_T to be updated
//!\param   value        The current bidirectional encoder value
//!\param   rev_counts   Number of value counts per revolution
*/
/******************************************************************************/
extern void AuxInput_BidirectionalEncoder(AuxiliaryInput_T *input, AuxInputValue_T value, AuxInputValue_T rev_counts);
/******************************************************************************/
/*!
\details Register an user auxiliary function callback
\param   vt_client   Applicable VTClient structure
\param   object_id   Object ID of auxiliary function the callback is being registered with
\param   callback    Callback (statically located) to be assigned to the auxiliary function
\return  bool_t
\retval   TRUE   Callback successfully registered
\retval   FALSE  Callback registration failed
*/
/******************************************************************************/
extern bool_t AuxiliaryFunction_Callback_Register(const VTClient_T *vt_client, ObjectID_T object_id, const AuxiliaryFunction_Callback_T *callback);
/******************************************************************************/
/*!
\details Register an user preferred assignment data callback
\param   vt_client   Applicable VTClient structure
\param   callback    Callback (statically located) to be assigned to the auxiliary function working set
\return  bool_t
\retval   TRUE   Callback successfully registered
\retval   FALSE  Callback registration failed
*/
/******************************************************************************/
extern bool_t VTClient_PreferredAssignments_Updated_Callback_Register(const VTClient_T *vt_client, const PreferredAssignments_Updated_Callback_T *callback);
/******************************************************************************/
/*!
\brief    Gets the size of the Preferred_Assignment_T array
\details  Function to return the size of the Preferred_Assignment_T array, in bytes,
from the supplied object pool.
\param    vt_client   Applicable VTClient the Preferred_Assignment_T array is in
\return   Size_T
\retval   Size of the Preferred_Assignment_T array in bytes
*/
/******************************************************************************/
extern Size_T VTClient_PreferredAssignments_GetSize(const VTClient_T *vt_client);
/******************************************************************************/
/*!
\brief    Allows user to save the preferred assignments to non-volatile memory
\details  Places the Preferred_Assignment_T data into the supplied pipe to allow the
user to save the data in non-volatile memory.
\param    vt_client      Applicable VTClient to save the preferred assignments from
\param    write_handle   Pipe to allow user to pipe information to their non-volatile memory
\return   bool_t
\retval   TRUE if preferred assignments were successfully saved
\retval   FALSE if preferred assignments failed to save
*/
/******************************************************************************/
extern bool_t VTClient_PreferredAssignments_Get(const VTClient_T *vt_client, Pipe_WriteHandle_T write_handle);
/******************************************************************************/
/*!
\brief    Allows user to send, from non-volatile memory, preferred assignments to the library
\details  Places the Preferred_Assignment_T data into the supplied pipe to allow the
user to save the data in non-volatile memory.
\param    vt_client     Applicable VTClient to send the preferred assignments to
\param    read_handle   Pipe to allow user to pipe information from their non-volatile memory to the library
\return   bool_t
\retval   TRUE if preferred assignments were successfully sent
\retval   FALSE if preferred assignments failed to send
*/
/******************************************************************************/
extern bool_t VTClient_PreferredAssignments_Set(const VTClient_T *vt_client, Pipe_ReadHandle_T read_handle);
/******************************************************************************/
//! F.36  Change Soft Key Mask command (Data Mask)
/******************************************************************************/
/*!
   \brief    Datamask wrapper function for ChangeSoftKeyMask_Command.
   \details  Automatically applies the data mask parameter for the ChangeSoftKeyMask_Command.
   \param    vt_client        pointer to the application's VTClient data structure
   \param    vt               pointer to the application's active data structure
   \param    callback         Callback when message is sent
   \param    data_mask        Data Mask Object ID
   \param    soft_key_mask    Soft Key Mask Object ID
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t ChangeSoftKeyMask_DataMask(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T data_mask, ObjectID_T soft_key_mask);
/******************************************************************************/
//! F.36  Change Soft Key Mask command (Alarm Mask)
/******************************************************************************/
/*!
   \brief    Alarm mask wrapper function for ChangeSoftKeyMask_Command.
   \details  Automatically applies the alarm mask parameter for the ChangeSoftKeyMask_Command.
   \param    vt_client        pointer to the application's VTClient data structure
   \param    vt               pointer to the application's active data structure
   \param    callback         Callback when message is sent
   \param    alarm_mask       Alarm Mask Object ID
   \param    soft_key_mask    Soft Key Mask Object ID
   \return  bool_t
   \retval  TRUE if the message was queued to be sent
   \retval  FALSE if the message was not queued
*/
/******************************************************************************/
extern bool_t ChangeSoftKeyMask_AlarmMask(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T alarm_mask, ObjectID_T soft_key_mask);
/******************************************************************************/
// F.14  Change Child Location command (Data Mask)
/******************************************************************************/
/*!
   \brief    Datamask wrapper function for ChangeChildLocation_Command_Scaled.
   \details  Automatically applies datamask scaling for the ChangeChildLocation_Command.
   \param    vt_client            Pointer to the application's VTClient data structure
   \param    vt                   Pointer to the application's active data structure
   \param    callback             Callback when message is sent
   \param    parent_object_id     Parent Object ID
   \param    child_object_id      Object ID of object to move
   \param    change_x_position    Relative change in X position
   \param    change_y_position    Relative change in Y position
   \return   bool_t
   \retval   TRUE if ChangeChildLocation_Command_Scaled_DataMask was successful
   \retval   FALSE if ChangeChildLocation_Command_Scaled_DataMask was not successful
*/
/******************************************************************************/
extern bool_t ChangeChildLocation_Command_Scaled_DataMask(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T parent_object_id, ObjectID_T child_object_id, Pixel_T change_x_position, Pixel_T change_y_position);
/******************************************************************************/
// F.14  Change Child Location command (Soft Key Mask)
/******************************************************************************/
/*!
   \brief    Softkey mask wrapper function for ChangeChildLocation_Command_Scaled.
   \details  Automatically applies softkey mask scaling for the ChangeChildLocation_Command.
   \param    vt_client            Pointer to the application's VTClient data structure
   \param    vt                   Pointer to the application's active data structure
   \param    callback             Callback when message is sent
   \param    parent_object_id     Parent Object ID
   \param    child_object_id      Object ID of object to move
   \param    change_x_position    Relative change in X position
   \param    change_y_position    Relative change in Y position
   \return   bool_t
   \retval   TRUE if ChangeChildLocation_Command_Scaled_SoftKeyMask was successful
   \retval   FALSE if ChangeChildLocation_Command_Scaled_SoftKeyMask was not successful
*/
/******************************************************************************/
extern bool_t ChangeChildLocation_Command_Scaled_SoftKeyMask(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T parent_object_id, ObjectID_T child_object_id, Pixel_T change_x_position, Pixel_T change_y_position);
/******************************************************************************/
// F.16  Change Child Position command (Data Mask)
/******************************************************************************/
/*!
   \brief    Datamask wrapper function for ChangeChildPosition_Command_Scaled.
   \details  Automatically applies datamask scaling for the ChangeChildPosition_Command.
   \param    vt_client          Pointer to the application's VTClient data structure
   \param    vt                 Pointer to the application's active data structure
   \param    callback           Callback when message is sent
   \param    parent_object_id   Parent Object ID
   \param    child_object_id    Object ID of object to move
   \param    new_x_position     New X position relative to the top left corner of
                                parent object
   \param    new_y_position     New Y position relative to the top left corner of
                                parent object
   \return   bool_t
   \retval   TRUE if ChangeChildPosition_Command_Scaled_DataMask was successful
   \retval   FALSE if ChangeChildPosition_Command_Scaled_DataMask was not successful
*/
/******************************************************************************/
extern bool_t ChangeChildPosition_Command_Scaled_DataMask(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_MessageCallback_T *callback, ObjectID_T parent_object_id, ObjectID_T child_object_id, Pixel_T new_x_position, Pixel_T new_y_position);
/******************************************************************************/
// F.16  Change Child Position command (Soft Key Mask)
/******************************************************************************/
/*!
   \brief    Softkey mask wrapper function for ChangeChildPosition_Command_Scaled.
   \details  Automatically applies softkey mask scaling for the ChangeChildPosition_Command.
   \param    vt_client          Pointer to the application's VTClient data structure
   \param    vt                 Pointer to the application's active data structure
   \param    callback           Callback when message is sent
   \param    parent_object_id   Parent Object ID
   \param    child_object_id    Object ID of object to move
   \param    new_x_position     New X position relative to the top left corner of
                                parent object
   \param    new_y_position     New Y position relative to the top left corner of
                                parent object
   \return   bool_t
   \retval   TRUE if ChangeChildPosition_Command_Scaled_SoftKeyMask was successful
   \retval   FALSE if ChangeChildPosition_Command_Scaled_SoftKeyMask was not successful
*/
/******************************************************************************/
extern bool_t ChangeChildPosition_Command_Scaled_SoftKeyMask(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_MessageCallback_T *callback, ObjectID_T parent_object_id, ObjectID_T child_object_id, Pixel_T new_x_position, Pixel_T new_y_position);
/******************************************************************************/
// F.18  Change Size command (Data Mask)
/******************************************************************************/
/*!
   \brief    Datamask wrapper function for ChangeSize_Command_Scaled.
   \details  Automatically applies datamask scaling for the ChangeSize_Command.
   \param    vt_client        Pointer to the application's VTClient data structure
   \param    vt               Pointer to the application's active data structure
   \param    callback         Callback when message is sent
   \param    object_id        Object ID of the object to change size
   \param    new_width        New width
   \param    new_height       New height
   \return   bool_t
   \retval   TRUE if ChangeSize_Command_Scaled_DataMask was successful
   \retval   FALSE if ChangeSize_Command_Scaled_DataMask was not successful
*/
/******************************************************************************/
extern bool_t ChangeSize_Command_Scaled_DataMask(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T object_id, Pixel_T new_width, Pixel_T new_height);
/******************************************************************************/
// B.1 Working Set object
/******************************************************************************/
//! Type containing supported commands for a VTv4 Working Set object
typedef struct VTv4_WorkingSet_S
{
   //! Change Active Mask command
   bool_t (*ChangeActiveMask) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T working_set, ObjectID_T new_mask_id);
   //! Change Background Colour command
   bool_t (*ChangeBackgroundColour)(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T working_set, Colour_T background_colour);
   //! Change Child Location command (Relative Position)
   bool_t (*ChangeChildLocation) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T working_set, ObjectID_T child, Pixel_T change_x_position, Pixel_T change_y_position);
   //! Change Child Position command (Absolute Position)
   bool_t (*ChangeChildPosition) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_MessageCallback_T *callback, ObjectID_T working_set, ObjectID_T child, Pixel_T new_x_position, Pixel_T new_y_position);
   struct
   {
      //! Get Type attribute
      bool_t (*Type) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T working_set); // 0
      //! Get Background Colour attribute
      bool_t (*BackgroundColour) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T working_set); // 1
      //! Get Selectable attribute
      bool_t (*Selectable) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T working_set); // 2
      //! Get Active Mask attribute
      bool_t (*ActiveMask) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T working_set); // 3
   } GetAttributeValue; //!< Get Attribute Command
} VTv4_WorkingSet_T;
/******************************************************************************/
// B.2 Data Mask object
/******************************************************************************/
//! Type containing supported commands for a VTv4 Data Mask object
typedef struct VTv4_DataMask_S
{
   //! Change Background Colour command
   bool_t (*ChangeBackgroundColour)(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T data_mask, Colour_T background_colour);
   //! Change Child Location command (Relative Position)
   bool_t (*ChangeChildLocation) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T data_mask, ObjectID_T child, Pixel_T change_x_position, Pixel_T change_y_position);
   //! Change Child Position command (Absolute Position)
   bool_t (*ChangeChildPosition) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_MessageCallback_T *callback, ObjectID_T data_mask, ObjectID_T child, Pixel_T new_x_position, Pixel_T new_y_position);
   //! Change Soft Key Mask command
   bool_t (*ChangeSoftKeyMask) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T data_mask, ObjectID_T soft_key_mask);
   //! Lock Unlock Mask command
   bool_t (*LockUnlockMask) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, MaskCommand_T command, ObjectID_T object_id, Time_T timeout);
   struct
   {
      //! Change Background Colour attribute
      bool_t (*BackgroundColour) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T data_mask, Colour_T background_colour); // 1
      //! Change Soft Key Mask attribute
      bool_t (*SoftKeyMask) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T data_mask, ObjectID_T soft_key_mask); // 2
   } ChangeAttribute; //!< Change Attribute command
   struct
   {
      //! Get Type attribute
      bool_t (*Type) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T data_mask); // 0
      //! Get Background Colour attribute
      bool_t (*BackgroundColour) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T data_mask); // 1
      //! Get Soft Key Mask attribute
      bool_t (*SoftKeyMask) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T data_mask); // 2
   } GetAttributeValue; //!< Get Attribute Command
} VTv4_DataMask_T;
/******************************************************************************/
// B.3 Alarm Mask object
/******************************************************************************/
//! Type containing supported commands for a VTv4 Alarm Mask object
typedef struct VTv4_AlarmMask_S
{
   //! Change Background Colour command
   bool_t (*ChangeBackgroundColour)(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T alarm_mask, Colour_T background_colour);
   //! Change Child Location command (Relative Position)
   bool_t (*ChangeChildLocation) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T alarm_mask, ObjectID_T child, Pixel_T change_x_position, Pixel_T change_y_position);
   //! Change Child Position command (Absolute Position)
   bool_t (*ChangeChildPosition) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_MessageCallback_T *callback, ObjectID_T alarm_mask, ObjectID_T child, Pixel_T new_x_position, Pixel_T new_y_position);
   //! Change Priority command
   bool_t (*ChangePriority) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T alarm_mask, AlarmPriority_T priority);
   //! Change Soft Key Mask command
   bool_t (*ChangeSoftKeyMask) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T alarm_mask, ObjectID_T soft_key_mask);
   struct
   {
      //! Change Background Colour attribute
      bool_t (*BackgroundColour) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T alarm_mask, Colour_T background_colour); // 1
      //! Change Soft Key Mask attribute
      bool_t (*SoftKeyMask) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T alarm_mask, ObjectID_T soft_key_mask); // 2
      //! Change Priority attribute
      bool_t (*Priority) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T alarm_mask, AlarmPriority_T priority); // 3
      //! Change Acoustic Signal attribute
      bool_t (*AcousticSignal) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T alarm_mask, AcousticSignal_T priority); // 4
   } ChangeAttribute; //!< Change Attribute command
   struct
   {
      //! Get Type attribute
      bool_t (*Type) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T alarm_mask); // 0
      //! Get Background Colour attribute
      bool_t (*BackgroundColour) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T alarm_mask); // 1
      //! Get Soft Key Mask attribute
      bool_t (*SoftKeyMask) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T alarm_mask); // 2
      //! Get Priority attribute
      bool_t (*Priority) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T alarm_mask); // 3
      //! Get Acoustic Signal attribute
      bool_t (*AcousticSignal) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T alarm_mask); // 4
   } GetAttributeValue; //!< Get Attribute Command
} VTv4_AlarmMask_T;
/******************************************************************************/
// B.4 Container object
/******************************************************************************/
//! Type containing supported commands for a VTv4 Container object
typedef struct VTv4_Container_S
{
   //! Hide/Show Object command
   bool_t (*HideShowObject) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T container, ShowHide_Status_T show_flag);
   //! Change Child Location command (Relative Position)
   bool_t (*ChangeChildLocation)(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T container, ObjectID_T child, Pixel_T change_x_position, Pixel_T change_y_position, ObjectPool_ScaleFactor_T scaling_type);
   //! Change Child Position command (Absolute Position)
   bool_t (*ChangeChildPosition)(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_MessageCallback_T *callback, ObjectID_T container, ObjectID_T child, Pixel_T new_x_position, Pixel_T new_y_position, ObjectPool_ScaleFactor_T scaling_type);
   //! Change Size command
   bool_t (*ChangeSize) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T container, Pixel_T new_width, Pixel_T new_height, ObjectPool_ScaleFactor_T scaling_type);
   struct
   {
      //! Get Type attribute
      bool_t (*Type) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T container); // 0
      //! Get Width attribute
      bool_t (*Width) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T container); // 1
      //! Get Height attribute
      bool_t (*Height) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T container); // 2
      //! Get Hidden attribute
      bool_t (*Hidden) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T container); // 3
   } GetAttributeValue; //!< Get Attribute Command
} VTv4_Container_T;
/******************************************************************************/
// B.5 Soft Key Mask object
/******************************************************************************/
//! Type containing supported commands for a VTv4 Soft Key Mask object
typedef struct VTv4_SoftKeyMask_S
{
   //! Change Background Colour command
   bool_t (*ChangeBackgroundColour)(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T soft_key_mask, Colour_T background_colour);
   struct
   {
      //! Change Background Colour attribute
      bool_t (*BackgroundColour) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T soft_key_mask, Colour_T background_colour); // 1
   } ChangeAttribute; //!< Change Attribute command
   struct
   {
      //! Get Type attribute
      bool_t (*Type) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T soft_key_mask); // 0
      //! Get Background Colour attribute
      bool_t (*BackgroundColour) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T soft_key_mask); // 1
   } GetAttributeValue; //!< Get Attribute Command
} VTv4_SoftKeyMask_T;
/******************************************************************************/
// B.6 Key object
/******************************************************************************/
//! Type containing supported commands for a VTv4 Key object
typedef struct VTv4_Key_S
{
   //! Select Input Object command
   //! \note VTv4 and later only!
   bool_t (*SelectInputObject) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T key, Object_SelectionState_T option);
   //! Change Background Colour command
   bool_t (*ChangeBackgroundColour)(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T key, Colour_T background_colour);
   //! Change Child Location command (Relative Position)
   bool_t (*ChangeChildLocation) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T key, ObjectID_T child, Pixel_T change_x_position, Pixel_T change_y_position);
   //! Change Child Position command (Absolute Position)
   bool_t (*ChangeChildPosition) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_MessageCallback_T *callback, ObjectID_T key, ObjectID_T child, Pixel_T new_x_position, Pixel_T new_y_position);
   struct
   {
      //! Change Background Colour attribute
      bool_t (*BackgroundColour) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T key, Colour_T background_colour); // 1
      //! Change Key Code attribute
      bool_t (*KeyCode) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T key, KeyCode_T key_code); // 2
   } ChangeAttribute; //!< Change Attribute command
   struct
   {
      //! Get Type attribute
      bool_t (*Type) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T key); // 0
      //! Get Background Colour attribute
      bool_t (*BackgroundColour) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T key); // 1
      //! Get Key Code attribute
      bool_t (*KeyCode) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T key); // 2
   } GetAttributeValue; //!< Get Attribute Command
} VTv4_Key_T;
/******************************************************************************/
// B.7 Button object
/******************************************************************************/
//! Button Options attribute
typedef uint8_t ButtonOptions_T;
//! Option Bit 0:  If TRUE (1), the button is "latchable" and remains pressed until the next activation.  If FALSE (0), the button is momentary.
#define BUTTON_OPTIONS_LATCHABLE ((ButtonOptions_T)0x01)
//! Option Bit 1:  Current button state for latchable buttons.  0 = released, 1 = latched.  This attribute is ignored for momentary buttons.
#define BUTTON_OPTIONS_LATCHED ((ButtonOptions_T)0x02)
//! \brief  Option Bit 2:  Suppress border.  If FALSE (0), VT draws the proprietary border.  If TRUE (1), no border is ever drawn (even when pressed momentarily or latched) and the area normally occupied by the border is always transparent.
//! \note   VTv4 and later
#define BUTTON_OPTIONS_SUPPRESS_BORDER ((ButtonOptions_T)0x04)
//! \brief  Option Bit 3:  Transparent Background.  If FALSE (0), the button's interior background is filled using the background colour attribute.  If TRUE (1), the button's background is always transparent and the background colour attribute is not used.
//! \note   VTv4 and later
#define BUTTON_OPTIONS_TRANSPARENT_BACKGROUND ((ButtonOptions_T)0x08)
//! \brief  Option Bit 4:  Disabled.  If FALSE (0), the button is enabled and can be selected and activated by the operator.  If TRUE (1), the button is drawn disabled (method proprietary to VT) and it cannot be selected or activated by the operator.
//! \note   VTv4 and later
#define BUTTON_OPTIONS_DISABLED ((ButtonOptions_T)0x10)
//! \brief  Option Bit 5:  No border.  If FALSE (0), the Button Border area is used by the VT as described in Bit 2.  If TRUE (1), Bit 2 is ignored therefore no border is ever drawn (even when pressed momentarily or latched) and the Button Face extends to the full Button Area.
//! \note   VTv4 and later
#define BUTTON_OPTIONS_NO_BORDER ((ButtonOptions_T)0x20)
//! Type containing supported commands for a VTv4 Button object
typedef struct VTv4_Button_S
{
   //! Enable/Disable Object command
   //! \note VTv4 and later only!
   bool_t (*EnableDisableObject) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T button, EnableDisable_Status_T enable_flag);
   //! Select Input Object command
   //! \note VTv4 and later only!
   bool_t (*SelectInputObject) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T button, Object_SelectionState_T option);
   //! Change Background Colour command
   bool_t (*ChangeBackgroundColour)(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T button, Colour_T background_colour);
   //! Change Size command
   bool_t (*ChangeSize) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T button, Pixel_T width, Pixel_T height);
   //! Change Child Location command (Relative Position)
   bool_t (*ChangeChildLocation) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T button, ObjectID_T child, Pixel_T change_x_position, Pixel_T change_y_position);
   //! Change Child Position command (Absolute Position)
   bool_t (*ChangeChildPosition) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_MessageCallback_T *callback, ObjectID_T button, ObjectID_T child, Pixel_T new_x_position, Pixel_T new_y_position);
   struct
   {
      //! Change Width attribute
      bool_t (*Width) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T button, Pixel_T width); // 1
      //! Change Height attribute
      bool_t (*Height) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T button, Pixel_T height); // 2
      //! Change Background Colour attribute
      bool_t (*BackgroundColour) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T button, Colour_T background_colour); // 3
      //! Change Border Colour attribute
      bool_t (*BorderColour) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T button, Colour_T border_colour); // 4
      //! Change Key Code attribute
      bool_t (*KeyCode) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T button, KeyCode_T key_code); // 5
      //! Change Options attribute
      //! \note VTv4 and later
      bool_t (*Options) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T button, ButtonOptions_T options); // 6
   } ChangeAttribute; //!< Change Attribute command
   struct
   {
      //! Get Type attribute
      bool_t (*Type) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T button); // 0
      //! Get Width attribute
      bool_t (*Width) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T button); // 1
      //! Get Height attribute
      bool_t (*Height) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T button); // 2
      //! Get Background Colour attribute
      bool_t (*BackgroundColour) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T button); // 3
      //! Get Border Colour attribute
      bool_t (*BorderColour) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T button); // 4
      //! Get Key Code attribute
      bool_t (*KeyCode) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T button); // 5
      //! Get Options attribute
      //! \note VTv4 and later
      bool_t (*Options) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T button); // 6
   } GetAttributeValue; //!< Get Attribute Command
} VTv4_Button_T;
/******************************************************************************/
// B.8 Input field objects
/******************************************************************************/
/******************************************************************************/
// B.8.2 Input Boolean object
/******************************************************************************/
//! Type containing supported commands for a VTv4 Input Boolean object
typedef struct VTv4_InputBoolean_S
{
   //! Enable/Disable Object command
   bool_t (*EnableDisableObject) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_boolean, EnableDisable_Status_T enable_flag);
   //! Select Input Object command
   bool_t (*SelectInputObject) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_boolean, Object_SelectionState_T option);
   //! ESC command
   bool_t (*ESC) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback);
   //! Change Background Colour command
   bool_t (*ChangeBackgroundColour)(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_boolean, Colour_T background_colour);
   //! Change Numeric Value command
   bool_t (*ChangeNumericValue) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_boolean, NumericValue_T value);
   //! Change Size command
   //! \todo only uses width parameter
   bool_t (*ChangeSize) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_boolean, Pixel_T width, Pixel_T height);
   struct
   {
      //! Change Background Colour attribute
      bool_t (*BackgroundColour) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_boolean, Colour_T background_colour); // 1
      //! Change Width attribute
      bool_t (*Width) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_boolean, Pixel_T width); // 2
      //! Change Foreground Colour attribute
      bool_t (*ForegroundColour) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_boolean, Colour_T foreground_colour); // 3
      //! Change Variable Reference attribute
      bool_t (*VariableReference) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_boolean, ObjectID_T variable); // 4
   } ChangeAttribute; //!< Change Attribute command
   struct
   {
      //! Get Type attribute
      bool_t (*Type) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_boolean); // 0
      //! Get Background Colour attribute
      bool_t (*BackgroundColour) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_boolean); // 1
      //! Get Width attribute
      bool_t (*Width) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_boolean); // 2
      //! Get Foreground Colour attribute
      bool_t (*ForegroundColour) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_boolean); // 3
      //! Get Variable Reference attribute
      bool_t (*VariableReference) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_boolean); // 4
      //! Get Value attribute
      bool_t (*Value) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_boolean); // 5
      //! Get Enabled attribute
      bool_t (*Enabled) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_boolean); // 6
   } GetAttributeValue; //!< Get Attribute Command
} VTv4_InputBoolean_T;
/******************************************************************************/
// B.8.3 Input String object
/******************************************************************************/
//! Input/Output String Options
typedef uint8_t StringOptions_T;
//! Options Bit 0:  Transparent. If TRUE (1), the input field is displayed with background showing through instead of using the background colour attribute.
#define STRING_OPTIONS_TRANSPARENT ((StringOptions_T)0x01)
//! Options Bit 1:  Auto-Wrap. If TRUE (1), Auto-Wrapping rules apply
#define STRING_OPTIONS_AUTO_WRAP ((StringOptions_T)0x02)
//! \brief  Options Bit 2:  Wrap on Hyphen. If TRUE (1), Auto-Wrapping can occur between a hyphen (2D) and the following character.  Wrap on Hyphen is a modifier to the Auto-Wrap option and is applied only if the Auto-Wrap option is TRUE (1) and ignored if the Auto-Wrap option is FALSE (0).
//! \note VTv4 and later
#define STRING_OPTIONS_WRAP_ON_HYPHEN ((StringOptions_T)0x04)
//! Justification
typedef uint8_t Justification_T;
//! Left Justify
#define JUSTIFICATION_H_LEFT ((Justification_T)0x00)
//! Horizontal Center Justify
#define JUSTIFICATION_H_MIDDLE ((Justification_T)0x01)
//! Right Justify
#define JUSTIFICATION_H_RIGHT ((Justification_T)0x02)
//! \brief  Top Justify
//! \note   VTv4 and later
#define JUSTIFICATION_V_TOP ((Justification_T)0x00)
//! \brief  Vertical Center Justify
//! \note   VTv4 and later
#define JUSTIFICATION_V_MIDDLE ((Justification_T)0x04)
//! \brief  Bottom Justify
//! \note   VTv4 and later
#define JUSTIFICATION_V_BOTTOM ((Justification_T)0x08)
//! Type containing supported commands for a VTv4 Input String object
typedef struct VTv4_InputString_S
{
   //! Enable/Disable Object command
   bool_t (*EnableDisableObject) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_string, EnableDisable_Status_T enable_flag);
   //! Select Input Object command
   bool_t (*SelectInputObject) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_string, Object_SelectionState_T option);
   //! ESC command
   bool_t (*ESC) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback);
   //! Change Background Colour command
   bool_t (*ChangeBackgroundColour)(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_string, Colour_T background_colour);
   //! Change String Value command
   bool_t (*ChangeStringValue) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_MessageCallback_T *callback, ObjectID_T input_string, Size_T string_length, const char *string);
   //! Change Size command
   bool_t (*ChangeSize) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_string, Pixel_T width, Pixel_T height);
   struct
   {
      //! Change Width attribute
      bool_t (*Width) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_string, Pixel_T width); // 1
      //! Change Height attribute
      bool_t (*Height) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_string, Pixel_T height); // 2
      //! Change Background Colour attribute
      bool_t (*BackgroundColour) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_string, Colour_T background_colour); // 3
      //! Change Font Attributes attribute
      bool_t (*FontAttributes) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_string, ObjectID_T font_attributes); // 4
      //! Change Input Attributes attribute
      bool_t (*InputAttributes) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_string, ObjectID_T input_attributes); // 5
      //! Change Options attribute
      bool_t (*Options) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_string, StringOptions_T options); // 6
      //! Change Variable Reference attribute
      bool_t (*VariableReference) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_string, ObjectID_T variable); // 7
      //! Change Justification attribute
      bool_t (*Justification) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_string, Justification_T justification); // 8
   } ChangeAttribute; //!< Change Attribute command
   struct
   {
      //! Get Type attribute
      bool_t (*Type) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_string); // 0
      //! Get Width attribute
      bool_t (*Width) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_string); // 1
      //! Get Height attribute
      bool_t (*Height) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_string); // 2
      //! Get Background Colour attribute
      bool_t (*BackgroundColour) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_string); // 3
      //! Get Font Attributes attribute
      bool_t (*FontAttributes) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_string); // 4
      //! Get Input Attributes attribute
      bool_t (*InputAttributes) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_string); // 5
      //! Get Options attribute
      bool_t (*Options) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_string); // 6
      //! Get Variable Reference attribute
      bool_t (*VariableReference) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_string); // 7
      //! Get Justification attribute
      bool_t (*Justification) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_string); // 8
      //! Get Enabled attribute
      bool_t (*Enabled) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_string); // 9
   } GetAttributeValue; //!< Get Attribute Command
} VTv4_InputString_T;
/******************************************************************************/
// B.8.4 Input Number object
/******************************************************************************/
//! Input/Output Number Options
typedef uint8_t NumberOptions_T;
//! Number Options Bit 0:  Transparent. If TRUE (1), the input field is displayed with background showing through instead of using the background colour attribute.
#define NUMBER_OPTIONS_TRANSPARENT ((NumberOptions_T)0x01)
//! Number Options Bit 1:  Display leading zeros. If TRUE (1), Fill left to width of field with zeros.
#define NUMBER_OPTIONS_DISPLAY_LEADING_ZEROS ((NumberOptions_T)0x02)
//! Number Options Bit 2:  Display zero as blank if this bit is TRUE (1).  When this option bit is set, a blank field is displayed if and only if the value of the object is exactly zero.
#define NUMBER_OPTIONS_DISPLAY_ZERO_AS_BLANK ((NumberOptions_T)0x04)
//! \brief  Number Options Bit 4:  Truncate.  If TRUE (1), the value shall be truncated to the specified number of decimals.  Otherwise (0), it shall be rounded off to the specified number of decimals.
//! \note   VTv4 and later
#define NUMBER_OPTIONS_TRUNCATE ((NumberOptions_T)0x08)
//! Offset to be applied to the input, output, minimum and maximum values.  (actual_value = (value + offset) * scale)
typedef int32_t NumberOffset_T;
//! Scale to be applied to the input, output, minimum and maximum values.
typedef float32_t NumberScaleFactor_T;
//! Number of decimals to display after the decimal point.
typedef uint8_t NumberOfDecimals_T;
//! Number format (fixed decimal or exponential)
typedef uint8_t NumberFormat_T;
//! Number Format:  0 = use fixed format decimal display (####.nn)  where n is set by the number of decimals attribute.
#define NUMBER_FORMAT_FIXED_DECIMAL ((NumberFormat_T)0)
//! Number Format:  1 = use exponential format ([-]###.nnE[+/-]##)  where n is set by the number of decimals attribute.
#define NUMBER_FORMAT_EXPONENTIAL ((NumberFormat_T)1)
//! Type containing supported commands for a VTv4 Input Number object
typedef struct VTv4_InputNumber_S
{
   //! Enable/Disable Object command
   bool_t (*EnableDisableObject) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_number, EnableDisable_Status_T enable_flag);
   //! Select Input Object command
   bool_t (*SelectInputObject) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_number, Object_SelectionState_T option);
   //! ESC command
   bool_t (*ESC) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback);
   //! Change Background Colour command
   bool_t (*ChangeBackgroundColour)(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_number, Colour_T background_colour);
   //! Change Numeric Value command
   bool_t (*ChangeNumericValue) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_number, NumericValue_T value);
   //! Change Size command
   bool_t (*ChangeSize) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_number, Pixel_T width, Pixel_T height);
   struct
   {
      //! Change Width attribute
      bool_t (*Width) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_number, Pixel_T width); // 1
      //! Change Height attribute
      bool_t (*Height) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_number, Pixel_T height); // 2
      //! Change Background Colour attribute
      bool_t (*BackgroundColour) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_number, Colour_T background_colour); // 3
      //! Change Font Attributes attribute
      bool_t (*FontAttributes) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_number, ObjectID_T font_attributes); // 4
      //! Change Options attribute
      bool_t (*Options) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_number, NumberOptions_T options); // 5
      //! Change Variable Reference attribute
      bool_t (*VariableReference) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_number, ObjectID_T variable); // 6
      //! Change Minimum Value attribute
      bool_t (*MinimumValue) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_number, NumericValue_T minimum); // 7
      //! Change Maximum Value attribute
      bool_t (*MaximumValue) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_number, NumericValue_T maximum); // 8
      //! Change Offset attribute
      bool_t (*Offset) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_number, NumberOffset_T offset); // 9
      //! Change Scale attribute
      bool_t (*Scale) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_number, NumberScaleFactor_T scale); // 10
      //! Change Number Of Decimals attribute
      bool_t (*NumberOfDecimals) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_number, NumberOfDecimals_T number_of_decimals); // 11
      //! Change Format attribute
      bool_t (*Format) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_number, NumberFormat_T format); // 12
      //! Change Justification attribute
      bool_t (*Justification) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_number, Justification_T justification); // 13
   } ChangeAttribute; //!< Change Attribute command
   struct
   {
      //! Get Type attribute
      bool_t (*Type) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_number); // 0
      //! Get Width attribute
      bool_t (*Width) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_number); // 1
      //! Get Height attribute
      bool_t (*Height) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_number); // 2
      //! Get Background Colour attribute
      bool_t (*BackgroundColour) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_number); // 3
      //! Get Font Attributes attribute
      bool_t (*FontAttributes) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_number); // 4
      //! Get Options attribute
      bool_t (*Options) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_number); // 5
      //! Get Variable Reference attribute
      bool_t (*VariableReference) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_number); // 6
      //! Get Minimum Value attribute
      bool_t (*MinimumValue) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_number); // 7
      //! Get Maximum Value attribute
      bool_t (*MaximumValue) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_number); // 8
      //! Get Offset attribute
      bool_t (*Offset) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_number); // 9
      //! Get Scale attribute
      bool_t (*Scale) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_number); // 10
      //! Get Number Of Decimals attribute
      bool_t (*NumberOfDecimals) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_number); // 11
      //! Get Format attribute
      bool_t (*Format) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_number); // 12
      //! Get Justification attribute
      bool_t (*Justification) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_number); // 13
      //! Get Value attribute
      bool_t (*Value) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_number); // 14
      //! Get Options2 attribute
      bool_t (*Options2) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_number); // 15
   } GetAttributeValue; //!< Get Attribute Command
} VTv4_InputNumber_T;
/******************************************************************************/
// B.8.5 Input List object
/******************************************************************************/
//! Type containing supported commands for a VTv4 Input List object
typedef struct VTv4_InputList_S
{
   //! Enable/Disable Object command
   bool_t (*EnableDisableObject) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_list, EnableDisable_Status_T enable_flag);
   //! Select Input Object command
   bool_t (*SelectInputObject) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_list, Object_SelectionState_T option);
   //! ESC command
   bool_t (*ESC) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback);
   //! Change Numeric Value command
   bool_t (*ChangeNumericValue) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_list, NumericValue_T value);
   //! Change List Item command
   bool_t (*ChangeListItem) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_list, ListIndex_T list_index, ObjectID_T new_object);
   //! Change Size command
   bool_t (*ChangeSize) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_list, Pixel_T width, Pixel_T height);
   struct
   {
      //! Change Width attribute
      bool_t (*Width) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_list, Pixel_T width); // 1
      //! Change Height attribute
      bool_t (*Height) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_list, Pixel_T height); // 2
      //! Change Variable Reference attribute
      bool_t (*VariableReference)(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_list, ObjectID_T variable); // 3
   } ChangeAttribute; //!< Change Attribute command
   struct
   {
      //! Get Type attribute
      bool_t (*Type) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_list); // 0
      //! Get Width attribute
      bool_t (*Width) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_list); // 1
      //! Get Height attribute
      bool_t (*Height) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_list); // 2
      //! Get Variable Reference attribute
      bool_t (*VariableReference)(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_list); // 3
      //! Get Value attribute
      bool_t (*Value) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_list); // 4
      //! Get Options attribute
      bool_t (*Options) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_list); // 5
   } GetAttributeValue; //!< Get Attribute Command
} VTv4_InputList_T;
/******************************************************************************/
// B.9 Output field objects
/******************************************************************************/
/******************************************************************************/
// B.9.2 Output String object
/******************************************************************************/
//! Type containing supported commands for a VTv4 Output String object
typedef struct VTv4_OutputString_S
{
   //! Change Background Colour command
   bool_t (*ChangeBackgroundColour)(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T output_string, Colour_T background_colour);
   //! Change String Value command
   bool_t (*ChangeStringValue) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_MessageCallback_T *callback, ObjectID_T output_string, Size_T string_length, const char *string);
   //! Change Size command
   bool_t (*ChangeSize) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T output_string, Pixel_T width, Pixel_T height, ObjectPool_ScaleFactor_T scaling_type);
   struct
   {
      //! Change Width attribute
      bool_t (*Width) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T output_string, Pixel_T width); // 1
      //! Change Height attribute
      bool_t (*Height) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T output_string, Pixel_T height); // 2
      //! Change Background Colour attribute
      bool_t (*BackgroundColour) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T output_string, Colour_T background_colour); // 3
      //! Change Font Attributes attribute
      bool_t (*FontAttributes) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T output_string, ObjectID_T font_attributes); // 4
      //! Change Options attribute
      bool_t (*Options) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T output_string, StringOptions_T options); // 5
      //! Change Variable Reference attribute
      bool_t (*VariableReference) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T output_string, ObjectID_T variable); // 6
      //! Change Justification attribute
      bool_t (*Justification) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T output_string, Justification_T justification); // 7
   } ChangeAttribute; //!< Change Attribute command
   struct
   {
      //! Get Type attribute
      bool_t (*Type) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T output_string); // 0
      //! Get Width attribute
      bool_t (*Width) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T output_string); // 1
      //! Get Height attribute
      bool_t (*Height) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T output_string); // 2
      //! Get Background Colour attribute
      bool_t (*BackgroundColour) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T output_string); // 3
      //! Get Font Attributes attribute
      bool_t (*FontAttributes) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T output_string); // 4
      //! Get Options attribute
      bool_t (*Options) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T output_string); // 5
      //! Get Variable Reference attribute
      bool_t (*VariableReference) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T output_string); // 6
      //! Get Justification attribute
      bool_t (*Justification) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T output_string); // 7
   } GetAttributeValue; //!< Get Attribute Command
} VTv4_OutputString_T;
/******************************************************************************/
// B.9.3 Output Number object
/******************************************************************************/
//! Type containing supported commands for a VTv4 Output Number object
typedef struct VTv4_OutputNumber_S
{
   //! Change Background Colour command
   bool_t (*ChangeBackgroundColour)(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T output_number, Colour_T background_colour);
   //! Change Numeric Value command
   bool_t (*ChangeNumericValue) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T output_number, NumericValue_T value);
   //! Change Size command
   bool_t (*ChangeSize) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T output_number, Pixel_T width, Pixel_T height, ObjectPool_ScaleFactor_T scaling_type);
   struct
   {
      //! Change Width attribute
      bool_t (*Width) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T output_number, Pixel_T width); // 1
      //! Change Height attribute
      bool_t (*Height) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T output_number, Pixel_T height); // 2
      //! Change Background Colour attribute
      bool_t (*BackgroundColour) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T output_number, Colour_T background_colour); // 3
      //! Change Font Attributes attribute
      bool_t (*FontAttributes) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T output_number, ObjectID_T font_attributes); // 4
      //! Change Options attribute
      bool_t (*Options) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T output_number, NumberOptions_T options); // 5
      //! Change Variable Reference attribute
      bool_t (*VariableReference) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T output_number, ObjectID_T variable); // 6
      //! Change Offset attribute
      bool_t (*Offset) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T output_number, NumberOffset_T offset); // 7
      //! Change Scale attribute
      bool_t (*Scale) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T output_number, NumberScaleFactor_T scale); // 8
      //! Change Number Of Decimals attribute
      bool_t (*NumberOfDecimals) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T output_number, NumberOfDecimals_T number_of_decimals); // 9
      //! Change Format attribute
      bool_t (*Format) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T output_number, NumberFormat_T format); // 10
      //! Change Justification attribute
      bool_t (*Justification) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T output_number, Justification_T justification); // 11
   } ChangeAttribute; //!< Change Attribute command
   struct
   {
      //! Get Type attribute
      bool_t (*Type) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T output_number); // 0
      //! Get Width attribute
      bool_t (*Width) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T output_number); // 1
      //! Get Height attribute
      bool_t (*Height) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T output_number); // 2
      //! Get Background Colour attribute
      bool_t (*BackgroundColour) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T output_number); // 3
      //! Get Font Attributes attribute
      bool_t (*FontAttributes) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T output_number); // 4
      //! Get Options attribute
      bool_t (*Options) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T output_number); // 5
      //! Get Variable Reference attribute
      bool_t (*VariableReference) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T output_number); // 6
      //! Get Offset attribute
      bool_t (*Offset) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T output_number); // 7
      //! Get Scale attribute
      bool_t (*Scale) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T output_number); // 8
      //! Get Number Of Decimals attribute
      bool_t (*NumberOfDecimals) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T output_number); // 9
      //! Get Format attribute
      bool_t (*Format) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T output_number); // 10
      //! Get Justification attribute
      bool_t (*Justification) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T output_number); // 11
      //! Get Value attribute
      bool_t (*Value) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T output_number); // 12
   } GetAttributeValue; //!< Get Attribute Command
} VTv4_OutputNumber_T;
/******************************************************************************/
// B.9.4 Output List object
/******************************************************************************/
//! Type containing supported commands for a VTv4 Output List object
typedef struct VTv4_OutputList_S
{
   //! Change Numeric Value command
   bool_t (*ChangeNumericValue) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T output_list, NumericValue_T value);
   //! Change List Item command
   bool_t (*ChangeListItem) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T output_list, ListIndex_T list_index, ObjectID_T new_object);
   //! Change Size command
   bool_t (*ChangeSize) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T output_list, Pixel_T width, Pixel_T height, ObjectPool_ScaleFactor_T scaling_type);
   struct
   {
      //! Change Width attribute
      bool_t (*Width) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T output_list, Pixel_T width); // 1
      //! Change Height attribute
      bool_t (*Height) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T output_list, Pixel_T height); // 2
      //! Change Variable Reference attribute
      bool_t (*VariableReference)(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T output_list, ObjectID_T variable); // 3
   } ChangeAttribute; //!< Change Attribute command
   struct
   {
      //! Get Type attribute
      bool_t (*Type) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T output_list); // 0
      //! Get Width attribute
      bool_t (*Width) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T output_list); // 1
      //! Get Height attribute
      bool_t (*Height) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T output_list); // 2
      //! Get Variable Reference attribute
      bool_t (*VariableReference)(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T output_list); // 3
      //! Get Value attribute
      bool_t (*Value) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T output_list); // 4
   } GetAttributeValue; //!< Get Attribute Command
} VTv4_OutputList_T;
/******************************************************************************/
// B.10 Output Shape Objects
/******************************************************************************/
/******************************************************************************/
// B.10.2 Line object
/******************************************************************************/
//! Type containing supported commands for a VTv4 Line object
typedef struct VTv4_Line_S
{
   //! Change End Point command
   bool_t (*ChangeEndPoint) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T line, Pixel_T width, Pixel_T height, LineDirection_T direction, ObjectPool_ScaleFactor_T scaling_type);
   //! Change Size command
   bool_t (*ChangeSize) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T line, Pixel_T width, Pixel_T height, ObjectPool_ScaleFactor_T scaling_type);
   struct
   {
      //! Change Line Attributes attribute
      bool_t (*LineAttributes)(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T line, ObjectID_T line_attributes); // 1
      //! Change Width attribute
      bool_t (*Width) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T line, Pixel_T width); // 2
      //! Change Height attribute
      bool_t (*Height) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T line, Pixel_T height); // 3
      //! Change Line Direction attribute
      bool_t (*LineDirection) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T line, LineDirection_T direction); // 4
   } ChangeAttribute; //!< Change Attribute command
   struct
   {
      //! Get Type attribute
      bool_t (*Type) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T line); // 0
      //! Get Line Attributes attribute
      bool_t (*LineAttributes)(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T line); // 1
      //! Get Width attribute
      bool_t (*Width) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T line); // 2
      //! Get Height attribute
      bool_t (*Height) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T line); // 3
      //! Get Line Direction attribute
      bool_t (*LineDirection) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T line); // 4
   } GetAttributeValue; //!< Get Attribute Command
} VTv4_Line_T;
/******************************************************************************/
// B.10.3 Rectangle object
/******************************************************************************/
//! Type containing supported commands for a VTv4 Rectangle object
typedef struct VTv4_Rectangle_S
{
   //! Change Size command
   bool_t (*ChangeSize) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T rectangle, Pixel_T width, Pixel_T height, ObjectPool_ScaleFactor_T scaling_type);
   struct
   {
      //! Change Line Attributes attribute
      bool_t (*LineAttributes) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T rectangle, ObjectID_T line_attributes); // 1
      //! Change Width attribute
      bool_t (*Width) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T rectangle, Pixel_T width); // 2
      //! Change Height attribute
      bool_t (*Height) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T rectangle, Pixel_T height); // 3
      //! Change Line Suppression attribute
      bool_t (*LineSuppression)(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T rectangle, LineSuppression_T line_suppression); // 4
      //! Change Fill Attributes attribute
      bool_t (*FillAttributes) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T rectangle, ObjectID_T fill_attributes); // 5
   } ChangeAttribute; //!< Change Attribute command
   struct
   {
      //! Get Type attribute
      bool_t (*Type) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T rectangle); // 0
      //! Get Line Attributes attribute
      bool_t (*LineAttributes) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T rectangle); // 1
      //! Get Width attribute
      bool_t (*Width) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T rectangle); // 2
      //! Get Height attribute
      bool_t (*Height) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T rectangle); // 3
      //! Get Line Suppression attribute
      bool_t (*LineSuppression)(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T rectangle); // 4
      //! Get Fill Attributes attribute
      bool_t (*FillAttributes) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T rectangle); // 5
   } GetAttributeValue; //!< Get Attribute Command
} VTv4_Rectangle_T;
/******************************************************************************/
// B.10.4 Ellipse object
/******************************************************************************/
//! Type containing supported commands for a VTv4 Ellipse object
typedef struct VTv4_Ellipse_S
{
   //! Change Size command
   bool_t (*ChangeSize) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T ellipse, Pixel_T width, Pixel_T height, ObjectPool_ScaleFactor_T scaling_type);
   struct
   {
      //! Change Line Attributes attribute
      bool_t (*LineAttributes)(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T ellipse, ObjectID_T line_attributes); // 1
      //! Change Width attribute
      bool_t (*Width) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T ellipse, Pixel_T width); // 2
      //! Change Height attribute
      bool_t (*Height) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T ellipse, Pixel_T height); // 3
      //! Change Ellipse Type attribute
      bool_t (*EllipseType) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T ellipse, EllipseType_T ellipse_type); // 4
      //! Change Start Angle attribute
      bool_t (*StartAngle) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T ellipse, Angle_T start); // 5
      //! Change End Angle attribute
      bool_t (*EndAngle) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T ellipse, Angle_T end); // 6
      //! Change Fill Attributes attribute
      bool_t (*FillAttributes)(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T ellipse, ObjectID_T fill_attributes); // 7
   } ChangeAttribute; //!< Change Attribute command
   struct
   {
      //! Get Type attribute
      bool_t (*Type) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T ellipse); // 0
      //! Get Line Attributes attribute
      bool_t (*LineAttributes)(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T ellipse); // 1
      //! Get Width attribute
      bool_t (*Width) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T ellipse); // 2
      //! Get Height attribute
      bool_t (*Height) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T ellipse); // 3
      //! Get Ellipse Type attribute
      bool_t (*EllipseType) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T ellipse); // 4
      //! Get Start Angle attribute
      bool_t (*StartAngle) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T ellipse); // 5
      //! Get End Angle attribute
      bool_t (*EndAngle) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T ellipse); // 6
      //! Get Fill Attributes attribute
      bool_t (*FillAttributes)(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T ellipse); // 7
   } GetAttributeValue; //!< Get Attribute Command
} VTv4_Ellipse_T;
/******************************************************************************/
// B.10.5 Polygon object
/******************************************************************************/
//! Type containing supported commands for a VTv4 Polygon object
typedef struct VTv4_Polygon_S
{
   //! Change Size command
   bool_t (*ChangeSize) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T polygon, Pixel_T width, Pixel_T height, ObjectPool_ScaleFactor_T scaling_type);
   //! Change Polygon Point command
   bool_t (*ChangePolygonPoint)(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T polygon, PolygonPointIndex_T point_index, Pixel_T x_value, Pixel_T y_value, ObjectPool_ScaleFactor_T scaling_type);
   //! Change Polygon Scale command
   bool_t (*ChangePolygonScale)(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T polygon, Pixel_T width, Pixel_T height, ObjectPool_ScaleFactor_T scaling_type);
   struct
   {
      //! Change Width attribute
      bool_t (*Width) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T polygon, Pixel_T width); // 1
      //! Change Height attribute
      bool_t (*Height) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T polygon, Pixel_T height); // 2
      //! Change Line Attributes attribute
      bool_t (*LineAttributes) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T polygon, ObjectID_T line_attributes); // 3
      //! Change Fill Attributes attribute
      bool_t (*FillAttributes) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T polygon, ObjectID_T fill_attributes); // 4
      //! Change Polygon Type attribute
      bool_t (*PolygonType) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T polygon, PolygonType_T polygon_type); // 5
   } ChangeAttribute; //!< Change Attribute command
   struct
   {
      //! Get Type attribute
      bool_t (*Type) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T polygon); // 0
      //! Get Width attribute
      bool_t (*Width) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T polygon); // 1
      //! Get Height attribute
      bool_t (*Height) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T polygon); // 2
      //! Get Line Attributes attribute
      bool_t (*LineAttributes) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T polygon); // 3
      //! Get Fill Attributes attribute
      bool_t (*FillAttributes) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T polygon); // 4
      //! Get Polygon Type attribute
      bool_t (*PolygonType) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T polygon); // 5
   } GetAttributeValue; //!< Get Attribute Command
} VTv4_Polygon_T;
/******************************************************************************/
// B.11 Output Graphic Objects
/******************************************************************************/
/******************************************************************************/
// B.11.2 Meter object
/******************************************************************************/
//! Meter options
typedef uint8_t MeterOptions_T;
//! Meter Options Bit 0:  1 = Draw Arc
#define METER_OPTIONS_DRAW_ARC ((MeterOptions_T)0x01)
//! Meter Options Bit 1:  1 = Draw Border
#define METER_OPTIONS_DRAW_BORDER ((MeterOptions_T)0x02)
//! Meter Options Bit 2:  1 = Draw Ticks
#define METER_OPTIONS_DRAW_TICKS ((MeterOptions_T)0x04)
//! Meter Options Bit 3:  Deflection Direction. 0 = From minimum to maximum, anticlockwise. 1 = From minimum to maximum, clockwise.
#define METER_OPTIONS_CLOCKWISE_DEFLECTION ((MeterOptions_T)0x08)
//! Number of Ticks on a graphic (meter, or linear bar graph)
typedef uint8_t GraphicTicks_T;
//! Type containing supported commands for a VTv4 Meter object
typedef struct VTv4_Meter_S
{
   //! Change Numeric Value command
   bool_t (*ChangeNumericValue) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T meter, NumericValue_T value);
   //! Change Size command
   bool_t (*ChangeSize) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T meter, Pixel_T width, Pixel_T height, ObjectPool_ScaleFactor_T scaling_type);
   struct
   {
      //! Change Width attribute
      bool_t (*Width) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T meter, Pixel_T width); // 1
      //! Change Needle Colour attribute
      bool_t (*NeedleColour) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T meter, Colour_T needle_colour); // 2
      //! Change Border Colour attribute
      bool_t (*BorderColour) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T meter, Colour_T border_colour); // 3
      //! Change Arc And Tick Colour attribute
      bool_t (*ArcAndTickColour) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T meter, Colour_T arc_tick_colour); // 4
      //! Change Options attribute
      bool_t (*Options) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T meter, MeterOptions_T options); // 5
      //! Change Number Of Ticks attribute
      bool_t (*NumberOfTicks) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T meter, GraphicTicks_T number_of_ticks); // 6
      //! Change Start Angle attribute
      bool_t (*StartAngle) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T meter, Angle_T start); // 7
      //! Change End Angle attribute
      bool_t (*EndAngle) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T meter, Angle_T end); // 8
      //! Change Minimum Value attribute
      bool_t (*MinimumValue) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T meter, NumericValue_T minimum_value); // 9
      //! Change Maximum Value attribute
      bool_t (*MaximumValue) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T meter, NumericValue_T maximum_value); // 10
      //! Change Variable Reference attribute
      bool_t (*VariableReference)(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T meter, ObjectID_T variable); // 11
   } ChangeAttribute; //!< Change Attribute command
   struct
   {
      //! Get Type attribute
      bool_t (*Type) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T meter); // 0
      //! Get Width attribute
      bool_t (*Width) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T meter); // 1
      //! Get Needle Colour attribute
      bool_t (*NeedleColour) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T meter); // 2
      //! Get Border Colour attribute
      bool_t (*BorderColour) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T meter); // 3
      //! Get Arc And Tick Colour attribute
      bool_t (*ArcAndTickColour) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T meter); // 4
      //! Get Options attribute
      bool_t (*Options) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T meter); // 5
      //! Get Number Of Ticks attribute
      bool_t (*NumberOfTicks) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T meter); // 6
      //! Get Start Angle attribute
      bool_t (*StartAngle) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T meter); // 7
      //! Get End Angle attribute
      bool_t (*EndAngle) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T meter); // 8
      //! Get Minimum Value attribute
      bool_t (*MinimumValue) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T meter); // 9
      //! Get Maximum Value attribute
      bool_t (*MaximumValue) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T meter); // 10
      //! Get Variable Reference attribute
      bool_t (*VariableReference)(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T meter); // 11
      //! Get Value attribute
      bool_t (*Value) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T meter); // 12
   } GetAttributeValue; //!< Get Attribute Command
} VTv4_Meter_T;
/******************************************************************************/
// B.11.3 Linear Bar Graph object
/******************************************************************************/
//! Linear Bar Graph options
typedef uint8_t LinearBarGraphOptions_T;
//! Linear Bar Graph Options Bit 0:  Draw border
#define LINEAR_BAR_GRAPH_OPTIONS_DRAW_BORDER ((LinearBarGraphOptions_T)0x01)
//! Linear Bar Graph Options Bit 1:  Draw target line
#define LINEAR_BAR_GRAPH_OPTIONS_DRAW_TARGET ((LinearBarGraphOptions_T)0x02)
//! Linear Bar Graph Options Bit 2:  Draw ticks
#define LINEAR_BAR_GRAPH_OPTIONS_DRAW_TICKS ((LinearBarGraphOptions_T)0x04)
//! Linear Bar Graph Options Bit 3:  Bar graph type.  If this bit is FALSE (0), bar graph is filled.  If this bit is TRUE (1), bar graph is not filled but rather shows the current value as a single line at the proper position within the bar graph.
#define LINEAR_BAR_GRAPH_OPTIONS_GRAPH_TYPE ((LinearBarGraphOptions_T)0x08)
//! Linear Bar Graph Options Bit 4:  Axis orientation.  0 = vertical (increasing values move parallel to the Y axis with constant X)
#define LINEAR_BAR_GRAPH_OPTIONS_VERTICAL ((LinearBarGraphOptions_T)0x00)
//! Linear Bar Graph Options Bit 4:  Axis orientation.  1 = horizontal (increasing values move parallel to the X axis with constant Y)
#define LINEAR_BAR_GRAPH_OPTIONS_HORIZONTAL ((LinearBarGraphOptions_T)0x10)
//! Linear Bar Graph Options Bit 5:  Direction.  0 = Grows negative (left or down).  1 = Grows positive (right or up).
#define LINEAR_BAR_GRAPH_OPTIONS_GROW_NEGATIVE ((LinearBarGraphOptions_T)0x00)
//! Linear Bar Graph Options Bit 5:  Direction.  0 = Grows negative (left or down).  1 = Grows positive (right or up).
#define LINEAR_BAR_GRAPH_OPTIONS_GROW_POSITIVE ((LinearBarGraphOptions_T)0x20)
//! Type containing supported commands for a VTv4 Linear Bar Graph object
typedef struct VTv4_LinearBarGraph_S
{
   //! Change Numeric Value command
   bool_t (*ChangeNumericValue) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T linear_bar_graph, NumericValue_T value);
   //! Change Size command
   bool_t (*ChangeSize) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T linear_bar_graph, Pixel_T width, Pixel_T height, ObjectPool_ScaleFactor_T scaling_type);
   struct
   {
      //! Change Width attribute
      bool_t (*Width) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T linear_bar_graph, Pixel_T width); // 1
      //! Change Height attribute
      bool_t (*Height) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T linear_bar_graph, Pixel_T height); // 2
      //! Change Colour attribute
      bool_t (*Colour) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T linear_bar_graph, Colour_T colour); // 3
      //! Change Target Line Colour attribute
      bool_t (*TargetLineColour) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T linear_bar_graph, Colour_T target_line_colour); // 4
      //! Change Options attribute
      bool_t (*Options) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T linear_bar_graph, LinearBarGraphOptions_T options); // 5
      //! Change Number Of Ticks attribute
      bool_t (*NumberOfTicks) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T linear_bar_graph, GraphicTicks_T number_of_ticks); // 6
      //! Change Minimum Value attribute
      bool_t (*MinimumValue) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T linear_bar_graph, NumericValue_T minimum_value); // 7
      //! Change Maximum Value attribute
      bool_t (*MaximumValue) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T linear_bar_graph, NumericValue_T maximum_value); // 8
      //! Change Variable Reference attribute
      bool_t (*VariableReference) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T linear_bar_graph, ObjectID_T variable); // 9
      //! Change Target Value Reference attribute
      bool_t (*TargetValueReference)(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T linear_bar_graph, ObjectID_T target_variable); // 10
      //! Change Target Value attribute
      bool_t (*TargetValue) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T linear_bar_graph, NumericValue_T target_value); // 11
   } ChangeAttribute; //!< Change Attribute command
   struct
   {
      //! Get Type attribute
      bool_t (*Type) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T linear_bar_graph); // 0
      //! Get Width attribute
      bool_t (*Width) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T linear_bar_graph); // 1
      //! Get Height attribute
      bool_t (*Height) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T linear_bar_graph); // 2
      //! Get Colour attribute
      bool_t (*Colour) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T linear_bar_graph); // 3
      //! Get Target Line Colour attribute
      bool_t (*TargetLineColour) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T linear_bar_graph); // 4
      //! Get Options attribute
      bool_t (*Options) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T linear_bar_graph); // 5
      //! Get Number Of Ticks attribute
      bool_t (*NumberOfTicks) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T linear_bar_graph); // 6
      //! Get Minimum Value attribute
      bool_t (*MinimumValue) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T linear_bar_graph); // 7
      //! Get Maximum Value attribute
      bool_t (*MaximumValue) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T linear_bar_graph); // 8
      //! Get Variable Reference attribute
      bool_t (*VariableReference) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T linear_bar_graph); // 9
      //! Get Target Value Reference attribute
      bool_t (*TargetValueReference)(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T linear_bar_graph); // 10
      //! Get Target Value attribute
      bool_t (*TargetValue) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T linear_bar_graph); // 11
      //! Get Value attribute
      bool_t (*Value) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T linear_bar_graph); // 12
   } GetAttributeValue; //!< Get Attribute Command
} VTv4_LinearBarGraph_T;
/******************************************************************************/
// B.11.4 Arched Bar Graph object
/******************************************************************************/
//! Arched Bar Graph options
typedef uint8_t ArchedBarGraphOptions_T;
//! Arched Bar Graph Options Bit 0:  Draw border
#define ARCHED_BAR_GRAPH_OPTIONS_DRAW_BORDER ((ArchedBarGraphOptions_T)0x01)
//! Arched Bar Graph Options Bit 1:  Draw a target line
#define ARCHED_BAR_GRAPH_OPTIONS_DRAW_TARGET ((ArchedBarGraphOptions_T)0x02)
//! Arched Bar Graph Options Bit 3:  bar graph type.  If this bit is FALSE (0), bar graph is filled.
#define ARCHED_BAR_GRAPH_OPTIONS_GRAPH_FILLED ((ArchedBarGraphOptions_T)0x00)
//! Arched Bar Graph Options Bit 3:  bar graph type.  If this bit is TRUE (1), the bar graph is not filled but rather shows the current value as a single line at the proper position within the bar graph.
#define ARCHED_BAR_GRAPH_OPTIONS_GRAPH_NOT_FILLED ((ArchedBarGraphOptions_T)0x08)
//! Arched Bar Graph Options Bit 4:  Deflection of the bar graph around the arc. 0 = anticlockwise
#define ARCHED_BAR_GRAPH_OPTIONS_ANTICLOCKWISE ((ArchedBarGraphOptions_T)0x00)
//! Arched Bar Graph Options Bit 4:  Deflection of the bar graph around the arc. 1 = clockwise
#define ARCHED_BAR_GRAPH_OPTIONS_CLOCKWISE ((ArchedBarGraphOptions_T)0x10)
//! Type containing supported commands for a VTv4 Arched Bar Graph object
typedef struct VTv4_ArchedBarGraph_S
{
   //! Change Numeric Value command
   bool_t (*ChangeNumericValue) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T arched_bar_graph, NumericValue_T value);
   //! Change Size command
   bool_t (*ChangeSize) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T arched_bar_graph, Pixel_T width, Pixel_T height, ObjectPool_ScaleFactor_T scaling_type);
   struct
   {
      //! Change Width attribute
      bool_t (*Width) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T arched_bar_graph, Pixel_T width); // 1
      //! Change Height attribute
      bool_t (*Height) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T arched_bar_graph, Pixel_T height); // 2
      //! Change Colour attribute
      bool_t (*Colour) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T arched_bar_graph, Colour_T colour); // 3
      //! Change Target Line Colour attribute
      bool_t (*TargetLineColour) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T arched_bar_graph, Colour_T target_line_colour); // 4
      //! Change Options attribute
      bool_t (*Options) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T arched_bar_graph, ArchedBarGraphOptions_T options); // 5
      //! Change Start Angle attribute
      bool_t (*StartAngle) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T arched_bar_graph, Angle_T start); // 6
      //! Change End Angle attribute
      bool_t (*EndAngle) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T arched_bar_graph, Angle_T end); // 7
      //! Change Bar Graph Width attribute
      bool_t (*BarGraphWidth) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T arched_bar_graph, Pixel_T width); // 8
      //! Change Minimum Value attribute
      bool_t (*MinimumValue) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T arched_bar_graph, NumericValue_T minimum_value); // 9
      //! Change Maximum Value attribute
      bool_t (*MaximumValue) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T arched_bar_graph, NumericValue_T maximum_value); // 10
      //! Change Variable Reference attribute
      bool_t (*VariableReference) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T arched_bar_graph, ObjectID_T variable); // 11
      //! Change Target Value Reference attribute
      bool_t (*TargetValueReference)(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T arched_bar_graph, ObjectID_T target_variable); // 12
      //! Change Target Value attribute
      bool_t (*TargetValue) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T arched_bar_graph, NumericValue_T target_value); // 13
   } ChangeAttribute; //!< Change Attribute command
   struct
   {
      //! Get Type attribute
      bool_t (*Type) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T arched_bar_graph); // 0
      //! Get Width attribute
      bool_t (*Width) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T arched_bar_graph); // 1
      //! Get Height attribute
      bool_t (*Height) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T arched_bar_graph); // 2
      //! Get Colour attribute
      bool_t (*Colour) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T arched_bar_graph); // 3
      //! Get Target Line Colour attribute
      bool_t (*TargetLineColour) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T arched_bar_graph); // 4
      //! Get Options attribute
      bool_t (*Options) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T arched_bar_graph); // 5
      //! Get Start Angle attribute
      bool_t (*StartAngle) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T arched_bar_graph); // 6
      //! Get End Angle attribute
      bool_t (*EndAngle) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T arched_bar_graph); // 7
      //! Get Bar Graph Width attribute
      bool_t (*BarGraphWidth) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T arched_bar_graph); // 8
      //! Get Minimum Value attribute
      bool_t (*MinimumValue) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T arched_bar_graph); // 9
      //! Get Maximum Value attribute
      bool_t (*MaximumValue) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T arched_bar_graph); // 10
      //! Get Variable Reference attribute
      bool_t (*VariableReference) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T arched_bar_graph); // 11
      //! Get Target Value Reference attribute
      bool_t (*TargetValueReference)(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T arched_bar_graph); // 12
      //! Get Target Value attribute
      bool_t (*TargetValue) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T arched_bar_graph); // 13
      //! Get Value attribute
      bool_t (*Value) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T arched_bar_graph); // 14
   } GetAttributeValue; //!< Get Attribute Command
} VTv4_ArchedBarGraph_T;
/******************************************************************************/
// B.12 Picture Graphic object
/******************************************************************************/
//! Type containing supported commands for a VTv4 Picture Graphic object
typedef struct VTv4_PictureGraphic_S
{
   struct
   {
      //! Change Width attribute
      bool_t (*Width) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T picture_graphic, Pixel_T width); // 1
      //! Change Options attribute
      bool_t (*Options) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T picture_graphic, PictureGraphicOptions_T options); // 2
      //! Change Transparency Colour attribute
      bool_t (*TransparencyColour)(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T picture_graphic, Colour_T tranparency_colour); // 3
   } ChangeAttribute; //!< Change Attribute command
   struct
   {
      //! Get Type attribute
      bool_t (*Type) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T picture_graphic); // 0
      //! Get Width attribute
      bool_t (*Width) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T picture_graphic); // 1
      //! Get Options attribute
      bool_t (*Options) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T picture_graphic); // 2
      //! Get Transparency Colour attribute
      bool_t (*TransparencyColour)(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T picture_graphic); // 3
      //! Get Actual Width attribute
      bool_t (*ActualWidth) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T picture_graphic); // 4
      //! Get Actual Height attribute
      bool_t (*ActualHeight) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T picture_graphic); // 5
      //! Get Format attribute
      bool_t (*Format) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T picture_graphic); // 6
   } GetAttributeValue; //!< Get Attribute Command
} VTv4_PictureGraphic_T;
/******************************************************************************/
// B.13 Variable Objects
/******************************************************************************/
/******************************************************************************/
// B.13.2 Number Variable object
/******************************************************************************/
//! Type containing supported commands for a VTv4 Number Variable object
typedef struct VTv4_NumberVariable_S
{
   //! Change Numeric Value command
   bool_t (*ChangeNumericValue)(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T number_variable, NumericValue_T value);
   struct
   {
      //! Get Type attribute
      bool_t (*Type) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T number_variable); // 0
      //! Get Value attribute
      bool_t (*Value) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T number_variable); // 1
   } GetAttributeValue; //!< Get Attribute Command
} VTv4_NumberVariable_T;
/******************************************************************************/
// B.13.3 String Variable object
/******************************************************************************/
//! Type containing supported commands for a VTv4 String Variable object
typedef struct VTv4_StringVariable_S
{
   //! Change String Value command
   bool_t (*ChangeStringValue)(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_MessageCallback_T *callback, ObjectID_T string_variable, Size_T string_length, const char *string);
   struct
   {
      //! Get Type attribute
      bool_t (*Type) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T string_variable); // 0
   } GetAttributeValue; //!< Get Attribute Command
} VTv4_StringVariable_T;
/******************************************************************************/
// B.14 Attribute Objects
/******************************************************************************/
/******************************************************************************/
// B.14.2 Font Attributes object
/******************************************************************************/
//! Type containing supported commands for a VTv4 Font Attributes object
typedef struct VTv4_FontAttributes_S
{
   //! Change Font Attributes command
   bool_t (*ChangeFontAttributes)(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T font_attributes, Colour_T colour, FontSize_T size, FontType_T type, FontStyle_T style);
   struct
   {
      //! Change Font Colour attribute
      bool_t (*FontColour) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T font_attributes, Colour_T colour); // 1
      //! Change Font Size attribute
      bool_t (*FontSize) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T font_attributes, FontSize_T size); // 2
      //! Change Font Type attribute
      bool_t (*FontType) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T font_attributes, FontType_T type); // 3
      //! Change Font Style attribute
      bool_t (*FontStyle) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T font_attributes, FontStyle_T style); // 4
   } ChangeAttribute; //!< Change Attribute command
   struct
   {
      //! Get Type attribute
      bool_t (*Type) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T font_attributes); // 0
      //! Get Font Colour attribute
      bool_t (*FontColour) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T font_attributes); // 1
      //! Get Font Size attribute
      bool_t (*FontSize) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T font_attributes); // 2
      //! Get Font Type attribute
      bool_t (*FontType) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T font_attributes); // 3
      //! Get Font Style attribute
      bool_t (*FontStyle) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T font_attributes); // 4
   } GetAttributeValue; //!< Get Attribute Command
} VTv4_FontAttributes_T;
/******************************************************************************/
// B.14.3 Line Attributes object
/******************************************************************************/
//! Type containing supported commands for a VTv4 Line Attributes object
typedef struct VTv4_LineAttributes_S
{
   //! Change Line Attributes command
   bool_t (*ChangeLineAttributes)(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T line_attributes, Colour_T colour, Pixel_T width, LineArt_T line_art, ObjectPool_ScaleFactor_T scaling_type);
   struct
   {
      //! Change Line Colour attribute
      bool_t (*LineColour) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T line_attributes, Colour_T colour); // 1
      //! Change Line Width attribute
      bool_t (*LineWidth) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T line_attributes, Pixel_T width); // 2
      //! Change Line Art attribute
      bool_t (*LineArt) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T line_attributes, LineArt_T line_art); // 3
   } ChangeAttribute; //!< Change Attribute command
   struct
   {
      //! Get Type attribute
      bool_t (*Type) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T line_attributes); // 0
      //! Get Line Colour attribute
      bool_t (*LineColour) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T line_attributes); // 1
      //! Get Line Width attribute
      bool_t (*LineWidth) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T line_attributes); // 2
      //! Get Line Art attribute
      bool_t (*LineArt) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T line_attributes); // 3
   } GetAttributeValue; //!< Get Attribute Command
} VTv4_LineAttributes_T;
/******************************************************************************/
// B.14.4 Fill Attributes object
/******************************************************************************/
//! Type containing supported commands for a VTv4 Fill Attributes object
typedef struct VTv4_FillAttributes_S
{
   //! Change Fill Attributes command
   bool_t (*ChangeFillAttributes)(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T fill_attributes, FillType_T type, Colour_T colour, ObjectID_T pattern_id);
   struct
   {
      //! Change Fill Type attribute
      bool_t (*FillType) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T fill_attributes, FillType_T type); // 1
      //! Change Fill Colour attribute
      bool_t (*FillColour) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T fill_attributes, Colour_T colour); // 2
      //! Change Fill Pattern attribute
      bool_t (*FillPattern) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T fill_attributes, ObjectID_T pattern_id); // 3
   } ChangeAttribute; //!< Change Attribute command
   struct
   {
      //! Get Type attribute
      bool_t (*Type) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T fill_attributes); // 0
      //! Get Fill Type attribute
      bool_t (*FillType) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T fill_attributes); // 1
      //! Get Fill Colour attribute
      bool_t (*FillColour) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T fill_attributes); // 2
      //! Get Fill Pattern attribute
      bool_t (*FillPattern) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T fill_attributes); // 3
   } GetAttributeValue; //!< Get Attribute Command
} VTv4_FillAttributes_T;
/******************************************************************************/
// B.14.5 Input Attributes object
/******************************************************************************/
//! Type containing supported commands for a VTv4 Input Attributes object
typedef struct VTv4_InputAttributes_S
{
   //! Change String Value command
   bool_t (*ChangeStringValue)(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_MessageCallback_T *callback, ObjectID_T input_attributes, Size_T string_length, const char *string);
   struct
   {
      //! Get Type attribute
      bool_t (*Type) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_attributes); // 0
      //! Get Validation Type attribute
      bool_t (*ValidationType)(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T input_attributes); // 1
   } GetAttributeValue; //!< Get Attribute Command
} VTv4_InputAttributes_T;
/******************************************************************************/
// B.14.6 Extended Input Attributes object
/******************************************************************************/
//! Type containing supported commands for a VTv4 Extended Input Attributes object
typedef struct VTv4_ExtendedInputAttributes_S
{
   struct
   {
      //! Get Type attribute
      bool_t (*Type) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T extended_input_attributes); // 0
      //! Get Validation Type attribute
      bool_t (*ValidationType)(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T extended_input_attributes); // 1
   } GetAttributeValue; //!< Get Attribute Command
} VTv4_ExtendedInputAttributes_T;
/******************************************************************************/
// B.15 Object Pointer object
/******************************************************************************/
//! Type containing supported commands for a VTv4 Object Pointer object
typedef struct VTv4_ObjectPointer_S
{
   //! Change Numeric Value command
   bool_t (*ChangeNumericValue)(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T object_pointer, NumericValue_T value);
   struct
   {
      //! Get Type attribute
      bool_t (*Type) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T object_pointer); // 0
      //! Get Value attribute
      bool_t (*Value) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T object_pointer); // 1
   } GetAttributeValue; //!< Get Attribute Command
} VTv4_ObjectPointer_T;
/******************************************************************************/
// B.16 Macro object
/******************************************************************************/
//! Type containing supported commands for a VTv4 Macro object
typedef struct VTv4_Macro_S
{
   //! Execute Macro command
   bool_t (*ExecuteMacro)(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, MacroID_T macro);
   struct
   {
      //! Get Type attribute
      bool_t (*Type) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T macro); // 0
   } GetAttributeValue; //!< Get Attribute Command
} VTv4_Macro_T;
/******************************************************************************/
// B.17 Colour Map object
/******************************************************************************/
//! Type containing supported commands for a VTv4 Colour Map object
typedef struct VTv4_ColourMap_S
{
   //! Select Colour Map command
   bool_t (*SelectColourMap)(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T colour_map);
   struct
   {
      //! Get Type attribute
      bool_t (*Type) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T colour_map); // 0
   } GetAttributeValue; //!< Get Attribute Command
} VTv4_ColourMap_T;
/******************************************************************************/
// B.18 Graphics Context object
/******************************************************************************/
//! Graphics Context options
typedef uint8_t GraphicsContextOptions_T;
//! \brief    Graphics Context options bit 0:  Transparency
//! \details  0 = Opaque
//!           1 = Transparent.  If opaque, all pixels are drawn in indicated
//!               colour.  Background objects do not show through.  If
//!               transparent, pixels in the bitmap that have the transparency
//!               colour should show the colour of the background or objects
//!               underneath this object instead.
#define GRAPHICS_CONTEXT_OPTIONS_TRANSPARENT ((GraphicsContextOptions_T)0x01)
//! \brief    Graphics Context options bit 1:  Colour
//! \details  0 = Use Foreground and Background Colours of this object when drawing.
//!           1 = Use Line Colour, Font Colour and Fill Colour, specified in the
//!               Line, Font, and Fill attributes when drawing.
#define GRAPHICS_CONTEXT_OPTIONS_USE_ATTRIBUTE_COLOURS ((GraphicsContextOptions_T)0x02)
//! Type containing supported commands for a VTv4 Graphics Context object
typedef struct VTv4_GraphicsContext_S
{
   struct
   {
      //! Graphics Context - Set Graphics Cursor subcommand
      bool_t (*SetGraphicsCursor) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T graphics_context, Pixel_T x_position, Pixel_T y_position);
      //! Graphics Context - Move Graphics Cursor subcommand
      bool_t (*MoveGraphicsCursor) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T graphics_context, Pixel_T x_offset, Pixel_T y_offset);
      //! Graphics Context - Set Foreground Colour subcommand
      bool_t (*SetForegroundColour) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T graphics_context, Colour_T colour);
      //! Graphics Context - Set Background Colour subcommand
      bool_t (*SetBackgroundColour) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T graphics_context, Colour_T colour);
      //! Graphics Context - Set Line Attributes subcommand
      bool_t (*SetLineAttributes) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T graphics_context, ObjectID_T line_attributes);
      //! Graphics Context - Set Fill Attributes subcommand
      bool_t (*SetFillAttributes) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T graphics_context, ObjectID_T fill_attributes);
      //! Graphics Context - Set Font Attributes subcommand
      bool_t (*SetFontAttributes) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T graphics_context, ObjectID_T font_attributes);
      //! Graphics Context - Erase Rectangle subcommand
      bool_t (*EraseRectangle) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T graphics_context, Pixel_T width, Pixel_T height);
      //! Graphics Context - Draw Point subcommand
      bool_t (*DrawPoint) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T graphics_context, Pixel_T x_offset, Pixel_T y_offset);
      //! Graphics Context - Draw Line subcommand
      bool_t (*DrawLine) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T graphics_context, Pixel_T x_offset, Pixel_T y_offset);
      //! Graphics Context - Draw Rectangle subcommand
      bool_t (*DrawRectangle) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T graphics_context, Pixel_T width, Pixel_T height);
      //! Graphics Context - Draw Closed Ellipse subcommand
      bool_t (*DrawClosedEllipse) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T graphics_context, Pixel_T width, Pixel_T height);
   //   //! Graphics Context - Draw Polygon subcommand
   //   bool_t (*DrawPolygon)                 (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T graphics_context);
   //   //! Graphics Context - Draw Text subcommand
   //   bool_t (*DrawText)                    (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T graphics_context);
      //! Graphics Context - Pan Viewport subcommand
      bool_t (*PanViewport) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T graphics_context, Pixel_T viewport_x, Pixel_T viewport_y);
      //! Graphics Context - Zoom Viewport subcommand
      bool_t (*ZoomViewport) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T graphics_context, GraphicsZoom_T zoom, ObjectPool_ScaleFactor_T scaling_type);
      //! Graphics Context - Pan and Zoom Viewport subcommand
      bool_t (*PanAndZoomViewport) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T graphics_context, Pixel_T viewport_x, Pixel_T viewport_y, GraphicsZoom_T zoom, ObjectPool_ScaleFactor_T scaling_type);
      //! Graphics Context - Change Viewport Size subcommand
      bool_t (*ChangeViewportSize) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T graphics_context, Pixel_T width, Pixel_T height, ObjectPool_ScaleFactor_T scaling_type);
      //! Graphics Context - Draw VT Object subcommand
      bool_t (*DrawVtObject) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T graphics_context, ObjectID_T object_to_draw);
      //! Graphics Context - Copy Canvas to Picture Graphic subcommand
      bool_t (*CopyCanvasToPictureGraphic) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T graphics_context, ObjectID_T picture_graphic);
      //! Graphics Context - Copy Viewport to Picture Graphic subcommand
      bool_t (*CopyViewportToPictureGraphic)(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T graphics_context, ObjectID_T picture_graphic);
   } GraphicsContext_Command; //!< Graphics Context command
   //! Change Background Colour command
   bool_t (*ChangeBackgroundColour) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T graphics_context, Colour_T background_colour);
   struct
   {
      //! Change Viewport Width attribute
      bool_t (*ViewportWidth) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T graphics_context, Pixel_T viewport_width); // 1
      //! Change Viewport Height attribute
      bool_t (*ViewportHeight) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T graphics_context, Pixel_T viewport_height); // 2
      //! Change Viewport X attribute
      bool_t (*ViewportX) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T graphics_context, Pixel_T viewport_x); // 3
      //! Change Viewport Y attribute
      bool_t (*ViewportY) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T graphics_context, Pixel_T viewport_y); // 4
      //! Change Viewport Zoom attribute
      bool_t (*ViewportZoom) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T graphics_context, GraphicsZoom_T zoom); // 7
      //! Change Graphics Cursor X attribute
      bool_t (*GraphicsCursorX) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T graphics_context, Pixel_T cursor_x); // 8
      //! Change Graphics Cursor Y attribute
      bool_t (*GraphicsCursorY) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T graphics_context, Pixel_T cursor_y); // 9
      //! Change Foreground Colour attribute
      bool_t (*ForegroundColour) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T graphics_context, Colour_T foreground_colour); // 10
      //! Change Background Colour attribute
      bool_t (*BackgroundColour) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T graphics_context, Colour_T background_colour); // 11
      //! Change Font Attributes Object attribute
      bool_t (*FontAttributesObject)(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T graphics_context, ObjectID_T font_attributes); // 12
      //! Change Line Attributes Object attribute
      bool_t (*LineAttributesObject)(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T graphics_context, ObjectID_T line_attributes); // 13
      //! Change Fill Attributes Object attribute
      bool_t (*FillAttributesObject)(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T graphics_context, ObjectID_T fill_attributes); // 14
      //! Change Format attribute
      bool_t (*Format) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T graphics_context, VT_GraphicType_T format); // 15
      //! Change Options attribute
      bool_t (*Options) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T graphics_context, GraphicsContextOptions_T options); // 16
      //! Change Transparency Colour attribute
      bool_t (*TransparencyColour) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T graphics_context, Colour_T transparency_colour); // 17
   } ChangeAttribute; //!< Change Attribute command
   struct
   {
      //! Get Type attribute
      bool_t (*Type) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T graphics_context); // 0
      //! Get Viewport Width attribute
      bool_t (*ViewportWidth) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T graphics_context); // 1
      //! Get Viewport Height attribute
      bool_t (*ViewportHeight) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T graphics_context); // 2
      //! Get Viewport X attribute
      bool_t (*ViewportX) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T graphics_context); // 3
      //! Get Viewport Y attribute
      bool_t (*ViewportY) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T graphics_context); // 4
      //! Get Canvas Width attribute
      bool_t (*CanvasWidth) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T graphics_context); // 5
      //! Get Canvas Height attribute
      bool_t (*CanvasHeight) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T graphics_context); // 6
      //! Get Viewport Zoom attribute
      bool_t (*ViewportZoom) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T graphics_context); // 7
      //! Get Graphics Cursor X attribute
      bool_t (*GraphicsCursorX) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T graphics_context); // 8
      //! Get Graphics Cursor Y attribute
      bool_t (*GraphicsCursorY) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T graphics_context); // 9
      //! Get Foreground Colour attribute
      bool_t (*ForegroundColour) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T graphics_context); // 10
      //! Get Background Colour attribute
      bool_t (*BackgroundColour) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T graphics_context); // 11
      //! Get Font Attributes Object attribute
      bool_t (*FontAttributesObject)(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T graphics_context); // 12
      //! Get Line Attributes Object attribute
      bool_t (*LineAttributesObject)(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T graphics_context); // 13
      //! Get Fill Attributes Object attribute
      bool_t (*FillAttributesObject)(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T graphics_context); // 14
      //! Get Format attribute
      bool_t (*Format) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T graphics_context); // 15
      //! Get Options attribute
      bool_t (*Options) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T graphics_context); // 16
      //! Get Transparency Colour attribute
      bool_t (*TransparencyColour) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T graphics_context); // 17
   } GetAttributeValue; //!< Get Attribute Command
} VTv4_GraphicsContext_T;
/******************************************************************************/
// B.19 Window Mask object
/******************************************************************************/
//! Type containing supported commands for a VTv4 Window Mask object
typedef struct VTv4_WindowMask_S
{
   //! Change Background Colour command
   bool_t (*ChangeBackgroundColour)(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T window_mask, Colour_T background_colour);
   //! Change Child Location command (Relative Position)
   bool_t (*ChangeChildLocation) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T window_mask, ObjectID_T child, Pixel_T change_x_position, Pixel_T change_y_position);
   //! Change Child Position command (Absolute Position)
   bool_t (*ChangeChildPosition) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_MessageCallback_T *callback, ObjectID_T window_mask, ObjectID_T child, Pixel_T new_x_position, Pixel_T new_y_position);
   //! Lock Unlock Mask command
   bool_t (*LockUnlockMask) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, MaskCommand_T command, ObjectID_T object_id, Time_T timeout);
   struct
   {
      //! Change Background Colour attribute
      bool_t (*BackgroundColour) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T window_mask, Colour_T background_colour); // 1
      //! Change Options attribute
      bool_t (*Options) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T window_mask, WindowMaskOptions_T options); // 2
      //! Change Name attribute
      bool_t (*Name) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T window_mask, ObjectID_T name); // 3
   } ChangeAttribute; //!< Change Attribute command
   struct
   {
      //! Get Type attribute
      bool_t (*Type) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T window_mask); // 0
      //! Get Background Colour attribute
      bool_t (*BackgroundColour) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T window_mask); // 1
      //! Get Options attribute
      bool_t (*Options) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T window_mask); // 2
      //! Get Name attribute
      bool_t (*Name) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T window_mask); // 3
   } GetAttributeValue; //!< Get Attribute Command
} VTv4_WindowMask_T;
/******************************************************************************/
// B.20 Key Group object
/******************************************************************************/
//! Type containing supported commands for a VTv4 Key Group object
typedef struct VTv4_KeyGroup_S
{
   struct
   {
      //! Change Options attribute
      bool_t (*Options)(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T key_group, KeyGroupOptions_T options); // 1
      //! Change Name attribute
      bool_t (*Name) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T key_group, ObjectID_T name); // 2
   } ChangeAttribute; //!< Change Attribute command
   struct
   {
      //! Get Type attribute
      bool_t (*Type) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T key_group); // 0
      //! Get Options attribute
      bool_t (*Options)(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T key_group); // 1
      //! Get Name attribute
      bool_t (*Name) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T key_group); // 2
   } GetAttributeValue; //!< Get Attribute Command
} VTv4_KeyGroup_T;
/******************************************************************************/
// B.21 Object Label Reference List object
/******************************************************************************/
//! Type containing supported commands for a VTv4 Object Label Reference List object
typedef struct VTv4_ObjectLabelReferenceList_S
{
   //! Change Object Label command
   bool_t (*ChangeObjectLabel) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T object_label_reference_list, ObjectID_T string_obj_id, FontType_T font_type, ObjectID_T graphic_obj_id);
   struct
   {
      //! Get Type attribute
      bool_t (*Type) (const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T object_label_reference_list); // 0
      //! Get Number of Labelled Objects attribute
      bool_t (*NumberOfLabelledObjects)(const VTClient_T *vt_client, const VT_T *vt, const ISOBUS_Callback_T *callback, ObjectID_T object_label_reference_list); // 1
   } GetAttributeValue; //!< Get Attribute Command
} VTv4_ObjectLabelReferenceList_T;
//! Type containing all supported objects/commands for VTv4
typedef struct
{
   //! Working Set object commands
   VTv4_WorkingSet_T WorkingSet;
   //! Data Mask object commands
   VTv4_DataMask_T DataMask;
   //! Alarm Mask object commands
   VTv4_AlarmMask_T AlarmMask;
   //! Container object commands
   VTv4_Container_T Container;
   //! Soft Key Mask object commands
   VTv4_SoftKeyMask_T SoftKeyMask;
   //! Key object commands
   VTv4_Key_T Key;
   //! Button object commands
   VTv4_Button_T Button;
   //! Input Boolean object commands
   VTv4_InputBoolean_T InputBoolean;
   //! Input String object commands
   VTv4_InputString_T InputString;
   //! Input Number object commands
   VTv4_InputNumber_T InputNumber;
   //! Input List object commands
   VTv4_InputList_T InputList;
   //! Output String object commands
   VTv4_OutputString_T OutputString;
   //! Output Number object commands
   VTv4_OutputNumber_T OutputNumber;
   //! Output List object commands
   VTv4_OutputList_T OutputList;
   //! Line object commands
   VTv4_Line_T Line;
   //! Rectangle object commands
   VTv4_Rectangle_T Rectangle;
   //! Ellipse object commands
   VTv4_Ellipse_T Ellipse;
   //! Polygon object commands
   VTv4_Polygon_T Polygon;
   //! Meter object commands
   VTv4_Meter_T Meter;
   //! Linear Bar Graph object commands
   VTv4_LinearBarGraph_T LinearBarGraph;
   //! Arched Bar Graph object commands
   VTv4_ArchedBarGraph_T ArchedBarGraph;
   //! Picture Graphic object commands
   VTv4_PictureGraphic_T PictureGraphic;
   //! Number Variable object commands
   VTv4_NumberVariable_T NumberVariable;
   //! String Variable object commands
   VTv4_StringVariable_T StringVariable;
   //! Font Attributes object commands
   VTv4_FontAttributes_T FontAttributes;
   //! Line Attributes object commands
   VTv4_LineAttributes_T LineAttributes;
   //! Fill Attributes object commands
   VTv4_FillAttributes_T FillAttributes;
   //! Input Attributes object commands
   VTv4_InputAttributes_T InputAttributes;
   //! Extended Input Attributes object commands
   VTv4_ExtendedInputAttributes_T ExtendedInputAttributes;
   //! Object Pointer object commands
   VTv4_ObjectPointer_T ObjectPointer;
   //! Macro object commands
   VTv4_Macro_T Macro;
   //! Colour Map object commands
   VTv4_ColourMap_T ColourMap;
   //! Graphics Context object commands
   VTv4_GraphicsContext_T GraphicsContext;
   //! Window Mask object commands
   VTv4_WindowMask_T WindowMask;
   //! Key Group object commands
   VTv4_KeyGroup_T KeyGroup;
   //! Object Label Reference List object commands
   VTv4_ObjectLabelReferenceList_T ObjectLabelReferenceList;
} VTv4_T;
//! Structure containing all supported objects/commands for VTv4
extern const VTv4_T VTv4;
//! \cond SKIP
/******************************************************************************/
// B.1 Working Set object
/******************************************************************************/
#define VTv4_WorkingSet_ChangeActiveMask ChangeActiveMask_Command
#define VTv4_WorkingSet_ChangeBackgroundColour ChangeBackgroundColour_Command
#define VTv4_WorkingSet_ChangeChildLocation ChangeChildLocation_Command_Scaled_SoftkeyMask
#define VTv4_WorkingSet_ChangeChildPosition ChangeChildPosition_Command_Scaled_SoftkeyMask
#define VTv4_WorkingSet_GetAttributeValue_Type(vt_client,vt,working_set) GetAttributeValue_Message(vt_client,vt,working_set,0)
#define VTv4_WorkingSet_GetAttributeValue_BackgroundColour(vt_client,vt,working_set) GetAttributeValue_Message(vt_client,vt,working_set,1)
#define VTv4_WorkingSet_GetAttributeValue_Selectable(vt_client,vt,working_set) GetAttributeValue_Message(vt_client,vt,working_set,2)
#define VTv4_WorkingSet_GetAttributeValue_ActiveMask(vt_client,vt,working_set) GetAttributeValue_Message(vt_client,vt,working_set,3)
/******************************************************************************/
// B.2 Data Mask object
/******************************************************************************/
#define VTv4_DataMask_ChangeBackgroundColour ChangeBackgroundColour_Command
#define VTv4_DataMask_ChangeChildLocation ChangeChildLocation_Command_Scaled_DataMask
#define VTv4_DataMask_ChangeChildPosition ChangeChildPosition_Command_Scaled_DataMask
#define VTv4_DataMask_ChangeSoftKeyMask ChangeSoftKeyMask_Command
#define VTv4_DataMask_LockUnlockMask LockUnlockMask_Command
#define VTv4_DataMask_ChangeAttribute_BackgroundColour(vt_client,vt,data_mask,background_colour) ChangeAttribute_Command (vt_client,vt,data_mask,CAST(AttributeValue_T,background_colour),1)
#define VTv4_DataMask_ChangeAttribute_SoftKeyMask(vt_client,vt,data_mask,soft_key_mask) ChangeAttribute_Command (vt_client,vt,data_mask,CAST(AttributeValue_T,soft_key_mask),2)
#define VTv4_DataMask_GetAttributeValue_Type(vt_client,vt,data_mask) GetAttributeValue_Message(vt_client,vt,data_mask,0)
#define VTv4_DataMask_GetAttributeValue_BackgroundColour(vt_client,vt,data_mask) GetAttributeValue_Message(vt_client,vt,data_mask,1)
#define VTv4_DataMask_GetAttributeValue_SoftKeyMask(vt_client,vt,data_mask) GetAttributeValue_Message(vt_client,vt,data_mask,2)
/******************************************************************************/
// B.3 Alarm Mask object
/******************************************************************************/
#define VTv4_AlarmMask_ChangeBackgroundColour ChangeBackgroundColour_Command
#define VTv4_AlarmMask_ChangeChildLocation ChangeChildLocation_Command_Scaled_DataMask
#define VTv4_AlarmMask_ChangeChildPosition ChangeChildPosition_Command_Scaled_DataMask
#define VTv4_AlarmMask_ChangePriority ChangePriority_Command
#define VTv4_AlarmMask_ChangeSoftKeyMask ChangeSoftKeyMask_Command
#define VTv4_AlarmMask_ChangeAttribute_BackgroundColour(vt_client,vt,alarm_mask,background_colour) ChangeAttribute_Command (vt_client,vt,alarm_mask,CAST(AttributeValue_T,background_colour),1)
#define VTv4_AlarmMask_ChangeAttribute_SoftKeyMask(vt_client,vt,alarm_mask,soft_key_mask) ChangeAttribute_Command (vt_client,vt,alarm_mask,CAST(AttributeValue_T,soft_key_mask),2)
#define VTv4_AlarmMask_ChangeAttribute_Priority(vt_client,vt,alarm_mask,priority) ChangeAttribute_Command (vt_client,vt,alarm_mask,CAST(AttributeValue_T,priority),3)
#define VTv4_AlarmMask_ChangeAttribute_AcousticSignal(vt_client,vt,alarm_mask,acoustic_signal) ChangeAttribute_Command (vt_client,vt,alarm_mask,CAST(AttributeValue_T,acoustic_signal),4)
#define VTv4_AlarmMask_GetAttributeValue_Type(vt_client,vt,alarm_mask) GetAttributeValue_Message(vt_client,vt,alarm_mask,0)
#define VTv4_AlarmMask_GetAttributeValue_BackgroundColour(vt_client,vt,alarm_mask) GetAttributeValue_Message(vt_client,vt,alarm_mask,1)
#define VTv4_AlarmMask_GetAttributeValue_SoftKeyMask(vt_client,vt,alarm_mask) GetAttributeValue_Message(vt_client,vt,alarm_mask,2)
#define VTv4_AlarmMask_GetAttributeValue_Priority(vt_client,vt,alarm_mask) GetAttributeValue_Message(vt_client,vt,alarm_mask,3)
#define VTv4_AlarmMask_GetAttributeValue_AcousticSignal(vt_client,vt,alarm_mask) GetAttributeValue_Message(vt_client,vt,alarm_mask,4)
/******************************************************************************/
// B.4 Container object
/******************************************************************************/
#define VTv4_Container_HideShowObject HideShowObject_Command
#define VTv4_Container_ChangeChildLocation ChangeChildLocation_Command_Scaled
#define VTv4_Container_ChangeChildPosition ChangeChildPosition_Command_Scaled
#define VTv4_Container_ChangeSize ChangeSize_Command_Scaled
#define VTv4_Container_GetAttributeValue_Type(vt_client,vt,container) GetAttributeValue_Message(vt_client,vt,container,0)
#define VTv4_Container_GetAttributeValue_Width(vt_client,vt,container) GetAttributeValue_Message(vt_client,vt,container,1)
#define VTv4_Container_GetAttributeValue_Height(vt_client,vt,container) GetAttributeValue_Message(vt_client,vt,container,2)
#define VTv4_Container_GetAttributeValue_Hidden(vt_client,vt,container) GetAttributeValue_Message(vt_client,vt,container,3)
/******************************************************************************/
// B.5 Soft Key Mask object
/******************************************************************************/
#define VTv4_SoftKeyMask_ChangeBackgroundColour ChangeBackgroundColour_Command
#define VTv4_SoftKeyMask_ChangeAttribute_BackgroundColour(vt_client,vt,soft_key_mask,background_colour) ChangeAttribute_Command (vt_client,vt,soft_key_mask,CAST(AttributeValue_T,background_colour),1)
#define VTv4_SoftKeyMask_GetAttributeValue_Type(vt_client,vt,soft_key_mask) GetAttributeValue_Message(vt_client,vt,soft_key_mask,0)
#define VTv4_SoftKeyMask_GetAttributeValue_BackgroundColour(vt_client,vt,soft_key_mask) GetAttributeValue_Message(vt_client,vt,soft_key_mask,1)
/******************************************************************************/
// B.6 Key object
/******************************************************************************/
#define VTv4_Key_SelectInputObject SelectInputObject_Command
#define VTv4_Key_ChangeBackgroundColour ChangeBackgroundColour_Command
#define VTv4_Key_ChangeChildLocation ChangeChildLocation_Command_Scaled_SoftKeyMask
#define VTv4_Key_ChangeChildPosition ChangeChildPosition_Command_Scaled_SoftKeyMask
#define VTv4_Key_ChangeAttribute_BackgroundColour(vt_client,vt,key,background_colour) ChangeAttribute_Command (vt_client,vt,key,CAST(AttributeValue_T,background_colour),1)
#define VTv4_Key_ChangeAttribute_KeyCode(vt_client,vt,key,key_code) ChangeAttribute_Command (vt_client,vt,key,CAST(AttributeValue_T,key_code) ,2)
#define VTv4_Key_GetAttributeValue_Type(vt_client,vt,key) GetAttributeValue_Message(vt_client,vt,key,0)
#define VTv4_Key_GetAttributeValue_BackgroundColour(vt_client,vt,key) GetAttributeValue_Message(vt_client,vt,key,1)
#define VTv4_Key_GetAttributeValue_KeyCode(vt_client,vt,key) GetAttributeValue_Message(vt_client,vt,key,2)
/******************************************************************************/
// B.7 Button object
/******************************************************************************/
#define VTv4_Button_EnableDisableObject EnableDisableObject_Command
#define VTv4_Button_SelectInputObject SelectInputObject_Command
#define VTv4_Button_ChangeBackgroundColour ChangeBackgroundColour_Command
#define VTv4_Button_ChangeSize ChangeSize_Command_Scaled_DataMask
#define VTv4_Button_ChangeChildLocation ChangeChildLocation_Command_Scaled_DataMask
#define VTv4_Button_ChangeChildPosition ChangeChildPosition_Command_Scaled_DataMask
#define VTv4_Button_ChangeAttribute_Width(vt_client,vt,button,width) ChangeAttribute_Command (vt_client,vt,button,CAST(AttributeValue_T,width) ,1)
#define VTv4_Button_ChangeAttribute_Height(vt_client,vt,button,height) ChangeAttribute_Command (vt_client,vt,button,CAST(AttributeValue_T,height) ,2)
#define VTv4_Button_ChangeAttribute_BackgroundColour(vt_client,vt,button,background_colour) ChangeAttribute_Command (vt_client,vt,button,CAST(AttributeValue_T,background_colour),3)
#define VTv4_Button_ChangeAttribute_BorderColour(vt_client,vt,button,border_colour) ChangeAttribute_Command (vt_client,vt,button,CAST(AttributeValue_T,border_colour) ,4)
#define VTv4_Button_ChangeAttribute_KeyCode(vt_client,vt,button,key_code) ChangeAttribute_Command (vt_client,vt,button,CAST(AttributeValue_T,key_code) ,5)
#define VTv4_Button_ChangeAttribute_Options(vt_client,vt,button,options) ChangeAttribute_Command (vt_client,vt,button,CAST(AttributeValue_T,options) ,6)
#define VTv4_Button_GetAttributeValue_Type(vt_client,vt,button) GetAttributeValue_Message(vt_client,vt,button,0)
#define VTv4_Button_GetAttributeValue_Width(vt_client,vt,button) GetAttributeValue_Message(vt_client,vt,button,1)
#define VTv4_Button_GetAttributeValue_Height(vt_client,vt,button) GetAttributeValue_Message(vt_client,vt,button,2)
#define VTv4_Button_GetAttributeValue_BackgroundColour(vt_client,vt,button) GetAttributeValue_Message(vt_client,vt,button,3)
#define VTv4_Button_GetAttributeValue_BorderColour(vt_client,vt,button) GetAttributeValue_Message(vt_client,vt,button,4)
#define VTv4_Button_GetAttributeValue_KeyCode(vt_client,vt,button) GetAttributeValue_Message(vt_client,vt,button,5)
#define VTv4_Button_GetAttributeValue_Options(vt_client,vt,button) GetAttributeValue_Message(vt_client,vt,button,6)
/******************************************************************************/
// B.8 Input field objects
/******************************************************************************/
/******************************************************************************/
// B.8.2 Input Boolean object
/******************************************************************************/
#define VTv4_InputBoolean_EnableDisableObject EnableDisableObject_Command
#define VTv4_InputBoolean_SelectInputObject SelectInputObject_Command
#define VTv4_InputBoolean_ESC Esc_Command
#define VTv4_InputBoolean_ChangeBackgroundColour ChangeBackgroundColour_Command
#define VTv4_InputBoolean_ChangeNumericValue ChangeNumericValue_Command
#define VTv4_InputBoolean_ChangeSize ChangeSize_Command_Scaled_DataMask
#define VTv4_InputBoolean_ChangeAttribute_BackgroundColour(vt_client,vt,input_boolean,background_colour) ChangeAttribute_Command (vt_client,vt,input_boolean,CAST(AttributeValue_T,background_colour),1)
#define VTv4_InputBoolean_ChangeAttribute_Width(vt_client,vt,input_boolean,width) ChangeAttribute_Command (vt_client,vt,input_boolean,CAST(AttributeValue_T,width) ,2)
#define VTv4_InputBoolean_ChangeAttribute_ForegroundColour(vt_client,vt,input_boolean,foreground_colour) ChangeAttribute_Command (vt_client,vt,input_boolean,CAST(AttributeValue_T,foreground_colour),3)
#define VTv4_InputBoolean_ChangeAttribute_VariableReference(vt_client,vt,input_boolean,variable) ChangeAttribute_Command (vt_client,vt,input_boolean,CAST(AttributeValue_T,variable) ,4)
#define VTv4_InputBoolean_GetAttributeValue_Type(vt_client,vt,input_boolean) GetAttributeValue_Message(vt_client,vt,input_boolean,0)
#define VTv4_InputBoolean_GetAttributeValue_BackgroundColour(vt_client,vt,input_boolean) GetAttributeValue_Message(vt_client,vt,input_boolean,1)
#define VTv4_InputBoolean_GetAttributeValue_Width(vt_client,vt,input_boolean) GetAttributeValue_Message(vt_client,vt,input_boolean,2)
#define VTv4_InputBoolean_GetAttributeValue_ForegroundColour(vt_client,vt,input_boolean) GetAttributeValue_Message(vt_client,vt,input_boolean,3)
#define VTv4_InputBoolean_GetAttributeValue_VariableReference(vt_client,vt,input_boolean) GetAttributeValue_Message(vt_client,vt,input_boolean,4)
#define VTv4_InputBoolean_GetAttributeValue_Value(vt_client,vt,input_boolean) GetAttributeValue_Message(vt_client,vt,input_boolean,5)
#define VTv4_InputBoolean_GetAttributeValue_Enabled(vt_client,vt,input_boolean) GetAttributeValue_Message(vt_client,vt,input_boolean,6)
/******************************************************************************/
// B.8.3 Input String object
/******************************************************************************/
#define VTv4_InputString_EnableDisableObject EnableDisableObject_Command
#define VTv4_InputString_SelectInputObject SelectInputObject_Command
#define VTv4_InputString_ESC ESC_Command
#define VTv4_InputString_ChangeBackgroundColour ChangeBackgroundColour_Command
#define VTv4_InputString_ChangeStringValue ChangeStringValue_Command
#define VTv4_InputString_ChangeSize ChangeSize_Command_Scaled_DataMask
#define VTv4_InputString_ChangeAttribute_Width(vt_client,vt,input_string,width) ChangeAttribute_Command (vt_client,vt,input_string,CAST(AttributeValue_T,width) ,1)
#define VTv4_InputString_ChangeAttribute_Height(vt_client,vt,input_string,height) ChangeAttribute_Command (vt_client,vt,input_string,CAST(AttributeValue_T,height) ,2)
#define VTv4_InputString_ChangeAttribute_BackgroundColour(vt_client,vt,input_string,background_colour) ChangeAttribute_Command (vt_client,vt,input_string,CAST(AttributeValue_T,background_colour),3)
#define VTv4_InputString_ChangeAttribute_FontAttributes(vt_client,vt,input_string,font_attributes) ChangeAttribute_Command (vt_client,vt,input_string,CAST(AttributeValue_T,font_attributes) ,4)
#define VTv4_InputString_ChangeAttribute_InputAttributes(vt_client,vt,input_string,input_attributes) ChangeAttribute_Command (vt_client,vt,input_string,CAST(AttributeValue_T,input_attributes) ,5)
#define VTv4_InputString_ChangeAttribute_Options(vt_client,vt,input_string,options) ChangeAttribute_Command (vt_client,vt,input_string,CAST(AttributeValue_T,options) ,6)
#define VTv4_InputString_ChangeAttribute_VariableReference(vt_client,vt,input_string,variable) ChangeAttribute_Command (vt_client,vt,input_string,CAST(AttributeValue_T,variable) ,7)
#define VTv4_InputString_ChangeAttribute_Justification(vt_client,vt,input_string,justification) ChangeAttribute_Command (vt_client,vt,input_string,CAST(AttributeValue_T,justification) ,8)
#define VTv4_InputString_GetAttributeValue_Type(vt_client,vt,input_string) GetAttributeValue_Message(vt_client,vt,input_string,0)
#define VTv4_InputString_GetAttributeValue_Width(vt_client,vt,input_string) GetAttributeValue_Message(vt_client,vt,input_string,1)
#define VTv4_InputString_GetAttributeValue_Height(vt_client,vt,input_string) GetAttributeValue_Message(vt_client,vt,input_string,2)
#define VTv4_InputString_GetAttributeValue_BackgroundColour(vt_client,vt,input_string) GetAttributeValue_Message(vt_client,vt,input_string,3)
#define VTv4_InputString_GetAttributeValue_FontAttributes(vt_client,vt,input_string) GetAttributeValue_Message(vt_client,vt,input_string,4)
#define VTv4_InputString_GetAttributeValue_InputAttributes(vt_client,vt,input_string) GetAttributeValue_Message(vt_client,vt,input_string,5)
#define VTv4_InputString_GetAttributeValue_Options(vt_client,vt,input_string) GetAttributeValue_Message(vt_client,vt,input_string,6)
#define VTv4_InputString_GetAttributeValue_VariableReference(vt_client,vt,input_string) GetAttributeValue_Message(vt_client,vt,input_string,7)
#define VTv4_InputString_GetAttributeValue_Justification(vt_client,vt,input_string) GetAttributeValue_Message(vt_client,vt,input_string,8)
#define VTv4_InputString_GetAttributeValue_Enabled(vt_client,vt,input_string) GetAttributeValue_Message(vt_client,vt,input_string,9)
/******************************************************************************/
// B.8.4 Input Number object
/******************************************************************************/
#define VTv4_InputNumber_EnableDisableObject EnableDisableObject_Command
#define VTv4_InputNumber_SelectInputObject SelectInputObject_Command
#define VTv4_InputNumber_ESC ESC_Command
#define VTv4_InputNumber_ChangeBackgroundColour ChangeBackgroundColour_Command
#define VTv4_InputNumber_ChangeNumericValue ChangeNumericValue_Command
#define VTv4_InputNumber_ChangeSize ChangeSize_Command_Scaled_DataMask
#define VTv4_InputNumber_ChangeAttribute_Width(vt_client,vt,input_number,width) ChangeAttribute_Command (vt_client,vt,input_number,CAST(AttributeValue_T,width) , 1)
#define VTv4_InputNumber_ChangeAttribute_Height(vt_client,vt,input_number,height) ChangeAttribute_Command (vt_client,vt,input_number,CAST(AttributeValue_T,height) , 2)
#define VTv4_InputNumber_ChangeAttribute_BackgroundColour(vt_client,vt,input_number,background_colour) ChangeAttribute_Command (vt_client,vt,input_number,CAST(AttributeValue_T,background_colour) , 3)
#define VTv4_InputNumber_ChangeAttribute_FontAttributes(vt_client,vt,input_number,font_attributes) ChangeAttribute_Command (vt_client,vt,input_number,CAST(AttributeValue_T,font_attributes) , 4)
#define VTv4_InputNumber_ChangeAttribute_Options(vt_client,vt,input_number,options) ChangeAttribute_Command (vt_client,vt,input_number,CAST(AttributeValue_T,options) , 5)
#define VTv4_InputNumber_ChangeAttribute_VariableReference(vt_client,vt,input_number,variable) ChangeAttribute_Command (vt_client,vt,input_number,CAST(AttributeValue_T,variable) , 6)
#define VTv4_InputNumber_ChangeAttribute_MinimumValue(vt_client,vt,input_number,minimum_value) ChangeAttribute_Command (vt_client,vt,input_number,CAST(AttributeValue_T,minimum_value) , 7)
#define VTv4_InputNumber_ChangeAttribute_MaximumValue(vt_client,vt,input_number,maximum_value) ChangeAttribute_Command (vt_client,vt,input_number,CAST(AttributeValue_T,maximum_value) , 8)
#define VTv4_InputNumber_ChangeAttribute_Offset(vt_client,vt,input_number,offset) ChangeAttribute_Command (vt_client,vt,input_number,CAST(AttributeValue_T,offset) , 9)
#define VTv4_InputNumber_ChangeAttribute_Scale(vt_client,vt,input_number,scale) ChangeAttribute_Command (vt_client,vt,input_number,CAST(AttributeValue_T,scale) ,10)
#define VTv4_InputNumber_ChangeAttribute_NumberOfDecimals(vt_client,vt,input_number,number_of_decimals) ChangeAttribute_Command (vt_client,vt,input_number,CAST(AttributeValue_T,number_of_decimals),11)
#define VTv4_InputNumber_ChangeAttribute_Format(vt_client,vt,input_number,format) ChangeAttribute_Command (vt_client,vt,input_number,CAST(AttributeValue_T,format) ,12)
#define VTv4_InputNumber_ChangeAttribute_Justification(vt_client,vt,input_number,justification) ChangeAttribute_Command (vt_client,vt,input_number,CAST(AttributeValue_T,justification) ,13)
#define VTv4_InputNumber_GetAttributeValue_Type(vt_client,vt,input_number) GetAttributeValue_Message(vt_client,vt,input_number, 0)
#define VTv4_InputNumber_GetAttributeValue_Width(vt_client,vt,input_number) GetAttributeValue_Message(vt_client,vt,input_number, 1)
#define VTv4_InputNumber_GetAttributeValue_Height(vt_client,vt,input_number) GetAttributeValue_Message(vt_client,vt,input_number, 2)
#define VTv4_InputNumber_GetAttributeValue_BackgroundColour(vt_client,vt,input_number) GetAttributeValue_Message(vt_client,vt,input_number, 3)
#define VTv4_InputNumber_GetAttributeValue_FontAttributes(vt_client,vt,input_number) GetAttributeValue_Message(vt_client,vt,input_number, 4)
#define VTv4_InputNumber_GetAttributeValue_Options(vt_client,vt,input_number) GetAttributeValue_Message(vt_client,vt,input_number, 5)
#define VTv4_InputNumber_GetAttributeValue_VariableReference(vt_client,vt,input_number) GetAttributeValue_Message(vt_client,vt,input_number, 6)
#define VTv4_InputNumber_GetAttributeValue_MinimumValue(vt_client,vt,input_number) GetAttributeValue_Message(vt_client,vt,input_number, 7)
#define VTv4_InputNumber_GetAttributeValue_MaximumValue(vt_client,vt,input_number) GetAttributeValue_Message(vt_client,vt,input_number, 8)
#define VTv4_InputNumber_GetAttributeValue_Offset(vt_client,vt,input_number) GetAttributeValue_Message(vt_client,vt,input_number, 9)
#define VTv4_InputNumber_GetAttributeValue_Scale(vt_client,vt,input_number) GetAttributeValue_Message(vt_client,vt,input_number,10)
#define VTv4_InputNumber_GetAttributeValue_NumberOfDecimals(vt_client,vt,input_number) GetAttributeValue_Message(vt_client,vt,input_number,11)
#define VTv4_InputNumber_GetAttributeValue_Format(vt_client,vt,input_number) GetAttributeValue_Message(vt_client,vt,input_number,12)
#define VTv4_InputNumber_GetAttributeValue_Justification(vt_client,vt,input_number) GetAttributeValue_Message(vt_client,vt,input_number,13)
#define VTv4_InputNumber_GetAttributeValue_Value(vt_client,vt,input_number) GetAttributeValue_Message(vt_client,vt,input_number,14)
#define VTv4_InputNumber_GetAttributeValue_Options2(vt_client,vt,input_number) GetAttributeValue_Message(vt_client,vt,input_number,15)
/******************************************************************************/
// B.8.5 Input List object
/******************************************************************************/
#define VTv4_InputList_EnableDisableObject EnableDisableObject_Command
#define VTv4_InputList_SelectInputObject SelectInputObject_Command
#define VTv4_InputList_ESC ESC_Command
#define VTv4_InputList_ChangeNumericValue ChangeNumericValue_Command
#define VTv4_InputList_ChangeListItem ChangeListItem_Command
#define VTv4_InputList_ChangeSize ChangeSize_Command_Scaled_DataMask
#define VTv4_InputList_ChangeAttribute_Width(vt_client,vt,input_list,width) ChangeAttribute_Command (vt_client,vt,input_list,CAST(AttributeValue_T,width) ,1)
#define VTv4_InputList_ChangeAttribute_Height(vt_client,vt,input_list,height) ChangeAttribute_Command (vt_client,vt,input_list,CAST(AttributeValue_T,height) ,2)
#define VTv4_InputList_ChangeAttribute_VariableReference(vt_client,vt,input_list,variable) ChangeAttribute_Command (vt_client,vt,input_list,CAST(AttributeValue_T,variable),3)
#define VTv4_InputList_GetAttributeValue_Type(vt_client,vt,input_list) GetAttributeValue_Message(vt_client,vt,input_list,0)
#define VTv4_InputList_GetAttributeValue_Width(vt_client,vt,input_list) GetAttributeValue_Message(vt_client,vt,input_list,1)
#define VTv4_InputList_GetAttributeValue_Height(vt_client,vt,input_list) GetAttributeValue_Message(vt_client,vt,input_list,2)
#define VTv4_InputList_GetAttributeValue_VariableReference(vt_client,vt,input_list) GetAttributeValue_Message(vt_client,vt,input_list,3)
#define VTv4_InputList_GetAttributeValue_Value(vt_client,vt,input_list) GetAttributeValue_Message(vt_client,vt,input_list,4)
#define VTv4_InputList_GetAttributeValue_Options(vt_client,vt,input_list) GetAttributeValue_Message(vt_client,vt,input_list,5)
/******************************************************************************/
// B.9 Output field objects
/******************************************************************************/
/******************************************************************************/
// B.9.2 Output String object
/******************************************************************************/
#define VTv4_OutputString_ChangeBackgroundColour ChangeBackgroundColour_Command
#define VTv4_OutputString_ChangeStringValue ChangeStringValue_Command
#define VTv4_OutputString_ChangeSize ChangeSize_Command_Scaled
#define VTv4_OutputString_ChangeAttribute_Width(vt_client,vt,output_string,width) ChangeAttribute_Command (vt_client,vt,output_string,CAST(AttributeValue_T,width) ,1)
#define VTv4_OutputString_ChangeAttribute_Height(vt_client,vt,output_string,height) ChangeAttribute_Command (vt_client,vt,output_string,CAST(AttributeValue_T,height) ,2)
#define VTv4_OutputString_ChangeAttribute_BackgroundColour(vt_client,vt,output_string,background_colour) ChangeAttribute_Command (vt_client,vt,output_string,CAST(AttributeValue_T,background_colour),3)
#define VTv4_OutputString_ChangeAttribute_FontAttributes(vt_client,vt,output_string,font_attributes) ChangeAttribute_Command (vt_client,vt,output_string,CAST(AttributeValue_T,font_attributes) ,4)
#define VTv4_OutputString_ChangeAttribute_Options(vt_client,vt,output_string,options) ChangeAttribute_Command (vt_client,vt,output_string,CAST(AttributeValue_T,options) ,5)
#define VTv4_OutputString_ChangeAttribute_VariableReference(vt_client,vt,output_string,variable) ChangeAttribute_Command (vt_client,vt,output_string,CAST(AttributeValue_T,variable) ,6)
#define VTv4_OutputString_ChangeAttribute_Justification(vt_client,vt,output_string,justification) ChangeAttribute_Command (vt_client,vt,output_string,CAST(AttributeValue_T,justification) ,7)
#define VTv4_OutputString_GetAttributeValue_Type(vt_client,vt,output_string) GetAttributeValue_Message(vt_client,vt,output_string,0)
#define VTv4_OutputString_GetAttributeValue_Width(vt_client,vt,output_string) GetAttributeValue_Message(vt_client,vt,output_string,1)
#define VTv4_OutputString_GetAttributeValue_Height(vt_client,vt,output_string) GetAttributeValue_Message(vt_client,vt,output_string,2)
#define VTv4_OutputString_GetAttributeValue_BackgroundColour(vt_client,vt,output_string) GetAttributeValue_Message(vt_client,vt,output_string,3)
#define VTv4_OutputString_GetAttributeValue_FontAttributes(vt_client,vt,output_string) GetAttributeValue_Message(vt_client,vt,output_string,4)
#define VTv4_OutputString_GetAttributeValue_Options(vt_client,vt,output_string) GetAttributeValue_Message(vt_client,vt,output_string,5)
#define VTv4_OutputString_GetAttributeValue_VariableReference(vt_client,vt,output_string) GetAttributeValue_Message(vt_client,vt,output_string,6)
#define VTv4_OutputString_GetAttributeValue_Justification(vt_client,vt,output_string) GetAttributeValue_Message(vt_client,vt,output_string,7)
/******************************************************************************/
// B.9.3 Output Number object
/******************************************************************************/
#define VTv4_OutputNumber_ChangeBackgroundColour ChangeBackgroundColour_Command
#define VTv4_OutputNumber_ChangeNumericValue ChangeNumericValue_Command
#define VTv4_OutputNumber_ChangeSize ChangeSize_Command_Scaled
#define VTv4_OutputNumber_ChangeAttribute_Width(vt_client,vt,output_number,width) ChangeAttribute_Command (vt_client,vt,output_number,CAST(AttributeValue_T,width) , 1)
#define VTv4_OutputNumber_ChangeAttribute_Height(vt_client,vt,output_number,height) ChangeAttribute_Command (vt_client,vt,output_number,CAST(AttributeValue_T,height) , 2)
#define VTv4_OutputNumber_ChangeAttribute_BackgroundColour(vt_client,vt,output_number,background_colour) ChangeAttribute_Command (vt_client,vt,output_number,CAST(AttributeValue_T,background_colour) , 3)
#define VTv4_OutputNumber_ChangeAttribute_FontAttributes(vt_client,vt,output_number,font_attributes) ChangeAttribute_Command (vt_client,vt,output_number,CAST(AttributeValue_T,font_attributes) , 4)
#define VTv4_OutputNumber_ChangeAttribute_Options(vt_client,vt,output_number,options) ChangeAttribute_Command (vt_client,vt,output_number,CAST(AttributeValue_T,options) , 5)
#define VTv4_OutputNumber_ChangeAttribute_VariableReference(vt_client,vt,output_number,variable) ChangeAttribute_Command (vt_client,vt,output_number,CAST(AttributeValue_T,variable) , 6)
#define VTv4_OutputNumber_ChangeAttribute_Offset(vt_client,vt,output_number,offset) ChangeAttribute_Command (vt_client,vt,output_number,CAST(AttributeValue_T,offset) , 7)
#define VTv4_OutputNumber_ChangeAttribute_Scale(vt_client,vt,output_number,scale) ChangeAttribute_Command (vt_client,vt,output_number,CAST(AttributeValue_T,scale) , 8)
#define VTv4_OutputNumber_ChangeAttribute_NumberOfDecimals(vt_client,vt,output_number,number_of_decimals) ChangeAttribute_Command (vt_client,vt,output_number,CAST(AttributeValue_T,number_of_decimals), 9)
#define VTv4_OutputNumber_ChangeAttribute_Format(vt_client,vt,output_number,format) ChangeAttribute_Command (vt_client,vt,output_number,CAST(AttributeValue_T,format) ,10)
#define VTv4_OutputNumber_ChangeAttribute_Justification(vt_client,vt,output_number,justification) ChangeAttribute_Command (vt_client,vt,output_number,CAST(AttributeValue_T,justification) ,11)
#define VTv4_OutputNumber_GetAttributeValue_Type(vt_client,vt,output_number) GetAttributeValue_Message(vt_client,vt,output_number, 0)
#define VTv4_OutputNumber_GetAttributeValue_Width(vt_client,vt,output_number) GetAttributeValue_Message(vt_client,vt,output_number, 1)
#define VTv4_OutputNumber_GetAttributeValue_Height(vt_client,vt,output_number) GetAttributeValue_Message(vt_client,vt,output_number, 2)
#define VTv4_OutputNumber_GetAttributeValue_BackgroundColour(vt_client,vt,output_number) GetAttributeValue_Message(vt_client,vt,output_number, 3)
#define VTv4_OutputNumber_GetAttributeValue_FontAttributes(vt_client,vt,output_number) GetAttributeValue_Message(vt_client,vt,output_number, 4)
#define VTv4_OutputNumber_GetAttributeValue_Options(vt_client,vt,output_number) GetAttributeValue_Message(vt_client,vt,output_number, 5)
#define VTv4_OutputNumber_GetAttributeValue_VariableReference(vt_client,vt,output_number) GetAttributeValue_Message(vt_client,vt,output_number, 6)
#define VTv4_OutputNumber_GetAttributeValue_Offset(vt_client,vt,output_number) GetAttributeValue_Message(vt_client,vt,output_number, 7)
#define VTv4_OutputNumber_GetAttributeValue_Scale(vt_client,vt,output_number) GetAttributeValue_Message(vt_client,vt,output_number, 8)
#define VTv4_OutputNumber_GetAttributeValue_NumberOfDecimals(vt_client,vt,output_number) GetAttributeValue_Message(vt_client,vt,output_number, 9)
#define VTv4_OutputNumber_GetAttributeValue_Format(vt_client,vt,output_number) GetAttributeValue_Message(vt_client,vt,output_number,10)
#define VTv4_OutputNumber_GetAttributeValue_Justification(vt_client,vt,output_number) GetAttributeValue_Message(vt_client,vt,output_number,11)
#define VTv4_OutputNumber_GetAttributeValue_Value(vt_client,vt,output_number) GetAttributeValue_Message(vt_client,vt,output_number,12)
/******************************************************************************/
// B.9.4 Output List object
/******************************************************************************/
#define VTv4_OutputList_ChangeNumericValue ChangeNumericValue_Command
#define VTv4_OutputList_ChangeListItem ChangeListItem_Command
#define VTv4_OutputList_ChangeSize ChangeSize_Command_Scaled
#define VTv4_OutputList_ChangeAttribute_Width(vt_client,vt,output_list,width) ChangeAttribute_Command (vt_client,vt,output_list,CAST(AttributeValue_T,width) ,1)
#define VTv4_OutputList_ChangeAttribute_Height(vt_client,vt,output_list,height) ChangeAttribute_Command (vt_client,vt,output_list,CAST(AttributeValue_T,height) ,2)
#define VTv4_OutputList_ChangeAttribute_VariableReference(vt_client,vt,output_list,variable) ChangeAttribute_Command (vt_client,vt,output_list,CAST(AttributeValue_T,variable),3)
#define VTv4_OutputList_GetAttributeValue_Type(vt_client,vt,output_list) GetAttributeValue_Message(vt_client,vt,output_list,0)
#define VTv4_OutputList_GetAttributeValue_Width(vt_client,vt,output_list) GetAttributeValue_Message(vt_client,vt,output_list,1)
#define VTv4_OutputList_GetAttributeValue_Height(vt_client,vt,output_list) GetAttributeValue_Message(vt_client,vt,output_list,2)
#define VTv4_OutputList_GetAttributeValue_VariableReference(vt_client,vt,output_list) GetAttributeValue_Message(vt_client,vt,output_list,3)
#define VTv4_OutputList_GetAttributeValue_Value(vt_client,vt,output_list) GetAttributeValue_Message(vt_client,vt,output_list,4)
/******************************************************************************/
// B.10 Output Shape Objects
/******************************************************************************/
/******************************************************************************/
// B.10.2 Line object
/******************************************************************************/
#define VTv4_Line_ChangeEndPoint ChangeEndPoint_Command_Scaled
#define VTv4_Line_ChangeSize ChangeSize_Command_Scaled
#define VTv4_Line_ChangeAttribute_LineAttributes(vt_client,vt,line,line_attributes) ChangeAttribute_Command (vt_client,vt,line,CAST(AttributeValue_T,line_attributes),1)
#define VTv4_Line_ChangeAttribute_Width(vt_client,vt,line,width) ChangeAttribute_Command (vt_client,vt,line,CAST(AttributeValue_T,width) ,2)
#define VTv4_Line_ChangeAttribute_Height(vt_client,vt,line,height) ChangeAttribute_Command (vt_client,vt,line,CAST(AttributeValue_T,height) ,3)
#define VTv4_Line_ChangeAttribute_LineDirection(vt_client,vt,line,direction) ChangeAttribute_Command (vt_client,vt,line,CAST(AttributeValue_T,direction) ,4)
#define VTv4_Line_GetAttributeValue_Type(vt_client,vt,line) GetAttributeValue_Message(vt_client,vt,line,0)
#define VTv4_Line_GetAttributeValue_LineAttributes(vt_client,vt,line) GetAttributeValue_Message(vt_client,vt,line,1)
#define VTv4_Line_GetAttributeValue_Width(vt_client,vt,line) GetAttributeValue_Message(vt_client,vt,line,2)
#define VTv4_Line_GetAttributeValue_Height(vt_client,vt,line) GetAttributeValue_Message(vt_client,vt,line,3)
#define VTv4_Line_GetAttributeValue_LineDirection(vt_client,vt,line) GetAttributeValue_Message(vt_client,vt,line,4)
/******************************************************************************/
// B.10.3 Rectangle object
/******************************************************************************/
#define VTv4_Rectangle_ChangeSize ChangeSize_Command_Scaled
#define VTv4_Rectangle_ChangeAttribute_LineAttributes(vt_client,vt,rectangle,line_attributes) ChangeAttribute_Command (vt_client,vt,rectangle,CAST(AttributeValue_T,line_attributes) ,1)
#define VTv4_Rectangle_ChangeAttribute_Width(vt_client,vt,rectangle,width) ChangeAttribute_Command (vt_client,vt,rectangle,CAST(AttributeValue_T,width) ,2)
#define VTv4_Rectangle_ChangeAttribute_Height(vt_client,vt,rectangle,height) ChangeAttribute_Command (vt_client,vt,rectangle,CAST(AttributeValue_T,height) ,3)
#define VTv4_Rectangle_ChangeAttribute_LineSuppression(vt_client,vt,rectangle,line_suppression) ChangeAttribute_Command (vt_client,vt,rectangle,CAST(AttributeValue_T,line_suppression),4)
#define VTv4_Rectangle_ChangeAttribute_FillAttributes(vt_client,vt,rectangle,fill_attributes) ChangeAttribute_Command (vt_client,vt,rectangle,CAST(AttributeValue_T,fill_attributes) ,5)
#define VTv4_Rectangle_GetAttributeValue_Type(vt_client,vt,rectangle) GetAttributeValue_Message(vt_client,vt,rectangle,0)
#define VTv4_Rectangle_GetAttributeValue_LineAttributes(vt_client,vt,rectangle) GetAttributeValue_Message(vt_client,vt,rectangle,1)
#define VTv4_Rectangle_GetAttributeValue_Width(vt_client,vt,rectangle) GetAttributeValue_Message(vt_client,vt,rectangle,2)
#define VTv4_Rectangle_GetAttributeValue_Height(vt_client,vt,rectangle) GetAttributeValue_Message(vt_client,vt,rectangle,3)
#define VTv4_Rectangle_GetAttributeValue_LineSuppression(vt_client,vt,rectangle) GetAttributeValue_Message(vt_client,vt,rectangle,4)
#define VTv4_Rectangle_GetAttributeValue_FillAttributes(vt_client,vt,rectangle) GetAttributeValue_Message(vt_client,vt,rectangle,5)
/******************************************************************************/
// B.10.4 Ellipse object
/******************************************************************************/
#define VTv4_Ellipse_ChangeSize ChangeSize_Command_Scaled
#define VTv4_Ellipse_ChangeAttribute_LineAttributes(vt_client,vt,ellipse,line_attributes) ChangeAttribute_Command (vt_client,vt,ellipse,CAST(AttributeValue_T,line_attributes),1)
#define VTv4_Ellipse_ChangeAttribute_Width(vt_client,vt,ellipse,width) ChangeAttribute_Command (vt_client,vt,ellipse,CAST(AttributeValue_T,width) ,2)
#define VTv4_Ellipse_ChangeAttribute_Height(vt_client,vt,ellipse,height) ChangeAttribute_Command (vt_client,vt,ellipse,CAST(AttributeValue_T,height) ,3)
#define VTv4_Ellipse_ChangeAttribute_EllipseType(vt_client,vt,ellipse,ellipse_type) ChangeAttribute_Command (vt_client,vt,ellipse,CAST(AttributeValue_T,ellipse_type) ,4)
#define VTv4_Ellipse_ChangeAttribute_StartAngle(vt_client,vt,ellipse,start) ChangeAttribute_Command (vt_client,vt,ellipse,CAST(AttributeValue_T,start) ,5)
#define VTv4_Ellipse_ChangeAttribute_EndAngle(vt_client,vt,ellipse,end) ChangeAttribute_Command (vt_client,vt,ellipse,CAST(AttributeValue_T,end) ,6)
#define VTv4_Ellipse_ChangeAttribute_FillAttributes(vt_client,vt,ellipse,fill_attributes) ChangeAttribute_Command (vt_client,vt,ellipse,CAST(AttributeValue_T,fill_attributes),7)
#define VTv4_Ellipse_GetAttributeValue_Type(vt_client,vt,ellipse) GetAttributeValue_Message(vt_client,vt,ellipse,0)
#define VTv4_Ellipse_GetAttributeValue_LineAttributes(vt_client,vt,ellipse) GetAttributeValue_Message(vt_client,vt,ellipse,1)
#define VTv4_Ellipse_GetAttributeValue_Width(vt_client,vt,ellipse) GetAttributeValue_Message(vt_client,vt,ellipse,2)
#define VTv4_Ellipse_GetAttributeValue_Height(vt_client,vt,ellipse) GetAttributeValue_Message(vt_client,vt,ellipse,3)
#define VTv4_Ellipse_GetAttributeValue_EllipseType(vt_client,vt,ellipse) GetAttributeValue_Message(vt_client,vt,ellipse,4)
#define VTv4_Ellipse_GetAttributeValue_StartAngle(vt_client,vt,ellipse) GetAttributeValue_Message(vt_client,vt,ellipse,5)
#define VTv4_Ellipse_GetAttributeValue_EndAngle(vt_client,vt,ellipse) GetAttributeValue_Message(vt_client,vt,ellipse,6)
#define VTv4_Ellipse_GetAttributeValue_FillAttributes(vt_client,vt,ellipse) GetAttributeValue_Message(vt_client,vt,ellipse,7)
/******************************************************************************/
// B.10.5 Polygon object
/******************************************************************************/
#define VTv4_Polygon_ChangeSize ChangeSize_Command_Scaled
#define VTv4_Polygon_ChangePolygonPoint ChangePolygonPoint_Command_Scaled
#define VTv4_Polygon_ChangePolygonScale ChangePolygonScale_Command_Scaled
#define VTv4_Polygon_ChangeAttribute_Width(vt_client,vt,polygon,width) ChangeAttribute_Command (vt_client,vt,polygon,CAST(AttributeValue_T,width) ,1)
#define VTv4_Polygon_ChangeAttribute_Height(vt_client,vt,polygon,height) ChangeAttribute_Command (vt_client,vt,polygon,CAST(AttributeValue_T,height) ,2)
#define VTv4_Polygon_ChangeAttribute_LineAttributes(vt_client,vt,polygon,line_attributes) ChangeAttribute_Command (vt_client,vt,polygon,CAST(AttributeValue_T,line_attributes),3)
#define VTv4_Polygon_ChangeAttribute_FillAttributes(vt_client,vt,polygon,fill_attributes) ChangeAttribute_Command (vt_client,vt,polygon,CAST(AttributeValue_T,fill_attributes),4)
#define VTv4_Polygon_ChangeAttribute_PolygonType(vt_client,vt,polygon,polygon_type) ChangeAttribute_Command (vt_client,vt,polygon,CAST(AttributeValue_T,polygon_type) ,5)
#define VTv4_Polygon_GetAttributeValue_Type(vt_client,vt,polygon) GetAttributeValue_Message(vt_client,vt,polygon,0)
#define VTv4_Polygon_GetAttributeValue_Width(vt_client,vt,polygon) GetAttributeValue_Message(vt_client,vt,polygon,1)
#define VTv4_Polygon_GetAttributeValue_Height(vt_client,vt,polygon) GetAttributeValue_Message(vt_client,vt,polygon,2)
#define VTv4_Polygon_GetAttributeValue_LineAttributes(vt_client,vt,polygon) GetAttributeValue_Message(vt_client,vt,polygon,3)
#define VTv4_Polygon_GetAttributeValue_FillAttributes(vt_client,vt,polygon) GetAttributeValue_Message(vt_client,vt,polygon,4)
#define VTv4_Polygon_GetAttributeValue_PolygonType(vt_client,vt,polygon) GetAttributeValue_Message(vt_client,vt,polygon,5)
/******************************************************************************/
// B.11 Output Graphic Objects
/******************************************************************************/
/******************************************************************************/
// B.11.2 Meter object
/******************************************************************************/
#define VTv4_Meter_ChangeNumericValue ChangeNumericValue_Command
#define VTv4_Meter_ChangeSize ChangeSize_Command_Scaled
#define VTv4_Meter_ChangeAttribute_Width(vt_client,vt,meter,width) ChangeAttribute_Command (vt_client,vt,meter,CAST(AttributeValue_T,width) , 1)
#define VTv4_Meter_ChangeAttribute_NeedleColour(vt_client,vt,meter,needle_colour) ChangeAttribute_Command (vt_client,vt,meter,CAST(AttributeValue_T,needle_colour) , 2)
#define VTv4_Meter_ChangeAttribute_BorderColour(vt_client,vt,meter,border_colour) ChangeAttribute_Command (vt_client,vt,meter,CAST(AttributeValue_T,border_colour) , 3)
#define VTv4_Meter_ChangeAttribute_ArcAndTickColour(vt_client,vt,meter,arc_tick_colour) ChangeAttribute_Command (vt_client,vt,meter,CAST(AttributeValue_T,arc_tick_colour), 4)
#define VTv4_Meter_ChangeAttribute_Options(vt_client,vt,meter,options) ChangeAttribute_Command (vt_client,vt,meter,CAST(AttributeValue_T,options) , 5)
#define VTv4_Meter_ChangeAttribute_NumberOfTicks(vt_client,vt,meter,number_of_ticks) ChangeAttribute_Command (vt_client,vt,meter,CAST(AttributeValue_T,number_of_ticks), 6)
#define VTv4_Meter_ChangeAttribute_StartAngle(vt_client,vt,meter,start) ChangeAttribute_Command (vt_client,vt,meter,CAST(AttributeValue_T,start) , 7)
#define VTv4_Meter_ChangeAttribute_EndAngle(vt_client,vt,meter,end) ChangeAttribute_Command (vt_client,vt,meter,CAST(AttributeValue_T,end) , 8)
#define VTv4_Meter_ChangeAttribute_MinimumValue(vt_client,vt,meter,minimum_value) ChangeAttribute_Command (vt_client,vt,meter,CAST(AttributeValue_T,minimum_value) , 9)
#define VTv4_Meter_ChangeAttribute_MaximumValue(vt_client,vt,meter,maximum_value) ChangeAttribute_Command (vt_client,vt,meter,CAST(AttributeValue_T,maximum_value) ,10)
#define VTv4_Meter_ChangeAttribute_VariableReference(vt_client,vt,meter,variable) ChangeAttribute_Command (vt_client,vt,meter,CAST(AttributeValue_T,variable) ,11)
#define VTv4_Meter_GetAttributeValue_Type(vt_client,vt,meter) GetAttributeValue_Message(vt_client,vt,meter, 0)
#define VTv4_Meter_GetAttributeValue_Width(vt_client,vt,meter) GetAttributeValue_Message(vt_client,vt,meter, 1)
#define VTv4_Meter_GetAttributeValue_NeedleColour(vt_client,vt,meter) GetAttributeValue_Message(vt_client,vt,meter, 2)
#define VTv4_Meter_GetAttributeValue_BorderColour(vt_client,vt,meter) GetAttributeValue_Message(vt_client,vt,meter, 3)
#define VTv4_Meter_GetAttributeValue_ArcAndTickColour(vt_client,vt,meter) GetAttributeValue_Message(vt_client,vt,meter, 4)
#define VTv4_Meter_GetAttributeValue_Options(vt_client,vt,meter) GetAttributeValue_Message(vt_client,vt,meter, 5)
#define VTv4_Meter_GetAttributeValue_NumberOfTicks(vt_client,vt,meter) GetAttributeValue_Message(vt_client,vt,meter, 6)
#define VTv4_Meter_GetAttributeValue_StartAngle(vt_client,vt,meter) GetAttributeValue_Message(vt_client,vt,meter, 7)
#define VTv4_Meter_GetAttributeValue_EndAngle(vt_client,vt,meter) GetAttributeValue_Message(vt_client,vt,meter, 8)
#define VTv4_Meter_GetAttributeValue_MinimumValue(vt_client,vt,meter) GetAttributeValue_Message(vt_client,vt,meter, 9)
#define VTv4_Meter_GetAttributeValue_MaximumValue(vt_client,vt,meter) GetAttributeValue_Message(vt_client,vt,meter,10)
#define VTv4_Meter_GetAttributeValue_VariableReference(vt_client,vt,meter) GetAttributeValue_Message(vt_client,vt,meter,11)
#define VTv4_Meter_GetAttributeValue_Value(vt_client,vt,meter) GetAttributeValue_Message(vt_client,vt,meter,12)
/******************************************************************************/
// B.11.3 Linear Bar Graph object
/******************************************************************************/
#define VTv4_LinearBarGraph_ChangeNumericValue ChangeNumericValue_Command
#define VTv4_LinearBarGraph_ChangeSize ChangeSize_Command_Scaled
#define VTv4_LinearBarGraph_ChangeAttribute_Width(vt_client,vt,linear_bar_graph,width) ChangeAttribute_Command (vt_client,vt,linear_bar_graph,CAST(AttributeValue_T,width) , 1)
#define VTv4_LinearBarGraph_ChangeAttribute_Height(vt_client,vt,linear_bar_graph,height) ChangeAttribute_Command (vt_client,vt,linear_bar_graph,CAST(AttributeValue_T,height) , 2)
#define VTv4_LinearBarGraph_ChangeAttribute_Colour(vt_client,vt,linear_bar_graph,colour) ChangeAttribute_Command (vt_client,vt,linear_bar_graph,CAST(AttributeValue_T,colour) , 3)
#define VTv4_LinearBarGraph_ChangeAttribute_TargetLineColour(vt_client,vt,linear_bar_graph,target_line_colour) ChangeAttribute_Command (vt_client,vt,linear_bar_graph,CAST(AttributeValue_T,target_line_colour), 4)
#define VTv4_LinearBarGraph_ChangeAttribute_Options(vt_client,vt,linear_bar_graph,options) ChangeAttribute_Command (vt_client,vt,linear_bar_graph,CAST(AttributeValue_T,options) , 5)
#define VTv4_LinearBarGraph_ChangeAttribute_NumberOfTicks(vt_client,vt,linear_bar_graph,number_of_ticks) ChangeAttribute_Command (vt_client,vt,linear_bar_graph,CAST(AttributeValue_T,number_of_ticks) , 6)
#define VTv4_LinearBarGraph_ChangeAttribute_MinimumValue(vt_client,vt,linear_bar_graph,minimum_value) ChangeAttribute_Command (vt_client,vt,linear_bar_graph,CAST(AttributeValue_T,minimum_value) , 7)
#define VTv4_LinearBarGraph_ChangeAttribute_MaximumValue(vt_client,vt,linear_bar_graph,maximum_value) ChangeAttribute_Command (vt_client,vt,linear_bar_graph,CAST(AttributeValue_T,maximum_value) , 8)
#define VTv4_LinearBarGraph_ChangeAttribute_VariableReference(vt_client,vt,linear_bar_graph,variable) ChangeAttribute_Command (vt_client,vt,linear_bar_graph,CAST(AttributeValue_T,variable) , 9)
#define VTv4_LinearBarGraph_ChangeAttribute_TargetValueReference(vt_client,vt,linear_bar_graph,target_variable) ChangeAttribute_Command (vt_client,vt,linear_bar_graph,CAST(AttributeValue_T,target_variable) ,10)
#define VTv4_LinearBarGraph_ChangeAttribute_TargetValue(vt_client,vt,linear_bar_graph,target_value) ChangeAttribute_Command (vt_client,vt,linear_bar_graph,CAST(AttributeValue_T,target_value) ,11)
#define VTv4_LinearBarGraph_GetAttributeValue_Type(vt_client,vt,linear_bar_graph) GetAttributeValue_Message(vt_client,vt,linear_bar_graph, 0)
#define VTv4_LinearBarGraph_GetAttributeValue_Width(vt_client,vt,linear_bar_graph) GetAttributeValue_Message(vt_client,vt,linear_bar_graph, 1)
#define VTv4_LinearBarGraph_GetAttributeValue_Height(vt_client,vt,linear_bar_graph) GetAttributeValue_Message(vt_client,vt,linear_bar_graph, 2)
#define VTv4_LinearBarGraph_GetAttributeValue_Colour(vt_client,vt,linear_bar_graph) GetAttributeValue_Message(vt_client,vt,linear_bar_graph, 3)
#define VTv4_LinearBarGraph_GetAttributeValue_TargetLineColour(vt_client,vt,linear_bar_graph) GetAttributeValue_Message(vt_client,vt,linear_bar_graph, 4)
#define VTv4_LinearBarGraph_GetAttributeValue_Options(vt_client,vt,linear_bar_graph) GetAttributeValue_Message(vt_client,vt,linear_bar_graph, 5)
#define VTv4_LinearBarGraph_GetAttributeValue_NumberOfTicks(vt_client,vt,linear_bar_graph) GetAttributeValue_Message(vt_client,vt,linear_bar_graph, 6)
#define VTv4_LinearBarGraph_GetAttributeValue_MinimumValue(vt_client,vt,linear_bar_graph) GetAttributeValue_Message(vt_client,vt,linear_bar_graph, 7)
#define VTv4_LinearBarGraph_GetAttributeValue_MaximumValue(vt_client,vt,linear_bar_graph) GetAttributeValue_Message(vt_client,vt,linear_bar_graph, 8)
#define VTv4_LinearBarGraph_GetAttributeValue_VariableReference(vt_client,vt,linear_bar_graph) GetAttributeValue_Message(vt_client,vt,linear_bar_graph, 9)
#define VTv4_LinearBarGraph_GetAttributeValue_TargetValueReference(vt_client,vt,linear_bar_graph) GetAttributeValue_Message(vt_client,vt,linear_bar_graph,10)
#define VTv4_LinearBarGraph_GetAttributeValue_TargetValue(vt_client,vt,linear_bar_graph) GetAttributeValue_Message(vt_client,vt,linear_bar_graph,11)
#define VTv4_LinearBarGraph_GetAttributeValue_Value(vt_client,vt,linear_bar_graph) GetAttributeValue_Message(vt_client,vt,linear_bar_graph,12)
/******************************************************************************/
// B.11.4 Arched Bar Graph object
/******************************************************************************/
#define VTv4_ArchedBarGraph_ChangeNumericValue ChangeNumericValue_Command
#define VTv4_ArchedBarGraph_ChangeSize ChangeSize_Command_Scaled
#define VTv4_ArchedBarGraph_ChangeAttribute_Width(vt_client,vt,arched_bar_graph,width) ChangeAttribute_Command (vt_client,vt,arched_bar_graph,CAST(AttributeValue_T,width) , 1)
#define VTv4_ArchedBarGraph_ChangeAttribute_Height(vt_client,vt,arched_bar_graph,height) ChangeAttribute_Command (vt_client,vt,arched_bar_graph,CAST(AttributeValue_T,height) , 2)
#define VTv4_ArchedBarGraph_ChangeAttribute_Colour(vt_client,vt,arched_bar_graph,colour) ChangeAttribute_Command (vt_client,vt,arched_bar_graph,CAST(AttributeValue_T,colour) , 3)
#define VTv4_ArchedBarGraph_ChangeAttribute_TargetLineColour(vt_client,vt,arched_bar_graph,target_line_colour) ChangeAttribute_Command (vt_client,vt,arched_bar_graph,CAST(AttributeValue_T,target_line_colour), 4)
#define VTv4_ArchedBarGraph_ChangeAttribute_Options(vt_client,vt,arched_bar_graph,options) ChangeAttribute_Command (vt_client,vt,arched_bar_graph,CAST(AttributeValue_T,options) , 5)
#define VTv4_ArchedBarGraph_ChangeAttribute_StartAngle(vt_client,vt,arched_bar_graph,start) ChangeAttribute_Command (vt_client,vt,arched_bar_graph,CAST(AttributeValue_T,start) , 6)
#define VTv4_ArchedBarGraph_ChangeAttribute_EndAngle(vt_client,vt,arched_bar_graph,end) ChangeAttribute_Command (vt_client,vt,arched_bar_graph,CAST(AttributeValue_T,end) , 7)
#define VTv4_ArchedBarGraph_ChangeAttribute_BarGraphWidth(vt_client,vt,arched_bar_graph,width) ChangeAttribute_Command (vt_client,vt,arched_bar_graph,CAST(AttributeValue_T,width) , 8)
#define VTv4_ArchedBarGraph_ChangeAttribute_MinimumValue(vt_client,vt,arched_bar_graph,minimum_value) ChangeAttribute_Command (vt_client,vt,arched_bar_graph,CAST(AttributeValue_T,minimum_value) , 9)
#define VTv4_ArchedBarGraph_ChangeAttribute_MaximumValue(vt_client,vt,arched_bar_graph,maximum_value) ChangeAttribute_Command (vt_client,vt,arched_bar_graph,CAST(AttributeValue_T,maximum_value) ,10)
#define VTv4_ArchedBarGraph_ChangeAttribute_VariableReference(vt_client,vt,arched_bar_graph,variable) ChangeAttribute_Command (vt_client,vt,arched_bar_graph,CAST(AttributeValue_T,variable) ,11)
#define VTv4_ArchedBarGraph_ChangeAttribute_TargetValueReference(vt_client,vt,arched_bar_graph,target_variable) ChangeAttribute_Command (vt_client,vt,arched_bar_graph,CAST(AttributeValue_T,target_variable) ,12)
#define VTv4_ArchedBarGraph_ChangeAttribute_TargetValue(vt_client,vt,arched_bar_graph,target_value) ChangeAttribute_Command (vt_client,vt,arched_bar_graph,CAST(AttributeValue_T,target_value) ,13)
#define VTv4_ArchedBarGraph_GetAttributeValue_Type(vt_client,vt,arched_bar_graph) GetAttributeValue_Message(vt_client,vt,arched_bar_graph, 0)
#define VTv4_ArchedBarGraph_GetAttributeValue_Width(vt_client,vt,arched_bar_graph) GetAttributeValue_Message(vt_client,vt,arched_bar_graph, 1)
#define VTv4_ArchedBarGraph_GetAttributeValue_Height(vt_client,vt,arched_bar_graph) GetAttributeValue_Message(vt_client,vt,arched_bar_graph, 2)
#define VTv4_ArchedBarGraph_GetAttributeValue_Colour(vt_client,vt,arched_bar_graph) GetAttributeValue_Message(vt_client,vt,arched_bar_graph, 3)
#define VTv4_ArchedBarGraph_GetAttributeValue_TargetLineColour(vt_client,vt,arched_bar_graph) GetAttributeValue_Message(vt_client,vt,arched_bar_graph, 4)
#define VTv4_ArchedBarGraph_GetAttributeValue_Options(vt_client,vt,arched_bar_graph) GetAttributeValue_Message(vt_client,vt,arched_bar_graph, 5)
#define VTv4_ArchedBarGraph_GetAttributeValue_StartAngle(vt_client,vt,arched_bar_graph) GetAttributeValue_Message(vt_client,vt,arched_bar_graph, 6)
#define VTv4_ArchedBarGraph_GetAttributeValue_EndAngle(vt_client,vt,arched_bar_graph) GetAttributeValue_Message(vt_client,vt,arched_bar_graph, 7)
#define VTv4_ArchedBarGraph_GetAttributeValue_BarGraphWidth(vt_client,vt,arched_bar_graph) GetAttributeValue_Message(vt_client,vt,arched_bar_graph, 8)
#define VTv4_ArchedBarGraph_GetAttributeValue_MinimumValue(vt_client,vt,arched_bar_graph) GetAttributeValue_Message(vt_client,vt,arched_bar_graph, 9)
#define VTv4_ArchedBarGraph_GetAttributeValue_MaximumValue(vt_client,vt,arched_bar_graph) GetAttributeValue_Message(vt_client,vt,arched_bar_graph,10)
#define VTv4_ArchedBarGraph_GetAttributeValue_VariableReference(vt_client,vt,arched_bar_graph) GetAttributeValue_Message(vt_client,vt,arched_bar_graph,11)
#define VTv4_ArchedBarGraph_GetAttributeValue_TargetValueReference(vt_client,vt,arched_bar_graph) GetAttributeValue_Message(vt_client,vt,arched_bar_graph,12)
#define VTv4_ArchedBarGraph_GetAttributeValue_TargetValue(vt_client,vt,arched_bar_graph) GetAttributeValue_Message(vt_client,vt,arched_bar_graph,13)
#define VTv4_ArchedBarGraph_GetAttributeValue_Value(vt_client,vt,arched_bar_graph) GetAttributeValue_Message(vt_client,vt,arched_bar_graph,14)
/******************************************************************************/
// B.12 Picture Graphic object
/******************************************************************************/
#define VTv4_PictureGraphic_ChangeAttribute_Width(vt_client,vt,picture_graphic,width) ChangeAttribute_Command (vt_client,vt,picture_graphic,CAST(AttributeValue_T,width) ,1)
#define VTv4_PictureGraphic_ChangeAttribute_Options(vt_client,vt,picture_graphic,options) ChangeAttribute_Command (vt_client,vt,picture_graphic,CAST(AttributeValue_T,options) ,2)
#define VTv4_PictureGraphic_ChangeAttribute_TransparencyColour(vt_client,vt,picture_graphic,tranparency_colour) ChangeAttribute_Command (vt_client,vt,picture_graphic,CAST(AttributeValue_T,tranparency_colour),3)
#define VTv4_PictureGraphic_GetAttributeValue_Type(vt_client,vt,picture_graphic) GetAttributeValue_Message(vt_client,vt,picture_graphic,0)
#define VTv4_PictureGraphic_GetAttributeValue_Width(vt_client,vt,picture_graphic) GetAttributeValue_Message(vt_client,vt,picture_graphic,1)
#define VTv4_PictureGraphic_GetAttributeValue_Options(vt_client,vt,picture_graphic) GetAttributeValue_Message(vt_client,vt,picture_graphic,2)
#define VTv4_PictureGraphic_GetAttributeValue_TransparencyColour(vt_client,vt,picture_graphic) GetAttributeValue_Message(vt_client,vt,picture_graphic,3)
#define VTv4_PictureGraphic_GetAttributeValue_ActualWidth(vt_client,vt,picture_graphic) GetAttributeValue_Message(vt_client,vt,picture_graphic,4)
#define VTv4_PictureGraphic_GetAttributeValue_ActualHeight(vt_client,vt,picture_graphic) GetAttributeValue_Message(vt_client,vt,picture_graphic,5)
#define VTv4_PictureGraphic_GetAttributeValue_Format(vt_client,vt,picture_graphic) GetAttributeValue_Message(vt_client,vt,picture_graphic,6)
/******************************************************************************/
// B.13 Variable Objects
/******************************************************************************/
/******************************************************************************/
// B.13.2 Number Variable object
/******************************************************************************/
#define VTv4_NumberVariable_ChangeNumericValue ChangeNumericValue_Command
#define VTv4_NumberVariable_GetAttributeValue_Type(vt_client,vt,number_variable) GetAttributeValue_Message(vt_client,vt,number_variable,0)
#define VTv4_NumberVariable_GetAttributeValue_Value(vt_client,vt,number_variable) GetAttributeValue_Message(vt_client,vt,number_variable,1)
/******************************************************************************/
// B.13.3 String Variable object
/******************************************************************************/
#define VTv4_StringVariable_ChangeStringValue ChangeStringValue_Command
#define VTv4_StringVariable_GetAttributeValue_Type(vt_client,vt,string_variable) GetAttributeValue_Message(vt_client,vt,string_variable,0)
/******************************************************************************/
// B.14 Attribute Objects
/******************************************************************************/
/******************************************************************************/
// B.14.2 Font Attributes object
/******************************************************************************/
#define VTv4_FontAttributes_ChangeFontAttributes ChangeFontAttributes_Command
#define VTv4_FontAttributes_ChangeAttribute_FontColour(vt_client,vt,font_attributes,colour) ChangeAttribute_Command (vt_client,vt,font_attributes,CAST(AttributeValue_T,colour),1)
#define VTv4_FontAttributes_ChangeAttribute_FontSize(vt_client,vt,font_attributes,size) ChangeAttribute_Command (vt_client,vt,font_attributes,CAST(AttributeValue_T,size) ,2)
#define VTv4_FontAttributes_ChangeAttribute_FontType(vt_client,vt,font_attributes,type) ChangeAttribute_Command (vt_client,vt,font_attributes,CAST(AttributeValue_T,type) ,3)
#define VTv4_FontAttributes_ChangeAttribute_FontStyle(vt_client,vt,font_attributes,style) ChangeAttribute_Command (vt_client,vt,font_attributes,CAST(AttributeValue_T,style) ,4)
#define VTv4_FontAttributes_GetAttributeValue_Type(vt_client,vt,font_attributes) GetAttributeValue_Message(vt_client,vt,font_attributes,0)
#define VTv4_FontAttributes_GetAttributeValue_FontColour(vt_client,vt,font_attributes) GetAttributeValue_Message(vt_client,vt,font_attributes,1)
#define VTv4_FontAttributes_GetAttributeValue_FontSize(vt_client,vt,font_attributes) GetAttributeValue_Message(vt_client,vt,font_attributes,2)
#define VTv4_FontAttributes_GetAttributeValue_FontType(vt_client,vt,font_attributes) GetAttributeValue_Message(vt_client,vt,font_attributes,3)
#define VTv4_FontAttributes_GetAttributeValue_FontStyle(vt_client,vt,font_attributes) GetAttributeValue_Message(vt_client,vt,font_attributes,4)
/******************************************************************************/
// B.14.3 Line Attributes object
/******************************************************************************/
#define VTv4_LineAttributes_ChangeLineAttributes ChangeLineAttributes_Command_Scaled
#define VTv4_LineAttributes_ChangeAttribute_LineColour(vt_client,vt,line_attributes,colour) ChangeAttribute_Command (vt_client,vt,line_attributes,CAST(AttributeValue_T,colour) ,1)
#define VTv4_LineAttributes_ChangeAttribute_LineWidth(vt_client,vt,line_attributes,width) ChangeAttribute_Command (vt_client,vt,line_attributes,CAST(AttributeValue_T,width) ,2)
#define VTv4_LineAttributes_ChangeAttribute_LineArt(vt_client,vt,line_attributes,line_art) ChangeAttribute_Command (vt_client,vt,line_attributes,CAST(AttributeValue_T,line_art),3)
#define VTv4_LineAttributes_GetAttributeValue_Type(vt_client,vt,line_attributes) GetAttributeValue_Message(vt_client,vt,line_attributes,0)
#define VTv4_LineAttributes_GetAttributeValue_LineColour(vt_client,vt,line_attributes) GetAttributeValue_Message(vt_client,vt,line_attributes,1)
#define VTv4_LineAttributes_GetAttributeValue_LineWidth(vt_client,vt,line_attributes) GetAttributeValue_Message(vt_client,vt,line_attributes,2)
#define VTv4_LineAttributes_GetAttributeValue_LineArt(vt_client,vt,line_attributes) GetAttributeValue_Message(vt_client,vt,line_attributes,3)
/******************************************************************************/
// B.14.4 Fill Attributes object
/******************************************************************************/
#define VTv4_FillAttributes_ChangeFillAttributes ChangeFillAttributes_Command
#define VTv4_FillAttributes_ChangeAttribute_FillType(vt_client,vt,fill_attributes,type) ChangeAttribute_Command (vt_client,vt,fill_attributes,CAST(AttributeValue_T,type) ,1)
#define VTv4_FillAttributes_ChangeAttribute_FillColour(vt_client,vt,fill_attributes,colour) ChangeAttribute_Command (vt_client,vt,fill_attributes,CAST(AttributeValue_T,colour) ,2)
#define VTv4_FillAttributes_ChangeAttribute_FillPattern(vt_client,vt,fill_attributes,pattern_id) ChangeAttribute_Command (vt_client,vt,fill_attributes,CAST(AttributeValue_T,pattern_id),3)
#define VTv4_FillAttributes_GetAttributeValue_Type(vt_client,vt,fill_attributes) GetAttributeValue_Message(vt_client,vt,fill_attributes,0)
#define VTv4_FillAttributes_GetAttributeValue_FillType(vt_client,vt,fill_attributes) GetAttributeValue_Message(vt_client,vt,fill_attributes,1)
#define VTv4_FillAttributes_GetAttributeValue_FillColour(vt_client,vt,fill_attributes) GetAttributeValue_Message(vt_client,vt,fill_attributes,2)
#define VTv4_FillAttributes_GetAttributeValue_FillPattern(vt_client,vt,fill_attributes) GetAttributeValue_Message(vt_client,vt,fill_attributes,3)
/******************************************************************************/
// B.14.5 Input Attributes object
/******************************************************************************/
#define VTv4_InputAttributes_ChangeStringValue ChangeStringValue_Command
#define VTv4_InputAttributes_GetAttributeValue_Type(vt_client,vt,input_attributes) GetAttributeValue_Message(vt_client,vt,input_attributes,0)
#define VTv4_InputAttributes_GetAttributeValue_ValidationType(vt_client,vt,input_attributes) GetAttributeValue_Message(vt_client,vt,input_attributes,1)
/******************************************************************************/
// B.14.6 Extended Input Attributes object
/******************************************************************************/
#define VTv4_ExtendedInputAttributes_GetAttributeValue_Type(vt_client,vt,extended_input_attributes) GetAttributeValue_Message(vt_client,vt,extended_input_attributes,0)
#define VTv4_ExtendedInputAttributes_GetAttributeValue_ValidationType(vt_client,vt,extended_input_attributes) GetAttributeValue_Message(vt_client,vt,extended_input_attributes,1)
/******************************************************************************/
// B.15 Object Pointer object
/******************************************************************************/
#define VTv4_ObjectPointer_ChangeNumericValue ChangeNumericValue_Command
#define VTv4_ObjectPointer_GetAttributeValue_Type(vt_client,vt,object_pointer) GetAttributeValue_Message(vt_client,vt,object_pointer,0)
#define VTv4_ObjectPointer_GetAttributeValue_Value(vt_client,vt,object_pointer) GetAttributeValue_Message(vt_client,vt,object_pointer,1)
/******************************************************************************/
// B.16 Macro object
/******************************************************************************/
#define VTv4_Macro_ExecuteMacro ExecuteMacro_Command
#define VTv4_Macro_GetAttributeValue_Type(vt_client,vt,macro) GetAttributeValue_Message(vt_client,vt,macro, 0)
/******************************************************************************/
// B.17 Colour Map object
/******************************************************************************/
#define VTv4_ColourMap_SelectColourMap SelectColourMap_Command
#define VTv4_ColourMap_GetAttributeValue_Type(vt_client,vt,colour_map) GetAttributeValue_Message(vt_client,vt,colour_map,0)
/******************************************************************************/
// B.18 Graphics Context object
/******************************************************************************/
#define VTv4_GraphicsContext_GraphicsContextCommand GraphicsContext_Command
#define VTv4_GraphicsContext_ChangeBackgroundColour ChangeBackgroundColour_Command
#define VTv4_GraphicsContext_ChangeAttribute_ViewportWidth(vt_client,vt,graphics_context,viewport_width) ChangeAttribute_Command (vt_client,vt,graphics_context,CAST(AttributeValue_T,viewport_width) , 1)
#define VTv4_GraphicsContext_ChangeAttribute_ViewportHeight(vt_client,vt,graphics_context,viewport_height) ChangeAttribute_Command (vt_client,vt,graphics_context,CAST(AttributeValue_T,viewport_height) , 2)
#define VTv4_GraphicsContext_ChangeAttribute_ViewportX(vt_client,vt,graphics_context,viewport_x) ChangeAttribute_Command (vt_client,vt,graphics_context,CAST(AttributeValue_T,viewport_x) , 3)
#define VTv4_GraphicsContext_ChangeAttribute_ViewportY(vt_client,vt,graphics_context,viewport_y) ChangeAttribute_Command (vt_client,vt,graphics_context,CAST(AttributeValue_T,viewport_y) , 4)
#define VTv4_GraphicsContext_ChangeAttribute_ViewportZoom(vt_client,vt,graphics_context,zoom) ChangeAttribute_Command (vt_client,vt,graphics_context,CAST(AttributeValue_T,zoom) , 7)
#define VTv4_GraphicsContext_ChangeAttribute_GraphicsCursorX(vt_client,vt,graphics_context,cursor_x) ChangeAttribute_Command (vt_client,vt,graphics_context,CAST(AttributeValue_T,cursor_x) , 8)
#define VTv4_GraphicsContext_ChangeAttribute_GraphicsCursorY(vt_client,vt,graphics_context,cursor_y) ChangeAttribute_Command (vt_client,vt,graphics_context,CAST(AttributeValue_T,cursor_y) , 9)
#define VTv4_GraphicsContext_ChangeAttribute_ForegroundColour(vt_client,vt,graphics_context,foreground_colour) ChangeAttribute_Command (vt_client,vt,graphics_context,CAST(AttributeValue_T,foreground_colour) ,10)
#define VTv4_GraphicsContext_ChangeAttribute_BackgroundColour(vt_client,vt,graphics_context,background_colour) ChangeAttribute_Command (vt_client,vt,graphics_context,CAST(AttributeValue_T,background_colour) ,11)
#define VTv4_GraphicsContext_ChangeAttribute_FontAttributesObject(vt_client,vt,graphics_context,font_attributes) ChangeAttribute_Command (vt_client,vt,graphics_context,CAST(AttributeValue_T,font_attributes) ,12)
#define VTv4_GraphicsContext_ChangeAttribute_LineAttributesObject(vt_client,vt,graphics_context,line_attributes) ChangeAttribute_Command (vt_client,vt,graphics_context,CAST(AttributeValue_T,line_attributes) ,13)
#define VTv4_GraphicsContext_ChangeAttribute_FillAttributesObject(vt_client,vt,graphics_context,fill_attributes) ChangeAttribute_Command (vt_client,vt,graphics_context,CAST(AttributeValue_T,fill_attributes) ,14)
#define VTv4_GraphicsContext_ChangeAttribute_Format(vt_client,vt,graphics_context,format) ChangeAttribute_Command (vt_client,vt,graphics_context,CAST(AttributeValue_T,format) ,15)
#define VTv4_GraphicsContext_ChangeAttribute_Options(vt_client,vt,graphics_context,options) ChangeAttribute_Command (vt_client,vt,graphics_context,CAST(AttributeValue_T,options) ,16)
#define VTv4_GraphicsContext_ChangeAttribute_TransparencyColour(vt_client,vt,graphics_context,transparency_colour) ChangeAttribute_Command (vt_client,vt,graphics_context,CAST(AttributeValue_T,transparency_colour),17)
#define VTv4_GraphicsContext_GetAttributeValue_Type(vt_client,vt,graphics_context) GetAttributeValue_Message(vt_client,vt,graphics_context, 0)
#define VTv4_GraphicsContext_GetAttributeValue_ViewportWidth(vt_client,vt,graphics_context) GetAttributeValue_Message(vt_client,vt,graphics_context, 1)
#define VTv4_GraphicsContext_GetAttributeValue_ViewportHeight(vt_client,vt,graphics_context) GetAttributeValue_Message(vt_client,vt,graphics_context, 2)
#define VTv4_GraphicsContext_GetAttributeValue_ViewportX(vt_client,vt,graphics_context) GetAttributeValue_Message(vt_client,vt,graphics_context, 3)
#define VTv4_GraphicsContext_GetAttributeValue_ViewportY(vt_client,vt,graphics_context) GetAttributeValue_Message(vt_client,vt,graphics_context, 4)
#define VTv4_GraphicsContext_GetAttributeValue_CanvasWidth(vt_client,vt,graphics_context) GetAttributeValue_Message(vt_client,vt,graphics_context, 5)
#define VTv4_GraphicsContext_GetAttributeValue_CanvasHeight(vt_client,vt,graphics_context) GetAttributeValue_Message(vt_client,vt,graphics_context, 6)
#define VTv4_GraphicsContext_GetAttributeValue_ViewportZoom(vt_client,vt,graphics_context) GetAttributeValue_Message(vt_client,vt,graphics_context, 7)
#define VTv4_GraphicsContext_GetAttributeValue_GraphicsCursorX(vt_client,vt,graphics_context) GetAttributeValue_Message(vt_client,vt,graphics_context, 8)
#define VTv4_GraphicsContext_GetAttributeValue_GraphicsCursorY(vt_client,vt,graphics_context) GetAttributeValue_Message(vt_client,vt,graphics_context, 9)
#define VTv4_GraphicsContext_GetAttributeValue_ForegroundColour(vt_client,vt,graphics_context) GetAttributeValue_Message(vt_client,vt,graphics_context,10)
#define VTv4_GraphicsContext_GetAttributeValue_BackgroundColour(vt_client,vt,graphics_context) GetAttributeValue_Message(vt_client,vt,graphics_context,11)
#define VTv4_GraphicsContext_GetAttributeValue_FontAttributesObject(vt_client,vt,graphics_context) GetAttributeValue_Message(vt_client,vt,graphics_context,12)
#define VTv4_GraphicsContext_GetAttributeValue_LineAttributesObject(vt_client,vt,graphics_context) GetAttributeValue_Message(vt_client,vt,graphics_context,13)
#define VTv4_GraphicsContext_GetAttributeValue_FillAttributesObject(vt_client,vt,graphics_context) GetAttributeValue_Message(vt_client,vt,graphics_context,14)
#define VTv4_GraphicsContext_GetAttributeValue_Format(vt_client,vt,graphics_context) GetAttributeValue_Message(vt_client,vt,graphics_context,15)
#define VTv4_GraphicsContext_GetAttributeValue_Options(vt_client,vt,graphics_context) GetAttributeValue_Message(vt_client,vt,graphics_context,16)
#define VTv4_GraphicsContext_GetAttributeValue_TransparencyColour(vt_client,vt,graphics_context) GetAttributeValue_Message(vt_client,vt,graphics_context,17)
/******************************************************************************/
// B.19 Window Mask object
/******************************************************************************/
#define VTv4_WindowMask_ChangeBackgroundColour ChangeBackgroundColour_Command
#define VTv4_WindowMask_ChangeChildLocation ChangeChildLocation_Command_Scaled_DataMask
#define VTv4_WindowMask_ChangeChildPosition ChangeChildPosition_Command_Scaled_DataMask
#define VTv4_WindowMask_LockUnlockMask LockUnlockMask_Command
#define VTv4_WindowMask_ChangeAttribute_BackgroundColour(vt_client,vt,window_mask,background_colour) ChangeAttribute_Command (vt_client,vt,window_mask,CAST(AttributeValue_T,background_colour),1)
#define VTv4_WindowMask_ChangeAttribute_Options(vt_client,vt,window_mask,options) ChangeAttribute_Command (vt_client,vt,window_mask,CAST(AttributeValue_T,options) ,2)
#define VTv4_WindowMask_ChangeAttribute_Name(vt_client,vt,window_mask,name) ChangeAttribute_Command (vt_client,vt,window_mask,CAST(AttributeValue_T,name) ,3)
#define VTv4_WindowMask_GetAttributeValue_Type(vt_client,vt,window_mask) GetAttributeValue_Message(vt_client,vt,window_mask,0)
#define VTv4_WindowMask_GetAttributeValue_BackgroundColour(vt_client,vt,window_mask) GetAttributeValue_Message(vt_client,vt,window_mask,1)
#define VTv4_WindowMask_GetAttributeValue_Options(vt_client,vt,window_mask) GetAttributeValue_Message(vt_client,vt,window_mask,2)
#define VTv4_WindowMask_GetAttributeValue_Name(vt_client,vt,window_mask) GetAttributeValue_Message(vt_client,vt,window_mask,3)
/******************************************************************************/
// B.20 Key Group object
/******************************************************************************/
#define VTv4_KeyGroup_ChangeAttribute_Options(vt_client,vt,key_group,options) ChangeAttribute_Command (vt_client,vt,key_group,CAST(AttributeValue_T,options),1)
#define VTv4_KeyGroup_ChangeAttribute_Name(vt_client,vt,key_group,name) ChangeAttribute_Command (vt_client,vt,key_group,CAST(AttributeValue_T,name) ,2)
#define VTv4_KeyGroup_GetAttributeValue_Type(vt_client,vt,key_group) GetAttributeValue_Message(vt_client,vt,key_group),0)
#define VTv4_KeyGroup_GetAttributeValue_Options(vt_client,vt,key_group) GetAttributeValue_Message(vt_client,vt,key_group),1)
#define VTv4_KeyGroup_GetAttributeValue_Name(vt_client,vt,key_group) GetAttributeValue_Message(vt_client,vt,key_group),2)
/******************************************************************************/
// B.21 Object Label Reference List object
/******************************************************************************/
#define VTv4_ObjectLabelReferenceList_ChangeObjectLabel ChangeObjectLabel_Command
#define VTv4_ObjectLabelReferenceList_GetAttributeValue_Type(vt_client,vt,object_label_reference_list) GetAttributeValue_Message(vt_client,vt,object_label_reference_list,0)
#define VTv4_ObjectLabelReferenceList_GetAttributeValue_NumberOfLabeledObjects(vt_client,vt,object_label_reference_list) GetAttributeValue_Message(vt_client,vt,object_label_reference_list,1)
//! \endcond
/******************************************************************************/
// Annex E  Non-volatile memory operations commands
/******************************************************************************/
/******************************************************************************/
// Annex F  Command and Macro messages
/******************************************************************************/
/******************************************************************************/
// F.3  Hide/Show Object response
/******************************************************************************/
//! Structure for registering Hide/Show Object callback
typedef struct HideShowObject_Response_Callback_S
{
   //! Object id to match
   const ObjectID_T ObjectID;
   //! Callback function pointer for Hide/Show Object
   void (*HideShowObject_Response)(VTClient_T *vt_client, const VT_T *vt, const HideShowObject_Response_T *);
   //! Linked List node
   struct LinkedList_Node_S Node;
} HideShowObject_Response_Callback_T;
/******************************************************************************/
/*!
   \brief    Macro used to initialize a HideShowObject_Response_Callback_T
   \details  This macro is used to create a HideShowObject_Response_Callback_T.
*/
/******************************************************************************/
#define MAKE_HideShowObject_Response_Callback_T(function,object_id) {object_id, function, MAKE_LinkedList_Node_S(NULL)}
// Externing the function
/******************************************************************************/
/*! \details   Function to register object pool callbacks                     */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to register                                */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was registered                            */
/*! \retval  FALSE  if the callback was not registered                        */
/******************************************************************************/
extern bool_t HideShowObject_Response_Register(ObjectPool_T *objectpool, HideShowObject_Response_Callback_T *callback);
/******************************************************************************/
/*! \details   Function to unregister object pool callbacks                   */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to unregister                              */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was unregistered                          */
/*! \retval  FALSE  if the callback was not unregistered                      */
/******************************************************************************/
extern bool_t HideShowObject_Response_Unregister(ObjectPool_T *objectpool, HideShowObject_Response_Callback_T *callback);
/******************************************************************************/
// F.5  Enable/Disable Object response
/******************************************************************************/
//! Structure for registering Enable/Disable Object callback
typedef struct EnableDisableObject_Response_Callback_S
{
   //! Object id to match
   const ObjectID_T ObjectID;
   //! Callback function pointer for Enable/Disable Object
   void (*EnableDisableObject_Response)(VTClient_T *vt_client, const VT_T *vt, const EnableDisableObject_Response_T *);
   //! Linked List node
   struct LinkedList_Node_S Node;
} EnableDisableObject_Response_Callback_T;
/******************************************************************************/
/*!
   \brief    Macro used to initialize a EnableDisableObject_Response_Callback_T
   \details  This macro is used to create a EnableDisableObject_Response_Callback_T.
*/
/******************************************************************************/
#define MAKE_EnableDisableObject_Response_Callback_T(function,object_id) {object_id, function, MAKE_LinkedList_Node_S(NULL)}
// Externing the function
/******************************************************************************/
/*! \details   Function to register object pool callbacks                     */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to register                                */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was registered                            */
/*! \retval  FALSE  if the callback was not registered                        */
/******************************************************************************/
extern bool_t EnableDisableObject_Response_Register(ObjectPool_T *objectpool, EnableDisableObject_Response_Callback_T *callback);
/******************************************************************************/
/*! \details   Function to unregister object pool callbacks                   */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to unregister                              */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was unregistered                          */
/*! \retval  FALSE  if the callback was not unregistered                      */
/******************************************************************************/
extern bool_t EnableDisableObject_Response_Unregister(ObjectPool_T *objectpool, EnableDisableObject_Response_Callback_T *callback);
/******************************************************************************/
// F.7  Select Input Object response
/******************************************************************************/
//! Structure for registering Select Input Object callback
typedef struct SelectInputObject_Response_Callback_S
{
   //! Object id to match
   const ObjectID_T ObjectID;
   //! Callback function pointer for Select Input Object
   void (*SelectInputObject_Response)(VTClient_T *vt_client, const VT_T *vt, const SelectInputObject_Response_T *);
   //! Linked List node
   struct LinkedList_Node_S Node;
} SelectInputObject_Response_Callback_T;
/******************************************************************************/
/*!
   \brief    Macro used to initialize a SelectInputObject_Response_Callback_T
   \details  This macro is used to create a SelectInputObject_Response_Callback_T.
*/
/******************************************************************************/
#define MAKE_SelectInputObject_Response_Callback_T(function,object_id) {object_id, function, MAKE_LinkedList_Node_S(NULL)}
// Externing the function
/******************************************************************************/
/*! \details   Function to register object pool callbacks                     */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to register                                */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was registered                            */
/*! \retval  FALSE  if the callback was not registered                        */
/******************************************************************************/
extern bool_t SelectInputObject_Response_Register(ObjectPool_T *objectpool, SelectInputObject_Response_Callback_T *callback);
/******************************************************************************/
/*! \details   Function to unregister object pool callbacks                   */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to unregister                              */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was unregistered                          */
/*! \retval  FALSE  if the callback was not unregistered                      */
/******************************************************************************/
extern bool_t SelectInputObject_Response_Unregister(ObjectPool_T *objectpool, SelectInputObject_Response_Callback_T *callback);
/******************************************************************************/
// F.9  ESC response
/******************************************************************************/
//! Structure for registering ESC callback
typedef struct Esc_Response_Callback_S
{
   //! Object id to match
   const ObjectID_T ObjectID;
   //! Callback function pointer for ESC
   void (*Esc_Response)(VTClient_T *vt_client, const VT_T *vt, const Esc_Response_T *);
   //! Linked List node
   struct LinkedList_Node_S Node;
} Esc_Response_Callback_T;
/******************************************************************************/
/*!
   \brief    Macro used to initialize a Esc_Response_Callback_T
   \details  This macro is used to create a Esc_Response_Callback_T.
*/
/******************************************************************************/
#define MAKE_Esc_Response_Callback_T(function,object_id) {object_id, function, MAKE_LinkedList_Node_S(NULL)}
// Externing the function
/******************************************************************************/
/*! \details   Function to register object pool callbacks                     */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to register                                */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was registered                            */
/*! \retval  FALSE  if the callback was not registered                        */
/******************************************************************************/
extern bool_t Esc_Response_Register(ObjectPool_T *objectpool, Esc_Response_Callback_T *callback);
/******************************************************************************/
/*! \details   Function to unregister object pool callbacks                   */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to unregister                              */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was unregistered                          */
/*! \retval  FALSE  if the callback was not unregistered                      */
/******************************************************************************/
extern bool_t Esc_Response_Unregister(ObjectPool_T *objectpool, Esc_Response_Callback_T *callback);
/******************************************************************************/
// F.15  Child Location response
/******************************************************************************/
//! Structure for registering Child Location callback
typedef struct ChangeChildLocation_Response_Callback_S
{
   //! Object id to match
   const ObjectID_T ObjectID;
   //! Callback function pointer for Child Location
   void (*ChangeChildLocation_Response)(VTClient_T *vt_client, const VT_T *vt, const ChangeChildLocation_Response_T *);
   //! Linked List node
   struct LinkedList_Node_S Node;
} ChangeChildLocation_Response_Callback_T;
/******************************************************************************/
/*!
   \brief    Macro used to initialize a ChangeChildLocation_Response_Callback_T
   \details  This macro is used to create a ChangeChildLocation_Response_Callback_T.
*/
/******************************************************************************/
#define MAKE_ChangeChildLocation_Response_Callback_T(function,object_id) {object_id, function, MAKE_LinkedList_Node_S(NULL)}
// Externing the function
/******************************************************************************/
/*! \details   Function to register object pool callbacks                     */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to register                                */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was registered                            */
/*! \retval  FALSE  if the callback was not registered                        */
/******************************************************************************/
extern bool_t ChangeChildLocation_Response_Register(ObjectPool_T *objectpool, ChangeChildLocation_Response_Callback_T *callback);
/******************************************************************************/
/*! \details   Function to unregister object pool callbacks                   */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to unregister                              */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was unregistered                          */
/*! \retval  FALSE  if the callback was not unregistered                      */
/******************************************************************************/
extern bool_t ChangeChildLocation_Response_Unregister(ObjectPool_T *objectpool, ChangeChildLocation_Response_Callback_T *callback);
/******************************************************************************/
// F.17  Change Child Position response
/******************************************************************************/
//! Structure for registering Change Child Position callback
typedef struct ChangeChildPosition_Response_Callback_S
{
   //! Object id to match
   const ObjectID_T ObjectID;
   //! Callback function pointer for Change Child Position
   void (*ChangeChildPosition_Response)(VTClient_T *vt_client, const VT_T *vt, const ChangeChildPosition_Response_T *);
   //! Linked List node
   struct LinkedList_Node_S Node;
} ChangeChildPosition_Response_Callback_T;
/******************************************************************************/
/*!
   \brief    Macro used to initialize a ChangeChildPosition_Response_Callback_T
   \details  This macro is used to create a ChangeChildPosition_Response_Callback_T.
*/
/******************************************************************************/
#define MAKE_ChangeChildPosition_Response_Callback_T(function,object_id) {object_id, function, MAKE_LinkedList_Node_S(NULL)}
// Externing the function
/******************************************************************************/
/*! \details   Function to register object pool callbacks                     */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to register                                */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was registered                            */
/*! \retval  FALSE  if the callback was not registered                        */
/******************************************************************************/
extern bool_t ChangeChildPosition_Response_Register(ObjectPool_T *objectpool, ChangeChildPosition_Response_Callback_T *callback);
/******************************************************************************/
/*! \details   Function to unregister object pool callbacks                   */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to unregister                              */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was unregistered                          */
/*! \retval  FALSE  if the callback was not unregistered                      */
/******************************************************************************/
extern bool_t ChangeChildPosition_Response_Unregister(ObjectPool_T *objectpool, ChangeChildPosition_Response_Callback_T *callback);
/******************************************************************************/
// F.19  Change Size response
/******************************************************************************/
//! Structure for registering Change Size callback
typedef struct ChangeSize_Response_Callback_S
{
   //! Object id to match
   const ObjectID_T ObjectID;
   //! Callback function pointer for Change Size
   void (*ChangeSize_Response)(VTClient_T *vt_client, const VT_T *vt, const ChangeSize_Response_T *);
   //! Linked List node
   struct LinkedList_Node_S Node;
} ChangeSize_Response_Callback_T;
/******************************************************************************/
/*!
   \brief    Macro used to initialize a ChangeSize_Response_Callback_T
   \details  This macro is used to create a ChangeSize_Response_Callback_T.
*/
/******************************************************************************/
#define MAKE_ChangeSize_Response_Callback_T(function,object_id) {object_id, function, MAKE_LinkedList_Node_S(NULL)}
// Externing the function
/******************************************************************************/
/*! \details   Function to register object pool callbacks                     */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to register                                */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was registered                            */
/*! \retval  FALSE  if the callback was not registered                        */
/******************************************************************************/
extern bool_t ChangeSize_Response_Register(ObjectPool_T *objectpool, ChangeSize_Response_Callback_T *callback);
/******************************************************************************/
/*! \details   Function to unregister object pool callbacks                   */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to unregister                              */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was unregistered                          */
/*! \retval  FALSE  if the callback was not unregistered                      */
/******************************************************************************/
extern bool_t ChangeSize_Response_Unregister(ObjectPool_T *objectpool, ChangeSize_Response_Callback_T *callback);
/******************************************************************************/
// F.21  Change Background Colour response
/******************************************************************************/
//! Structure for registering Change Background Colour callback
typedef struct ChangeBackgroundColour_Response_Callback_S
{
   //! Object id to match
   const ObjectID_T ObjectID;
   //! Callback function pointer for Change Background Colour
   void (*ChangeBackgroundColour_Response)(VTClient_T *vt_client, const VT_T *vt, const ChangeBackgroundColour_Response_T *);
   //! Linked List node
   struct LinkedList_Node_S Node;
} ChangeBackgroundColour_Response_Callback_T;
/******************************************************************************/
/*!
   \brief    Macro used to initialize a ChangeBackgroundColour_Response_Callback_T
   \details  This macro is used to create a ChangeBackgroundColour_Response_Callback_T.
*/
/******************************************************************************/
#define MAKE_ChangeBackgroundColour_Response_Callback_T(function,object_id) {object_id, function, MAKE_LinkedList_Node_S(NULL)}
// Externing the function
/******************************************************************************/
/*! \details   Function to register object pool callbacks                     */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to register                                */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was registered                            */
/*! \retval  FALSE  if the callback was not registered                        */
/******************************************************************************/
extern bool_t ChangeBackgroundColour_Response_Register(ObjectPool_T *objectpool, ChangeBackgroundColour_Response_Callback_T *callback);
/******************************************************************************/
/*! \details   Function to unregister object pool callbacks                   */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to unregister                              */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was unregistered                          */
/*! \retval  FALSE  if the callback was not unregistered                      */
/******************************************************************************/
extern bool_t ChangeBackgroundColour_Response_Unregister(ObjectPool_T *objectpool, ChangeBackgroundColour_Response_Callback_T *callback);
/******************************************************************************/
// F.23  Change Numeric Value response
/******************************************************************************/
//! Structure for registering Change Numeric Value callback
typedef struct ChangeNumericValue_Response_Callback_S
{
   //! Object id to match
   const ObjectID_T ObjectID;
   //! Callback function pointer for Change Numeric Value
   void (*ChangeNumericValue_Response)(VTClient_T *vt_client, const VT_T *vt, const ChangeNumericValue_Response_T *);
   //! Linked List node
   struct LinkedList_Node_S Node;
} ChangeNumericValue_Response_Callback_T;
/******************************************************************************/
/*!
   \brief    Macro used to initialize a ChangeNumericValue_Response_Callback_T
   \details  This macro is used to create a ChangeNumericValue_Response_Callback_T.
*/
/******************************************************************************/
#define MAKE_ChangeNumericValue_Response_Callback_T(function,object_id) {object_id, function, MAKE_LinkedList_Node_S(NULL)}
// Externing the function
/******************************************************************************/
/*! \details   Function to register object pool callbacks                     */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to register                                */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was registered                            */
/*! \retval  FALSE  if the callback was not registered                        */
/******************************************************************************/
extern bool_t ChangeNumericValue_Response_Register(ObjectPool_T *objectpool, ChangeNumericValue_Response_Callback_T *callback);
/******************************************************************************/
/*! \details   Function to unregister object pool callbacks                   */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to unregister                              */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was unregistered                          */
/*! \retval  FALSE  if the callback was not unregistered                      */
/******************************************************************************/
extern bool_t ChangeNumericValue_Response_Unregister(ObjectPool_T *objectpool, ChangeNumericValue_Response_Callback_T *callback);
/******************************************************************************/
// F.25  Change String Value response
/******************************************************************************/
//! Structure for registering Change Numeric Value callback
typedef struct ChangeStringValue_Response_Callback_S
{
   //! Object id to match
   const ObjectID_T ObjectID;
   //! Callback function pointer for Change Numeric Value
   void (*ChangeStringValue_Response)(VTClient_T *vt_client, const VT_T *vt, const ChangeStringValue_Response_T *);
   //! Linked List node
   struct LinkedList_Node_S Node;
} ChangeStringValue_Response_Callback_T;
/******************************************************************************/
/*!
   \brief    Macro used to initialize a ChangeStringValue_Response_Callback_T
   \details  This macro is used to create a ChangeStringValue_Response_Callback_T.
*/
/******************************************************************************/
#define MAKE_ChangeStringValue_Response_Callback_T(function,object_id) {object_id, function, MAKE_LinkedList_Node_S(NULL)}
// Externing the function
/******************************************************************************/
/*! \details   Function to register object pool callbacks                     */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to register                                */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was registered                            */
/*! \retval  FALSE  if the callback was not registered                        */
/******************************************************************************/
extern bool_t ChangeStringValue_Response_Register(ObjectPool_T *objectpool, ChangeStringValue_Response_Callback_T *callback);
/******************************************************************************/
/*! \details   Function to unregister object pool callbacks                   */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to unregister                              */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was unregistered                          */
/*! \retval  FALSE  if the callback was not unregistered                      */
/******************************************************************************/
extern bool_t ChangeStringValue_Response_Unregister(ObjectPool_T *objectpool, ChangeStringValue_Response_Callback_T *callback);
/******************************************************************************/
// F.27  Change End Point response
/******************************************************************************/
//! Structure for registering Change End Point callback
typedef struct ChangeEndPoint_Response_Callback_S
{
   //! Object id to match
   const ObjectID_T ObjectID;
   //! Callback function pointer for Change End Point
   void (*ChangeEndPoint_Response)(VTClient_T *vt_client, const VT_T *vt, const ChangeEndPoint_Response_T *);
   //! Linked List node
   struct LinkedList_Node_S Node;
} ChangeEndPoint_Response_Callback_T;
/******************************************************************************/
/*!
   \brief    Macro used to initialize a ChangeEndPoint_Response_Callback_T
   \details  This macro is used to create a ChangeEndPoint_Response_Callback_T.
*/
/******************************************************************************/
#define MAKE_ChangeEndPoint_Response_Callback_T(function,object_id) {object_id, function, MAKE_LinkedList_Node_S(NULL)}
// Externing the function
/******************************************************************************/
/*! \details   Function to register object pool callbacks                     */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to register                                */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was registered                            */
/*! \retval  FALSE  if the callback was not registered                        */
/******************************************************************************/
extern bool_t ChangeEndPoint_Response_Register(ObjectPool_T *objectpool, ChangeEndPoint_Response_Callback_T *callback);
/******************************************************************************/
/*! \details   Function to unregister object pool callbacks                   */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to unregister                              */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was unregistered                          */
/*! \retval  FALSE  if the callback was not unregistered                      */
/******************************************************************************/
extern bool_t ChangeEndPoint_Response_Unregister(ObjectPool_T *objectpool, ChangeEndPoint_Response_Callback_T *callback);
/******************************************************************************/
// F.29  Change Font Attributes response
/******************************************************************************/
//! Structure for registering Change Font Attributes callback
typedef struct ChangeFontAttributes_Response_Callback_S
{
   //! Object id to match
   const ObjectID_T ObjectID;
   //! Callback function pointer for Change Font Attributes
   void (*ChangeFontAttributes_Response)(VTClient_T *vt_client, const VT_T *vt, const ChangeFontAttributes_Response_T *);
   //! Linked List node
   struct LinkedList_Node_S Node;
} ChangeFontAttributes_Response_Callback_T;
/******************************************************************************/
/*!
   \brief    Macro used to initialize a ChangeFontAttributes_Response_Callback_T
   \details  This macro is used to create a ChangeFontAttributes_Response_Callback_T.
*/
/******************************************************************************/
#define MAKE_ChangeFontAttributes_Response_Callback_T(function,object_id) {object_id, function, MAKE_LinkedList_Node_S(NULL)}
// Externing the function
/******************************************************************************/
/*! \details   Function to register object pool callbacks                     */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to register                                */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was registered                            */
/*! \retval  FALSE  if the callback was not registered                        */
/******************************************************************************/
extern bool_t ChangeFontAttributes_Response_Register(ObjectPool_T *objectpool, ChangeFontAttributes_Response_Callback_T *callback);
/******************************************************************************/
/*! \details   Function to unregister object pool callbacks                   */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to unregister                              */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was unregistered                          */
/*! \retval  FALSE  if the callback was not unregistered                      */
/******************************************************************************/
extern bool_t ChangeFontAttributes_Response_Unregister(ObjectPool_T *objectpool, ChangeFontAttributes_Response_Callback_T *callback);
/******************************************************************************/
// F.31  Change Line Attributes response
/******************************************************************************/
//! Structure for registering Change Line Attributes callback
typedef struct ChangeLineAttributes_Response_Callback_S
{
   //! Object id to match
   const ObjectID_T ObjectID;
   //! Callback function pointer for Change Line Attributes
   void (*ChangeLineAttributes_Response)(VTClient_T *vt_client, const VT_T *vt, const ChangeLineAttributes_Response_T *);
   //! Linked List node
   struct LinkedList_Node_S Node;
} ChangeLineAttributes_Response_Callback_T;
/******************************************************************************/
/*!
   \brief    Macro used to initialize a ChangeLineAttributes_Response_Callback_T
   \details  This macro is used to create a ChangeLineAttributes_Response_Callback_T.
*/
/******************************************************************************/
#define MAKE_ChangeLineAttributes_Response_Callback_T(function,object_id) {object_id, function, MAKE_LinkedList_Node_S(NULL)}
// Externing the function
/******************************************************************************/
/*! \details   Function to register object pool callbacks                     */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to register                                */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was registered                            */
/*! \retval  FALSE  if the callback was not registered                        */
/******************************************************************************/
extern bool_t ChangeLineAttributes_Response_Register(ObjectPool_T *objectpool, ChangeLineAttributes_Response_Callback_T *callback);
/******************************************************************************/
/*! \details   Function to unregister object pool callbacks                   */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to unregister                              */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was unregistered                          */
/*! \retval  FALSE  if the callback was not unregistered                      */
/******************************************************************************/
extern bool_t ChangeLineAttributes_Response_Unregister(ObjectPool_T *objectpool, ChangeLineAttributes_Response_Callback_T *callback);
/******************************************************************************/
// F.33  Change Fill Attributes response
/******************************************************************************/
//! Structure for registering Change Fill Attributes callback
typedef struct ChangeFillAttributes_Response_Callback_S
{
   //! Object id to match
   const ObjectID_T ObjectID;
   //! Callback function pointer for Change Fill Attributes
   void (*ChangeFillAttributes_Response)(VTClient_T *vt_client, const VT_T *vt, const ChangeFillAttributes_Response_T *);
   //! Linked List node
   struct LinkedList_Node_S Node;
} ChangeFillAttributes_Response_Callback_T;
/******************************************************************************/
/*!
   \brief    Macro used to initialize a ChangeFillAttributes_Response_Callback_T
   \details  This macro is used to create a ChangeFillAttributes_Response_Callback_T.
*/
/******************************************************************************/
#define MAKE_ChangeFillAttributes_Response_Callback_T(function,object_id) {object_id, function, MAKE_LinkedList_Node_S(NULL)}
// Externing the function
/******************************************************************************/
/*! \details   Function to register object pool callbacks                     */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to register                                */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was registered                            */
/*! \retval  FALSE  if the callback was not registered                        */
/******************************************************************************/
extern bool_t ChangeFillAttributes_Response_Register(ObjectPool_T *objectpool, ChangeFillAttributes_Response_Callback_T *callback);
/******************************************************************************/
/*! \details   Function to unregister object pool callbacks                   */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to unregister                              */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was unregistered                          */
/*! \retval  FALSE  if the callback was not unregistered                      */
/******************************************************************************/
extern bool_t ChangeFillAttributes_Response_Unregister(ObjectPool_T *objectpool, ChangeFillAttributes_Response_Callback_T *callback);
/******************************************************************************/
// F.35  Change Active Mask response
/******************************************************************************/
//! Structure for registering Change Active Mask callback
typedef struct ChangeActiveMask_Response_Callback_S
{
   //! Object id to match
   const ObjectID_T ObjectID;
   //! Callback function pointer for Change Active Mask
   void (*ChangeActiveMask_Response)(VTClient_T *vt_client, const VT_T *vt, const ChangeActiveMask_Response_T *);
   //! Linked List node
   struct LinkedList_Node_S Node;
} ChangeActiveMask_Response_Callback_T;
/******************************************************************************/
/*!
   \brief    Macro used to initialize a ChangeActiveMask_Response_Callback_T
   \details  This macro is used to create a ChangeActiveMask_Response_Callback_T.
*/
/******************************************************************************/
#define MAKE_ChangeActiveMask_Response_Callback_T(function,object_id) {object_id, function, MAKE_LinkedList_Node_S(NULL)}
// Externing the function
/******************************************************************************/
/*! \details   Function to register object pool callbacks                     */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to register                                */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was registered                            */
/*! \retval  FALSE  if the callback was not registered                        */
/******************************************************************************/
extern bool_t ChangeActiveMask_Response_Register(ObjectPool_T *objectpool, ChangeActiveMask_Response_Callback_T *callback);
/******************************************************************************/
/*! \details   Function to unregister object pool callbacks                   */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to unregister                              */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was unregistered                          */
/*! \retval  FALSE  if the callback was not unregistered                      */
/******************************************************************************/
extern bool_t ChangeActiveMask_Response_Unregister(ObjectPool_T *objectpool, ChangeActiveMask_Response_Callback_T *callback);
/******************************************************************************/
// F.37  Change Soft Key Mask response
/******************************************************************************/
//! Structure for registering Change Soft Key Mask callback
typedef struct ChangeSoftKeyMask_Response_Callback_S
{
   //! Object id to match
   const ObjectID_T ObjectID;
   //! Callback function pointer for Change Soft Key Mask
   void (*ChangeSoftKeyMask_Response)(VTClient_T *vt_client, const VT_T *vt, const ChangeSoftKeyMask_Response_T *);
   //! Linked List node
   struct LinkedList_Node_S Node;
} ChangeSoftKeyMask_Response_Callback_T;
/******************************************************************************/
/*!
   \brief    Macro used to initialize a ChangeSoftKeyMask_Response_Callback_T
   \details  This macro is used to create a ChangeSoftKeyMask_Response_Callback_T.
*/
/******************************************************************************/
#define MAKE_ChangeSoftKeyMask_Response_Callback_T(function,object_id) {object_id, function, MAKE_LinkedList_Node_S(NULL)}
// Externing the function
/******************************************************************************/
/*! \details   Function to register object pool callbacks                     */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to register                                */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was registered                            */
/*! \retval  FALSE  if the callback was not registered                        */
/******************************************************************************/
extern bool_t ChangeSoftKeyMask_Response_Register(ObjectPool_T *objectpool, ChangeSoftKeyMask_Response_Callback_T *callback);
/******************************************************************************/
/*! \details   Function to unregister object pool callbacks                   */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to unregister                              */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was unregistered                          */
/*! \retval  FALSE  if the callback was not unregistered                      */
/******************************************************************************/
extern bool_t ChangeSoftKeyMask_Response_Unregister(ObjectPool_T *objectpool, ChangeSoftKeyMask_Response_Callback_T *callback);
/******************************************************************************/
// F.39  Change Attribute response
/******************************************************************************/
//! Structure for registering Change Attribute callback
typedef struct ChangeAttribute_Response_Callback_S
{
   //! Object id to match
   const ObjectID_T ObjectID;
   //! Attribute id to match
   const AttributeID_T AttributeID;
   //! Callback function pointer for Change Attribute
   void (*ChangeAttribute_Response)(VTClient_T *vt_client, const VT_T *vt, const ChangeAttribute_Response_T *);
   //! Linked List node
   struct LinkedList_Node_S Node;
} ChangeAttribute_Response_Callback_T;
/******************************************************************************/
/*!
   \brief    Macro used to initialize a ChangeAttribute_Response_Callback_T
   \details  This macro is used to create a ChangeAttribute_Response_Callback_T.
*/
/******************************************************************************/
#define MAKE_ChangeAttribute_Response_Callback_T(function,object_id,attribute_id) {object_id, attribute_id, function, MAKE_LinkedList_Node_S(NULL)}
// Externing the function
/******************************************************************************/
/*! \details   Function to register object pool callbacks                     */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to register                                */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was registered                            */
/*! \retval  FALSE  if the callback was not registered                        */
/******************************************************************************/
extern bool_t ChangeAttribute_Response_Register(ObjectPool_T *objectpool, ChangeAttribute_Response_Callback_T *callback);
/******************************************************************************/
/*! \details   Function to unregister object pool callbacks                   */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to unregister                              */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was unregistered                          */
/*! \retval  FALSE  if the callback was not unregistered                      */
/******************************************************************************/
extern bool_t ChangeAttribute_Response_Unregister(ObjectPool_T *objectpool, ChangeAttribute_Response_Callback_T *callback);
/******************************************************************************/
// F.41  Change Priority response
/******************************************************************************/
//! Structure for registering Change Priority callback
typedef struct ChangePriority_Response_Callback_S
{
   //! Object id to match
   const ObjectID_T ObjectID;
   //! Callback function pointer for Change Priority
   void (*ChangePriority_Response)(VTClient_T *vt_client, const VT_T *vt, const ChangePriority_Response_T *);
   //! Linked List node
   struct LinkedList_Node_S Node;
} ChangePriority_Response_Callback_T;
/******************************************************************************/
/*!
   \brief    Macro used to initialize a ChangePriority_Response_Callback_T
   \details  This macro is used to create a ChangePriority_Response_Callback_T.
*/
/******************************************************************************/
#define MAKE_ChangePriority_Response_Callback_T(function,object_id) {object_id, function, MAKE_LinkedList_Node_S(NULL)}
// Externing the function
/******************************************************************************/
/*! \details   Function to register object pool callbacks                     */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to register                                */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was registered                            */
/*! \retval  FALSE  if the callback was not registered                        */
/******************************************************************************/
extern bool_t ChangePriority_Response_Register(ObjectPool_T *objectpool, ChangePriority_Response_Callback_T *callback);
/******************************************************************************/
/*! \details   Function to unregister object pool callbacks                   */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to unregister                              */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was unregistered                          */
/*! \retval  FALSE  if the callback was not unregistered                      */
/******************************************************************************/
extern bool_t ChangePriority_Response_Unregister(ObjectPool_T *objectpool, ChangePriority_Response_Callback_T *callback);
/******************************************************************************/
// F.43  Change List Item response
/******************************************************************************/
//! Structure for registering Change List Item callback
typedef struct ChangeListItem_Response_Callback_S
{
   //! Object id to match
   const ObjectID_T ObjectID;
   //! Callback function pointer for Change List Item
   void (*ChangeListItem_Response)(VTClient_T *vt_client, const VT_T *vt, const ChangeListItem_Response_T *);
   //! Linked List node
   struct LinkedList_Node_S Node;
} ChangeListItem_Response_Callback_T;
/******************************************************************************/
/*!
   \brief    Macro used to initialize a ChangeListItem_Response_Callback_T
   \details  This macro is used to create a ChangeListItem_Response_Callback_T.
*/
/******************************************************************************/
#define MAKE_ChangeListItem_Response_Callback_T(function,object_id) {object_id, function, MAKE_LinkedList_Node_S(NULL)}
// Externing the function
/******************************************************************************/
/*! \details   Function to register object pool callbacks                     */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to register                                */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was registered                            */
/*! \retval  FALSE  if the callback was not registered                        */
/******************************************************************************/
extern bool_t ChangeListItem_Response_Register(ObjectPool_T *objectpool, ChangeListItem_Response_Callback_T *callback);
/******************************************************************************/
/*! \details   Function to unregister object pool callbacks                   */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to unregister                              */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was unregistered                          */
/*! \retval  FALSE  if the callback was not unregistered                      */
/******************************************************************************/
extern bool_t ChangeListItem_Response_Unregister(ObjectPool_T *objectpool, ChangeListItem_Response_Callback_T *callback);
/******************************************************************************/
// F.53  Change Polygon Point response
/******************************************************************************/
//! Structure for registering Change Polygon Point callback
typedef struct ChangePolygonPoint_Response_Callback_S
{
   //! Object id to match
   const ObjectID_T ObjectID;
   //! Callback function pointer for Change Polygon Point
   void (*ChangePolygonPoint_Response)(VTClient_T *vt_client, const VT_T *vt, const ChangePolygonPoint_Response_T *);
   //! Linked List node
   struct LinkedList_Node_S Node;
} ChangePolygonPoint_Response_Callback_T;
/******************************************************************************/
/*!
   \brief    Macro used to initialize a ChangePolygonPoint_Response_Callback_T
   \details  This macro is used to create a ChangePolygonPoint_Response_Callback_T.
*/
/******************************************************************************/
#define MAKE_ChangePolygonPoint_Response_Callback_T(function,object_id) {object_id, function, MAKE_LinkedList_Node_S(NULL)}
// Externing the function
/******************************************************************************/
/*! \details   Function to register object pool callbacks                     */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to register                                */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was registered                            */
/*! \retval  FALSE  if the callback was not registered                        */
/******************************************************************************/
extern bool_t ChangePolygonPoint_Response_Register(ObjectPool_T *objectpool, ChangePolygonPoint_Response_Callback_T *callback);
/******************************************************************************/
/*! \details   Function to unregister object pool callbacks                   */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to unregister                              */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was unregistered                          */
/*! \retval  FALSE  if the callback was not unregistered                      */
/******************************************************************************/
extern bool_t ChangePolygonPoint_Response_Unregister(ObjectPool_T *objectpool, ChangePolygonPoint_Response_Callback_T *callback);
/******************************************************************************/
// F.55  Change Polygon Scale response
/******************************************************************************/
//! Structure for registering Change Polygon Scale callback
typedef struct ChangePolygonScale_Response_Callback_S
{
   //! Object id to match
   const ObjectID_T ObjectID;
   //! Callback function pointer for Change Polygon Scale
   void (*ChangePolygonScale_Response)(VTClient_T *vt_client, const VT_T *vt, const ChangePolygonScale_Response_T *);
   //! Linked List node
   struct LinkedList_Node_S Node;
} ChangePolygonScale_Response_Callback_T;
/******************************************************************************/
/*!
   \brief    Macro used to initialize a ChangePolygonScale_Response_Callback_T
   \details  This macro is used to create a ChangePolygonScale_Response_Callback_T.
*/
/******************************************************************************/
#define MAKE_ChangePolygonScale_Response_Callback_T(function,object_id) {object_id, function, MAKE_LinkedList_Node_S(NULL)}
// Externing the function
/******************************************************************************/
/*! \details   Function to register object pool callbacks                     */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to register                                */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was registered                            */
/*! \retval  FALSE  if the callback was not registered                        */
/******************************************************************************/
extern bool_t ChangePolygonScale_Response_Register(ObjectPool_T *objectpool, ChangePolygonScale_Response_Callback_T *callback);
/******************************************************************************/
/*! \details   Function to unregister object pool callbacks                   */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to unregister                              */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was unregistered                          */
/*! \retval  FALSE  if the callback was not unregistered                      */
/******************************************************************************/
extern bool_t ChangePolygonScale_Response_Unregister(ObjectPool_T *objectpool, ChangePolygonScale_Response_Callback_T *callback);
/******************************************************************************/
// F.57  Graphics Context response
/******************************************************************************/
//! Structure for registering Graphics Context callback
typedef struct GraphicsContext_Response_Callback_S
{
   //! Object id to match
   const ObjectID_T ObjectID;
   //! subcommand id to match
   const GraphicsContext_Subcommand_T SubcommandID;
   //! Callback function pointer for Graphics Context
   void (*GraphicsContext_Response)(VTClient_T *vt_client, const VT_T *vt, const GraphicsContext_Response_T *);
   //! Linked List node
   struct LinkedList_Node_S Node;
} GraphicsContext_Response_Callback_T;
/******************************************************************************/
/*!
   \brief    Macro used to initialize a GraphicsContext_Response_Callback_T
   \details  This macro is used to create a GraphicsContext_Response_Callback_T.
*/
/******************************************************************************/
#define MAKE_GraphicsContext_Response_Callback_T(function,object_id,subcommand_id) {object_id, subcommand_id, function, MAKE_LinkedList_Node_S(NULL)}
// Externing the function
/******************************************************************************/
/*! \details   Function to register object pool callbacks                     */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to register                                */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was registered                            */
/*! \retval  FALSE  if the callback was not registered                        */
/******************************************************************************/
extern bool_t GraphicsContext_Response_Register(ObjectPool_T *objectpool, GraphicsContext_Response_Callback_T *callback);
/******************************************************************************/
/*! \details   Function to unregister object pool callbacks                   */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to unregister                              */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was unregistered                          */
/*! \retval  FALSE  if the callback was not unregistered                      */
/******************************************************************************/
extern bool_t GraphicsContext_Response_Unregister(ObjectPool_T *objectpool, GraphicsContext_Response_Callback_T *callback);
/******************************************************************************/
// F.59  Get Attribute Value response
/******************************************************************************/
//! Structure for registering Get Attribute Value callback
typedef struct GetAttributeValue_Response_Callback_S
{
   //! Object id to match
   const ObjectID_T ObjectID;
   //! Attribute id to match
   const AttributeID_T AttributeID;
   //! Callback function pointer for Get Attribute Value
   void (*GetAttributeValue_Response)(VTClient_T *vt_client, const VT_T *vt, const GetAttributeValue_Response_T *);
   //! Linked List node
   struct LinkedList_Node_S Node;
} GetAttributeValue_Response_Callback_T;
/******************************************************************************/
/*!
   \brief    Macro used to initialize a GetAttributeValue_Response_Callback_T
   \details  This macro is used to create a GetAttributeValue_Response_Callback_T.
*/
/******************************************************************************/
#define MAKE_GetAttributeValue_Response_Callback_T(function,object_id,attribute_id) {object_id, attribute_id, function, MAKE_LinkedList_Node_S(NULL)}
// Externing the function
/******************************************************************************/
/*! \details   Function to register object pool callbacks                     */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to register                                */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was registered                            */
/*! \retval  FALSE  if the callback was not registered                        */
/******************************************************************************/
extern bool_t GetAttributeValue_Response_Register(ObjectPool_T *objectpool, GetAttributeValue_Response_Callback_T *callback);
/******************************************************************************/
/*! \details   Function to unregister object pool callbacks                   */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to unregister                              */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was unregistered                          */
/*! \retval  FALSE  if the callback was not unregistered                      */
/******************************************************************************/
extern bool_t GetAttributeValue_Response_Unregister(ObjectPool_T *objectpool, GetAttributeValue_Response_Callback_T *callback);
/******************************************************************************/
// F.61  Select Colour Map response
/******************************************************************************/
//! Structure for registering Select Colour Map callback
typedef struct SelectColourMap_Response_Callback_S
{
   //! Object id to match
   const ObjectID_T ObjectID;
   //! Callback function pointer for Select Colour Map
   void (*SelectColourMap_Response)(VTClient_T *vt_client, const VT_T *vt, const SelectColourMap_Response_T *);
   //! Linked List node
   struct LinkedList_Node_S Node;
} SelectColourMap_Response_Callback_T;
/******************************************************************************/
/*!
   \brief    Macro used to initialize a SelectColourMap_Response_Callback_T
   \details  This macro is used to create a SelectColourMap_Response_Callback_T.
*/
/******************************************************************************/
#define MAKE_SelectColourMap_Response_Callback_T(function,object_id) {object_id, function, MAKE_LinkedList_Node_S(NULL)}
// Externing the function
/******************************************************************************/
/*! \details   Function to register object pool callbacks                     */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to register                                */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was registered                            */
/*! \retval  FALSE  if the callback was not registered                        */
/******************************************************************************/
extern bool_t SelectColourMap_Response_Register(ObjectPool_T *objectpool, SelectColourMap_Response_Callback_T *callback);
/******************************************************************************/
/*! \details   Function to unregister object pool callbacks                   */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to unregister                              */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was unregistered                          */
/*! \retval  FALSE  if the callback was not unregistered                      */
/******************************************************************************/
extern bool_t SelectColourMap_Response_Unregister(ObjectPool_T *objectpool, SelectColourMap_Response_Callback_T *callback);
/******************************************************************************/
// F.63  Identify VT response
/******************************************************************************/
/******************************************************************************/
// Annex H  Activation messages
/******************************************************************************/
/******************************************************************************/
// H.2  Soft Key Activation message
/******************************************************************************/
//! Structure for registering Soft Key Activation callback
typedef struct SoftKeyActivation_Callback_S
{
   //! Object id to match
   const ObjectID_T ObjectID;
   //! Callback function pointer for Soft Key Activation
   void (*SoftKeyActivation)(VTClient_T *vt_client, const VT_T *vt, const SoftKeyActivation_T *);
   //! Linked List node
   struct LinkedList_Node_S Node;
} SoftKeyActivation_Callback_T;
/******************************************************************************/
/*!
   \brief    Macro used to initialize a SoftKeyActivation_Callback_T
   \details  This macro is used to create a SoftKeyActivation_Callback_T.
*/
/******************************************************************************/
#define MAKE_SoftKeyActivation_Callback_T(function,object_id) {object_id, function, MAKE_LinkedList_Node_S(NULL)}
// Externing the function
/******************************************************************************/
/*! \details   Function to register object pool callbacks                     */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to register                                */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was registered                            */
/*! \retval  FALSE  if the callback was not registered                        */
/******************************************************************************/
extern bool_t SoftKeyActivation_Register(ObjectPool_T *objectpool, SoftKeyActivation_Callback_T *callback);
/******************************************************************************/
/*! \details   Function to unregister object pool callbacks                   */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to unregister                              */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was unregistered                          */
/*! \retval  FALSE  if the callback was not unregistered                      */
/******************************************************************************/
extern bool_t SoftKeyActivation_Unregister(ObjectPool_T *objectpool, SoftKeyActivation_Callback_T *callback);
/******************************************************************************/
// H.4  Button Activation message
/******************************************************************************/
//! Structure for registering Button Activation callback
typedef struct ButtonActivation_Callback_S
{
   //! Object id to match
   const ObjectID_T ObjectID;
   //! Callback function pointer for Button Activation
   void (*ButtonActivation)(VTClient_T *vt_client, const VT_T *vt, const ButtonActivation_T *);
   //! Linked List node
   struct LinkedList_Node_S Node;
} ButtonActivation_Callback_T;
/******************************************************************************/
/*!
   \brief    Macro used to initialize a ButtonActivation_Callback_T
   \details  This macro is used to create a ButtonActivation_Callback_T.
*/
/******************************************************************************/
#define MAKE_ButtonActivation_Callback_T(function,object_id) {object_id, function, MAKE_LinkedList_Node_S(NULL)}
// Externing the function
/******************************************************************************/
/*! \details   Function to register object pool callbacks                     */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to register                                */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was registered                            */
/*! \retval  FALSE  if the callback was not registered                        */
/******************************************************************************/
extern bool_t ButtonActivation_Register(ObjectPool_T *objectpool, ButtonActivation_Callback_T *callback);
/******************************************************************************/
/*! \details   Function to unregister object pool callbacks                   */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to unregister                              */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was unregistered                          */
/*! \retval  FALSE  if the callback was not unregistered                      */
/******************************************************************************/
extern bool_t ButtonActivation_Unregister(ObjectPool_T *objectpool, ButtonActivation_Callback_T *callback);
/******************************************************************************/
// H.8  VT Select Input Object message
/******************************************************************************/
//! Structure for registering VT Select Input Object callback
typedef struct VtSelectInputObject_Callback_S
{
   //! Object id to match
   const ObjectID_T ObjectID;
   //! Callback function pointer for VT Select Input Object
   void (*VtSelectInputObject)(VTClient_T *vt_client, const VT_T *vt, const VtSelectInputObject_T *);
   //! Linked List node
   struct LinkedList_Node_S Node;
} VtSelectInputObject_Callback_T;
/******************************************************************************/
/*!
   \brief    Macro used to initialize a VtSelectInputObject_Callback_T
   \details  This macro is used to create a VtSelectInputObject_Callback_T.
*/
/******************************************************************************/
#define MAKE_VtSelectInputObject_Callback_T(function,object_id) {object_id, function, MAKE_LinkedList_Node_S(NULL)}
// Externing the function
/******************************************************************************/
/*! \details   Function to register object pool callbacks                     */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to register                                */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was registered                            */
/*! \retval  FALSE  if the callback was not registered                        */
/******************************************************************************/
extern bool_t VtSelectInputObject_Register(ObjectPool_T *objectpool, VtSelectInputObject_Callback_T *callback);
/******************************************************************************/
/*! \details   Function to unregister object pool callbacks                   */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to unregister                              */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was unregistered                          */
/*! \retval  FALSE  if the callback was not unregistered                      */
/******************************************************************************/
extern bool_t VtSelectInputObject_Unregister(ObjectPool_T *objectpool, VtSelectInputObject_Callback_T *callback);
/******************************************************************************/
// H.10  VT ESC message
/******************************************************************************/
//! Structure for registering VT ESC callback
typedef struct VtEsc_Callback_S
{
   //! Object id to match
   const ObjectID_T ObjectID;
   //! Callback function pointer for VT ESC
   void (*VtEsc)(VTClient_T *vt_client, const VT_T *vt, const VtEsc_T *);
   //! Linked List node
   struct LinkedList_Node_S Node;
} VtEsc_Callback_T;
/******************************************************************************/
/*!
   \brief    Macro used to initialize VtEsc_Callback_T
   \details  This macro is used to create a VtEsc_Callback_T.
*/
/******************************************************************************/
#define MAKE_VtEsc_Callback_T(function,object_id) {object_id, function, MAKE_LinkedList_Node_S(NULL)}
// Externing the function
/******************************************************************************/
/*! \details   Function to register object pool callbacks                     */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to register                                */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was registered                            */
/*! \retval  FALSE  if the callback was not registered                        */
/******************************************************************************/
extern bool_t VtEsc_Register(ObjectPool_T *objectpool, VtEsc_Callback_T *callback);
/******************************************************************************/
/*! \details   Function to unregister object pool callbacks                   */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to unregister                              */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was unregistered                          */
/*! \retval  FALSE  if the callback was not unregistered                      */
/******************************************************************************/
extern bool_t VtEsc_Unregister(ObjectPool_T *objectpool, VtEsc_Callback_T *callback);
/******************************************************************************/
// H.12  VT Change Numeric Value message
/******************************************************************************/
//! Structure for registering VT Change Numeric Value callback
typedef struct VtChangeNumericValue_Callback_S
{
   //! Object id to match
   const ObjectID_T ObjectID;
   //! Callback function pointer for VT Change Numeric Value
   void (*VtChangeNumericValue)(VTClient_T *vt_client, const VT_T *vt, const VtChangeNumericValue_T *);
   //! Linked List node
   struct LinkedList_Node_S Node;
} VtChangeNumericValue_Callback_T;
/******************************************************************************/
/*!
   \brief    Macro used to initialize a VtChangeNumericValue_Callback_T
   \details  This macro is used to create a VtChangeNumericValue_Callback_T.
*/
/******************************************************************************/
#define MAKE_VtChangeNumericValue_Callback_T(function,object_id) {object_id, function, MAKE_LinkedList_Node_S(NULL)}
// Externing the function
/******************************************************************************/
/*! \details   Function to register object pool callbacks                     */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to register                                */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was registered                            */
/*! \retval  FALSE  if the callback was not registered                        */
/******************************************************************************/
extern bool_t VtChangeNumericValue_Register(ObjectPool_T *objectpool, VtChangeNumericValue_Callback_T *callback);
/******************************************************************************/
/*! \details   Function to unregister object pool callbacks                   */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to unregister                              */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was unregistered                          */
/*! \retval  FALSE  if the callback was not unregistered                      */
/******************************************************************************/
extern bool_t VtChangeNumericValue_Unregister(ObjectPool_T *objectpool, VtChangeNumericValue_Callback_T *callback);
/******************************************************************************/
// H.14  VT Change Active Mask message
/******************************************************************************/
//! Structure for registering VT Change Active Mask callback
typedef struct VtChangeActiveMask_Callback_S
{
   //! Object id to match
   const ObjectID_T ObjectID;
   //! Callback function pointer for VT Change Active Mask
   void (*VtChangeActiveMask)(VTClient_T *vt_client, const VT_T *vt, const VtChangeActiveMask_T *);
   //! Linked List node
   struct LinkedList_Node_S Node;
} VtChangeActiveMask_Callback_T;
/******************************************************************************/
/*!
   \brief    Macro used to initialize a VtChangeActiveMask_Callback_T
   \details  This macro is used to create a VtChangeActiveMask_Callback_T.
*/
/******************************************************************************/
#define MAKE_VtChangeActiveMask_Callback_T(function,object_id) {object_id, function, MAKE_LinkedList_Node_S(NULL)}
// Externing the function
/******************************************************************************/
/*! \details   Function to register object pool callbacks                     */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to register                                */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was registered                            */
/*! \retval  FALSE  if the callback was not registered                        */
/******************************************************************************/
extern bool_t VtChangeActiveMask_Register(ObjectPool_T *objectpool, VtChangeActiveMask_Callback_T *callback);
/******************************************************************************/
/*! \details   Function to unregister object pool callbacks                   */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to unregister                              */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was unregistered                          */
/*! \retval  FALSE  if the callback was not unregistered                      */
/******************************************************************************/
extern bool_t VtChangeActiveMask_Unregister(ObjectPool_T *objectpool, VtChangeActiveMask_Callback_T *callback);
/******************************************************************************/
// H.16  VT Change Soft Key Mask message
/******************************************************************************/
//! Structure for registering VT Change Soft Key Mask callback
typedef struct VtChangeSoftKeyMask_Callback_S
{
   //! Object id to match
   const ObjectID_T ObjectID;
   //! Callback function pointer for VT Change Soft Key Mask
   void (*VtChangeSoftKeyMask)(VTClient_T *vt_client, const VT_T *vt, const VtChangeSoftKeyMask_T *);
   //! Linked List node
   struct LinkedList_Node_S Node;
} VtChangeSoftKeyMask_Callback_T;
/******************************************************************************/
/*!
   \brief    Macro used to initialize a VtChangeSoftKeyMask_Callback_T
   \details  This macro is used to create a VtChangeSoftKeyMask_Callback_T.
*/
/******************************************************************************/
#define MAKE_VtChangeSoftKeyMask_Callback_T(function,object_id) {object_id, function, MAKE_LinkedList_Node_S(NULL)}
// Externing the function
/******************************************************************************/
/*! \details   Function to register object pool callbacks                     */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to register                                */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was registered                            */
/*! \retval  FALSE  if the callback was not registered                        */
/******************************************************************************/
extern bool_t VtChangeSoftKeyMask_Register(ObjectPool_T *objectpool, VtChangeSoftKeyMask_Callback_T *callback);
/******************************************************************************/
/*! \details   Function to unregister object pool callbacks                   */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to unregister                              */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was unregistered                          */
/*! \retval  FALSE  if the callback was not unregistered                      */
/******************************************************************************/
extern bool_t VtChangeSoftKeyMask_Unregister(ObjectPool_T *objectpool, VtChangeSoftKeyMask_Callback_T *callback);
/******************************************************************************/
// H.18  VT Change String Value message
/******************************************************************************/
//! Structure for registering VT Change String Value callback
typedef struct VtChangeStringValue_Callback_S
{
   //! Object id to match
   const ObjectID_T ObjectID;
   //! Callback function pointer for VT Change String Value
   void (*VtChangeStringValue)(VTClient_T *vt_client, const VT_T *vt, VtChangeStringValue_T *);
   //! Linked List node
   struct LinkedList_Node_S Node;
} VtChangeStringValue_Callback_T;
/******************************************************************************/
/*!
   \brief    Macro used to initialize a VtChangeStringValue_Callback_T
   \details  This macro is used to create a VtChangeStringValue_Callback_T.
*/
/******************************************************************************/
#define MAKE_VtChangeStringValue_Callback_T(function,object_id) {object_id, function, MAKE_LinkedList_Node_S(NULL)}
// Externing the function
/******************************************************************************/
/*! \details   Function to register object pool callbacks                     */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to register                                */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was registered                            */
/*! \retval  FALSE  if the callback was not registered                        */
/******************************************************************************/
extern bool_t VtChangeStringValue_Register(ObjectPool_T *objectpool, VtChangeStringValue_Callback_T *callback);
/******************************************************************************/
/*! \details   Function to unregister object pool callbacks                   */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to unregister                              */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was unregistered                          */
/*! \retval  FALSE  if the callback was not unregistered                      */
/******************************************************************************/
extern bool_t VtChangeStringValue_Unregister(ObjectPool_T *objectpool, VtChangeStringValue_Callback_T *callback);
/******************************************************************************/
// H.20  VT On User-Layout Hide/Show message
/******************************************************************************/
//! Structure for registering VT On User-Layout Hide/Show callback
typedef struct VtOnUserLayoutHideShow_Callback_S
{
   //! Object id to match
   const ObjectID_T ObjectID;
   //! Callback function pointer for VT On User-Layout Hide/Show
   void (*VtOnUserLayoutHideShow)(VTClient_T *vt_client, const VT_T *vt, const VtOnUserLayoutHideShow_T *);
   //! Linked List node
   struct LinkedList_Node_S Node;
} VtOnUserLayoutHideShow_Callback_T;
/******************************************************************************/
/*!
   \brief    Macro used to initialize a VtOnUserLayoutHideShow_Callback_T
   \details  This macro is used to create a VtOnUserLayoutHideShow_Callback_T.
*/
/******************************************************************************/
#define MAKE_VtOnUserLayoutHideShow_Callback_T(function,object_id) {object_id, function, MAKE_LinkedList_Node_S(NULL)}
// Externing the function
/******************************************************************************/
/*! \details   Function to register object pool callbacks                     */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to register                                */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was registered                            */
/*! \retval  FALSE  if the callback was not registered                        */
/******************************************************************************/
extern bool_t VtOnUserLayoutHideShow_Register(ObjectPool_T *objectpool, VtOnUserLayoutHideShow_Callback_T *callback);
/******************************************************************************/
/*! \details   Function to unregister object pool callbacks                   */
/*! \param   objectpool   Applicable object pool                              */
/*! \param   callback     Callback to unregister                              */
/*! \return  bool_t                                                           */
/*! \retval  TRUE   if the callback was unregistered                          */
/*! \retval  FALSE  if the callback was not unregistered                      */
/******************************************************************************/
extern bool_t VtOnUserLayoutHideShow_Unregister(ObjectPool_T *objectpool, VtOnUserLayoutHideShow_Callback_T *callback);
/******************************************************************************/
/*!
   \details   Function to initialize object pool callbacks
   \param   object_pool   Applicable object pool
*/
/******************************************************************************/
extern void ObjectPool_Init(ObjectPool_T *object_pool);
/******************************************************************************/
// VT Callbacks Register Functions
/******************************************************************************/
/******************************************************************************/
/*!
   \brief    Function to register a PointingEvent Message callback.
   \details  This function registers the given VT callback globally (for
             messages received from all active VTs).
   \param    vt_client  pointer to VT client struct.
   \param    PointingEvent_Message  function pointer to callback.
*/
/******************************************************************************/
extern void PointingEvent_Response_Callback_Register(VTClient_T *vt_client, void(*PointingEvent_Message)(VTClient_T *vt_client, const VT_T *vt, const PointingEvent_T *));
/******************************************************************************/
/*!
   \brief    Function to register a VtControlAudioSignalTermination Message callback.
   \details  This function registers the given VT callback globally (for
             messages received from all active VTs).
   \param    vt_client  pointer to VT client struct.
   \param    VtControlAudioSignalTermination_Message  function pointer to callback.
*/
/******************************************************************************/
extern void VtControlAudioSignalTermination_Callback_Register(VTClient_T *vt_client, void(*VtControlAudioSignalTermination_Message)(VTClient_T *vt_client, const VT_T *vt, const VtControlAudioSignalTermination_T *));
/******************************************************************************/
/*!
   \brief    Function to register a GetMemory Response callback.
   \details  This function registers the given VT callback globally (for
             messages received from all active VTs).
   \param    vt_client  pointer to VT client struct.
   \param    GetMemory_Response  function pointer to callback.
*/
/******************************************************************************/
extern void GetMemory_Response_Callback_Register(VTClient_T *vt_client, void(*GetMemory_Response)(VTClient_T *vt_client, const VT_T *vt, const GetMemory_Response_T *));
/******************************************************************************/
/*!
   \brief    Function to register a GetNumberOfSoftKeys Response callback.
   \details  This function registers the given VT callback globally (for
             messages received from all active VTs).
   \param    vt_client  pointer to VT client struct.
   \param    GetNumberOfSoftKeys_Response  function pointer to callback.
*/
/******************************************************************************/
extern void GetNumberOfSoftKeys_Callback_Register(VTClient_T *vt_client, void(*GetNumberOfSoftKeys_Response)(VTClient_T *vt_client, const VT_T *vt, const GetSoftKeys_Response_T *));
/******************************************************************************/
/*!
   \brief    Function to register a GetTextFontData Response callback.
   \details  This function registers the given VT callback globally (for
             messages received from all active VTs).
   \param    vt_client  pointer to VT client struct.
   \param    GetTextFontData_Response  function pointer to callback.
*/
/******************************************************************************/
extern void GetTextFontData_Callback_Register(VTClient_T *vt_client, void(*GetTextFontData_Response)(VTClient_T *vt_client, const VT_T *vt, const GetTextFont_Response_T *));
/******************************************************************************/
/*!
   \brief    Function to register a GetHardware Response callback.
   \details  This function registers the given VT callback globally (for
             messages received from all active VTs).
   \param    vt_client  pointer to VT client struct.
   \param    GetHardware_Response  function pointer to callback.
*/
/******************************************************************************/
extern void GetHardware_Callback_Register(VTClient_T *vt_client, void(*GetHardware_Response)(VTClient_T *vt_client, const VT_T *vt, const GetHardware_Response_T *));
/******************************************************************************/
/*!
   \brief    Function to register a GetSupportedWideChars Response callback.
   \details  This function registers the given VT callback globally (for
             messages received from all active VTs).
   \param    vt_client  pointer to VT client struct.
   \param    GetSupportedWideChars_Response  function pointer to callback.
*/
/******************************************************************************/
extern void GetSupportedWideChars_Callback_Register(VTClient_T *vt_client, void(*GetSupportedWideChars_Response)(VTClient_T *vt_client, const VT_T *vt, void *));
/******************************************************************************/
/*!
   \brief    Function to register a GetWindowMaskData Response callback.
   \details  This function registers the given VT callback globally (for
             messages received from all active VTs).
   \param    vt_client  pointer to VT client struct.
   \param    GetWindowMaskData_Response  function pointer to callback.
*/
/******************************************************************************/
extern void GetWindowMaskData_Callback_Register(VTClient_T *vt_client, void(*GetWindowMaskData_Response)(VTClient_T *vt_client, const VT_T *vt, const GetWindowMask_Response_T *));
/******************************************************************************/
/*!
   \brief    Function to register a GetSupportedObjects Response callback.
   \details  This function registers the given VT callback globally (for
             messages received from all active VTs).
   \param    vt_client  pointer to VT client struct.
   \param    GetSupportedObjects_Response  function pointer to callback.
*/
/******************************************************************************/
extern void GetSupportedObjects_Callback_Register(VTClient_T *vt_client, void(*GetSupportedObjects_Response)(VTClient_T *vt_client, const VT_T *vt, void *));
/******************************************************************************/
/*!
   \brief    Function to register a GetVersions Response callback.
   \details  This function registers the given VT callback globally (for
             messages received from all active VTs).
   \param    vt_client  pointer to VT client struct.
   \param    GetVersions_Response  function pointer to callback.
*/
/******************************************************************************/
extern void GetVersions_Callback_Register(VTClient_T *vt_client, void(*GetVersions_Response)(VTClient_T *vt_client, const VT_T *vt, GetVersions_Response_T *));
/******************************************************************************/
/*!
   \brief    Function to register a StoreVersion Response callback.
   \details  This function registers the given VT callback globally (for
             messages received from all active VTs).
   \param    vt_client  pointer to VT client struct.
   \param    StoreVersion_Response  function pointer to callback.
*/
/******************************************************************************/
extern void StoreVersion_Callback_Register(VTClient_T *vt_client, void(*StoreVersion_Response)(VTClient_T *vt_client, const VT_T *vt, const StoreVersion_Response_T *));
/******************************************************************************/
/*!
  \brief    Function to register a LoadVersion Response callback.
  \details  This function registers the given VT callback globally (for
            messages received from all active VTs).
  \param    vt_client  pointer to VT client struct.
  \param    LoadVersion_Response  function pointer to callback.
*/
/******************************************************************************/
extern void LoadVersion_Callback_Register(VTClient_T *vt_client, void(*LoadVersion_Response)(VTClient_T *vt_client, const VT_T *vt, const LoadVersion_Response_T *));
/******************************************************************************/
/*!
   \brief    Function to register a DeleteVersion Response callback.
   \details  This function registers the given VT callback globally (for
             messages received from all active VTs).
   \param    vt_client  pointer to VT client struct.
   \param    DeleteVersion_Response  function pointer to callback.
*/
/******************************************************************************/
extern void DeleteVersion_Callback_Register(VTClient_T *vt_client, void(*DeleteVersion_Response)(VTClient_T *vt_client, const VT_T *vt, const DeleteVersion_Response_T *));
/******************************************************************************/
/*!
   \brief    Function to register a ControlAudioSignal Response callback.
   \details  This function registers the given VT callback globally (for
             messages received from all active VTs).
   \param    vt_client  pointer to VT client struct.
   \param    ControlAudioSignal_Response  function pointer to callback.
*/
/******************************************************************************/
extern void ControlAudioSignal_Callback_Register(VTClient_T *vt_client, void(*ControlAudioSignal_Response)(VTClient_T *vt_client, const VT_T *vt, const ControlAudioSignal_Response_T *));
/******************************************************************************/
/*!
   \brief    Function to register a SetAudioVolume Response callback.
   \details  This function registers the given VT callback globally (for
             messages received from all active VTs).
   \param    vt_client  pointer to VT client struct.
   \param    SetAudioVolume_Response  function pointer to callback.
*/
/******************************************************************************/
extern void SetAudioVolume_Callback_Register(VTClient_T *vt_client, void(*SetAudioVolume_Response)(VTClient_T *vt_client, const VT_T *vt, const SetAudioVolume_Response_T *));
/******************************************************************************/
/*!
   \brief    Function to register a LockUnlockMask Response callback.
   \details  This function registers the given VT callback globally (for
              messages received from all active VTs).
   \param    vt_client  pointer to VT client struct.
   \param    LockUnlockMask_Response  function pointer to callback.
*/
/******************************************************************************/
extern void LockUnlockMask_Callback_Register(VTClient_T *vt_client, void(*LockUnlockMask_Response)(VTClient_T *vt_client, const VT_T *vt, const LockUnlockMask_Response_T *));
/******************************************************************************/
/*!
   \brief    Function to register a ExecuteMacro Response callback.
   \details  This function registers the given VT callback globally (for
             messages received from all active VTs).
   \param    vt_client  pointer to VT client struct.
   \param    ExecuteMacro_Response  function pointer to callback.
*/
/******************************************************************************/
extern void ExecuteMacro_Callback_Register(VTClient_T *vt_client, void(*ExecuteMacro_Response)(VTClient_T *vt_client, const VT_T *vt, const ExecuteMacro_Response_T *));
/******************************************************************************/
/*!
   \brief    Function to register a ChangeObjectLabel Response callback.
   \details  This function registers the given VT callback globally (for
             messages received from all active VTs).
   \param    vt_client  pointer to VT client struct.
   \param    ChangeObjectLabel_Response  function pointer to callback.
*/
/******************************************************************************/
extern void ChangeObjectLabel_Callback_Register(VTClient_T *vt_client, void(*ChangeObjectLabel_Response)(VTClient_T *vt_client, const VT_T *vt, const ChangeObjectLabel_Response_T *));
/******************************************************************************/
/*
   Copyright (C) 2016  DISTek Integration, Inc.  All Rights Reserved.
   Developed by:
      DISTek(R) Integration, Inc.
      6612 Chancellor Drive Suite 600
      Cedar Falls, IA 50613
      Tel: 319-859-3600
*/
/******************************************************************************/
#endif //VTCLIENT_H
