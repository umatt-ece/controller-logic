//-----------------------------------------------------------------------------
/*!
   \internal
   \file
   \brief       Application specific J1939 PGN CTL

   Defines the PGN Continuous Torque Speed Limit Request

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
#include "j1939_pgn_CTL.h"
#include "j1939_pgn_types.h"
#include "j1939_pg_rt_config.h"


// -- Defines -----------------------------------------------------------------
#define PG_TYPE       T_J1939_PGN_CTL                     // identificate the PG


// -- Module Global Variables --------------------------------------------------
static const T_J1939_SPN_unscaled mt_Unscaled_SPN1784 = {0 , 250}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN1785 = {1 , 250}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN1786 = {2 , 250}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN1787 = {3 , 250}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN1788 = {4 , 250}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN1789 = {5 , 250}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN1790 = {6 , 250}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN1791 = {7 , 250}; // 
static const T_J1939_SPN_scaled mt_Scaled_SPN1784 = {0 , SPN_SCALING_FACTOR_32 , 0 , 250};
static const T_J1939_SPN_scaled mt_Scaled_SPN1785 = {1 , SPN_SCALING_FACTOR_32 , 0 , 250};
static const T_J1939_SPN_scaled mt_Scaled_SPN1786 = {2 , SPN_SCALING_FACTOR_1 , -125 , 250};
static const T_J1939_SPN_scaled mt_Scaled_SPN1787 = {3 , SPN_SCALING_FACTOR_1 , -125 , 250};
static const T_J1939_SPN_scaled mt_Scaled_SPN1788 = {4 , SPN_SCALING_FACTOR_32 , 0 , 250};
static const T_J1939_SPN_scaled mt_Scaled_SPN1789 = {5 , SPN_SCALING_FACTOR_32 , 0 , 250};
static const T_J1939_SPN_scaled mt_Scaled_SPN1790 = {6 , SPN_SCALING_FACTOR_1 , -125 , 250};
static const T_J1939_SPN_scaled mt_Scaled_SPN1791 = {7 , SPN_SCALING_FACTOR_1 , -125 , 250};


static const T_J1939_SPN_description mat_SPNS[] =
{
   {   // SPN  1784
      offsetof(PG_TYPE,u8_MinContEngineSpeedLimitReq),
      &mt_Unscaled_SPN1784,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  1785
      offsetof(PG_TYPE,u8_MaxContEngineSpeedLimitReq),
      &mt_Unscaled_SPN1785,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  1786
      offsetof(PG_TYPE,u8_MinContEngineTorqueLimitReq),
      &mt_Unscaled_SPN1786,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  1787
      offsetof(PG_TYPE,u8_MaxContEngineTorqueLimitReq),
      &mt_Unscaled_SPN1787,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  1788
      offsetof(PG_TYPE,u8_MinContRetarderSpeedLimitReq),
      &mt_Unscaled_SPN1788,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  1789
      offsetof(PG_TYPE,u8_MaxContRetarderSpeedLimitReq),
      &mt_Unscaled_SPN1789,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  1790
      offsetof(PG_TYPE,u8_MinContRetarderTorqueLimitReq),
      &mt_Unscaled_SPN1790,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  1791
      offsetof(PG_TYPE,u8_MaxContRetarderTorqueLimitReq),
      &mt_Unscaled_SPN1791,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   // ----------------------------------
   {  // scaled SPNs follow
      J1939_SPN_SCALED, NULL, NULL, NULL
   },
   {   // SPN  1784
      offsetof(PG_TYPE,u16_MinContEngineSpeedLimitReq_rpm),
      &mt_Scaled_SPN1784,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_u8_scaled_mult, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_u8_scaled_mult
   },
   {   // SPN  1785
      offsetof(PG_TYPE,u16_MaxContEngineSpeedLimitReq_rpm),
      &mt_Scaled_SPN1785,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_u8_scaled_mult, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_u8_scaled_mult
   },
   {   // SPN  1786
      offsetof(PG_TYPE,s8_MinContEngineTorqueLimitReq_perc),
      &mt_Scaled_SPN1786,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_s8_u8_scaled_offset, (PR_J1939_SPN_HandleTx)&J1939_spn_set_s8_u8_scaled_offset
   },
   {   // SPN  1787
      offsetof(PG_TYPE,s8_MaxContEngineTorqueLimitReq_perc),
      &mt_Scaled_SPN1787,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_s8_u8_scaled_offset, (PR_J1939_SPN_HandleTx)&J1939_spn_set_s8_u8_scaled_offset
   },
   {   // SPN  1788
      offsetof(PG_TYPE,u16_MinContRetarderSpeedLimitReq_rpm),
      &mt_Scaled_SPN1788,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_u8_scaled_mult, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_u8_scaled_mult
   },
   {   // SPN  1789
      offsetof(PG_TYPE,u16_MaxContRetarderSpeedLimitReq_rpm),
      &mt_Scaled_SPN1789,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_u8_scaled_mult, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_u8_scaled_mult
   },
   {   // SPN  1790
      offsetof(PG_TYPE,s8_MinContRetarderTorqueLimitReq_perc),
      &mt_Scaled_SPN1790,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_s8_u8_scaled_offset, (PR_J1939_SPN_HandleTx)&J1939_spn_set_s8_u8_scaled_offset
   },
   {   // SPN  1791
      offsetof(PG_TYPE,s8_MaxContRetarderTorqueLimitReq_perc),
      &mt_Scaled_SPN1791,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_s8_u8_scaled_offset, (PR_J1939_SPN_HandleTx)&J1939_spn_set_s8_u8_scaled_offset
   },
   {  // End mark
      0, NULL, NULL, NULL
   }
};


// -- Global Variables ---------------------------------------------------------
const T_J1939_PGN_parameters gt_J1939_PGN_CFG_CTL =
{
   J1939_PGN_CTL,    // PGN
   6,                // default priority
   8,                // PG data buffer size
   sizeof(PG_TYPE),  // structure size
   5000,             // Rx default timeout [ms]
   5000,             // Tx default cycle time [ms]
   mat_SPNS          // array with all PG SPNS
};
