#ifndef _RTOS_INTERFACE_H_

#define _RTOS_INTERFACE_H_


void RTOS_VidCreatTask(u32 Copy_U8Periodicity, u8 Copy_U8Periorty, void (*pfunc)(void));
void RTOS_VidSchaduler(void);
void RTOS_TIMER0_VidInit();


#endif
