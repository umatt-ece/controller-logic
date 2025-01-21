//-----------------------------------------------------------------------------
/*!
   \internal
   \file
   \brief       Application specific J1939 PGN TRF1

   Defines the PGN Transmission Fluids 1

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
#include "j1939_pgn_TRF1.h"
#include "j1939_pgn_types.h"
#include "j1939_pg_rt_config.h"


// -- Defines -----------------------------------------------------------------
#define PG_TYPE       T_J1939_PGN_TRF1                     // identificate the PG


// -- Module Global Variables --------------------------------------------------
static const T_J1939_SPN_unscaled mt_Unscaled_SPN123 = {0 , 250}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN124 = {1 , 250}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN126 = {2 , 250}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN127 = {3 , 250}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN3027 = {6 , 250}; // 
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN3028 = {SPN_FIELD_MASK_4_BIT , 0 , 7 , 0x0E}; // 
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN3026 = {SPN_FIELD_MASK_4_BIT , 4 , 7 , 0x0E}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN177 = {4 , 64255}; // 
static const T_J1939_SPN_scaled mt_Scaled_SPN123 = {0 , SPN_SCALING_FACTOR_16 , 0 , 250};
static const T_J1939_SPN_scaled mt_Scaled_SPN124 = {1 , SPN_SCALING_FACTOR_4 , 0 , 250};
static const T_J1939_SPN_scaled mt_Scaled_SPN126 = {2 , SPN_SCALING_FACTOR_2 , 0 , 250};
static const T_J1939_SPN_scaled mt_Scaled_SPN127 = {3 , SPN_SCALING_FACTOR_16 , 0 , 250};
static const T_J1939_SPN_scaled mt_Scaled_SPN3027 = {6 , 5 , -625 , 250};
static const T_J1939_SPN_scaled_2_factors mt_Scaled_SPN177 = {4 , SPN_SCALING_FACTOR_16 , 5 , -2730 , 64255};


static const T_J1939_SPN_description mat_SPNS[] =
{
   {   // SPN  123
      offsetof(PG_TYPE,u8_ClutchPressure),
      &mt_Unscaled_SPN123,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  124
      offsetof(PG_TYPE,u8_TransmissionOilLevel),
      &mt_Unscaled_SPN124,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  126
      offsetof(PG_TYPE,u8_TransmFilterDiffPres),
      &mt_Unscaled_SPN126,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  127
      offsetof(PG_TYPE,u8_TransmissionOilPressue),
      &mt_Unscaled_SPN127,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  3027
      offsetof(PG_TYPE,u8_TransmOilLevelHighLow),
      &mt_Unscaled_SPN3027,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  3028
      offsetof(PG_TYPE,u8_TransmOilLevelCountdownTimer),
      &mt_Unscaled_SPN3028,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  3026
      offsetof(PG_TYPE,u8_TransmOilLevelMeasurStatus),
      &mt_Unscaled_SPN3026,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  177
      offsetof(PG_TYPE,u16_TransmOilTemperature),
      &mt_Unscaled_SPN177,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_unscaled
   },
   // ----------------------------------
   {  // scaled SPNs follow
      J1939_SPN_SCALED, NULL, NULL, NULL
   },
   {   // SPN  123
      offsetof(PG_TYPE,u16_ClutchPressure_kPa),
      &mt_Scaled_SPN123,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_u8_scaled_mult, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_u8_scaled_mult
   },
   {   // SPN  124
      offsetof(PG_TYPE,u16_TransmissionOilLevel_permil),
      &mt_Scaled_SPN124,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_u8_scaled_mult, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_u8_scaled_mult
   },
   {   // SPN  126
      offsetof(PG_TYPE,u16_TransmFilterDiffPres_kPa),
      &mt_Scaled_SPN126,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_u8_scaled_mult, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_u8_scaled_mult
   },
   {   // SPN  127
      offsetof(PG_TYPE,u16_TransmissionOilPressue_kPa),
      &mt_Scaled_SPN127,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_u8_scaled_mult, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_u8_scaled_mult
   },
   {   // SPN  3027
      offsetof(PG_TYPE,s16_TransmOilLevelHighLow_01L),
      &mt_Scaled_SPN3027,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_s16_u8_scaled_r_mult_offset, (PR_J1939_SPN_HandleTx)&J1939_spn_set_s16_u8_scaled_r_mult_offset
   },
   {   // SPN  177
      offsetof(PG_TYPE,s16_TransmOilTemperature_01degC),
      &mt_Scaled_SPN177,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_s16_u16_scaled_div_offset, (PR_J1939_SPN_HandleTx)&J1939_spn_set_s16_u16_scaled_div_offset
   },
   {  // End mark
      0, NULL, NULL, NULL
   }
};


// -- Global Variables ---------------------------------------------------------
const T_J1939_PGN_parameters gt_J1939_PGN_CFG_TRF1 =
{
   J1939_PGN_TRF1,    // PGN
   6,                // default priority
   8,                // PG data buffer size
   sizeof(PG_TYPE),  // structure size
   1000,             // Rx default timeout [ms]
   1000,             // Tx default cycle time [ms]
   mat_SPNS          // array with all PG SPNS
};
