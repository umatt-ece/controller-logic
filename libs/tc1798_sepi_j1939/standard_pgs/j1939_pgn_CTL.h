//-----------------------------------------------------------------------------
/*!
   \file
   \brief       Application specific J1939 PGN CTL

   Defines the PGN Continuous Torque Speed Limit Request

   \implementation
   project     J1939 Protocolstack
   copyright   STW (c) 2010
   license     use only under terms of contract / confidential

   created     03.09.2013  STW/J1939-PGen V1.00r0
   \endimplementation
*/
//------------------------------------------------------------------------------


#ifndef _J1939_PGN_CTL_H_                // Avoid multiple/recursive inclusion
#define _J1939_PGN_CTL_H_


// -- Includes ----------------------------------------------------------------
#include "stwtypes.h"
#include "j1939_pgn_types.h"

#if defined(__cplusplus) 
extern "C" {     // Make sure we have C-declarations in C++ programs
#endif


// -- Defines -----------------------------------------------------------------
#define J1939_PGN_CTL       (uint32)52992U          // Continuous Torque Speed Limit Request   CTL

// -- Types -------------------------------------------------------------------
typedef struct
{
   T_J1939_PG_ctrl t_Ctrl; // control structure
   //unscaled SPNs
   uint8   u8_MinContEngineSpeedLimitReq;   // SPN 1784: 1 Byte, 32rpm / bit
   uint8   u8_MaxContEngineSpeedLimitReq;   // SPN 1785: 1 Byte, 32rpm / bit
   uint8   u8_MinContEngineTorqueLimitReq;   // SPN 1786: 1 Byte, 1% / bit
   uint8   u8_MaxContEngineTorqueLimitReq;   // SPN 1787: 1 Byte, 1% / bit
   uint8   u8_MinContRetarderSpeedLimitReq;   // SPN 1788: 1 Byte, 32rpm / bit
   uint8   u8_MaxContRetarderSpeedLimitReq;   // SPN 1789: 1 Byte, 32rpm / bit
   uint8   u8_MinContRetarderTorqueLimitReq;   // SPN 1790: 1 Byte, 1% / bit
   uint8   u8_MaxContRetarderTorqueLimitReq;   // SPN 1791: 1 Byte, 1% / bit
   //Scaled Versions
   uint16 u16_MinContEngineSpeedLimitReq_rpm;   // SPN 1784: [0 .. 8000]rpm
   uint16 u16_MaxContEngineSpeedLimitReq_rpm;   // SPN 1785: [0 .. 8000]rpm
   sint8 s8_MinContEngineTorqueLimitReq_perc;   // SPN 1786: [-125 .. +125]%
   sint8 s8_MaxContEngineTorqueLimitReq_perc;   // SPN 1787: [-125 .. +125]%
   uint16 u16_MinContRetarderSpeedLimitReq_rpm;   // SPN 1788: [0 .. 8000]rpm
   uint16 u16_MaxContRetarderSpeedLimitReq_rpm;   // SPN 1789: [0 .. 8000]rpm
   sint8 s8_MinContRetarderTorqueLimitReq_perc;   // SPN 1790: [-125 .. +125]%
   sint8 s8_MaxContRetarderTorqueLimitReq_perc;   // SPN 1791: [-125 .. +125]%
}
T_J1939_PGN_CTL;   //struct for the PG Continuous Torque Speed Limit Request


// -- Global Variables --------------------------------------------------------
extern const T_J1939_PGN_parameters gt_J1939_PGN_CFG_CTL;   //this variable is used to describe the data which doesn't change in the run-time environment


// -- Function Prototypes -----------------------------------------------------


// -- Implementation ----------------------------------------------------------


#if defined(__cplusplus)
}                // Make sure we have C-declarations in C++ programs
#endif

#endif                // Avoid multiple/recursive inclusion

/*************************** End of file ****************************/
