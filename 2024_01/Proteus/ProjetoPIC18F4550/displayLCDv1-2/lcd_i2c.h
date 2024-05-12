#ifndef LCD_I2C_H
#define LCD_I2C_H

#include <i2c.h>
#define PCF8574W  					0x4E  // Endereço expansor PCF8574 e o operação de escrita
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
//void printStringLCD_i2c(unsigned char LINE, rom unsigned char *STR);
void printStringLCD_i2c(rom unsigned char *STR);
void setCursorLCD_i2c(unsigned char linha, unsigned char coluna);

// Rotina que envia uma instrução de inicialização ou configuração para o LCD
void cmdLCD_i2c(unsigned char CMD)
{
  unsigned char LCD;

  IdleI2C(); StartI2C();        	// Inicia comunicação I2C
  IdleI2C(); WriteI2C(PCF8574W); 	// Define dispositivo e operação de escrita
  LCD = 0xF0 & CMD;             	// Separa parte alta da instrução
  LCD = (LCD | _LCD_CURSOR_OFF);    // Ativa backlight (P3=1), modo instrução (RS=0) e habilita o display (E=1)
  IdleI2C(); WriteI2C(LCD);     	// Envia instrução
  Delay10TCYx(1);               	// Aguarda 10us
  LCD = (LCD & 0xF8);           	// Desabilita o display (E=0)
  IdleI2C(); WriteI2C(LCD);     	// Envia instrução
  LCD = (CMD<<4) & 0xF0;        	// Separa parte baixa da instrução
  LCD = (LCD | _LCD_CURSOR_OFF);    // Ativa backlight (P3=1), modo instrução (RS=0) e habilita o display (E=1)
  IdleI2C(); WriteI2C(LCD);     	// Escreve instrução
  Delay10TCYx(1);               	// Aguarda 10us
  LCD = (LCD & 0xF8);           	// Desabilita o display (E=0)
  IdleI2C(); WriteI2C(LCD);     	// Envia instrução
  IdleI2C(); StopI2C();         	// Finaliza comunicação I2C
  Delay1KTCYx(5);  	            	// Aguarda 5ms
}

// Rotina que realiza a inicialização do LCD
void StartLCDi2c(void)
{
  Delay1KTCYx(20);     // Aguarda pelo menos 15ms
  cmdLCD_i2c(_LCD_INTERFACE_8bL1_5X7); // Instrução de inicialização
  Delay1KTCYx(5);      // Aguarda pelo menos 4.1ms
  cmdLCD_i2c(_LCD_INTERFACE_8bL1_5X7); // Instrução de inicialização
  Delay100TCYx(2);     // Aguarda pelo menos 100us
  cmdLCD_i2c(_LCD_INTERFACE_8bL1_5X7); // Instrução de inicialização
  cmdLCD_i2c(_LCD_HOME); // Define interface de 4 bits
  cmdLCD_i2c(_LCD_INTERFACE_4bL2_5X7); // Define interface de 4 bits e display de 2 linhas
  cmdLCD_i2c(_LCD_DESLOC_DIR); // Modo de entrada: desloca cursor para direita sem deslocar a mensagem
  cmdLCD_i2c(_LCD_CURSOR_OFF); // Desliga cursor
  cmdLCD_i2c(_LCD_LIMPA); // Limpa display
}

// Rotina que envia um caractere a ser escrito no LCD
void printCharLCD_i2c(unsigned char DATA)
{
  unsigned char LCD;

	IdleI2C(); StartI2C();        	// Inicia comunicação I2C
	IdleI2C(); WriteI2C(PCF8574W); 	// Define dispositivo e operação de escrita
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
	IdleI2C(); StopI2C();         	// Para comunicação I2C
	Delay1KTCYx(5);  	            	// Aguarda 5ms
}

// Rotina que escreve uma linha completa no LCD
/*

void printStringLCD_i2c(unsigned char LINE, rom unsigned char *STR)
{
  if(LINE == 1) ControlLCDi2c(0x80);
  if(LINE == 2) ControlLCDi2c(0xC0);

  // Escreve todos os caracteres até encontrar o final do ponteiro
  while(*STR != '\0')
  {
    printCharLCD_i2c(*STR);
    ++STR;
  }
}

*/

void printStringLCD_i2c(rom unsigned char *STR)
{

  // Escreve todos os caracteres até encontrar o final do ponteiro
  while(*STR != '\0')
  {
    printCharLCD_i2c(*STR);
    ++STR;
  }
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