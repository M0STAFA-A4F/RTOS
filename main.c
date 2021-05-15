#define F_CPU 8000000UL
#include <util/delay.h>

#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "RTOS_Interface.h"



void tog_led1()
{
	DIO_VidTogglePinValue(PORTA, 0);
}

void tog_led2()
{
	DIO_VidTogglePinValue(PORTA, 1);
}

void tog_led3()
{
	DIO_VidTogglePinValue(PORTA, 2);
}



int main()
{
	DIO_VidSetPinDirection(PORTA,0,OUTPUT);
	DIO_VidSetPinDirection(PORTA,1,OUTPUT);
	DIO_VidSetPinDirection(PORTA,2,OUTPUT);

	RTOS_VidCreatTask(1000,0,&tog_led1);
	RTOS_VidCreatTask(2000,1,&tog_led2);
	RTOS_VidCreatTask(3000,2,&tog_led3);

	RTOS_TIMER0_VidInit();


	while(1)
	{

	}

	return 0;
}
