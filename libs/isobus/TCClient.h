#ifndef TCCLIENT_H
#define TCCLIENT_H
/******************************************************************************/
/*!
   \file
      TC Client API
   \copyright
      Copyright (C) 2018  DISTek Integration, Inc.  All Rights Reserved.
*/
/******************************************************************************/
//! Version of the TC Client Library  (Product,Major,minor,build)
#define TCCLIENT_VERSION SoftwareVersion("TCClient",2,0,beta6)
//##############################################################################
// Note:  The following macros are for easily initializing the Functionalities_T
//        structure in the Foundation library with the functionalities and
//        Functionality Generations provided by the TCClient library.
//
// EACH APPLICATION MUST REPORT THE CORRECT FUNCTIONALITIES IN ORDER TO PASS THE
// AEF CONFORMANCE TESTS REQUIRED FOR CERTIFICATION
//##############################################################################
/******************************************************************************/
/*!
   \brief  Initializes the Functionalities_T structure for a Task Controller Basic Working Set
*/
/******************************************************************************/
#define MAKE_Functionalities_T__TaskController_Basic_WorkingSet() MAKE_Functionalities_T ( Functionality_TaskController_Basic_WorkingSet, (FunctionalityGeneration_T)1, (Size_T)0, (ISOBUS_PacketData_T)0x00, (ISOBUS_PacketData_T)0x00 )
/******************************************************************************/
/*!
\brief  Initializes the Functionalities_T structure for a Task Controller Geo
Working Set
\param  number_of_channels          Number of supported channels
\param  polygon_prescription_maps   Supports polygon prescription maps  (0=no, 1=yes)
*/
/******************************************************************************/
#define MAKE_Functionalities_T__TaskController_Geo_WorkingSet(number_of_channels,polygon_prescription_maps) MAKE_Functionalities_T ( Functionality_TaskController_Geo_WorkingSet, (FunctionalityGeneration_T)1, (Size_T)((polygon_prescription_maps == 0) ? (1) : (2)), ( (ISOBUS_PacketData_T)number_of_channels ), ( (ISOBUS_PacketData_T)polygon_prescription_maps & (ISOBUS_PacketData_T)1 ) )
/******************************************************************************/
/*!
\brief  Initializes the Functionalities_T structure for a Task Controller Section
Control Working Set
\param  number_of_booms      Number of supported booms
\param  number_of_sections   Number of supported sections
*/
/******************************************************************************/
#define MAKE_Functionalities_T__TaskController_SectionControl_WorkingSet(number_of_booms,number_of_sections) MAKE_Functionalities_T ( Functionality_TaskController_SectionControl_WorkingSet, (FunctionalityGeneration_T)1, (Size_T)2, ( (ISOBUS_PacketData_T)number_of_booms ), ( (ISOBUS_PacketData_T)number_of_sections ) )
//! Type used to track the ISOBUS 11783-10 supported options
typedef uint16_t TCClient_SupportedOptions_T;
//! Supported Option: TC-BAS functionality, documentation, and task totals
#define TC_BAS ((TCClient_SupportedOptions_T)0x01)
//! Supported Option: TC-GEO functionality without position-based control
#define TC_GEO_WITHOUT_POSITION_BASED_CONTROL ((TCClient_SupportedOptions_T)0x02)
//! Supported Option: TC-GEO functionality with position-based control
#define TC_GEO_WITH_POSITION_BASED_CONTROL ((TCClient_SupportedOptions_T)0x04)
//! Supported Option: TC-SC functionality
#define TC_SC ((TCClient_SupportedOptions_T)0x10)
//! Type used to track of capable section control - booms
typedef uint8_t TCClient_CapableBooms_T;
//! Type used to track capable section control - sections
typedef uint8_t TCClient_CapableSections_T;
//! Type used to track capable postion based control - control channels
typedef uint8_t TCClient_ControlChannels_T;
/******************************************************************************/
//! Structure to hold TCClient's capabilities
typedef struct TCClient_Capabilities_S
{
   //! ISOBUS 11783-10 Supported Options
   TCClient_SupportedOptions_T SupportedOptions;
   //! Number of Capable Section Control - Booms
   TCClient_CapableBooms_T NumberOfCapableSectionControl_Booms;
   //! Number of Capable Section Control - Sections
   TCClient_CapableSections_T NumberOfCapableSectionControl_Sections;
   //! Number of Capable Position Based Control - Control Channels
   TCClient_ControlChannels_T NumberOfCapablePostionBasedControl_ControlChannels;
} TCClient_Capabilities_T;
/******************************************************************************/
/*!
\brief  Macro for initializing TC_Capabilities_T structure
\param  options   ISOBUS 11783-10 Supported Options
\param  booms     Number of Capable Section Control - Booms
\param  sections  Number of Capable Section Control - Sections
\param  channels  Number of Capable Position Based Control - Control Channels
*/
/******************************************************************************/
#define MAKE_TCCapabilities_T(options,booms,sections,channels) { (TCClient_SupportedOptions_T)options, (TCClient_CapableBooms_T)booms, (TCClient_CapableSections_T)sections, (TCClient_ControlChannels_T)channels }
// Include structures from header files related to TC Client
//! Type used to track the number of bytes
typedef uint8_t TC_NumberOfBytes_255Max_T;
//! Type used to track the number of decimal places
typedef uint8_t TC_NumberOfDecimals_255Max_T;
//! Type used to store one byte of a structure label
typedef uint8_t TC_StructureLabelByte_T;
//! Type used to store one byte of a localization label
typedef uint8_t TC_LocalizationLabelByte_T;
//! Type used to store a TC Object ID
typedef uint16_t TC_ObjectID_T;
//! Type used to represent an Element Number
typedef uint16_t TC_ElementNumber_T;
//! Type used to represent the number of objects in a collection
typedef uint16_t TC_NumObjects_T;
//! Type used to represent a DDI (Data Dictionary Identifier)
typedef uint16_t TC_DDI_T;
//! Type used to represent a device property value
typedef int32_t TC_DevicePropertyValue_T;
//! Type used to represent a device property value
typedef int32_t TC_DVP_Offset_T;
//! enum list of TC device types
typedef enum TC_DeviceElementType_E
{
  //! Used only for looping over this enum type
  FIRST_DEVICE_TYPE = 1,
  //! represents the complete device and makes it addressable for the task controller. DDOP shall have at least one.
  TC_DeviceElementType_Device = FIRST_DEVICE_TYPE,
  //! Can be used as a generic device element to define individually accessible components of a device like valves or sensors.
  TC_DeviceElementType_Function = 2,
  //! Example: the tank of a sprayer or the bin of a seeder.
  TC_DeviceElementType_Bin = 3,
  //! Example: section of a spray boom, seed toolbar or planter toolbar. A section may provide device geometry definitions(x, y, z) and a working width next to supported process data elements as device process variable values or device property values.
  TC_DeviceElementType_Section = 4,
  //! This device element type is, for example, used for spray boom nozzles, seeder openers or planter row units. It is intended as a layer below the device element type section in the hierarchical device element structure.
  TC_DeviceElementType_Unit = 5,
  //! This device element type specifies the mounting/connection position of the device. More than one connector can be defined for one device(e.g.a tractor may provide front - end mounting and rear - end mounting connection locations).A connector element shall provide its device geometry definitions(x, y, z) relative to the device reference point as device process data values or as device property values, even when the device reference point is the same as the location of the connector(x = y = z = 0).
  TC_DeviceElementType_Connector = 6,
  //! This device element type defines the navigation reference position for navigation devices such as GPS receivers.Such elements have to reference their position in the x - , y - , and z - direction as device process data values or device property values.
  TC_DeviceElementType_NavigationReference = 7,
  //! Used only for looping over this enum type
  MAX_DEVICE_TYPES
} TC_DeviceElementType_T;
//! Type used to store DPD Properties
typedef uint8_t TC_DPD_Properties_Bitmask_T;
//! Type used to store trigger methods
typedef uint8_t TC_DPD_TriggerMethodsBitmask_T;
////////////////////////////////////////////////////////////////////////////////
// Object Pool Definition (modified from VIRTEC)
////////////////////////////////////////////////////////////////////////////////
//! Stores one part of an object pool. Object Pool information
typedef struct TC_ObjectPoolPart_S
{
   //! Object Pool Data
   MemoryPointer_T Data;
   //! Size of Object Pool Data
   Size_T Size;
} TC_ObjectPoolPart_T;
//! \bug  Should use a macro to initialize the MemoryPointer_T
#define MAKE_TC_ObjectPoolPart_T(object_pool) {MAKE_MemoryPointer_T(object_pool), SIZEOF(object_pool)}
//! Combines Object Pool Parts into a complete Object Pool
typedef struct TC_ObjectPoolParts_S
{
   //! Data for each part of the object pool
   TC_ObjectPoolPart_T *Parts;
   //! Number of parts to the object pool
   Size_T NumParts;
   //! App's object pool version string
   ISOBUS_PacketData_T Structure_Label[7];
} TC_ObjectPoolParts_T;
//! Macro used to process Object Pool Parts
#define MAKE_TC_ObjectPoolParts_T(object_pool_parts,version) {object_pool_parts, SIZEOF(object_pool_parts)/SIZEOF(TC_ObjectPoolPart_T), version}
/******************************************************************************/
//! Type used to track a PDV trigger method
typedef uint8_t TC_StringLength_T;
//! Type used to track error codes for process data
typedef uint8_t TC_PD_ErrorCode_T;
//! Type to hold the Device Element Number
typedef uint16_t TC_DetElementNumber_T;
//! Type to hold the Device Process Data (DPD) properties
typedef uint8_t TC_DpdProperties_T;
//! Type to hold the Device Process Data (DPD) Available Trigger Methods
typedef uint8_t TC_DpdAvailableTriggerMethods_T;
//! Type to hold a DPT value
typedef int32_t TC_DptValue_T;
//! Type to hold a DVP offset
typedef int32_t TC_DvpOffset_T;
//! Type to hold a DVP scale
typedef float32_t TC_DvpScale_T;
//! Type to hold the number of designator bytes (0-32 bytes for TCv3)
typedef uint8_t TC_NumOfDecimals_T;
//! Enumeration containing all possible states for inserting a DDOP into a Pipe_T for transmission with a TP or ETP
//lint -e788  Suppress warnings for enumeration constants not used within defaulted switch
typedef enum TC_DDOP_InsertState_E
{
   TC_DDOP_Idle,
   TC_DDOP_SerializeDVC,
   TC_DDOP_InsertDvc,
   // DVC states
   TC_DDOP_DVC_Init,
   TC_DDOP_DVC_TableID,
   TC_DDOP_DVC_ObjectID,
   TC_DDOP_DVC_DesignatorLength,
   TC_DDOP_DVC_Designator,
   TC_DDOP_DVC_VersionLength,
   TC_DDOP_DVC_Version,
   TC_DDOP_DVC_NAME,
   TC_DDOP_DVC_SerialLength,
   TC_DDOP_DVC_SerialNumber,
   TC_DDOP_DVC_StructureLabel,
   TC_DDOP_DVC_Localization,
   TC_DDOP_SerializeDETs,
   TC_DDOP_InsertDets,
   // DET states
   TC_DDOP_DET_Init,
   TC_DDOP_DET_TableID,
   TC_DDOP_DET_ObjectID,
   TC_DDOP_DET_ElementType,
   TC_DDOP_DET_DesignatorLength,
   TC_DDOP_DET_Designator,
   TC_DDOP_DET_ElementNumber,
   TC_DDOP_DET_ParentObjectID,
   TC_DDOP_DET_NumberOfObjects,
   TC_DDOP_DET_ChildObjects,
   TC_DDOP_SerializeDPDs,
   TC_DDOP_InsertDpds,
   // DPD states
   TC_DDOP_DPD_Init,
   TC_DDOP_DPD_TableID,
   TC_DDOP_DPD_ObjectID,
   TC_DDOP_DPD_DDI,
   TC_DDOP_DPD_Properties,
   TC_DDOP_DPD_TriggerMethods,
   TC_DDOP_DPD_DesignatorLength,
   TC_DDOP_DPD_Designator,
   TC_DDOP_DPD_DVP,
   TC_DDOP_SerializeDPTs,
   TC_DDOP_InsertDpts,
   // DPT states
   TC_DDOP_DPT_Init,
   TC_DDOP_DPT_TableID,
   TC_DDOP_DPT_ObjectID,
   TC_DDOP_DPT_DDI,
   TC_DDOP_DPT_Value,
   TC_DDOP_DPT_DesignatorLength,
   TC_DDOP_DPT_Designator,
   TC_DDOP_DPT_DVP,
   TC_DDOP_SerializeDVPs,
   TC_DDOP_InsertDvps,
   // DVP states
   TC_DDOP_DVP_Init,
   TC_DDOP_DVP_TableID,
   TC_DDOP_DVP_ObjectID,
   TC_DDOP_DVP_Offset,
   TC_DDOP_DVP_Scale,
   TC_DDOP_DVP_NumberOfDecimals,
   TC_DDOP_DVP_UnitDesignatorLength,
   TC_DDOP_DVP_UnitDesignator,
   TC_DDOP_Finished
} TC_DDOP_InsertState_T;
//! Process data variable no properties
#define TC_DPD_PROPERTY_NONE ((TC_DpdProperties_T)0x00)
//! Process data variable default property
#define TC_DPD_PROPERTY_DEFAULT ((TC_DpdProperties_T)0x01)
//! Process data variable settable property
#define TC_DPD_PROPERTY_SETTABLE ((TC_DpdProperties_T)0x02)
//! Object Pool TRIGGER_METHOD_NONE
#define TC_TRIGGER_METHOD_NONE ((TC_DpdAvailableTriggerMethods_T)0x00)
//! Object Pool TRIGGER_METHOD_TIME
#define TC_TRIGGER_METHOD_TIME ((TC_DpdAvailableTriggerMethods_T)0x01)
//! Object Pool TRIGGER_METHOD_DISTANCE
#define TC_TRIGGER_METHOD_DISTANCE ((TC_DpdAvailableTriggerMethods_T)0x02)
//! Object Pool TRIGGER_METHOD_THRESHOLD_LIMITS
#define TC_TRIGGER_METHOD_THRESHOLD_LIMITS ((TC_DpdAvailableTriggerMethods_T)0x04)
//! Object Pool TRIGGER_METHOD_ONCHANGE
#define TC_TRIGGER_METHOD_ONCHANGE ((TC_DpdAvailableTriggerMethods_T)0x08)
//! Object Pool TRIGGER_METHOD_TOTAL
#define TC_TRIGGER_METHOD_TOTAL ((TC_DpdAvailableTriggerMethods_T)0x10)
//! Structure to define a Device Value Presentation Object
typedef struct TC_DVP_S
{
   //! Unique object ID for the given DVP object
   TC_ObjectID_T ObjectId;
   //! Offset to be applied to the value presentation
   TC_DvpOffset_T Offset;
   //! Scale to be applied to the value presentation
   TC_DvpScale_T Scale;
   //! Number of decimals to be displayed after the decimal point
   TC_NumOfDecimals_T NumberOfDecimals;
   //! Number of bytes in the Unit Designator
   Size_T DesignatorLength;
   //! Unit designator for the DVP
   const char* UnitDesignator;
   //! Linked list node for the DVP object
   struct LinkedList_Node_S LinkedList_Node;
} TC_DVP_T;
/******************************************************************************/
/*!
   \brief    Macro used to initialize a DVP_T
   \details  This macro is used to create a DVP_T.
   \param    object_id      DVP unique object ID
   \param    designator     Unit designator
   \param    offset         Offset to be applied to the value for presentation
   \param    scale_factor   Scale to be applied to the value for presentation
   \param    num_decimals   Number of decimals to display
*/
/******************************************************************************/
#define MAKE_TC_DVP_T(object_id,designator,offset,scale_factor,num_decimals) { object_id, offset, scale_factor, num_decimals, SIZEOF(designator), designator, MAKE_LinkedList_Node_S(NULL) }
//! Structure to define a Device Property Object
typedef struct TC_DPT_S
{
   //! Unique Object ID for the given DPT object
   TC_ObjectID_T ObjectId;
   //! Identifier of property
   TC_DDI_T Ddi;
   //! Property value
   TC_DptValue_T PropertyValue;
   //! Number of bytes in property designator
   Size_T DesignatorLength;
   //! Property designator
   const char* Designator;
   //! DVP for the property
   TC_DVP_T* Dvp;
   //! Linked list node for the DPT object
   struct LinkedList_Node_S LinkedList_Node;
} TC_DPT_T;
/******************************************************************************/
/*!
   \brief    Macro used to initialize a DPT_T
   \details  This macro is used to create a DPT_T.
   \param    object_id    DPT unique object ID
   \param    designator   Property designator
   \param    ddi          Property data dictionary identifier (DDI)
   \param    value        Value of property
   \param    dvp          Reference to a DVP
*/
/******************************************************************************/
#define MAKE_TC_DPT_T(object_id,designator,ddi,value,dvp) { object_id, ddi, value, SIZEOF(designator), designator, dvp, MAKE_LinkedList_Node_S(NULL) }
//! Structure to define a Device Process Data Object
typedef struct TC_DPD_S
{
   //! Unique Object ID for the given DPD object
   TC_ObjectID_T ObjectId;
   //! Identifier of proccess data variable
   TC_DDI_T Ddi;
   //! Process data properties
   TC_DpdProperties_T DpdProperties;
   //! Process data trigger methods
   TC_DpdAvailableTriggerMethods_T TriggerMethods;
   //! Number of bytes in process data designator
   Size_T DesignatorLength;
   //! Process data designator
   const char* Designator;
   //! DVP for the process data
   TC_DVP_T* Dvp;
   //! Linked list node for the DPD object
   struct LinkedList_Node_S LinkedList_Node;
} TC_DPD_T;
/******************************************************************************/
/*!
   \brief    Macro used to initialize a DPD_T
   \details  This macro is used to create a DPD_T.
   \param    object_id    DPD unique object ID
   \param    designator   Process data designator
   \param    ddi          Process data data dictionary identifier (DDI)
   \param    properties   Process data properties
   \param    trigger      Process data available trigger methods
   \param    dvp          Reference to a DVP
*/
/******************************************************************************/
#define MAKE_TC_DPD_T(object_id,designator,ddi,properties,trigger,dvp) { object_id, ddi, properties, trigger, SIZEOF(designator), designator, dvp, MAKE_LinkedList_Node_S(NULL) }
//! Enum for DET reference types (DPT or DPD)
typedef enum TC_ObjectType_E
{
   TC_DVC_TYPE,
   TC_DET_TYPE,
   TC_DPD_TYPE,
   TC_DPT_TYPE,
   TC_DVP_TYPE
} TC_ObjectType_T;
//! Structure for Device Object Reference (DOR)
typedef struct TC_DOR_S
{
   //! DOR object type (DPD or DPT)
   TC_ObjectType_T Type;
   union
   {
      //! void pointer for MAKE macro
      void *voidPtr;
      //! DOR DPD pointer
      TC_DPD_T *Dpd;
      //! DOP DPT pointer
      TC_DPT_T *Dpt;
   } ObjectReference; //!< Pointer to DOR
   //! Linked list node for the DOR object
   struct LinkedList_Node_S LinkedList_Node;
} TC_DOR_T;
/******************************************************************************/
/*!
   \brief    Macro used to create a TC_DOR_T
   \details  This macro is used to create a TC_DOR_T.
   \param    type      DOR type (DPD or DPT)
   \param    pointer   Pointer to a DOR
*/
/******************************************************************************/
#define MAKE_TC_DOR_T(type,pointer) { type, { (void*)pointer }, MAKE_LinkedList_Node_S(NULL) }
//! Structure to define a Device Element Object (DET)
typedef struct TC_DET_S
{
   //! Unique object ID for the given DET object
   TC_ObjectID_T ObjectId;
   //! Device element type
   TC_DeviceElementType_T DetType;
   //! Number of bytes in device element designator
   Size_T DesignatorLength;
   //! Device element designator
   const char* Designator;
   //! Element number for process data variable addressing
   TC_DetElementNumber_T DeviceElementNumber;
   //! Pointer to parent DET
   struct TC_DET_S* Parent;
   //! Number of objects to follow
   Size_T NumOfObjToFollow;
   //! Linked list of object references (DPDs or DPTs) in DET
   struct LinkedList_List_S Dor;
   //! Linked list node for the DET object
   struct LinkedList_Node_S LinkedList_Node;
} TC_DET_T;
/******************************************************************************/
/*!
   \brief    Macro used to initialize a DET_T
   \details  This macro is used to create a DET_T.
   \param    object_id        DET unique object ID
   \param    designator       Device element type designator
   \param    element_type     Device element type
   \param    element_number   Element number for process data variable
                              addressing
   \param    det_parent       Reference to the object's DET parent
   \param    priority         Priority of highest priority task that
                              accesses the DOR list
*/
/******************************************************************************/
#define MAKE_TC_DET_T(object_id,designator,element_type,element_number,det_parent,priority) { object_id, element_type, SIZEOF(designator), designator, element_number, det_parent, (Size_T)0, MAKE_LinkedList_List_S(priority), MAKE_LinkedList_Node_S(NULL) }
//! Structure for Device Descriptor Object Pool (DDOP), which contains a single Device Object (DVC)
typedef struct TC_DDOP_S
{
   //! Mutex for object pool
   Mutex_T Mutex;
   //! DVC designator
   const char* Designator;
   //! DVC software version
   const char* SwVersion;
   //! DVC serial number
   const char* SerialNumber;
   //! DVC structure label
   ISOBUS_PacketData_T StructureLabel[7];
   //! DVC localization label
   Language_T LocalizationLabel;
   //! Linked list of DETs in DVC
   struct LinkedList_List_S DETs;
   //! Linked list of DPDs in DVC
   struct LinkedList_List_S DPDs;
   //! Linked list of DPTs in DVC
   struct LinkedList_List_S DPTs;
   //! Linked list of DVPs in DVC
   struct LinkedList_List_S DVPs;
} TC_DDOP_T;
/******************************************************************************/
/*!
   \brief    Macro used to initialize a DDOP_T
   \details  This macro is used to create a DDOP_T.
   \param    designator           Device object designator
   \param    software_version     Device software version
   \param    serial_number        Device and manufacturer-specific serial number
   \param    localization_label   Label given by device to identify the device
                                  descriptor localization
   \param    priority             Priority of highest priority task that
                                  accesses the DDOP or the DET, DPD, DPT, and
                                  DVP lists
*/
/******************************************************************************/
#define MAKE_TC_DDOP_T(designator,software_version,serial_number,localization_label,priority) { MAKE_Mutex_T(priority), designator, software_version, serial_number, {0, 0, 0, 0, 0, 0, 0}, localization_label, MAKE_LinkedList_List_S(priority), MAKE_LinkedList_List_S(priority), MAKE_LinkedList_List_S(priority), MAKE_LinkedList_List_S(priority) }
//###################################################
//####            Metrics Gathering               ###
//###################################################
//! TC Metrics state/storage types
typedef enum TC_MetricsState_E
{
  TC_METRICS_IDLE,
  TC_METRICS_SEND_REQUEST,
  TC_METRICS_REQUEST_SENT,
  TC_METRICS_WAIT_RESPONSE
} TC_MetricsState_T;
//! Value to indicate that neither version or language is known
#define TC_RECEIVED_NONE ((TC_MetricsMessages_T)0x00)
//! Bit mask to indicate that the TC Version is known
#define TC_RECEIVED_VERSION ((TC_MetricsMessages_T)0x01)
//! Bit mask to indicate that the TC Localization message has been received
#define TC_RECEIVED_LANGUAGE ((TC_MetricsMessages_T)0x02)
//! Bitfield indicating received messages
typedef uint8_t TC_MetricsMessages_T;
//! The version of ISO 11783-10 that this control function meets
typedef uint8_t TC_Version_T;
//! The number of seconds from power cycle to the first TC Status Message
typedef uint8_t TC_BootTime_T;
//! The provided options this TC supports
typedef uint8_t TC_ProvidedOptions_T;
//! The number of booms this TC supports
typedef uint8_t TC_NumberOfBooms_T;
//! The number of sections this TC supports
typedef uint8_t TC_NumberOfSections_T;
//! The number of control channels this TC supports
typedef uint8_t TC_NumberOfControlChannels_T;
//! Type used to track retries for requested metrics
typedef uint8_t TC_MetricsRetries_T;
//! Type used to track previous received status, and actual status byte
typedef uint8_t TC_SubStatus_T;
//! Type used to track a command being executed
typedef uint8_t TC_Command_T;
//! Type used to store a distance
typedef int32_t TC_Distance_T;
//! Type used to store a threshold value
typedef int32_t TC_Threshold_T;
//! Type used to store a PDV value
typedef int32_t TC_PDV_Value_T;
//! Information for fields of the Version message
typedef struct TC_VersionMessage_S
{
   //! TC Version Number
   TC_Version_T VersionNumber;
   //! Maximum number of seconds from power cycle to first TC Status Message
   Time_T BootTime;
   //! TC capabilities
   TCClient_Capabilities_T Capabilities;
} TC_VersionMessage_T;
//! Structure to store TC metrics
typedef struct TC_Metrics_S
{
  //! Localization Information
  Language_T Language;
  //! TC Version Message Information
  TC_VersionMessage_T VersionMessage;
  //! Indicates whether Metrics are needed
  TC_MetricsState_T State;
  //! Bit Mask Indicating Supported VT messaging
  TC_MetricsMessages_T ExpectedMetrics;
  //! Bit Mask Indicating Received VT messaging
  TC_MetricsMessages_T ReceivedMetrics;
  //! Bit Mask Indicating current message we're waiting for
  TC_MetricsMessages_T CurrentMetric;
  //! Tracks how many times a particular metric has been requested
  TC_MetricsRetries_T Retries;
  //! Tracks Metrics Response Timeouts
  SoftwareTimer_T ResponseTimer;
} TC_Metrics_T;
//###################################################
//####              PDNACK Message                ###
//###################################################
//! PDNACK Message CMD not supported
#define PROCESS_DATA_CMD_NOT_SUPPORTED ((TC_PD_ErrorCode_T)0x01)
//! PDNACK Message Invalid Element Number
#define INVALID_ELEMENT_NUMBER ((TC_PD_ErrorCode_T)0x02)
//! PDNACK Message DDI Not Supported By Element
#define DDI_NOT_SUPPORTED_BY_ELEMENT ((TC_PD_ErrorCode_T)0x04)
//! PDNACK Message Trigger Method Not Supported
#define TRIGGER_METHOD_NOT_SUPPORTED ((TC_PD_ErrorCode_T)0x08)
//! PDNACK Message Process Data Not Setable
#define PROCESS_DATA_NOT_SETABLE ((TC_PD_ErrorCode_T)0x10)
//! PDNACK Message Invalid or Unsupported Interval or Threshold
#define INVALID_OR_UNSUPPORTED_INTERVAL_OR_THRESHOLD ((TC_PD_ErrorCode_T)0x20)
//###################################################
//####          Task Controller Status            ###
//###################################################
//! TC status of totals
#define TC_TOTALS_STATUS ((TC_SubStatus_T)0x01) /* bit 0*/
//! TC is busy saving data to non-volatile memory
#define TC_BUSY_SAVING_DATA_TO_NONVOLATILE_MEMORY ((TC_SubStatus_T)0x02) /* bit 1*/
//! TC is busy reading data from non-volatile memory
#define TC_BUSY_READING_DATA_FROM_NONVOLATILE_MEMORY ((TC_SubStatus_T)0x04) /* bit 2*/
//! TC is busy executing a B.3 command (device description messages)
#define TC_BUSY_EXECUTING_B3_COMMAND ((TC_SubStatus_T)0x08) /* bit 3*/
//! TC is out of memory
#define TC_OUT_OF_MEMORY ((TC_SubStatus_T)0x80) /* bit 7*/
//! Structure for TC Status message
typedef struct TC_Status_S
{
  //! Element number, set to not available
  TC_ElementNumber_T ElementNumber;
  //! DDI, set to not available
  TC_DDI_T DDI;
  //! Actual task controller status
  TC_SubStatus_T ActualStatus;
  //! Previous status byte. (For status transition detection) //! \todo this may or may not need to be implemented
  TC_SubStatus_T PreviousStatus;
  //! Flag to indicate if the TC is busy
  bool_t Busy;
  //! Flag to indicate if the TC is out of memory
  bool_t OutOfMemory;
  //! Flag to indicate if totals are active
  bool_t TotalsActive;
  //! SA of working-set master, if TC is executing a B.3 command. Else, 0
  SourceAddress_T WorkingSetMasterSA;
  //! Command being executed, if TC is executing a B.3 command. Else, 0
  TC_Command_T CommandCurrentlyRunning;
  //! Timer tracking when to consider TC connection has dropped
  SoftwareTimer_T Timer;
  //! Source address of the TC
  NameTableIndex_T Source;
} TC_Status_T;
//###################################################
//####          Connection Management             ###
//###################################################
//! Structure for Working Set Task
typedef struct TC_Connection_S
{
  //! Timer tracking when to send Working Set Task message
  SoftwareTimer_T Timer;
  //! Indicates whether the connection is active
  bool_t IsConnected;
  //! Indicates whether the application wants a connection
  bool_t ConnectionWanted;
} TC_Connection_T;
//###################################################
//####               Object Pool                  ###
//###################################################
//! Enumeration to track Object Pool state
typedef enum TC_ObjectPoolState_E
{
  TC_OP_SET_WAIT_AFTER_DISCONNECT, // Set a timer to ensure proper disconnect before reconnecting
  TC_OP_WAIT_AFTER_DISCONNECT, // Wait for the timer to expire before becoming available again
  TC_OP_IDLE, // Idle State
  TC_OP_WAIT_CONNECTED, // Wait for a connection to a TC to be established
  TC_OP_WAIT_METRICS, // Wait for all metrics to be gathered
  TC_OP_SEND_REQUEST_STRUCTURE_LABEL, // ECU sends Request Structure Label message to the TC
  TC_OP_REQUEST_STRUCTURE_LABEL_SENT, // Wait for ECU to send the Request Structure Label message
  TC_OP_WAIT_REQUEST_STRUCTURE_LABEL_RESPONSE, // Wait for Request Structure Label message from the TC
  TC_OP_SEND_REQUEST_LOCALIZATION_LABEL, // ECU sends Request Localization Label message to the TC
  TC_OP_REQUEST_LOCALIZATION_LABEL_SENT, // Wait for ECU to send the Request Localization Label message
  TC_OP_WAIT_REQUEST_LOCALIZATION_LABEL_RESPONSE, // Wait for Request Localization Label message from the TC
  TC_OP_SEND_REQUEST_OP_TRANSFER, // ECU sends Request Object-pool Transfer message to TC
  TC_OP_REQUEST_OP_TRANSFER_SENT, // Wait for ECU to send Request Object-pool Transfer message
  TC_OP_WAIT_REQUEST_OP_TRANSFER_RESPONSE, // Wait for Request Object-Pool Transfer Response message from the TC
  TC_OP_SEND_OP_TRANSFER, // ECU sends Object-pool Transfer message to TC
  TC_OP_OP_TRANSFER_SENT, // Wait for Object-pool Transfer message to be sent
  TC_OP_WAIT_OP_TRANSFER_RESPONSE, // Wait for Object-pool Transfer Response message from TC
  TC_OP_SEND_OP_ACTIVATE, // Send Object-pool Activate message to TC
  TC_OP_OP_ACTIVATE_SENT, // Wait for Object-pool Activate message to be sent
  TC_OP_WAIT_OP_ACTIVATE_RESPONSE, // Wait for Object-pool Activate Response message from the TC
  TC_OP_OPERATOR_INTERACTION, // If connection is no longer wanted, go to TC_OP_SEND_DELETE_OP
  TC_OP_SEND_OP_DELETE, // ECU sends Delete Object Pool message to TC
  TC_OP_OP_DELETE_SENT, // Wait for ECU to send the Delete Object Pool message
  TC_OP_WAIT_OP_DELETE_RESPONSE // Wait for Delete Object Pool Resonse message from the TC
} TC_ObjectPoolState_T;
//! Object Pool TRIGGER_METHOD_NONE
#define TRIGGER_METHOD_NONE ((TC_TriggerMethod_T)0)
//! Object Pool TRIGGER_METHOD_TIME
#define TRIGGER_METHOD_TIME ((TC_TriggerMethod_T)1)
//! Object Pool TRIGGER_METHOD_DISTANCE
#define TRIGGER_METHOD_DISTANCE ((TC_TriggerMethod_T)2)
//! Object Pool TRIGGER_METHOD_THRESHOLD_LIMITS
#define TRIGGER_METHOD_THRESHOLD_LIMITS ((TC_TriggerMethod_T)4)
//! Object Pool TRIGGER_METHOD_ONCHANGE
#define TRIGGER_METHOD_ONCHANGE ((TC_TriggerMethod_T)8)
//! Object Pool TRIGGER_METHOD_TOTAL
#define TRIGGER_METHOD_TOTAL ((TC_TriggerMethod_T)16)
//! Object Pool ISO_OBJECTID_NULL
#define ISO_OBJECTID_NULL ((TC_ObjectID_T)0xFFFF)
//! TC Measurement Function Pointer
typedef TC_PDV_Value_T(*TC_Meas_Func_T)(TC_PDV_Value_T val, void *);
//! TC Measurement Structure
typedef struct TC_Measurement_S
{
  //! pointer to function that will be used to measure
  TC_Meas_Func_T Function;
  //! pointer to the argument that will be passed to the measurement function
  void *Argument;
}TC_Measurement_T;
//! Type used to track a PDV trigger method
typedef uint8_t TC_TriggerMethod_T;
//! Type used to represent the default and settable state of a process data variable
typedef uint8_t DPD_Properties_T;
//! Process data variable no properties
#define DPD_PROPERTY_NONE ((DPD_Properties_T)0x00)
//! Process data variable default property
#define DPD_PROPERTY_DEFAULT ((DPD_Properties_T)0x01)
//! Process data variable settable property
#define DPD_PROPERTY_SETTABLE ((DPD_Properties_T)0x02)
//! This structure is used to notify a module when a packet has been sent
typedef struct PDV_Callback_S
{
   //! Callback function pointer
   void(*Function)(const struct PDV_Callback_S *pointer, TC_PDV_Value_T new_value);
   //! Pointer to arbitrary data for use by callback
   void *Pointer_1;
   //! Pointer to arbitrary data for use by callback
   const void *Pointer_2;
} PDV_Callback_T;
//! Process Data Variable
//! NOTE: If this structure changes, the python script that generates the object pool will need to be changed to match it.
typedef struct TC_PDV_S
{
  //! Unique object identifier
  TC_ObjectID_T ObjectID;
  //! Number associated with the Element
  TC_ElementNumber_T ElementNumber;
  //! Identifier for DDI
  TC_DDI_T DDI;
  //! Properties: Select default/settable
  DPD_Properties_T Properties;
  //! Trigger method for sending
  TC_TriggerMethod_T Triggermethod;
  //! Interval for sending
  Time_T SendInterval;
  //! PDV Distance Interval
  TC_Distance_T DistanceInterval;
  //! Last Sent Distance
  TC_Distance_T LastSentAtDistance;
  //! PDV Send Timer
  SoftwareTimer_T SendTimer;
  //! PDV Max Threshold
  TC_Threshold_T MaxThreshold;
  //! PDV Min Threshold
  TC_Threshold_T MinThreshold;
  //! PDV Changethreshold
  TC_Threshold_T ChangeThreshold;
  //! flag indicating Value Changed
  bool_t ValueChangedFlag;
  //! Measurement structure
  TC_Measurement_T Measurement;
  //! Function to set PDV value
  PDV_Callback_T Set_Function;
  //! Value of PDV
  TC_PDV_Value_T PDV_Value;
  //! Pointer to next PDV in the list
  struct TC_PDV_S *NextInList;
}TC_PDV_T;
//! Structure Containing list of PDVs
typedef struct TC_PDVList_S
{
  //! Mutex for TC_PDV
  Mutex_T Mutex;
  //! Period for TC_PDV
  Time_T Period;
  //! Select to send defaults
  bool_t SendDefaults;
  //! Structure holding information about current Process Data
  struct TC_PDV_S *StartOfList;
}TC_PDVList_T;
//! Structure for Object Pool status
typedef struct TC_ObjectPool_S
{
   //! State of the object pool
  TC_ObjectPoolState_T State;
  //! State of sending the DDOP
  TC_DDOP_InsertState_T DDOP_State;
  //! Type of the object currently being serialized
  TC_ObjectType_T ObjectType;
  //! Pointer to the object currently being serialized
  const struct LinkedList_Node_S *CurrentObject;
  //! Pointer to the object reference currently being serialized
  const struct LinkedList_Node_S *ObjectReference;
  //! Object Pool Response Timer
  SoftwareTimer_T ResponseTimer;
  //! TC PDV List
  TC_PDVList_T PDVList;
  //! TC PDV List Timer
  SoftwareTimer_T PDVListTimer;
  //! Pointer to the structure containing object pool parts
  TC_ObjectPoolParts_T *Pool;
  //! Dynamic Object Pool
  TC_DDOP_T const *DynamicObjectPool;
  //! Object Pool part currently being loaded
  Size_T Part;
  //! Pipe handle to write raw pool data into
  Pipe_WriteHandle_T WriteHandle;
  //! Structure label of the DDOP stored on the TC
  ISOBUS_PacketData_T StructureLabel[7];
  //! Localization label of the DDOP stored on the TC
  Language_T LocalizationLabel;
} TC_ObjectPool_T;
//###################################################
//####              TC Definition                 ###
//###################################################
//! Stores known data for the TC
typedef struct TC_S
{
  //! Mutex for TC data
  Mutex_T Mutex;
  //! Data for the TC Status messages (ISO 11783-10 Annex B)
  TC_Status_T Status;
  //! Data for TC connection management
  TC_Connection_T Connection;
  //! Data for the various Technical Data messages (ISO 11783-6 Annex D)
  TC_Metrics_T Metrics;
  //! Loaded Object Pool
  TC_ObjectPool_T ObjectPool;
  //! Distance (in Millimeters)
  TC_Distance_T Distance;
} TC_T;
//! Structure containing state information for all active TCs
typedef struct ActiveTCList_S
{
  //! Mutex to copy
  Mutex_T Mutex;
  //! Maximum number of active TCs
  const Size_T MaxTCs;
  //! Pointer to array of transport sessions
  TC_T * const List;
} ActiveTCList_T;
//###################################################
//####              Task Information              ###
//###################################################
//! Available Status states
typedef enum Task_Status_E
{
  TASK_RUNNING,
  TASK_PAUSED,
  TASK_COMPLETED
} Task_Status_T;
//! Holds information about the task
typedef struct Task_S
{
  //! Status of task
  Task_Status_T Status;
} Task_T;
/******************************************************************************/
/*!
   \brief    Macro used to initialize an ActiveTCList_T
   \details  This macro is used to create an ActiveTCList_T that uses an
             previously declared array of ActiveTC_T.
   \param    tc_array  Name of the array of Active TCs
   \param    priority  Maximum task priority accessing this list.
*/
/******************************************************************************/
#define MAKE_ActiveTCList_T(tc_array,priority) { MAKE_Mutex_T(priority), sizeof(tc_array) / sizeof(TC_T), tc_array }
//! Contains all Foundation Functionality information for an ISOBUS App
typedef struct TCClient_S
{
   //! Pointer to the foundation layer
   Foundation_T *FoundationPtr;
   //! Language Command Handler
   LanguageCallback_T LanguageCallback;
   //! Active TC List (There should only be one active TC on the network according to current ISOBUS 11783)
   ActiveTCList_T ActiveTCs;
   //! Struct for registering a message handler for the TC to ECU message
   struct Transport_MessageHandler_Node_S TCClient_MessageHandler_Node;
   //! Struct for registering a request handler for the Process Data message
   struct Request_Node_S Request_ProcessData_Node;
   //! Struct holding capabilities of the TCClient
   TCClient_Capabilities_T TCClient_Capabilities;
} TCClient_T;
/******************************************************************************/
/*!
   \brief  Macro for initializing TCClient_T structure
   \param  foundation_ptr  Pointer to the corresponding Foundation_T structure
   \param  tc_array        Name of TC_T array
   \param  options         ISOBUS 11783-10 Supported Options
   \param  booms           Number of Capable Section Control - Booms
   \param  sections        Number of Capable Section Control - Sections
   \param  channels        Number of Capable Position Based Control - Control Channels
   \param  priority        Maximum task priority that accesses this structure
*/
/******************************************************************************/
#define MAKE_TCClient_T(foundation_ptr,tc_array,options,booms,sections,channels,priority) { foundation_ptr, MAKE_LanguageCallback_T(), MAKE_ActiveTCList_T(tc_array, priority), MAKE_Transport_MessageHandler_Node_S(0xCB00,TCtoECU_MsgHandler,Filter_GlobalOrWorkingSetOrDestinationSpecificToMe,NULL,NULL,1785), MAKE_Request_Node_S(0xCB00, Request_AutoAcknowledgePositive, NULL, NULL), MAKE_TCCapabilities_T(options, booms, sections, channels) }
// ECU to TC Message Senders
/******************************************************************************/
/*!
   \brief     Sends Request Version message to the TC
   \details   Sends a destination specific Request Version message to the TC. If a
              callback is provided, it will be called when the TC reply is received.
   \param     tcclient TC Client structure containing all active TCs
   \param     tc       Pointer to the application's active TC data structure
   \param     callback Message callback
   \return    bool_t
   \retval    TRUE   if the message was queued to be sent
   \retval    FALSE  if the message was not queued
*/
/******************************************************************************/
extern bool_t TC_Send_RequestVersion_Msg(const TCClient_T *tcclient, const TC_T *tc, const ISOBUS_Callback_T *callback);
/******************************************************************************/
/*!
   \brief     Function sends out Version message
   \details   The version message is sent in response to the request version message
              and contains the version information of the task controller or
              working-set implementation
   \param     tcclient   pointer to Task Controller structure with all active TCs
   \param     tc         pointer to the application's active data structure
   \return    bool_t
   \retval    TRUE   if the message was queued to be sent
   \retval    FALSE  if the message was not queued
*/
/******************************************************************************/
extern bool_t TC_Send_Version_Msg(const TCClient_T *tcclient, const TC_T *tc);
/******************************************************************************/
/*!
   \brief     Function sends Request Localization Label message to Task Controller
   \details   The device description Request Localization Label request message allows the working set to determine the
              localization version of the latest device description available at the task controller. If a localization label is not
              present, a localization label message with all localization label bytes set to value = 0xFF shall be transmitted
              by the task controller to the sender of the Request Localization Label message.
   \param     tcclient TC Client structure containing all active TCs
   \param     tc       Pointer to the application's active TC data structure
   \param     callback Message callback
   \return    bool_t
   \retval    TRUE        Message was successfully sent
   \retval    FALSE       Message send failed (try later)
*/
/******************************************************************************/
extern bool_t TC_Send_RequestLocalization_Msg(const TCClient_T *tcclient, const TC_T *tc, const ISOBUS_Callback_T *callback);
/******************************************************************************/
/*!
   \brief     Function sends Change Designator message to Task Controller
   \details   This message is to update the designator of an object.  This
              function uses transport protocol.
   \param     tcclient       Pointer to TC Client data structure
   \param     tc             pointer to the application's TC data structure
   \param     object_id      Object ID of the ofject to update
   \param     string_length  Total number of bytes in the string to transfer (32 bytes max)
   \param     designator     Pointer to a string
   \return    bool_t
   \retval    TRUE   if the message was queued to be sent
   \retval    FALSE  if the message was not queued
*/
/******************************************************************************/
extern bool_t TC_Send_ChangeDesignator_Msg(const TCClient_T *tcclient, const TC_T *tc, TC_ObjectID_T object_id, Size_T string_length, const char *designator);
/******************************************************************************/
/*!
   \brief     TCClient sends requested value to the TC
   \details   This command is used both to answer a request value command and to set the value of a
              process data entity. The layout of this message is defined in B.3.
   \param     tcclient   Pointer to TC Client data structure
   \param     tc         Pointer to the application's TC data structure
   \param     PDV        Value to set to
   \return    bool_t
   \retval    TRUE   if the message was queued to be sent
   \retval    FALSE  if the message was not queued
*/
/******************************************************************************/
extern bool_t TC_Send_ValueCommand_Msg(const TCClient_T *tcclient, const TC_T *tc, const TC_PDV_T *PDV);
/******************************************************************************/
/*!
   \brief     Function sends Process Data Negative Acknowledge (PDNACK) message to task controller
   \details   This message is sent by the working-set master or by the task controller to reject commands and process data.
              The reasons are given in the least significant byte of the process data value. When the process data error
              code reported is not associated with a specific element number or a specific DDI, the values of the element
              number or DDI shall be set to "not available". The "not available" value of the element number is 0xFFF and
              the "not available" value of the DDI is 0xFFFF.
   \param     tcclient         Pointer to TC Client data structure
   \param     tc               Pointer to the application's TC data structure
   \param     element_number   Element Number
              Pass ELEMENT_NUMBER_NA if Element Number does not pertain to the error code
   \param     ddi              Data Dictionary Identifier
              Pass DDI_NA if DDI does not pertain to the error code
   \param     pd_error_codes   Process Data Error Codes (0 = no errors)
              Bit 0 = 1 = Process Data Command not supported
              Bit 1 = 1 = Invalid element number
              Bit 2 = 1 = DDI not supported by element
              Bit 3 = 1 = Trigger method not supported
              Bit 4 = 1 = Process data not setable
              Bit 5 = 1 = Invalid or unsupported interval or threshold
              Bit 6 = 0 = Reserved (set to zero)
              Bit 7 = 0 = Reserved (set to zero)
   \return    bool_t
   \retval    TRUE   if the message was queued to be sent
   \retval    FALSE  if the message was not queued
*/
/******************************************************************************/
extern bool_t TC_Send_PDNACK_Msg(const TCClient_T *tcclient, const TC_T *tc, TC_ElementNumber_T element_number, TC_DDI_T ddi, TC_PD_ErrorCode_T pd_error_codes);
/******************************************************************************/
/*!
   \details   Sends Working-Set Task message
   \param     tcclient  TC Client structure containing all active TCs
   \param     tc        TC instance
   \return    bool_t
   \retval    TRUE   if the message was sent
   \retval    FALSE  if the message was not sent
*/
/******************************************************************************/
extern bool_t TC_Send_WSTask_Msg(const TCClient_T *tcclient, const TC_T *tc);
/******************************************************************************/
/*!
   \details  Initializes a Device Element Type
   \param    det    DET to initialize
*/
/******************************************************************************/
extern void TC_DET_Init(TC_DET_T *det);
/******************************************************************************/
/*!
\details  Initializes a Device Descriptor Object Pool
\param    ddop    DDOP to initialize
*/
/******************************************************************************/
extern void TC_DDOP_Init(TC_DDOP_T *ddop);
/******************************************************************************/
/*!
   \details  Adds a Device Element Object (DET) to the object pool.
   \param    ddop  DDOP to add this element to
   \param    det   The device element object to add
   \return  bool_t
   \retval  TRUE   DET added to DDOP
   \retval  FALSE  Unable to add DET to DDOP (det is the DVC but DVC already exists?)
*/
/******************************************************************************/
extern bool_t TC_DET_Register(TC_DDOP_T *ddop, TC_DET_T *det);
/******************************************************************************/
/*!
   \details  Removes a Device Element Object (DET) from the object pool.
   \param    ddop  DDOP to remove this element from
   \param    det   The device element object to remove
   \return  bool_t
   \retval  TRUE   DET removed from DDOP
   \retval  FALSE  Unable to remove DET from DDOP
*/
/******************************************************************************/
extern bool_t TC_DET_Unregister(TC_DDOP_T *ddop, TC_DET_T *det);
/******************************************************************************/
/*!
   \details  Adds a Device Process Data (DPD) object to the object pool.
   \param    ddop  DDOP to add this object to
   \param    dpd   The device process data object to add
   \return  bool_t
   \retval  TRUE   DPD added to DDOP
   \retval  FALSE  Unable to add DPD
*/
/******************************************************************************/
extern bool_t TC_DPD_Register(TC_DDOP_T *ddop, TC_DPD_T *dpd);
/******************************************************************************/
/*!
   \details  Removes a Device Process Data (DPD) object from the object pool.
   \param    ddop  DDOP to remove this object from
   \param    dpd   The DPD object to remove
   \return  bool_t
   \retval  TRUE   DPD removed from DDOP
   \retval  FALSE  Unable to remove DPD
*/
/******************************************************************************/
extern bool_t TC_DPD_Unregister(TC_DDOP_T *ddop, TC_DPD_T *dpd);
/******************************************************************************/
/*!
   \details  Adds a Device Property (DPT) object to the object pool.
   \param    ddop  DDOP to add this object to
   \param    dpt   The DPT object to add
   \return  bool_t
   \retval  TRUE   DPT added to DDOP
   \retval  FALSE  Unable to add DPT
*/
/******************************************************************************/
extern bool_t TC_DPT_Register(TC_DDOP_T *ddop, TC_DPT_T *dpt);
/******************************************************************************/
/*!
   \details  Removes a Device Property (DPT) object from the object pool.
   \param    ddop  DDOP to remove this object from
   \param    dpt   The DPT object to remove
   \return  bool_t
   \retval  TRUE   DPT removed from DDOP
   \retval  FALSE  Unable to remove DPT
*/
/******************************************************************************/
extern bool_t TC_DPT_Unregister(TC_DDOP_T *ddop, TC_DPT_T *dpt);
/******************************************************************************/
/*!
   \details  Assosiates a Device Object Reference (DOR) to its parent DET.
   \param   parent  Device Element Type parent to the DOR (Either DPD or DPT)
   \param   dor     The DOR to add to the DET's linked list
   \return  bool_t
   \retval  TRUE   DOR added to DET
   \retval  FALSE  Unable to add DOR
*/
/******************************************************************************/
extern bool_t TC_DOR_Register(TC_DET_T *parent, TC_DOR_T *dor);
/******************************************************************************/
/*!
   \details  Disassociate a Device Object Reference (DOR) from its parent DET.
   \param   parent  Device Element Type parent to the DOR (Either DPD or DPT)
   \param   dor     The DOR to remove from the DET's linked list
   \return  bool_t
   \retval  TRUE   DOR removed from DET
   \retval  FALSE  Unable to remove DOR
*/
/******************************************************************************/
extern bool_t TC_DOR_Unregister(TC_DET_T *parent, TC_DOR_T *dor);
/******************************************************************************/
/*!
   \details  Adds a Device Value Presentation (DVP) object to the object pool.
   \param    ddop  DDOP to add this object to
   \param    dvp   The DVP object to add
   \return  bool_t
   \retval  TRUE   DVP added to DDOP
   \retval  FALSE  Unable to add DVP
*/
/******************************************************************************/
extern bool_t TC_DVP_Register(TC_DDOP_T *ddop, TC_DVP_T *dvp);
/******************************************************************************/
/*!
   \details  Removes a Device Value Presentation (DVP) object from the object pool.
   \param    ddop  DDOP to remove this object from
   \param    dvp   The DVP object to remove
   \return  bool_t
   \retval  TRUE   DVP removed from DDOP
   \retval  FALSE  Unable to remove DVP
*/
/******************************************************************************/
extern bool_t TC_DVP_Unregister(TC_DDOP_T *ddop, TC_DVP_T *dvp);
/******************************************************************************/
/*!
   \details  Initializes TCClient_T structure
   \param    tcclient  TC Client structure containing all active TCs
*/
/******************************************************************************/
extern void TCClient_Init(TCClient_T *tcclient);
/******************************************************************************/
/*!
   \details  Uninitializes TCClient_T structure
   \param    tcclient  TC Client structure containing all active TCs
*/
/******************************************************************************/
extern void TCClient_Uninit(TCClient_T *tcclient);
/******************************************************************************/
/*!
   \details  Runs all the TC Client tasks
   \param    tcclient  TCClient_T structure containing all active TCs
*/
/******************************************************************************/
extern void TCClient_Task(const TCClient_T *tcclient);
/******************************************************************************/
/*!
   \brief  Message/Event handler for TC to ECU messages.
   \param    message       Message to handle
   \param    event         Multi-packet event (reason for the call)
   \param    handler_node  Pointer that includes task controller client data structure
*/
/******************************************************************************/
extern void TCtoECU_MsgHandler(ISOBUS_Message_T *message, ISOBUS_MessageEvent_T event, const struct Transport_MessageHandler_Node_S *handler_node);
/******************************************************************************/
/*!
   \details  Starts a connection to a TC
   \param    tcclient     TC Client data structure containing all active TCs
   \param    tc           TC to connect to
   \return  bool_t
   \retval  TRUE   Connection started
   \retval  FALSE  Connection not started
*/
/******************************************************************************/
extern bool_t TC_Start_Connection(const TCClient_T *tcclient, TC_T *tc);
/******************************************************************************/
/*!
   \details  Finds the next active TC in the list
   \param    tcclient  [In]  TCClient_T structure containing all active TCs
   \param    tc        [Out] Pointer to TC_T pointer (populated if found)
   \return  bool_t
   \retval  TRUE   TC found (and **tc populated)
   \retval  FALSE  TC not found
*/
/******************************************************************************/
extern bool_t TC_NextTC(const TCClient_T *tcclient, TC_T **tc);
/******************************************************************************/
/*!
   \details  Sends an object pool to the TC
   \param    tcclient           TC client structure containing all active TCs
   \param    tc                 TC to send object pool to
   \param    object_pool_parts  Object Pool to send
   \param    firstpdv           Pointer to the first PDV
   \param    numpdvs            Number of PDV's
   \return  bool_t
   \retval  TRUE   Connection started
   \retval  FALSE  Connection not started
*/
/******************************************************************************/
extern bool_t TC_SendObjectPool(const TCClient_T *tcclient, TC_T *tc, TC_ObjectPoolParts_T *object_pool_parts, TC_PDV_T *firstpdv, Size_T numpdvs);
/******************************************************************************/
/*!
   \details  Sends a dynamic object pool to the TC
   \param    tcclient           TC client structure containing all active TCs
   \param    tc                 TC to send object pool to
   \param    ddop               Dynamic object pool to send
   \return  bool_t
   \retval  TRUE   Connection started
   \retval  FALSE  Connection not started
*/
/******************************************************************************/
extern bool_t TC_SendDynamicObjectPool(const TCClient_T *tcclient, TC_T *tc, const TC_DDOP_T *ddop);
/******************************************************************************/
/*!
   \details  Disconnects from a TC
   \param    tcclient     TCClient structure containing all active TCs
   \param    tc           TC to connect to
   \return  bool_t
   \retval  TRUE   Disonnection started
   \retval  FALSE  Disonnection not started
*/
/******************************************************************************/
extern bool_t TC_Disconnect(TCClient_T *tcclient, TC_T *tc);
/******************************************************************************/
/*!
   \details  Assigns a user-defined measurement function to a PDV
   \param    tc        Pointer to the active TC data structure
   \param    objectid  Object ID of PDV to assign a measurement to
   \param    func      name of the function to assign
   \param    argument  Pointer to the data to be used as an argument eveytime the PDV list processor calls the measurement function
   \return  bool_t
   \retval  TRUE  if the function was assigned to the PDV
   \retval  FALSE if the function was not assigned because the PDV was not found in the PDV list
*/
/******************************************************************************/
extern bool_t TC_PDV_MeasurementFunction_Set(TC_T *tc, TC_ObjectID_T objectid, TC_Meas_Func_T func, void *argument);
/******************************************************************************/
/*!
   \details  Clears any assigned measurement function from a PDV
   \param    tc        Pointer to the active TC data structure
   \param    objectid  Object ID of PDV to assign a measurement to
   \return  bool_t
   \retval  TRUE  if the function was cleared from the PDV
   \retval  FALSE if the function was not cleared
*/
/******************************************************************************/
extern bool_t TC_PDV_MeasurementFunction_Clear(TC_T *tc, TC_ObjectID_T objectid);
/******************************************************************************/
/*!
   \details  Seaches PDV list
   \param    tc            [in]  Pointer to the active TC data structure
   \param    objectid      [in]  Object ID of PDV
   \param    elementnumber [in]  Element# of the PDV
   \param    ddi           [in]  DDI of the PDV
   \param    result        [out] Pointer to the found PDV
   \return  bool_t
   \retval  TRUE  if the PDV was found
   \retval  FALSE if the PDV was not found
*/
/******************************************************************************/
extern bool_t TC_PDV_List_Search(TC_T *tc, TC_ObjectID_T objectid, TC_ElementNumber_T elementnumber, TC_DDI_T ddi, TC_PDV_T **result);
/******************************************************************************/
/*!
   \details  Initializes TCClient_T structure
   \param    tc        Pointer to TC data structure
   \param    distance  Distance value to set to
*/
/******************************************************************************/
extern void TC_Set_Distance(TC_T *tc, TC_Distance_T distance);
/******************************************************************************/
/*!
   \details  Get the distance traveled by the Task Controller (implement)
   \param    tc   Pointer to TC data structure
   \return   TC_Distance_T
   \retval   Distance in millimeters
*/
/******************************************************************************/
extern TC_Distance_T TC_Get_Distance(TC_T *tc);
/******************************************************************************/
/*!
   \details  Public wrapper around PDV Search functions
   \param    tc            Pointer to the active TC data structure
   \param    objectid      Object ID of PDV.  If unknown, use ISO_OBJECTID_NULL
   \param    element       Element# of PDV.   NOTE: Not used if objectid is specified.
   \param    ddi           DDI of PDV.        NOTE: Not used if objectid is specified.
   \param    newvalue      New PDV Value
   \return  bool_t
   \retval  TRUE  if the PDV was found and the value was updated
   \retval  FALSE if the PDV was not found in the PDV list
*/
/******************************************************************************/
extern bool_t PDV_Value_Set(TC_T *tc, TC_ObjectID_T objectid, TC_ElementNumber_T element, TC_DDI_T ddi, TC_PDV_Value_T newvalue);
/******************************************************************************/
/*!
   \details  Public wrapper around PDV get function
   \param    tc            Pointer to the active TC data structure
   \param    objectid      Object ID of PDV.  If unknown, use ISO_OBJECTID_NULL
   \param    pdv_value     Pointer to the PDV value
   \return  int32_t        PDV Value
*/
/******************************************************************************/
extern bool_t PDV_Value_Get(TC_T *tc, TC_ObjectID_T objectid, TC_PDV_Value_T *pdv_value);
/******************************************************************************/
/*!
   \details  Initialization function for the PDV software timers
   \param    pdv_list         List of PDVs to initialize timers for
   \param    number_of_pdvs   Number of PDVs
*/
/******************************************************************************/
extern void TC_ObjectPoolTimer_Init(TC_PDV_T *pdv_list, Size_T number_of_pdvs);
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
#endif //TCCLIENT_H
