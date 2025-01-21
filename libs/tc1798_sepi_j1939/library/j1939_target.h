//-----------------------------------------------------------------------------
/*!
   \file       j1939_target.h
   \brief      ECU architecture specific abstraction layer

   Provide a target independt interface to the stack.
   Here: ESX-3c

   \implementation
   copyright   STW (c) 1999-201x
   license     use only under terms of contract / confidential

   created           20.07.2010     STW/M.Greiner
   \endimplementation

   \internal
   \history
   Date(dd.mm.yyyy)  Author         Description
   20.06.2016        STW/S.Singer   modified for ESX-3c target
   24.09.2012        STW/M.Greiner  extended for EB10 and SL targets
   20.07.2010        STW/M.Greiner  file created
   \endhistory
*/
//-----------------------------------------------------------------------------
#ifndef _J1939_TARGET_H_
#define _J1939_TARGET_H_

#ifdef __cplusplus
extern "C" {
#endif


/* -- Includes ------------------------------------------------------------ */
#include "stdtypes.h"
#include "stwtypes.h"


/* -- Defines ------------------------------------------------------------- */
#define J1939_CAN_CH_MAX       (4+(6*4))                         // the maximal number of CAN buses suported by target
#define J1939_TRG_HUGE                                           // memory specifier


/* -- Types --------------------------------------------------------------- */
typedef struct
{
   uint16 u16_Channel;           // the physical mainboard can bus number - X_CAN_BUS_[01..04]
   // Tx object
   uint8  u8_TxBufferSize;       // the max number of messages in buffer (0 - default 10)
   // Rx object
   uint8  u8_RxBufferSize;       // the max number of messages in buffer (0 - default 30)
}
T_J1939_bus_parameters;          // bus parameters for mainboard CAN target


/* -- Global Variables ---------------------------------------------------- */


/* -- Function Prototypes ------------------------------------------------- */
extern sint16 J1939_init        (const uint16 ou16_Channel, const T_J1939_bus_parameters *      const opt_Config);


/* -- Implementation ------------------------------------------------------ */


#ifdef __cplusplus
} /* end of extern "C" */
#endif

#endif  /* _STWTYPES_H */
