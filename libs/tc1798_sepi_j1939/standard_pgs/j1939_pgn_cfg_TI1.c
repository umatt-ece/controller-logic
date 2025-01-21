//-----------------------------------------------------------------------------
/*!
   \internal
   \file
   \brief       Application specific J1939 PGN TI1

   Defines the PGN Aftertreatment 1 Diesel Exhaust Fluid Tank 1 Information

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
#include "j1939_pgn_TI1.h"
#include "j1939_pgn_types.h"
#include "j1939_pg_rt_config.h"


// -- Defines -----------------------------------------------------------------
#define PG_TYPE       T_J1939_PGN_TI1                     // identificate the PG


// -- Module Global Variables --------------------------------------------------
static const T_J1939_SPN_unscaled mt_Unscaled_SPN1761 = {0 , 250}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN3031 = {1 , 250}; // 
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN3532 = {SPN_FIELD_MASK_5_BIT , 0 , 4 , 0x1F}; // 
static const T_J1939_SPN_u8_bit_field     mt_Unscaled_SPN5245  = {SPN_FIELD_MASK_3_BIT, 5 , 4 , 6};
static const T_J1939_SPN_u8_bit_field     mt_Unscaled_SPN4365  = {SPN_FIELD_MASK_5_BIT, 0 , 5 , 30};
static const T_J1939_SPN_u8_bit_field     mt_Unscaled_SPN5246  = {SPN_FIELD_MASK_3_BIT, 5 , 5 , 6};
static const T_J1939_SPN_unscaled         mt_Unscaled_SPN3363  = {6 , 250};
static const T_J1939_SPN_u8_bit_field     mt_Unscaled_SPN4366  = {SPN_FIELD_MASK_5_BIT, 0 , 7 , 30};
static const T_J1939_SPN_unscaled mt_Unscaled_SPN3517 = {2 , 64255}; // 
static const T_J1939_SPN_scaled mt_Scaled_SPN1761 = {0 , SPN_SCALING_FACTOR_4 , 0 , 250};
static const T_J1939_SPN_scaled mt_Scaled_SPN3031 = {1 , SPN_SCALING_FACTOR_1 , -40 , 250};
static const T_J1939_SPN_scaled           mt_Scaled_SPN3363  = {6 , 2 , 0 , 250};
static const T_J1939_SPN_scaled mt_Scaled_SPN3517 = {2 , SPN_SCALING_FACTOR_1 , 0 , 64255};


static const T_J1939_SPN_description mat_SPNS[] =
{
   {   // SPN  1761
      offsetof(PG_TYPE,u8_CatalystTankLevel),
      &mt_Unscaled_SPN1761,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  3031
      offsetof(PG_TYPE,u8_CatalystTankTemperature),
      &mt_Unscaled_SPN3031,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  3532
      offsetof(PG_TYPE,u8_CatalystTankLevelPreliminaryFMI),
      &mt_Unscaled_SPN3532,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  5245
      offsetof(PG_TYPE,u8_AftertreatmentSelectiveCatalyticReductionOperatorInducementActive),
      &mt_Unscaled_SPN5245,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  4365
      offsetof(PG_TYPE,u8_Aftertreatment1DieselExhaustFluidTank1TemperaturePreliminaryFMI),
      &mt_Unscaled_SPN4365,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  5246
      offsetof(PG_TYPE,u8_AftertreatmentSCROperatorInducementSeverity),
      &mt_Unscaled_SPN5246,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  3363
      offsetof(PG_TYPE,u8_Aftertreatment1DieselExhaustFluidTankHeater),
      &mt_Unscaled_SPN3363,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  4366
      offsetof(PG_TYPE,u8_Aftertreatment1DieselExhaustFluidTank1HeaterPreliminaryFMI),
      &mt_Unscaled_SPN4366,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  3517
      offsetof(PG_TYPE,u16_CatalystTankLevel2),
      &mt_Unscaled_SPN3517,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_unscaled
   },
   // ----------------------------------
   {  // scaled SPNs follow
      J1939_SPN_SCALED, NULL, NULL, NULL
   },
   {   // SPN  1761
      offsetof(PG_TYPE,u16_CatalystTankLevel_permil),
      &mt_Scaled_SPN1761,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_u8_scaled_mult, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_u8_scaled_mult
   },
   {   // SPN  3031
      offsetof(PG_TYPE,s16_CatalystTankTemperature_degC),
      &mt_Scaled_SPN3031,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_s16_u8_scaled_offset, (PR_J1939_SPN_HandleTx)&J1939_spn_set_s16_u8_scaled_offset
   },
   {   // SPN  3363
      offsetof(PG_TYPE,u16_Aftertreatment1DieselExhaustFluidTankHeater_permil),
      &mt_Scaled_SPN3363,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_u8_scaled_mult, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_u8_scaled_mult
   },
   {   // SPN  3517
      offsetof(PG_TYPE,u16_CatalystTankLevel2_01mm),
      &mt_Scaled_SPN3517,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_u16_scaled_div, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_u16_scaled_div
   },
   {  // End mark
      0, NULL, NULL, NULL
   }
};


// -- Global Variables ---------------------------------------------------------
const T_J1939_PGN_parameters gt_J1939_PGN_CFG_TI1 =
{
   J1939_PGN_TI1,    // PGN
   6,                // default priority
   8,                // PG data buffer size
   sizeof(PG_TYPE),  // structure size
   1000,             // Rx default timeout [ms]
   1000,             // Tx default cycle time [ms]
   mat_SPNS          // array with all PG SPNS
};
