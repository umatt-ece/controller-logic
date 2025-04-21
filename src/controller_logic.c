/*******************************************************************************/
/*!
    \file controller_logic.c
    \brief Implementation of the controller_logic.c

    Project     Controller Logic\n
    Copyright   UMATT 2025\n
    License     Use only under the terms of the contract / confidential\n

    Date (YYYY/MM/DD) |   Author       |   Changes
    ------------------|----------------|----------------
    2025/04/19       |   Bruce Niemi  | File created
 */
/*******************************************************************************/

#include "controller_logic.h"

#include <stdlib.h>

static const controller_logic_settings_t *controller_settings = NULL;

controller_logic_error_t controller_logic_init(
    const controller_logic_settings_t *settings) {
  if (settings == NULL) {
    return CONTROLLER_LOGIC_INVALID_SETTINGS;
  }

  controller_settings = settings;

  return CONTROLLER_LOGIC_OK;
}

void controller_logic_run(void) {
  if (controller_settings == NULL) {
    return;
  }
}
