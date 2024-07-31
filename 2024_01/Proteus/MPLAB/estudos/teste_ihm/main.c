/* Teste da placa IHM com circuito auxiliar (1 trimpot, 1 bot?o, 6 leds)   */

// Inclus?o de bibliotecas
#include <p18f4550.h>
#include <delays.h>
#include <i2c.h>      // Biblioteca para comunica??o i2c

// Configura??es para grava??o
#pragma config FOSC = HS			// Oscilador: cristal de alta velocidade (HS)
#pragma config WDT = OFF			// Watchdog Timer desabilitado
#pragma config MCLRE = ON			// Reset em RE3 desabilitado
#pragma config LVP = OFF			// Desabilita Single-Supply ICSP

// Mapeamento de hardware
#define ADDRESSW  0x4E  // Endere?o i2c do m?dulo e o opera??o de escrita
#define BTN_ESQ   PORTDbits.RD0
#define BTN_CIMA  PORTDbits.RD1
#define BTN_BAIXO PORTDbits.RD2
#define BTN_DIR   PORTDbits.RD3
#define BTN_EXT		PORTBbits.RB2

// Prot?tipos das fun??es
void Initialize(void);
void ControlLCDi2c(unsigned char CMD);
void StartLCDi2c(void);
void WriteLCDi2c(unsigned char DATA);
void StringLCDi2c(unsigned char LINE, rom unsigned char *STR);
int i = 0;

// Fun??o principal
void main()
{
	unsigned short VAN0;

	// Inicializa??o das portas
	PORTA  = 0x00; PORTB = 0x00; PORTC = 0x00;  PORTD = 0x00;  
	LATA   = 0x00; LATB  = 0x00; LATC  = 0x00; LATD  = 0x00;
	TRISA  = 0x01; TRISB = 0x07; TRISC = 0x00; TRISD = 0x00;

	// Inicializa??o do m?dulo A/D
	ADCON2 = 0b10000001;    // Resultado justificado a direita, 0 Tad, Fosc/8
	ADCON1 = 0b00001110;    // Tens?es de refer?ncia padr?o, 1 entrada anal?gicas
	ADCON0 = 0b00000001;    // Seleciona o canal AN0 e ativa o m?dulo A/D
	
	OpenI2C(MASTER, SLEW_OFF); // Inicializa I2C: Mestre com velocidade de 100Khz.
  SSPADD = 9;                // Taxa de comunica??o I2C de 100khz (FOSC=4MHz)
  Delay1KTCYx(1);
  StartLCDi2c(); // Inicializa??o do LCD

	Delay1KTCYx(1);
	
	StringLCDi2c(1, "TESTE DO MODULO "); // Escreve texto no LCD usando fun??o de linha inteira
	StringLCDi2c(2, "  I2C PARA LCD  ");
	Delay10KTCYx(100);
	
	while(1)
	{       
		PORTDbits.RD1 = 1;
		for(i=0;i<1000;i++)
		{
			Delay100TCYx(10);
		}
		i = 0;
		PORTDbits.RD1 = 0;
		// Leitura da entrada anal?gica (canal AN0 selecionado na inicializa??o)
		ADCON0bits.GO_DONE = 1;     // Inicia a convers?o
		while(ADCON0bits.GO_DONE);  // Aguarda t?rmino da convers?o
		VAN0 = ADRES;               // L? resultado da convers?o AD
        
    Delay1KTCYx(1);
    if(VAN0 >= 512 && BTN_EXT == 0)
	  {
	
			StringLCDi2c(1, " BOTAO EXTERNO  "); // Escreve texto no LCD usando fun??o de linha inteira
			StringLCDi2c(2, "  PRESSIONADO   ");
			
			PORTAbits.RA1 = 1;
			PORTAbits.RA2 = 1;
			PORTAbits.RA3 = 1;
			PORTAbits.RA4 = 1;
			PORTAbits.RA5 = 1;
			PORTBbits.RB3 = 1;
		}
		else
		{
			PORTAbits.RA1 = 0;
			PORTAbits.RA2 = 0;
			PORTAbits.RA3 = 0;
			PORTAbits.RA4 = 0;
			PORTAbits.RA5 = 0;
			PORTBbits.RB3 = 0;
			if(BTN_ESQ == 0)
			{
				PORTAbits.RA1 = 1;
				StringLCDi2c(1, " BOTAO ESQUERDA "); // Escreve texto no LCD usando fun??o de linha inteira
				StringLCDi2c(2, "  PRESSIONADO   ");
			}	
			else PORTAbits.RA1 = 0;
			if(BTN_BAIXO == 0)
			{
				PORTAbits.RA2 = 1;
				StringLCDi2c(1, " BOTAO BAIXO    "); // Escreve texto no LCD usando fun??o de linha inteira
				StringLCDi2c(2, "  PRESSIONADO   ");
			}	
			else PORTAbits.RA2 = 0;
			if(BTN_DIR == 0)
			{
				PORTAbits.RA3 = 1;
				StringLCDi2c(1, " BOTAO DIREITA  "); // Escreve texto no LCD usando fun??o de linha inteira
				StringLCDi2c(2, "  PRESSIONADO   ");
			}	
			else PORTAbits.RA3 = 0;
			if(BTN_CIMA == 0)
			{
				PORTAbits.RA4 = 1;
				StringLCDi2c(1, " BOTAO CIMA     "); // Escreve texto no LCD usando fun??o de linha inteira
				StringLCDi2c(2, "  PRESSIONADO   ");
			}	
			else PORTAbits.RA4 = 0;
		}
	
	}
}


// Rotina que envia uma instru??o de inicializa??o ou configura??o para o LCD
void ControlLCDi2c(unsigned char CMD)
{
  unsigned char LCD;

  IdleI2C(); StartI2C();         // Inicia comunica??o I2C
  IdleI2C(); WriteI2C(ADDRESSW); // Define dispositivo e opera??o de escrita
  LCD = 0xF0 & CMD;              // Separa parte alta da instru??o
  LCD = (LCD | 0x0C);            // Ativa backlight (P3=1), modo instru??o (RS=0) e habilita o display (E=1)
  IdleI2C(); WriteI2C(LCD);      // Envia instru??o
  Delay10TCYx(2);                // Aguarda 20 instrucoes
  LCD = (LCD & 0xF8);            // Desabilita o display (E=0)
  IdleI2C(); WriteI2C(LCD);      // Envia instru??o
  LCD = (CMD<<4) & 0xF0;         // Separa parte baixa da instru??o
  LCD = (LCD | 0x0C);            // Ativa backlight (P3=1), modo instru??o (RS=0) e habilita o display (E=1)
  IdleI2C(); WriteI2C(LCD);      // Escreve instru??o
  Delay10TCYx(2);                // Aguarda 20 instrucoes
  LCD = (LCD & 0xF8);            // Desabilita o display (E=0)
  IdleI2C(); WriteI2C(LCD);      // Envia instru??o
  IdleI2C(); StopI2C();          // Finaliza comunica??o I2C
  Delay1KTCYx(5);  	             // Aguarda 5ms
}

// Rotina que realiza a inicializa??o do LCD
void StartLCDi2c(void)
{
  Delay1KTCYx(20);     // Aguarda pelo menos 15ms
  ControlLCDi2c(0x30); // Instru??o de inicializa??o
  Delay1KTCYx(30);  	             // Aguarda 30ms
  ControlLCDi2c(0x30); // Instru??o de inicializa??o
  Delay1KTCYx(30);  	             // Aguarda 30ms
  ControlLCDi2c(0x30); // Instru??o de inicializa??o
  Delay1KTCYx(30);  	             // Aguarda 30ms
  ControlLCDi2c(0x02); // Define interface de 4 bits
  ControlLCDi2c(0x28); // Define interface de 4 bits e display de 2 linhas
  ControlLCDi2c(0x06); // Modo de entrada: desloca cursor para direita sem deslocar a mensagem
  ControlLCDi2c(0x0C); // Desliga cursor
  ControlLCDi2c(0x01); // Limpa display
}

// Rotina que envia um caractere a ser escrito no LCD
void WriteLCDi2c(unsigned char DATA)
{
  unsigned char LCD;

  IdleI2C(); StartI2C();         // Inicia comunica??o I2C
  IdleI2C(); WriteI2C(ADDRESSW); // Define dispositivo e opera??o de escrita
  LCD = 0xF0 & DATA;             // Separa parte alta do dado
  LCD = LCD | 0x0D;              // Ativa backlight (P3=1), modo dados (RS=1) e habilita o display (E=1)
  IdleI2C(); WriteI2C(LCD);      // Envia dado
  Delay10TCYx(10);               // Aguarda 10us
  LCD = (LCD & 0xF9);            // Desabilita o display (E=0)
  IdleI2C(); WriteI2C(LCD);      // Envia dado
  LCD = (DATA<<4) & 0xF0;        // Separa parte baixa do dado
  LCD = LCD | 0x0D;              // Ativa backlight (P3=1), modo dados (RS=1) e habilita o display (E=1)
  IdleI2C(); WriteI2C(LCD);      // Envia dado
  Delay10TCYx(10);               // Aguarda 10us
  LCD = (LCD & 0xF9);            // Desabilita o display (E=0)
  IdleI2C(); WriteI2C(LCD);      // Envia dado
  IdleI2C(); StopI2C();          // Para comunica??o I2C
  Delay1KTCYx(5);  	             // Aguarda 5ms
}

// Rotina que escreve uma linha completa no LCD
void StringLCDi2c(unsigned char LINE, rom unsigned char *STR)
{
  if(LINE == 1) ControlLCDi2c(0x80);
  if(LINE == 2) ControlLCDi2c(0xC0);

  // Escreve todos os caracteres at? encontrar o final do ponteiro
  while(*STR != '\0')
  {
    WriteLCDi2c(*STR);
    ++STR;
  }
}