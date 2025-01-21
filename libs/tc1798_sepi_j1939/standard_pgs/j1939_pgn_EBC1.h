//-----------------------------------------------------------------------------
/*!
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


#ifndef _J1939_PGN_EBC1_H_                // Avoid multiple/recursive inclusion
#define _J1939_PGN_EBC1_H_


// -- Includes ----------------------------------------------------------------
#include "stwtypes.h"
#include "j1939_pgn_types.h"

#if defined(__cplusplus) 
extern "C" {     // Make sure we have C-declarations in C++ programs
#endif


// -- Defines -----------------------------------------------------------------
#define J1939_PGN_EBC1       (uint32)61441U          // Electronic Brake Controller 1   EBC1

// -- Types -------------------------------------------------------------------
typedef struct
{
   T_J1939_PG_ctrl t_Ctrl; // control structure
   //unscaled SPNs
   uint8   u8_ASR_EngineControlActive;   // SPN 561:  2 Bits
   uint8   u8_ASR_BrakeControlActive;   // SPN 562:  2 Bits
   uint8   u8_AntiLockBrakingActive;   // SPN 563:  2 Bits
   uint8   u8_EBS_BrakeSwitch;   // SPN 1121: 2 Bits
   uint8   u8_BrakePedalPosition;   // SPN 521:  1 Byte, 0.4% / bit
   uint8   u8_ABS_OffRoadSwitch;   // SPN 575:  2 Bits
   uint8   u8_ASR_OffRoadSwitch;   // SPN 576:  2 Bits
   uint8   u8_ASR_HillHolderSwitch;   // SPN 577:  2 Bits
   uint8   u8_TractionControlOverrideSwitch;   // SPN 1238: 2 Bits
   uint8   u8_AcceleratorInterlockSwitch;   // SPN 972:  2 Bits
   uint8   u8_EngineDerateSwitch;   // SPN 971:  2 Bits
   uint8   u8_EngineAuxiliaryShutdownSwitch;   // SPN 970:  2 Bits
   uint8   u8_RemoteAcceleratorEnableSwitch;   // SPN 969:  2 Bits
   uint8   u8_EngineRetarderSelection;   // SPN 973:  1 Byte, 0.4% / bit
   uint8   u8_ABS_FullyOperational;   // SPN 1243: 2 Bits
   uint8   u8_EBS_RedWarningSignal;   // SPN 1439: 2 Bits
   uint8   u8_ABS_EBS_AmberWarningSignal;   // SPN 1438: 2 Bits
   uint8   u8_ATC_ASR_InformationSignal;   // SPN 1793: 2 Bits
   uint8   u8_SrcAddrOfCntrlingBrakeControlDevice;   // SPN 1481: 1 Byte, 1 source address / bit
   uint8   u8_HaltBrakeSwitch;   // SPN 2911: 2 Bits
   uint8   u8_TrailerABSStatus;   // SPN 1836: 2 Bits
   uint8   u8_TractorMountedTrailerABSWarnSignal;   // SPN 1792: 2 Bits
   //Scaled Versions
   uint16 u16_BrakePedalPosition_permil;   // SPN 521:  [0 .. 1000]%%
   uint16 u16_EngineRetarderSelection_permil;   // SPN 973:  [0 .. 1000]%%
}
T_J1939_PGN_EBC1;   //struct for the PG Electronic Brake Controller 1


// -- Global Variables --------------------------------------------------------
extern const T_J1939_PGN_parameters gt_J1939_PGN_CFG_EBC1;   //this variable is used to describe the data which doesn't change in the run-time environment


// -- Function Prototypes -----------------------------------------------------


// -- Implementation ----------------------------------------------------------


#if defined(__cplusplus)
}                // Make sure we have C-declarations in C++ programs
#endif

#endif                // Avoid multiple/recursive inclusion

/*************************** End of file ****************************/
