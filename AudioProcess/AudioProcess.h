/*
 * AudioProcess.h
 *
 *  Created on: Sep 5, 2019
 *      Author: lamgiang
 */

#ifndef AUDIOPROCESS_AUDIOPROCESS_H_
#define AUDIOPROCESS_AUDIOPROCESS_H_


#define NUMBER_OF_MODES         5


/*
 * Basic operations
 */
extern uint16_t AudioProcessSampleBySample(uint16_t input, volatile  uint32_t *parameter,volatile bool bypassed);
extern void ParameterProcessing(volatile uint32_t* parameter, uint16_t* upperThres, uint16_t* lowerThres,
                                float* gain, float* drive1, float* drive2, uint8_t *pedalMode);
/*
 * Effects
 */
extern uint16_t HardClippingEffect(uint16_t sampleInput, uint16_t upperThres, uint16_t lowerThres, float gain);
extern uint16_t SoftClippingEffect1(uint16_t sampleInput, float drive, float gain);
extern uint16_t SoftClippingEffect2(uint16_t sampleInput, float drive, float gain);
extern uint16_t TanhDistortionEffect(uint16_t sampleInput, float drive, float gain);


#endif /* AUDIOPROCESS_AUDIOPROCESS_H_ */
