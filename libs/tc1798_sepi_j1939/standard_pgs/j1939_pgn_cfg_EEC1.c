//-----------------------------------------------------------------------------
/*!
   \internal
   \file
   \brief       Application specific J1939 PGN EEC1

   Defines the PGN Electronic Engine Controller 1

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
#include "j1939_pgn_EEC1.h"
#include "j1939_pgn_types.h"
#include "j1939_pg_rt_config.h"


// -- Defines -----------------------------------------------------------------
#define PG_TYPE       T_J1939_PGN_EEC1                     // identificate the PG


// -- Module Global Variables --------------------------------------------------
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN899 = {SPN_FIELD_MASK_4_BIT , 0 , 0 , 14}; // 
static const T_J1939_SPN_u8_bit_field     mt_Unscaled_SPN4154  = {SPN_FIELD_MASK_4_BIT, 4 , 0 , 7};
static const T_J1939_SPN_unscaled mt_Unscaled_SPN512 = {1 , 250}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN513 = {2 , 250}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN1483 = {5 , 253}; // 
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN1675 = {SPN_FIELD_MASK_4_BIT , 6 , 0 , 14}; // 
static const T_J1939_SPN_unscaled         mt_Unscaled_SPN2432  = {7 , 250};
static const T_J1939_SPN_unscaled mt_Unscaled_SPN190 = {3 , 64255}; // 
static const T_J1939_SPN_scaled mt_Scaled_SPN512 = {1 , SPN_SCALING_FACTOR_1 , -125 , 250};
static const T_J1939_SPN_scaled mt_Scaled_SPN513 = {2 , SPN_SCALING_FACTOR_1 , -125 , 250};
static const T_J1939_SPN_scaled           mt_Scaled_SPN2432  = {7 , 0 , -125 , 250};
static const T_J1939_SPN_scaled mt_Scaled_SPN190 = {3 , SPN_SCALING_FACTOR_8 , 0 , 64255};


static const T_J1939_SPN_description mat_SPNS[] =
{
   {   // SPN  899
      offsetof(PG_TYPE,u8_EngineTorqueMode),
      &mt_Unscaled_SPN899,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  4154
      offsetof(PG_TYPE,u8_ActualEnginePercentTorqueHighResolution),
      &mt_Unscaled_SPN4154,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  512
      offsetof(PG_TYPE,u8_DrvrDemandEngPercTorque),
      &mt_Unscaled_SPN512,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  513
      offsetof(PG_TYPE,u8_ActualEngPercentTorque),
      &mt_Unscaled_SPN513,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  1483
      offsetof(PG_TYPE,u8_SrcAddrCtrlDevEngCtrl),
      &mt_Unscaled_SPN1483,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  1675
      offsetof(PG_TYPE,u8_EngineStarterMode),
      &mt_Unscaled_SPN1675,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  2432
      offsetof(PG_TYPE,u8_EngineDemandPercentTorque),
      &mt_Unscaled_SPN2432,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  190
      offsetof(PG_TYPE,u16_EngineSpeed),
      &mt_Unscaled_SPN190,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_unscaled
   },
   // ----------------------------------
   {  // scaled SPNs follow
      J1939_SPN_SCALED, NULL, NULL, NULL
   },
   {   // SPN  512
      offsetof(PG_TYPE,s8_DrvrDemandEngPercTorque_perc),
      &mt_Scaled_SPN512,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_s8_u8_scaled_offset, (PR_J1939_SPN_HandleTx)&J1939_spn_set_s8_u8_scaled_offset
   },
   {   // SPN  513
      offsetof(PG_TYPE,s8_ActualEngPercentTorque_perc),
      &mt_Scaled_SPN513,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_s8_u8_scaled_offset, (PR_J1939_SPN_HandleTx)&J1939_spn_set_s8_u8_scaled_offset
   },
   {   // SPN  2432
      offsetof(PG_TYPE,s8_EngineDemandPercentTorque_percent),
      &mt_Scaled_SPN2432,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_s8_u8_scaled_offset, (PR_J1939_SPN_HandleTx)&J1939_spn_set_s8_u8_scaled_offset
   },
   {   // SPN  190
      offsetof(PG_TYPE,u16_EngineSpeed_rpm),
      &mt_Scaled_SPN190,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_u16_scaled_div, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_u16_scaled_div
   },
   {  // End mark
      0, NULL, NULL, NULL
   }
};


// -- Global Variables ---------------------------------------------------------
const T_J1939_PGN_parameters gt_J1939_PGN_CFG_EEC1 =
{
   J1939_PGN_EEC1,    // PGN
   3,                // default priority
   8,                // PG data buffer size
   sizeof(PG_TYPE),  // structure size
   1000,             // Rx default timeout [ms]
   50,             // Tx default cycle time [ms]
   mat_SPNS          // array with all PG SPNS
};
