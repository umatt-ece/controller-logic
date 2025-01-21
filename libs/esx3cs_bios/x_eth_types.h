//-----------------------------------------------------------------------------
/*!
   \file       x_eth_types.h
   \brief      Types and constants for generic Ethernet API

   Header defines types and constants for generic Ethernet API.

   \implementation
   project     project name
   copyright   STW (c) 1999-200x
   license     use only under terms of contract / confidential
   \endimplementation
*/
//-----------------------------------------------------------------------------
/*!
   \addtogroup     x_eth
   \{
*/
//-----------------------------------------------------------------------------

#ifndef _X_ETH_TYPES_H
#define _X_ETH_TYPES_H

/* -- Includes ------------------------------------------------------------ */
#include "stwtypes.h"

#ifdef __cplusplus
extern "C" {
#endif

/* -- Defines ------------------------------------------------------------- */
#define X_ETH_LINK_DOWN                      (0u)
#define X_ETH_LINK_UP                        (1u)

#define X_ETH_SPEED_NONE                     (0u)
#define X_ETH_SPEED_AUTO                     (1u)
#define X_ETH_SPEED_10MB                     (2u)
#define X_ETH_SPEED_100MB                    (3u)

#define X_ETH_DUPLEX_MODE_NONE               (0u)
#define X_ETH_DUPLEX_MODE_AUTO               (1u)
#define X_ETH_DUPLEX_MODE_HALF               (2u)
#define X_ETH_DUPLEX_MODE_FULL               (3u)

#define X_ETH_FILTER_ACCEPT_BROADCAST        (1u)     // accept broadcast frames
#define X_ETH_FILTER_ACCEPT_MULTICAST        (2u)     // accept all multicast frames
#define X_ETH_FILTER_ACCEPT_UNICAST          (4u)     // accept unicast frames matching the local MAC address
#define X_ETH_FILTER_ACCEPT_UNICAST_OTHERS   (8u)     // accept unicast frames not matching the local MAC address


/* -- Types --------------------------------------------------------------- */
typedef void (*PR_x_eth_rx_callback)(const uint32 ou32_CallbackParameter, void* const opv_Handle);
typedef void (*PR_x_eth_tx_callback)(const uint32 ou32_CallbackParameter, void* const opv_Handle);
typedef void (*PR_x_eth_link_callback)(const uint32 ou32_CallbackParameter, void* const opv_Handle,
                                       const uint8 ou8_LinkStatus);


/*! \brief  Ethernet interface configuration data */
typedef struct
{
   uint16 u16_Channel;                       //!< Interface channel number
   uint8  u8_Speed;                          //!< Requested link speed (X_ETH_SPEED_AUTO, ..._10MB, ..._100MB)
   uint8  u8_DuplexMode;                     //!< Requested link duplex mode (X_ETH_DUPLEX_MODE_AUTO, ..._HALF, .._FULL)
   uint16 u16_RxFilter;                      //!< Receive filter (X_ETH_FILTER_ACCEPT_BROADCAST, ..._MULTICAST, ...)
   uint8 au8_MacAddr[6];                     //!< Interface MAC address, (0: Use built-in MAC)
   uint16 u16_MaxFrameLen;                   //!< Max. transmission unit (incl. header and FCS), (0: use default=1518)
   PR_x_eth_rx_callback pr_RxCallback;       //!< Data RX callback
   uint32 u32_RxCallbackParameter;           //!< Callback parameter for RX callback
   PR_x_eth_tx_callback pr_TxCallback;       //!< Data TX callback
   uint32 u32_TxCallbackParameter;           //!< Callback parameter for TX callback
   PR_x_eth_link_callback pr_LinkCallback;   //!< Link change notification callback
   uint32 u32_LinkCallbackParameter;         //!< Callback parameter for link change notification callback
} T_x_eth_config;


/*! \brief  Ethernet interface status information */
typedef struct
{
   uint8  u8_LinkStatus;                     //!< Link status (X_ETH_LINK_UP, X_ETH_LINK_DOWN)
   uint8  u8_Speed;                          //!< Link speed (X_ETH_SPEED_NONE, X_ETH_SPEED_10MB, X_ETH_SPEED_100MB)
   uint8  u8_DuplexMode;                     //!< Link duplex mode (X_ETH_DUPLEX_MODE_NONE, ..._HALF, ..._FULL)
   uint16 u16_RxPending;                     //!< Number of received Ethernet frames ready for reading
   uint16 u16_RxOverflow;                    //!< Number of dumped RX Ethernet frames (due to buffer overflow)
   uint16 u16_RxError;                       //!< Number of corrupted RX Ethernet frames
   uint16 u16_TxPending;                     //!< Number of Ethernet frames ready for sending
} T_x_eth_status;


/* -- Global Variables ---------------------------------------------------- */

/* -- Function Prototypes ------------------------------------------------- */

/* -- Implementation ------------------------------------------------------ */

#ifdef __cplusplus
} /* end of extern "C" */
#endif

#endif   // _X_ETH_TYPES_H

/*! \} */
