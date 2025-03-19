/******************************************************************************/
/*!
    \file
        user_parameters.c

    \defgroup
        can CAN

    \brief
        Application-specific file to define each parameter necessary for the logic layer.

    \ingroup
        can

    \copyright
        Copyright (C) 2025  University of Manitoba Association of Tiny Tractors  All Rights Reserved.
        License   use only under terms of contract / confidential\n

    History:

    Date (YYYY/MM/DD) |   Author            |   Changes
    ------------------|---------------------|----------------
    2025/03/19        | Zachary DeGraeve    | File Created
*/
/******************************************************************************/

/*******************************************************************************
  INCLUDE
*******************************************************************************/
// include platform configuration
#include "platform_config.h"

#include "user_parameters.h"

/*******************************************************************************
  DEFINES
*******************************************************************************/

/*******************************************************************************
  MACROS
*******************************************************************************/

/*******************************************************************************
  ENUMS
*******************************************************************************/

/*******************************************************************************
  STRUCTS
*******************************************************************************/

/*******************************************************************************
  CONSTANTS
*******************************************************************************/

/*******************************************************************************
  VARIABLES
*******************************************************************************/
// Sample SPN for J1939 Tx messages
static uint32_t u32_spn_sample_tx_parameter = 0xFFFFFFFF;

// Sample SPN for J1939 Rx messages
static uint32_t u32_spn_sample_rx_parameter = 0xFFFFFFFF;

/*******************************************************************************
  EXTERNS
*******************************************************************************/

/*******************************************************************************
  PROTOTYPES
*******************************************************************************/

/*******************************************************************************
  FUNCTIONS
*******************************************************************************/

/******************************************************************************/
/*!
   \fn       void set_spn_u32_sample_tx_parameter( uint32_t new_value )
   \brief    This function sets the J1939 Tx SPN XXXXXX to the new value.
   \param    uint32_t new_value: The new value to set SPN XXXXXX to.
   \return   None.

    @{
*/
/******************************************************************************/
void set_spn_u32_sample_tx_parameter( uint32_t new_value )
{
    u32_spn_sample_tx_parameter = new_value;
}
/*! @} */

/******************************************************************************/
/*!
   \fn       uint32_t get_spn_u32_sample_tx_parameter( void )
   \brief    This function gets the value of the J1939 Tx SPN XXXXXX.
   \param    None.
   \return   The current value of SPN XXXXXX.
   \retval   uint32_t

    @{
*/
/******************************************************************************/
uint32_t get_spn_u32_sample_tx_parameter( void )
{
    return( u32_spn_sample_tx_parameter );
}
/*! @} */

/******************************************************************************/
/*!
   \fn       void set_spn_u32_sample_rx_parameter( uint32_t new_value )
   \brief    This function sets the J1939 Rx SPN XXXXXX to the new value.
   \param    uint32_t new_value: The new value to set SPN XXXXXX to.
   \return   None.

    @{
*/
/******************************************************************************/
void set_spn_u32_sample_rx_parameter( uint32_t new_value )
{
    u32_spn_sample_rx_parameter = new_value;
}
/*! @} */

/******************************************************************************/
/*!
   \fn       uint32_t get_spn_u32_sample_rx_parameter( void )
   \brief    This function gets the value of the J1939 Rx SPN XXXXXX.
   \param    None.
   \return   The current value of SPN XXXXXX.
   \retval   uint32_t

    @{
*/
/******************************************************************************/
uint32_t get_spn_u32_sample_rx_parameter( void )
{
    return( u32_spn_sample_rx_parameter );
}
/*! @} */