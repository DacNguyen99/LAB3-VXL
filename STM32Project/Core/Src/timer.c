#include "timer.h"

#include "main.h"
#include "global.h"
#include "input_reading.h"

void setTimer_MODE ( int duration ){
	timer_MODE_counter = duration / TIMER_CYCLE ;
	timer_MODE_flag = 0;
}

void setTimer_VALUE (int duration ) {
	timer_VALUE_counter = duration / TIMER_CYCLE ;
	timer_VALUE_flag = 0;
}

void timer_run () {
	if( timer_MODE_counter > 0) {
		timer_MODE_counter--;
		if( timer_MODE_counter == 0) timer_MODE_flag = 1;
	}
	if( timer_VALUE_counter > 0) {
		timer_VALUE_counter--;
		if( timer_VALUE_counter == 0) timer_VALUE_flag = 1;
	}
}

