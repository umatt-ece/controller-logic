//-----------------------------------------------------------------------------
/*!
   \internal
   \file
   \brief       Application specific J1939 PGN CCVS

   Defines the PGN Cruise Control Vehicle Speed 1

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
#include "j1939_pgn_CCVS.h"
#include "j1939_pgn_types.h"
#include "j1939_pg_rt_config.h"


// -- Defines -----------------------------------------------------------------
#define PG_TYPE       T_J1939_PGN_CCVS                     // identificate the PG


// -- Module Global Variables --------------------------------------------------
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN69 = {SPN_FIELD_MASK_2_BIT , 0 , 0 , 1}; // 
static const T_J1939_SPN_u8_bit_field     mt_Unscaled_SPN70   = {SPN_FIELD_MASK_2_BIT, 2 , 0 , 2};
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN1633 = {SPN_FIELD_MASK_2_BIT , 4 , 0 , 2}; // 
static const T_J1939_SPN_u8_bit_field     mt_Unscaled_SPN3807  = {SPN_FIELD_MASK_2_BIT, 6 , 0 , 2};
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN595 = {SPN_FIELD_MASK_2_BIT , 0 , 3 , 1}; // 
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN596 = {SPN_FIELD_MASK_2_BIT , 2 , 3 , 1}; // 
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN597 = {SPN_FIELD_MASK_2_BIT , 4 , 3 , 2}; // 
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN598 = {SPN_FIELD_MASK_2_BIT , 6 , 3 , 1}; // 
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN599 = {SPN_FIELD_MASK_2_BIT , 0 , 4 , 1}; // 
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN600 = {SPN_FIELD_MASK_2_BIT , 2 , 4 , 1}; // 
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN601 = {SPN_FIELD_MASK_2_BIT , 4 , 4 , 1}; // 
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN602 = {SPN_FIELD_MASK_2_BIT , 6 , 4 , 1}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN86 = {5 , 250}; // 
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN976 = {SPN_FIELD_MASK_5_BIT , 0 , 6 , 0x11}; // 
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN527 = {SPN_FIELD_MASK_3_BIT , 5 , 6 , 0x06}; // 
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN968 = {SPN_FIELD_MASK_2_BIT , 0 , 7 , 1}; // 
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN967 = {SPN_FIELD_MASK_2_BIT , 2 , 7 , 1}; // 
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN966 = {SPN_FIELD_MASK_2_BIT , 4 , 7 , 1}; // 
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN1237 = {SPN_FIELD_MASK_2_BIT , 6 , 7 , 1}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN84 = {1 , 64255}; // 
static const T_J1939_SPN_scaled_2_factors mt_Scaled_SPN84 = {1 , SPN_SCALING_FACTOR_64 , 25 , 0 , 64255};


static const T_J1939_SPN_description mat_SPNS[] =
{
   {   // SPN  69
      offsetof(PG_TYPE,u8_TwoSpeedAxleSwitch),
      &mt_Unscaled_SPN69,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  70
      offsetof(PG_TYPE,u8_ParkingBrakeSwitch),
      &mt_Unscaled_SPN70,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  1633
      offsetof(PG_TYPE,u8_CruiseControlPauseSwitch),
      &mt_Unscaled_SPN1633,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  3807
      offsetof(PG_TYPE,u8_ParkBrakeReleaseInhibitRequest),
      &mt_Unscaled_SPN3807,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  595
      offsetof(PG_TYPE,u8_CruiseControlActive),
      &mt_Unscaled_SPN595,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  596
      offsetof(PG_TYPE,u8_CruiseControlEnableSwitch),
      &mt_Unscaled_SPN596,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  597
      offsetof(PG_TYPE,u8_BrakeSwitch),
      &mt_Unscaled_SPN597,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  598
      offsetof(PG_TYPE,u8_ClutchSwitch),
      &mt_Unscaled_SPN598,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  599
      offsetof(PG_TYPE,u8_CruiseControlSetSwitch),
      &mt_Unscaled_SPN599,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  600
      offsetof(PG_TYPE,u8_CruiseControlCoastSwitch),
      &mt_Unscaled_SPN600,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  601
      offsetof(PG_TYPE,u8_CruiseControlResumeSwitch),
      &mt_Unscaled_SPN601,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  602
      offsetof(PG_TYPE,u8_CruiseControlAccelerateSwitch),
      &mt_Unscaled_SPN602,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  86
      offsetof(PG_TYPE,u8_CruiseControlSetSpeed),
      &mt_Unscaled_SPN86,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  976
      offsetof(PG_TYPE,u8_PTOState),
      &mt_Unscaled_SPN976,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  527
      offsetof(PG_TYPE,u8_CruiseControlStates),
      &mt_Unscaled_SPN527,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  968
      offsetof(PG_TYPE,u8_IdleIncrementSwitch),
      &mt_Unscaled_SPN968,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  967
      offsetof(PG_TYPE,u8_IdleDecrementSwitch),
      &mt_Unscaled_SPN967,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  966
      offsetof(PG_TYPE,u8_EngineTestModeSwitch),
      &mt_Unscaled_SPN966,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  1237
      offsetof(PG_TYPE,u8_EngineShutdownOverrideSwitch),
      &mt_Unscaled_SPN1237,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  84
      offsetof(PG_TYPE,u16_WheelBasedVehicleSpeed),
      &mt_Unscaled_SPN84,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_unscaled
   },
   // ----------------------------------
   {  // scaled SPNs follow
      J1939_SPN_SCALED, NULL, NULL, NULL
   },
   {   // SPN  84
      offsetof(PG_TYPE,u16_WheelBasedVehicleSpeed_10mperh),
      &mt_Scaled_SPN84,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_s16_u16_scaled_div_offset, (PR_J1939_SPN_HandleTx)&J1939_spn_set_s16_u16_scaled_div_offset
   },
   {  // End mark
      0, NULL, NULL, NULL
   }
};


// -- Global Variables ---------------------------------------------------------
const T_J1939_PGN_parameters gt_J1939_PGN_CFG_CCVS =
{
   J1939_PGN_CCVS,    // PGN
   6,                // default priority
   8,                // PG data buffer size
   sizeof(PG_TYPE),  // structure size
   100,             // Rx default timeout [ms]
   100,             // Tx default cycle time [ms]
   mat_SPNS          // array with all PG SPNS
};
