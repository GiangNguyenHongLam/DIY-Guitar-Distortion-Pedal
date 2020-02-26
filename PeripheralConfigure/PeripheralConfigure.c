/*
 * PeripheralConfigure.c
 *
 *  Created on: Sep 5, 2019
 *      Author: lamgiang
 */

#include <stdint.h>
#include <stdbool.h>
#include"mini_library/mini_regmap.h"
#include"mini_library/mini_gpio.h"
#include"mini_library/mini_timer.h"
#include"mini_library/mini_adc.h"
#include"mini_library/mini_interrupt.h"
#include"mini_library/mini_sysctl.h"
#include"mini_library/mini_ssi.h"

#include "driverlib/sysctl.h"
#include "driverlib/ssi.h"
#include"PeripheralConfigure.h"
/*
 * This function will set system clock to 80MHz and configure the necessary GPIO Pin for other peripherals
 * Two GPIO Port F and E will be configured since Port F is responsible for LED control and Timer
 * and Port E is responsible for ADC feature.
 *
 * The TivaC driverlib will be used for the SysCtlClockSet function
 */
void GeneralConfigure(){
   //Set clock to 80MHz
   SysCtlClockSet(SYSCTL_SYSDIV_2_5 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);
   //GPIO Port Enable
   GPIOPeripheralEnable(GPIO_PORTF|GPIO_PORTE|GPIO_PORTA|GPIO_PORTB);
   //Configure Port F
   GPIOSetMode(GPIO_PORTF_BASE,GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3,OUTPUT_MODE);
   GPIOSetMode(GPIO_PORTB_BASE,GPIO_PIN_2,OUTPUT_MODE);
   //Configure Port E and enable PE0, PE3, PE4, PE5 as input
   GPIOSetMode(GPIO_PORTE_BASE,GPIO_PIN_0|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5,INPUT_MODE);
   GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, GPIO_PIN_3);
   GPIOSwitchInterruptEnable();
   if(GPIOPinRead(GPIO_PORTA_BASE,GPIO_PIN_2) == 0){
       GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3|GPIO_PIN_2, GPIO_PIN_3|GPIO_PIN_2);
       GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_2, GPIO_PIN_2);
   }
   else LEDIndicator(0);
}


/*
 * This function will configure subtimer A of timer 0 (32 bits), runs for 44.1KHz to trigger ADC
 * Noted that since the system clock is 80MHz -. 44.1Khz -> 1814 clocks
 * Edited 26/02/2020 set back to the sample rate of 32kHz to trigger ADC, which is 2500 clocks
 *
 */
void Timer0A_ADCConfigure(){
    //Enable and configure subtimer A of timer 0 to be Periodic
    TimerPeripheralEnable(TIMER_0);
    TimerConfigure(TIMER0_BASE, TIMER_A, TIMERA_CFG_PERIODIC, TIMER_16_32BIT);
    //Set timer A interval load
    TimerLoadSet(TIMER0_BASE,TIMER_A,2500);
    //Enable interrupt for subtimer A
    TimerInterruptEnable(TIMER0_BASE, TIMER0_A_INT_EN, TIMERA_INT_MASK_TIMEOUT);
    //NVICInterruptEnable(TIMER0_A_INT_EN);
    //Configure Timer A to trigger ADC
    TimerADCEnable(TIMER0_BASE,TIMER_A);
}



/*
 * This function will configure subtimer A of timer 1 (32 bits), runs for 1 second in order to check the validity of ADC rate
 * Noted that since the system clock is 80MHz -> 80*10^6 clocks
 */
void Timer1A_Configure(){
    //Enable and configure subtimer A of timer 1 to be Periodic
    TimerPeripheralEnable(TIMER_1);
    TimerConfigure(TIMER1_BASE, TIMER_A, TIMERA_CFG_PERIODIC, TIMER_32_64BIT);
    //Set timer A interval load
    TimerLoadSet(TIMER1_BASE,TIMER_A,0x1312D00);
    //Enable interrupt for subtimer A
    TimerInterruptEnable(TIMER1_BASE, TIMER0_A_INT_EN, TIMERA_INT_MASK_TIMEOUT);
    NVICInterruptEnable(TIMER1_A_INT_EN);
    HWREG(NVIC_PRIO5_R) |= (0x4 << 13);
    //Configure Timer A to trigger ADC
    TimerEnable(TIMER1_BASE,TIMER_A);

}

/*
 * Idle timer for future upgrades
 */
void Timer2A_SSIConfigure(){
    //Enable and configure subtimer A of timer 1 to be Periodic
    TimerPeripheralEnable(TIMER_2);
    TimerConfigure(TIMER2_BASE, TIMER_A, TIMERA_CFG_PERIODIC, TIMER_16_32BIT);
    //Set timer A interval load
    TimerLoadSet(TIMER2_BASE,TIMER_A, 2500);
    //Enable interrupt for subtimer A
    TimerInterruptEnable(TIMER2_BASE, TIMER0_A_INT_EN, TIMERA_INT_MASK_TIMEOUT);
    NVICInterruptEnable(TIMER2_A_INT_EN);
    HWREG(NVIC_PRIO5_R) |= (0x3 << 13);
    //Configure Timer A to trigger ADC
    TimerEnable(TIMER2_BASE,TIMER_A);
}


/*
 * This function will configure ADC. Noted that ADC0 will control PE1 to sample signal,
 * while ADC1 will read PE2, PE3 to load user parameters
 */
void ADCConfigure(){
    //Enable ADC0 and ADC1 Clock
    ADCClockEnable(ADC_0|ADC_1);
    //Enable Alternative Function
    GPIOAlternativeFuncEnable(GPIO_PORTE_BASE, GPIO_PIN_0|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5);
    //Select Analog mode
    GPIOAnalogModeSelect(GPIO_PORTE_BASE, GPIO_PIN_0|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5);
    //Configure ADC0 to have sample sequence 3 to read PE3
    ADCSS3Configure(ADC0_BASE, ADC_TIMER_TRIGGER, AIN0);
    //Configure ADC1 to have sample sequence 2 to read PE0, PE4, PE5
    ADCSS2Configure(ADC1_BASE, ADC_TIMER_TRIGGER);
    //Enable interrupt for ADC
    NVICInterruptEnable(ADC0SS3Int);
    NVICInterruptEnable(ADC1SS2Int);
    //Set priority of ADC0 SS3 with highest level
    HWREG(NVIC_PRIO4_R) &=~ (0x7 << 13);
    //Set priority of ADC1 SS2 with second level
    HWREG(NVIC_PRIO12_R) |= (0x1 << 3);
}

/*
 * This function will configure GPIO interrupt to control the Pedal mode
 * Noted that, the interrupt will activate when it detects falling edge on PA2 and PA5
 */
void GPIOSwitchInterruptEnable(){
    GPIOPullupResisterEnable(GPIO_PORTA_BASE, GPIO_PIN_2|GPIO_PIN_5);
    GPIOSetMode(GPIO_PORTA_BASE, GPIO_PIN_2|GPIO_PIN_5, INPUT_MODE);
    GPIOInterruptEnable(GPIO_PORTA_BASE, GPIO_PIN_2|GPIO_PIN_5);
    //Enable Interrupt
    NVICInterruptEnable(GPIOInt);
    //Set priority
    HWREG(NVIC_PRIO0_R) &=~ (0x4 << 5);
}



/*
 * This function control the state of LED Indicator based on the pedal mode variable
 */

void LEDIndicator(uint8_t mode){
    switch (mode){
        //No effect
        case 0:
            //Turn on indicator 1
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, GPIO_PIN_3);
            //Turn off indicator 2 and 3
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0);
            GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_2, 0);
            break;
        //Hard Clipping Distortion
        case 1:
            //Turn on indicator 2
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, GPIO_PIN_2);
            //Turn off indicator 1 and 3
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0);
            GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_2, 0);
            break;
        //Soft Clipping Distortion
        case 2:
            //Turn on indicator 3
            GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_2, GPIO_PIN_2);
            //Turn off indicator 1 and 2
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2|GPIO_PIN_3, 0);
            break;
        case 3:
            //Turn on indicator 1 and 2
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3|GPIO_PIN_2,  GPIO_PIN_3|GPIO_PIN_2);
            //Turn off indicator 3
            GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_2, 0);
            break;
        case 4:
            //Turn on indicator 1 and 3
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3,  GPIO_PIN_3);
            GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_2, GPIO_PIN_2);
            //Turn off indicator 3
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0);
            break;
    }
}

