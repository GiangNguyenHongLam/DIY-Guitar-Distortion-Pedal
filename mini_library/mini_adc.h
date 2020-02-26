/*
 * mini_adc.c
 *
 *  Created on: Aug 29, 2019
 *      Author: lamgiang
 */

#ifndef MINI_LIBRARY_MINI_ADC_H_
#define MINI_LIBRARY_MINI_ADC_H_


#define ADC_0           0x00000001
#define ADC_1           0x00000002


#define AIN0            0 // Analog Input 0 - PE3
#define AIN1            1 // Analog Input 1 - PE2
#define AIN2            2 // Analog Input 2 - PE1
#define AIN3            3 // Analog Input 3 - PE0
#define AIN8            8 // Analog Input 8 - PE5
#define AIN9            9 // Analog Input 9 - PE4

#define ADC_FIFO_EMPTY      0x00000100

#define ADC_ALWAYS_SAMPLE           0xF // Always (Continuously sample)
#define ADC_TIMER_TRIGGER           0x5 // Timer triggered

extern void ADCClockEnable(uint32_t ui32ADC);
extern void ADCSS3Configure(uint32_t ui32ADCBase,uint32_t ui32EventSelect, uint32_t ui32AIpin);
extern void ADCSS2Configure(uint32_t ui32ADCBase,uint32_t ui32EventSelect);
extern uint32_t ADCSS3ReturnData(uint32_t ui32ADCBase);
extern uint32_t ADCSS2ReturnData(uint32_t ui32ADCBase, volatile  uint32_t *buffer);

extern void ADCClearInterruptFlag(uint32_t ui32ADCBase);
void ADCSS2ClearInterruptFlag(uint32_t ui32ADCBase);

#endif /* MINI_LIBRARY_MINI_ADC_H_ */
