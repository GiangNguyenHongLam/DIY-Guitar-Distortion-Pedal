/*
 * mini_ssi.c
 *
 *  Created on: Sep 2, 2019
 *      Author: lamgiang
 */
#include<stdint.h>
#include"mini_gpio.h"
#include"mini_ssi.h"
#include"mini_regmap.h"

void SSI1_FrameConfigure(){
    //Enable SSI 1
    SYSCTL_RCGCSSI_R = (1 << 1);
    //Clock to Port B
    GPIOPeripheralEnable(GPIO_PORTD);
    //Enable AFSEL
    GPIOAlternativeFuncEnable(GPIO_PORTD_BASE, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);
    //Configure PMCn fields in GPIOPCTL for pin 0,1,2,3, write 0x02 to the suitable bit field in the PCTL register
    HWREG(GPIO_PORTD_BASE + GPIO_PCTL_OFFSET) = (2 << 0)|(2 << 4)|(2 << 8)|(2 << 12);
    //Enable GPIO pin
    HWREG(GPIO_PORTD_BASE + GPIO_DEN_OFFSET) |= (GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);
    //GPIOPullupResisterEnable(GPIO_PORTB_BASE, GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7);
    //Clear the SSE bit in CR1 register
    SSI1_CR1 &=~ (1 << 1);
    //Choose SSI to be a master
    SSI1_CR1 = 0x00000000;
    //Select SSI Clock
    SSI1_CC = 0x00000000;
    //Select SSI Clock prescaler (System clock / (Prescaler * (SCR))
    SSI1_CPSR = 0x50;

    //Write the SSICR0 register with the following configuration:
    //Serial clock rate (SCR)
    //SSI2_CR0 = (0x00000000);
    //Desired clock phase/polarity, if using Freescale SPI mode (SPH and SPO)
    //SSI2_CR0 |= (1 << 7);
    //The protocol mode: Freescale SPI, TI SSF, MICROWIRE (FRF)
    //The data size (DSS) 16-bit data
    SSI1_CR0 |= (0xF << 0);
    //Enable SSI2
    SSI1_CR1 |= (1 << 1);
}


void SSI1_16bitWrite(uint16_t ui16data){
    //SSI1_DR = 0b0011000000000000;
    SSI1_DR = (0b0011 << 12)|(ui16data << 0);
    //while((SSI0_SR & (1<<0)) ==0);
}


