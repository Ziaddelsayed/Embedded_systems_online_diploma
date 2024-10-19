#include "Alarm_monitor.h"
extern void (*alarm_state)();


 void High_Pressure_Detected()
 {
    alarm_state=STATE(Alarm_monitor_on);
 }

STATE_define(Alarm_monitor_waiting)
{
    Alarm_monitor_id=Alarm_monitor_waiting;

}
STATE_define(Alarm_monitor_off)
{
    Alarm_monitor_id=Alarm_monitor_off;
    StopAlarm();

    alarm_state=STATE(Alarm_monitor_waiting);

}
STATE_define(Alarm_monitor_on)
{
    Alarm_monitor_id=Alarm_monitor_on;
    StartAlarm();
    Delay(50000);
    StopAlarm();
    alarm_state=STATE(Alarm_monitor_waiting);

}