/*
 * blink.h
 *
 *  Created on: Oct 31, 2021
 *      Author: fulcrum
 */

#ifndef INC_BLINK_H_
#define INC_BLINK_H_
#include "main.h"


void blink_scheme_1(volatile uint32_t * delay,volatile uint8_t * pause_flag,volatile uint8_t * exit_flag);
void blink_scheme_2(volatile uint32_t * delay,volatile uint8_t * pause_flag,volatile uint8_t * exit_flag);
void blink_scheme_3(volatile uint32_t * delay,volatile uint8_t * pause_flag,volatile uint8_t * exit_flag);


#endif /* INC_BLINK_H_ */
