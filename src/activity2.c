#include "activity2.h"
#include <avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>

/**
 * @brief This is the function to initialise the analog to digital converter
 *
 */
void InitADC()
{
 ADMUX=(1<<REFS0);
 ADCSRA=(1<<ADEN)|(7<<ADPS0);
}
/**
 * @brief A funciton to receive temperature sensor inputs from analog pin and output it to a register ADC which has 2 8 bit registers ADCL and ADCH.
 *
 * @param ch
 * @return uint16_t
 */
 uint16_t ReadADC(uint8_t ch)
 {
     ADMUX&=0xf8;
     ch=ch&0b00000111;

     ADMUX|=ch;
     ADCSRA|=(1<<ADSC);

     while(!(ADCSRA&(1<<ADIF)))
     ADCSRA|=(1<<ADIF);
     return(ADC);
}
