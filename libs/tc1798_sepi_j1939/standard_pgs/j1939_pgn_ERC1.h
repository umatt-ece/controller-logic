//-----------------------------------------------------------------------------
/*!
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


#ifndef _J1939_PGN_ERC1_H_                // Avoid multiple/recursive inclusion
#define _J1939_PGN_ERC1_H_


// -- Includes ----------------------------------------------------------------
#include "stwtypes.h"
#include "j1939_pgn_types.h"

#if defined(__cplusplus) 
extern "C" {     // Make sure we have C-declarations in C++ programs
#endif


// -- Defines -----------------------------------------------------------------
#define J1939_PGN_ERC1       (uint32)61440U          // Electronic Retarder Controller 1   ERC1

// -- Types -------------------------------------------------------------------
typedef struct
{
   T_J1939_PG_ctrl t_Ctrl; // control structure
   //unscaled SPNs
   uint8   u8_RetarderTorqueMode;   // SPN 900:  4 Bits
   uint8   u8_RetarderEnableBrakeAssistSwitch;   // SPN 571:  2 Bits
   uint8   u8_RetarderEnableShiftAssistSwitch;   // SPN 572:  2 Bits
   uint8   u8_ActualRetarderPercentTorque;   // SPN 520:  1 Byte, 1% / bit
   uint8   u8_IntendedRetarderPercentTorque;   // SPN 1085: 1 Byte, 1% / bit
   uint8   u8_EngineCoolantLoadIncrease;   // SPN 1082: 2 Bits
   uint8   u8_RetarderRequestingBrakeLight;   // SPN 1667: 2 Bits
   uint8   u8_RetarderRoadSpeedLimitSwitch;   // SPN 4233: 4 states/2 bit
   uint8   u8_RetarderRoadSpeedExceededStatus;   // SPN 4234: 4 states/2 bit
   uint8   u8_SrcAddrOfCntrlDeviceForRetCntrl;   // SPN 1480: 1 Byte
   uint8   u8_DriversDemandRetarderPercTorq;   // SPN 1715: 1 Byte, 1% / bit
   uint8   u8_RetarderSelectionNonEngine;   // SPN 1716: 1 Byte, 0.4% / bit
   uint8   u8_ActMaxAvlblRetarderPercTorque;   // SPN 1717: 1 Byte, 1% / bit
   //Scaled Versions
   sint8 s8_ActualRetarderPercentTorque_perc;   // SPN 520:  [-125 .. +125]%
   sint8 s8_IntendedRetarderPercentTorque_perc;   // SPN 1085: [-125 .. +125]%
   sint8 s8_DriversDemandRetarderPercTorq_perc;   // SPN 1715: [-125 .. +125]%
   uint16 u16_RetarderSelectionNonEngine_permill;   // SPN 1716: [0 .. 1000]%%
   sint8 s8_ActMaxAvlblRetarderPercTorque_perc;   // SPN 1717: [-125 .. +125]%
}
T_J1939_PGN_ERC1;   //struct for the PG Electronic Retarder Controller 1


// -- Global Variables --------------------------------------------------------
extern const T_J1939_PGN_parameters gt_J1939_PGN_CFG_ERC1;   //this variable is used to describe the data which doesn't change in the run-time environment


// -- Function Prototypes -----------------------------------------------------


// -- Implementation ----------------------------------------------------------


#if defined(__cplusplus)
}                // Make sure we have C-declarations in C++ programs
#endif

#endif                // Avoid multiple/recursive inclusion

/*************************** End of file ****************************/
