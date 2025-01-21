//-----------------------------------------------------------------------------
/*!
   \file
   \brief       Application specific J1939 PGN TSC1

   Defines the PGN Torque Speed Control 1

   \implementation
   project     J1939 Protocolstack
   copyright   STW (c) 2010
   license     use only under terms of contract / confidential

   created     03.09.2013  STW/J1939-PGen V1.00r0
   \endimplementation
*/
//------------------------------------------------------------------------------


#ifndef _J1939_PGN_TSC1_H_                // Avoid multiple/recursive inclusion
#define _J1939_PGN_TSC1_H_


// -- Includes ----------------------------------------------------------------
#include "stwtypes.h"
#include "j1939_pgn_types.h"

#if defined(__cplusplus) 
extern "C" {     // Make sure we have C-declarations in C++ programs
#endif


// -- Defines -----------------------------------------------------------------
#define J1939_PGN_TSC1       (uint32)0U          // Torque Speed Control 1   TSC1

// -- Types -------------------------------------------------------------------
typedef struct
{
   T_J1939_PG_ctrl t_Ctrl; // control structure
   //unscaled SPNs
   uint8   u8_OverrideControlMode;   // SPN 695: 2 Bits
   uint8   u8_RequestedSpeedCntrlConditions;   // SPN 696: 2 Bits
   uint8   u8_OverrideCntrlModePriority;   // SPN 897: 2 Bits
   uint8   u8_RequestedTorqueLimit;   // SPN 518: 1 Byte,  1% / bit
   uint8   u8_TSC1TransmissionRate;   // SPN 3349: 8 states/3 bit
   uint8   u8_TSC1ControlPurpose;   // SPN 3350: 32 states/5 bit
   uint8   u8_EngineRequestedTorqueHighResolution;   // SPN 4191: 0.125percent/bit
   uint8   u8_MessageCounter;   // SPN 4206: 1 count/bit
   uint8   u8_MessageChecksum;   // SPN 4207: 1 count/bit
   uint16 u16_RequestedSpeedLimit;   // SPN 898: 2 Bytes, 0.125rpm / bit
   //Scaled Versions
   sint8 s8_RequestedTorqueLimit_perc;   // SPN 518: [-125 .. +125]%
   uint16 u16_RequestedSpeedLimit_rpm;   // SPN 898: [0 .. 8031]rpm
}
T_J1939_PGN_TSC1;   //struct for the PG Torque Speed Control 1


// -- Global Variables --------------------------------------------------------
extern const T_J1939_PGN_parameters gt_J1939_PGN_CFG_TSC1;   //this variable is used to describe the data which doesn't change in the run-time environment


// -- Function Prototypes -----------------------------------------------------


// -- Implementation ----------------------------------------------------------


#if defined(__cplusplus)
}                // Make sure we have C-declarations in C++ programs
#endif

#endif                // Avoid multiple/recursive inclusion

/*************************** End of file ****************************/
