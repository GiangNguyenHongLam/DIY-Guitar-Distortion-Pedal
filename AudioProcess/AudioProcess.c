/*
 * AudioProcess.c
 *
 *  Created on: Sep 5, 2019
 *      Author: lamgiang
 */

//#include <math.h>
#include<stdbool.h>
#include<stdint.h>
#include<math.h>
#include "LookUpTable.h"
#include "FastMathApproximation.h"
#include "AudioProcess.h"


uint16_t AudioProcessSampleBySample(uint16_t input, volatile  uint32_t *parameter,volatile bool bypassed){
    uint8_t pedalMode = 0;
    uint16_t upperThres, lowerThres;
    float gain;
    float drive1, drive2;
    ParameterProcessing(parameter, &upperThres, &lowerThres, &gain, &drive1, &drive2, &pedalMode);
    //Run the loop for 32 times
    //Switch mode
    if(!bypassed){
        LEDIndicator(pedalMode);
        switch(pedalMode){
            case 0:
                return input;
            case 1:
                return HardClippingEffect(input, upperThres, lowerThres, gain);
            case 2:
                return SoftClippingEffect1(input, drive1, gain);
            case 3:
                return SoftClippingEffect2(input, drive2, gain);
            case 4:
                return TanhDistortionEffect(input, drive1, gain);
        }
    }
}

/*
 * Important note: the resting voltage when there is no input is 1986. The result is calculated by the ratio: 3.32V/1.61V
 */
void ParameterProcessing(volatile uint32_t* parameter, uint16_t* upperThres, uint16_t* lowerThres,
                         float* gain, float* drive1, float* drive2, uint8_t *pedalMode){
    //Pedal Mode 0 -> 4
    *pedalMode = parameter[0]*0.00122;
    //Upper threshold
    *upperThres = (uint16_t) parameter[1]*0.3662 + 2596; // Scale from 0 - 4096 to 2496 -> 4096
    //Lower threshold
    *lowerThres = 1500 - (uint16_t) parameter[1]*0.3662; // Scale from 0 - 4096 to 0 - 1600
    //Gain (scale 1 - 4)
    *gain = (uint16_t) parameter[2]*0.000732 + 1; // Scale from 0 - 4096 to 1 - 3
    //Scale 1 - 4
    *drive1 = parameter[1]*0.000732+1;
    //Scale 0.5 - 1.5
    *drive2 = parameter[1]*0.000122 + 0.5;
}



uint16_t HardClippingEffect(uint16_t sampleInput, uint16_t upperThres, uint16_t lowerThres, float gain){
    //Amplify the input
    float output = 1986 + gain*(sampleInput - 1986);
    //Hard-clipping the signal
    if(output > upperThres) return upperThres;
    else if (output < lowerThres) return lowerThres;
    return (uint16_t)output;
}


/*
 * gain: 1 - 4
 * UpperThres 2696 - 4096
 * LowerThres 0 - 1400
 */
uint16_t SoftClippingEffect1(uint16_t sampleInput, float drive, float gain){
    //Covert the signal from 0 -> 4096 to -1 -> 1
    float x = drive*(sampleInput*0.000488 - 1);            //scale input to -1 -> 1
    //Soft-clipping, amplify and covert the signal from (-2/3 -> 2/3) back to scale (0 - 4096)
    //float output = (gain * 0.3333)*(x*3072 - x*x*x*1024) + 2046;
    float output = gain*(x*1024 - x*x*x*341) + 2046;
    //Setting threshold
    if(output > 4096) return 4096;
    else if (output < 0) return 0;
    return (uint16_t)output;
}


uint16_t SoftClippingEffect2(uint16_t sampleInput, float drive, float gain){
    float xabs;
    //float x = 10*drive*((sampleInput)*0.000488 - 1);
    float x = drive*(sampleInput*0.00488 - 10);
    if(x >= 0) xabs = x;
    else xabs = -x;
    //float output = gain*0.3333*(x/(1+xabs))*2048 + 2048;
    float output = gain*683*(x/(1+xabs)) + 2048;
    if(output > 4096) return 4096;
    else if (output < 0) return 0;
    return (uint16_t)output;
}



/*
 * gain: 0.5 - 1.5
 * drive 0 - 4
 * UpperThres 2696 - 4096
 * LowerThres 0 - 1400
 */
uint16_t TanhDistortionEffect(uint16_t sampleInput, float drive, float gain){
    float x = 5*((sampleInput+60)*0.000488 - 1);
    //float output = (gain * 0.3333)*((FastTanh(drive*x)) * 2048) + 2048;
    float output = gain*FastTanh(drive*x)*683 + 2048;
    if(output > 4096) return 4096;
    else if (output < 0) return 0;
    return (uint16_t)output;
}
