//----------------------------------------------------------------------------------------------------------------------
/*!
   \file
   \brief       openSYDE server target layer: definitions for process data exchange stacks

   Type definitions for compilation of the library.

   \copyright   Copyright 2017 Sensor-Technik Wiedemann GmbH. All rights reserved.
*/
//----------------------------------------------------------------------------------------------------------------------
#ifndef OSY_COM_TRG_DEFINITIONSH
#define OSY_COM_TRG_DEFINITIONSH

/* -- Includes ------------------------------------------------------------------------------------------------------ */

/* -- Defines ------------------------------------------------------------------------------------------------------- */
#ifdef __cplusplus
extern "C"
{
#endif

#define OSY_COM_TRG_MAX_CAN_INTERFACES    (2U) //< number of CAN interfaces to support

/* -- Types --------------------------------------------------------------------------------------------------------- */
typedef struct
{
   uint8 u8_Dummy;    ///< no target specific parameters needed
} T_osy_com_trg_can_init_params; ///< target specific initialization parameters

/* -- Global Variables ---------------------------------------------------------------------------------------------- */

/* -- Function Prototypes ------------------------------------------------------------------------------------------- */

/* -- Implementation ------------------------------------------------------------------------------------------------ */

#ifdef __cplusplus
} //end of extern "C"
#endif

#endif
