//-----------------------------------------------------------------------------
/*!
   \file        x_uti.hpp
   \brief       CPP namespace extention for x_uti.h

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

#ifndef __X_UTI_HPP
#define __X_UTI_HPP



/* -- Function Prototypes ------------------------------------------------- */

//-----------------------------------------------------------------------------
/*!
   \brief    calculate 32bit CRC over ou32_Count 32bit words.

             the function use the ethernet polynomial 0x104C11DB7  \n
             and TriCore memchecker hardware \n

   \note     the TriCore algorithm is not compatible to standard CRC generation \n

   \param    ou32_Count: number of 32bit data words that should be CRC checked \n
   \param    opu32_Data: data pointer (start address) \n
   \param    opu32_Crc:  pointer to CRC value, start value should be 0xFFFFFFFF \n

   \return   C_NO_ERR    terminated with no error
   \retval   C_RANGE     pu32_Data is not a valid 32bit word address

   \created  13.04.2005  Herb

*/
//-----------------------------------------------------------------------------
stw_types::sint16 x_uti_calc_crc_tricore(const stw_types::uint32 ou32_Count, const stw_types::uint32* const opu32_Data, stw_types::uint32* const opu32_Crc);

//-----------------------------------------------------------------------------
/*!
   \brief    Calculate 16bit CRC checksum over n bytes.

             the function use the CCITT X25 polynomial 0x11021 \n
             the start value *pu16_CRC should be 0xFFFF \n
             it uses the look up table mau16_CRC16[] \n

   \param    ou32_Count: number of data bytes that should be CRC checked \n
   \param    opu8_Data:  data pointer \n
   \param    opu16_Crc:  pointer to CRC value, start value should be 0xFFFF \n

   \return   C_NO_ERR    terminated with no error

   \created  13.04.2005  Herb

*/
//-----------------------------------------------------------------------------
stw_types::sint16 x_uti_calc_crc_16(const stw_types::uint32 ou32_Count, const stw_types::uint8* const opu8_Data, stw_types::uint16* const opu16_Crc);

//-----------------------------------------------------------------------------
/*!
   \brief    Calculate 16bit STW CRC checksum over n bytes.

             the function use the polynomial 0x11021 \n
             the start value *pu16_CRC should be 0x0000 \n
             it uses the look up table mau16_CRC16[] \n

   \note     the STW CRC algorithm is not compatible to standard CRC generation \n

   \param    ou32_Count: number of data bytes that should be CRC checked \n
   \param    opu8_Data:  data pointer \n
   \param    opu16_Crc:  pointer to CRC value, start value should be 0xFFFF \n

   \return   C_NO_ERR    terminated with no error

   \created  08.03.2006  Herb

*/
//-----------------------------------------------------------------------------
stw_types::sint16 x_uti_calc_crc_stw(const stw_types::uint32 ou32_Count, const stw_types::uint8* const opu8_Data, stw_types::uint16* const opu16_Crc);


#endif  // __X_UTI_HPP
