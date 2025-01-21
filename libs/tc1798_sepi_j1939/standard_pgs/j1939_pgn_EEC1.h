//-----------------------------------------------------------------------------
/*!
   \file
   \brief       Application specific J1939 PGN EEC1

   Defines the PGN Electronic Engine Controller 1

   \implementation
   project     J1939 Protocolstack
   copyright   STW (c) 2010
   license     use only under terms of contract / confidential

   created     03.09.2013  STW/J1939-PGen V1.00r0
   \endimplementation
*/
//------------------------------------------------------------------------------


#ifndef _J1939_PGN_EEC1_H_                // Avoid multiple/recursive inclusion
#define _J1939_PGN_EEC1_H_


// -- Includes ----------------------------------------------------------------
#include "stwtypes.h"
#include "j1939_pgn_types.h"

#if defined(__cplusplus) 
extern "C" {     // Make sure we have C-declarations in C++ programs
#endif


// -- Defines -----------------------------------------------------------------
#define J1939_PGN_EEC1       (uint32)61444U          // Electronic Engine Controller 1   EEC1

// -- Types -------------------------------------------------------------------
typedef struct
{
   T_J1939_PG_ctrl t_Ctrl; // control structure
   //unscaled SPNs
   uint8   u8_EngineTorqueMode;   // SPN 899:  4 Bits
   uint8   u8_ActualEnginePercentTorqueHighResolution;   // SPN 4154: 0.125percent/bit
   uint8   u8_DrvrDemandEngPercTorque;   // SPN 512:  1 Byte,  1% / bit
   uint8   u8_ActualEngPercentTorque;   // SPN 513:  1 Byte,  1% / bit
   uint8   u8_SrcAddrCtrlDevEngCtrl;   // SPN 1483: 1 Byte
   uint8   u8_EngineStarterMode;   // SPN 1675: 4 Bits
   uint8   u8_EngineDemandPercentTorque;   // SPN 2432: 1 percent/bit, with offset: -125 percent
   uint16 u16_EngineSpeed;   // SPN 190:  2 Bytes, 0.125rpm / bit
   //Scaled Versions
   sint8 s8_DrvrDemandEngPercTorque_perc;   // SPN 512:  [-125 .. +125]%
   sint8 s8_ActualEngPercentTorque_perc;   // SPN 513:  [-125 .. +125]%
   sint8   s8_EngineDemandPercentTorque_percent;   // SPN 2432:  [-125 .. 125]_percent
   uint16 u16_EngineSpeed_rpm;   // SPN 190:  [0 .. 8031]rpm
}
T_J1939_PGN_EEC1;   //struct for the PG Electronic Engine Controller 1


// -- Global Variables --------------------------------------------------------
extern const T_J1939_PGN_parameters gt_J1939_PGN_CFG_EEC1;   //this variable is used to describe the data which doesn't change in the run-time environment


// -- Function Prototypes -----------------------------------------------------


// -- Implementation ----------------------------------------------------------


#if defined(__cplusplus)
}                // Make sure we have C-declarations in C++ programs
#endif

#endif                // Avoid multiple/recursive inclusion

/*************************** End of file ****************************/
