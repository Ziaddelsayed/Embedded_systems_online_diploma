#ifndef ALARM_MONITOR_H_
#define ALARM_MONITOR_H_
#include "state.h"

void (*alarm_state)();
enum{
    Alarm_monitor_waiting,
    Alarm_monitor_off,
    Alarm_monitor_on
}Alarm_monitor_id;

STATE_define(Alarm_monitor_waiting);
STATE_define(Alarm_monitor_off);
STATE_define(Alarm_monitor_on);










#endif