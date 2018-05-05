/* Lecture 2 - PortOut() Example */
#include "mbed.h"

#define LED_MASK 0x00B40000
// LED1 is connected to Port 1, bit 18;  LED2 is connected to Port 1, bit 20
// LED3 is connected to Port 1, bit 21;  LED4 is connected to Port 1, bit 23
#define LED1_MASK 0x00040000
#define LED2_MASK 0x00100000
#define LED3_MASK 0x00200000
#define LED4_MASK 0x00800000

PortOut LEDPort(Port1, LED_MASK);

int main() 
{
	uint32_t value;
    while(1) 
    {
    	LEDPort = 0;
    	for(int i= 0; i<=0xF; ++i)
    	{
    		if(i&0x01) value = (1<<18);
    		else value = (0<<18);
    		LEDPort = LEDPort & ~(LED1_MASK);
    		LEDPort=  LEDPort |  value;

    		if(i&0x02) value = LED2_MASK;
    		else value = 0;
    		LEDPort = LEDPort & ~(LED2_MASK);
    		LEDPort=  LEDPort |  value;

    		if(i&0x04) value = LED3_MASK;
			else value = 0;
    		LEDPort = LEDPort & ~(LED3_MASK);
			LEDPort=  LEDPort |  value;

			if(i&0x08) value = LED4_MASK;
			else value = 0;
			LEDPort = LEDPort & ~(LED4_MASK);
			LEDPort=  LEDPort |  value;

    		wait_ms(250);
    	}
    }
}
