#include"header.h"
#include<LPC21XX.H>

#define BULB (1<<17)
#define LED (1<<18)
#define SW1 ((IOPIN0>>14)&1)
#define SW2 ((IOPIN0>>15)&1)

int main()
{   
    unsigned short int ret;
    int automation = 1, manual = 0;
    float light;

	IODIR0 = LED | BULB;
    IOSET0 = LED | BULB;

    spi0_init();
	uart0_init(9600);

	uart0_tx_string("SPI0 ADC\r\n");

    while(1)
    {
        ret = mcp3204_adc_read(2);
		delay_ms(250);

        light = 1 - ((float)ret/4095);

		if(automation == 1) IOCLR0 |= LED;
		else IOSET0 |= LED;

        if((automation == 1) && (light<0.5))
        {
            IOCLR0 |= BULB;
        }
        else if((automation == 1) && (light>=0.5))
        {
            IOSET0 |= BULB;
        }

        if(SW1 == 0)
        {
            while(SW1 == 0);
            automation = !automation;
        }

        if(SW2 == 0)
        {
            while(SW2 == 0);
			automation = 0;
            if(manual == 0)
            {
                manual = 1;
                IOCLR0 |= BULB;
            }
            else if(manual == 1)
            {
                manual = 0;
                IOSET0 |= BULB;
            }
        }
    }
}
