//----------------------------------------------------------------------------------------------------------------------
/*!
   \file
   \brief       openSYDE server target layer: definitions

   General definitions for compilation of the library.

   \copyright   Copyright 2017 Sensor-Technik Wiedemann GmbH. All rights reserved.
*/
//----------------------------------------------------------------------------------------------------------------------
#ifndef OSY_DPA_TRG_DEFINITIONSH
#define OSY_DPA_TRG_DEFINITIONSH

/* -- Includes ------------------------------------------------------------------------------------------------------ */
#include "memtypes.h"

/* -- Defines ------------------------------------------------------------------------------------------------------- */
#ifdef __cplusplus
extern "C"
{
#endif

/* -- Types --------------------------------------------------------------------------------------------------------- */

///marker to place data in memory protected by memory protection
///keep empty if not required
#define OSY_DPA_SAFE_RAM_DATA     MEM_PROT
///marker to place non-safe data in freely accessible memory
///this is only applied for data used in safe code that also needs to be written to
///from non-safe code
#define OSY_DPA_NON_SAFE_RAM_DATA

/* -- Global Variables ---------------------------------------------------------------------------------------------- */

/* -- Function Prototypes ------------------------------------------------------------------------------------------- */

/* -- Implementation ------------------------------------------------------------------------------------------------ */

#ifdef __cplusplus
} //end of extern "C"
#endif

#endif
