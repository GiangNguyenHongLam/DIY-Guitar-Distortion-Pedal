/*
 * mini_sysctl.h
 *
 *  Created on: Sep 1, 2019
 *      Author: lamgiang
 */

#ifndef MINI_LIBRARY_MINI_SYSCTL_H_
#define MINI_LIBRARY_MINI_SYSCTL_H_

#define W16MHz_XTAL          0x15


#define RCC_BYPASS          0x00000800
#define RCC_USESYSDIV       0x00400000
#define RCC_OSCSRC          0x00000030
#define RCC_XTAL_M          0x000007C0
#define RCC_PWRDN           0x00002000

#define RCC2_PWRDN2         0x00002000
#define RCC2_BYPASS         0x00000800
#define RCC2_USERCC2        0x80000000
#define RCC2_OSCSRC2_M      0x00000070



extern void SysCtlClockSet_mini();

#endif /* MINI_LIBRARY_MINI_SYSCTL_H_ */
