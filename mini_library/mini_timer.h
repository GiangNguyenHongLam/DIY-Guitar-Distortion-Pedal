/*
 * mini_timer.h
 *
 *  Created on: Aug 27, 2019
 *      Author: lamgiang
 */

#ifndef MINI_LIBRARY_MINI_TIMER_H_
#define MINI_LIBRARY_MINI_TIMER_H_

//*****************************************************************************
//
// Values that can be passed to most of the timer APIs as the ui32SubTimer
// parameter.
//
//*****************************************************************************
#define TIMER_A                     0x000000FF
#define TIMER_B                     0x0000FF00
#define BOTH_TIMER                  0x0000FFFF

//*****************************************************************************
//
// Values that can be passed to most of the timer APIs as the ui32Timer
// parameter.
//
//*****************************************************************************
#define TIMER_0                     0x00000001
#define TIMER_1                     0x00000002
#define TIMER_2                     0x00000004
#define TIMER_3                     0x00000008
#define TIMER_4                     0x00000010
#define TIMER_5                     0x00000020


//*****************************************************************************
//
// Configuration bit masks
//
//*****************************************************************************
#define TIMERA_CFG_ONE_SHOT         0x00000021  // Timer A one-shot timer
#define TIMERA_CFG_ONE_SHOT_UP      0x00000031  // Timer A one-shot up-count timer
#define TIMERA_CFG_PERIODIC         0x00000022  // Timer A periodic timer
#define TIMERA_CFG_PERIODIC_UP      0x00000032  // Timer A periodic up-count timer
#define TIMERA_CFG_CAP_COUNT        0x00000003  // Timer A event counter
#define TIMERA_CFG_CAP_COUNT_UP     0x00000013  // Timer A event up-counter
#define TIMERA_CFG_CAP_TIME         0x00000007  // Timer A event timer
#define TIMERA_CFG_CAP_TIME_UP      0x00000017  // Timer A event up-count timer

#define TIMER_CTL_TAEN              0x00000001  //GPTM Timer A Enable
#define TIMER_CTL_TBEN              0x00000100  //GPTM Timer B Enable
#define TIMER_CTL_ADC_TAEN             0x00000021  //GPTM Timer B Enable
#define TIMER_CTL_ADC_TBEN             0x00002100  //GPTM Timer B Enable

#define TIMERA_INT_MASK_TIMEOUT     0x00000001  //GPTM Timer Mask Timeout
#define TIMERB_INT_MASK_TIMEOUT     0x00000100  //GPTM Timer Mask Timeout
#define TIMERA_INT_MASK_AB_TIMEOUT  0x00000101  //GPTM Timer Mask Timeout
#define TIMERA_INT_MASK_CAP_MATCH   0x00000002  //GPTM Timer Mask Capture Match
#define TIMERA_INT_MASK_CAP_EVENT   0x00000004  //GPTM Timer Mask Capture Event

#define TIMER0_A_INT_EN             19
#define TIMER0_B_INT_EN             20
#define TIMER1_A_INT_EN             21
#define TIMER1_B_INT_EN             22
#define TIMER2_A_INT_EN             23
#define TIMER2_B_INT_EN             24


#define TIMER_32_64BIT              0x00000000
#define TIMER_16_32BIT              0x00000004




//*****************************************************************************
//
// APIs Declaration
//
//*****************************************************************************

extern void TimerPeripheralEnable(uint32_t ui32Timer);
extern void TimerConfigure(uint32_t ui32TimerBase, uint32_t ui32SubTimer, uint32_t mode, uint8_t timerWidth);
extern void TimerEnable(uint32_t ui32TimerBase, uint32_t timer);
extern void TimerLoadSet(uint32_t ui32TimerBase, uint32_t timer, uint32_t ui32Value);
extern void TimerInterruptEnable(uint32_t ui32TimerBase, uint32_t timerInt, uint32_t intMode);
uint32_t getTimerAValue(uint32_t ui32TimerBase);
uint32_t getTimerBValue(uint32_t ui32TimerBase);
extern void TimerADCEnable(uint32_t ui32TimerBase, uint32_t ui32SubTimer);
extern void TimerADCEnable(uint32_t ui32TimerBase, uint32_t ui32SubTimer);

#endif /* MINI_LIBRARY_MINI_TIMER_H_ */
