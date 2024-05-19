#include <p18F4550.h>
#include "funcoes.c"

void main()
{
	PORTA = 0x00; LATA = 0x00; TRISA = 0x01; 
	PORTB = 0x00; LATB = 0x00; TRISB = 0x03; 
	PORTC = 0x00; LATC = 0x00; TRISC = 0x03; 
	PORTD = 0x00; LATD = 0x00; TRISD = 0x0F; 
	PORTE = 0x00; LATE = 0x00; TRISE = 0x00;
	
	ADCON2 = 0x81;
	ADCON1 = 0x0E;
	ADCON0 = 0x01;
	CMCON = 0x07;
	
	configTimer1();
	configInterrupcaoRelogio();	

	OpenI2C(MASTER, SLEW_OFF); 	// Inicializa I2C: Mestre com velocidade de 100Khz.
	SSPADD = 9;                	// Taxa de comunica??o I2C de 100khz
	
	StartLCDi2c();	
	maskInit();
	atualizaIndice();

	LED_ON = 1;

	while(1)
	{
		TelaInicializacao();
		menuSelect();
	}
}