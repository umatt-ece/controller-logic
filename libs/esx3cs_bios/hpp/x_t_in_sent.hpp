//-----------------------------------------------------------------------------
/*!
   \file        x_t_in_sent.hpp
   \brief       CPP namespace extention for x_t_in_sent.h

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

#ifndef __X_T_IN_SENT_HPP
#define __X_T_IN_SENT_HPP



/* -- Types --------------------------------------------------------------- */

typedef struct
{
   stw_types::uint16 u16_Channel1;          // 1st channel data (e.g. nibble 1..3 for frames with 6 data nibbles)
   stw_types::uint16 u16_Channel2;          // 2nd channel data (e.g. nibble 4..6 for frames with 6 data nibbles)
   stw_types::uint8 u8_FrameLength;         // Number of data nibbles (1..8)
   stw_types::uint8 u8_Crc;                 // CRC checksum Nibble
} T_x_t_in_sent_fast_channel_data;

/*
   SENT Encoding Scheme of Short and Enhanced Serial Message Format (aka "Slow Channel" data/signals):

   +---------------+------------------------------------+---------------------------------------+
   | Format        |       ..._SHORT_SERIAL_MSG         |       ..._ENHANCED_SERIAL_MSG         |
   +---------------+------------------------------------+---------------------------------------+
   | Data          | 8bit                               | 12bit             | 16bit             |
   +---------------+------------------------------------+---------------------------------------+
   | Configuration | Not used                           | 0                 | 1                 |
   +---------------+------------------------------------+---------------------------------------+
   | MessageId     | 4bit                               | 8bit              | 4bit              |
   +---------------+------------------------------------+---------------------------------------+
   | CRC           | 4bit                               | 6bit                                  |
   +---------------+------------------------------------+---------------------------------------+
*/
typedef struct
{
   stw_types::uint16 u16_Data;              // Data (8bit, 12bit or 16bit)
   stw_types::uint8 u8_Format;              // Serial message format (0 = Short or 1 = Enhanced Serial Message Format)
   stw_types::uint8 u8_Configuration;       // 0 -> 8bit MessageId and 12bit Data; 1 -> 4bit MessageId and 16bit Data
   stw_types::uint8 u8_MessageId;           // Message identifier (4bit or 8bit)
   stw_types::uint8 u8_Crc;                 // CRC checksum (4bit or 6bit)
} T_x_t_in_sent_slow_channel_data;

typedef struct
{
   stw_types::uint8 u8_SystemStatus;        // SENT System Status (see defines X_T_IN_SENT_STATUS_...)
   stw_types::uint8 u8_SlowChannelBufOvl;   // slow channel buffer overflow counter
   stw_types::uint16 u16_LastError;         // last error (see defines X_T_IN_SENT_ERROR_...)
} T_x_t_in_sent_status;


// fast channel data receive callback function prototype
typedef void (*PR_x_t_in_sent_rx_fast_callback)(const stw_types::uint32 ou32_CallbackParameter, const stw_types::uint16 ou16_Channel,
                                                const T_x_t_in_sent_fast_channel_data * const opt_Data);
// slow channel data receive callback function prototype
typedef void (*PR_x_t_in_sent_rx_slow_callback)(const stw_types::uint32 ou32_CallbackParameter, const stw_types::uint16 ou16_Channel,
                                                const T_x_t_in_sent_slow_channel_data * const opt_Data);
// error callback function prototype
typedef void (*PR_x_t_in_sent_error_callback)(const stw_types::uint32 ou32_CallbackParameter, const stw_types::uint16 ou16_Channel,
                                              const stw_types::uint16 ou16_Error);

typedef struct
{
   stw_types::uint8  u8_TickTimeUs;            // nominal tick time in micro seconds, range 1..90
   stw_types::uint8  u8_FrameLength;           // frame length in data nibbles (without status and CRC nibbles), range 0..8
   stw_types::uint8  u8_InputFilter;           // digital input filter, resolution 0.03*u8_TickTimeUs, range 0..15 (0 = filter off)
   stw_types::uint8  u8_OperationMode;         // configures the SENT operation mode, see defines X_T_IN_SENT_MODE_...
   stw_types::uint16 u16_CrcMode;              // configuration of CRC calculation, see defines X_T_IN_SENT_CRC_...
   stw_types::uint16 u16_SlowChannelBufSize;   // FIFO buffer size for serial message data (slow channel)
   
   stw_types::uint32 u32_NibbleMapping;  // fast channel data nibble mapping:
   // each nibble of u32_NibbleMapping points to a destination nibble in
   // T_x_t_in_sent_fast_channel_data::u16_Channel1 and :: u16_Channel2
   // nibble 0 of u32_NibbleMapping remaps the first received nibble, nibble1 the 2nd, and so on.
   // Therefore up to 8 received data nibbles can be remapped to u16_Channel1 and u16_Channel2.
   // Remap nibble value 0 points to the LSN of u16_Channel1, remap value 3 points to MSN of u16_Channel1,
   // Remap nibble value 4 points to the LSN of u16_Channel2, remap value 7 points to MSN of u16_Channel2.
   // If a frame length is <8 nibbles e.g. 6 than the unused nibbles 6 and 7 are zero and might be used
   // to fill the destination u16_Channel1 and/or u16_Channel2 with nibbles of value zero.
   //
   // Example: sensor data frame length is 6 nibbles, two 12bit fast channel data are send with MSN first.
   //          The first 12bit data value should be located in u16_Channel1 the second in u16_Channel2
   //          u32_NibbleMapping = 0x73456012u
   //
   //          Destination:   u16_Channel1    u16_Channel2
   //                           _ _ _ _         _ _ _ _
   //                          |3|2|1|0|       |7|6|5|4|
   //                           | | | |         | | | |
   //    RX nibble 0 -------------+ | |         | | | |
   //    RX nibble 1 ---------------+ |         | | | |
   //    RX nibble 2 -----------------+         | | | |
   //    RX nibble 3 -----------------------------+ | |
   //    RX nibble 4 -------------------------------+ |
   //    RX nibble 5 ---------------------------------+
   //             [6] =0 -------+               |        note: nibble 6 and 7 are not used and have zero value
   //             [7] =0 -----------------------+              they are used to fill the MSN of the destination
   
   stw_types::uint32 u32_RxSlowCallbackParameter;                   // slow channel callback parameter
   PR_x_t_in_sent_rx_slow_callback pr_RxSlowCallback;    // slow channel receive callback function pointer
   stw_types::uint32 u32_RxFastCallbackParameter;                   // fast channel callback parameter
   PR_x_t_in_sent_rx_fast_callback pr_RxFastCallback;    // fast channel receive callback function pointer
   stw_types::uint32 u32_ErrorCallbackParameter;                    // error callback parameter
   PR_x_t_in_sent_error_callback pr_ErrorCallback;       // error callback function pointer
   stw_types::uint16 u16_FastChannelRxTimeout500us;                 // fast channel receive timeout in 500us steps,
   // range 2..65535, 0 and 1 = timeout disabled
} T_x_t_in_sent_config;


/* -- Function Prototypes ------------------------------------------------- */

stw_types::sint16 x_t_in_sent_init(const stw_types::uint16 ou16_Channel, const T_x_t_in_sent_config* const opt_Config);
stw_types::sint16 x_t_in_sent_read_fast_channel(const stw_types::uint16 ou16_Channel, T_x_t_in_sent_fast_channel_data * const opt_Data);
stw_types::sint16 x_t_in_sent_get_slow_channel_buf_count(const stw_types::uint16 ou16_Channel, stw_types::uint16 * const opu16_Count);
stw_types::sint16 x_t_in_sent_read_slow_channel(const stw_types::uint16 ou16_Channel, T_x_t_in_sent_slow_channel_data * const opt_Data);
stw_types::sint16 x_t_in_sent_get_status(const stw_types::uint16 ou16_Channel, T_x_t_in_sent_status * const opt_Status);


#endif  // __X_T_IN_SENT_HPP
