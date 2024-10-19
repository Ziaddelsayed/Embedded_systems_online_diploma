#include "state.h"
#include "Psensor.h"
#include "MainAlg.h"
#include "Alarm_monitor.h"
#include "Actuator_driver.h"


void setup()
{
    //init all the sensors 
    psensor_init();
    Actuator_init();

    //set states pointer for each block 
    psensor_state=STATE(psensor_waiting);
    main_state=STATE(mainAlg_receiving);
    alarm_state=STATE(Alarm_monitor_waiting);
    acuator_state=STATE(Actuator_off);
    StopAlarm();
}

void main()
{
    setup();
    while(1)
    {
        psensor_state();   // Call  pressure sensor state function
        main_state();       //call the MainAlg state function
        alarm_state();      // Call alarm state function
        acuator_state();    //call the actuator driver
        
    }

}