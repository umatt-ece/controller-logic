//-----------------------------------------------------------------------------
/*!
   \file
   \brief       Application specific J1939 PGN EEC2

   Defines the PGN Electronic Engine Controller 2

   \implementation
   project     J1939 Protocolstack
   copyright   STW (c) 2010
   license     use only under terms of contract / confidential

   created     03.09.2013  STW/J1939-PGen V1.00r0
   \endimplementation
*/
//------------------------------------------------------------------------------


#ifndef _J1939_PGN_EEC2_H_                // Avoid multiple/recursive inclusion
#define _J1939_PGN_EEC2_H_


// -- Includes ----------------------------------------------------------------
#include "stwtypes.h"
#include "j1939_pgn_types.h"

#if defined(__cplusplus) 
extern "C" {     // Make sure we have C-declarations in C++ programs
#endif


// -- Defines -----------------------------------------------------------------
#define J1939_PGN_EEC2       (uint32)61443U          // Electronic Engine Controller 2   EEC2

// -- Types -------------------------------------------------------------------
typedef struct
{
   T_J1939_PG_ctrl t_Ctrl; // control structure
   //unscaled SPNs
   uint8   u8_AcceleratorPedal1LowIdleSwitch;   // SPN 558:  2 Bits
   uint8   u8_AcceleratorPedalKickdownSwitch;   // SPN 559:  2 Bits
   uint8   u8_RoadSpeedLimitStatus;   // SPN 1437: 2 Bits
   uint8   u8_AcceleratorPedal2LowIdleSwitch;   // SPN 2970: 2 Bits
   uint8   u8_AcceleratorPedalPosition1;   // SPN 91:   1 Byte, 0.4% / bit
   uint8   u8_EnginePercLoadAtCurrentSpeed;   // SPN 92:   1 Byte
   uint8   u8_RemoteAcceleratorPedalPosition;   // SPN 974:  1 Byte, 0.4% / bit
   uint8   u8_AcceleratorPedalPosition2;   // SPN 29:   1 Byte
   uint8   u8_VehicleAccelRateLimitStatus;   // SPN 2979: 2 Bits
   uint8   u8_MomentaryEngineMaximumPowerEnableFeedback;   // SPN 5021: 4 states/2 bit
   uint8   u8_DPFThermalManagementActive;   // SPN 5399: 4 states/2 bit
   uint8   u8_SCRThermalManagementActive;   // SPN 5400: 4 states/2 bit
   uint8   u8_ActMaxAvailableEnginePercTorque;   // SPN 3357: 1 Byte, 0.4% / bit
   uint8   u8_EstimatedPumpingPercentTorque;   // SPN 5398: 1 percent/bit, with offset: -125 percent
   //Scaled Versions
   uint16 u16_AcceleratorPedalPosition1_permil;   // SPN 91:   [0 .. 1000]%%
   uint16 u16_RemoteAccelPedalPosition_permil;   // SPN 974:  [0 .. 1000]%%
   uint16   u16_AcceleratorPedalPosition2_permil;   // SPN 29:  [0 .. 1000]_permil
   uint16 u16_ActMaxAvailEnginePercTorque_permil;   // SPN 3357: [0 .. 1000]%%
   sint8   s8_EstimatedPumpingPercentTorque_percent;   // SPN 5398:  [-125 .. 125]_percent
}
T_J1939_PGN_EEC2;   //struct for the PG Electronic Engine Controller 2


// -- Global Variables --------------------------------------------------------
extern const T_J1939_PGN_parameters gt_J1939_PGN_CFG_EEC2;   //this variable is used to describe the data which doesn't change in the run-time environment


// -- Function Prototypes -----------------------------------------------------


// -- Implementation ----------------------------------------------------------


#if defined(__cplusplus)
}                // Make sure we have C-declarations in C++ programs
#endif

#endif                // Avoid multiple/recursive inclusion

/*************************** End of file ****************************/
