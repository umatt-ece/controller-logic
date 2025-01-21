//-----------------------------------------------------------------------------
/*!
   \file        x_lin.hpp
   \brief       CPP namespace extention for x_lin.h

   This header was automatically created. DO NOT EDIT!

   \implementation
   copyright   STW (c) 1999-20xx
   license     use only under terms of contract / confidential

   created     by hpp_generator.pl
   \endimplementation


   \internal
   \history
   Date(dd.mm.yyyy)  Author                Description
   \endhistory
*/
//-----------------------------------------------------------------------------

#ifndef __X_LIN_HPP
#define __X_LIN_HPP



/* -- Types --------------------------------------------------------------- */

/* -- Global Variables ---------------------------------------------------- */

/* -- Function Prototypes ------------------------------------------------- */
stw_types::sint16 x_lin_init(const stw_types::uint16 ou16_Channel, const T_x_lin_config * const opt_Config);
stw_types::sint16 x_lin_close(const stw_types::uint16 ou16_Channel);
stw_types::sint16 x_lin_get_status(const stw_types::uint16 ou16_Channel, T_x_lin_status * const opt_Status);
stw_types::sint16 x_lin_set_sleep_mode(const stw_types::uint16 ou16_Channel, const stw_types::uint8 ou8_OnOff);

stw_types::sint16 x_lin_send_request(const stw_types::uint16 ou16_Channel, const T_x_lin_service * const opt_Request);
stw_types::sint16 x_lin_get_response(const stw_types::uint16 ou16_Channel, T_x_lin_service * const opt_Response);

stw_types::sint16 x_lin_get_request_buf_count(const stw_types::uint16 ou16_Channel, stw_types::uint16 * const opu16_Count);
stw_types::sint16 x_lin_get_response_buf_count(const stw_types::uint16 ou16_Channel, stw_types::uint16 * const opu16_Count);
stw_types::sint16 x_lin_clear_request_buf(const stw_types::uint16 ou16_Channel);
stw_types::sint16 x_lin_clear_response_buf(const stw_types::uint16 ou16_Channel);


/* -- Implementation ------------------------------------------------------ */


#endif  // __X_LIN_HPP
