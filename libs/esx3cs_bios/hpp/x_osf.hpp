//-----------------------------------------------------------------------------
/*!
   \file        x_osf.hpp
   \brief       CPP namespace extention for x_osf.h

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

#ifndef __X_OSF_HPP
#define __X_OSF_HPP




/* -- Types --------------------------------------------------------------------------------------------------------- */
// This structure provides fingerprint information about the last software update
typedef struct
{
   stw_types::uint8 au8_ProgDate[3];  // date of programming (format: yymmdd)
   stw_types::uint8 au8_ProgTime[3];  // time of programming (format: hhmmss)
   stw_types::charn acn_Username[21]; // username (20 characters + zero-termination)
} T_x_osf_fingerprint;

// This structure contains CAN interface parameters
typedef struct
{
   stw_types::uint32 u32_Bitrate;     // CAN bit rate (bit/s)
   stw_types::uint16 u16_SamplePoint; // sample point (in 0.1%; 0 = auto)
} T_x_osf_can;

// This structure contains the openSYDE communication settings
typedef struct
{
   stw_types::uint8 u8_Active;   // openSYDE communication channel Status
   stw_types::uint8 u8_BusId;    // openSYDE communication channel BusId
   stw_types::uint8 u8_NodeId;   // openSYDE communication channel NodeId
   stw_types::uint8 u8_Reserved; // reserved (used for 32bit alignment)
} T_x_osf_oscs;

// This structure contains IPv4 settings for Ethernet interfaces
typedef struct
{
stw_types::uint8 au8_Ip[4];      // IP address (e.g. 192.168.1.2 -> {192, 168, 1, 2})
stw_types::uint8 au8_NetMask[4]; // subnet mask (e.g. 255.255.255.0 -> {255, 255, 255, 0})
stw_types::uint8 au8_Gateway[4]; // gateway address (e.g. 192.168.1.1 -> {192, 168, 1, 1})
} T_x_osf_eth_ipv4;


/* -- Global Variables ---------------------------------------------------------------------------------------------- */


/* -- Function Prototypes ------------------------------------------------------------------------------------------- */
// General Parameters
stw_types::sint16 x_osf_get_prog_req_flag(stw_types::uint8 * const opu8_ProgramRequestFlag);
stw_types::sint16 x_osf_set_prog_req_flag(const stw_types::uint8 ou8_ProgramRequestFlag);
stw_types::sint16 x_osf_get_fingerprint(T_x_osf_fingerprint * const opt_Fingerprint);
stw_types::sint16 x_osf_get_download_cnt(stw_types::uint32 * const opu32_DownloadCount);
stw_types::sint16 x_osf_get_boot_sw_id(stw_types::uint8 opu8_Identification[3]);

// CAN Parameters
stw_types::sint16 x_osf_can_get_param(const stw_types::uint16 ou16_Interface, T_x_osf_can * const opt_Settings);
stw_types::sint16 x_osf_can_set_param(const stw_types::uint16 ou16_Interface, const T_x_osf_can * const opt_Settings);
stw_types::sint16 x_osf_can_get_oscs(const stw_types::uint16 ou16_Interface, T_x_osf_oscs * const opt_Settings);
stw_types::sint16 x_osf_can_set_oscs(const stw_types::uint16 ou16_Interface, const T_x_osf_oscs * const opt_Settings);

// Ethernet Parameters
stw_types::sint16 x_osf_eth_get_mac(const stw_types::uint16 ou16_Interface, stw_types::uint8 opu8_MacAddress[6]);
stw_types::sint16 x_osf_eth_set_mac(const stw_types::uint16 ou16_Interface, const stw_types::uint8 opu8_MacAddress[6]);
stw_types::sint16 x_osf_eth_get_hostname(const stw_types::uint16 ou16_Interface, stw_types::charn opcn_Hostname[32]);
stw_types::sint16 x_osf_eth_set_hostname(const stw_types::uint16 ou16_Interface, const stw_types::charn opcn_Hostname[32]);
stw_types::sint16 x_osf_eth_get_oscs(const stw_types::uint16 ou16_Interface, T_x_osf_oscs * const opt_Settings);
stw_types::sint16 x_osf_eth_set_oscs(const stw_types::uint16 ou16_Interface, const T_x_osf_oscs * const opt_Settings);
stw_types::sint16 x_osf_eth_get_ipv4(const stw_types::uint16 ou16_Interface, T_x_osf_eth_ipv4 * const opt_Settings);
stw_types::sint16 x_osf_eth_set_ipv4(const stw_types::uint16 ou16_Interface, const T_x_osf_eth_ipv4 * const opt_Settings);


/* -- Implementation ------------------------------------------------------------------------------------------------ */


#endif  // __X_OSF_HPP
