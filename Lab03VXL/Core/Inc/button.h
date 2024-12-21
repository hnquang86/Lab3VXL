/*
 * button.h
 *
 *  Created on: Oct 31, 2024
 *      Author: Admin
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_
#include "main.h"



#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

#define BUTTON 10
#define TIME_INTO_LONG_PRESS 200		//3 second
#define CYCLE_LONG_PRESS 50				// 500 ms


void get_input_button(uint8_t index, GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
uint8_t get_pressed_flag(uint8_t index);
void set_pressed_flag(uint8_t index);
void getInputKey();

#endif /* INC_BUTTON_H_ */
