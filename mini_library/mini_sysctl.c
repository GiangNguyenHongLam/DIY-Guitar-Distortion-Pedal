/*
 * mini_sysctl.c
 *
 *  Created on: Sep 1, 2019
 *      Author: lamgiang
 */
#include<stdint.h>

#include "mini_sysctl.h"
#include"mini_regmap.h"

void SysCtlClockSet_mini(){

    uint32_t u32RCC, u32RCC2;

    u32RCC = HWREG(SYSCTL_RCC_R);
    u32RCC2 = HWREG(SYSCTL_RCC2_R);

    //Bypass the PLL and system clock divider
    u32RCC |= RCC_BYPASS;
    u32RCC &=~ RCC_USESYSDIV;
    u32RCC2 |= RCC2_BYPASS;

    //Write to the register
    HWREG(SYSCTL_RCC_R) = u32RCC;
    HWREG(SYSCTL_RCC2_R)= u32RCC2;

    //Set the crystal value (XTAL) and oscillator source for RCC
    u32RCC &=~ (RCC_OSCSRC|RCC_XTAL_M);
    u32RCC |= (W16MHz_XTAL << 6);

    //Set the crystal value (XTAL) and oscillator source for RCC2
    u32RCC2 &=~(RCC2_OSCSRC2_M);
    u32RCC2 |= (RCC2_USERCC2);

    //Write to the register
    HWREG(SYSCTL_RCC_R) = u32RCC;
    HWREG(SYSCTL_RCC2_R)= u32RCC2;


    //Clear PWDRN bit in RCC and RCC2
    u32RCC &=~ (RCC_PWRDN);
    u32RCC2 &=~ (RCC2_PWRDN2);

    //Write to the register
    HWREG(SYSCTL_RCC_R) = u32RCC;
    HWREG(SYSCTL_RCC2_R)= u32RCC2;

    //Use 400MHz
    u32RCC2 |= (1<<30);
    //Use RCC2
    u32RCC2 |= (1<<31);
    //Divide by 5
    //u32RCC |= (0x5 << 23);

    u32RCC2 &=~ 0x1FC00000;
    u32RCC2 |=  0x01000000;

    //HWREG(SYSCTL_RCC_R) = u32RCC;
    //HWREG(SYSCTL_RCC2_R)= u32RCC2;


    uint32_t check = HWREG(SYSCTL_RIS_R);
    //Wait for PLLLRIS to indicate the PLL has successfully set
    //while(!(SYSCTL_RIS_R & (1<<6))){}

    u32RCC &=~ RCC_BYPASS;



    HWREG(SYSCTL_RCC_R) = u32RCC;
    HWREG(SYSCTL_RCC2_R)= u32RCC2;

    int i = 0;
    while(i<1000){
        i++;
    }

}




