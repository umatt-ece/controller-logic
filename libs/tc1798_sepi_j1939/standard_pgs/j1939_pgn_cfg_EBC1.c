//-----------------------------------------------------------------------------
/*!
   \internal
   \file
   \brief       Application specific J1939 PGN EBC1

   Defines the PGN Electronic Brake Controller 1

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
#include "j1939_pgn_EBC1.h"
#include "j1939_pgn_types.h"
#include "j1939_pg_rt_config.h"


// -- Defines -----------------------------------------------------------------
#define PG_TYPE       T_J1939_PGN_EBC1                     // identificate the PG


// -- Module Global Variables --------------------------------------------------
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN561 = {SPN_FIELD_MASK_2_BIT , 0 , 0 , 1}; // 
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN562 = {SPN_FIELD_MASK_2_BIT , 2 , 0 , 1}; // 
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN563 = {SPN_FIELD_MASK_2_BIT , 4 , 0 , 1}; // 
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN1121 = {SPN_FIELD_MASK_2_BIT , 6 , 0 , 2}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN521 = {1 , 250}; // 
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN575 = {SPN_FIELD_MASK_2_BIT , 0 , 2 , 2}; // 
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN576 = {SPN_FIELD_MASK_2_BIT , 2 , 2 , 2}; // 
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN577 = {SPN_FIELD_MASK_2_BIT , 4 , 2 , 2}; // 
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN1238 = {SPN_FIELD_MASK_2_BIT , 6 , 2 , 2}; // 
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN972 = {SPN_FIELD_MASK_2_BIT , 0 , 3 , 2}; // 
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN971 = {SPN_FIELD_MASK_2_BIT , 2 , 3 , 2}; // 
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN970 = {SPN_FIELD_MASK_2_BIT , 4 , 3 , 2}; // 
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN969 = {SPN_FIELD_MASK_2_BIT , 6 , 3 , 2}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN973 = {4 , 250}; // 
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN1243 = {SPN_FIELD_MASK_2_BIT , 0 , 5 , 1}; // 
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN1439 = {SPN_FIELD_MASK_2_BIT , 2 , 5 , 1}; // 
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN1438 = {SPN_FIELD_MASK_2_BIT , 4 , 5 , 1}; // 
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN1793 = {SPN_FIELD_MASK_2_BIT , 6 , 5 , 1}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN1481 = {6 , 250}; // 
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN2911 = {SPN_FIELD_MASK_2_BIT , 2 , 7 , 2}; // 
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN1836 = {SPN_FIELD_MASK_2_BIT , 4 , 7 , 1}; // 
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN1792 = {SPN_FIELD_MASK_2_BIT , 6 , 7 , 1}; // 
static const T_J1939_SPN_scaled mt_Scaled_SPN521 = {1 , SPN_SCALING_FACTOR_4 , 0 , 250};
static const T_J1939_SPN_scaled mt_Scaled_SPN973 = {4 , SPN_SCALING_FACTOR_4 , 0 , 250};


static const T_J1939_SPN_description mat_SPNS[] =
{
   {   // SPN  561
      offsetof(PG_TYPE,u8_ASR_EngineControlActive),
      &mt_Unscaled_SPN561,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  562
      offsetof(PG_TYPE,u8_ASR_BrakeControlActive),
      &mt_Unscaled_SPN562,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  563
      offsetof(PG_TYPE,u8_AntiLockBrakingActive),
      &mt_Unscaled_SPN563,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  1121
      offsetof(PG_TYPE,u8_EBS_BrakeSwitch),
      &mt_Unscaled_SPN1121,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  521
      offsetof(PG_TYPE,u8_BrakePedalPosition),
      &mt_Unscaled_SPN521,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  575
      offsetof(PG_TYPE,u8_ABS_OffRoadSwitch),
      &mt_Unscaled_SPN575,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  576
      offsetof(PG_TYPE,u8_ASR_OffRoadSwitch),
      &mt_Unscaled_SPN576,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  577
      offsetof(PG_TYPE,u8_ASR_HillHolderSwitch),
      &mt_Unscaled_SPN577,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  1238
      offsetof(PG_TYPE,u8_TractionControlOverrideSwitch),
      &mt_Unscaled_SPN1238,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  972
      offsetof(PG_TYPE,u8_AcceleratorInterlockSwitch),
      &mt_Unscaled_SPN972,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  971
      offsetof(PG_TYPE,u8_EngineDerateSwitch),
      &mt_Unscaled_SPN971,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  970
      offsetof(PG_TYPE,u8_EngineAuxiliaryShutdownSwitch),
      &mt_Unscaled_SPN970,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  969
      offsetof(PG_TYPE,u8_RemoteAcceleratorEnableSwitch),
      &mt_Unscaled_SPN969,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  973
      offsetof(PG_TYPE,u8_EngineRetarderSelection),
      &mt_Unscaled_SPN973,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  1243
      offsetof(PG_TYPE,u8_ABS_FullyOperational),
      &mt_Unscaled_SPN1243,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  1439
      offsetof(PG_TYPE,u8_EBS_RedWarningSignal),
      &mt_Unscaled_SPN1439,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  1438
      offsetof(PG_TYPE,u8_ABS_EBS_AmberWarningSignal),
      &mt_Unscaled_SPN1438,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  1793
      offsetof(PG_TYPE,u8_ATC_ASR_InformationSignal),
      &mt_Unscaled_SPN1793,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  1481
      offsetof(PG_TYPE,u8_SrcAddrOfCntrlingBrakeControlDevice),
      &mt_Unscaled_SPN1481,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  2911
      offsetof(PG_TYPE,u8_HaltBrakeSwitch),
      &mt_Unscaled_SPN2911,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  1836
      offsetof(PG_TYPE,u8_TrailerABSStatus),
      &mt_Unscaled_SPN1836,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  1792
      offsetof(PG_TYPE,u8_TractorMountedTrailerABSWarnSignal),
      &mt_Unscaled_SPN1792,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   // ----------------------------------
   {  // scaled SPNs follow
      J1939_SPN_SCALED, NULL, NULL, NULL
   },
   {   // SPN  521
      offsetof(PG_TYPE,u16_BrakePedalPosition_permil),
      &mt_Scaled_SPN521,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_u8_scaled_mult, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_u8_scaled_mult
   },
   {   // SPN  973
      offsetof(PG_TYPE,u16_EngineRetarderSelection_permil),
      &mt_Scaled_SPN973,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_u8_scaled_mult, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_u8_scaled_mult
   },
   {  // End mark
      0, NULL, NULL, NULL
   }
};


// -- Global Variables ---------------------------------------------------------
const T_J1939_PGN_parameters gt_J1939_PGN_CFG_EBC1 =
{
   J1939_PGN_EBC1,    // PGN
   6,                // default priority
   8,                // PG data buffer size
   sizeof(PG_TYPE),  // structure size
   100,             // Rx default timeout [ms]
   100,             // Tx default cycle time [ms]
   mat_SPNS          // array with all PG SPNS
};
