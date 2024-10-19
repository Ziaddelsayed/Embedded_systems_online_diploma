#include "MainAlg.h"

static int main_value=0;
static int threshold =20;
extern void (*main_state)();


void pressure_value(int pval)
{
    main_value=pval;


}

STATE_define(mainAlg_receiving)
{
    mainAlg_id=mainAlg_receiving;
    if(threshold>20)
    {
        High_Pressure_Detected();
    }
    Delay(5000);

    main_state=STATE(mainAlg_receiving);
}