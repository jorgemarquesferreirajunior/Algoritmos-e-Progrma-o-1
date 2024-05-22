#include "analogico.c"

#define ALTA_PRIORIDADE				0x08
#define flagTimer0					INTCONbits.TMR0IF 
#define flagTimer1					PIR1bits.TMR1IF

void delay_ms (unsigned int tempo);
void interrupcaoRelogio(void);
void configInterrupcaoRelogio(void);
void configTimer1(void);
void setTimer1(void);
void configTimer0(void);
void setTimer0(void);
void atualizaRelogio(void);
void mostrarRelogio(void);
void setupRelogio(void);
void configPWM(void);
void piscaCursor(void);

//-----------------------------------setup-timer-pwm-----------------------------------//
// SUB-ROTINA PARA DEFINICAO DE PRIORIDADE DA INTERRUPCAO
#pragma code high_vector=ALTA_PRIORIDADE
void interrupt_at_high_vector(void)
{
  _asm GOTO interrupcaoRelogio _endasm
}
#pragma code

// SUB-ROTINA PARA GERAR UMA PAUSA NO CODIGO
void delay_ms (unsigned int tempo)
{
	while(tempo > 0){
		Delay100TCYx(10);
		tempo--;
	}
}

// SUB-ROTINA PARA GERAR UMA INTERRUPCAO BASEADA NO OVERFLOW DO TIMER0
void interrupcaoRelogio(void)
{
	if(flagTimer0 == 1)
	{
		conta_cursor ++;
		cursor_visivel = !cursor_visivel;
		if (conta_cursor == 2)
		{
			conta_cursor = 0;
		
			if(boas_vindas > 0 ) boas_vindas --;
			variavel_teste --;
			secs++;
			
			if(secs == 0x3c)
			{
				secs = 0x00;
				mins++;
				if(mins == 0x3c)
				{
					mins = 0x00;
					hours++;
					if(hours == 0x18)
					{
						hours = 0x00;
						if (dias == 6) dias = 0x00;
						else dias++;
					}
				}
			}
		}
		setTimer0();
	}
}

// SUB-ROTINA PARA CONFIGURACAO DA INTERRUPCAO DE ATUALIZACAO DO RELOGIO
void configInterrupcaoRelogio(void)
{
   // Configura??o das interrup??es	
   RCONbits.IPEN 	= 0; // Desabilita atribuicao de prioridades ?s interrup??es
   INTCONbits.GIE 	= 1; // Habilita todas as interrup??es
   INTCONbits.PEIE 	= 1; // Habilita interrupcoes geradas a partir de perif?ricos do PIC
   INTCONbits.TMR0IE = 1; // Habilita interrupcao do Timer0
   
}

// SUB-ROTINA PARA CONFIGURACAO DO TIMER1
void configTimer1(void)
{
	T1CONbits.RD16		= 1; //contador de 8 bits (0) / contador de 16 bits (1)
	T1CONbits.T1RUN 	= 1; //fonte de clock: oscilador interno (1) / outra fonte (0)
	T1CONbits.T1CKPS1	= 0; // T1CKPS1:T1CKPS0 ? Configura??o do prescaler ? 00 (1:1), 01 (1:2), 10 (1:4), 11 (1:8)
	T1CONbits.T1CKPS0	= 0;
	T1CONbits.T1OSCEN 	= 1; // (modo de eco. de ener.) ? habilita (1) desliga o oscilador interno (0)
	T1CONbits.T1SYNC	= 0; // (somente no modo contador) ? modo s?ncrono (0) ou ass?ncrono (1)
	T1CONbits.TMR1CS	= 0; //modo contador ou economia de energia (1) / temporizador (0)
	T1CONbits.TMR1ON	= 1; //habilita o contador (1) , para o contador (0)
	setTimer1();
}

// SUB-ROTINA PARA DEFINICAO DE INICIO DO TIMER1
void setTimer1(void)
{
   flagTimer1 = 0;
   TMR1H = 0xC0;          
   TMR1L = 0x00;
}

// SUB-ROTINA PARA CONFIGURACAO DO TIMER0
void configTimer0(void)
{
	T0CONbits.TMR0ON	= 1; //habilita o contador (1) , para o contador (0)
	T0CONbits.T08BIT 	= 0; //contador de 8 bits (1) / contador de 16 bits (0)
	T0CONbits.T0CS  	= 0; //fonte de clock: oscilador interno (0) / proveniente do pino T0CKI 0 (1)
	T0CONbits.T0SE		= 0; // Ignorado se T0CS = 0 1 = incremento na borda de descida do pino T0CKI 0 = incremento na borda de subida do pino T0CKI	
	T0CONbits.PSA		= 0; // 1 = PRESCALER n�o utilizado 0 = PRESCALER habilitado de acordo com a configura��o dos bits T0PS2:T0PS0	
	/*
	T0PS2:T0PS0
	Ignorado se PSA = 1
	111 = divide o clock na raz�o 1:256
	110 = divide o clock na raz�o 1:128
	101 = divide o clock na raz�o 1:64
	100 = divide o clock na raz�o 1:32
	011 = divide o clock na raz�o 1:16
	010 = divide o clock na raz�o 1:8
	001 = divide o clock na raz�o 1:4
	000 = divide o clock na raz�o 1:2	
	*/
	T0CONbits.T0PS2 	= 0; 
	T0CONbits.T0PS1		= 1; 
	T0CONbits.T0PS0		= 1;
	
	setTimer0();
}

// SUB-ROTINA PARA DEFINICAO DE INICIO DO TIMER0
void setTimer0(void)
{
   flagTimer0 = 0;
   // 0.5 segundo
   TMR0H = 0x85;          
   TMR0L = 0xEE;
}

// SUB-ROTINA PARA ATUIZACAO DO TEXTO DO RELOGIO
void atualizaRelogio(void)
{
	relogio[1] = hours%10 + '0';
	relogio[0] = hours/10 + '0';
	
	relogio[4] = mins%10 + '0';
	relogio[3] = mins/10 + '0';
	
	relogio[9] = secs%10 + '0';
	relogio[8] = secs/10 + '0';
}

// SUB-ROTINA PARA MOSTRAR O RELOGIO
void mostrarRelogio(void)
{
	unsigned char i = 0;
	setCursorLCD_i2c(1,4);
	
	for(i=0;i<14;i++) printCharLCD_i2c(relogio[i]);
	setCursorLCD_i2c(2,0);
	switch(dias)
	{
		case 0:
			printStringLCD_i2c("      DOMINGO       ");
			break;
		case 1:
			printStringLCD_i2c("   SEGUNDA-FEIRA    ");
			break;
		case 2:
			printStringLCD_i2c("    TERCA-FEIRA     ");
			break;
		case 3:
			printStringLCD_i2c("    QUARTA-FEIRA    ");
			break;
		case 4:
			printStringLCD_i2c("    QUINTA-FEIRA    ");
			break;
		case 5:
			printStringLCD_i2c("    SEXTA-FEIRA     ");
			break;
		case 6:
			printStringLCD_i2c("       SABADO       ");
			break;
		default:
			printStringLCD_i2c("                    ");
			break;
	}
}

// SUB-ROTINA PARA FAZER O CURSOR DO DUSPLAY PISCAR
void piscaCursor(void)
{	
	if(cursor_visivel)	printCharLCD_i2c('>');
	else				printCharLCD_i2c('  ');
}

// SUB-ROTINA PARA INICIALIZACAO DO RELOGIO
void setupRelogio(void)
{
	linha = 0; coluna = 12;

	while(!flag_btn[left])
	{
		lerBtnUp();
		lerBtnDown();
		lerBtnLeft();

		setCursorLCD_i2c(0, coluna+2); printShortLCD_i2c(hours);
		setCursorLCD_i2c(1, coluna+2); printShortLCD_i2c(mins);
		setCursorLCD_i2c(2, coluna+2); printShortLCD_i2c(secs);

		if (flag_btn[up])
		{
			flag_btn[up] = 0;
			setCursorLCD_i2c(linha, coluna); printCharLCD_i2c('  ');
			if (linha == 0) linha = 2;
			else linha --;
		}

		if (flag_btn[down])
		{
			flag_btn[down] = 0;
			setCursorLCD_i2c(linha, coluna); printCharLCD_i2c('  ');
			if (linha == 2) linha = 0;
			else linha ++;
		}

		setCursorLCD_i2c(3, 19);printShortLCD_i2c(indice);
		setCursorLCD_i2c(linha, coluna);piscaCursor();
	}
	resetBotoes();
	linha = 1, coluna = 0;
}

// SUB-ROTINA PARA CONFIGURACAO DO PWM1
void configPWM(void)
{
	// Inicializa do Timer2: respons�vel por determinar a frequ�ncia dos canais PWM

	// Configuracao do POSTSCALER - T2OUTPS3:T2OUTPS0 - 0000 (1:1) ATE 1111 (1:16)
	T2CONbits.T2OUTPS3 = 0;T2CONbits.T2OUTPS2 = 0;T2CONbits.T2OUTPS1 = 0;T2CONbits.T2OUTPS0 = 0;
	T2CONbits.TMR2ON = 1; // Habilita (1) / Desabilita (0) o contador
	
	//Configura��o do prescaler - T2CKPS1:T2CKPS0 - 00 (SEM DIVISAO) 01 (1:4) 1X (1:16)
	T2CONbits.T2CKPS1 = 0;T2CONbits.T2CKPS0 = 0;
	PIR1bits.TMR2IF = 0; // Limpa flag de overflow do Timer2
	
	/*
	Fosc = Frequencia do microcontrolador
	1/Fosc = Tosc = Periodo do microcontrolador
	Tpwm = Tosc*4*TMR2Prescale*(PR2+1) = Periodo do PWM
	PR2 = (Tpwm / (Tosc*4*TMR2Prescale)) - 1
	*/
	
	// Fpwm = 10KHz -> Tpwm = 1/Fpwm = 100us
	// Fosc = 4MHz  -> Tosc = 1/Fosc = 250ns
	// PR2 = (100us / (250ns*4*1)) - 1 = 99

	PR2 = 100;
	/*
	DC1B1:DC1B0 � bits 1 e 0 do Duty Cycle do PWM1
	CCP1M3:CCP1M0 � Configura��o do m�dulo CCP1
	0000 (CCP desabilitado)
	0001 (reservado)
	0010 (Modo Compara��o)
	0011 (reservado) ATE 1011 (reservado) 1011 (Modo Compara��o)
	11xx (Modo PWM)
	1100 � sa�da ativo alto
	1101 � sa�da ativo alto
	1111 � sa�da ativo baixo (pwm invertido)
	1111 � sa�da ativo baixo (pwm invertido)
	*/

	CCP1CONbits.DC1B1 = 0;CCP1CONbits.DC1B0 = 0;
	CCP1CONbits.CCP1M3 = 1;CCP1CONbits.CCP1M2 = 1;CCP1CONbits.CCP1M1 = 0;CCP1CONbits.CCP1M0 = 0;
	
	// DCpwm = DUTY CYCLE
	// CCPR1L = DCpwm * (PR2+1) = 0,5*100 = 50
	// Ton = Tosc*CCPR1L*4*TRM2Prescaler = 125us
	
	velocidadePWM_Motor_Tambor  = 30;

	// Inicializa do Timer2: respons�vel por determinar a frequ�ncia dos canais PWM
  //T2CON = 0x04;        // POSTSCALER: 1:1, ligado, PRESCALER 1:1
  //PIR1bits.TMR2IF = 0; // Limpa flag de overflow do Timer2
  //PR2 = 100;            // Per�odo do Timer2 (Fpwm=10KHz, Fosc=4MHz)
	
  // Inicializa PMW 1 com Ajuste 30%
  //CCP1CON = 0x0C; // LSBs do duty cycle = 00 (n�o usado em 8 bits), opera��o como PWM (canal 1 Ativo alto)
  //CCPR1L  = 30;   // 8 bits mais significativos do duty cycle (PWM1)
}
