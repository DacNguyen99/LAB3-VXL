#include "led_display.h"
#include "main.h"
#include "global.h"

void clearLED() {
	HAL_GPIO_WritePin(GPIOB, LED7_0_Pin | LED7_1_Pin | LED7_2_Pin| LED7_3_Pin | LED7_4_Pin | LED7_5_Pin | LED7_6_Pin, 1) ;
	HAL_GPIO_WritePin(GPIOB, LED7_00_Pin | LED7_11_Pin | LED7_22_Pin | LED7_33_Pin | LED7_44_Pin | LED7_55_Pin | LED7_66_Pin, 1);
	HAL_GPIO_WritePin(GPIOA, RED_1_Pin | YELLOW_1_Pin | GREEN_1_Pin | RED_2_Pin | YELLOW_2_Pin | GREEN_2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, EN_MODE_00_Pin | EN_MODE_11_Pin | EN_VALUE_0_Pin | EN_VALUE_1_Pin, GPIO_PIN_RESET);
}

void display7SEG_VALUE(int num) {
	switch (num) {
	case 0:
		HAL_GPIO_WritePin(GPIOB, LED7_0_Pin | LED7_1_Pin | LED7_2_Pin | LED7_3_Pin | LED7_4_Pin | LED7_5_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, LED7_6_Pin, GPIO_PIN_SET);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOB, LED7_1_Pin | LED7_2_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, LED7_0_Pin | LED7_3_Pin | LED7_4_Pin | LED7_5_Pin | LED7_6_Pin, 1);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOB, LED7_0_Pin | LED7_1_Pin | LED7_3_Pin | LED7_4_Pin | LED7_6_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, LED7_2_Pin | LED7_5_Pin, GPIO_PIN_SET);
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOB, LED7_0_Pin | LED7_1_Pin | LED7_2_Pin | LED7_3_Pin | LED7_6_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, LED7_4_Pin | LED7_5_Pin, GPIO_PIN_SET);
		break;
	case 4:
		HAL_GPIO_WritePin(GPIOB, LED7_1_Pin | LED7_2_Pin | LED7_5_Pin | LED7_6_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, LED7_0_Pin | LED7_3_Pin | LED7_4_Pin, GPIO_PIN_SET);
		break;
	case 5:
		HAL_GPIO_WritePin(GPIOB, LED7_0_Pin | LED7_2_Pin | LED7_3_Pin | LED7_5_Pin | LED7_6_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, LED7_1_Pin | LED7_4_Pin ,GPIO_PIN_SET);
		break;
	case 6:
		HAL_GPIO_WritePin(GPIOB, LED7_0_Pin | LED7_2_Pin | LED7_3_Pin | LED7_4_Pin | LED7_5_Pin | LED7_6_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, LED7_1_Pin, GPIO_PIN_SET);
		break;
	case 7:
		HAL_GPIO_WritePin ( GPIOB , LED7_0_Pin | LED7_1_Pin | LED7_2_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( GPIOB , LED7_3_Pin | LED7_4_Pin | LED7_5_Pin | LED7_6_Pin , GPIO_PIN_SET ) ;
		break ;
	case 8:
		HAL_GPIO_WritePin ( GPIOB , LED7_0_Pin | LED7_1_Pin | LED7_2_Pin | LED7_3_Pin | LED7_4_Pin | LED7_5_Pin | LED7_6_Pin ,GPIO_PIN_RESET ) ;
		break ;
	case 9:
		HAL_GPIO_WritePin ( GPIOB , LED7_0_Pin | LED7_1_Pin | LED7_2_Pin | LED7_3_Pin | LED7_5_Pin | LED7_6_Pin ,GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( GPIOB , LED7_4_Pin , GPIO_PIN_SET ) ;
		break ;
	}
}

void display7SEG_MODE (int num ) {
	switch ( num ) {
	case 0:
		HAL_GPIO_WritePin ( GPIOB , LED7_00_Pin | LED7_11_Pin | LED7_22_Pin | LED7_33_Pin | LED7_44_Pin | LED7_55_Pin ,GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( GPIOB , LED7_66_Pin , GPIO_PIN_SET ) ;
		break ;
	case 1:
		HAL_GPIO_WritePin ( GPIOB , LED7_11_Pin | LED7_22_Pin ,GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( GPIOB , LED7_00_Pin | LED7_33_Pin |LED7_44_Pin | LED7_55_Pin | LED7_66_Pin , GPIO_PIN_SET ) ;
		break ;
	case 2:
		HAL_GPIO_WritePin ( GPIOB , LED7_00_Pin | LED7_11_Pin | LED7_33_Pin | LED7_44_Pin | LED7_66_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( GPIOB , LED7_22_Pin | LED7_55_Pin ,GPIO_PIN_SET ) ;
		break ;
	case 3:
		HAL_GPIO_WritePin ( GPIOB , LED7_00_Pin | LED7_11_Pin |LED7_22_Pin | LED7_33_Pin | LED7_66_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( GPIOB , LED7_44_Pin | LED7_55_Pin , GPIO_PIN_SET ) ;
		break ;
	case 4:
		HAL_GPIO_WritePin ( GPIOB , LED7_11_Pin | LED7_22_Pin | LED7_55_Pin | LED7_66_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( GPIOB , LED7_00_Pin | LED7_33_Pin | LED7_44_Pin , GPIO_PIN_SET ) ;
		break ;
	case 5:
		HAL_GPIO_WritePin ( GPIOB , LED7_00_Pin | LED7_22_Pin | LED7_33_Pin | LED7_55_Pin | LED7_66_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( GPIOB , LED7_11_Pin | LED7_44_Pin , GPIO_PIN_SET ) ;
		break ;
	case 6:
		HAL_GPIO_WritePin ( GPIOB , LED7_00_Pin | LED7_22_Pin | LED7_33_Pin | LED7_44_Pin | LED7_55_Pin | LED7_66_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( GPIOB , LED7_11_Pin , GPIO_PIN_SET ) ;
		break ;
	case 7:
		HAL_GPIO_WritePin ( GPIOB , LED7_00_Pin | LED7_11_Pin | LED7_22_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( GPIOB , LED7_33_Pin | LED7_44_Pin | LED7_55_Pin | LED7_66_Pin , GPIO_PIN_SET ) ;
		break ;
	case 8:
		HAL_GPIO_WritePin ( GPIOB , LED7_00_Pin | LED7_11_Pin | LED7_22_Pin | LED7_33_Pin | LED7_44_Pin | LED7_55_Pin | LED7_66_Pin , GPIO_PIN_RESET ) ;
		break ;
	case 9:
		HAL_GPIO_WritePin ( GPIOB , LED7_00_Pin | LED7_11_Pin | LED7_22_Pin | LED7_33_Pin | LED7_55_Pin | LED7_66_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( GPIOB , LED7_44_Pin , GPIO_PIN_SET ) ;
		break ;
	}
}


// LED 7 SEG - MODE
// Display Mode LED
void update7SEG_MODE (int index , int value ) {
	int donvi = value % 10;
	int chuc = value / 10;
	switch ( index ) {
		case 0:
		// Display the first 7 SEG - MODE with value = 0
			HAL_GPIO_WritePin ( EN_MODE_00_GPIO_Port , EN_MODE_00_Pin ,0) ;
			HAL_GPIO_WritePin ( EN_MODE_11_GPIO_Port , EN_MODE_11_Pin ,1) ;
			display7SEG_MODE ( chuc );
			break ;
		case 1:
		// Display the second 7 SEG - MODE with value parameters
			HAL_GPIO_WritePin ( EN_MODE_00_GPIO_Port , EN_MODE_00_Pin ,1) ;
			HAL_GPIO_WritePin ( EN_MODE_11_GPIO_Port , EN_MODE_11_Pin ,0) ;
			display7SEG_MODE ( donvi ) ;
			break ;
		default :
			break ;
		}
}

// LED 7 SEG - VALUE
// Display Value LED
void update7SEG_VALUE (int index , int value ) {
	int donvi = value % 10;
	int chuc = value / 10;
	switch ( index ) {
		case 0:
		// Display the first 7 SEG - MODE with value = 0
			HAL_GPIO_WritePin ( EN_VALUE_0_GPIO_Port , EN_VALUE_0_Pin ,0) ;
			HAL_GPIO_WritePin ( EN_VALUE_1_GPIO_Port , EN_VALUE_1_Pin ,1) ;
			display7SEG_VALUE ( chuc ) ;
			break ;
		case 1:
		// Display the second 7 SEG - MODE with value parameters
			HAL_GPIO_WritePin ( EN_VALUE_0_GPIO_Port , EN_VALUE_0_Pin ,1) ;
			HAL_GPIO_WritePin ( EN_VALUE_1_GPIO_Port , EN_VALUE_1_Pin ,0) ;
			display7SEG_VALUE ( donvi ) ;
			break ;
		default :
			break ;
		}
}

// MODE_1 Normal
// Variable is initialized in global .c
void mode1_normal () {
	if( counter_mode1 == 0) {
		counter_mode1 = 100;
		if( counter == red_timer + green_timer + yellow_timer ) {
		// Led 1 RED
			display_1 = red_timer ;
			HAL_GPIO_WritePin ( RED_1_GPIO_Port , RED_1_Pin ,GPIO_PIN_RESET ) ;
			HAL_GPIO_WritePin ( YELLOW_1_GPIO_Port , YELLOW_1_Pin ,GPIO_PIN_SET ) ;
			HAL_GPIO_WritePin ( GREEN_1_GPIO_Port , GREEN_1_Pin ,GPIO_PIN_SET ) ;
		// Led 2 GREEN
			display_2 = green_timer ;
			HAL_GPIO_WritePin ( RED_2_GPIO_Port , RED_2_Pin ,GPIO_PIN_SET ) ;
			HAL_GPIO_WritePin ( YELLOW_2_GPIO_Port , YELLOW_2_Pin ,GPIO_PIN_SET ) ;
			HAL_GPIO_WritePin ( GREEN_2_GPIO_Port , GREEN_2_Pin ,GPIO_PIN_RESET ) ;
		}
		if( counter == ( red_timer + yellow_timer ) ) {
		// Led 2 YELLOW
			display_2 = yellow_timer ;
			HAL_GPIO_WritePin ( RED_2_GPIO_Port , RED_2_Pin ,GPIO_PIN_SET ) ;
			HAL_GPIO_WritePin ( YELLOW_2_GPIO_Port , YELLOW_2_Pin ,GPIO_PIN_RESET ) ;
			HAL_GPIO_WritePin ( GREEN_2_GPIO_Port , GREEN_2_Pin ,GPIO_PIN_SET ) ;
		}
		if ( counter == ( yellow_timer + green_timer ) ) {
		// Led 1 GREEN
			display_1 = green_timer ;
			HAL_GPIO_WritePin ( RED_1_GPIO_Port , RED_1_Pin ,GPIO_PIN_SET ) ;
			HAL_GPIO_WritePin ( YELLOW_1_GPIO_Port , YELLOW_1_Pin ,GPIO_PIN_SET ) ;
			HAL_GPIO_WritePin ( GREEN_1_GPIO_Port , GREEN_1_Pin ,GPIO_PIN_RESET ) ;
		}
		if ( counter == red_timer ) {
		// Led 2 RED
			display_2 = red_timer ;
			HAL_GPIO_WritePin ( RED_2_GPIO_Port , RED_2_Pin ,GPIO_PIN_RESET ) ;
			HAL_GPIO_WritePin ( YELLOW_2_GPIO_Port , YELLOW_2_Pin ,GPIO_PIN_SET ) ;
			HAL_GPIO_WritePin ( GREEN_2_GPIO_Port , GREEN_2_Pin ,GPIO_PIN_SET ) ;
		}
		if ( counter == yellow_timer ) {
		// Led 1 YELLOW
			display_1 = yellow_timer ;
			HAL_GPIO_WritePin ( RED_1_GPIO_Port , RED_1_Pin ,GPIO_PIN_SET ) ;
			HAL_GPIO_WritePin ( YELLOW_1_GPIO_Port , YELLOW_1_Pin ,GPIO_PIN_RESET ) ;
			HAL_GPIO_WritePin ( GREEN_1_GPIO_Port , GREEN_1_Pin ,GPIO_PIN_SET ) ;
		}
		display_1--;
		display_2--;
		counter--;
		if( counter == 0)
			counter = red_timer + green_timer + yellow_timer ;
	}

	if( counter_mode1 == 100 || counter_mode1 == 50) {
		update7SEG_VALUE ( index_mode , display_1 + 1) ;
		update7SEG_MODE ( index_mode , display_2 + 1) ;
		index_mode++;
		if( index_mode >= 2)
			index_mode = 0;
	}
	counter_mode1--;
}
