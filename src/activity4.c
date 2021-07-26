/**
 * @file activity4.c
 * @author 260842 - K.Nagasowmika
 * @brief
 * @version 0.1
 * @date 2021-04-29
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "activity4.h"
#include "activity1.h"
#include <avr/interrupt.h>

void UARTinit(uint16_t ubrr_value){

    UBRR0L = ubrr_value;
    UBRR0H = (ubrr_value>>8)&(0x00ff);
    UCSR0C = (1<<UMSEL00)|(1<<UCSZ00)|(1<<UCSZ01);

    UCSR0B = (1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0)|(1<<TXCIE0);

}


/**
 * @brief Function to read characters coming from the UART port
 *
 * @return char
 */
char UARTreadchar(){

while(UART_DATA_NOT_RECEIVED){

}

return UDR0;

}


/**
 * @brief  Function to write characters to send it to other port of UART
 *
 * 
 */
void UARTwritecharacter(char data){

while(UART_DATA_NOT_WRITTEN){

}
UDR0 = data;

}
