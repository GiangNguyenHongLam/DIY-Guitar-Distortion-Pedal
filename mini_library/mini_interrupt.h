/*
 * mini_interrupt.h
 *
 *  Created on: Aug 30, 2019
 *      Author: lamgiang
 */

#ifndef MINI_LIBRARY_MINI_INTERRUPT_H_
#define MINI_LIBRARY_MINI_INTERRUPT_H_


#define ADC0SS3Int      17
#define ADC1SS3Int      51
#define ADC1SS2Int      50
#define GPIOInt         0

extern void NVICInterruptEnable(uint32_t ui32Interrupt);
extern uint32_t NVICIntCheck(uint32_t ui32Interrupt);

#endif /* MINI_LIBRARY_MINI_INTERRUPT_H_ */
