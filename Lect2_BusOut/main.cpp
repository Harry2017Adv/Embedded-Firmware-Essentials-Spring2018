/* Lecture 2 - BusOut() Examples */

#include "mbed.h"


BusOut led(LED1,LED2,LED3,LED4);


int main() 
{
    while(1) 
    {
    	for(int i= 0; i<=0xF; ++i)
    	{
    		led = i;
    		wait_ms(500);
    	}
    }
}
