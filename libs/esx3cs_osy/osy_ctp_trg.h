//----------------------------------------------------------------------------------------------------------------------
/*!
   \file
   \brief       CAN-TP: Example template for CAN-TP target definitions
   \copyright   Copyright 2017 Sensor-Technik Wiedemann GmbH. All rights reserved.
*/
//----------------------------------------------------------------------------------------------------------------------
#ifndef OSY_TRG_CANH
#define OSY_TRG_CANH

/* -- Includes ------------------------------------------------------------------------------------------------------ */
#include "stwtypes.h"
#include "stdtypes.h"
#include "stwerrors.h"

/***************************************************************************
 * temporary MISRA deviations:
 *
 * message 3219 off: inline functions are defined but not used inside the header file
 * message 3450 off: the TriCore GCC need inline functions to be declared static
 * message 3480 off: inline functions are defined inside the header file
 * message 6002 off: inline functions are declared static, but they have global scope
 ***************************************************************************/
//PRQA S 3219, 3450, 3480, 6002 ++


/* -- Defines ------------------------------------------------------------------------------------------------------- */
#ifdef __cplusplus
extern "C"
{
#endif
// CAN channel indices
#define  OSY_CTP_TRG_CAN_01               (0U)
#define  OSY_CTP_TRG_CAN_02               (1U)
# define OSY_CTP_TRG_MAX_CAN_INTERFACES   (2U) //< number of CAN interfaces to support


/* -- Types --------------------------------------------------------------------------------------------------------- */
typedef struct
{
   uint8 u8_RxFifoSize;    ///< size of Rx FIFO buffer in number of messages
   uint8 u8_TxFifoSize;    ///< size of Tx FIFO buffer in number of messages
} T_osy_ctp_trg_can_init_params; ///< target specific initialization parameters

/* -- Global Variables ---------------------------------------------------------------------------------------------- */

/* -- Function Prototypes ------------------------------------------------------------------------------------------- */

/* -- Implementation ------------------------------------------------------------------------------------------------ */



#ifdef __cplusplus
} //end of extern "C"
#endif

#endif
