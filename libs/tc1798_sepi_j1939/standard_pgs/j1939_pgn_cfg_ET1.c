//-----------------------------------------------------------------------------
/*!
   \internal
   \file
   \brief       Application specific J1939 PGN ET1

   Defines the PGN Engine Temperature 1

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
#include "j1939_pgn_ET1.h"
#include "j1939_pgn_types.h"
#include "j1939_pg_rt_config.h"


// -- Defines -----------------------------------------------------------------
#define PG_TYPE       T_J1939_PGN_ET1                     // identificate the PG


// -- Module Global Variables --------------------------------------------------
static const T_J1939_SPN_unscaled mt_Unscaled_SPN110 = {0 , 250}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN174 = {1 , 250}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN52 = {6 , 250}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN1134 = {7 , 250}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN175 = {2 , 64255}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN176 = {4 , 64255}; // 
static const T_J1939_SPN_scaled mt_Scaled_SPN110 = {0 , SPN_SCALING_FACTOR_1 , -40 , 250};
static const T_J1939_SPN_scaled mt_Scaled_SPN174 = {1 , SPN_SCALING_FACTOR_1 , -40 , 250};
static const T_J1939_SPN_scaled mt_Scaled_SPN52 = {6 , SPN_SCALING_FACTOR_1 , -40 , 250};
static const T_J1939_SPN_scaled mt_Scaled_SPN1134 = {7 , SPN_SCALING_FACTOR_4 , 0 , 250};
static const T_J1939_SPN_scaled_2_factors mt_Scaled_SPN175 = {2 , SPN_SCALING_FACTOR_16 , 5 , -2730 , 64255};
static const T_J1939_SPN_scaled_2_factors mt_Scaled_SPN176 = {4 , SPN_SCALING_FACTOR_16 , 5 , -2730 , 64255};


static const T_J1939_SPN_description mat_SPNS[] =
{
   {   // SPN  110
      offsetof(PG_TYPE,u8_EngineCoolantTemp),
      &mt_Unscaled_SPN110,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  174
      offsetof(PG_TYPE,u8_FuelTemp),
      &mt_Unscaled_SPN174,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  52
      offsetof(PG_TYPE,u8_EngineIntercoolerTemp),
      &mt_Unscaled_SPN52,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  1134
      offsetof(PG_TYPE,u8_EngIntercoolerThermostatOpn),
      &mt_Unscaled_SPN1134,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  175
      offsetof(PG_TYPE,u16_EngineOilTemp1),
      &mt_Unscaled_SPN175,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_unscaled
   },
   {   // SPN  176
      offsetof(PG_TYPE,u16_TurboOilTemp),
      &mt_Unscaled_SPN176,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_unscaled
   },
   // ----------------------------------
   {  // scaled SPNs follow
      J1939_SPN_SCALED, NULL, NULL, NULL
   },
   {   // SPN  110
      offsetof(PG_TYPE,s16_EngineCoolantTemp_degC),
      &mt_Scaled_SPN110,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_s16_u8_scaled_offset, (PR_J1939_SPN_HandleTx)&J1939_spn_set_s16_u8_scaled_offset
   },
   {   // SPN  174
      offsetof(PG_TYPE,s16_FuelTemp_degC),
      &mt_Scaled_SPN174,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_s16_u8_scaled_offset, (PR_J1939_SPN_HandleTx)&J1939_spn_set_s16_u8_scaled_offset
   },
   {   // SPN  52
      offsetof(PG_TYPE,s16_EngineIntercoolerTemp_degC),
      &mt_Scaled_SPN52,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_s16_u8_scaled_offset, (PR_J1939_SPN_HandleTx)&J1939_spn_set_s16_u8_scaled_offset
   },
   {   // SPN  1134
      offsetof(PG_TYPE,u16_EngIntercoolerThermostatOpn_permil),
      &mt_Scaled_SPN1134,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_u8_scaled_mult, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_u8_scaled_mult
   },
   {   // SPN  175
      offsetof(PG_TYPE,s16_EngineOilTemp1_01degC),
      &mt_Scaled_SPN175,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_s16_u16_scaled_div_offset, (PR_J1939_SPN_HandleTx)&J1939_spn_set_s16_u16_scaled_div_offset
   },
   {   // SPN  176
      offsetof(PG_TYPE,s16_TurboOilTemp_01degC),
      &mt_Scaled_SPN176,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_s16_u16_scaled_div_offset, (PR_J1939_SPN_HandleTx)&J1939_spn_set_s16_u16_scaled_div_offset
   },
   {  // End mark
      0, NULL, NULL, NULL
   }
};


// -- Global Variables ---------------------------------------------------------
const T_J1939_PGN_parameters gt_J1939_PGN_CFG_ET1 =
{
   J1939_PGN_ET1,    // PGN
   6,                // default priority
   8,                // PG data buffer size
   sizeof(PG_TYPE),  // structure size
   1000,             // Rx default timeout [ms]
   1000,             // Tx default cycle time [ms]
   mat_SPNS          // array with all PG SPNS
};
