/*******************************************************************************/
/*!
    \file controller_logic_context.c
    \brief Implementation of the controller_logic_context.c

    Project     Controller Logic\n
    Copyright   UMATT 2025\n
    License     Use only under the terms of the contract / confidential\n

    Date (YYYY/MM/DD) |   Author       |   Changes
    ------------------|----------------|----------------
    2025/04/22       |   Bruce Niemi  | File created
 */
/*******************************************************************************/

#include "controller_logic_context.h"

#include <stdlib.h>

void controller_logic_context_init(controller_logic_context_t *context) {
  if (context == NULL) {
    return;
  }

  context->seat_pressed = false;
}
