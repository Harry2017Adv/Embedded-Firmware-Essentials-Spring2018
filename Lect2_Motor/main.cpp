/* Lecture 2 - Motor Control Example */
#include "mbed.h"

DigitalOut motor(p5);


int main() 
{
    while(1) 
    {
        motor = 1;
        wait(5.);
        motor = 0;
        wait(2.5);
    }
}
