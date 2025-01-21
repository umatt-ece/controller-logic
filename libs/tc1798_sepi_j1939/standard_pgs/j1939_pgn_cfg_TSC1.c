//-----------------------------------------------------------------------------
/*!
   \internal
   \file
   \brief       Application specific J1939 PGN TSC1

   Defines the PGN Torque Speed Control 1

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
#include "j1939_pgn_TSC1.h"
#include "j1939_pgn_types.h"
#include "j1939_pg_rt_config.h"


// -- Defines -----------------------------------------------------------------
#define PG_TYPE       T_J1939_PGN_TSC1                     // identificate the PG


// -- Module Global Variables --------------------------------------------------
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN695 = {SPN_FIELD_MASK_2_BIT , 0 , 0 , 3}; // 
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN696 = {SPN_FIELD_MASK_2_BIT , 2 , 0 , 3}; // 
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN897 = {SPN_FIELD_MASK_2_BIT , 4 , 0 , 3}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN518 = {3 , 250}; // 
static const T_J1939_SPN_u8_bit_field     mt_Unscaled_SPN3349  = {SPN_FIELD_MASK_3_BIT, 0 , 4 , 6};
static const T_J1939_SPN_u8_bit_field     mt_Unscaled_SPN3350  = {SPN_FIELD_MASK_5_BIT, 3 , 4 , 30};
static const T_J1939_SPN_u8_bit_field     mt_Unscaled_SPN4191  = {SPN_FIELD_MASK_4_BIT, 0 , 5 , 7};
static const T_J1939_SPN_u8_bit_field     mt_Unscaled_SPN4206  = {SPN_FIELD_MASK_4_BIT, 0 , 7 , 14};
static const T_J1939_SPN_u8_bit_field     mt_Unscaled_SPN4207  = {SPN_FIELD_MASK_4_BIT, 4 , 7 , 14};
static const T_J1939_SPN_unscaled mt_Unscaled_SPN898 = {1 , 64255}; // 
static const T_J1939_SPN_scaled mt_Scaled_SPN518 = {3 , SPN_SCALING_FACTOR_1 , -125 , 250};
static const T_J1939_SPN_scaled mt_Scaled_SPN898 = {1 , SPN_SCALING_FACTOR_8 , 0 , 64255};


static const T_J1939_SPN_description mat_SPNS[] =
{
   {   // SPN  695
      offsetof(PG_TYPE,u8_OverrideControlMode),
      &mt_Unscaled_SPN695,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  696
      offsetof(PG_TYPE,u8_RequestedSpeedCntrlConditions),
      &mt_Unscaled_SPN696,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  897
      offsetof(PG_TYPE,u8_OverrideCntrlModePriority),
      &mt_Unscaled_SPN897,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  518
      offsetof(PG_TYPE,u8_RequestedTorqueLimit),
      &mt_Unscaled_SPN518,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  3349
      offsetof(PG_TYPE,u8_TSC1TransmissionRate),
      &mt_Unscaled_SPN3349,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  3350
      offsetof(PG_TYPE,u8_TSC1ControlPurpose),
      &mt_Unscaled_SPN3350,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  4191
      offsetof(PG_TYPE,u8_EngineRequestedTorqueHighResolution),
      &mt_Unscaled_SPN4191,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  4206
      offsetof(PG_TYPE,u8_MessageCounter),
      &mt_Unscaled_SPN4206,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  4207
      offsetof(PG_TYPE,u8_MessageChecksum),
      &mt_Unscaled_SPN4207,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  898
      offsetof(PG_TYPE,u16_RequestedSpeedLimit),
      &mt_Unscaled_SPN898,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_unscaled
   },
   // ----------------------------------
   {  // scaled SPNs follow
      J1939_SPN_SCALED, NULL, NULL, NULL
   },
   {   // SPN  518
      offsetof(PG_TYPE,s8_RequestedTorqueLimit_perc),
      &mt_Scaled_SPN518,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_s8_u8_scaled_offset, (PR_J1939_SPN_HandleTx)&J1939_spn_set_s8_u8_scaled_offset
   },
   {   // SPN  898
      offsetof(PG_TYPE,u16_RequestedSpeedLimit_rpm),
      &mt_Scaled_SPN898,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_u16_scaled_div, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_u16_scaled_div
   },
   {  // End mark
      0, NULL, NULL, NULL
   }
};


// -- Global Variables ---------------------------------------------------------
const T_J1939_PGN_parameters gt_J1939_PGN_CFG_TSC1 =
{
   J1939_PGN_TSC1,    // PGN
   3,                // default priority
   8,                // PG data buffer size
   sizeof(PG_TYPE),  // structure size
   50,             // Rx default timeout [ms]
   10,             // Tx default cycle time [ms]
   mat_SPNS          // array with all PG SPNS
};
