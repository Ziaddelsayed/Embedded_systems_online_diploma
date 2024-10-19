#ifndef PSENSOR_H_
#define PSENSOR_H_
#include "state.h"

enum{
    psensor_waiting,
    psensor_reading
}psensor_id;

void (*psensor_state)();
STATE_define(psensor_waiting);
STATE_define(psensor_reading);
void psensor_init();



 #endif