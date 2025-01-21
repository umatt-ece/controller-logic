//-----------------------------------------------------------------------------
/*!
   \file        x_eth.hpp
   \brief       CPP namespace extention for x_eth.h

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

#ifndef __X_ETH_HPP
#define __X_ETH_HPP



/* -- Types --------------------------------------------------------------- */

/* -- Global Variables ---------------------------------------------------- */

/* -- Function Prototypes ------------------------------------------------- */

stw_types::sint16 x_eth_init(const T_x_eth_config* const opt_Config, void** const oppv_Handle);
stw_types::sint16 x_eth_close(void* const opv_Handle);
stw_types::sint16 x_eth_send_frame(void* const opv_Handle, const stw_types::uint16 ou16_Length, const stw_types::uint8* const opu8_Data,
                                   const stw_types::uint8 ou8_FrameComplete);
stw_types::sint16 x_eth_get_frame(void* const opv_Handle, const stw_types::uint16 ou16_BufSize, stw_types::uint8* const opu8_Data,
                                  stw_types::uint16* const opu16_Length, stw_types::uint8* const opu8_FrameComplete);
stw_types::sint16 x_eth_get_status(void* const opv_Handle, T_x_eth_status* const opt_Status);
stw_types::sint16 x_eth_get_rx_buf_count(void* const opv_Handle, stw_types::uint16* const opu16_Count);
stw_types::sint16 x_eth_get_tx_buf_count(void* const opv_Handle, stw_types::uint16* const opu16_Count);
stw_types::sint16 x_eth_get_tx_buf_space(void* const opv_Handle, stw_types::uint16* const opu16_Count);
stw_types::sint16 x_eth_get_rx_frame_length(void* const opv_Handle, stw_types::uint16* const opu16_Length);
stw_types::sint16 x_eth_get_config(void* const opv_Handle, T_x_eth_config* const opt_Config);


#endif  // __X_ETH_HPP
