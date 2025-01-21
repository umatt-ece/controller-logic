//-----------------------------------------------------------------------------
/*!
   \file
   \brief       Application specific J1939 PGN EH

   Defines the PGN ECUHistory

   \implementation
   project     J1939 Protocolstack
   copyright   STW (c) 2010
   license     use only under terms of contract / confidential

   created     03.09.2013  STW/J1939-PGen V1.00r0
   \endimplementation
*/
//------------------------------------------------------------------------------


#ifndef _J1939_PGN_EH_H_                // Avoid multiple/recursive inclusion
#define _J1939_PGN_EH_H_


// -- Includes ----------------------------------------------------------------
#include "stwtypes.h"
#include "j1939_pgn_types.h"

#if defined(__cplusplus) 
extern "C" {     // Make sure we have C-declarations in C++ programs
#endif


// -- Defines -----------------------------------------------------------------
#define J1939_PGN_EH       (uint32)65201U          // ECUHistory   EH

// -- Types -------------------------------------------------------------------
typedef struct
{
   T_J1939_PG_ctrl t_Ctrl; // control structure
   //unscaled SPNs
   uint32 u32_TotalEcuDistance;   // SPN 1032: 4 Byte, 125m / bit
   uint32 u32_TotalEcuRunTime;   // SPN 1033: 4 Byte, 0.05h=3minutes / bit
}
T_J1939_PGN_EH;   //struct for the PG ECUHistory


// -- Global Variables --------------------------------------------------------
extern const T_J1939_PGN_parameters gt_J1939_PGN_CFG_EH;   //this variable is used to describe the data which doesn't change in the run-time environment


// -- Function Prototypes -----------------------------------------------------


// -- Implementation ----------------------------------------------------------


#if defined(__cplusplus)
}                // Make sure we have C-declarations in C++ programs
#endif

#endif                // Avoid multiple/recursive inclusion

/*************************** End of file ****************************/
