/*
 * mini_interrupt.c
 *
 *  Created on: Aug 30, 2019
 *      Author: lamgiang
 */

#include<stdint.h>
#include<stdbool.h>
#include"mini_interrupt.h"
#include"mini_regmap.h"

static const uint32_t NVICEnableRegister[] =
{
    NVIC_EN0_R, NVIC_EN1_R, NVIC_EN2_R, NVIC_EN3_R
};

void NVICInterruptEnable(uint32_t ui32Interrupt){
    HWREG(NVICEnableRegister[ui32Interrupt/32]) = (1 << (ui32Interrupt & 31));
}


uint32_t NVICIntCheck(uint32_t ui32Interrupt){
    return HWREG(NVICEnableRegister[ui32Interrupt/32]);
}
