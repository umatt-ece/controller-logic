//----------------------------------------------------------------------------------------------------------------------
/*!
   \file
   \brief       Definition of openSYDE data pool structures describing data pools with their lists,
                 elements, min/max/data_set values
   \copyright   Copyright 2017 Sensor-Technik Wiedemann GmbH. All rights reserved.
*/
//----------------------------------------------------------------------------------------------------------------------
#ifndef OSY_DPA_DATA_POOLH
#define OSY_DPA_DATA_POOLH

/* -- Includes ------------------------------------------------------------------------------------------------------ */
#include "stwtypes.h"
#include "osy_dpa_trg_data_protector.h" //we need the target specific structure definition
#include "osy_dpa_trg_definitions.h"

/* -- Includes ------------------------------------------------------------------------------------------------------ */
#ifdef __cplusplus
extern "C"
{
#endif

//Macro for creating and initializing data pool instance data
//PRQA S 0881,0342 ++ //see comment about these messages in this scenario in osy_dpd_driver.h
///data pool definition instance data; not placed in safe memory; needs to be written from non-safe protocol driver
#define OSY_DPA_CREATE_STATIC_DP_DEFINITION_INSTANCE_DATA(STRUCT_NAME)  \
   static OSY_DPA_NON_SAFE_RAM_DATA T_osy_dpa_data_pool_definition_instance_data(STRUCT_NAME);
///data pool instance data; placed in safe memory as wrong content can affect safety
///T_osy_dpa_trg_dp_thread_lock is not pre-initialized by this macro (there's a init function for that)
#define OSY_DPA_CREATE_STATIC_DP_INSTANCE_DATA(STRUCT_NAME, DP_DEFINITION_ADDRESS)  \
   static OSY_DPA_SAFE_RAM_DATA T_osy_dpa_trg_dp_thread_lock(STRUCT_NAME ## ThreadLock); \
   static OSY_DPA_SAFE_RAM_DATA T_osy_dpa_data_pool_instance_data(STRUCT_NAME) = \
   { \
      (DP_DEFINITION_ADDRESS), \
      &(STRUCT_NAME ## ThreadLock) \
   };
//PRQA S 0881,0342 --

#define OSY_DPA_DATA_POOL_MAGIC    (0x05DBU) ///< "0pen5ydeDataBool"

#define OSY_DPA_DATA_POOL_VALID_VALUE (0x5AFEU)

#define OSY_DPA_DATA_POOL_DEFINITION_VERSION (0x0001U)

#define OSY_DPA_ELEMENT_TYPE_UINT8    (0U)
#define OSY_DPA_ELEMENT_TYPE_SINT8    (1U)
#define OSY_DPA_ELEMENT_TYPE_UINT16   (2U)
#define OSY_DPA_ELEMENT_TYPE_SINT16   (3U)
#define OSY_DPA_ELEMENT_TYPE_UINT32   (4U)
#define OSY_DPA_ELEMENT_TYPE_SINT32   (5U)
#define OSY_DPA_ELEMENT_TYPE_UINT64   (6U)
#define OSY_DPA_ELEMENT_TYPE_SINT64   (7U)
#define OSY_DPA_ELEMENT_TYPE_FLOAT32  (8U)
#define OSY_DPA_ELEMENT_TYPE_FLOAT64  (9U)
#define OSY_DPA_ELEMENT_TYPE_AUINT8   (20U)
#define OSY_DPA_ELEMENT_TYPE_ASINT8   (21U)
#define OSY_DPA_ELEMENT_TYPE_AUINT16  (22U)
#define OSY_DPA_ELEMENT_TYPE_ASINT16  (23U)
#define OSY_DPA_ELEMENT_TYPE_AUINT32  (24U)
#define OSY_DPA_ELEMENT_TYPE_ASINT32  (25U)
#define OSY_DPA_ELEMENT_TYPE_AUINT64  (26U)
#define OSY_DPA_ELEMENT_TYPE_ASINT64  (27U)
#define OSY_DPA_ELEMENT_TYPE_AFLOAT32 (28U)
#define OSY_DPA_ELEMENT_TYPE_AFLOAT64 (29U)

#define OSY_DPA_DATA_POOL_TYPE_DIAGNOSIS     (0U) ///< diagnosis data pool containing variables
#define OSY_DPA_DATA_POOL_TYPE_NVM           (1U) ///< NMV data pool containing parameters
#define OSY_DPA_DATA_POOL_TYPE_COMMUNICATION (2U) ///< communication data pool containing signals

/* -- Types --------------------------------------------------------------------------------------------------------- */

///Wrapper around pointer to one data set
typedef struct
{
   const void * const pv_Data; ///< pointer to actual data set data
} T_osy_dpa_data_set;

//----------------------------------------------------------------------------------------------------------------------

///Describes one data pool element
typedef struct
{
   const uint8 u8_DataType;           ///< Type of element (e.g. uint8, float32, array of sint16)
   const uint8 u8_TriggerAccessEvent; ///< Bit0 = 1 -> trigger application specific read/write/pre-write events
   ///<             on access from protocol driver
   const uint16 u16_SizeBytes;     ///< Size of element in bytes
   void * const pv_Data;           ///< Pointer to current data in RAM (i.e. to global data for this element)
   const void * const pv_MinValue; ///< Pointer to minimum value for this element (NULL: not available)
   const void * const pv_MaxValue; ///< Pointer to maximum value for this element (NULL: not available)
} T_osy_dpa_element_definition;

//----------------------------------------------------------------------------------------------------------------------

///Describes one data pool list
typedef struct
{
   const uint16 u16_NumberOfElements;                                ///< Number of entries within this list
   const uint8 u8_NumberOfDataSets;                                  ///< Number of data sets available for this list
   const uint8 u8_HasCrc;                                            ///< Only for NVM data pool: Bit0: is the data in
                                                                     // NVM protected by a CRC (0/1) ?
   const uint32 u32_NvmStartAddress;                                 ///< Only for NVM data pool: Start address of list
                                                                     // data in NVM
   const uint32 u32_SizeOfDataBytes;                                 ///< Size of RAM/dataset/min/max data of this list
                                                                     // in bytes (sizeof(struct); (NOT == size in NVM))
   const T_osy_dpa_element_definition * const pt_ElementDefinitions; ///< pointer to "NumberOfElements" elements
   void * const pv_Data;                                             ///< Pointer to current data in RAM (i.e. to global
                                                                     // data for this list)
   const T_osy_dpa_data_set * const pt_DataSets;                     ///< Pointer to "NumberOfDataSets" data sets
} T_osy_dpa_list_definition;

//----------------------------------------------------------------------------------------------------------------------

///Instance data per data pool definition that can change at run-time
typedef struct
{
   ///Target specific process lock data for locking data pool
   T_osy_dpa_trg_dp_process_lock t_ProcessLockData;
} T_osy_dpa_data_pool_definition_instance_data;

//----------------------------------------------------------------------------------------------------------------------

///Describes one data pool
typedef struct
{
   const uint16 u16_LayoutVersion;                                       ///< Version of data pool definition structure.
                                                                         // At beginning to allow sanity checks.
   const uint8 u8_Type;                                                  ///< Type of data pool (Diag/NVM/Comm)
   const uint8 au8_Version[3];                                           ///< Version of this data pool (major, minor,
                                                                         // release)
   const charn acn_Name[32];                                             ///< Name of this data pool
   const uint16 u16_NumberOfLists;                                       ///< Number of lists within this data pool
   const uint32 u32_HashValue;                                           ///< Hash value over the data pool definition
   const uint32 u32_NvmStartAddress;                                     ///< Only for NVM data pool: Start address in
                                                                         // NVM
   const uint32 u32_NvmSize;                                             ///< Only for NVM data pool: Number of bytes in
                                                                         // NVM
                                                                         // assigned for this data pool
   const T_osy_dpa_list_definition * const pt_ListDefinitions;           ///< Pointer to "NumberOfLists" list
                                                                         // definitions
   T_osy_dpa_data_pool_definition_instance_data * const pt_InstanceData; ///<Instance data that might change at run-time
} T_osy_dpa_data_pool_definition;

//----------------------------------------------------------------------------------------------------------------------

///Information about remote data pool. Can be used to request information about remote data pool from another process.
typedef struct
{
   const uint32 u32_ProcessId; ///< Identification ID of remote process providing information about the data pool
   /// for local data pools: ID of local process
   const uint8 u8_DataPoolIndex; ///< Index of data pool within the process identified by ProcessId
} T_osy_dpa_remote_data_pool_info;

//----------------------------------------------------------------------------------------------------------------------

///Instance data per data pool that can change at run-time
typedef struct
{
   ///Data pool definition (initially NULL if not local; will be set at startup)
   const T_osy_dpa_data_pool_definition * pt_DataPoolDefinition;
   ///Target specific thread lock data for locking data pool
   ///Reason to keep this as a pointer and not just aggregate it:
   ///We create the instance of this structure with a macro. There is no way to reliably
   /// pre-set the content without provoking compiler warnings.
   T_osy_dpa_trg_dp_thread_lock * const pt_ThreadLockData;
} T_osy_dpa_data_pool_instance_data;

//----------------------------------------------------------------------------------------------------------------------

///Wrapper adding location and status information
typedef struct
{
   const uint16 u16_MagicMark;                                  ///< to identify proper data pool instances
   const uint8 u8_DataPoolIndex;                                ///< index of data pool within this process
                                                                // (0=first DP)
   const uint8 u8_IsRemote;                                     ///< Bit0: 0: all data pool information available
                                                                // locally; 1: data pool info is remote
   const T_osy_dpa_remote_data_pool_info * const pt_RemoteInfo; ///< data pool process information
   T_osy_dpa_data_pool_instance_data * const pt_InstanceData;   ///< data that can change at run-time
} T_osy_dpa_data_pool;

/* -- Global Variables ---------------------------------------------------------------------------------------------- */

/* -- Function Prototypes ------------------------------------------------------------------------------------------- */

/* -- Implementation ------------------------------------------------------------------------------------------------ */

#ifdef __cplusplus
} //end of extern "C"
#endif

#endif
