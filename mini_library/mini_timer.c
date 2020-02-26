/*
 * mini_timer.c
 *
 *  Created on: Aug 27, 2019
 *      Author: lamgiang
 */

#include<stdint.h>
#include<stdbool.h>

#include"mini_timer.h"
#include"mini_regmap.h"
#include"inc/tm4c123gh6pm.h"


void TimerPeripheralEnable(uint32_t ui32Timer){
    //Enable Timer
    SYSCTL_RCGCTIMER_R |= ui32Timer;
}


void TimerConfigure(uint32_t ui32TimerBase, uint32_t ui32SubTimer, uint32_t mode, uint8_t timerWidth){
    //Make sure the timer is disabled (Clear all TnEN bits)
    HWREG(ui32TimerBase + TIMER_CTL_OFFSET) &=~ (ui32SubTimer & (TIMER_CTL_TAEN|TIMER_CTL_TBEN));
    //Select 32 bit timer if 16/32 Timer is used,
    //and 64 bit timer if 32/64 Timer is used
    HWREG(ui32TimerBase + TIMER_CFG_OFFSET) = timerWidth;
    //Configure subtimer
    if(ui32SubTimer & TIMER_A){
        HWREG(ui32TimerBase + TIMER_TAMR_OFFSET) = mode;
    }
    if(ui32SubTimer & TIMER_B){
        HWREG(ui32TimerBase + TIMER_TBMR_OFFSET) = mode;
    }
}

void TimerEnable(uint32_t ui32TimerBase, uint32_t ui32SubTimer){
    HWREG(ui32TimerBase + TIMER_CTL_OFFSET) |= ui32SubTimer & ((TIMER_CTL_TAEN|TIMER_CTL_TBEN));
}

void TimerADCEnable(uint32_t ui32TimerBase, uint32_t ui32SubTimer){
    HWREG(ui32TimerBase + TIMER_CTL_OFFSET) |= ui32SubTimer & ((TIMER_CTL_ADC_TAEN|TIMER_CTL_ADC_TBEN));
}



void TimerLoadSet(uint32_t ui32TimerBase, uint32_t ui32SubTimer, uint32_t ui32Value){
    //Set the timer A load value
    if(ui32SubTimer & TIMER_A)
    {
        HWREG(ui32TimerBase + TIMERA_ITLR_OFFSET) = ui32Value;
    }

    // Set the timer B load value if requested.
    if(ui32SubTimer & TIMER_B)
    {
        HWREG(ui32TimerBase + TIMERB_ITLR_OFFSET) = ui32Value;
    }
}

void TimerInterruptEnable(uint32_t ui32TimerBase, uint32_t timerInt, uint32_t intMode){
    //Enable Timer Interrupt
    HWREG(ui32TimerBase + TIMER_IM_OFFSET) |= intMode;

    //Enable Timer Interrupt in NVIC
    //NVIC_EN0_R = 1 << (timerInt);
    //NVIC_EN0_R = 0x80000;
}

uint32_t getTimerAValue(uint32_t ui32TimerBase){
    //Return current timer A value
    return HWREG(ui32TimerBase + TIMERA_VALUE_OFFSET);
}

uint32_t getTimerBValue(uint32_t ui32TimerBase){
    //Return current timer B value
    return HWREG(ui32TimerBase + TIMERB_VALUE_OFFSET);
}

