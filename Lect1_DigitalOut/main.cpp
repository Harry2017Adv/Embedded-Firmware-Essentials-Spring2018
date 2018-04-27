/* Lecture 1 DigitalOut Example
*/
#include "mbed.h"

DigitalOut myled(LED1);


int main() 
{
    while(1) 
    {
        myled = 1;
        printf("Blink\r\n");
        wait(0.2);
        myled = 0;
        wait(0.2);
    }
}
