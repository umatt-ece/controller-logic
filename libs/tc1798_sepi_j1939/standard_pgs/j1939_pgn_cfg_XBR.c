//-----------------------------------------------------------------------------
/*!
   \internal
   \file
   \brief       Application specific J1939 PGN XBR

   Defines the PGN External Brake Request

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
#include "j1939_pgn_XBR.h"
#include "j1939_pgn_types.h"
#include "j1939_pg_rt_config.h"


// -- Defines -----------------------------------------------------------------
#define PG_TYPE       T_J1939_PGN_XBR                     // identificate the PG


// -- Module Global Variables --------------------------------------------------
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN2914 = {SPN_FIELD_MASK_2_BIT , 0 , 2 , 2}; // 
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN2915 = {SPN_FIELD_MASK_2_BIT , 2 , 2 , 3}; // 
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN2916 = {SPN_FIELD_MASK_2_BIT , 4 , 2 , 2}; // 
static const T_J1939_SPN_unscaled         mt_Unscaled_SPN4099  = {3 , 250};
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN3189 = {SPN_FIELD_MASK_4_BIT , 0 , 7 , 15}; // 
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN3188 = {SPN_FIELD_MASK_4_BIT , 4 , 7 , 15}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN2920 = {0 , 64255}; // 
static const T_J1939_SPN_scaled           mt_Scaled_SPN4099  = {3 , 2 , 0 , 250};
static const T_J1939_SPN_scaled_2_factors mt_Scaled_SPN2920 = {0 , SPN_SCALING_FACTOR_256 , 125 , -15687 , 64255};


static const T_J1939_SPN_description mat_SPNS[] =
{
   {   // SPN  2914
      offsetof(PG_TYPE,u8_XBREBIMode),
      &mt_Unscaled_SPN2914,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  2915
      offsetof(PG_TYPE,u8_XBRPriority),
      &mt_Unscaled_SPN2915,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  2916
      offsetof(PG_TYPE,u8_XBRControlMode),
      &mt_Unscaled_SPN2916,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  4099
      offsetof(PG_TYPE,u8_XBRUrgency),
      &mt_Unscaled_SPN4099,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  3189
      offsetof(PG_TYPE,u8_XBRMessageCounter),
      &mt_Unscaled_SPN3189,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  3188
      offsetof(PG_TYPE,u8_XBRMessageChecksum),
      &mt_Unscaled_SPN3188,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  2920
      offsetof(PG_TYPE,u16_ExternalAccelerationDemand),
      &mt_Unscaled_SPN2920,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_unscaled
   },
   // ----------------------------------
   {  // scaled SPNs follow
      J1939_SPN_SCALED, NULL, NULL, NULL
   },
   {   // SPN  4099
      offsetof(PG_TYPE,u16_XBRUrgency_permil),
      &mt_Scaled_SPN4099,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_u8_scaled_mult, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_u8_scaled_mult
   },
   {   // SPN  2920
      offsetof(PG_TYPE,s16_ExternalAccelerationDemand_mm_s2),
      &mt_Scaled_SPN2920,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_s16_u16_scaled_div_offset, (PR_J1939_SPN_HandleTx)&J1939_spn_set_s16_u16_scaled_div_offset
   },
   {  // End mark
      0, NULL, NULL, NULL
   }
};


// -- Global Variables ---------------------------------------------------------
const T_J1939_PGN_parameters gt_J1939_PGN_CFG_XBR =
{
   J1939_PGN_XBR,    // PGN
   3,                // default priority
   8,                // PG data buffer size
   sizeof(PG_TYPE),  // structure size
   20,             // Rx default timeout [ms]
   20,             // Tx default cycle time [ms]
   mat_SPNS          // array with all PG SPNS
};
