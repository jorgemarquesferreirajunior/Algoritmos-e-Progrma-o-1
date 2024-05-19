void maskInit(void);
void maskSensores(void);
void maskMotores(void);
void maskPurificador(void);
void maskRelogio(void);
void bateriaLow();
void cat1();
void cat2();
void loadCaracteres(void);

void maskInit(void)
{
	cmdLCD_i2c(_LCD_LIMPA);
	setCursorLCD_i2c(0, 0);printStringLCD_i2c("  HOME   CONFIG     ");
	setCursorLCD_i2c(1, 0);printStringLCD_i2c("  INFO   ABOUT-ME   ");
}

void maskSensores(void)
{
	cmdLCD_i2c(_LCD_LIMPA);
	setCursorLCD_i2c(0, 0);printStringLCD_i2c("TAMBOR RECUADO ");
	setCursorLCD_i2c(1, 0);printStringLCD_i2c("TAMBOR AVANCADO");
	setCursorLCD_i2c(2, 0);printStringLCD_i2c("GAVETA ABERTO  ");
	setCursorLCD_i2c(3, 0);printStringLCD_i2c("GAVETA FECHADO ");
}

void maskPurificador(void)
{
	cmdLCD_i2c(_LCD_LIMPA);
	setCursorLCD_i2c(0, 0);printStringLCD_i2c("----PURIFICADOR---- ");
	setCursorLCD_i2c(1, 0);printStringLCD_i2c("SPRAYS 000/000      ");
}

void maskMotores(void)
{
	cmdLCD_i2c(_LCD_LIMPA);
	setCursorLCD_i2c(0, 0);printStringLCD_i2c("MOTOR TAMBOR ");
	setCursorLCD_i2c(1, 0);printStringLCD_i2c("MOTOR GAVETA ");
}

void maskRelogio(void)
{
	cmdLCD_i2c(_LCD_LIMPA);
	setCursorLCD_i2c(0, 0);printStringLCD_i2c("HORA....:           ");
	setCursorLCD_i2c(1, 0);printStringLCD_i2c("MINUTO..:           ");
	setCursorLCD_i2c(2, 0);printStringLCD_i2c("SEGUNDO.:           ");
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








