/*
	\file 	  main.c
	\brief	  main program.

	\authors: César Villarreal Hernández, ie707560
	          Luís Fernando Rodríguez Gutiérrez, ie705694

	\date	  10/05/2019
*/

#include "system.h"
#include "lcd_nokia_images.h"
#include "simon_says.h"

int main(void)
{
	system_init();

	while(1)
	{
		victory_buzzer();
	}

	return 0;
}
