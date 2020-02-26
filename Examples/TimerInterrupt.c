/**
 * main.c
 */
/*
#include <stdint.h>
#include <stdbool.h>
#include"mini_library/mini_regmap.h"
#include"mini_library/mini_gpio.h"
#include"mini_library/mini_timer.h"
#include"inc/tm4c123gh6pm.h"

uint32_t timerValue = 0;
uint32_t checkTime = 0;
void TIMER0A_Handler(void){
    //Clear bit
    HWREG(TIMER0_BASE + TIMER_ICR_OFFSET) |= 0x00000001;
    GPIOPinToggle(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);
}

int main(void)
{


    GPIOPeripheralEnable(GPIO_PORTF);
    GPIOSetMode(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, OUTPUT_MODE);
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);

    TimerSysctl(TIMER_0);
    TimerConfigure(TIMER0_BASE, TIMER_A, TIMERA_CFG_PERIODIC);

    TimerLoadSet(TIMER0_BASE,TIMER_A,0xF42400);
    checkTime = HWREG(TIMER0_BASE + TIMERA_ITLR_OFFSET);
    TimerInterruptEnable(TIMER0_BASE, TIMER0_A_INT_EN, TIMERA_INT_MASK_TIMEOUT);
    HWREG(PERIPHERALS_REG_BASE + EVIC_EN0) = 0x40000;
    TimerEnable(TIMER0_BASE,TIMER_A);

    while(1){

    }
}
*/
