//-----------------------------------------------------------------------------
/*!
   \file
   \brief       Application specific J1939 PGN WFI

   Defines the PGN Operator Indicators

   \implementation
   project     J1939 Protocolstack
   copyright   STW (c) 2010
   license     use only under terms of contract / confidential

   created     03.09.2013  STW/J1939-PGen V1.00r0
   \endimplementation
*/
//------------------------------------------------------------------------------


#ifndef _J1939_PGN_WFI_H_                // Avoid multiple/recursive inclusion
#define _J1939_PGN_WFI_H_


// -- Includes ----------------------------------------------------------------
#include "stwtypes.h"
#include "j1939_pgn_types.h"

#if defined(__cplusplus) 
extern "C" {     // Make sure we have C-declarations in C++ programs
#endif


// -- Defines -----------------------------------------------------------------
#define J1939_PGN_WFI       (uint32)65279U          // Operator Indicators   WFI

// -- Types -------------------------------------------------------------------
typedef struct
{
   T_J1939_PG_ctrl t_Ctrl; // control structure
   //unscaled SPNs
   uint8   u8_WaterInFuelIndicator;   // SPN 97: 2 Bits
   uint8   u8_OperatorShiftPrompt;   // SPN 5675: 4 states/2 bit
   uint8   u8_WaterInFuelIndicator2;   // SPN 6301: 4 states/2 bit
   uint8   u8_DriverWarningSystemIndicatorStatus;   // SPN 5825: 8 states/3 bit
   uint8   u8_EmissionControlSystemOperatorInducementSeverity;   // SPN 5826: 8 states/3 bit
}
T_J1939_PGN_WFI;   //struct for the PG Operator Indicators


// -- Global Variables --------------------------------------------------------
extern const T_J1939_PGN_parameters gt_J1939_PGN_CFG_WFI;   //this variable is used to describe the data which doesn't change in the run-time environment


// -- Function Prototypes -----------------------------------------------------


// -- Implementation ----------------------------------------------------------


#if defined(__cplusplus)
}                // Make sure we have C-declarations in C++ programs
#endif

#endif                // Avoid multiple/recursive inclusion

/*************************** End of file ****************************/
