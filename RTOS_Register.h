#ifndef _RTOS_REGISTER_H_

#define _RTOS_REGISTER_H_



#define TCCR0	*((u8*)0x53)
#define TCNT0	*((u8*)0x52)
#define OCR0	*((u8*)0x5c)
#define TIMSK	*((u8*)0x59)
#define TIFR	*((u8*)0x58)

#define SREG	*((u8*)0x5F)

void __vector_10(void)       __attribute__((signal));


typedef struct task
{
	void (*func)(void);
	u32 periodicity;
}task;


#endif
