#ifndef ACTIVITY2_H_INCLUDED
#define ACTIVITY2_H_INCLUDED
#include "Activity2.h"

void Init_ADC();

/**
 * @brief A funciton to receive temperature sensor inputs from analog pin and output it to a register ADC which has 2 8 bit registers ADCL and ADCH.
 *
 * @param ch
 * @return uint16_t
 */
uint16_t ReadADC(uint8_t ch);

/**
 * @brief A function to setup timer1 with channel A for pulse width modulation with wave generation mode of 10 bits fast PWM and prescaling of 64.
 *
 */


#endif // ACTIVITY2_H_INCLUDED
