/**
 * @file main.c
 * @author 260842 - K.Nagasowmika
 * @brief
 * @version 0.1
 * @date 2021-04-28
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <avr/io.h>
#include <util/delay.h>
#include "activity1.h"
#include "activity2.h"
#include "activity3.h"
#include "activity4.h"

/**
 * @brief Main function
 *
 * @return int
 */
int main(void)
{
    activity1();
    InitADC();
    activity3();
    uint16_t temp;
    UARTinit(103);


    while(1)
    {
       if(!(BUTTON_ON || HEATER_ON)) {
        //setting if the input bit to 0th bit of pinB is made 0 from 1 by pressing led

                _delay_ms(20);
                SET_LED_ON; //set portB0 it will ON the led
                temp = ReadADC(1); // setting channel to 1
                 PWMoutput(temp); //generates PWM output
                _delay_ms(200);


        }
        else
        {
                _delay_ms(20);
                OCR1A = 0; //if IF condtion fails PWM is set to 0
                SET_LED_OFF; //clear 0th bit of portB and it will OFF the led
        }
    }

 return 0;
}
