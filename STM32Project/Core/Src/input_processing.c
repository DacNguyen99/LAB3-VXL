#include "input_processing.h"

#include "main.h"
#include "global.h"
#include "input_reading.h"
#include "led_display.h"
#include "timer.h"

enum ButtonState { STATE_1 = 0 , STATE_2 = 1 , STATE_3 = 2 , STATE_4 = 3} ;
enum ButtonState buttonState = STATE_1 ;
enum ButtonIndex { PRESS_BUTTON_1 = 0 , PRESS_BUTTON_2 = 1 , PRESS_BUTTON_3 = 2};

void fsm_for_input_processing ( void ) {
	switch ( buttonState ){
		case STATE_1 :
			// Display the traffic light application is running normally
			mode1_normal () ;
			// When button 1 is pressed , go to the next state
			if( is_button_pressed ( PRESS_BUTTON_1 ) == 1) {
				clearLED () ;
				buttonState = STATE_2 ;
				red_temp = red_timer ;
			}
			break ;
		case STATE_2 :
			// Display 2 red LEDS , LED7 - SEG for mode and LED7_SEG for value
			HAL_GPIO_WritePin ( GPIOA , RED_1_Pin | RED_2_Pin , GPIO_PIN_RESET ) ;
			if( timer_MODE_flag == 1) {
				update7SEG_VALUE ( index_mode , red_temp ) ;
				update7SEG_MODE ( index_mode , 2) ;
				index_mode ++;
			}
			// When button 2 is pressed , red light value temporarily increased by 1 in a range of 1 -99
			if( is_button_pressed ( PRESS_BUTTON_2 ) == 1) {
				red_temp += 1;
			}
			// When button 3 is pressed , set temporary red light value to red light value
			if( is_button_pressed ( PRESS_BUTTON_3 ) == 1) {
				red_timer = red_temp ;
			}
			// When button 1 is pressed , go to the next state
			if( is_button_pressed ( PRESS_BUTTON_1 ) == 1) {
				clearLED () ;
				buttonState = STATE_3 ;
				yellow_temp = yellow_timer ;
			}
			break ;
		case STATE_3 :
			// Display 2 yellow LEDS , LED7 - SEG for mode and LED7_SEG for value
			HAL_GPIO_WritePin ( GPIOA , YELLOW_1_Pin | YELLOW_2_Pin , GPIO_PIN_RESET ) ;
			if( timer_MODE_flag == 1) {
				update7SEG_VALUE ( index_mode , yellow_temp ) ;
				update7SEG_MODE ( index_mode , 3) ;
				index_mode ++;
			}
			// When button 2 is pressed , yellow light value temporarily increased by 1 in a range of 1 -99
			if( is_button_pressed ( PRESS_BUTTON_2 ) == 1) {
				yellow_temp += 1;
			}
			// When button 3 is pressed , set temporary yellow light value to yellow light value
			if( is_button_pressed ( PRESS_BUTTON_3 ) == 1) {
				yellow_timer = yellow_temp ;
			}
			// When button 1 is pressed , go to the next state
			if( is_button_pressed ( PRESS_BUTTON_1 ) == 1) {
				clearLED () ;
				buttonState = STATE_4 ;
				green_temp = green_timer ;
			}
			break ;
		case STATE_4 :
			// Display 2 green LEDS , LED7 - SEG for mode and LED7_SEG for value
			HAL_GPIO_WritePin ( GPIOA , GREEN_1_Pin | GREEN_2_Pin , GPIO_PIN_RESET ) ;
			if( timer_MODE_flag == 1) {
				update7SEG_VALUE ( index_mode , green_temp ) ;
				update7SEG_MODE ( index_mode , 4) ;
				index_mode ++;
			}
			// When button 2 is pressed , green light valu temporarily increased by 1 in a range of 1 -99
			if( is_button_pressed ( PRESS_BUTTON_2 ) == 1) {
				green_temp += 1;
			}
			// When button 3 is pressed , set temporary green light value to green light value
			if( is_button_pressed ( PRESS_BUTTON_3 ) == 1) {
				green_timer = green_temp ;
			}
			// When button 1 is pressed , go to the next state
			if( is_button_pressed ( PRESS_BUTTON_1 ) == 1) {
				clearLED () ;
				buttonState = STATE_1 ;
			}
			break ;
		default :
			break ;
	}
}
