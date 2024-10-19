#ifndef ACTUATOR_DRIVER_H_
#define ACTUATOR_DRIVER_H_

#include "state.h"

void (*acuator_state)();
enum{
    Actuator_waiting,
    Actuator_off,
    Actuator_on
}Actuator_id;

STATE_define(Actuator_waiting);
STATE_define(Actuator_off);
STATE_define(Actuator_on);

void Actuator_init();








#endif