#ifndef MAINALG_H_
#define MAINALG_H_
#include "state.h"

enum{
    mainAlg_receiving
}mainAlg_id;

void (*main_state)();
STATE_define(mainAlg_receiving);











#endif