/*********************************************************************************************************/
//
// Lecture 4 - ADXL345 Using SPI
//
//
//
/*********************************************************************************************************/
#include "mbed.h"
#include "ADXL345.h"


//SPI acc(p11,p12,p13);  // MOSI (SDA), MISO (SDO), SCL
//DigitalOut cs(p14);
Serial pc(USBTX,USBRX);


float x, y, z;

int main() 
{
	pc.baud(115200);
	pc.printf("Starting ADXL345 Test...\r\n\r\n");
	// Initialize ADXL345
	ADXL345_init();


	while(1)
	{
		wait_ms(200);


		ADXL345_meas();


		x = acc_x();
		y = acc_y();
		z = acc_z();
		pc.printf("x:  %+4.2f g, y:  %+4.2f g, z:  %+4.2f g\r\n",x,y,z);
	}
}

