/*
 * traffic_light.h
 *
 *  Created on: Oct 31, 2024
 *      Author: Admin
 */

#ifndef INC_TRAFFIC_LIGHT_H_
#define INC_TRAFFIC_LIGHT_H_
#include "main.h"

#define ON	GPIO_PIN_SET
#define OFF GPIO_PIN_RESET

#define HIGH 1
#define LOW 0


void led_red_and_green();
void led_red_and_yellow();
void led_green_and_red();
void led_yellow_and_red();

void Blinkred();
void Blinkyellow();
void Blinkgreen();
#endif /* INC_TRAFFIC_LIGHT_H_ */
