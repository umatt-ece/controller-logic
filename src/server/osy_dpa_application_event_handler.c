//----------------------------------------------------------------------------------------------------------------------
/*!
   \file
   \brief       openSYDE server: application event handler

   Provides functions for openSYDE application event handler.

   \copyright   Copyright 2018 Sensor-Technik Wiedemann GmbH. All rights reserved.
*/
//----------------------------------------------------------------------------------------------------------------------

/* -- Includes ------------------------------------------------------------------------------------------------------ */
#include "stwtypes.h"   // standard type definitions
#include "osy_dpa_application_event_handler_if.h" //this is the interface this module implements
#include "osy_dph_nvm_handler.h"  // access to NVM data pool functions

/* -- Defines ------------------------------------------------------------------------------------------------------- */

/* -- Types --------------------------------------------------------------------------------------------------------- */

/* -- Global Variables ---------------------------------------------------------------------------------------------- */

/* -- Module Global Variables --------------------------------------------------------------------------------------- */

/* -- Module Global Function Prototypes ----------------------------------------------------------------------------- */

/* -- Implementation ------------------------------------------------------------------------------------------------ */

//----------------------------------------------------------------------------------------------------------------------
/*! \brief   Handle notification about new value written to element

   Will be called by the communication driver after it has written a new value to a data pool element's RAM copy.

   Notes:
   The communication driver does not keep a lock on the data pool for the duration of this hook function.
   So if another thread also writes to the same data pool element it could have a different content by the time
    the hook function is executed.

   This function blocks the execution of the protocol driver. Keep execution time to a minimum.

   \param[in]    ou8_DataPoolIndex   index of data pool that was written to
   \param[in]    ou16_ListIndex      list that was written to
   \param[in]    ou16_ElementIndex   element that was written to
*/
//----------------------------------------------------------------------------------------------------------------------
void osy_app_write_event(const uint8 ou8_DataPoolIndex, const uint16 ou16_ListIndex, const uint16 ou16_ElementIndex)
{
   // PRQA S 3112 3  // avoid compiler warning for unused parameters
   (void)ou8_DataPoolIndex;
   (void)ou16_ListIndex;
   (void)ou16_ElementIndex;
}

//----------------------------------------------------------------------------------------------------------------------
/*! \brief   Handle notification about attempt to read from element

   Will be called by the communication driver before it reads from a data pool element.

   Notes:
   The communication driver does not keep a lock on the data pool for the duration of this hook function.
   So if another thread also writes to the same data pool element the value could be overwritten before it is
    reported back to the communication driver.

   This function blocks the execution of the protocol driver. Keep execution time to a minimum.

   \param[in]    ou8_DataPoolIndex   index of data pool that the driver wants to read from
   \param[in]    ou16_ListIndex      list that the driver wants to read from
   \param[in]    ou16_ElementIndex   element that the driver wants to read from

   \retval C_NO_ERR   let protocol driver know everything is all right
                      - driver will commence reading the data from the data pool
                      - driver will send an OK response with the data to client
   \retval else       inform diagnostic protocol about problem
                      - driver will send an error response to client
*/
//----------------------------------------------------------------------------------------------------------------------
sint16 osy_app_read_event(const uint8 ou8_DataPoolIndex, const uint16 ou16_ListIndex, const uint16 ou16_ElementIndex)
{
   // PRQA S 3112 3  // avoid compiler warning for unused parameters
   (void)ou8_DataPoolIndex;
   (void)ou16_ListIndex;
   (void)ou16_ElementIndex;

   // read event not evaluated; everything is ok
   return C_NO_ERR;
}

//----------------------------------------------------------------------------------------------------------------------
/*! \brief   Handle notification about attempt to write to element

   Will be called by the communication driver before it writes a new value to an element.
   This function can:
   - handle the writing itself (e.g. if the communication driver has no direct access to the RAM memory)
   - abort the writing procedure (through the return value)
   - let the communication driver process

   The calling function is responsible to pass a valid pointer for the pointer parameter.

   \param[in]    ou8_DataPoolIndex   index of data pool that the driver wants to write to
   \param[in]    ou16_ListIndex      list that the driver wants to write to
   \param[in]    ou16_ElementIndex   element that the driver wants to write to
   \param[in]    opv_Data            received data that is about to be written
   \param[in]    ou16_DataSizeBytes  size of opv_Data in bytes

   \retval C_NO_ERR   let protocol driver know everything is all right
                      - driver will commence writing the data to the data pool
                      - driver will send an OK response to client
   \retval C_WARN     let protocol driver know the write access was already handled
                      - driver will not write the data to the data pool
                      - driver will send an OK response to client
   \retval else       inform diagnostic protocol about problem
                      - driver will not write the data to the data pool
                      - driver will send an error response to client
*/
//----------------------------------------------------------------------------------------------------------------------
sint16 osy_app_pre_write_event(const uint8 ou8_DataPoolIndex, const uint16 ou16_ListIndex,
                               const uint16 ou16_ElementIndex, const void * const opv_Data,
                               const uint16 ou16_DataSizeBytes)
{
   // PRQA S 3112 5  // avoid compiler warning for unused parameters
   (void)ou8_DataPoolIndex;
   (void)ou16_ListIndex;
   (void)ou16_ElementIndex;
   (void)opv_Data;
   (void)ou16_DataSizeBytes;

   // write event not evaluated; everything is ok
   return C_NO_ERR;
}

//----------------------------------------------------------------------------------------------------------------------
/*! \brief   Handle notification about changed NVM content

   Will be called by the communication driver when it receives notification about changed NVM content.
   The application can then react according to its design, typically:
   Re-read values from NVM to RAM using the osy_dph_... functions when the application state permits this.

   \param[in]    ou8_DataPoolIndex   index of affected data pool
   \param[in]    ou16_ListIndex      affected list

   \retval C_NO_ERR   let protocol driver know everything is all right
                      - driver will send an OK response to client
   \retval else       inform diagnostic protocol about problem
                      - driver will send an error response to client
*/
//----------------------------------------------------------------------------------------------------------------------
sint16 osy_app_nvm_data_was_changed_event(const uint8 ou8_DataPoolIndex, const uint16 ou16_ListIndex)
{
   // update the RAM copy of the NVM data pool
   return osy_dph_nvm_read_list(ou8_DataPoolIndex, ou16_ListIndex);
}
