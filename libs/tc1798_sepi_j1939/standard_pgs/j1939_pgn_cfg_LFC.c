//-----------------------------------------------------------------------------
/*!
   \internal
   \file
   \brief       Application specific J1939 PGN LFC

   Defines the PGN Fuel Consumption Liquid

   \implementation
   project     J1939 Protocolstack
   copyright   STW (c) 2010
   license     use only under terms of contract / confidential

   created     03.09.2013  STW/J1939-PGen V1.00r0
   \endimplementation
*/
//------------------------------------------------------------------------------


// -- Includes ----------------------------------------------------------------
#include <stddef.h>
#include "j1939_pgn_LFC.h"
#include "j1939_pgn_types.h"
#include "j1939_pg_rt_config.h"


// -- Defines -----------------------------------------------------------------
#define PG_TYPE       T_J1939_PGN_LFC                     // identificate the PG


// -- Module Global Variables --------------------------------------------------
static const T_J1939_SPN_unscaled mt_Unscaled_SPN182 = {0 , 0xFAFFFFFF}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN250 = {4 , 0xFAFFFFFF}; // 
static const T_J1939_SPN_scaled_32bit mt_Scaled_SPN182 = {0 , SPN_SCALING_FACTOR_2 , 0 , 0xFAFFFFFF};
static const T_J1939_SPN_scaled_32bit mt_Scaled_SPN250 = {4 , SPN_SCALING_FACTOR_2 , 0 , 0xFAFFFFFF};


static const T_J1939_SPN_description mat_SPNS[] =
{
   {   // SPN  182
      offsetof(PG_TYPE,u32_EngineTripFuel),
      &mt_Unscaled_SPN182,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u32_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u32_unscaled
   },
   {   // SPN  250
      offsetof(PG_TYPE,u32_EngineTotalFuelUsed),
      &mt_Unscaled_SPN250,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u32_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u32_unscaled
   },
   // ----------------------------------
   {  // scaled SPNs follow
      J1939_SPN_SCALED, NULL, NULL, NULL
   },
   {   // SPN  182
      offsetof(PG_TYPE,u32_EngineTripFuel_Liter),
      &mt_Scaled_SPN182,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u32_u32_scaled_div, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u32_u32_scaled_div
   },
   {   // SPN  250
      offsetof(PG_TYPE,u32_EngineTotalFuelUsed_Liter),
      &mt_Scaled_SPN250,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u32_u32_scaled_div, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u32_u32_scaled_div
   },
   {  // End mark
      0, NULL, NULL, NULL
   }
};


// -- Global Variables ---------------------------------------------------------
const T_J1939_PGN_parameters gt_J1939_PGN_CFG_LFC =
{
   J1939_PGN_LFC,    // PGN
   6,                // default priority
   8,                // PG data buffer size
   sizeof(PG_TYPE),  // structure size
   J1939_DISABLE_TIME,             // Rx default timeout [ms]
   J1939_DISABLE_TIME,             // Tx default cycle time [ms]
   mat_SPNS          // array with all PG SPNS
};
