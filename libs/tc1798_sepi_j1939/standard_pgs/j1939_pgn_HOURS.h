//-----------------------------------------------------------------------------
/*!
   \file
   \brief       Application specific J1939 PGN HOURS

   Defines the PGN Engine Hours Revolutions

   \implementation
   project     J1939 Protocolstack
   copyright   STW (c) 2010
   license     use only under terms of contract / confidential

   created     03.09.2013  STW/J1939-PGen V1.00r0
   \endimplementation
*/
//------------------------------------------------------------------------------


#ifndef _J1939_PGN_HOURS_H_                // Avoid multiple/recursive inclusion
#define _J1939_PGN_HOURS_H_


// -- Includes ----------------------------------------------------------------
#include "stwtypes.h"
#include "j1939_pgn_types.h"

#if defined(__cplusplus) 
extern "C" {     // Make sure we have C-declarations in C++ programs
#endif


// -- Defines -----------------------------------------------------------------
#define J1939_PGN_HOURS       (uint32)65253U          // Engine Hours Revolutions   HOURS

// -- Types -------------------------------------------------------------------
typedef struct
{
   T_J1939_PG_ctrl t_Ctrl; // control structure
   //unscaled SPNs
   uint32 u32_TotalEngineHours;   // SPN 247: 4 Byte, 0.05h=3minutes / bit
   uint32 u32_TotalEngineRevolutions;   // SPN 249: 4 Byte, 1000r / bit
}
T_J1939_PGN_HOURS;   //struct for the PG Engine Hours Revolutions


// -- Global Variables --------------------------------------------------------
extern const T_J1939_PGN_parameters gt_J1939_PGN_CFG_HOURS;   //this variable is used to describe the data which doesn't change in the run-time environment


// -- Function Prototypes -----------------------------------------------------


// -- Implementation ----------------------------------------------------------


#if defined(__cplusplus)
}                // Make sure we have C-declarations in C++ programs
#endif

#endif                // Avoid multiple/recursive inclusion

/*************************** End of file ****************************/
