#ifndef LCD_H_
#define LCD_H_

// ================================================================= //
// BIBLIOTECA PARA CONTROLE DE DISPLAY LCD 2x16 e 4x16               //
// ================================================================= //
#include <delays.h>

// ================================================================= //
// DEFINI합ES DE HARDWARE                                            //
// ================================================================= //
#define DATA_LCD 	PORTD
#define ENABLE_LCD	PORTEbits.RE1
#define RS_LCD	    PORTEbits.RE2

// ================================================================= //
// DEFINI합ES DE SOFTWARE		                                     //
// ================================================================= //
#define _LCD_INTERFACE_8bL2_5X7		0x38	// (8-bit interface, 2 lines, 5*7 Pixels)
#define _LCD_INTERFACE_8bL1_5X7		0x30	// (8-bit interface, 1 line, 5*7 Pixels)
#define _LCD_INTERFACE_4bL2_5X7		0x28	// (4-bit interface, 2 lines, 5*7 Pixels)
#define _LCD_INTERFACE_4bL1_5X7		0x20	// (4-bit interface, 1 line, 5*7 Pixels)
#define _LCD_LINHA_1						0x80
#define _LCD_LINHA_2						0xC0
#define _LCD_LINHA_3						0x94
#define _LCD_LINHA_4						0xD4
#define _LCD_LIMPA							0x01
#define _LCD_HOME						0x02
#define _LCD_CURSOR_OFF				0x0C
#define _LCD_UNDERLINE_ON				0x0E
#define _LCD_DESLOC_DIR					0x06	// sentido de escrita para a direita -->>
#define _LCD_DESLOC_ESQ				0x04	// sentido de escrita para a esquerda <<--
#define _LCD_BLINK_CURSOR_ON			0x0F
#define _LCD_MOVE_CURSOR_ESQ		0x10
#define _LCD_MOVE_CURSOR_DIR			0x14
#define _LCD_DESLIGADO					0x08
#define _LCD_LIGADO						0x0C
#define _LCD_DESLOCA_ESQ				0x18
#define _LCD_DESLOCA_DIR				0x1E
#define _LCD_CMD							0x40    
// ================================================================= //
// SUB-ROTINA PULSO PINO ENABLE_LCD                                  //
// ================================================================= //
void pulsoE(void)
{
   ENABLE_LCD 	= 1;
   Delay100TCYx(2);
   ENABLE_LCD 	= 0;
   Delay1KTCYx(10);
}
// ================================================================= //
// SUB-ROTINA DE CONTROLE DE LCD                                     //
// ================================================================= //
void cmdLCD (unsigned char comando){
   RS_LCD 		= 0;
   DATA_LCD 	= comando;
   pulsoE();
}
// ================================================================ //
// SUB-ROTINA DE POSICIONAMENTO DE ESCRITA DE LCD                   //
// ================================================================ //
void setCursorLCD (unsigned char linha, unsigned char coluna){
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

   if (x != 0x00) cmdLCD(x); 
} 
// ================================================================ //
// SUB-ROTINA DE ESCRITA DE 1 CARACTER NO LCD                       //
// ================================================================ //
void printCharLCD (unsigned char caracter){  
    RS_LCD = 1;
    DATA_LCD = caracter;
    pulsoE();
}

// ================================================================ //
// SUB-ROTINA DE ESCRITA DE 1 FRASE NO LCD                          //
// ================================================================ //
void printStringLCD (rom unsigned char *caracter){
   while (*caracter != '\0'){
      printCharLCD(*caracter);
      ++caracter;
   } 
}

// ================================================================ //
// SUB-ROTINA DE INICIALIZA플O DO LCD 8 bits tela16X2               //
// ================================================================ //
void Inicializa_LCD_8b_16X2 (void){
   unsigned char x = 0;
   static rom unsigned char ini [] = {
   _LCD_INTERFACE_8bL2_5X7,_LCD_INTERFACE_8bL2_5X7, _LCD_INTERFACE_8bL2_5X7,
   _LCD_CURSOR_OFF, _LCD_DESLOC_DIR, _LCD_LIGADO, _LCD_LIMPA, 0x00};
   
   ADCON1 = 0x0F;
   LATD = 0x00;
   LATE = LATE & 0xF8;
   TRISD = 0x00;
   TRISE = TRISE & 0xF8;
 
   while (ini [x] != 0x00){
	  Delay1KTCYx(30);
      cmdLCD (ini[x]);
      Delay1KTCYx(30);
      ++ x;
   } 
}


// ================================================================ //
// SUB-ROTINA DE INICIALIZA플O DO LCD 8 bits tela20X4               //
// ================================================================ //
void Inicializa_LCD_8b_20X4 (void){
   Inicializa_LCD_8b_16X2();
}

// ================================================================ //
// SUB-ROTINA DE TESTE DO LCD 8 bits tela20X4               //
// ================================================================ //
void testeLCD(unsigned char linhas)
{
	short i = 0;
	unsigned short tempo;
	
	for(i = 0; i < linhas; i++)
	{
		cmdLCD(_LCD_LIMPA);
		setCursorLCD(i,0);
		printStringLCD("JORGE M. F. J.");
		
		tempo = 1000;
		 while(tempo > 0)
		{
       	 	Delay100TCYx(10);
       		 tempo--;
    		}
	}
}

// ================================================================ //
#endif