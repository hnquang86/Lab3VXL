/*
 * fsm_manual.c
 *
 *  Created on: Nov 1, 2024
 *      Author: PC
 */

#include "fsm_manual.h"

#define CYCLE_TIME 200

void fsm_manual(){
	switch(status){
		case MAN_GREEN_RED:
			setTimer(1, CYCLE_TIME);
			Blinkred();
			status = MAN_MODE_2;
			update_segment_buffer(red_time, MAN_MODE_2-20);
			break;
		case MAN_MODE_2:

			if(getTimerFlag(1)){
				Blinkred();
				setTimer(1, CYCLE_TIME);
			}

			if(get_pressed_flag(0) || get_pressed_flag(1)){
				setTimer(2, FSM_MANUAL_TIMEOUT);
			}

			if(get_pressed_flag(0)){
				status = MAN_MODE_3;
				Blinkyellow();
				set_pressed_flag(0);
			}
			if(get_pressed_flag(1)){
				red_time++;
				if(red_time >= 100)
					red_time = 1;
				set_pressed_flag(1);
			}
			update_segment_buffer(red_time, MAN_MODE_2-20);
			break;
		case MAN_MODE_3:
			if(getTimerFlag(1)){
				Blinkyellow();
				setTimer(1, CYCLE_TIME);
			}
			if(get_pressed_flag(0) || get_pressed_flag(1)){ // button 1 is pressed
				setTimer(2, FSM_MANUAL_TIMEOUT); // reset timeout for man_fsm
			}

			if(get_pressed_flag(0)){
				status = MAN_MODE_4;
				Blinkgreen();
				set_pressed_flag(0);
			}
			if(get_pressed_flag(1)){
				yellow_time++;
				if(yellow_time >= 100)
					yellow_time = 1;
				set_pressed_flag(1);
			}
			update_segment_buffer(yellow_time, MAN_MODE_3-20);
			break;
		case MAN_MODE_4:
			if(getTimerFlag(1)){
				Blinkgreen();
				setTimer(1, CYCLE_TIME);
			}
			if(get_pressed_flag(0) || get_pressed_flag(1)){
				setTimer(2, FSM_MANUAL_TIMEOUT);
			}

			if(get_pressed_flag(1)){
				green_time++;
				if(green_time >= 100)
					green_time = 1;
				set_pressed_flag(1);
			}
			update_segment_buffer(green_time, MAN_MODE_4-20);
			break;
		default:
			break;
	}


}
