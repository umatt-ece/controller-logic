//-----------------------------------------------------------------------------
/*!
   \internal
   \file
   \brief       Application specific J1939 PGN EH

   Defines the PGN ECUHistory

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
#include "j1939_pgn_EH.h"
#include "j1939_pgn_types.h"
#include "j1939_pg_rt_config.h"


// -- Defines -----------------------------------------------------------------
#define PG_TYPE       T_J1939_PGN_EH                     // identificate the PG


// -- Module Global Variables --------------------------------------------------
static const T_J1939_SPN_unscaled mt_Unscaled_SPN1032 = {0 , 0xFAFFFFFF}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN1033 = {4 , 0xFAFFFFFF}; // 


static const T_J1939_SPN_description mat_SPNS[] =
{
   {   // SPN  1032
      offsetof(PG_TYPE,u32_TotalEcuDistance),
      &mt_Unscaled_SPN1032,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u32_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u32_unscaled
   },
   {   // SPN  1033
      offsetof(PG_TYPE,u32_TotalEcuRunTime),
      &mt_Unscaled_SPN1033,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u32_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u32_unscaled
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
const T_J1939_PGN_parameters gt_J1939_PGN_CFG_EH =
{
   J1939_PGN_EH,    // PGN
   7,                // default priority
   8,                // PG data buffer size
   sizeof(PG_TYPE),  // structure size
   J1939_DISABLE_TIME,             // Rx default timeout [ms]
   J1939_DISABLE_TIME,             // Tx default cycle time [ms]
   mat_SPNS          // array with all PG SPNS
};
