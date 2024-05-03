#include<18F4550.h>
//#include <p18f4550.h>
// XT: velocidade media para o oscilador
// NOLVP: modo de gravacao em baixa tensao desabilitado, pino RB4 habilitado para uso
// NOWDT: nao reiniciar o codigo quando trava
#fuses XT, NOLVP, NOWDT
#use delay(clock=4000000) // frequencia do clock: 4Mhz

void main()
{
	while(TRUE)
	{
		output_high(pin_b0);
		delay_ms(500);
		output_low(pin_b0);
		delay_ms(500);
	}
}