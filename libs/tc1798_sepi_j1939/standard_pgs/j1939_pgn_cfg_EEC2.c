//-----------------------------------------------------------------------------
/*!
   \internal
   \file
   \brief       Application specific J1939 PGN EEC2

   Defines the PGN Electronic Engine Controller 2

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
#include "j1939_pgn_EEC2.h"
#include "j1939_pgn_types.h"
#include "j1939_pg_rt_config.h"


// -- Defines -----------------------------------------------------------------
#define PG_TYPE       T_J1939_PGN_EEC2                     // identificate the PG


// -- Module Global Variables --------------------------------------------------
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN558 = {SPN_FIELD_MASK_2_BIT , 0 , 0 , 2}; // 
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN559 = {SPN_FIELD_MASK_2_BIT , 2 , 0 , 2}; // 
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN1437 = {SPN_FIELD_MASK_2_BIT , 4 , 0 , 2}; // 
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN2970 = {SPN_FIELD_MASK_2_BIT , 6 , 0 , 2}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN91 = {1 , 250}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN92 = {2 , 250}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN974 = {3 , 250}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN29 = {4 , 250}; // 
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN2979 = {SPN_FIELD_MASK_2_BIT , 0 , 5 , 2}; // 
static const T_J1939_SPN_u8_bit_field     mt_Unscaled_SPN5021  = {SPN_FIELD_MASK_2_BIT, 2 , 5 , 2};
static const T_J1939_SPN_u8_bit_field     mt_Unscaled_SPN5399  = {SPN_FIELD_MASK_2_BIT, 4 , 5 , 2};
static const T_J1939_SPN_u8_bit_field     mt_Unscaled_SPN5400  = {SPN_FIELD_MASK_2_BIT, 6 , 5 , 2};
static const T_J1939_SPN_unscaled mt_Unscaled_SPN3357 = {6 , 250}; // 
static const T_J1939_SPN_unscaled         mt_Unscaled_SPN5398  = {7 , 250};
static const T_J1939_SPN_scaled mt_Scaled_SPN91 = {1 , SPN_SCALING_FACTOR_4 , 0 , 250};
static const T_J1939_SPN_scaled mt_Scaled_SPN974 = {3 , SPN_SCALING_FACTOR_4 , 0 , 250};
static const T_J1939_SPN_scaled           mt_Scaled_SPN29   = {4 , 2 , 0 , 250};
static const T_J1939_SPN_scaled mt_Scaled_SPN3357 = {6 , SPN_SCALING_FACTOR_4 , 0 , 250};
static const T_J1939_SPN_scaled           mt_Scaled_SPN5398  = {7 , 0 , -125 , 250};


static const T_J1939_SPN_description mat_SPNS[] =
{
   {   // SPN  558
      offsetof(PG_TYPE,u8_AcceleratorPedal1LowIdleSwitch),
      &mt_Unscaled_SPN558,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  559
      offsetof(PG_TYPE,u8_AcceleratorPedalKickdownSwitch),
      &mt_Unscaled_SPN559,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  1437
      offsetof(PG_TYPE,u8_RoadSpeedLimitStatus),
      &mt_Unscaled_SPN1437,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  2970
      offsetof(PG_TYPE,u8_AcceleratorPedal2LowIdleSwitch),
      &mt_Unscaled_SPN2970,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  91
      offsetof(PG_TYPE,u8_AcceleratorPedalPosition1),
      &mt_Unscaled_SPN91,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  92
      offsetof(PG_TYPE,u8_EnginePercLoadAtCurrentSpeed),
      &mt_Unscaled_SPN92,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  974
      offsetof(PG_TYPE,u8_RemoteAcceleratorPedalPosition),
      &mt_Unscaled_SPN974,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  29
      offsetof(PG_TYPE,u8_AcceleratorPedalPosition2),
      &mt_Unscaled_SPN29,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  2979
      offsetof(PG_TYPE,u8_VehicleAccelRateLimitStatus),
      &mt_Unscaled_SPN2979,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  5021
      offsetof(PG_TYPE,u8_MomentaryEngineMaximumPowerEnableFeedback),
      &mt_Unscaled_SPN5021,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  5399
      offsetof(PG_TYPE,u8_DPFThermalManagementActive),
      &mt_Unscaled_SPN5399,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  5400
      offsetof(PG_TYPE,u8_SCRThermalManagementActive),
      &mt_Unscaled_SPN5400,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  3357
      offsetof(PG_TYPE,u8_ActMaxAvailableEnginePercTorque),
      &mt_Unscaled_SPN3357,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  5398
      offsetof(PG_TYPE,u8_EstimatedPumpingPercentTorque),
      &mt_Unscaled_SPN5398,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   // ----------------------------------
   {  // scaled SPNs follow
      J1939_SPN_SCALED, NULL, NULL, NULL
   },
   {   // SPN  91
      offsetof(PG_TYPE,u16_AcceleratorPedalPosition1_permil),
      &mt_Scaled_SPN91,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_u8_scaled_mult, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_u8_scaled_mult
   },
   {   // SPN  974
      offsetof(PG_TYPE,u16_RemoteAccelPedalPosition_permil),
      &mt_Scaled_SPN974,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_u8_scaled_mult, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_u8_scaled_mult
   },
   {   // SPN  29
      offsetof(PG_TYPE,u16_AcceleratorPedalPosition2_permil),
      &mt_Scaled_SPN29,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_u8_scaled_mult, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_u8_scaled_mult
   },
   {   // SPN  3357
      offsetof(PG_TYPE,u16_ActMaxAvailEnginePercTorque_permil),
      &mt_Scaled_SPN3357,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_u8_scaled_mult, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_u8_scaled_mult
   },
   {   // SPN  5398
      offsetof(PG_TYPE,s8_EstimatedPumpingPercentTorque_percent),
      &mt_Scaled_SPN5398,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_s8_u8_scaled_offset, (PR_J1939_SPN_HandleTx)&J1939_spn_set_s8_u8_scaled_offset
   },
   {  // End mark
      0, NULL, NULL, NULL
   }
};


// -- Global Variables ---------------------------------------------------------
const T_J1939_PGN_parameters gt_J1939_PGN_CFG_EEC2 =
{
   J1939_PGN_EEC2,    // PGN
   3,                // default priority
   8,                // PG data buffer size
   sizeof(PG_TYPE),  // structure size
   50,             // Rx default timeout [ms]
   50,             // Tx default cycle time [ms]
   mat_SPNS          // array with all PG SPNS
};
