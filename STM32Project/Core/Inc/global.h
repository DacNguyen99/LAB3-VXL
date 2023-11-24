#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

int timer_MODE_counter;
int timer_MODE_flag;
int TIMER_CYCLE;
int timer_VALUE_counter;
int timer_VALUE_flag;
int counter_mode1;

// Variable for function Mode1_normal
int red_timer;
int green_timer;
int yellow_timer;
int counter;
int display_1;
int display_2;

// Variable for display mode and value
int index_mode;

// Variable for value of led when press button 2
int red_temp;
int yellow_temp;
int green_temp;

void initialize_variable() ;
#endif /* INC_GLOBAL_H_ */
