/*
 * PeripheralConfigure.h
 *
 *  Created on: Sep 5, 2019
 *      Author: lamgiang
 */

#ifndef PERIPHERALCONFIGURE_PERIPHERALCONFIGURE_H_
#define PERIPHERALCONFIGURE_PERIPHERALCONFIGURE_H_


extern void GeneralConfigure();
extern void Timer0A_ADCConfigure();
extern void Timer1A_Configure();
extern void Timer2A_SSIConfigure();
extern void ADCConfigure();
extern void GPIOSwitchInterruptEnable();
extern void LEDIndicator(uint8_t mode);

#endif /* PERIPHERALCONFIGURE_PERIPHERALCONFIGURE_H_ */
