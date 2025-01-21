//----------------------------------------------------------------------------------------------------------------------
/*!
   \file
   \brief       openSYDE server target layer: data protector definition

   Target specific definitions of thread and process lock objects.

   \copyright   Copyright 2017 Sensor-Technik Wiedemann GmbH. All rights reserved.
*/
//----------------------------------------------------------------------------------------------------------------------
#ifndef OSDP_TARGET_DATA_PROTECTORH
#define OSDP_TARGET_DATA_PROTECTORH

/* -- Includes ------------------------------------------------------------------------------------------------------ */
#include "stwtypes.h"

// a Mutex is used as locking mechanism
#include "x_os.h"

/* -- Defines ------------------------------------------------------------------------------------------------------- */
#ifdef __cplusplus
extern "C"
{
#endif

/* -- Types --------------------------------------------------------------------------------------------------------- */
///target specific data for locking against other threads:
typedef struct
{
   T_x_os_mutex t_LockMutexObject;  ///< a Mutex is used to implement the data pool lock
} T_osy_dpa_trg_dp_thread_lock;

///target specific data for locking against other process:
typedef struct
{
   uint8 u8_Reserved;              ///< not used for ESX-3CS
} T_osy_dpa_trg_dp_process_lock;

/* -- Global Variables ---------------------------------------------------------------------------------------------- */

/* -- Function Prototypes ------------------------------------------------------------------------------------------- */

/* -- Implementation ------------------------------------------------------------------------------------------------ */

#ifdef __cplusplus
} //end of extern "C"
#endif

#endif
