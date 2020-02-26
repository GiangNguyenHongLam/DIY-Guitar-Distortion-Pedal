/*
 * mini_adc.c
 *
 *  Created on: Aug 29, 2019
 *      Author: lamgiang
 */

#include<stdint.h>
#include<stdbool.h>
#include"mini_adc.h"
#include"mini_regmap.h"
#include"driverlib/adc.h"

void ADCClockEnable(uint32_t ui32ADC){
    SYSCTL_RCGCADC_R |= ui32ADC;
}

void ADCSS2Configure(uint32_t ui32ADCBase,uint32_t ui32EventSelect){
    //Disable ADC Sequence 2
    HWREG(ui32ADCBase + ADC_ACTSS_OFFSET) &=~ (1<<2);
    //USe ADC Sequence 2
    HWREG(ui32ADCBase + ADC_EMUX_OFFSET) |= (ui32EventSelect << 8);
    //For each sample in the sample sequence, configure the corresponding input source
    HWREG(ui32ADCBase + ADC_SSMUX2_OFFSET) |= (9 << 0)|(8 << 4)|(3 << 8);
    //Ensure that the END bit is set, otherwise unpredictable behaviors may occur
    //Set 1 to bit IE0 to enable Sample Interrupt (ADC step)
    HWREG(ui32ADCBase + ADC_SSCTL2_OFFSET) = 0x644; //0b011001000100
    //Set Interrupt mask
    HWREG(ui32ADCBase + ADC_IM_OFFSET) = (1 << 2); // Set Sequence 2 interrupt mask
    //Enable ADC Sequence 2 again
    HWREG(ui32ADCBase + ADC_ACTSS_OFFSET) |= (1<<2);
    //Clear the interrupt flag
    HWREG(ui32ADCBase + ADC_ISC_OFFSET) |= (1<<2);
}

void ADCSS3Configure(uint32_t ui32ADCBase,uint32_t ui32EventSelect, uint32_t ui32AIpin){
    //Disable ADC Sequence 3
    HWREG(ui32ADCBase + ADC_ACTSS_OFFSET) &=~ (1<<3);
    //USe ADC Sequence 3
    HWREG(ui32ADCBase + ADC_EMUX_OFFSET) |= (ui32EventSelect << 12);
    //For each sample in the sample sequence, configure the corresponding input source
    HWREG(ui32ADCBase + ADC_SSMUX3_OFFSET) = ui32AIpin;
    //Ensure that the END bit is set, otherwise unpredictable behaviors may occur
    //Set 1 to bit IE0 to enable Sample Interrupt
    HWREG(ui32ADCBase + ADC_SSCTL3_OFFSET) = 0x06; //0b0110
    //Set Interrupt mask
    HWREG(ui32ADCBase + ADC_IM_OFFSET) = (1 << 3); // Set Sequence 3 interrupt mask
    //Enable ADC Sequence 3 again
    HWREG(ui32ADCBase + ADC_ACTSS_OFFSET) |= (1<<3);
    //Clear the interrupt flag
    HWREG(ui32ADCBase + ADC_ISC_OFFSET) |= (1<<3);
}


uint32_t ADCSS3ReturnData(uint32_t ui32ADCBase){
    return HWREG(ui32ADCBase + ADC_SSFIFO3_OFFSET);
}

uint32_t ADCSS2ReturnData(uint32_t ui32ADCBase, volatile uint32_t *buffer){
    uint8_t varCount = 0;
    while(!(HWREG(ui32ADCBase + ADC_RIS_OFFSET) & 0b100));
    ADCSS2ClearInterruptFlag(ADC1_BASE);
    while(!(HWREG(ui32ADCBase + ADC_SSFIFO2STAT_OFFSET) & ADC_FIFO_EMPTY) && (varCount < 6)){
        *buffer++ = HWREG(ui32ADCBase + ADC_SSFIFO2_OFFSET);
        varCount++;
    }
    return varCount;
}

void ADCClearInterruptFlag(uint32_t ui32ADCBase){
    HWREG(ui32ADCBase + ADC_ISC_OFFSET) |= (1<<3);
}

void ADCSS2ClearInterruptFlag(uint32_t ui32ADCBase){
    HWREG(ui32ADCBase + ADC_ISC_OFFSET) |= (1<<2);
}
