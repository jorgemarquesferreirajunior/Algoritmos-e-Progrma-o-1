#ifndef LCD_I2C_H
#define LCD_I2C_H

#include <i2c.h>
#define PCF8574W  					0x3F  // Endereco expansor PCF8574 e o operacao de escrita
#define _LCD_INTERFACE_8bL2_5X7		0x38	// (8-bit interface, 2 lines, 5*7 Pixels)
#define _LCD_INTERFACE_8bL1_5X7		0x30	// (8-bit interface, 1 line, 5*7 Pixels)
#define _LCD_INTERFACE_4bL2_5X7		0x28	// (4-bit interface, 2 lines, 5*7 Pixels)
#define _LCD_INTERFACE_4bL1_5X7		0x20	// (4-bit interface, 1 line, 5*7 Pixels)
#define _LCD_LINHA_1				0x80
#define _LCD_LINHA_2				0xC0
#define _LCD_LINHA_3				0x94
#define _LCD_LINHA_4				0xD4
#define _LCD_LIMPA					0x01
#define _LCD_HOME					0x02
#define _LCD_CURSOR_OFF				0x0C
#define _LCD_UNDERLINE_ON			0x0E
#define _LCD_DESLOC_DIR				0x06	// sentido de escrita para a direita -->>
#define _LCD_DESLOC_ESQ				0x04	// sentido de escrita para a esquerda <<--
#define _LCD_BLINK_CURSOR_ON		0x0F
#define _LCD_MOVE_CURSOR_ESQ		0x10
#define _LCD_MOVE_CURSOR_DIR		0x14
#define _LCD_DESLIGADO				0x08
#define _LCD_LIGADO					0x0C
#define _LCD_DESLOCA_ESQ			0x18
#define _LCD_DESLOCA_DIR			0x1E
#define _LCD_CMD					0x40   

// ================================================================= //
// BIBLIOTECA PARA CONTROLE DE DISPLAY LCD VIA I2C		             //
// ================================================================= //
void cmdLCD_i2c(unsigned char CMD);
void StartLCDi2c(void);
void printCharLCD_i2c(unsigned char DATA);
void printStringLCD_i2c(rom unsigned char *STR);
unsigned char lenShort(unsigned short numero);
void printShortLCD_i2c(unsigned short num);
void setCursorLCD_i2c(unsigned char linha, unsigned char coluna);

// Rotina que envia uma instru��o de inicializa��o ou configura��o para o LCD
void cmdLCD_i2c(unsigned char CMD)
{
  unsigned char LCD;

  IdleI2C(); StartI2C();        	// Inicia comunica��o I2C
  IdleI2C(); WriteI2C(PCF8574W); 	// Define dispositivo e opera��o de escrita
  LCD = 0xF0 & CMD;             	// Separa parte alta da instru��o
  LCD = (LCD | 0x0C);    // Ativa backlight (P3=1), modo instru��o (RS=0) e habilita o display (E=1)
  IdleI2C(); WriteI2C(LCD);     	// Envia instru��o
  Delay10TCYx(1);               	// Aguarda 10us
  LCD = (LCD & 0xF8);           	// Desabilita o display (E=0)
  IdleI2C(); WriteI2C(LCD);     	// Envia instru��o
  LCD = (CMD<<4) & 0xF0;        	// Separa parte baixa da instru��o
  LCD = (LCD | 0X0C);    // Ativa backlight (P3=1), modo instru��o (RS=0) e habilita o display (E=1)
  IdleI2C(); WriteI2C(LCD);     	// Escreve instru��o
  Delay10TCYx(1);               	// Aguarda 10us
  LCD = (LCD & 0xF8);           	// Desabilita o display (E=0)
  IdleI2C(); WriteI2C(LCD);     	// Envia instru��o
  IdleI2C(); StopI2C();         	// Finaliza comunica��o I2C
  Delay1KTCYx(5);  	            	// Aguarda 5ms
}

// Rotina que realiza a inicializa��o do LCD
void StartLCDi2c(void)
{
  Delay1KTCYx(20);     // Aguarda pelo menos 15ms
  cmdLCD_i2c(0x30); // Instru��o de inicializa��o
  Delay1KTCYx(5);      // Aguarda pelo menos 5ms
  cmdLCD_i2c(0x30); // Instru��o de inicializa��o
  Delay100TCYx(2);     // Aguarda pelo menos 100us
  cmdLCD_i2c(0x30); // Instru��o de inicializa��o
  cmdLCD_i2c(0x02); // Define interface de 4 bits
  cmdLCD_i2c(0x28); // Define interface de 4 bits e display de 2 linhas
  cmdLCD_i2c(0x06); // Modo de entrada: desloca cursor para direita sem deslocar a mensagem
  cmdLCD_i2c(0x0C); // Desliga cursor
  cmdLCD_i2c(0x01); // Limpa display
}

// Rotina que envia um caractere a ser escrito no LCD
void printCharLCD_i2c(unsigned char DATA)
{
  unsigned char LCD;

	IdleI2C(); StartI2C();        	// Inicia comunica��o I2C
	IdleI2C(); WriteI2C(PCF8574W); 	// Define dispositivo e opera��o de escrita
	LCD = 0xF0 & DATA;            	// Separa parte alta do dado
	LCD = LCD | 0x0D;             	// Ativa backlight (P3=1), modo dados (RS=1) e habilita o display (E=1)
	IdleI2C(); WriteI2C(LCD);     	// Envia dado
	Delay10TCYx(10);              	// Aguarda 10us
	LCD = (LCD & 0xF9);           	// Desabilita o display (E=0)
	IdleI2C(); WriteI2C(LCD);     	// Envia dado
	LCD = (DATA<<4) & 0xF0;      		// Separa parte baixa do dado
	LCD = LCD | 0x0D;             	// Ativa backlight (P3=1), modo dados (RS=1) e habilita o display (E=1)
	IdleI2C(); WriteI2C(LCD);     	// Envia dado
	Delay10TCYx(10);              	// Aguarda 10us
	LCD = (LCD & 0xF9);           	// Desabilita o display (E=0)
	IdleI2C(); WriteI2C(LCD);     	// Envia dado
	IdleI2C(); StopI2C();         	// Para comunica��o I2C
	Delay1KTCYx(5);  	            	// Aguarda 5ms
}

// Rotina que escreve uma linha completa no LCD

void printStringLCD_i2c(rom unsigned char *STR)
{

  // Escreve todos os caracteres at� encontrar o final do ponteiro
  while(*STR != '\0')
  {
    printCharLCD_i2c(*STR);
    ++STR;
  }
}

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

void printShortLCD_i2c(unsigned short num)
{
	int i = 0;
	unsigned short temp = num;
	
	cmdLCD_i2c(_LCD_DESLOC_ESQ);
	for (i = lenShort(num); i > 0; i--)
	{
		printCharLCD_i2c(temp % 10 + '0');
		temp /= 10;
	}
	cmdLCD_i2c(_LCD_DESLOC_DIR);
}
// ================================================================ //
// SUB-ROTINA DE POSICIONAMENTO DE ESCRITA DE LCD                   //
// ================================================================ //
void setCursorLCD_i2c (unsigned char linha, unsigned char coluna){
   unsigned char x = 0x00;

   switch (linha){
      case 0:  x = _LCD_LINHA_1 + coluna;
               break;
 
      case 1:  x = _LCD_LINHA_2 + coluna;
               break;
 
      case 2:  x = _LCD_LINHA_3 + coluna;
               break;
 
      case 3:  x = _LCD_LINHA_4 + coluna;
               break;

      default: break;
   }

   if (x != 0x00) cmdLCD_i2c(x); 
} 

#endif //LCD_I2C_H
