//-----------------------------------------------------------------------------
/*!
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


#ifndef _J1939_PGN_TC1_H_                // Avoid multiple/recursive inclusion
#define _J1939_PGN_TC1_H_


// -- Includes ----------------------------------------------------------------
#include "stwtypes.h"
#include "j1939_pgn_types.h"

#if defined(__cplusplus) 
extern "C" {     // Make sure we have C-declarations in C++ programs
#endif


// -- Defines -----------------------------------------------------------------
#define J1939_PGN_TC1       (uint32)256U          // Transmission Control 1   TC1

// -- Types -------------------------------------------------------------------
typedef struct
{
   T_J1939_PG_ctrl t_Ctrl; // control structure
   //unscaled SPNs
   uint8   u8_GearShiftInhibitRequest;   // SPN 681:  2 Bits
   uint8   u8_TorqueConvertLockupDisableRequest;   // SPN 682:  2 Bits
   uint8   u8_DisengageDrivelineRequest;   // SPN 683:  2 Bits
   uint8   u8_TransmissionReverseGearShiftInhibitRequest;   // SPN 4242: 4 states/2 bit
   uint8   u8_RequestedPercentClutchSlip;   // SPN 684:  1 Byte, 0.4% / bit
   uint8   u8_RequestedGear;   // SPN 525:  1 Byte, 1GearValue / bit
   uint8   u8_DisengDifferentLockReqFrntAx1;   // SPN 685:  2 Bits
   uint8   u8_DisengDifferentLockReqFrntAx2;   // SPN 686:  2 Bits
   uint8   u8_DisengDifferentLockReqRearAx1;   // SPN 687:  2 Bits
   uint8   u8_DisengDifferentLockReqRearAx2;   // SPN 688:  2 Bits
   uint8   u8_DisengDifferentLockReqCentral;   // SPN 689:  2 Bits
   uint8   u8_DisengDifferentLockReqCentralFrnt;   // SPN 690:  2 Bits
   uint8   u8_DisengDifferentLockReqCentralRear;   // SPN 691:  2 Bits
   uint8   u8_TransmissionLoadReductionInhibitRequest;   // SPN 5762: 4 states/2 bit
   uint8   u8_TransmissionMode1;   // SPN 1852: 4 states/2 bit
   uint8   u8_TransmissionMode2;   // SPN 1853: 4 states/2 bit
   uint8   u8_TransmissionMode3;   // SPN 1854: 4 states/2 bit
   uint8   u8_TransmissionMode4;   // SPN 1855: 4 states/2 bit
   uint8   u8_TransmissionRequestedLaunchGear;   // SPN 4255: 16 states/4 bit
   uint8   u8_TransmissionShiftSelectorDisplayModeSwitch;   // SPN 2985: 4 states/2 bit
   uint8   u8_TransmissionMode5;   // SPN 4246: 4 states/2 bit
   uint8   u8_TransmissionMode6;   // SPN 4247: 4 states/2 bit
   uint8   u8_TransmissionMode7;   // SPN 4248: 4 states/2 bit
   uint8   u8_TransmissionMode8;   // SPN 4249: 4 states/2 bit
   //Scaled Versions
   uint16 u16_RequestedPercentClutchSlip_permill;   // SPN 684:  [0 .. 1000]%%
   sint8 s8_RequestedGear_gv;   // SPN 525:  [-125 .. +125]GearValue
}
T_J1939_PGN_TC1;   //struct for the PG Transmission Control 1


// -- Global Variables --------------------------------------------------------
extern const T_J1939_PGN_parameters gt_J1939_PGN_CFG_TC1;   //this variable is used to describe the data which doesn't change in the run-time environment


// -- Function Prototypes -----------------------------------------------------


// -- Implementation ----------------------------------------------------------


#if defined(__cplusplus)
}                // Make sure we have C-declarations in C++ programs
#endif

#endif                // Avoid multiple/recursive inclusion

/*************************** End of file ****************************/
