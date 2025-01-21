//-----------------------------------------------------------------------------
/*!
   \internal
   \file
   \brief       Application specific J1939 PGN VEP1

   Defines the PGN Vehicle Electrical Power 1

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
#include "j1939_pgn_VEP1.h"
#include "j1939_pgn_types.h"
#include "j1939_pg_rt_config.h"


// -- Defines -----------------------------------------------------------------
#define PG_TYPE       T_J1939_PGN_VEP1                     // identificate the PG


// -- Module Global Variables --------------------------------------------------
static const T_J1939_SPN_unscaled mt_Unscaled_SPN114 = {0 , 250}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN115 = {1 , 250}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN167 = {2 , 64255}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN168 = {4 , 64255}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN158 = {6 , 64255}; // 
static const T_J1939_SPN_scaled mt_Scaled_SPN114 = {0 , SPN_SCALING_FACTOR_1 , -125 , 250};
static const T_J1939_SPN_scaled mt_Scaled_SPN115 = {1 , SPN_SCALING_FACTOR_1 , 0 , 250};
static const T_J1939_SPN_scaled mt_Scaled_SPN167 = {2 , SPN_SCALING_FACTOR_2 , 0 , 64255};
static const T_J1939_SPN_scaled mt_Scaled_SPN168 = {4 , SPN_SCALING_FACTOR_2 , 0 , 64255};
static const T_J1939_SPN_scaled mt_Scaled_SPN158 = {6 , SPN_SCALING_FACTOR_2 , 0 , 64255};


static const T_J1939_SPN_description mat_SPNS[] =
{
   {   // SPN  114
      offsetof(PG_TYPE,u8_NetBatteryCurrent),
      &mt_Unscaled_SPN114,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  115
      offsetof(PG_TYPE,u8_AlternatorCurrent),
      &mt_Unscaled_SPN115,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  167
      offsetof(PG_TYPE,u16_AlternatorPotentialVoltage),
      &mt_Unscaled_SPN167,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_unscaled
   },
   {   // SPN  168
      offsetof(PG_TYPE,u16_ElectricalPotentialVoltage),
      &mt_Unscaled_SPN168,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_unscaled
   },
   {   // SPN  158
      offsetof(PG_TYPE,u16_BatteryPotentialVoltSwitched),
      &mt_Unscaled_SPN158,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_unscaled
   },
   // ----------------------------------
   {  // scaled SPNs follow
      J1939_SPN_SCALED, NULL, NULL, NULL
   },
   {   // SPN  114
      offsetof(PG_TYPE,s8_NetBatteryCurrent_A),
      &mt_Scaled_SPN114,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_s8_u8_scaled_offset, (PR_J1939_SPN_HandleTx)&J1939_spn_set_s8_u8_scaled_offset
   },
   {   // SPN  115
      offsetof(PG_TYPE,u16_AlternatorCurrent_A),
      &mt_Scaled_SPN115,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_u8_scaled_mult, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_u8_scaled_mult
   },
   {   // SPN  167
      offsetof(PG_TYPE,u16_AlternatorPotentialVoltage_01V),
      &mt_Scaled_SPN167,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_u16_scaled_div, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_u16_scaled_div
   },
   {   // SPN  168
      offsetof(PG_TYPE,u16_ElectricalPotentialVoltage_01V),
      &mt_Scaled_SPN168,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_u16_scaled_div, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_u16_scaled_div
   },
   {   // SPN  158
      offsetof(PG_TYPE,u16_BatteryPotentialVoltSwitched_01V),
      &mt_Scaled_SPN158,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_u16_scaled_div, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_u16_scaled_div
   },
   {  // End mark
      0, NULL, NULL, NULL
   }
};


// -- Global Variables ---------------------------------------------------------
const T_J1939_PGN_parameters gt_J1939_PGN_CFG_VEP1 =
{
   J1939_PGN_VEP1,    // PGN
   6,                // default priority
   8,                // PG data buffer size
   sizeof(PG_TYPE),  // structure size
   1000,             // Rx default timeout [ms]
   1000,             // Tx default cycle time [ms]
   mat_SPNS          // array with all PG SPNS
};
