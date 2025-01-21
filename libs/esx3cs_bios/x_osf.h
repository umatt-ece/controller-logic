//----------------------------------------------------------------------------------------------------------------------
/*!
   \file       x_osf.h
   \brief      Flashloader Parameter Access

   \implementation
   project     project name
   copyright   STW (c) 1999-20xx
   license     use only under terms of contract / confidential

   \created     15.03.2018  TD
   \endimplementation
*/
//----------------------------------------------------------------------------------------------------------------------
#ifndef _X_OSF_H
#define _X_OSF_H


/* -- Includes ------------------------------------------------------------------------------------------------------ */
#include "stwtypes.h"

// Interface Identifiers
#include "x_can.h"
#include "x_eth.h"

#ifdef __cplusplus
extern "C" {
#endif


/* -- Defines ------------------------------------------------------------------------------------------------------- */

/*********************************************************************
 *  STW SEPI functions, data types and error codes are each          *
 *  placed into a separate namespace for C++.                        *
 *  The following #ifdef instruction will load either the standard   *
 *  C - API style or the C++ style with namespaces.                  *
 *********************************************************************/
#ifdef __cplusplus
namespace stw_sepi
{
   #include "./hpp/x_osf.hpp"
}
#else



/* -- Types --------------------------------------------------------------------------------------------------------- */
// This structure provides fingerprint information about the last software update
typedef struct
{
   uint8 au8_ProgDate[3];  // date of programming (format: yymmdd)
   uint8 au8_ProgTime[3];  // time of programming (format: hhmmss)
   charn acn_Username[21]; // username (20 characters + zero-termination)
} T_x_osf_fingerprint;

// This structure contains CAN interface parameters
typedef struct
{
   uint32 u32_Bitrate;     // CAN bit rate (bit/s)
   uint16 u16_SamplePoint; // sample point (in 0.1%; 0 = auto)
} T_x_osf_can;

// This structure contains the openSYDE communication settings
typedef struct
{
   uint8 u8_Active;   // openSYDE communication channel Status
   uint8 u8_BusId;    // openSYDE communication channel BusId
   uint8 u8_NodeId;   // openSYDE communication channel NodeId
   uint8 u8_Reserved; // reserved (used for 32bit alignment)
} T_x_osf_oscs;

// This structure contains IPv4 settings for Ethernet interfaces
typedef struct
{
   uint8 au8_Ip[4];      // IP address (e.g. 192.168.1.2 -> {192, 168, 1, 2})
   uint8 au8_NetMask[4]; // subnet mask (e.g. 255.255.255.0 -> {255, 255, 255, 0})
   uint8 au8_Gateway[4]; // gateway address (e.g. 192.168.1.1 -> {192, 168, 1, 1})
} T_x_osf_eth_ipv4;


/* -- Global Variables ---------------------------------------------------------------------------------------------- */


/* -- Function Prototypes ------------------------------------------------------------------------------------------- */
// General Parameters
sint16 x_osf_get_prog_req_flag(uint8 * const opu8_ProgramRequestFlag);
sint16 x_osf_set_prog_req_flag(const uint8 ou8_ProgramRequestFlag);
sint16 x_osf_get_fingerprint(T_x_osf_fingerprint * const opt_Fingerprint);
sint16 x_osf_get_download_cnt(uint32 * const opu32_DownloadCount);
sint16 x_osf_get_boot_sw_id(uint8 opu8_Identification[3]);

// CAN Parameters
sint16 x_osf_can_get_param(const uint16 ou16_Interface, T_x_osf_can * const opt_Settings);
sint16 x_osf_can_set_param(const uint16 ou16_Interface, const T_x_osf_can * const opt_Settings);
sint16 x_osf_can_get_oscs(const uint16 ou16_Interface, T_x_osf_oscs * const opt_Settings);
sint16 x_osf_can_set_oscs(const uint16 ou16_Interface, const T_x_osf_oscs * const opt_Settings);

// Ethernet Parameters
sint16 x_osf_eth_get_mac(const uint16 ou16_Interface, uint8 opu8_MacAddress[6]);
sint16 x_osf_eth_set_mac(const uint16 ou16_Interface, const uint8 opu8_MacAddress[6]);
sint16 x_osf_eth_get_hostname(const uint16 ou16_Interface, charn opcn_Hostname[32]);
sint16 x_osf_eth_set_hostname(const uint16 ou16_Interface, const charn opcn_Hostname[32]);
sint16 x_osf_eth_get_oscs(const uint16 ou16_Interface, T_x_osf_oscs * const opt_Settings);
sint16 x_osf_eth_set_oscs(const uint16 ou16_Interface, const T_x_osf_oscs * const opt_Settings);
sint16 x_osf_eth_get_ipv4(const uint16 ou16_Interface, T_x_osf_eth_ipv4 * const opt_Settings);
sint16 x_osf_eth_set_ipv4(const uint16 ou16_Interface, const T_x_osf_eth_ipv4 * const opt_Settings);


/* -- Implementation ------------------------------------------------------------------------------------------------ */


#endif  //__cplusplus

#ifdef __cplusplus
} /* end of extern "C" */
#endif

#endif  /* _X_OSF_H */
