#include "joystick.h"

#include <stdio.h>
#include <stdlib.h>

bool joystick_in_dead_zone(joystick_t *joystick, uint16_t dead_zone) {
  if (joystick == NULL) {
    return false;
  }

  int16_t delta = joystick->current_position - JOYSTICK_CENTER_POSITION;

  return abs(delta) <= dead_zone;
}
