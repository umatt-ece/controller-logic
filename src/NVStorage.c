/******************************************************************************/
/*!
   \defgroup   eeprom EEPROM

   Project     278 D200 Drapers\n
   Copyright   MacDon 2015\n
   License     use only under terms of contract / confidential\n

   Date         |    Author     |   Notes
   -------------|---------------|-----------------------------------------------------------------------------------
   22.07.2015   |    MacDon/KP  |   file created\n
   24.05.2018   |    MacDon/BZ  |   Add EEPROM CRC checking.  Changes can be seen in version_history.txt
   17.12.2018   |    MacDon/BZ  |   Updated to final field test release.  Changes can be seen in version_history.txt

   \file       NVStorage.c
   \brief      Functions for Initializing and Storing Variables
   \ingroup   eeprom

*/
/******************************************************************************/




// Includes
#include "x_eep.h"
#include "x_uti.h"
#include "main.h"

#include "stdtypes.h"
#include "NVStorage.h"




//section CRC check
//-----------global variables--------------------
EE_section_0_t gu_ee_section_0;
EE_section_1_t gu_ee_section_1;
EE_section_2_t gu_ee_section_2;
EE_section_3_t gu_ee_section_3;
EE_section_4_t gu_ee_section_4;
EE_section_5_t gu_ee_section_5;
EE_section_6_t gu_ee_section_6;
EE_section_7_t gu_ee_section_7;
EE_section_8_t gu_ee_section_8;


//--------------------------------
void resetEEsection(const uint32 ou32_SectionBaseAddr)
{
    uint32 u32_i;
    uint8 u8_value = 0xFF;
    for (u32_i = ou32_SectionBaseAddr; u32_i < (ou32_SectionBaseAddr + EE_SECTION_SIZE - 1); u32_i++)
    {
        x_eep_write(u32_i, 1, &u8_value);
    }
}

boolean sectionCRCvalid(const uint32 ou32_SectionBaseAddr)
{
    uint16 u16_storedCRC;
    uint8  au8_eeprom[EE_SECTION_DATA_SIZE];
    uint16 u16_Crc16;
    x_eep_read(ou32_SectionBaseAddr, EE_SECTION_DATA_SIZE, au8_eeprom);
    x_eep_read(ou32_SectionBaseAddr+EE_SECTION_DATA_SIZE, EE_CRC_SIZE, (uint8*)&u16_storedCRC);
    u16_Crc16 = EE_CRC_SEED;
    x_uti_calc_crc_16(EE_SECTION_DATA_SIZE, au8_eeprom, &u16_Crc16);
    return (u16_storedCRC == u16_Crc16);
}

void sectionCRCupdate(const uint32 ou32_SectionBaseAddr)
{
    uint16 u16_Crc16;
    uint8 au8_eeprom[EE_SECTION_DATA_SIZE];
    u16_Crc16 = EE_CRC_SEED;
    x_eep_read(ou32_SectionBaseAddr, EE_SECTION_DATA_SIZE, au8_eeprom);
    x_uti_calc_crc_16(EE_SECTION_DATA_SIZE, au8_eeprom, &u16_Crc16); //x_uti_calc_crc_16 has no error return value
    x_eep_write(ou32_SectionBaseAddr+EE_SECTION_DATA_SIZE, EE_CRC_SIZE, (uint8*)&u16_Crc16);
}

// opau8_sectionData is initialized as default before this function called.
// if CRC check fail, use the default data in opau8_sectionData
//The result of data will be in opau8_sectionData
//2018-12-12 bzhou: return: (1) when oq_CRCRequired==TRUE, if CRC check result is correct then return TRUE; incorrect then FALSE
//                          (2) when oq_CRCRequired==FASLE, if there already are data in the section then return TRUE; all bytes are 0xFF then return FALSE
boolean GetEEDataInit(const uint32 ou32_SectionBaseAddr,  uint8* const opau8_sectionData, const boolean oq_CRCRequired)
{
    uint8 au8_eeprom[EE_SECTION_DATA_SIZE];
    uint8 u8_cnt;
    uint8 u8_empty = 0xFF;
    boolean q_CRC = FALSE; //2018-12-12 bzhou: add q_CRC

    if(oq_CRCRequired)
    {
        if( sectionCRCvalid(ou32_SectionBaseAddr) )
        {
            x_eep_read(ou32_SectionBaseAddr, EE_SECTION_DATA_SIZE, opau8_sectionData);
            q_CRC = TRUE;
        }
        else
        {
            x_eep_write(ou32_SectionBaseAddr, EE_SECTION_DATA_SIZE, opau8_sectionData);
            sectionCRCupdate(ou32_SectionBaseAddr);
        }
    }
    else
    {
        x_eep_read(ou32_SectionBaseAddr, EE_SECTION_DATA_SIZE, au8_eeprom);
        for (u8_cnt=0; u8_cnt<EE_SECTION_DATA_SIZE; u8_cnt++)
        {
            u8_empty &= au8_eeprom[u8_cnt];// see if EEPROM data is not initialized
        }

        if(0xFF != u8_empty)
        {
            x_eep_read(ou32_SectionBaseAddr, EE_SECTION_DATA_SIZE, opau8_sectionData);
            q_CRC = TRUE;
        }
        else
        {
            x_eep_write(ou32_SectionBaseAddr, EE_SECTION_DATA_SIZE, opau8_sectionData);
        }
    }
    return q_CRC;
}


void putEEdata(const uint32 ou32_SectionBaseAddr, uint8* const opau8_sectionData, const boolean oq_CRCRequired)
{
    x_eep_write(ou32_SectionBaseAddr, EE_SECTION_DATA_SIZE, opau8_sectionData);
    if(oq_CRCRequired)
    {
        sectionCRCupdate(ou32_SectionBaseAddr);
    }
}



