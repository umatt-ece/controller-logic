//-----------------------------------------------------------------------------
/*!
   \file
   \brief       Application specific J1939 PGN XBR

   Defines the PGN External Brake Request

   \implementation
   project     J1939 Protocolstack
   copyright   STW (c) 2010
   license     use only under terms of contract / confidential

   created     03.09.2013  STW/J1939-PGen V1.00r0
   \endimplementation
*/
//------------------------------------------------------------------------------


#ifndef _J1939_PGN_XBR_H_                // Avoid multiple/recursive inclusion
#define _J1939_PGN_XBR_H_


// -- Includes ----------------------------------------------------------------
#include "stwtypes.h"
#include "j1939_pgn_types.h"

#if defined(__cplusplus) 
extern "C" {     // Make sure we have C-declarations in C++ programs
#endif


// -- Defines -----------------------------------------------------------------
#define J1939_PGN_XBR       (uint32)1024U          // External Brake Request   XBR

// -- Types -------------------------------------------------------------------
typedef struct
{
   T_J1939_PG_ctrl t_Ctrl; // control structure
   //unscaled SPNs
   uint8   u8_XBREBIMode;   // SPN 2914: 2 Bits
   uint8   u8_XBRPriority;   // SPN 2915: 2 Bits
   uint8   u8_XBRControlMode;   // SPN 2916: 2 Bits
   uint8   u8_XBRUrgency;   // SPN 4099: 0.4 percent/bit
   uint8   u8_XBRMessageCounter;   // SPN 3189: 4 Bits
   uint8   u8_XBRMessageChecksum;   // SPN 3188: 4 Bits
   uint16 u16_ExternalAccelerationDemand;   // SPN 2920: 2 Bytes, 1/2048(m/s^2) / bit
   //Scaled Versions
   uint16   u16_XBRUrgency_permil;   // SPN 4099:  [0 .. 1000]_permil
   sint16 s16_ExternalAccelerationDemand_mm_s2;   // SPN 2920: [-15687 .. +15687]mm/s^2
}
T_J1939_PGN_XBR;   //struct for the PG External Brake Request


// -- Global Variables --------------------------------------------------------
extern const T_J1939_PGN_parameters gt_J1939_PGN_CFG_XBR;   //this variable is used to describe the data which doesn't change in the run-time environment


// -- Function Prototypes -----------------------------------------------------


// -- Implementation ----------------------------------------------------------


#if defined(__cplusplus)
}                // Make sure we have C-declarations in C++ programs
#endif

#endif                // Avoid multiple/recursive inclusion

/*************************** End of file ****************************/
