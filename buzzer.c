/*
 * buzzer.c
 *
 *  Created on: May 7, 2019
 *      Author: LuisFernando
 */

#include "buzzer.h"

/* TODO: insert other definitions and declarations here. */

#define SYSTEM_CLOCK (21000000U)
#define DELAY (0.0025F)

float freq_delay [7] =
{
	0.00383,	/*DO*/
	0.00341,	/*RE*/
	0.00303,	/*MI*/
	0.00286,	/*FA*/
	0.00255,	/*SOL*/
	0.00227,	/*LA*/
	0.00202		/*SI*/
};

void buzzer_config(void)
{
/*GPIO config*/
	gpio_pin_control_register_t output_pit_config = GPIO_MUX1;

	/**Pin control configuration of GPIOB pin0 as GPIO*/
	GPIO_pin_control_register(GPIO_C,bit_2,&output_pit_config);

	/**Assigns a safe value to the output pin*/
	GPIO_set_pin(GPIO_C,bit_2);

	/**Configures GPIOD pin0 as output*/
	GPIO_data_direction_pin(GPIO_C,GPIO_OUTPUT,bit_2);

/*PIT config*/
	/**Activating the PIT clock gating*/
	PIT_clock_gating();
	/**Activating PIT*/
	PIT_enable();

	/*Set the delay for the pit_1*/
	//PIT_delay(PIT_0, SYSTEM_CLOCK, DELAY);
	buzzer_update_freq(freq_delay[7]);

}

void buzzer_update_freq(float delay)
{
	/*Set the delay for the pit_1*/
	PIT_delay(PIT_0, SYSTEM_CLOCK, delay);
}

void buzzer_toogle(void)
{
	GPIO_toogle_pin(GPIO_C,bit_2);
}