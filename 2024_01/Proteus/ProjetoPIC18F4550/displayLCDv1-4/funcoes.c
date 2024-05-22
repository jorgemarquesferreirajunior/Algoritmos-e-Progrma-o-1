#include "telas.c"


void menuSelect(void);

// SUB-ROTINA PARA SELECAO DO MENU DE VISUALIZACAO
void menuSelect(void)
{	
	lerBtnEnter();
	if(flag_btn[enter])
	{
		resetBotoes();
		cmdLCD_i2c(_LCD_LIMPA);
		switch(linha)
		{
			case 0:
				paginaHome();
				break;
			case 1:
				paginaConfiguracoes();
				break;
			case 2:
				paginaMonitoramento();
				break;
			case 3:
				paginaSobre();
				break;
		}
		maskInit();
	}
	resetBotoes();
}

// SUB-ROTINA PARA NAVEGACAO NA TELA DE INICIALIZACAO
void TelaInicializacao(void)
{	
	setCursorLCD_i2c(linha, coluna);
	lerBtnUp();
	lerBtnDown();

	if(flag_btn[up])
	{
		setCursorLCD_i2c(linha, coluna);printCharLCD_i2c('  ');
		if(linha == 0) linha = 3;
		else linha --;			
	}
	if(flag_btn[down])
	{
		setCursorLCD_i2c(linha, coluna);printCharLCD_i2c('  ');
		if(linha == 3) linha = 0;
		else linha ++;	
	}
	setCursorLCD_i2c(linha, coluna);
	piscaCursor();
	resetBotoes();
}

void mostraPurificador(void)
{
	atualizaBotoes();
	
	while(!flag_btn[left])
	{
		setCursorLCD_i2c(1,13);printShortLCD_i2c(sprays_capacidade);
		setCursorLCD_i2c(1,9);printShortLCD_i2c(sprays_utilizado);
		atualizaBotoes();
	}
	flag_btn[left] = 0;
	linha = 3; coluna = 0;
	paginaMonitoramento();
}
