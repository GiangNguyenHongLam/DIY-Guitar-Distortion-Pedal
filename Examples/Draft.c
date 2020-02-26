/**
 * main.c
 */
/*
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

//#include"inc/tm4c123gh6pm.h"

#define SSI2_BASE               0x4000A000  // SSI2


uint32_t timerValue = 0;
uint32_t checkTime = 0;
volatile static int count1 = 0;
volatile static int count2 = 0;
volatile static int count3 = 0;


volatile static uint16_t adcResult = 0;

void ADC1SS3_Handler(void){
    adcResult = ADCReturnData(ADC1_BASE);
    ADCClearInterruptFlag(ADC1_BASE);
    count3++;
}


void Timer0AHandler(void){
    HWREG(TIMER0_BASE + TIMER_ICR_OFFSET) |= 0x00000001;
    count1++;
}



void Timer1AHandler(void){
    HWREG(TIMER1_BASE + TIMER_ICR_OFFSET) |= 0x00000001;
    count2++;
    GPIOPinToggle(GPIO_PORTF_BASE, GPIO_PIN_1);
}


int main(void)
{
    //Set clock to 80MHz
    //SysCtlClockSet(SYSCTL_SYSDIV_2_5 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);
    uint32_t ClkCheck = SysCtlClockGet();

    GPIOPeripheralEnable(GPIO_PORTF|GPIO_PORTE);
    //Configure GPIO Pins
    GPIOSetMode(GPIO_PORTF_BASE,GPIO_PIN_1|GPIO_PIN_2,OUTPUT_MODE);
    GPIOSetMode(GPIO_PORTE_BASE,GPIO_PIN_1,INPUT_MODE);
    //GPIOSetMode(GPIO_PORTB_BASE,GPIO_PIN_5,OUTPUT_MODE);
    //GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_5, GPIO_PIN_5);



    TimerPeripheralEnable(TIMER_0);
    TimerPeripheralEnable(TIMER_1);

    TimerConfigure(TIMER0_BASE, TIMER_A, TIMERA_CFG_PERIODIC);
    TimerConfigure(TIMER1_BASE, TIMER_A, TIMERA_CFG_PERIODIC);


    TimerLoadSet(TIMER0_BASE,TIMER_A,362);
    TimerLoadSet(TIMER1_BASE,TIMER_A,0xF42400);


    TimerInterruptEnable(TIMER0_BASE, TIMER0_A_INT_EN|TIMER0_B_INT_EN, TIMERA_INT_MASK_TIMEOUT);
    TimerInterruptEnable(TIMER1_BASE, TIMER0_A_INT_EN|TIMER0_B_INT_EN, TIMERA_INT_MASK_TIMEOUT);

    NVICInterruptEnable(TIMER0_A_INT_EN);
    NVICInterruptEnable(TIMER1_A_INT_EN);


    TimerADCEnable(TIMER0_BASE,TIMER_A);
    TimerEnable(TIMER1_BASE,TIMER_A);


    uint32_t checkReg = NVICIntCheck(TIMER0_A_INT_EN);


    //Enable SSI Communication
    SSI2FrameConfigure();


    //Enable ADC Clock
    ADCClockEnable(ADC_1);


    //Enable Alternative Function
    GPIOAlternativeFuncEnable(GPIO_PORTE_BASE, GPIO_PIN_1);
    //Select Analog mode
    GPIOAnalogModeSelect(GPIO_PORTE_BASE, GPIO_PIN_1);
    //Configure ADC to pin PE1
    ADCConfigure(ADC1_BASE, ADC_TIMER_TRIGGER, AIN2);
    //Configure NVIC
    NVICInterruptEnable(ADC1SS3Int);

    checkReg = NVICIntCheck(ADC1SS3Int);

    //GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_5, 0);
    SSI16bitWrite(0x1);;

    SysCtlDelay(8000);

    SSI16bitWrite(0x2);
    SysCtlDelay(8000);
    SSI16bitWrite(0x1);
    SysCtlDelay(8000);
    SSI16bitWrite(0xF4);
    SysCtlDelay(8000);
    //GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_5, GPIO_PIN_5);


    while(1){
        SSI16bitWrite(0xF0);
        SysCtlDelay(8000);
        SSI16bitWrite(0xF1);
        SysCtlDelay(8000);
        SSI16bitWrite(0xF3);
        SysCtlDelay(8000);
        SSI16bitWrite(0xF4);
        SysCtlDelay(8000);
        if(adcResult > 2047){
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2,GPIO_PIN_2 );
        }
        else GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0);

    }
}
*/


