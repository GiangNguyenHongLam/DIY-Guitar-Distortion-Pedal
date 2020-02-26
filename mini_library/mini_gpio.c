/*
 * mini_gpio.cpp
 *
 *  Created on: Aug 25, 2019
 *      Author: lamgiang
 */
#include<stdint.h>
#include<stdbool.h>
#include"mini_gpio.h"
#include"mini_regmap.h"


void GPIOPeripheralEnable(uint32_t ui32Port){
    //Enable clock for the specified port
    SYSCTL_RCGCGPIO_R |= ui32Port;
    uint32_t check = HWREG(SYSCTL_RCGCGPIO_R);
    check = HWREG(SYSCTL_RCGCGPIO_R);

}

void GPIOSetMode(uint32_t ui32PortBase, uint8_t ui8Pin, uint8_t ui8PinMode){
    //Set direction Pin
    HWREG(ui32PortBase + GPIO_DIR_OFFSET) = ((ui8PinMode & OUTPUT_MODE) ?
                                            (HWREG(ui32PortBase + GPIO_DIR_OFFSET) | ui8Pin)  : //If pin is configured to be output
                                            (HWREG(ui32PortBase + GPIO_DIR_OFFSET) & (~ui8Pin))); //Else configured to be input
    //Enable Pin
    HWREG(ui32PortBase + GPIO_DEN_OFFSET) |= ui8Pin;
}

void GPIOPinWrite(uint32_t ui32PortBase, uint8_t ui8Pin, uint8_t ui8Value){
    //Write data to the specified pin, shift 2 since we need to write [9:2] bits of the GPIODATA
    HWREG(ui32PortBase + (GPIO_DATA_OFFSET + (ui8Pin << 2))) = ui8Value;
}

int32_t GPIOPinRead(uint32_t ui32PortBase, uint8_t ui8Pin){
    return HWREG(ui32PortBase + (GPIO_DATA_OFFSET + (ui8Pin << 2)));
}

void GPIOPinToggle(uint32_t ui32PortBase, uint8_t ui8Pin){
    HWREG(ui32PortBase + (GPIO_DATA_OFFSET + (ui8Pin << 2))) ^= ui8Pin;
}


void GPIOPinUnlock(uint32_t ui32PortBase, uint8_t ui8Pin){
    //Unlock the GPIO pin
    HWREG(ui32PortBase + GPIO_LOCK_OFFSET) = 0x4C4F434B;
    //Commit to enable the pin
    HWREG(ui32PortBase + GPIO_CR_OFFSET) |= ui8Pin;
}

void GPIOPullupResisterEnable(uint32_t ui32PortBase, uint8_t ui8Pin){
    HWREG(ui32PortBase + GPIO_PULLUP_RES_OFFSET) = ui8Pin;
}

void GPIOPulldownResisterEnable(uint32_t ui32PortBase, uint8_t ui8Pin){
    HWREG(ui32PortBase + GPIO_PULLDOWN_RES_OFFSET) = ui8Pin;
}


void GPIOAlternativeFuncEnable(uint32_t ui32PortBase, uint8_t ui8Pin){
    HWREG(ui32PortBase + GPIO_AFSEL_OFFSET) = ui8Pin;
}

void GPIOAnalogModeSelect(uint32_t ui32PortBase, uint8_t ui8Pin){
    HWREG(ui32PortBase + GPIO_AMSEL_OFFSET) = ui8Pin;
}

void GPIOInterruptEnable(uint32_t ui32PortBase, uint8_t ui8Pin){
    //Set desired interrupt event trigger to edge detection
    HWREG(ui32PortBase + GPIO_IS_OFFSET) = 0x00000000;
    //Set PA5 to detect single edge only
    HWREG(ui32PortBase + GPIO_IBE_OFFSET) = 0x00000000;
    //Set PA5 to detect falling edge
    HWREG(ui32PortBase + GPIO_IEV_OFFSET) = 0x00000000;
    //Set PA2 to detect both edges
    HWREG(ui32PortBase + GPIO_IBE_OFFSET) |= (1 << 2);
    //Set GPIO Interrupt mask with two pins
    HWREG(ui32PortBase + GPIO_IM_OFFSET) = ui8Pin;
}

uint8_t GPIOIntPinStatus(uint32_t ui32PortBase){
    return HWREG(ui32PortBase + GPIO_MIS_OFFSET);
}








