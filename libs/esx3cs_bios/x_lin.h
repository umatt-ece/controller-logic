//-----------------------------------------------------------------------------
/*!
   \file       x_lin.h
   \brief      Generic LIN functions.

   Header defines generic LIN functions.

   \implementation
   project     project name
   copyright   STW (c) 1999-201x
   license     use only under terms of contract / confidential

   created     10.07.2017        STW/T. Dedler
   \endimplementation

*/
//-----------------------------------------------------------------------------

#ifndef _X_LIN_H
#define _X_LIN_H

/* -- Includes ------------------------------------------------------------ */
#include "x_stdtypes.h"
#include "x_lin_types.h"


#ifdef __cplusplus
extern "C" {
#endif

/* -- Defines ------------------------------------------------------------- */
#define X_LIN_CH_MAX                (1)      // note: max number of channels depends on hardware assembly options

#define X_LIN_BUS_01                (0)

/*********************************************************************
 *  STW SEPI functions, data types and error codes are each          *
 *  placed into a separate namespace for C++.                        *
 *  The following #ifdef instruction will load either the standard   *
 *  C - API style or the C++ style with namespaces.                  *
 *********************************************************************/
#ifdef __cplusplus
namespace stw_sepi
{
   #include "./hpp/x_lin.hpp"
}
#else


/* -- Types --------------------------------------------------------------- */

/* -- Global Variables ---------------------------------------------------- */

/* -- Function Prototypes ------------------------------------------------- */
sint16 x_lin_init(const uint16 ou16_Channel, const T_x_lin_config * const opt_Config);
sint16 x_lin_close(const uint16 ou16_Channel);
sint16 x_lin_get_status(const uint16 ou16_Channel, T_x_lin_status * const opt_Status);
sint16 x_lin_set_sleep_mode(const uint16 ou16_Channel, const uint8 ou8_OnOff);

sint16 x_lin_send_request(const uint16 ou16_Channel, const T_x_lin_service * const opt_Request);
sint16 x_lin_get_response(const uint16 ou16_Channel, T_x_lin_service * const opt_Response);

sint16 x_lin_get_request_buf_count(const uint16 ou16_Channel, uint16 * const opu16_Count);
sint16 x_lin_get_response_buf_count(const uint16 ou16_Channel, uint16 * const opu16_Count);
sint16 x_lin_clear_request_buf(const uint16 ou16_Channel);
sint16 x_lin_clear_response_buf(const uint16 ou16_Channel);


/* -- Implementation ------------------------------------------------------ */


#endif  //__cplusplus

#ifdef __cplusplus
} /* end of extern "C" */
#endif

#endif   // _X_LIN_H
