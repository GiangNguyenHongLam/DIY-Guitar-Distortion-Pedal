/*
 * FastMathApproximation.c
 *
 *  Created on: Oct 19, 2019
 *      Author: lamgiang
 */


#include"FastMathApproximation.h"


/** Using Pade Approximation to estimate tanh() function

    https://varietyofsound.wordpress.com/2011/02/14/efficient-tanh-computation-using-lamberts-continued-fraction/
    Also as noted in JUCE DSP module, this function should only work with an input range between -5 to 5 to limit the errors
*/
float FastTanh(float x){

    float x2 = x*x;
    float num = x * (135135 + x2 * (17325 + x2 * (378 + x2)));
    float den = 135135 + x2 * (62370 + x2 * (3150 + 28 * x2));
    return num / den;
}

