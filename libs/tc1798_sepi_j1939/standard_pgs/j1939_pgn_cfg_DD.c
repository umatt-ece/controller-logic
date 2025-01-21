//-----------------------------------------------------------------------------
/*!
   \internal
   \file
   \brief       Application specific J1939 PGN DD

   Defines the PGN Dash Display

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
#include "j1939_pgn_DD.h"
#include "j1939_pgn_types.h"
#include "j1939_pg_rt_config.h"


// -- Defines -----------------------------------------------------------------
#define PG_TYPE       T_J1939_PGN_DD                     // identificate the PG


// -- Module Global Variables --------------------------------------------------
static const T_J1939_SPN_unscaled mt_Unscaled_SPN80 = {0 , 250}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN96 = {1 , 250}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN95 = {2 , 250}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN99 = {3 , 250}; // 
static const T_J1939_SPN_unscaled         mt_Unscaled_SPN38   = {6 , 250};
static const T_J1939_SPN_unscaled mt_Unscaled_SPN169 = {4 , 64255}; // 
static const T_J1939_SPN_scaled mt_Scaled_SPN80 = {0 , SPN_SCALING_FACTOR_4 , 0 , 250};
static const T_J1939_SPN_scaled mt_Scaled_SPN96 = {1 , SPN_SCALING_FACTOR_4 , 0 , 250};
static const T_J1939_SPN_scaled mt_Scaled_SPN95 = {2 , SPN_SCALING_FACTOR_2 , 0 , 250};
static const T_J1939_SPN_scaled mt_Scaled_SPN99 = {3 , 5 , 0 , 250};
static const T_J1939_SPN_scaled           mt_Scaled_SPN38   = {6 , 2 , 0 , 250};
static const T_J1939_SPN_scaled_2_factors mt_Scaled_SPN169 = {4 , SPN_SCALING_FACTOR_16 , 5 , -2730 , 64255};


static const T_J1939_SPN_description mat_SPNS[] =
{
   {   // SPN  80
      offsetof(PG_TYPE,u8_WasherFluidLevel),
      &mt_Unscaled_SPN80,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  96
      offsetof(PG_TYPE,u8_FuelLevel),
      &mt_Unscaled_SPN96,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  95
      offsetof(PG_TYPE,u8_FuelFilterDifferentialPressure),
      &mt_Unscaled_SPN95,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  99
      offsetof(PG_TYPE,u8_EngineOilFilterDiffPressure),
      &mt_Unscaled_SPN99,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  38
      offsetof(PG_TYPE,u8_FuelLevel2),
      &mt_Unscaled_SPN38,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  169
      offsetof(PG_TYPE,u16_CargoAmbientTemperature),
      &mt_Unscaled_SPN169,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_unscaled
   },
   // ----------------------------------
   {  // scaled SPNs follow
      J1939_SPN_SCALED, NULL, NULL, NULL
   },
   {   // SPN  80
      offsetof(PG_TYPE,u16_WasherFluidLevel_permil),
      &mt_Scaled_SPN80,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_u8_scaled_mult, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_u8_scaled_mult
   },
   {   // SPN  96
      offsetof(PG_TYPE,u16_FuelLevel_permil),
      &mt_Scaled_SPN96,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_u8_scaled_mult, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_u8_scaled_mult
   },
   {   // SPN  95
      offsetof(PG_TYPE,u16_FuelFilterDiffPres_kPa),
      &mt_Scaled_SPN95,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_u8_scaled_mult, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_u8_scaled_mult
   },
   {   // SPN  99
      offsetof(PG_TYPE,u16_EngineOilFilterDiffPres_100Pa),
      &mt_Scaled_SPN99,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_u8_scaled_r_mult, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_u8_scaled_r_mult
   },
   {   // SPN  38
      offsetof(PG_TYPE,u16_FuelLevel2_permil),
      &mt_Scaled_SPN38,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_u8_scaled_mult, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_u8_scaled_mult
   },
   {   // SPN  169
      offsetof(PG_TYPE,s16_CargoAmbientTemp_01degC),
      &mt_Scaled_SPN169,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_s16_u16_scaled_div_offset, (PR_J1939_SPN_HandleTx)&J1939_spn_set_s16_u16_scaled_div_offset
   },
   {  // End mark
      0, NULL, NULL, NULL
   }
};


// -- Global Variables ---------------------------------------------------------
const T_J1939_PGN_parameters gt_J1939_PGN_CFG_DD =
{
   J1939_PGN_DD,    // PGN
   6,                // default priority
   8,                // PG data buffer size
   sizeof(PG_TYPE),  // structure size
   1000,             // Rx default timeout [ms]
   1000,             // Tx default cycle time [ms]
   mat_SPNS          // array with all PG SPNS
};
