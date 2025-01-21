//-----------------------------------------------------------------------------
/*!
   \internal
   \file
   \brief       Application specific J1939 PGN AMB

   Defines the PGN Ambient Conditions

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
#include "j1939_pgn_AMB.h"
#include "j1939_pgn_types.h"
#include "j1939_pg_rt_config.h"


// -- Defines -----------------------------------------------------------------
#define PG_TYPE       T_J1939_PGN_AMB                     // identificate the PG


// -- Module Global Variables --------------------------------------------------
static const T_J1939_SPN_unscaled mt_Unscaled_SPN108 = {0 , 250}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN172 = {5 , 250}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN170 = {1 , 64255}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN171 = {3 , 64255}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN79 = {6 , 64255}; // 
static const T_J1939_SPN_scaled mt_Scaled_SPN108 = {0 , 5 , 0 , 250};
static const T_J1939_SPN_scaled mt_Scaled_SPN172 = {5 , SPN_SCALING_FACTOR_1 , -40 , 250};
static const T_J1939_SPN_scaled_2_factors mt_Scaled_SPN170 = {1 , SPN_SCALING_FACTOR_16 , 5 , -2730 , 64255};
static const T_J1939_SPN_scaled_2_factors mt_Scaled_SPN171 = {3 , SPN_SCALING_FACTOR_16 , 5 , -2730 , 64255};
static const T_J1939_SPN_scaled_2_factors mt_Scaled_SPN79 = {6 , SPN_SCALING_FACTOR_16 , 5 , -2730 , 64255};


static const T_J1939_SPN_description mat_SPNS[] =
{
   {   // SPN  108
      offsetof(PG_TYPE,u8_BarometricPressure),
      &mt_Unscaled_SPN108,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  172
      offsetof(PG_TYPE,u8_AirInletTemperature),
      &mt_Unscaled_SPN172,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  170
      offsetof(PG_TYPE,u16_CabInteriorTemperature),
      &mt_Unscaled_SPN170,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_unscaled
   },
   {   // SPN  171
      offsetof(PG_TYPE,u16_AmbientAirTemperature),
      &mt_Unscaled_SPN171,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_unscaled
   },
   {   // SPN  79
      offsetof(PG_TYPE,u16_RoadSurfaceTemperature),
      &mt_Unscaled_SPN79,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_unscaled
   },
   // ----------------------------------
   {  // scaled SPNs follow
      J1939_SPN_SCALED, NULL, NULL, NULL
   },
   {   // SPN  108
      offsetof(PG_TYPE,u16_BarometricPressure_100Pa),
      &mt_Scaled_SPN108,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_u8_scaled_r_mult, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_u8_scaled_r_mult
   },
   {   // SPN  172
      offsetof(PG_TYPE,s16_AirInletTemperature_degC),
      &mt_Scaled_SPN172,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_s16_u8_scaled_offset, (PR_J1939_SPN_HandleTx)&J1939_spn_set_s16_u8_scaled_offset
   },
   {   // SPN  170
      offsetof(PG_TYPE,s16_CabInteriorTemperature_01degC),
      &mt_Scaled_SPN170,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_s16_u16_scaled_div_offset, (PR_J1939_SPN_HandleTx)&J1939_spn_set_s16_u16_scaled_div_offset
   },
   {   // SPN  171
      offsetof(PG_TYPE,s16_AmbientAirTemperature_01degC),
      &mt_Scaled_SPN171,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_s16_u16_scaled_div_offset, (PR_J1939_SPN_HandleTx)&J1939_spn_set_s16_u16_scaled_div_offset
   },
   {   // SPN  79
      offsetof(PG_TYPE,s16_RoadSurfaceTemperature_01degC),
      &mt_Scaled_SPN79,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_s16_u16_scaled_div_offset, (PR_J1939_SPN_HandleTx)&J1939_spn_set_s16_u16_scaled_div_offset
   },
   {  // End mark
      0, NULL, NULL, NULL
   }
};


// -- Global Variables ---------------------------------------------------------
const T_J1939_PGN_parameters gt_J1939_PGN_CFG_AMB =
{
   J1939_PGN_AMB,    // PGN
   6,                // default priority
   8,                // PG data buffer size
   sizeof(PG_TYPE),  // structure size
   1000,             // Rx default timeout [ms]
   1000,             // Tx default cycle time [ms]
   mat_SPNS          // array with all PG SPNS
};
