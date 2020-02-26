/*
 * InputOutputLED.c
 *
 *  Created on: Aug 27, 2019
 *      Author: lamgiang
 */

/*
void InputOutputLED(){
    GPIOEnableSinglePort(PORTF);
    GPIOSetMode(GPIO_PORTF_BASE, PIN_1|PIN_2|PIN_3, OUTPUT_MODE);

    GPIOPinUnlock(GPIO_PORTF_BASE, PIN_0);
    GPIOPullupResisterEnable(GPIO_PORTF_BASE, PIN_0|PIN_4);

    GPIOSetMode(GPIO_PORTF_BASE, PIN_0|PIN_4, INPUT_MODE);
    GPIOPinWrite(GPIO_PORTF_BASE, PIN_1, PIN_1);

    PORTF_DATA |= (PIN_1 | PIN_2 | PIN_3);

    GPIOPinWrite(GPIO_PORTF_BASE, PIN_1|PIN_2|PIN_3, PIN_1|PIN_2|PIN_3);


    while(1){
        switch (GPIOPinRead(GPIO_PORTF_BASE, PIN_0|PIN_4) & (PIN_0|PIN_4)){
        case 0x00: //Both switch are pressed
            GPIOPinWrite(GPIO_PORTF_BASE, PIN_1, PIN_1);
            GPIOPinWrite(GPIO_PORTF_BASE, PIN_2|PIN_3, 0);
            break;
        case 0x01: //Switch 0 is pressed
            GPIOPinWrite(GPIO_PORTF_BASE, PIN_2, PIN_2);
            GPIOPinWrite(GPIO_PORTF_BASE, PIN_1|PIN_3, 0);
            break;
        case 0x10:
            GPIOPinWrite(GPIO_PORTF_BASE, PIN_3, PIN_3);
            GPIOPinWrite(GPIO_PORTF_BASE, PIN_1|PIN_2, 0);
            break;
        default:
            GPIOPinWrite(GPIO_PORTF_BASE, PIN_1|PIN_2|PIN_3, 0);
        }
    }
}
*/
