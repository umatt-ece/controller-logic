//-----------------------------------------------------------------------------
/*!
   \file
   \brief       Application specific J1939 PGN VEP1

   Defines the PGN Vehicle Electrical Power 1

   \implementation
   project     J1939 Protocolstack
   copyright   STW (c) 2010
   license     use only under terms of contract / confidential

   created     03.09.2013  STW/J1939-PGen V1.00r0
   \endimplementation
*/
//------------------------------------------------------------------------------


#ifndef _J1939_PGN_VEP1_H_                // Avoid multiple/recursive inclusion
#define _J1939_PGN_VEP1_H_


// -- Includes ----------------------------------------------------------------
#include "stwtypes.h"
#include "j1939_pgn_types.h"

#if defined(__cplusplus) 
extern "C" {     // Make sure we have C-declarations in C++ programs
#endif


// -- Defines -----------------------------------------------------------------
#define J1939_PGN_VEP1       (uint32)65271U          // Vehicle Electrical Power 1   VEP1

// -- Types -------------------------------------------------------------------
typedef struct
{
   T_J1939_PG_ctrl t_Ctrl; // control structure
   //unscaled SPNs
   uint8   u8_NetBatteryCurrent;   // SPN 114: 1 Byte, 1A / bit
   uint8   u8_AlternatorCurrent;   // SPN 115: 1 Byte, 1A / bit
   uint16 u16_AlternatorPotentialVoltage;   // SPN 167: 2 Byte, 0.05V / bit
   uint16 u16_ElectricalPotentialVoltage;   // SPN 168: 2 Byte, 0.05V / bit
   uint16 u16_BatteryPotentialVoltSwitched;   // SPN 158: 2 Byte, 0.05V / bit
   //Scaled Versions
   sint8 s8_NetBatteryCurrent_A;   // SPN 114: [-125 .. +125]A
   uint16 u16_AlternatorCurrent_A;   // SPN 115: [0 .. 250]A
   uint16 u16_AlternatorPotentialVoltage_01V;   // SPN 167: [0 .. 32127]100mV
   uint16 u16_ElectricalPotentialVoltage_01V;   // SPN 168: [0 .. 32127]100mV
   uint16 u16_BatteryPotentialVoltSwitched_01V;   // SPN 158: [0 .. 32127]100mV
}
T_J1939_PGN_VEP1;   //struct for the PG Vehicle Electrical Power 1


// -- Global Variables --------------------------------------------------------
extern const T_J1939_PGN_parameters gt_J1939_PGN_CFG_VEP1;   //this variable is used to describe the data which doesn't change in the run-time environment


// -- Function Prototypes -----------------------------------------------------


// -- Implementation ----------------------------------------------------------


#if defined(__cplusplus)
}                // Make sure we have C-declarations in C++ programs
#endif

#endif                // Avoid multiple/recursive inclusion

/*************************** End of file ****************************/
