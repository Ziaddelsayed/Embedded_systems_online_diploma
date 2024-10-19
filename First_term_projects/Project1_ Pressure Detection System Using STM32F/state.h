#ifndef STATE_H_
#define STATE_H_

#include "stdio.h"
#include"stdlib.h"
#include "stdint.h"
#include "driver.h"

//to use it easliy (one for ceartion and the other for jump to it)
#define STATE_define(_stateFun_) int ST_##_stateFun_()
#define STATE(_stateFun_) ST_##_stateFun_()

// State connection
 void pressure_value(int pval);
 void High_Pressure_Detected();
 void StartAlarm();
 void StopAlarm();


 #endif