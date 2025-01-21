//-----------------------------------------------------------------------------
/*!
   \internal
   \file
   \brief       Application specific J1939 PGN EFLP1

   Defines the PGN Engine Fluid Level Pressure 1

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
#include "j1939_pgn_EFLP1.h"
#include "j1939_pgn_types.h"
#include "j1939_pg_rt_config.h"


// -- Defines -----------------------------------------------------------------
#define PG_TYPE       T_J1939_PGN_EFLP1                     // identificate the PG


// -- Module Global Variables --------------------------------------------------
static const T_J1939_SPN_unscaled mt_Unscaled_SPN94 = {0 , 250}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN22 = {1 , 250}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN98 = {2 , 250}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN100 = {3 , 250}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN109 = {6 , 250}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN111 = {7 , 250}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN101 = {4 , 64255}; // 
static const T_J1939_SPN_scaled mt_Scaled_SPN94 = {0 , SPN_SCALING_FACTOR_4 , 0 , 250};
static const T_J1939_SPN_scaled mt_Scaled_SPN22 = {1 , 50 , 0 , 250};
static const T_J1939_SPN_scaled mt_Scaled_SPN98 = {2 , SPN_SCALING_FACTOR_4 , 0 , 250};
static const T_J1939_SPN_scaled mt_Scaled_SPN100 = {3 , SPN_SCALING_FACTOR_4 , 0 , 250};
static const T_J1939_SPN_scaled mt_Scaled_SPN109 = {6 , SPN_SCALING_FACTOR_2 , 0 , 250};
static const T_J1939_SPN_scaled mt_Scaled_SPN111 = {7 , SPN_SCALING_FACTOR_4 , 0 , 250};
static const T_J1939_SPN_scaled_2_factors mt_Scaled_SPN101 = {4 , SPN_SCALING_FACTOR_32 , 25 , -25000 , 64255};


static const T_J1939_SPN_description mat_SPNS[] =
{
   {   // SPN  94
      offsetof(PG_TYPE,u8_EngineFuelDelivPressure),
      &mt_Unscaled_SPN94,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  22
      offsetof(PG_TYPE,u8_EngineExtCcasePressure),
      &mt_Unscaled_SPN22,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  98
      offsetof(PG_TYPE,u8_EngineOilLevel),
      &mt_Unscaled_SPN98,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  100
      offsetof(PG_TYPE,u8_EngineOilPressure),
      &mt_Unscaled_SPN100,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  109
      offsetof(PG_TYPE,u8_EngineCoolantPressure),
      &mt_Unscaled_SPN109,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  111
      offsetof(PG_TYPE,u8_EngineCoolantLevel),
      &mt_Unscaled_SPN111,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  101
      offsetof(PG_TYPE,u16_EngineCcasePressure),
      &mt_Unscaled_SPN101,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_unscaled
   },
   // ----------------------------------
   {  // scaled SPNs follow
      J1939_SPN_SCALED, NULL, NULL, NULL
   },
   {   // SPN  94
      offsetof(PG_TYPE,u16_EngineFuelDelivPressure_kPa),
      &mt_Scaled_SPN94,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_u8_scaled_mult, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_u8_scaled_mult
   },
   {   // SPN  22
      offsetof(PG_TYPE,u16_EngineExtCcasePressure_Pa),
      &mt_Scaled_SPN22,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_u8_scaled_r_mult, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_u8_scaled_r_mult
   },
   {   // SPN  98
      offsetof(PG_TYPE,u16_EngineOilLevel_permil),
      &mt_Scaled_SPN98,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_u8_scaled_mult, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_u8_scaled_mult
   },
   {   // SPN  100
      offsetof(PG_TYPE,u16_EngineOilPressure_kPa),
      &mt_Scaled_SPN100,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_u8_scaled_mult, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_u8_scaled_mult
   },
   {   // SPN  109
      offsetof(PG_TYPE,u16_EngineCoolantPressure_kPa),
      &mt_Scaled_SPN109,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_u8_scaled_mult, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_u8_scaled_mult
   },
   {   // SPN  111
      offsetof(PG_TYPE,u16_EngineCoolantLevel_permil),
      &mt_Scaled_SPN111,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_u8_scaled_mult, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_u8_scaled_mult
   },
   {   // SPN  101
      offsetof(PG_TYPE,s16_EngineCcasePressure_10Pa),
      &mt_Scaled_SPN101,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_s16_u16_scaled_div_offset, (PR_J1939_SPN_HandleTx)&J1939_spn_set_s16_u16_scaled_div_offset
   },
   {  // End mark
      0, NULL, NULL, NULL
   }
};


// -- Global Variables ---------------------------------------------------------
const T_J1939_PGN_parameters gt_J1939_PGN_CFG_EFLP1 =
{
   J1939_PGN_EFLP1,    // PGN
   6,                // default priority
   8,                // PG data buffer size
   sizeof(PG_TYPE),  // structure size
   500,             // Rx default timeout [ms]
   500,             // Tx default cycle time [ms]
   mat_SPNS          // array with all PG SPNS
};
