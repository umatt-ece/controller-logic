//-----------------------------------------------------------------------------
/*!
   \file
   \brief       Application specific J1939 PGN LFC

   Defines the PGN Fuel Consumption Liquid

   \implementation
   project     J1939 Protocolstack
   copyright   STW (c) 2010
   license     use only under terms of contract / confidential

   created     03.09.2013  STW/J1939-PGen V1.00r0
   \endimplementation
*/
//------------------------------------------------------------------------------


#ifndef _J1939_PGN_LFC_H_                // Avoid multiple/recursive inclusion
#define _J1939_PGN_LFC_H_


// -- Includes ----------------------------------------------------------------
#include "stwtypes.h"
#include "j1939_pgn_types.h"

#if defined(__cplusplus) 
extern "C" {     // Make sure we have C-declarations in C++ programs
#endif


// -- Defines -----------------------------------------------------------------
#define J1939_PGN_LFC       (uint32)65257U          // Fuel Consumption Liquid   LFC

// -- Types -------------------------------------------------------------------
typedef struct
{
   T_J1939_PG_ctrl t_Ctrl; // control structure
   //unscaled SPNs
   uint32 u32_EngineTripFuel;   // SPN 182: 4 Byte, 0.5L / bit
   uint32 u32_EngineTotalFuelUsed;   // SPN 250: 4 Byte, 0.5L / bit
   //Scaled Versions
   uint32 u32_EngineTripFuel_Liter;   // SPN 182: [0..2105540607]Liter
   uint32 u32_EngineTotalFuelUsed_Liter;   // SPN 250: [0..2105540607]Liter
}
T_J1939_PGN_LFC;   //struct for the PG Fuel Consumption Liquid


// -- Global Variables --------------------------------------------------------
extern const T_J1939_PGN_parameters gt_J1939_PGN_CFG_LFC;   //this variable is used to describe the data which doesn't change in the run-time environment


// -- Function Prototypes -----------------------------------------------------


// -- Implementation ----------------------------------------------------------


#if defined(__cplusplus)
}                // Make sure we have C-declarations in C++ programs
#endif

#endif                // Avoid multiple/recursive inclusion

/*************************** End of file ****************************/
