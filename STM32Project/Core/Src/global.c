#include "global.h"

void initialize_variable() {
	// Variable for function mode1_normal()
	red_timer = 5;
	green_timer = 3;
	yellow_timer = 2;
	counter = red_timer + green_timer + yellow_timer;
	display_1 = 0;
	display_2 = 0;
	counter_mode1 = 100;

	// Variable for display mode and value
	index_mode = 0;
	TIMER_CYCLE = 10;
}

