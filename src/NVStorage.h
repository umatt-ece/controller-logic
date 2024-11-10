/******************************************************************************/
/*!
   \file       NVStorage.h
   \brief      Functions for Initializing and Storing Variables

   Project     278 D200 Drapers\n
   Copyright   MacDon 2015\n
   License     use only under terms of contract / confidential\n

   Date         |    Author     |   Notes
   -------------|---------------|-----------------------------------------------------------------------------------
   18.02.2015   |    MacDon/KP  |   file created\n
   24.05.2018   |    MacDon/BZ  |   Add EEPROM CRC checking.  Changes can be seen in version_history.txt
   17.12.2018   |    MacDon/BZ  |   Updated to final field test release.  Changes can be seen in version_history.txt

   \ingroup   eeprom
*/
/******************************************************************************/


#ifndef EEPROM_MAPPING_H_DEFINED
#define EEPROM_MAPPING_H_DEFINED

#include "stwtypes.h"
#include "general.h"
//#include "x_ssv.h"


//----------------------------------------------------------------------------------------------------------
/*!
    \brief      EEPROM address/size definition
    \ingroup    eeprom
    \defgroup   eepromAd EEPROM address/size
    @{
*/
#define EE_APP_BASE_ADDR    0
#define EE_SECTION_SIZE         32 // define a section is 32 bytes for CRC purpose. A page is 64 bytes.

#if defined(CONTROLLER_3CS)
#define EE_TOTAL_SIZE           24576 //0x6000 = 24KB for 3CM// find out by EEPROM status check x_eep_get_status()
#endif // CONTROLLER_3CS

#define EE_MAX_SECTION_NUM      (EE_TOTAL_SIZE / EE_SECTION_SIZE) //should be 768 for STW 3CM/3CS
#define EE_SECTION_DATA_SIZE    30 // 30 bytes to store data. 2 bytes for CRC result
#define EE_CRC_SIZE             2 // 2 bytes
#define EE_CRC_SEED 0xFFFF
/*! @} */





//-----------------------------------------
//union structure of EE data
//----------------------------------------
#define EE_ERROR_CODE_MAX_NUM   10 //max number of code could be stored. Don't be larger than 14 because the section size is 30
typedef union
{
    struct
    {
        //error code
        uint8 au8_errorGroup[EE_ERROR_CODE_MAX_NUM];
        uint8 au8_errorNumber[EE_ERROR_CODE_MAX_NUM];
        uint8 u8_indexOfError;
    } t_ee_data; //all are error data
    uint8 au8_sectionData[EE_SECTION_DATA_SIZE];//same in every section union
} EE_section_0_t;
//extern EE_section_0_t gu_ee_section_0;
#define EE_SECTION_0_BASE_ADDR       (EE_APP_BASE_ADDR + EE_SECTION_SIZE * 0)

//-------------------------------------
typedef union
{
    struct
    {
        uint8  sample_1;              //1 byte
        uint16 sample_2;
    } t_ee_data;
    uint8 au8_sectionData[EE_SECTION_DATA_SIZE];//same in every section union
} EE_section_1_t;
//extern EE_section_1_t gu_ee_section_1;
#define EE_SECTION_1_BASE_ADDR       (EE_APP_BASE_ADDR + EE_SECTION_SIZE * 1)

//-------------------------------------
typedef union
{
    struct
    {
        //system supervisor //2018-05-24 bzhou: 8 bytes
        uint16 u16_SSVConfig_WDmin;
        uint16 u16_SSVConfig_WDmax;
        uint8  u8_SSVConfig_UEmin;
        uint8  u8_SSVConfig_UEmax;
        uint8  u8_SSVConfig_RelOff;
        uint8  u8_SSVConfig_Reset;
    } t_ee_data;
    uint8 au8_sectionData[EE_SECTION_DATA_SIZE];//same in every section union
} EE_section_2_t;
//extern EE_section_2_t gu_ee_section_2;
#define EE_SECTION_2_BASE_ADDR       (EE_APP_BASE_ADDR + EE_SECTION_SIZE * 2)


//------------------------------------NVStorage.c--------------------------------------

extern EE_section_0_t gu_ee_section_0;
extern EE_section_1_t gu_ee_section_1;
extern EE_section_2_t gu_ee_section_2;


//------------------------------------NVStorage.c--------------------------------------
/*!
    \brief      EEPROM data loading and saving operation
    \ingroup    eeprom
    \defgroup   eepromOp EEPROM operation
    @{
*/
boolean GetEEDataInit(const uint32 ou32_SectionBaseAddr,  uint8* const opau8_sectionData, const boolean oq_CRCRequired);
void putEEdata(const uint32 ou32_SectionBaseAddr, uint8* const opau8_sectionData, const boolean oq_CRCRequired);
/*! @} */





#endif  //EEPROM_MAPPING_H_DEFINED







