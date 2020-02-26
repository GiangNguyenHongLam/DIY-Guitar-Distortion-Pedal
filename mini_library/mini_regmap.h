/*
 * mini_regmap.h: a reduced and modified version of TivaWare's hw_memmap.h
 *
 *  Created on: Aug 25, 2019
 *      Author: lamgiang
 */

#ifndef MINI_LIBRARY_MINI_REGMAP_H_
#define MINI_LIBRARY_MINI_REGMAP_H_

//Macro to get hardware register
#define HWREG(x) (*((volatile uint32_t *)(x)))




//*****************************************************************************
//
// The following values are all the registers and offset used in GPIO feature
//
//*****************************************************************************

//RCGCGPIO register address, used for enabling or disabling GPIO modules in Run Mode
#define SYSCTL_RCGCGPIO_R       (*((volatile uint32_t *)0x400FE608))


//GPIO Base Port (ui32PortBase)
#define GPIO_PORTA_BASE             0x40004000  // GPIO Port A
#define GPIO_PORTB_BASE             0x40005000  // GPIO Port B
#define GPIO_PORTC_BASE             0x40006000  // GPIO Port C
#define GPIO_PORTD_BASE             0x40007000  // GPIO Port D
#define GPIO_PORTE_BASE             0x40024000  // GPIO Port E
#define GPIO_PORTF_BASE             0x40025000  // GPIO Port F

//GPIO Offset
#define GPIO_DATA_OFFSET            0x00000000  // GPIO Data
#define GPIO_DIR_OFFSET             0x00000400  // GPIO Direction
#define GPIO_DEN_OFFSET             0x0000051C  // GPIO Digital Enable
#define GPIO_PULLUP_RES_OFFSET      0x00000510  // GPIO Pull-up resister
#define GPIO_PULLDOWN_RES_OFFSET    0x00000514  // GPIO Pull-down resister
#define GPIO_LOCK_OFFSET            0x00000520  // GPIO Lock
#define GPIO_CR_OFFSET              0x00000524  // GPIO Commit
#define GPIO_AFSEL_OFFSET           0x00000420  // GPIO Alternative Function register
#define GPIO_AMSEL_OFFSET           0x00000528  // GPIO Analog Mode Select
#define GPIO_PCTL_OFFSET            0x0000052C  // GPIO Port Control
#define GPIO_IS_OFFSET              0x00000404  // GPIO Interrupt Sense
#define GPIO_IBE_OFFSET             0x00000408  // GPIO Interrupt Both Edges
#define GPIO_IEV_OFFSET             0x0000040C  // GPIO Interrupt Event
#define GPIO_IM_OFFSET              0x00000410  // GPIO Interrupt Mask
#define GPIO_ICR_OFFSET             0x0000041C  // GPIO Raw Interrupt Status
#define GPIO_MIS_OFFSET             0x00000418  // GPIO Masked Interrupt Status

//*****************************************************************************
//
// The following values are all the registers and offset used in General-purpose Timer feature
//
//*****************************************************************************

#define SYSCTL_RCGCTIMER_R          (*((volatile uint32_t *)0x400FE604))

//Register base address
#define TIMER0_BASE                 0x40030000  // Timer0
#define TIMER1_BASE                 0x40031000  // Timer1
#define TIMER2_BASE                 0x40032000  // Timer2
#define TIMER3_BASE                 0x40033000  // Timer3
#define TIMER4_BASE                 0x40034000  // Timer4
#define TIMER5_BASE                 0x40035000  // Timer5

//Timer Offset
#define TIMER_CFG_OFFSET            0x00000000  //Timer configure
#define TIMER_CTL_OFFSET            0x0000000C  //TImer control
#define TIMER_TAMR_OFFSET           0x00000004  //GPTM Timer A mode
#define TIMER_TBMR_OFFSET           0x00000008  //GPTM Timer B mode
#define TIMERA_ITLR_OFFSET          0x00000028  //Timer A interval load
#define TIMERB_ITLR_OFFSET          0x0000002C  //Timer B interval load
#define TIMER_RIS_OFFSET            0x0000001C  //Timer Raw interrupt Status
#define TIMER_IM_OFFSET             0x00000018  //Timer Interrupt mask
#define TIMER_ICR_OFFSET            0x00000024  //Timer interrupt clear
#define TIMERA_VALUE_OFFSET         0x00000050  //Timer A value
#define TIMERB_VALUE_OFFSET         0x00000054  //Timer A value


//*****************************************************************************
//
// The following values are all the registers and offset used for ADC features
//
//*****************************************************************************

#define SYSCTL_RCGCADC_R       (*((volatile uint32_t *)0x400FE638))


#define ADC0_BASE                   0x40038000 // ADC 0 Base Address
#define ADC1_BASE                   0x40039000 // ADC 1 Base Address

#define ADC_ACTSS_OFFSET            0x00000000 // ADC Active Sample Sequencer
#define ADC_IM_OFFSET               0x00000008 // ADC Interrupt Mask
#define ADC_EMUX_OFFSET             0x00000014 // ADC Event Multiplexer select
#define ADC_SSMUX2_OFFSET           0x00000080 // ADC Sample Sequence Input Multiplexer Select 2
#define ADC_SSMUX3_OFFSET           0x000000A0 // ADC Sample Sequence Input Multiplexer Select 3
#define ADC_SSCTL2_OFFSET           0x00000084 // ADC Sample Sequence Control 2
#define ADC_SSCTL3_OFFSET           0x000000A4 // ADC Sample Sequence Control 3
#define ADC_ISC_OFFSET              0x0000000C // ADC Interrupt status and clear
#define ADC_RIS_OFFSET              0x00000004 // ADC Raw Interrupt status and clear
#define ADC_SSFIFO2_OFFSET          0x00000088 // ADC Sample Sequence 3 FIFO
#define ADC_SSFIFO3_OFFSET          0x000000A8 // ADC Sample Sequence 3 FIFO
#define ADC_SSFIFO2STAT_OFFSET      0x0000008c // ADC Sample Sequence 2 FIFO Status

//*****************************************************************************
//
// The following values are all the registers and offset used for Synchronous Serial Interface (SSI)
//
//*****************************************************************************
#define SYSCTL_RCGCSSI_R       (*((volatile uint32_t *)0x400FE61C))

#define SSI0_CR0          (*((volatile uint32_t *)0x40008000)) // SSI Control 0
#define SSI0_CR1          (*((volatile uint32_t *)0x40008004)) // SSI Control 1
#define SSI0_DR           (*((volatile uint32_t *)0x40008008)) // SSI Data
#define SSI0_CC           (*((volatile uint32_t *)0x40008FC8)) // SSI Clock Configuration
#define SSI0_CPSR         (*((volatile uint32_t *)0x40008010)) // SSI Clock Prescaler
#define SSI0_SR           (*((volatile uint32_t *)0x4000800C)) // SSI Status

#define SSI1_CR0          (*((volatile uint32_t *)0x40009000)) // SSI Control 0
#define SSI1_CR1          (*((volatile uint32_t *)0x40009004)) // SSI Control 1
#define SSI1_DR           (*((volatile uint32_t *)0x40009008)) // SSI Data
#define SSI1_CC           (*((volatile uint32_t *)0x40009FC8)) // SSI Clock Configuration
#define SSI1_CPSR         (*((volatile uint32_t *)0x40009010)) // SSI Clock Prescaler
#define SSI1_SR           (*((volatile uint32_t *)0x4000900C)) // SSI Status

//*****************************************************************************
//
// The following values are all the registers and offset used for Clock control
//
//*****************************************************************************

#define SYSCTL_RCC_R            0x400FE000
#define SYSCTL_RCC2_R           0x400FE070
#define SYSCTL_RIS_R            0x400FE050

//*****************************************************************************
//
// The following values are all the registers and offset used for Peripherals
//
//*****************************************************************************
#define PERIPHERALS_REG_BASE          (*((volatile uint32_t *)0xE000E000))

#define NVIC_EN0_R                    0xE000E100
#define NVIC_EN1_R                    0xE000E104
#define NVIC_EN2_R                    0xE000E108
#define NVIC_EN3_R                    0xE000E10C
#define NVIC_PRIO0_R                  0xE000E400
#define NVIC_PRIO4_R                  0xE000E410
#define NVIC_PRIO5_R                  0xE000E414
#define NVIC_PRIO12_R                 0xE000E430


#endif /* MINI_LIBRARY_MINI_REGMAP_H_ */
