/*******************************************************************************/
/*!
    \file controller_logic.h
    \brief Header file for the controller logic module.

    Project     Controller Logic\n
    Copyright   UMATT 2025\n
    License     Use only under the terms of the contract / confidential\n

    Date (YYYY/MM/DD) |   Author       |   Changes
    ------------------|----------------|----------------
    2025/04/19       |   Bruce Niemi  | File created
 */
/*******************************************************************************/

#ifndef CONTROLLER_LOGIC_H
#define CONTROLLER_LOGIC_H

#include "controller_logic_context.h"

typedef struct CONTROLLER_LOGIC_SETTINGS {
  int dummy_value;  // Placeholder for actual settings
} controller_logic_settings_t;

typedef enum CONTROLLER_LOGIC_ERROR {
  CONTROLLER_LOGIC_OK = 0,                 // No error
  CONTROLLER_LOGIC_INVALID_SETTINGS = -1,  // Invalid settings provided
} controller_logic_error_t;

/*******************************************************************************/
/*!
    \brief This function initializes the controller logic module. It sets up any
    necessary variables and prepares the module for use.

    \param settings A pointer to a controller_logic_settings structure that
    contains the settings for the controller logic module. This structure
    should be filled with the necessary values before calling this function.
    \param context A pointer to a controller_logic_context structure that will
    be used to store the context of the controller logic module. This structure
    should be allocated before calling this function.
    
    \return A controller_logic_error value indicating the success or failure of
   the initialization. If the function returns CONTROLLER_LOGIC_ERROR, it means
    that the initialization was not successful.
*/
/*******************************************************************************/
controller_logic_error_t controller_logic_init(
    const controller_logic_settings_t *settings,
    controller_logic_context_t *context);

/*******************************************************************************/
/*!
    \brief This function runs the main logic of the controller. It should be
    called in a loop to continuously update the controller's state.

    \return None
*/
/*******************************************************************************/
void controller_logic_run(void);

#endif  // CONTROLLER_LOGIC_H
