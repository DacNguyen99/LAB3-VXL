#ifndef INC_LED_DISPLAY_H_
#define INC_LED_DISPLAY_H_

void display7SEG_VALUE(int num);
void display7SEG_MODE(int num);
void update7SEG_MODE(int index, int value);
void update7SEG_VALUE(int index, int value);
void mode1_normal();
void clearLED();

#endif /* INC_LED_DISPLAY_H_ */
