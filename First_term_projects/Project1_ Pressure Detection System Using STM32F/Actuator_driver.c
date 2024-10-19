#include "Actuator_driver.h"

extern void (*acuator_state)();

void Actuator_init()
{
        GPIO_INITIALIZATION ();
}

 void StartAlarm()
 {
    Set_Alarm_actuator(0);
    acuator_state=STATE(Actuator_on);

 }
 void StopAlarm()
 {
    Set_Alarm_actuator(1);
    acuator_state=STATE(Actuator_off);
 }

STATE_define(Actuator_waiting)
{
    Actuator_id=Actuator_waiting;
    


}
STATE_define(Actuator_off)
{
    Actuator_id=Actuator_off;
    acuator_state=STATE(Actuator_waiting);

}
STATE_define(Actuator_on)
{
    Actuator_id=Actuator_on;
    acuator_state=STATE(Actuator_waiting);

}