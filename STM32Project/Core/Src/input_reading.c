#include "input_reading.h"

#include "main.h"

// we aim to work with more than one buttons
#define N0_OF_BUTTONS 3
#define DURATION_FOR_AUTO_INCREASING 100
// i = 0 => BUTTON_1 ; i = 1 = > BUTTON_2 ; i = 2 = > BUTTON_3 ;
#define BUTTON_IS_PRESSED GPIO_PIN_RESET
#define BUTTON_IS_RELEASED GPIO_PIN_SET
// the buffer that the final result is stored after debouncing
static GPIO_PinState buttonBuffer [ N0_OF_BUTTONS ];
// we define two buffers for debouncing
static GPIO_PinState debounceButtonBuffer1 [ N0_OF_BUTTONS ];
static GPIO_PinState debounceButtonBuffer2 [ N0_OF_BUTTONS ];
// we define counter for checking the button is pressed
static uint16_t counterForButtonPress [ N0_OF_BUTTONS ];
void clear_button () {
	for (int i = 0; i < N0_OF_BUTTONS ; i ++) {
		debounceButtonBuffer1 [ i ] = GPIO_PIN_SET ; // No press
		debounceButtonBuffer2 [ i ] = GPIO_PIN_SET ; // No press
		buttonBuffer [ i] = GPIO_PIN_SET ; // No press
	}
	HAL_GPIO_WritePin ( BUTTON_1_GPIO_Port , BUTTON_1_Pin , 1) ;
	HAL_GPIO_WritePin ( BUTTON_2_GPIO_Port , BUTTON_2_Pin , 1) ;
	HAL_GPIO_WritePin ( BUTTON_3_GPIO_Port , BUTTON_3_Pin , 1) ;
}

void button_reading ( void ) {
	for (int i = 0; i < N0_OF_BUTTONS ; i ++) {
		debounceButtonBuffer2 [ i ] = debounceButtonBuffer1 [ i ];
		// Catch signal every time the corresponding button is pressed
		if(i == 0)
			debounceButtonBuffer1 [ i ] = HAL_GPIO_ReadPin ( BUTTON_1_GPIO_Port , BUTTON_1_Pin ) ;
		else if ( i == 1)
			debounceButtonBuffer1 [ i ] = HAL_GPIO_ReadPin ( BUTTON_2_GPIO_Port , BUTTON_2_Pin ) ;
		else if ( i == 2)
			debounceButtonBuffer1 [ i ] = HAL_GPIO_ReadPin ( BUTTON_3_GPIO_Port , BUTTON_3_Pin ) ;

		if( debounceButtonBuffer1 [ i ] == debounceButtonBuffer2 [ i ]) {
			buttonBuffer [ i ] = debounceButtonBuffer1 [ i ];
			if( buttonBuffer [ i ] == BUTTON_IS_PRESSED ) {
				// If a button is pressed , we start counting
				if( counterForButtonPress [ i ] < DURATION_FOR_AUTO_INCREASING ) {
					counterForButtonPress [ i ]++;
				}
			} else {
				counterForButtonPress [ i ] = 0;
			}
		}
	}
}

unsigned char is_button_pressed ( uint8_t index ) {
	if( index >= N0_OF_BUTTONS ) return 0;
	if ( buttonBuffer [ index ] == BUTTON_IS_PRESSED ) {
		return counterForButtonPress [ index ];
	}
	return 0;
}
