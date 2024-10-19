#include "psensor.h"
extern void (*psensor_state)();

static int Pval=0 ;
void psensor_init()
{
    GPIO_INITIALIZATION ();
}

STATE_define(psensor_waiting)
{
    psensor_id=psensor_waiting;
    Delay(5000);
    psensor_state=STATE(psensor_reading);

}
STATE_define(psensor_reading)
{
    psensor_id=psensor_reading;
    Pval = getPressureVal();
    pressure_value(Pval);
    psensor_state=STATE(psensor_waiting);

}
