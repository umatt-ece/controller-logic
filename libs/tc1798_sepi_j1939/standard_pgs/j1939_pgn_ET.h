//-----------------------------------------------------------------------------
/*!
   \file
   \brief       Application specific J1939 PGN ET

   Defines the PGN Exhaust Temperature

   \implementation
   project     J1939 Protocolstack
   copyright   STW (c) 2010
   license     use only under terms of contract / confidential

   created     03.09.2013  STW/J1939-PGen V1.00r0
   \endimplementation
*/
//------------------------------------------------------------------------------


#ifndef _J1939_PGN_ET_H_                // Avoid multiple/recursive inclusion
#define _J1939_PGN_ET_H_


// -- Includes ----------------------------------------------------------------
#include "stwtypes.h"
#include "j1939_pgn_types.h"

#if defined(__cplusplus) 
extern "C" {     // Make sure we have C-declarations in C++ programs
#endif


// -- Defines -----------------------------------------------------------------
#define J1939_PGN_ET       (uint32)65031U          // Exhaust Temperature   ET

// -- Types -------------------------------------------------------------------
typedef struct
{
   T_J1939_PG_ctrl t_Ctrl; // control structure
   //unscaled SPNs
   uint16 u16_EngExhaustManifoldBank2Temp1;   // SPN 2433: 2 Byte, (1/32)°C / bit
   uint16 u16_EngExhaustManifoldBank1Temp1;   // SPN 2434: 2 Byte, (1/32)°C / bit
   uint16 u16_EngExhaustManifoldBank2Temp2;   // SPN 5969: 2 Byte, (1/32)°C / bit
   uint16 u16_EngExhaustManifoldBank1Temp2;   // SPN 5970: 2 Byte, (1/32)°C / bit
   //Scaled Versions
   sint16 s16_EngExhaustManifoldBank2Temp1_01degC;   // SPN 2433: [-2730 .. +17350]0.1°C
   sint16 s16_EngExhaustManifoldBank1Temp1_01degC;   // SPN 2434: [-2730 .. +17350]0.1°C
   sint16 s16_EngExhaustManifoldBank2Temp2_01degC;   // SPN 5969: [-2730 .. +17350]0.1°C
   sint16 s16_EngExhaustManifoldBank1Temp2_01degC;   // SPN 5970: [-2730 .. +17350]0.1°C
}
T_J1939_PGN_ET;   //struct for the PG Exhaust Temperature


// -- Global Variables --------------------------------------------------------
extern const T_J1939_PGN_parameters gt_J1939_PGN_CFG_ET;   //this variable is used to describe the data which doesn't change in the run-time environment


// -- Function Prototypes -----------------------------------------------------


// -- Implementation ----------------------------------------------------------


#if defined(__cplusplus)
}                // Make sure we have C-declarations in C++ programs
#endif

#endif                // Avoid multiple/recursive inclusion

/*************************** End of file ****************************/
