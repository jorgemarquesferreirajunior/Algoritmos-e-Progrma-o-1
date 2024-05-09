//---------------------------------------------------------Includes---------------------------------------------------------//
#include<p18F4550.h>
#include "lcd.h"

//----------------------------------------------------------pragma----------------------------------------------------------//
#pragma config FOSC		= HS
#pragma config WDT 		= OFF
#pragma config MCLRE	= OFF
#pragma config LVP = OFF

//--------------------------------------------------Mapeamento-de-Hardware--------------------------------------------------//
#define LED_BTN_LEFT 	PORTBbits.RB0 
#define LED_BTN_UP		PORTBbits.RB1 
#define LED_BTN_RIGHT 	PORTBbits.RB2 
#define LED_BTN_DOWN 	PORTBbits.RB3 
#define LED_BTN_ENTER 	PORTBbits.RB4
//--------------------------------------------------------Diretivas--------------------------------------------------------//
#define QTD_BTNS 		5
#define VARIACAO		5

//--------------------------------------------------------Variaveis--------------------------------------------------------//
unsigned short VAN0;
unsigned char estado_anterior_btn[QTD_BTNS]	= {0};
unsigned char flag_btn[QTD_BTNS]			= {0};
unsigned short faixas[QTD_BTNS] 			= {767, 682, 512, 731, 614};// enter = 767, left= 682, up = 512, right = 731, down = 614
enum {enter=0, left, up, right, down};
unsigned char cursor_pos_x = 0, cursor_pos_y = 0, cursor_visivel = 1, indice = 0; 

//**********************************************************Testes**********************************************************//
unsigned short variavel_teste = 0;

//--------------------------------------------------------Prototipos--------------------------------------------------------//

void maskInit(void);
void paginaHome(void);
void paginaConfiguracoes(void);
void paginaInfo(void);
void paginaMe(void);

void bateriaLow();
void cat1();
void cat2();
void loadCaracteres(void);

void atualizaIndice(void);
void menuSelect(void);
void TelaInicializacao(void);

signed short analogRead(char CANAL);
void readBtns(void);

unsigned char lenShort(unsigned short numero);
void convertShortToChar(unsigned short num, char *str) ;

void delay_ms (unsigned int tempo);

//=====================================================Funcao-Principal=====================================================//
void main()
{
	PORTA = 0x00; LATA = 0x00; TRISA = 0x01; 
	PORTB = 0x00; LATB = 0x00; TRISB = 0x00; 
	PORTD = 0x00; LATD = 0x00; TRISD = 0x00; 
	PORTE = 0x00; LATE = 0x00; TRISE = 0x00;
	
	ADCON2 = 0x81;
	ADCON1 = 0x0E;
	ADCON0 = 0x01;
	CMCON = 0x07;
	
	T0CON = 0x83;
	INTCONbits.TMR0IF = 0;
	TMR0H = 0xC2;
	TMR0L = 0xF7;
		
	Inicializa_LCD_8b_20X4();
	maskInit();
	
	while(1)
	{
		VAN0 = analogRead(0);
		readBtns();
		TelaInicializacao();
		delay_ms(30);
		
	}
}

//----------------------------------------------------------Telas----------------------------------------------------------//
void maskInit(void)
{
	cmdLCD(_LCD_LIMPA);
	setCursorLCD(0,0);
	printStringLCD("  HOME   CONFIG      ");
	setCursorLCD(1,0);
	printStringLCD("  INFO   ABOUT-ME     ");
}

// SUB-ROTINA TELA paginaHome
void paginaHome(void)
{
	printStringLCD( "    CAT-BOX    ");
	setCursorLCD(1, 0);
	printStringLCD("    00:00   dia");
	setCursorLCD(0, 0);
	while(1);
}

// SUB-ROTINA TELA paginaConfiguracoes
void paginaConfiguracoes(void)
{
	printStringLCD(" Motores");
	setCursorLCD(1, 0);
	printStringLCD(" Sensores");
	setCursorLCD(0, 0);
	while(1);
}

// SUB-ROTINA TELA paginaInfo
void paginaInfo(void)
{
	printStringLCD("CAT-BOX V.: 1.0");
	setCursorLCD(0, 0);
	while(1);
}

// SUB-ROTINA TELA paginaMe
void paginaMe(void)
{
	printStringLCD("Developed by:");
	setCursorLCD(1, 0);
	printStringLCD("Jorge M. F. J.");
	setCursorLCD(0, 0);
	while(1);
}

//---------------------------------------------------Caracteres-Especiais---------------------------------------------------//
// SUB-ROTINA PARA CRIACAO DE CARACTERE ESPECIAL NO DISPLAY	
void bateriaLow()
{
	cmdLCD(_LCD_CMD);
	printCharLCD(0b00000100);
	printCharLCD(0b00011011);
	printCharLCD(0b00010001);
	printCharLCD(0b00010001);
	printCharLCD(0b00010001);
	printCharLCD(0b00010001);
	printCharLCD(0b00011111);
	printCharLCD(0b00011111);
}

// SUB-ROTINA PARA CRIACAO DE CARACTERE ESPECIAL NO DISPLAY	
void cat1()
{
	cmdLCD(_LCD_CMD);
	printCharLCD(0b00000100);
	printCharLCD(0b00001110);
	printCharLCD(0b00000000);
	printCharLCD(0b00000000);
	printCharLCD(0b00000001);
	printCharLCD(0b00010011);
	printCharLCD(0b00011110);
	printCharLCD(0b00000000);
}

// SUB-ROTINA PARA CRIACAO DE CARACTERE ESPECIAL NO DISPLAY	
void cat2()
{
	cmdLCD(_LCD_CMD);
	printCharLCD(0b00000100);
	printCharLCD(0b00001110);
	printCharLCD(0b00000000);
	printCharLCD(0b00000000);
	printCharLCD(0b00010000);
	printCharLCD(0b00011001);
	printCharLCD(0b00001111);
	printCharLCD(0b00000000);
}

// SUB-ROTINA P/ SALVAR CARACTERES ESPECIAIS NA MEMORIA DO DISPLAY
void loadCaracteres(void)
{
	cat1();
	cat2();
	bateriaLow();
}

//------------------------------------------------------Controle-Telas------------------------------------------------------//
// SUB-ROTINA P/ ATUALIZAR O INDICE DO DISPLAY
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

// SUB-ROTINA PARA SELECAO DO MENU DE VISUALIZACAO
void menuSelect(void)
{
	if(flag_btn[enter])
	{
		flag_btn[enter] = 0;
		LED_BTN_ENTER = !LED_BTN_ENTER;	
		cmdLCD(_LCD_LIMPA);
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

// SUB-ROTINA PARA NAVEGACAO NA TELA DE INICIALIZACAO
void TelaInicializacao(void)
{	
	if(flag_btn[left])
	{
		flag_btn[left] = 0;
		LED_BTN_LEFT = !LED_BTN_LEFT;
		if(cursor_pos_x > 0)
		{
			setCursorLCD(cursor_pos_y, cursor_pos_x);
			printCharLCD('  ');
			cursor_pos_x -= 8;
		}				
	}
	if(flag_btn[up])
	{
		flag_btn[up] = 0;
		LED_BTN_UP = !LED_BTN_UP;
		if(cursor_pos_y > 0)
		{
			setCursorLCD(cursor_pos_y, cursor_pos_x);
			printCharLCD('  ');
			cursor_pos_y --;
		}				
	}
	if(flag_btn[right])
	{
		flag_btn[right] = 0;
		LED_BTN_RIGHT = !LED_BTN_RIGHT;
		if(cursor_pos_x < 8)
		{
			setCursorLCD(cursor_pos_y, cursor_pos_x);
			printCharLCD('  ');
			cursor_pos_x += 8;
		}			
	}
	if(flag_btn[down])
	{
		flag_btn[down] = 0;
		LED_BTN_DOWN = !LED_BTN_DOWN;
		if(cursor_pos_y < 1)
		{
			setCursorLCD(cursor_pos_y, cursor_pos_x);
			printCharLCD('  ');
			cursor_pos_y ++;
		}			
	}
	
	setCursorLCD(cursor_pos_y, cursor_pos_x);
	
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
		printCharLCD('>');
	}else
	{
		printCharLCD('  ');
	}
	
	atualizaIndice();
	menuSelect();
	
}

//------------------------------------------------Controle-Botoes-Analogicos------------------------------------------------//
// SUB-ROTINA PARA LEITURA DE UMA PORTA ANALOGICA DO PIC
signed short analogRead(char CANAL)
{
	ADCON0bits.CHS = CANAL;		// Seleciona canal A/D
	Delay100TCYx(1);				// Aguarda tempo para troca de canal antes de iniciar conversão
	ADCON0bits.GO_DONE = 1;    	// Inicia a conversão
	while(ADCON0bits.GO_DONE);  // Aguarda término da conversão
	
	return ADRES;
}

// SUB-ROTINA PARA MONITORAMENTO DOS BOTOES ANALOGICOS
void readBtns(void)
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

//---------------------------------------------------Manipulacao-de-Dados---------------------------------------------------//
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

//--------------------------------------------------Funcao-Auxiliar-Delay--------------------------------------------------//
void delay_ms (unsigned int tempo)
{
	while(tempo > 0){
		Delay100TCYx(10);
		tempo--;
	}
}
