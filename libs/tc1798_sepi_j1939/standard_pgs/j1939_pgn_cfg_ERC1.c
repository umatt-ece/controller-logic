//-----------------------------------------------------------------------------
/*!
   \internal
   \file
   \brief       Application specific J1939 PGN ERC1

   Defines the PGN Electronic Retarder Controller 1

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
#include "j1939_pgn_ERC1.h"
#include "j1939_pgn_types.h"
#include "j1939_pg_rt_config.h"


// -- Defines -----------------------------------------------------------------
#define PG_TYPE       T_J1939_PGN_ERC1                     // identificate the PG


// -- Module Global Variables --------------------------------------------------
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN900 = {SPN_FIELD_MASK_4_BIT , 0 , 0 , 15}; // 
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN571 = {SPN_FIELD_MASK_2_BIT , 4 , 0 , 2}; // 
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN572 = {SPN_FIELD_MASK_2_BIT , 6 , 0 , 2}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN520 = {1 , 250}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN1085 = {2 , 250}; // 
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN1082 = {SPN_FIELD_MASK_2_BIT , 0 , 3 , 2}; // 
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN1667 = {SPN_FIELD_MASK_2_BIT , 2 , 3 , 3}; // 
static const T_J1939_SPN_u8_bit_field     mt_Unscaled_SPN4233  = {SPN_FIELD_MASK_2_BIT, 4 , 3 , 2};
static const T_J1939_SPN_u8_bit_field     mt_Unscaled_SPN4234  = {SPN_FIELD_MASK_2_BIT, 6 , 3 , 2};
static const T_J1939_SPN_unscaled mt_Unscaled_SPN1480 = {4 , 253}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN1715 = {5 , 250}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN1716 = {6 , 250}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN1717 = {7 , 250}; // 
static const T_J1939_SPN_scaled mt_Scaled_SPN520 = {1 , SPN_SCALING_FACTOR_1 , -125 , 250};
static const T_J1939_SPN_scaled mt_Scaled_SPN1085 = {2 , SPN_SCALING_FACTOR_1 , -125 , 250};
static const T_J1939_SPN_scaled mt_Scaled_SPN1715 = {5 , SPN_SCALING_FACTOR_1 , -125 , 250};
static const T_J1939_SPN_scaled mt_Scaled_SPN1716 = {6 , SPN_SCALING_FACTOR_4 , 0 , 250};
static const T_J1939_SPN_scaled mt_Scaled_SPN1717 = {7 , SPN_SCALING_FACTOR_1 , -125 , 250};


static const T_J1939_SPN_description mat_SPNS[] =
{
   {   // SPN  900
      offsetof(PG_TYPE,u8_RetarderTorqueMode),
      &mt_Unscaled_SPN900,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  571
      offsetof(PG_TYPE,u8_RetarderEnableBrakeAssistSwitch),
      &mt_Unscaled_SPN571,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  572
      offsetof(PG_TYPE,u8_RetarderEnableShiftAssistSwitch),
      &mt_Unscaled_SPN572,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  520
      offsetof(PG_TYPE,u8_ActualRetarderPercentTorque),
      &mt_Unscaled_SPN520,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  1085
      offsetof(PG_TYPE,u8_IntendedRetarderPercentTorque),
      &mt_Unscaled_SPN1085,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  1082
      offsetof(PG_TYPE,u8_EngineCoolantLoadIncrease),
      &mt_Unscaled_SPN1082,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  1667
      offsetof(PG_TYPE,u8_RetarderRequestingBrakeLight),
      &mt_Unscaled_SPN1667,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  4233
      offsetof(PG_TYPE,u8_RetarderRoadSpeedLimitSwitch),
      &mt_Unscaled_SPN4233,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  4234
      offsetof(PG_TYPE,u8_RetarderRoadSpeedExceededStatus),
      &mt_Unscaled_SPN4234,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  1480
      offsetof(PG_TYPE,u8_SrcAddrOfCntrlDeviceForRetCntrl),
      &mt_Unscaled_SPN1480,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  1715
      offsetof(PG_TYPE,u8_DriversDemandRetarderPercTorq),
      &mt_Unscaled_SPN1715,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  1716
      offsetof(PG_TYPE,u8_RetarderSelectionNonEngine),
      &mt_Unscaled_SPN1716,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  1717
      offsetof(PG_TYPE,u8_ActMaxAvlblRetarderPercTorque),
      &mt_Unscaled_SPN1717,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   // ----------------------------------
   {  // scaled SPNs follow
      J1939_SPN_SCALED, NULL, NULL, NULL
   },
   {   // SPN  520
      offsetof(PG_TYPE,s8_ActualRetarderPercentTorque_perc),
      &mt_Scaled_SPN520,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_s8_u8_scaled_offset, (PR_J1939_SPN_HandleTx)&J1939_spn_set_s8_u8_scaled_offset
   },
   {   // SPN  1085
      offsetof(PG_TYPE,s8_IntendedRetarderPercentTorque_perc),
      &mt_Scaled_SPN1085,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_s8_u8_scaled_offset, (PR_J1939_SPN_HandleTx)&J1939_spn_set_s8_u8_scaled_offset
   },
   {   // SPN  1715
      offsetof(PG_TYPE,s8_DriversDemandRetarderPercTorq_perc),
      &mt_Scaled_SPN1715,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_s8_u8_scaled_offset, (PR_J1939_SPN_HandleTx)&J1939_spn_set_s8_u8_scaled_offset
   },
   {   // SPN  1716
      offsetof(PG_TYPE,u16_RetarderSelectionNonEngine_permill),
      &mt_Scaled_SPN1716,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_u8_scaled_mult, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_u8_scaled_mult
   },
   {   // SPN  1717
      offsetof(PG_TYPE,s8_ActMaxAvlblRetarderPercTorque_perc),
      &mt_Scaled_SPN1717,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_s8_u8_scaled_offset, (PR_J1939_SPN_HandleTx)&J1939_spn_set_s8_u8_scaled_offset
   },
   {  // End mark
      0, NULL, NULL, NULL
   }
};


// -- Global Variables ---------------------------------------------------------
const T_J1939_PGN_parameters gt_J1939_PGN_CFG_ERC1 =
{
   J1939_PGN_ERC1,    // PGN
   6,                // default priority
   8,                // PG data buffer size
   sizeof(PG_TYPE),  // structure size
   100,             // Rx default timeout [ms]
   100,             // Tx default cycle time [ms]
   mat_SPNS          // array with all PG SPNS
};
