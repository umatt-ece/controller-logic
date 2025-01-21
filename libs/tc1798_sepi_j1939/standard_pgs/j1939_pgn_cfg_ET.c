//-----------------------------------------------------------------------------
/*!
   \internal
   \file
   \brief       Application specific J1939 PGN ET

   Defines the PGN Exhaust Temperature

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
#include "j1939_pgn_ET.h"
#include "j1939_pgn_types.h"
#include "j1939_pg_rt_config.h"


// -- Defines -----------------------------------------------------------------
#define PG_TYPE       T_J1939_PGN_ET                     // identificate the PG


// -- Module Global Variables --------------------------------------------------
static const T_J1939_SPN_unscaled mt_Unscaled_SPN2433 = {0 , 64255}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN2434 = {2 , 64255}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN5969 = {4 , 64255}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN5970 = {6 , 64255}; // 
static const T_J1939_SPN_scaled_2_factors mt_Scaled_SPN2433 = {0 , SPN_SCALING_FACTOR_16 , 5 , -2730 , 64255};
static const T_J1939_SPN_scaled_2_factors mt_Scaled_SPN2434 = {2 , SPN_SCALING_FACTOR_16 , 5 , -2730 , 64255};
static const T_J1939_SPN_scaled_2_factors mt_Scaled_SPN5969 = {4 , SPN_SCALING_FACTOR_16 , 5 , -2730 , 64255};
static const T_J1939_SPN_scaled_2_factors mt_Scaled_SPN5970 = {6 , SPN_SCALING_FACTOR_16 , 5 , -2730 , 64255};


static const T_J1939_SPN_description mat_SPNS[] =
{
   {   // SPN  2433
      offsetof(PG_TYPE,u16_EngExhaustManifoldBank2Temp1),
      &mt_Unscaled_SPN2433,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_unscaled
   },
   {   // SPN  2434
      offsetof(PG_TYPE,u16_EngExhaustManifoldBank1Temp1),
      &mt_Unscaled_SPN2434,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_unscaled
   },
   {   // SPN  5969
      offsetof(PG_TYPE,u16_EngExhaustManifoldBank2Temp2),
      &mt_Unscaled_SPN5969,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_unscaled
   },
   {   // SPN  5970
      offsetof(PG_TYPE,u16_EngExhaustManifoldBank1Temp2),
      &mt_Unscaled_SPN5970,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_unscaled
   },
   // ----------------------------------
   {  // scaled SPNs follow
      J1939_SPN_SCALED, NULL, NULL, NULL
   },
   {   // SPN  2433
      offsetof(PG_TYPE,s16_EngExhaustManifoldBank2Temp1_01degC),
      &mt_Scaled_SPN2433,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_s16_u16_scaled_div_offset, (PR_J1939_SPN_HandleTx)&J1939_spn_set_s16_u16_scaled_div_offset
   },
   {   // SPN  2434
      offsetof(PG_TYPE,s16_EngExhaustManifoldBank1Temp1_01degC),
      &mt_Scaled_SPN2434,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_s16_u16_scaled_div_offset, (PR_J1939_SPN_HandleTx)&J1939_spn_set_s16_u16_scaled_div_offset
   },
   {   // SPN  5969
      offsetof(PG_TYPE,s16_EngExhaustManifoldBank2Temp2_01degC),
      &mt_Scaled_SPN5969,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_s16_u16_scaled_div_offset, (PR_J1939_SPN_HandleTx)&J1939_spn_set_s16_u16_scaled_div_offset
   },
   {   // SPN  5970
      offsetof(PG_TYPE,s16_EngExhaustManifoldBank1Temp2_01degC),
      &mt_Scaled_SPN5970,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_s16_u16_scaled_div_offset, (PR_J1939_SPN_HandleTx)&J1939_spn_set_s16_u16_scaled_div_offset
   },
   {  // End mark
      0, NULL, NULL, NULL
   }
};


// -- Global Variables ---------------------------------------------------------
const T_J1939_PGN_parameters gt_J1939_PGN_CFG_ET =
{
   J1939_PGN_ET,    // PGN
   6,                // default priority
   8,                // PG data buffer size
   sizeof(PG_TYPE),  // structure size
   500,             // Rx default timeout [ms]
   500,             // Tx default cycle time [ms]
   mat_SPNS          // array with all PG SPNS
};
