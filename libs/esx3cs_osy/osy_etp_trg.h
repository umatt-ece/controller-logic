//----------------------------------------------------------------------------------------------------------------------
/*!
   \file
   \brief       Ethernet-TP: Example template for Ethernet-TP target definitions
   \copyright   Copyright 2017 Sensor-Technik Wiedemann GmbH. All rights reserved.
*/
//----------------------------------------------------------------------------------------------------------------------
#ifndef OSY_TRG_ETHH
#define OSY_TRG_ETHH

/* -- Includes ------------------------------------------------------------------------------------------------------ */
#include "stwtypes.h"
#include "stdtypes.h"
#include "stwerrors.h"

/* -- Defines ------------------------------------------------------------------------------------------------------- */
#ifdef __cplusplus
extern "C"
{
#endif
// Ethernet channel indices
#define OSY_ETP_TRG_ETH_01                (0U)
#define OSY_ETP_TRG_MAX_ETH_INTERFACES    (1U) //< number of Ethernet interfaces to support

/* -- Types --------------------------------------------------------------------------------------------------------- */
typedef struct
{
   uint8 u8_Dummy;    ///< no target specific parameters needed
} T_osy_etp_trg_eth_init_params; ///< target specific initialization parameters

// This type is derived from the sockaddr definition of the lwIP stack which might not be available in the application
typedef struct
{
   uint8 u8_Length;
   uint8 u8_Family;
   charn acn_Data[14];
} T_osy_etp_trg_eth_sockaddr; ///<target specific structure to hold a socket address


/* -- Global Variables ---------------------------------------------------------------------------------------------- */

/* -- Function Prototypes ------------------------------------------------------------------------------------------- */

/* -- Implementation ------------------------------------------------------------------------------------------------ */

#ifdef __cplusplus
} //end of extern "C"
#endif

#endif
