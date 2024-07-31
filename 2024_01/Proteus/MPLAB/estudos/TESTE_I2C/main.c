/* Exemplo de utilização de comunicação I2C com o relógio de tempo real DS1307 e o
   módulo expansor de saídas PCF8574.
*/

// Incusão de bibliotecas
#include <p18f4455.h>
#include <i2c.h>
#include <delays.h>

// Configurações de gravação
#pragma config FOSC = HS
#pragma config PWRT = ON
#pragma config WDT = OFF
#pragma config MCLRE = OFF
#pragma config LVP = OFF

// Definições de rótulos
#define PCF8574W  0x4E  // Endereço i2c do expansor PCF8574 e o operação de escrita
#define DS1307W   0xD0  // Endereço i2c do RTC DS1307 e o operação de escrita
#define DS1307R   0xD1  // Endereço i2c do RTC DS1307 e o operação de leitura

// Variáveis globais
unsigned char SECONDS, MINUTES, HOURS, DAY_WEEK, DAY, MONTH, YEAR;

// Protótipos das funções
void ControlLCDi2c(unsigned char CMD);
void StartLCDi2c(void);
void WriteLCDi2c(unsigned char DATA);
void StringLCDi2c(unsigned char LINE, rom unsigned char *STR);
void StartRTC(void);
void ReadRTC(void);
void ShowRTCInfo(void);

// Programa principal
void main (void)
{
  // Inicialização
  PORTA = 0x00; PORTB = 0x00; PORTC = 0x00; PORTD = 0x00; PORTE = 0x00;
  LATA  = 0x00; LATB  = 0x00; LATC  = 0x00; LATD  = 0x00; LATE  = 0x00;
  TRISA = 0x00; TRISB = 0x03; TRISC = 0x00; TRISD = 0x00; TRISE = 0x00;
  ADCON1= 0x0F;
  CMCON = 0X07;
	
  OpenI2C(MASTER, SLEW_OFF); 	// Inicializa I2C: Mestre com velocidade de 100Khz.
  SSPADD = 9;                	// Taxa de comunicação I2C de 100khz

	StartLCDi2c(); 							// Inicializa LCD
	//StartRTC();									// Inicializa RTC

  while(1)
	{
		StringLCDi2c(1, "Hello World");
	//	ReadRTC();								// Lê as informações do TRC
	//	ShowRTCInfo();						// Apresenta data e hora no LCD
    Delay10KTCYx(100);		
  }	
}

// Rotina que envia uma instrução de inicialização ou configuração para o LCD
void ControlLCDi2c(unsigned char CMD)
{
  unsigned char LCD;

  IdleI2C(); StartI2C();        	// Inicia comunicação I2C
  IdleI2C(); WriteI2C(PCF8574W); 	// Define dispositivo e operação de escrita
  LCD = 0xF0 & CMD;             	// Separa parte alta da instrução
  LCD = (LCD | 0x0C);           	// Ativa backlight (P3=1), modo instrução (RS=0) e habilita o display (E=1)
  IdleI2C(); WriteI2C(LCD);     	// Envia instrução
  Delay10TCYx(1);               	// Aguarda 10us
  LCD = (LCD & 0xF8);           	// Desabilita o display (E=0)
  Delay10TCYx(1);               	// Aguarda 10us
  IdleI2C(); WriteI2C(LCD);     	// Envia instrução
  Delay10TCYx(5);               	// Aguarda 10us
  LCD = (CMD<<4) & 0xF0;        	// Separa parte baixa da instrução
  LCD = (LCD | 0x0C);           	// Ativa backlight (P3=1), modo instrução (RS=0) e habilita o display (E=1)
  IdleI2C(); WriteI2C(LCD);     	// Escreve instrução
  Delay10TCYx(1);               	// Aguarda 10us
  LCD = (LCD & 0xF8);           	// Desabilita o display (E=0)
  Delay10TCYx(1);               	// Aguarda 10us
  IdleI2C(); WriteI2C(LCD);     	// Envia instrução
  Delay10TCYx(5);               	// Aguarda 10us
  IdleI2C(); StopI2C();         	// Finaliza comunicação I2C
  Delay1KTCYx(5);  	            	// Aguarda 5ms
}

// Rotina que realiza a inicialização do LCD
void StartLCDi2c(void)
{
  Delay1KTCYx(20);     // Aguarda pelo menos 15ms
  Delay1KTCYx(20);     // Aguarda pelo menos 15ms
  ControlLCDi2c(0x30); // Instrução de inicialização
  Delay1KTCYx(5);      // Aguarda pelo menos 4.1ms
  ControlLCDi2c(0x30); // Instrução de inicialização
  Delay100TCYx(2);     // Aguarda pelo menos 100us
  ControlLCDi2c(0x30); // Instrução de inicialização
  ControlLCDi2c(0x02); // Define interface de 4 bits
  //ControlLCDi2c(0x28); // Define interface de 4 bits e display de 2 linhas
  ControlLCDi2c(0x28); // Define interface de 4 bits e display de 2 linhas
  ControlLCDi2c(0x06); // Modo de entrada: desloca cursor para direita sem deslocar a mensagem
  ControlLCDi2c(0x0C); // Desliga cursor
  ControlLCDi2c(0x01); // Limpa display
}

// Rotina que envia um caractere a ser escrito no LCD
void WriteLCDi2c(unsigned char DATA)
{
  unsigned char LCD;

  IdleI2C(); StartI2C();        	// Inicia comunicação I2C
  IdleI2C(); WriteI2C(PCF8574W); 	// Define dispositivo e operação de escrita
  LCD = 0xF0 & DATA;            	// Separa parte alta do dado
  LCD = LCD | 0x0D;             	// Ativa backlight (P3=1), modo dados (RS=1) e habilita o display (E=1)
  IdleI2C(); WriteI2C(LCD);     	// Envia dado
  Delay10TCYx(10);              	// Aguarda 10us
  LCD = (LCD & 0xF9);           	// Desabilita o display (E=0)
  Delay10TCYx(1);               	// Aguarda 10us
  IdleI2C(); WriteI2C(LCD);     	// Envia dado
	LCD = (DATA<<4) & 0xF0;      		// Separa parte baixa do dado
	LCD = LCD | 0x0D;             	// Ativa backlight (P3=1), modo dados (RS=1) e habilita o display (E=1)
  IdleI2C(); WriteI2C(LCD);     	// Envia dado
  Delay10TCYx(10);              	// Aguarda 10us
  LCD = (LCD & 0xF9);           	// Desabilita o display (E=0)
  IdleI2C(); WriteI2C(LCD);     	// Envia dado
  IdleI2C(); StopI2C();         	// Para comunicação I2C
  Delay1KTCYx(5);  	            	// Aguarda 5ms
}

// Rotina que escreve uma linha completa no LCD
void StringLCDi2c(unsigned char LINE, rom unsigned char *STR)
{
  if(LINE == 1) ControlLCDi2c(0x80);
  if(LINE == 2) ControlLCDi2c(0xC0);

  // Escreve todos os caracteres até encontrar o final do ponteiro
  while(*STR != '\0')
  {
    WriteLCDi2c(*STR);
    ++STR;
  }
}


// Rotina que inicializa o RTC
void StartRTC(void)
{
	IdleI2C();
  StartI2C();     		IdleI2C(); // Inicia comunicação I2C
  WriteI2C(DS1307W); 	IdleI2C(); // Define dispositivo e operação de escrita
  WriteI2C(0x00); 		IdleI2C(); // Define endereço inicial de escrita
  WriteI2C(0x00); 		IdleI2C(); // Escreve dado de segundos
  WriteI2C(0x19); 		IdleI2C(); // Escreve dado de minutos
  WriteI2C(0x16); 		IdleI2C(); // Escreve dado de horas
  WriteI2C(0x06); 		IdleI2C(); // Escreve dado do dia da semana
  WriteI2C(0x23); 		IdleI2C(); // Escreve dado do dia
  WriteI2C(0x10); 		IdleI2C(); // Escreve dado do mês
  WriteI2C(0x14); 		IdleI2C(); // Escreve dado do ano
  StopI2C();                 		 // Finaliza comunicação I2C
}

// Rotina que realiza a leitura do RTC
void ReadRTC(void)
{
	IdleI2C();
	StartI2C();           IdleI2C();                         // Inicia comunicação I2C
	WriteI2C(DS1307W);    IdleI2C();                         // Define dispositivo e operação de escrita
	WriteI2C(0x00);       IdleI2C();                         // Define endereço inicial para leitura
	RestartI2C();         IdleI2C();                         // Reinicia comunicação I2C
	WriteI2C(DS1307R);    IdleI2C();                      	 // Define dispositivo e operação de leitura
	SECONDS = ReadI2C();  IdleI2C(); AckI2C();    IdleI2C(); // Leitura dos segundos
	MINUTES = ReadI2C();  IdleI2C(); AckI2C();    IdleI2C(); // Leitura dos minutos
	HOURS = ReadI2C();    IdleI2C(); AckI2C();    IdleI2C(); // Leitura das horas
	DAY_WEEK = ReadI2C(); IdleI2C(); AckI2C();    IdleI2C(); // Leitura do dia da semana
	DAY = ReadI2C();      IdleI2C(); AckI2C();    IdleI2C(); // Leitura do dia
	MONTH = ReadI2C();    IdleI2C(); AckI2C();    IdleI2C(); // Leitura do mês
	YEAR = ReadI2C();     IdleI2C(); NotAckI2C(); IdleI2C(); // Leitura do ano
	StopI2C();                                               // Finaliza comunicação I2C
}

// Rotina que apresenta as informações de data e hora do RTC no display
void ShowRTCInfo(void)
{
	// Apresenta data e hora no display
	ControlLCDi2c(0x80);
	WriteLCDi2c((HOURS>>4)+0x30);
	WriteLCDi2c((HOURS & 0x0F)+0x30);
	WriteLCDi2c(':');
	WriteLCDi2c((MINUTES>>4)+0x30);
	WriteLCDi2c((MINUTES & 0x0F)+0x30);
	WriteLCDi2c(':');
	WriteLCDi2c((SECONDS>>4)+0x30);
	WriteLCDi2c((SECONDS & 0x0F)+0x30);
	ControlLCDi2c(0xC0);
	WriteLCDi2c((DAY>>4)+0x30);
	WriteLCDi2c((DAY & 0x0F)+0x30);
	WriteLCDi2c('/');
	WriteLCDi2c((MONTH>>4)+0x30);
	WriteLCDi2c((MONTH & 0x0F)+0x30);
	WriteLCDi2c('/');
	WriteLCDi2c('2');
	WriteLCDi2c('0');
	WriteLCDi2c((YEAR>>4)+0x30);
	WriteLCDi2c((YEAR & 0x0F)+0x30);
}
