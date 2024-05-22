#include "lcd_i2c.h"

unsigned char boas_vindas = 1;

// Prototipos
void maskInit(void);
void maskMonitoramento(void);
void maskMotores(void);
void maskPurificador(void);
void maskRelogio(void);
void maskData(void);
void bateriaLow();
void cat1();
void cat2();
void loadCaracteres(void);
void cabecalhoPaginaConfiguracoes(void);


void cabecalhoPaginaConfiguracoes(void)
{
	setCursorLCD_i2c(0,0);printStringLCD_i2c("  SPRAY PUIFICADOR  ");
	setCursorLCD_i2c(1,0);printStringLCD_i2c("  VELOCIDADE MOTORES");
	setCursorLCD_i2c(2,0);printStringLCD_i2c("  HORA DO RELOGIO   ");
	setCursorLCD_i2c(3,0);printStringLCD_i2c("  DATA              ");
}
//Funcoes
void maskInit(void)
{	
	if (boas_vindas >= 1)
	{
		cmdLCD_i2c(_LCD_LIMPA);
		setCursorLCD_i2c(0, 0);printStringLCD_i2c("-------CAT-BOX------");
		setCursorLCD_i2c(1, 0);printStringLCD_i2c(" BEM VINDO USUARIO  ");
		setCursorLCD_i2c(2, 0);printStringLCD_i2c("   PARABENS PELA    ");
		setCursorLCD_i2c(3, 0);printStringLCD_i2c(" ESCOLHA - BE HAPPY ");
		while(boas_vindas != 0);
	}
	cmdLCD_i2c(_LCD_LIMPA);
	setCursorLCD_i2c(0, 0);printStringLCD_i2c("  HOME              ");
	setCursorLCD_i2c(1, 0);printStringLCD_i2c("  CONFIGURACOES     ");
	setCursorLCD_i2c(2, 0);printStringLCD_i2c("  MONITORAMENTO     ");
	setCursorLCD_i2c(3, 0);printStringLCD_i2c("  SOBRE             ");
}

void maskMonitoramento(void)
{
	cmdLCD_i2c(_LCD_LIMPA);
	setCursorLCD_i2c(0, 0);printStringLCD_i2c("MOTOR TAMBOR        ");
	setCursorLCD_i2c(1, 0);printStringLCD_i2c("MOTOR COMPORTA      ");
	setCursorLCD_i2c(2, 0);printStringLCD_i2c("SPRAYS              ");
}

void maskPurificador(void)
{
	cmdLCD_i2c(_LCD_LIMPA);
	setCursorLCD_i2c(0, 0);printStringLCD_i2c("  Capacidade:       ");
	setCursorLCD_i2c(1, 0);printStringLCD_i2c("  Utilizado:        ");
	setCursorLCD_i2c(2, 0);printStringLCD_i2c("  CONFIRMA   CANCELA");
	
}

void maskMotores(void)
{
	cmdLCD_i2c(_LCD_LIMPA);
	setCursorLCD_i2c(0, 0);printStringLCD_i2c("  VEL MOTOR TAMB:00%");
	setCursorLCD_i2c(1, 0);printStringLCD_i2c("  VEL MOTOR COMP:00%");
	setCursorLCD_i2c(2, 0);printStringLCD_i2c("  CONFIRMA   CANCELA");
}

void maskRelogio(void)
{
	cmdLCD_i2c(_LCD_LIMPA);
	setCursorLCD_i2c(0, 0);printStringLCD_i2c("  HORA....:         ");
	setCursorLCD_i2c(1, 0);printStringLCD_i2c("  MINUTO..:         ");
	setCursorLCD_i2c(2, 0);printStringLCD_i2c("  SEGUNDO.:         ");
	setCursorLCD_i2c(3, 0);printStringLCD_i2c("  CONFIRMA   CANCELA");
}

void maskData(void)
{
	cmdLCD_i2c(_LCD_LIMPA);
	setCursorLCD_i2c(0, 0);printStringLCD_i2c("DE 0[DOM] A 6[SAB]  ");
	setCursorLCD_i2c(1, 0);printStringLCD_i2c("  NOVA DATA:        ");
	setCursorLCD_i2c(2, 0);printStringLCD_i2c("  CONFIRMA   CANCELA");
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
