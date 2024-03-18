#include <xc.h> 
__PROG_CONFIG(1,0x3FE4);
__PROG_CONFIG(2,0x1EFF);
#define _XTAL_FREQ 16000000 
#define LED_apas_scurt RB1 
#define LED_apas_mediu RB2
#define LED_apas_lung RB3

void init_uC (void);
void main(void)
{
	init_uC(); 
	while (1) 
	{
		if(RB0==0)
		{
			__delay_ms(800);
			if(RB0==1) LED_apas_scurt = 1;
				else
				{
					__delay_ms(1800);
					if(RB0==1) LED_apas_mediu = 1;
					else LED_apas_lung = 1;
				}
			__delay_ms(3000);
			PORTB = 0b00000000;
		}
	}
}

void init_uC (void)
{
	OSCCON = 0x7B; 
	TRISB = 0b00000001; 
	PORTB = 0b00000000;
	ANSELB= 0b00000000;
}