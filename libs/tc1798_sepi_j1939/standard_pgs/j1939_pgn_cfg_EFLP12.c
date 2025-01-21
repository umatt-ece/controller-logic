//-----------------------------------------------------------------------------
/*!
   \internal
   \file
   \brief       Application specific J1939 PGN EFLP12

   Defines the PGN Engine Fluid Level Pressure 12

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
#include "j1939_pgn_EFLP12.h"
#include "j1939_pgn_types.h"
#include "j1939_pg_rt_config.h"


// -- Defines -----------------------------------------------------------------
#define PG_TYPE       T_J1939_PGN_EFLP12                     // identificate the PG


// -- Module Global Variables --------------------------------------------------
static const T_J1939_SPN_unscaled mt_Unscaled_SPN5578 = {0 , 250}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN5579 = {1 , 250}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN5580 = {2 , 250}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN5584 = {3 , 250}; // 
static const T_J1939_SPN_scaled mt_Scaled_SPN5578 = {0 , SPN_SCALING_FACTOR_4 , 0 , 250};
static const T_J1939_SPN_scaled mt_Scaled_SPN5579 = {1 , SPN_SCALING_FACTOR_4 , 0 , 250};
static const T_J1939_SPN_scaled mt_Scaled_SPN5580 = {2 , SPN_SCALING_FACTOR_4 , 0 , 250};


static const T_J1939_SPN_description mat_SPNS[] =
{
   {   // SPN  5578
      offsetof(PG_TYPE,u8_EngFuelDeliveryAbsolutePressure),
      &mt_Unscaled_SPN5578,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  5579
      offsetof(PG_TYPE,u8_EngFilteredFuelDeliveryPressure),
      &mt_Unscaled_SPN5579,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  5580
      offsetof(PG_TYPE,u8_EngFiltrdFuelDeliveryAbsolutePress),
      &mt_Unscaled_SPN5580,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  5584
      offsetof(PG_TYPE,u8_EngFuelFilterDegradation),
      &mt_Unscaled_SPN5584,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   // ----------------------------------
   {  // scaled SPNs follow
      J1939_SPN_SCALED, NULL, NULL, NULL
   },
   {   // SPN  5578
      offsetof(PG_TYPE,u16_EngFuelDeliveryAbsolutePressure_kPa),
      &mt_Scaled_SPN5578,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_u8_scaled_mult, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_u8_scaled_mult
   },
   {   // SPN  5579
      offsetof(PG_TYPE,u16_EngFilteredFuelDeliveryPressure_kPa),
      &mt_Scaled_SPN5579,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_u8_scaled_mult, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_u8_scaled_mult
   },
   {   // SPN  5580
      offsetof(PG_TYPE,u16_EngFiltrdFuelDeliveryAbsltPress_kPa),
      &mt_Scaled_SPN5580,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_u8_scaled_mult, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_u8_scaled_mult
   },
   {  // End mark
      0, NULL, NULL, NULL
   }
};


// -- Global Variables ---------------------------------------------------------
const T_J1939_PGN_parameters gt_J1939_PGN_CFG_EFLP12 =
{
   J1939_PGN_EFLP12,    // PGN
   6,                // default priority
   8,                // PG data buffer size
   sizeof(PG_TYPE),  // structure size
   500,             // Rx default timeout [ms]
   500,             // Tx default cycle time [ms]
   mat_SPNS          // array with all PG SPNS
};
