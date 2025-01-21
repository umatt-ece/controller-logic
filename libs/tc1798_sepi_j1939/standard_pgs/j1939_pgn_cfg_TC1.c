//-----------------------------------------------------------------------------
/*!
   \internal
   \file
   \brief       Application specific J1939 PGN TC1

   Defines the PGN Transmission Control 1

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
#include "j1939_pgn_TC1.h"
#include "j1939_pgn_types.h"
#include "j1939_pg_rt_config.h"


// -- Defines -----------------------------------------------------------------
#define PG_TYPE       T_J1939_PGN_TC1                     // identificate the PG


// -- Module Global Variables --------------------------------------------------
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN681 = {SPN_FIELD_MASK_2_BIT , 0 , 0 , 1}; // 
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN682 = {SPN_FIELD_MASK_2_BIT , 2 , 0 , 1}; // 
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN683 = {SPN_FIELD_MASK_2_BIT , 4 , 0 , 1}; // 
static const T_J1939_SPN_u8_bit_field     mt_Unscaled_SPN4242  = {SPN_FIELD_MASK_2_BIT, 6 , 0 , 2};
static const T_J1939_SPN_unscaled mt_Unscaled_SPN684 = {1 , 250}; // 
static const T_J1939_SPN_unscaled mt_Unscaled_SPN525 = {2 , 250}; // 
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN685 = {SPN_FIELD_MASK_2_BIT , 0 , 3 , 1}; // 
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN686 = {SPN_FIELD_MASK_2_BIT , 2 , 3 , 1}; // 
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN687 = {SPN_FIELD_MASK_2_BIT , 4 , 3 , 1}; // 
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN688 = {SPN_FIELD_MASK_2_BIT , 6 , 3 , 1}; // 
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN689 = {SPN_FIELD_MASK_2_BIT , 0 , 4 , 1}; // 
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN690 = {SPN_FIELD_MASK_2_BIT , 2 , 4 , 1}; // 
static const T_J1939_SPN_u8_bit_field mt_Unscaled_SPN691 = {SPN_FIELD_MASK_2_BIT , 4 , 4 , 1}; // 
static const T_J1939_SPN_u8_bit_field     mt_Unscaled_SPN5762  = {SPN_FIELD_MASK_2_BIT, 6 , 4 , 2};
static const T_J1939_SPN_u8_bit_field     mt_Unscaled_SPN1852  = {SPN_FIELD_MASK_2_BIT, 0 , 5 , 2};
static const T_J1939_SPN_u8_bit_field     mt_Unscaled_SPN1853  = {SPN_FIELD_MASK_2_BIT, 2 , 5 , 2};
static const T_J1939_SPN_u8_bit_field     mt_Unscaled_SPN1854  = {SPN_FIELD_MASK_2_BIT, 4 , 5 , 2};
static const T_J1939_SPN_u8_bit_field     mt_Unscaled_SPN1855  = {SPN_FIELD_MASK_2_BIT, 6 , 5 , 2};
static const T_J1939_SPN_u8_bit_field     mt_Unscaled_SPN4255  = {SPN_FIELD_MASK_4_BIT, 2 , 6 , 14};
static const T_J1939_SPN_u8_bit_field     mt_Unscaled_SPN2985  = {SPN_FIELD_MASK_2_BIT, 6 , 6 , 2};
static const T_J1939_SPN_u8_bit_field     mt_Unscaled_SPN4246  = {SPN_FIELD_MASK_2_BIT, 0 , 7 , 2};
static const T_J1939_SPN_u8_bit_field     mt_Unscaled_SPN4247  = {SPN_FIELD_MASK_2_BIT, 2 , 7 , 2};
static const T_J1939_SPN_u8_bit_field     mt_Unscaled_SPN4248  = {SPN_FIELD_MASK_2_BIT, 4 , 7 , 2};
static const T_J1939_SPN_u8_bit_field     mt_Unscaled_SPN4249  = {SPN_FIELD_MASK_2_BIT, 6 , 7 , 2};
static const T_J1939_SPN_scaled mt_Scaled_SPN684 = {1 , SPN_SCALING_FACTOR_4 , 0 , 250};
static const T_J1939_SPN_scaled mt_Scaled_SPN525 = {2 , SPN_SCALING_FACTOR_1 , -125 , 250};


static const T_J1939_SPN_description mat_SPNS[] =
{
   {   // SPN  681
      offsetof(PG_TYPE,u8_GearShiftInhibitRequest),
      &mt_Unscaled_SPN681,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  682
      offsetof(PG_TYPE,u8_TorqueConvertLockupDisableRequest),
      &mt_Unscaled_SPN682,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  683
      offsetof(PG_TYPE,u8_DisengageDrivelineRequest),
      &mt_Unscaled_SPN683,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  4242
      offsetof(PG_TYPE,u8_TransmissionReverseGearShiftInhibitRequest),
      &mt_Unscaled_SPN4242,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  684
      offsetof(PG_TYPE,u8_RequestedPercentClutchSlip),
      &mt_Unscaled_SPN684,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  525
      offsetof(PG_TYPE,u8_RequestedGear),
      &mt_Unscaled_SPN525,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u8_unscaled, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u8_unscaled
   },
   {   // SPN  685
      offsetof(PG_TYPE,u8_DisengDifferentLockReqFrntAx1),
      &mt_Unscaled_SPN685,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  686
      offsetof(PG_TYPE,u8_DisengDifferentLockReqFrntAx2),
      &mt_Unscaled_SPN686,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  687
      offsetof(PG_TYPE,u8_DisengDifferentLockReqRearAx1),
      &mt_Unscaled_SPN687,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  688
      offsetof(PG_TYPE,u8_DisengDifferentLockReqRearAx2),
      &mt_Unscaled_SPN688,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  689
      offsetof(PG_TYPE,u8_DisengDifferentLockReqCentral),
      &mt_Unscaled_SPN689,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  690
      offsetof(PG_TYPE,u8_DisengDifferentLockReqCentralFrnt),
      &mt_Unscaled_SPN690,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  691
      offsetof(PG_TYPE,u8_DisengDifferentLockReqCentralRear),
      &mt_Unscaled_SPN691,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  5762
      offsetof(PG_TYPE,u8_TransmissionLoadReductionInhibitRequest),
      &mt_Unscaled_SPN5762,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  1852
      offsetof(PG_TYPE,u8_TransmissionMode1),
      &mt_Unscaled_SPN1852,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  1853
      offsetof(PG_TYPE,u8_TransmissionMode2),
      &mt_Unscaled_SPN1853,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  1854
      offsetof(PG_TYPE,u8_TransmissionMode3),
      &mt_Unscaled_SPN1854,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  1855
      offsetof(PG_TYPE,u8_TransmissionMode4),
      &mt_Unscaled_SPN1855,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  4255
      offsetof(PG_TYPE,u8_TransmissionRequestedLaunchGear),
      &mt_Unscaled_SPN4255,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  2985
      offsetof(PG_TYPE,u8_TransmissionShiftSelectorDisplayModeSwitch),
      &mt_Unscaled_SPN2985,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  4246
      offsetof(PG_TYPE,u8_TransmissionMode5),
      &mt_Unscaled_SPN4246,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  4247
      offsetof(PG_TYPE,u8_TransmissionMode6),
      &mt_Unscaled_SPN4247,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  4248
      offsetof(PG_TYPE,u8_TransmissionMode7),
      &mt_Unscaled_SPN4248,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   {   // SPN  4249
      offsetof(PG_TYPE,u8_TransmissionMode8),
      &mt_Unscaled_SPN4249,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_bitfield, (PR_J1939_SPN_HandleTx)&J1939_spn_set_bitfield
   },
   // ----------------------------------
   {  // scaled SPNs follow
      J1939_SPN_SCALED, NULL, NULL, NULL
   },
   {   // SPN  684
      offsetof(PG_TYPE,u16_RequestedPercentClutchSlip_permill),
      &mt_Scaled_SPN684,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_u16_u8_scaled_mult, (PR_J1939_SPN_HandleTx)&J1939_spn_set_u16_u8_scaled_mult
   },
   {   // SPN  525
      offsetof(PG_TYPE,s8_RequestedGear_gv),
      &mt_Scaled_SPN525,
      (PR_J1939_SPN_HandleRx)&J1939_spn_get_s8_u8_scaled_offset, (PR_J1939_SPN_HandleTx)&J1939_spn_set_s8_u8_scaled_offset
   },
   {  // End mark
      0, NULL, NULL, NULL
   }
};


// -- Global Variables ---------------------------------------------------------
const T_J1939_PGN_parameters gt_J1939_PGN_CFG_TC1 =
{
   J1939_PGN_TC1,    // PGN
   3,                // default priority
   8,                // PG data buffer size
   sizeof(PG_TYPE),  // structure size
   50,             // Rx default timeout [ms]
   50,             // Tx default cycle time [ms]
   mat_SPNS          // array with all PG SPNS
};
