/* Lecture 2 - Motor PWM Control Example */
#include "mbed.h"


float delay_sec = 4.;
unsigned int pwm_period_us = 10000;

PwmOut motor(p21);

Serial pc(USBTX, USBRX);


int main() 
{
	motor.period_us(pwm_period_us);

	pc.printf("\r\n\r\nPWM DC Motor Speed Control\r\n\r\n");
	pc.printf("PWM period = %d us, ",pwm_period_us);
	pc.printf("PWM frequency = %.3f kHZ\r\n\r\n",1./pwm_period_us/1.e-6/1.e3);

	while(1)
    {
		motor = .5; // Set PWM to 50% duty cycle
		wait(5.);
		pc.printf("Motor PWM at 50% Duty Cycle\r\n");

		motor = 1.;	// Set PWM to 100% duty cycle
		pc.printf("Motor PWM at 100% Duty Cycle\r\n");
		wait(5.);

    }
}
