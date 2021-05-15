

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RTOS_Register.h"

#define NULL			0
#define TasksNumber		3



task System_Tasks[TasksNumber];

void RTOS_VidCreatTask(u32 Copy_U8Periodicity, u8 Copy_U8Periorty, void (*pfunc)(void))
{
	System_Tasks[Copy_U8Periorty].func = pfunc;
	System_Tasks[Copy_U8Periorty].periodicity = Copy_U8Periodicity;
}

void RTOS_VidSchaduler(void)
{
	static u16 TickCounter = 0;
	TickCounter++;
	
	for(u8 i=0; i<TasksNumber; i++)
	{
		if(TickCounter % System_Tasks[i].periodicity == 0)
		{
			System_Tasks[i].func();
		}
	}
}


void RTOS_TIMER0_VidInit()
{
	// CTC Mode
	CLR_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);
	
	// prescaling   --> clk/64
	CLR_BIT(TCCR0,2);
	SET_BIT(TCCR0,1);
	SET_BIT(TCCR0,0);
	
	// preload value of timer0

	OCR0 = 125;
	
	//  Timer/Counter0 Overflow Interrupt Enable (TOIE)
	SET_BIT(TIMSK,1);
	
	// GIE=1
	SET_BIT(SREG,7);
}


void __vector_10(void)
{
	RTOS_VidSchaduler();
}






