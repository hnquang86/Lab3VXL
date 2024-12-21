/*
 * traffic_light.c
 *
 *  Created on: Oct 31, 2024
 *      Author: Admin
 */
#include "traffic_light.h"



void displayTrafficLed(uint8_t green_al, uint8_t yellow_al, uint8_t red_al,
		 	 	 	 	 uint8_t green_lf, uint8_t yellow_lf, uint8_t red_lf){
	//above and low
	HAL_GPIO_WritePin(LED_GREEN_AL_GPIO_Port, LED_GREEN_AL_Pin, green_al);
	HAL_GPIO_WritePin(LED_YELLOW_AL_GPIO_Port, LED_YELLOW_AL_Pin, yellow_al);
	HAL_GPIO_WritePin(LED_RED_AL_GPIO_Port, LED_RED_AL_Pin, red_al);
	// left and right
	HAL_GPIO_WritePin(LED_GREEN_LR_GPIO_Port, LED_GREEN_LR_Pin, green_lf);
	HAL_GPIO_WritePin(LED_YELLOW_LR_GPIO_Port, LED_YELLOW_LR_Pin, yellow_lf);
	HAL_GPIO_WritePin(LED_RED_LR_GPIO_Port, LED_RED_LR_Pin, red_lf);
}


void led_red_and_green(){

	displayTrafficLed(OFF, OFF, ON,
						ON, OFF, OFF);
}

void led_red_and_yellow(){
	displayTrafficLed(OFF, OFF, ON,
						OFF, ON, OFF);
}

void led_green_and_red(){
	displayTrafficLed(ON, OFF, OFF,
						OFF, OFF, ON);
}

void led_yellow_and_red(){
	displayTrafficLed(OFF, ON, OFF,
						OFF, OFF, ON);
}



uint8_t toggle = HIGH;
void Blinkred(){
	if(toggle == HIGH){
		displayTrafficLed(OFF, OFF, ON,
							OFF, OFF, ON);
		// toggle state
		toggle = LOW;
	}else{
		displayTrafficLed(OFF, OFF, OFF,
							OFF, OFF, OFF);
		// toggle state
		toggle = HIGH;
	}

}
void Blinkyellow(){
	if(toggle == HIGH){
		displayTrafficLed(OFF, ON, OFF,
							OFF, ON, OFF);
		// toggle state
		toggle = LOW;
	}else{
		displayTrafficLed(OFF, OFF, OFF,
							OFF, OFF, OFF);
		// toggle state
		toggle = HIGH;
	}
}
void Blinkgreen(){
	if(toggle == HIGH){
		displayTrafficLed(ON, OFF, OFF,
							ON, OFF, OFF);
		// toggle state
		toggle = LOW;
	}else{
		displayTrafficLed(OFF, OFF, OFF,
							OFF, OFF, OFF);
		// toggle state
		toggle = HIGH;
	}
}



















