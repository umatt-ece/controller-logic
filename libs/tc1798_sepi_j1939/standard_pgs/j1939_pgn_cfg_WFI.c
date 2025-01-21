//-----------------------------------------------------------------------------
/*!
   \internal
   \file
   \brief       Application specific J1939 PGN WFI

   Defines the PGN Operator Indicators

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
#include "j1939_pgn_WFI.h"
#include "j1939_pgn_types.h"
#include "j1939_pg_rt_config.h"


// -- Defines -----------------------------------------------------------------
#define PG_TYPE       T_J1939_PGN_WFI                     // identificate the PG


// -- Module Global Variables --------------------------------------------------
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN97 = {SPN_FIELD_MASK_2_BIT , 0 , 0 , 2}; // 
static const T_J1939_SPN_u8_bit_field     mt_Unscaled_SPN5675  = {SPN_FIELD_MASK_2_BIT, 2 , 0 , 2};
static const T_J1939_SPN_u8_bit_field     mt_Unscaled_SPN6301  = {SPN_FIELD_MASK_2_BIT, 4 , 0 , 2};
static const T_J1939_SPN_u8_bit_field     mt_Unscaled_SPN5825  = {SPN_FIELD_MASK_3_BIT, 0 , 1 , 6};
static const T_J1939_SPN_u8_bit_field     mt_Unscaled_SPN5826  = {SPN_FIELD_MASK_3_BIT, 3 , 1 , 6};


static const T_J1939_SPN_description mat_SPNS[] =
{
   {   // SPN  97
      offsetof(PG_TYPE,u8_WaterInFuelIndicator),
      &mt_Unscaled_SPN97,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  5675
      offsetof(PG_TYPE,u8_OperatorShiftPrompt),
      &mt_Unscaled_SPN5675,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  6301
      offsetof(PG_TYPE,u8_WaterInFuelIndicator2),
      &mt_Unscaled_SPN6301,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  5825
      offsetof(PG_TYPE,u8_DriverWarningSystemIndicatorStatus),
      &mt_Unscaled_SPN5825,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  5826
      offsetof(PG_TYPE,u8_EmissionControlSystemOperatorInducementSeverity),
      &mt_Unscaled_SPN5826,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   // ----------------------------------
   {  // scaled SPNs follow
      J1939_SPN_SCALED, NULL, NULL, NULL
   },
   {  // End mark
      0, NULL, NULL, NULL
   }
};


// -- Global Variables ---------------------------------------------------------
const T_J1939_PGN_parameters gt_J1939_PGN_CFG_WFI =
{
   J1939_PGN_WFI,    // PGN
   6,                // default priority
   8,                // PG data buffer size
   sizeof(PG_TYPE),  // structure size
   10000,             // Rx default timeout [ms]
   10000,             // Tx default cycle time [ms]
   mat_SPNS          // array with all PG SPNS
};
