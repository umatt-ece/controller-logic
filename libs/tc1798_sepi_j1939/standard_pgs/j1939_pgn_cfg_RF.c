//-----------------------------------------------------------------------------
/*!
   \internal
   \file
   \brief       Application specific J1939 PGN RF

   Defines the PGN Retarder Fluids

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
#include "j1939_pgn_RF.h"
#include "j1939_pgn_types.h"
#include "j1939_pg_rt_config.h"


// -- Defines -----------------------------------------------------------------
#define PG_TYPE       T_J1939_PGN_RF                     // identificate the PG


// -- Module Global Variables --------------------------------------------------
static const T_J1939_SPN_unscaled mt_Unscaled_SPN119 = {0 , 250}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN120 = {1 , 250}; // 
static const T_J1939_SPN_u8_bit_field     mt_Unscaled_SPN5346  = {SPN_FIELD_MASK_2_BIT, 0 , 2 , 2};
static const T_J1939_SPN_unscaled         mt_Unscaled_SPN5656  = {3 , 250};
static const T_J1939_SPN_scaled mt_Scaled_SPN119 = {0 , SPN_SCALING_FACTOR_16 , 0 , 250};
static const T_J1939_SPN_scaled mt_Scaled_SPN120 = {1 , SPN_SCALING_FACTOR_1 , -40 , 250};
static const T_J1939_SPN_scaled           mt_Scaled_SPN5656  = {3 , 0 , -40 , 250};


static const T_J1939_SPN_description mat_SPNS[] =
{
   {   // SPN  119
      offsetof(PG_TYPE,u8_HydraulicRetarderPressure),
      &mt_Unscaled_SPN119,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  120
      offsetof(PG_TYPE,u8_HydraulicRetarderOilTemp),
      &mt_Unscaled_SPN120,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  5346
      offsetof(PG_TYPE,u8_DrivelineRetarderOverheatIndicator),
      &mt_Unscaled_SPN5346,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  5656
      offsetof(PG_TYPE,u8_RetarderCoolantOutletTemperature),
      &mt_Unscaled_SPN5656,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   // ----------------------------------
   {  // scaled SPNs follow
      J1939_SPN_SCALED, NULL, NULL, NULL
   },
   {   // SPN  119
      offsetof(PG_TYPE,u16_HydraulicRetarderPres_kPa),
      &mt_Scaled_SPN119,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_u8_scaled_mult, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_u8_scaled_mult
   },
   {   // SPN  120
      offsetof(PG_TYPE,s16_HydraulicRetarderOilTemp_degC),
      &mt_Scaled_SPN120,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_s16_u8_scaled_offset, (PR_J1939_SPN_HandleTx)&J1939_spn_set_s16_u8_scaled_offset
   },
   {   // SPN  5656
      offsetof(PG_TYPE,s16_RetarderCoolantOutletTemperature_C),
      &mt_Scaled_SPN5656,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_s16_u8_scaled_offset, (PR_J1939_SPN_HandleTx)&J1939_spn_set_s16_u8_scaled_offset
   },
   {  // End mark
      0, NULL, NULL, NULL
   }
};


// -- Global Variables ---------------------------------------------------------
const T_J1939_PGN_parameters gt_J1939_PGN_CFG_RF =
{
   J1939_PGN_RF,    // PGN
   6,                // default priority
   8,                // PG data buffer size
   sizeof(PG_TYPE),  // structure size
   1000,             // Rx default timeout [ms]
   1000,             // Tx default cycle time [ms]
   mat_SPNS          // array with all PG SPNS
};
