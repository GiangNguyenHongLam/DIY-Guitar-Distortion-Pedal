/*
 * mini_gpio.h
 *
 *  Created on: Aug 25, 2019
 *      Author: lamgiang
 */

#ifndef MINI_LIBRARY_MINI_GPIO_H_
#define MINI_LIBRARY_MINI_GPIO_H_

#define INPUT_MODE              0x00000000
#define OUTPUT_MODE             0x00000001

//*****************************************************************************
//
// Values that can be passed to most of the GPIO APIs as the ui8Pin
// parameter.
//
//*****************************************************************************
#define GPIO_PIN_0              0x00000001  // GPIO pin 0
#define GPIO_PIN_1              0x00000002  // GPIO pin 1
#define GPIO_PIN_2              0x00000004  // GPIO pin 2
#define GPIO_PIN_3              0x00000008  // GPIO pin 3
#define GPIO_PIN_4              0x00000010  // GPIO pin 4
#define GPIO_PIN_5              0x00000020  // GPIO pin 5
#define GPIO_PIN_6              0x00000040  // GPIO pin 6
#define GPIO_PIN_7              0x00000080  // GPIO pin 7


//*****************************************************************************
//
// Values that can be passed to GPIOPeripheralEnable(uint32_t)
//
//*****************************************************************************

#define GPIO_PORTF              0x00000020  // GPIO Port F Run Mode Clock
#define GPIO_PORTE              0x00000010  // GPIO Port E Run Mode Clock
#define GPIO_PORTD              0x00000008  // GPIO Port D Run Mode Clock
#define GPIO_PORTC              0x00000004  // GPIO Port C Run Mode Clock
#define GPIO_PORTB              0x00000002  // GPIO Port B Run Mode Clock
#define GPIO_PORTA              0x00000001  // GPIO Port A Run Mode Clock


//*****************************************************************************
//
// APIs Declaration
//
//*****************************************************************************
extern void GPIOPeripheralEnable(uint32_t ui32Port);
extern void GPIOSetMode(uint32_t ui32PortBase, uint8_t ui8Pin, uint8_t ui8PinMode);
extern void GPIOPinWrite(uint32_t ui32PortBase, uint8_t ui8Pin, uint8_t ui8Value);
extern int32_t GPIOPinRead(uint32_t ui32PortBase, uint8_t ui8Pin);
extern void GPIOPinToggle(uint32_t ui32PortBase, uint8_t ui8Pin);
extern void GPIOPinUnlock(uint32_t ui32PortBase, uint8_t ui8Pin);
extern void GPIOPullupResisterEnable(uint32_t ui32PortBase, uint8_t ui8Pin);
extern void GPIOPulldownResisterEnable(uint32_t ui32PortBase, uint8_t ui8Pin);
extern void GPIOAlternativeFuncEnable(uint32_t ui32PortBase, uint8_t ui8Pin);
extern void GPIOAnalogModeSelect(uint32_t ui32PortBase, uint8_t ui8Pin);
extern void GPIOInterruptEnable(uint32_t ui32PortBase, uint8_t ui8Pin);
extern uint8_t GPIOIntPinStatus(uint32_t ui32PortBase);


#endif /* MINI_LIBRARY_MINI_GPIO_H_ */

