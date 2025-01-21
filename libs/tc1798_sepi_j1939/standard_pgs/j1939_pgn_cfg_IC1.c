//-----------------------------------------------------------------------------
/*!
   \internal
   \file
   \brief       Application specific J1939 PGN IC1

   Defines the PGN Intake Exhaust Conditions 1

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
#include "j1939_pgn_IC1.h"
#include "j1939_pgn_types.h"
#include "j1939_pg_rt_config.h"


// -- Defines -----------------------------------------------------------------
#define PG_TYPE       T_J1939_PGN_IC1                     // identificate the PG


// -- Module Global Variables --------------------------------------------------
static const T_J1939_SPN_unscaled mt_Unscaled_SPN81 = {0 , 250}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN102 = {1 , 250}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN105 = {2 , 250}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN106 = {3 , 250}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN107 = {4 , 250}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN112 = {7 , 250}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN173 = {5 , 64255}; // 
static const T_J1939_SPN_scaled mt_Scaled_SPN81 = {0 , 5 , 0 , 250};
static const T_J1939_SPN_scaled mt_Scaled_SPN102 = {1 , SPN_SCALING_FACTOR_2 , 0 , 250};
static const T_J1939_SPN_scaled mt_Scaled_SPN105 = {2 , SPN_SCALING_FACTOR_1 , -40 , 250};
static const T_J1939_SPN_scaled mt_Scaled_SPN106 = {3 , SPN_SCALING_FACTOR_2 , 0 , 250};
static const T_J1939_SPN_scaled mt_Scaled_SPN107 = {4 , 5 , 0 , 250};
static const T_J1939_SPN_scaled mt_Scaled_SPN112 = {7 , 5 , 0 , 250};
static const T_J1939_SPN_scaled_2_factors mt_Scaled_SPN173 = {5 , SPN_SCALING_FACTOR_16 , 5 , -2730 , 64255};


static const T_J1939_SPN_description mat_SPNS[] =
{
   {   // SPN  81
      offsetof(PG_TYPE,u8_ParticulateTrapInletPressure),
      &mt_Unscaled_SPN81,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  102
      offsetof(PG_TYPE,u8_BoostPressure),
      &mt_Unscaled_SPN102,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  105
      offsetof(PG_TYPE,u8_IntakeManifold1Temperature),
      &mt_Unscaled_SPN105,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  106
      offsetof(PG_TYPE,u8_AirInletPressure),
      &mt_Unscaled_SPN106,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  107
      offsetof(PG_TYPE,u8_AirFilterDifferentialPressure),
      &mt_Unscaled_SPN107,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  112
      offsetof(PG_TYPE,u8_CoolantFilterDifferentialPressure),
      &mt_Unscaled_SPN112,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  173
      offsetof(PG_TYPE,u16_ExhaustGasTemperature),
      &mt_Unscaled_SPN173,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_unscaled
   },
   // ----------------------------------
   {  // scaled SPNs follow
      J1939_SPN_SCALED, NULL, NULL, NULL
   },
   {   // SPN  81
      offsetof(PG_TYPE,u16_ParticulateTrapInletPres_100Pa),
      &mt_Scaled_SPN81,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_u8_scaled_r_mult, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_u8_scaled_r_mult
   },
   {   // SPN  102
      offsetof(PG_TYPE,u16_BoostPressure_kPa),
      &mt_Scaled_SPN102,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_u8_scaled_mult, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_u8_scaled_mult
   },
   {   // SPN  105
      offsetof(PG_TYPE,s16_IntakeManifold1Temperature_degC),
      &mt_Scaled_SPN105,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_s16_u8_scaled_offset, (PR_J1939_SPN_HandleTx)&J1939_spn_set_s16_u8_scaled_offset
   },
   {   // SPN  106
      offsetof(PG_TYPE,u16_AirInletPressure_kPa),
      &mt_Scaled_SPN106,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_u8_scaled_mult, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_u8_scaled_mult
   },
   {   // SPN  107
      offsetof(PG_TYPE,u16_AirFilterDifferentialPres_100Pa),
      &mt_Scaled_SPN107,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_u8_scaled_r_mult, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_u8_scaled_r_mult
   },
   {   // SPN  112
      offsetof(PG_TYPE,u16_CoolantFilterDiffPres_100Pa),
      &mt_Scaled_SPN112,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_u8_scaled_r_mult, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_u8_scaled_r_mult
   },
   {   // SPN  173
      offsetof(PG_TYPE,s16_ExhaustGasTemperature_01degC),
      &mt_Scaled_SPN173,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_s16_u16_scaled_div_offset, (PR_J1939_SPN_HandleTx)&J1939_spn_set_s16_u16_scaled_div_offset
   },
   {  // End mark
      0, NULL, NULL, NULL
   }
};


// -- Global Variables ---------------------------------------------------------
const T_J1939_PGN_parameters gt_J1939_PGN_CFG_IC1 =
{
   J1939_PGN_IC1,    // PGN
   6,                // default priority
   8,                // PG data buffer size
   sizeof(PG_TYPE),  // structure size
   500,             // Rx default timeout [ms]
   500,             // Tx default cycle time [ms]
   mat_SPNS          // array with all PG SPNS
};
