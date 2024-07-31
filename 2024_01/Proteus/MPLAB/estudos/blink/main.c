#include <p18F4550.h>
#include <delays.h>

#pragma config FOSC		= HS
#pragma config PWRT 	= ON
#pragma config WDT 		= OFF
#pragma config MCLRE	= OFF
#pragma config LVP 		= OFF

void delay_ms (unsigned int tempo);

void main()
{
	
	PORTA = 0x00; LATA = 0x00; TRISA = 0x00; 
	PORTB = 0x00; LATB = 0x00; TRISB = 0x00; 
	PORTC = 0x00; LATC = 0x00; TRISC = 0x00; 
	PORTD = 0x00; LATD = 0x00; TRISD = 0x0F; 
	PORTE = 0x00; LATE = 0x00; TRISE = 0x00;
	
	ADCON2 = 0x81;
	ADCON1 = 0x0F;
	ADCON0 = 0x01;
	CMCON = 0x07;
	
	while(1)
	{
		PORTDbits.RD2 = !PORTDbits.RD2;
		delay_ms(4000);
	}

}

void delay_ms (unsigned int tempo)
{
	while(tempo > 0){
		Delay100TCYx(10);
		tempo--;
	}
}