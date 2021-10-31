#include "blink.h"


static uint16_t LED_arr[4] = {LED_green_Pin, LED_orange_Pin,LED_red_Pin,LED_blue_Pin};
static uint16_t all_led_pins = LED_green_Pin|LED_orange_Pin|LED_red_Pin|LED_blue_Pin;
static GPIO_TypeDef * all_led_port = LED_blue_GPIO_Port;



void blink_scheme_1(volatile uint32_t * delay,volatile uint8_t * pause_flag,volatile uint8_t * exit_flag)
{
	uint32_t tick = 0;

	HAL_GPIO_WritePin(all_led_port,all_led_pins, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(all_led_port, LED_orange_Pin|LED_blue_Pin, GPIO_PIN_SET);

	while(1)
	{
		tick = HAL_GetTick();
		while((HAL_GetTick()< (tick + *delay)) || (*pause_flag == 1))
		{
			if(*exit_flag == 1)	return;


		}
		HAL_GPIO_TogglePin(all_led_port, all_led_pins);


	}



}

void blink_scheme_2(volatile uint32_t * delay,volatile uint8_t * pause_flag,volatile uint8_t * exit_flag)
{
	uint32_t tick = 0;

	HAL_GPIO_WritePin(all_led_port,all_led_pins, GPIO_PIN_RESET);


	while(1)
	{

		for(uint32_t i = 0; i < 4; i++)
		{
			HAL_GPIO_WritePin(all_led_port, LED_arr[i], GPIO_PIN_SET);
			tick = HAL_GetTick();
			while((HAL_GetTick()< (tick + *delay)) || (*pause_flag == 1))
			{
				if(*exit_flag == 1)	return;


			}
			HAL_GPIO_WritePin(all_led_port, LED_arr[i], GPIO_PIN_RESET);
		}






	}

}

void blink_scheme_3(volatile uint32_t * delay,volatile uint8_t * pause_flag,volatile uint8_t * exit_flag)
{
	const uint8_t led_sequence_arr[] = {0,2,0,2,3,1,3,1};
	const uint8_t sequence_arr_len = sizeof(led_sequence_arr)/sizeof(led_sequence_arr[0]);
	uint32_t tick = 0;

	HAL_GPIO_WritePin(all_led_port,all_led_pins, GPIO_PIN_RESET);


	while(1)
	{

		for(uint32_t i = 0; i < sequence_arr_len; i++)
		{
			HAL_GPIO_WritePin(all_led_port, LED_arr[led_sequence_arr[i]], GPIO_PIN_SET);
			tick = HAL_GetTick();
			while((HAL_GetTick()< (tick + *delay)) || (*pause_flag == 1))
			{
				if(*exit_flag == 1)	return;


			}
			HAL_GPIO_WritePin(all_led_port, LED_arr[led_sequence_arr[i]], GPIO_PIN_RESET);
		}

	}

}
