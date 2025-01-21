//-----------------------------------------------------------------------------
/*!
   \internal
   \file
   \brief       Application specific J1939 PGN LFE

   Defines the PGN Fuel Economy Liquid

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
#include "j1939_pgn_LFE.h"
#include "j1939_pgn_types.h"
#include "j1939_pg_rt_config.h"


// -- Defines -----------------------------------------------------------------
#define PG_TYPE       T_J1939_PGN_LFE                     // identificate the PG


// -- Module Global Variables --------------------------------------------------
static const T_J1939_SPN_unscaled mt_Unscaled_SPN51 = {6 , 250}; // 
static const T_J1939_SPN_unscaled         mt_Unscaled_SPN3673  = {7 , 250};
static const T_J1939_SPN_unscaled mt_Unscaled_SPN183 = {0 , 64255}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN184 = {2 , 64255}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN185 = {4 , 64255}; // 
static const T_J1939_SPN_scaled mt_Scaled_SPN51 = {6 , SPN_SCALING_FACTOR_4 , 0 , 250};
static const T_J1939_SPN_scaled           mt_Scaled_SPN3673  = {7 , 2 , 0 , 250};
static const T_J1939_SPN_scaled mt_Scaled_SPN183 = {0 , SPN_SCALING_FACTOR_2 , 0 , 64255};
static const T_J1939_SPN_scaled_2_factors mt_Scaled_SPN184 = {2 , SPN_SCALING_FACTOR_128 , 25 , 0 , 64255};
static const T_J1939_SPN_scaled_2_factors mt_Scaled_SPN185 = {4 , SPN_SCALING_FACTOR_128 , 25 , 0 , 64255};


static const T_J1939_SPN_description mat_SPNS[] =
{
   {   // SPN  51
      offsetof(PG_TYPE,u8_EngineThrottlePosition),
      &mt_Unscaled_SPN51,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  3673
      offsetof(PG_TYPE,u8_EngineThrottleValve2Position),
      &mt_Unscaled_SPN3673,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  183
      offsetof(PG_TYPE,u16_EngineFuelRate),
      &mt_Unscaled_SPN183,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_unscaled
   },
   {   // SPN  184
      offsetof(PG_TYPE,u16_EngineInstantFuelEconomy),
      &mt_Unscaled_SPN184,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_unscaled
   },
   {   // SPN  185
      offsetof(PG_TYPE,u16_EngineAverageFuelEconomy),
      &mt_Unscaled_SPN185,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_unscaled
   },
   // ----------------------------------
   {  // scaled SPNs follow
      J1939_SPN_SCALED, NULL, NULL, NULL
   },
   {   // SPN  51
      offsetof(PG_TYPE,u16_EngineThrottlePosition_permil),
      &mt_Scaled_SPN51,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_u8_scaled_mult, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_u8_scaled_mult
   },
   {   // SPN  3673
      offsetof(PG_TYPE,u16_EngineThrottleValve2Position_permil),
      &mt_Scaled_SPN3673,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_u8_scaled_mult, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_u8_scaled_mult
   },
   {   // SPN  183
      offsetof(PG_TYPE,u16_EngineFuelRate_01Lperh),
      &mt_Scaled_SPN183,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_u16_scaled_div, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_u16_scaled_div
   },
   {   // SPN  184
      offsetof(PG_TYPE,u16_EngineInstantFuelEconomy_10mperL),
      &mt_Scaled_SPN184,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_s16_u16_scaled_div_offset, (PR_J1939_SPN_HandleTx)&J1939_spn_set_s16_u16_scaled_div_offset
   },
   {   // SPN  185
      offsetof(PG_TYPE,u16_EngineAverageFuelEconomy_10mperL),
      &mt_Scaled_SPN185,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_s16_u16_scaled_div_offset, (PR_J1939_SPN_HandleTx)&J1939_spn_set_s16_u16_scaled_div_offset
   },
   {  // End mark
      0, NULL, NULL, NULL
   }
};


// -- Global Variables ---------------------------------------------------------
const T_J1939_PGN_parameters gt_J1939_PGN_CFG_LFE =
{
   J1939_PGN_LFE,    // PGN
   6,                // default priority
   8,                // PG data buffer size
   sizeof(PG_TYPE),  // structure size
   100,             // Rx default timeout [ms]
   100,             // Tx default cycle time [ms]
   mat_SPNS          // array with all PG SPNS
};
