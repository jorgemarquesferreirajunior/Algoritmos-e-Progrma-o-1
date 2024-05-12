//***************************************Includes***************************************//
#include <p18F4550.h>
#include <delays.h>
#include "lcd_i2c.h"
#include "rtc.h"

//****************************************pragma****************************************//
#pragma config FOSC		= HS
#pragma config PWRT 	= ON
#pragma config WDT 		= OFF
#pragma config MCLRE	= OFF
#pragma config LVP 		= OFF
//--------------------------------mapeamento-de-hardware--------------------------------//
#define LED_BTN_LEFT 	PORTBbits.RB2 
#define LED_BTN_UP		PORTBbits.RB3 
#define LED_BTN_RIGHT 	PORTBbits.RB4 
#define LED_BTN_DOWN 	PORTBbits.RB5 
#define LED_BTN_ENTER 	PORTBbits.RB6

#define FIM_CURSO_TB_SUPERIOR	PORTDbits.RD0
#define FIM_CURSO_TB_INFERIOR	PORTDbits.RD1
#define FIM_CURSO_GV_ABERTO		PORTDbits.RD2
#define FIM_CURSO_GV_FECHADO	PORTDbits.RD3

//--------------------------------------diretivas--------------------------------------//
#define QTD_BTNS 		5
#define VARIACAO		5
//--------------------------------------variaveis--------------------------------------//
unsigned short VAN0;
unsigned char estado_anterior_btn[QTD_BTNS]	= {0};
unsigned char flag_btn[QTD_BTNS] = {0};
unsigned short faixas[QTD_BTNS] = {767, 682, 512, 731, 614};// enter,left,up,right,down
enum {enter=0, left, up, right, down};
unsigned char cursor_pos_x = 0, cursor_pos_y = 0, cursor_visivel = 1, indice = 0; 
unsigned char status[2] = {"ON", "OFF"};
unsigned char sprays = 0;
//****************************************testes****************************************//
unsigned short variavel_teste = 0;
//--------------------------------------prototipos--------------------------------------//

void maskInit(void);
void maskSensores(void);
void maskMotores(void);
void maskPurificador(void);
void paginaHome(void);
void paginaConfiguracoes(void);
void paginaInfo(void);
void paginaMe(void);

void bateriaLow();
void cat1();
void cat2();
void loadCaracteres(void);

void atualizaIndice(void);
void atualizaIndiceInfo(void);
void menuSelect(void);
void infoSelect(void);
void TelaInicializacao(void);
void atualizaSensores(void);
void atualizaMotores(void);
void atualizaMotores(void);
void atualizaPosicaoCursor(void);

signed short lerAnalogico(char CANAL);
void lerBotoes(void);
void atualizaBotoes(void);

unsigned char lenShort(unsigned short numero);
void convertShortToChar(unsigned short num, char *str) ;

void delay_ms (unsigned int tempo);


//===================================Funcao-Principal===================================//
void main()
{
	PORTA = 0x00; LATA = 0x00; TRISA = 0x01; 
	PORTB = 0x00; LATB = 0x00; TRISB = 0x03; 
	PORTD = 0x00; LATD = 0x00; TRISD = 0x0F; 
	PORTE = 0x00; LATE = 0x00; TRISE = 0x00;
	
	ADCON2 = 0x81;
	ADCON1 = 0x0E;
	ADCON0 = 0x01;
	CMCON = 0x07;
	
	T0CON = 0x83;
	INTCONbits.TMR0IF = 0;
	TMR0H = 0xC2;
	TMR0L = 0xF7;
		
	
	
	OpenI2C(MASTER, SLEW_OFF); 	// Inicializa I2C: Mestre com velocidade de 100Khz.
	SSPADD = 9;                	// Taxa de comunicação I2C de 100khz
	
	StartLCDi2c();
	StartRTC();
	
	maskInit();
	
	while(1)
	{
		ReadRTC();
    	TelaInicializacao();
		delay_ms(30);
		
	}
}
//----------------------------------------telas----------------------------------------//


void maskInit(void)
{
	cmdLCD_i2c(_LCD_LIMPA);
	setCursorLCD_i2c(0,0);
	printStringLCD_i2c("  HOME   CONFIG      ");
	setCursorLCD_i2c(1,0);
	printStringLCD_i2c("  INFO   ABOUT-ME     ");
}

void maskSensores(void)
{
	cmdLCD_i2c(_LCD_LIMPA);
	setCursorLCD_i2c(0,0);
	printStringLCD_i2c("TAMBOR RECUADO ");
	setCursorLCD_i2c(1,0);
	printStringLCD_i2c("TAMBOR AVANCADO");
	setCursorLCD_i2c(2,0);
	printStringLCD_i2c("GAVETA ABERTO  ");
	setCursorLCD_i2c(3,0);
	printStringLCD_i2c("GAVETA FECHADO ");
}

void maskPurificador(void)
{
	cmdLCD_i2c(_LCD_LIMPA);
	setCursorLCD_i2c(0,0);
	printStringLCD_i2c("----PURIFICADOR---- ");
	setCursorLCD_i2c(1,0);
	printStringLCD_i2c("SPRAYS 000/000      ");
}

void maskMotores(void)
{
	cmdLCD_i2c(_LCD_LIMPA);
	setCursorLCD_i2c(0,0);
	printStringLCD_i2c("MOTOR TAMBOR ");
	setCursorLCD_i2c(1,0);
	printStringLCD_i2c("MOTOR GAVETA ");
}

// SUB-ROTINA TELA paginaHome
void paginaHome(void)
{
	printStringLCD_i2c( "------CAT-BOX------");
	setCursorLCD_i2c(1,6);
	printCharLCD_i2c((HOURS>>4)+0x30);
	printCharLCD_i2c((HOURS & 0x0F)+0x30);
	printCharLCD_i2c(':');
	printCharLCD_i2c((MINUTES>>4)+0x30);
	printCharLCD_i2c((MINUTES & 0x0F)+0x30);
	printCharLCD_i2c(':');
	printCharLCD_i2c((SECONDS>>4)+0x30);
	printCharLCD_i2c((SECONDS & 0x0F)+0x30);
	setCursorLCD_i2c(2,5);
	printCharLCD_i2c((DAY>>4)+0x30);
	printCharLCD_i2c((DAY & 0x0F)+0x30);
	printCharLCD_i2c('/');
	printCharLCD_i2c((MONTH>>4)+0x30);
	printCharLCD_i2c((MONTH & 0x0F)+0x30);
	printCharLCD_i2c('/');
	printCharLCD_i2c('2');
	printCharLCD_i2c('0');
	printCharLCD_i2c((YEAR>>4)+0x30);
	printCharLCD_i2c((YEAR & 0x0F)+0x30);
	setCursorLCD_i2c(0, 0);
	
	while(!flag_btn[left])
	{
		atualizaBotoes();
	}
	maskInit();
	TelaInicializacao();
	flag_btn[left] = 0;
}

// SUB-ROTINA TELA paginaConfiguracoes
void paginaConfiguracoes(void)
{
	printStringLCD_i2c(" Motores");
	setCursorLCD_i2c(1, 0);
	printStringLCD_i2c(" Sensores");
	setCursorLCD_i2c(0, 0);
	
	while(!flag_btn[left])
	{
		atualizaBotoes();
	}
	maskInit();
	TelaInicializacao();
	flag_btn[left] = 0;
}

// SUB-ROTINA TELA paginaInfo
void paginaInfo(void)
{
	cmdLCD_i2c(_LCD_LIMPA);
	printStringLCD_i2c("---CAT-BOX V: 1.0---");
	setCursorLCD_i2c(1, 0);
	printStringLCD_i2c("  Motores           ");
	setCursorLCD_i2c(2, 0);
	printStringLCD_i2c("  Sensores          ");
	setCursorLCD_i2c(3, 0);
	printStringLCD_i2c("  Purificador       ");
	setCursorLCD_i2c(0, 0);
	cursor_pos_y = 1;
	cursor_pos_x = 0;
	
	while(!flag_btn[left])
	{
		atualizaBotoes();
		
		if(flag_btn[up])
		{
			flag_btn[up] = 0;
			LED_BTN_UP = !LED_BTN_UP;
			setCursorLCD_i2c(cursor_pos_y, cursor_pos_x);
			printCharLCD_i2c('  ');
			if(cursor_pos_y == 1)
			{
				cursor_pos_y = 3;
			}else
			{
				cursor_pos_y --;
			}	
		}
		if(flag_btn[down])
		{
			flag_btn[down] = 0;
			LED_BTN_DOWN = !LED_BTN_DOWN;
			setCursorLCD_i2c(cursor_pos_y, cursor_pos_x);
			printCharLCD_i2c('  ');
			if(cursor_pos_y == 3)
			{
				cursor_pos_y = 1;
			}else
			{
				cursor_pos_y ++;
			}		
		}
		
		setCursorLCD_i2c(cursor_pos_y, cursor_pos_x);
		
		atualizaPosicaoCursor();
		atualizaIndiceInfo();
		infoSelect();
	}
	maskInit();
	TelaInicializacao();
	flag_btn[left] = 0;
}

// SUB-ROTINA TELA paginaMe
void paginaMe(void)
{
	printStringLCD_i2c("Developed by:");
	setCursorLCD_i2c(1, 0);
	printStringLCD_i2c("Jorge M. F. J.");
	setCursorLCD_i2c(0, 0);
	
	while(!flag_btn[left])
	{
		atualizaBotoes();
	}
	maskInit();
	TelaInicializacao();
	flag_btn[left] = 0;
}


//---------------------------------caracteres-especiais---------------------------------//
// SUB-ROTINA PARA CRIACAO DE CARACTERE ESPECIAL NO DISPLAY	
void bateriaLow()
{
	cmdLCD_i2c(_LCD_CMD);
	printCharLCD_i2c(0b00000100);
	printCharLCD_i2c(0b00011011);
	printCharLCD_i2c(0b00010001);
	printCharLCD_i2c(0b00010001);
	printCharLCD_i2c(0b00010001);
	printCharLCD_i2c(0b00010001);
	printCharLCD_i2c(0b00011111);
	printCharLCD_i2c(0b00011111);
}

// SUB-ROTINA PARA CRIACAO DE CARACTERE ESPECIAL NO DISPLAY	
void cat1()
{
	cmdLCD_i2c(_LCD_CMD);
	printCharLCD_i2c(0b00000100);
	printCharLCD_i2c(0b00001110);
	printCharLCD_i2c(0b00000000);
	printCharLCD_i2c(0b00000000);
	printCharLCD_i2c(0b00000001);
	printCharLCD_i2c(0b00010011);
	printCharLCD_i2c(0b00011110);
	printCharLCD_i2c(0b00000000);
}

// SUB-ROTINA PARA CRIACAO DE CARACTERE ESPECIAL NO DISPLAY	
void cat2()
{
	cmdLCD_i2c(_LCD_CMD);
	printCharLCD_i2c(0b00000100);
	printCharLCD_i2c(0b00001110);
	printCharLCD_i2c(0b00000000);
	printCharLCD_i2c(0b00000000);
	printCharLCD_i2c(0b00010000);
	printCharLCD_i2c(0b00011001);
	printCharLCD_i2c(0b00001111);
	printCharLCD_i2c(0b00000000);
}

// SUB-ROTINA P/ SALVAR CARACTERES ESPECIAIS NA MEMORIA DO DISPLAY
void loadCaracteres(void)
{
	cat1();
	cat2();
	bateriaLow();
}

//------------------------------------controle-telas------------------------------------//
// SUB-ROTINA P/ ATUALIZAR O INDICE DO DISPLAY
void atualizaPosicaoCursor(void)
{
	if(INTCONbits.TMR0IF)
	{
		PORTAbits.RA1 = !PORTAbits.RA1;
		INTCONbits.TMR0IF = 0;
		TMR0H = 0xC2;
		TMR0L = 0xF7;
		cursor_visivel = !cursor_visivel;
	}
	
	if(cursor_visivel)
	{
		printCharLCD_i2c('>');
	}else
	{
		printCharLCD_i2c('  ');
	}
}

void atualizaIndice(void)
{
	if(cursor_pos_y == 0 && cursor_pos_x == 0)
	{
		indice = 0;
	}
	else if(cursor_pos_y == 0 && cursor_pos_x == 8)
	{
		indice = 1;
	}
	else if(cursor_pos_y == 1 && cursor_pos_x == 0)
	{
		indice = 2;
	}
	else if(cursor_pos_y == 1 && cursor_pos_x == 8)
	{
		indice = 3;
	}
}

void atualizaIndiceInfo(void)
{
	if(cursor_pos_y == 1)
	{
		indice = 0;
	}
	else if(cursor_pos_y == 2)
	{
		indice = 1;
	}
	else if(cursor_pos_y == 3)
	{
		indice = 2;
	}
}
void atualizaSensores(void)
{
	atualizaBotoes();
	
	while(!flag_btn[left])
	{
		flag_btn[left] = 0;
		setCursorLCD_i2c(0, 16);
		if(FIM_CURSO_TB_SUPERIOR)
		{
			printStringLCD_i2c("ON ");//ON
			
		}else
		{
			printStringLCD_i2c("OFF");//OFF
		}
		setCursorLCD_i2c(1, 16);
		if(FIM_CURSO_TB_INFERIOR)
		{
			printStringLCD_i2c("ON ");//ON
			
		}else
		{
			printStringLCD_i2c("OFF");//OFF
		}
		
		setCursorLCD_i2c(2, 16);
		if(FIM_CURSO_GV_ABERTO)
		{
			printStringLCD_i2c("ON ");//ON
			
		}else
		{
			printStringLCD_i2c("OFF");//OFF
		}
		
		setCursorLCD_i2c(3, 16);
		if(FIM_CURSO_GV_FECHADO)
		{
			printStringLCD_i2c("ON ");//ON
			
		}else
		{
			printStringLCD_i2c("OFF");//OFF
		}
		atualizaBotoes();
	}
	flag_btn[left] = 0;
	paginaInfo();
}

void atualizaMotores(void)
{
	atualizaBotoes();
	
	while(!flag_btn[left])
	{
		// implementar
		atualizaBotoes();
	}
	flag_btn[left] = 0;
	paginaInfo();
}

void atualizaPurificador(void)
{
	atualizaBotoes();
	
	while(!flag_btn[left])
	{
		// implementar
		atualizaBotoes();
	}
	flag_btn[left] = 0;
	paginaInfo();
}

// SUB-ROTINA PARA SELECAO DO MENU DE VISUALIZACAO
void menuSelect(void)
{
	if(flag_btn[enter])
	{
		flag_btn[enter] = 0;
		LED_BTN_ENTER = !LED_BTN_ENTER;	
		cmdLCD_i2c(_LCD_LIMPA);
		switch(indice)
		{
			case 0:
				paginaHome();
				break;
			case 1:
				paginaConfiguracoes();
				break;
			case 2:
				paginaInfo();
				break;
			case 3:
				paginaMe();
				break;
		}
	}
}

void infoSelect(void)
{
	if(flag_btn[enter])
	{
		flag_btn[enter] = 0;
		LED_BTN_ENTER = !LED_BTN_ENTER;	
		cmdLCD_i2c(_LCD_LIMPA);
		switch(indice)
		{
			case 0:
				maskMotores();
				atualizaMotores();
				break;
			case 1:
				maskSensores();
				atualizaSensores();
				break;
			case 2:
				maskPurificador();
				atualizaPurificador();
				break;
		}
	}
}
// SUB-ROTINA PARA NAVEGACAO NA TELA DE INICIALIZACAO
void TelaInicializacao(void)
{	
	atualizaBotoes();
	if(flag_btn[left])
	{
		flag_btn[left] = 0;
		LED_BTN_LEFT = !LED_BTN_LEFT;
		if(cursor_pos_x > 0)
		{
			setCursorLCD_i2c(cursor_pos_y, cursor_pos_x);
			printCharLCD_i2c('  ');
			cursor_pos_x -= 8;
		}				
	}
	if(flag_btn[up])
	{
		flag_btn[up] = 0;
		LED_BTN_UP = !LED_BTN_UP;
		if(cursor_pos_y > 0)
		{
			setCursorLCD_i2c(cursor_pos_y, cursor_pos_x);
			printCharLCD_i2c('  ');
			cursor_pos_y --;
		}				
	}
	if(flag_btn[right])
	{
		flag_btn[right] = 0;
		LED_BTN_RIGHT = !LED_BTN_RIGHT;
		if(cursor_pos_x < 8)
		{
			setCursorLCD_i2c(cursor_pos_y, cursor_pos_x);
			printCharLCD_i2c('  ');
			cursor_pos_x += 8;
		}			
	}
	if(flag_btn[down])
	{
		flag_btn[down] = 0;
		LED_BTN_DOWN = !LED_BTN_DOWN;
		if(cursor_pos_y < 1)
		{
			setCursorLCD_i2c(cursor_pos_y, cursor_pos_x);
			printCharLCD_i2c('  ');
			cursor_pos_y ++;
		}			
	}
	
	setCursorLCD_i2c(cursor_pos_y, cursor_pos_x);
	
	atualizaPosicaoCursor();
	atualizaIndice();
	menuSelect();
	
}

//------------------------------controle-botoes-analogicos------------------------------//
// SUB-ROTINA PARA LEITURA DE UMA PORTA ANALOGICA DO PIC
signed short lerAnalogico(char CANAL)
{
	ADCON0bits.CHS = CANAL;		// Seleciona canal A/D
	Delay100TCYx(1);				// Aguarda tempo para troca de canal antes de iniciar conversão
	ADCON0bits.GO_DONE = 1;    	// Inicia a conversão
	while(ADCON0bits.GO_DONE);  // Aguarda término da conversão
	
	return ADRES;
}

// SUB-ROTINA PARA MONITORAMENTO DOS BOTOES ANALOGICOS
void lerBotoes(void)
{
	unsigned char i;	
	for(i = 0; i < QTD_BTNS; i++)
	{
		unsigned char estado_atual = 0;
		
		if((faixas[i] - VARIACAO)<= VAN0 && (faixas[i] + VARIACAO)>= VAN0)
		{
			estado_atual = 1;
			
			if(estado_atual && !estado_anterior_btn[i])
			{
				flag_btn[i]= 1;
			}
		}
		estado_anterior_btn[i] = estado_atual;
	}
}

void atualizaBotoes(void)
{
	VAN0 = lerAnalogico(0);
	lerBotoes();
}
//---------------------------------manipulacao-de-dados---------------------------------//
// SUB-ROTINA PARA RETORNAR A QUANTIDADE DE DIGITOS DE UM NUMERO
unsigned char lenShort(unsigned short numero)
{
	int temp = numero;
	unsigned char qtd = 0;
	
	do
	{
		temp /= 10;
		qtd ++;
	}while(temp != 0);
	
	return qtd;
}

// SUB-ROTINA PARA CONVERSAO DE UM INT PARA CHAR
void convertShortToChar(unsigned short num, char *str) 
{
	
	int length = lenShort(num); // Começamos com um dígito para o caractere nulo
	int i = 0;
		
	// Converte o número em uma string de caracteres
	for (i = length - 1; i >= 0; i--)
	{
		str[i] = num % 10 + '0'; // Converte o dígito para seu caractere correspondente
		num /= 10;
	}
	str[length] = '\0'; // Adiciona o caractere nulo ao final da string
}
//--------------------------------funcao-auxiliar-delay--------------------------------//
void delay_ms (unsigned int tempo)
{
	while(tempo > 0){
		Delay100TCYx(10);
		tempo--;
	}
}

