//-----------------------------------------------------------------------------
/*!
   \file       x_eth.h
   \brief      Generic Ethernet functions (Layer2 API)

   Header defines generic Ethernet functions for communication based on
   OSI Layer 2. This API provides functions to send and receive Ethernet frames.

   \implementation
   project     project name
   copyright   STW (c) 1999-200x
   license     use only under terms of contract / confidential
   \endimplementation

*/
//-----------------------------------------------------------------------------

#ifndef _X_ETH_H
#define _X_ETH_H

/* -- Includes ------------------------------------------------------------ */
#include "x_stdtypes.h"
#include "x_eth_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* -- Defines ------------------------------------------------------------- */

#define X_ETH_CH_MAX             (1)
#define X_ETH_01                 (0u)


/*********************************************************************
 *  STW SEPI functions, data types and error codes are each          *
 *  placed into a separate namespace for C++.                        *
 *  The following #ifdef instruction will load either the standard   *
 *  C - API style or the C++ style with namespaces.                  *
 *********************************************************************/

#ifdef __cplusplus
namespace stw_sepi
{
   #include "./hpp/x_eth.hpp"
}
#else


/* -- Types --------------------------------------------------------------- */

/* -- Global Variables ---------------------------------------------------- */

/* -- Function Prototypes ------------------------------------------------- */

sint16 x_eth_init(const T_x_eth_config* const opt_Config, void** const oppv_Handle);
sint16 x_eth_close(void* const opv_Handle);
sint16 x_eth_send_frame(void* const opv_Handle, const uint16 ou16_Length, const uint8* const opu8_Data,
                        const uint8 ou8_FrameComplete);
sint16 x_eth_get_frame(void* const opv_Handle, const uint16 ou16_BufSize, uint8* const opu8_Data,
                       uint16* const opu16_Length, uint8* const opu8_FrameComplete);
sint16 x_eth_get_status(void* const opv_Handle, T_x_eth_status* const opt_Status);
sint16 x_eth_get_rx_buf_count(void* const opv_Handle, uint16* const opu16_Count);
sint16 x_eth_get_tx_buf_count(void* const opv_Handle, uint16* const opu16_Count);
sint16 x_eth_get_tx_buf_space(void* const opv_Handle, uint16* const opu16_Count);
sint16 x_eth_get_rx_frame_length(void* const opv_Handle, uint16* const opu16_Length);
sint16 x_eth_get_config(void* const opv_Handle, T_x_eth_config* const opt_Config);


#endif  //__cplusplus

#ifdef __cplusplus
} /* end of extern "C" */
#endif

#endif   // _X_ETH_H

/*! \} */
