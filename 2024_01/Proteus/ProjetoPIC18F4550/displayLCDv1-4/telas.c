#include "selecoes_atualizacoes.c"

void TelaInicializacao(void);
void paginaHome(void);
void paginaConfiguracoes(void);
void paginaMonitoramento(void);
void paginaSobre(void);

//----------------------------------------telas----------------------------------------//

// SUB-ROTINA TELA paginaHome
void paginaHome(void)
{
	setCursorLCD_i2c(linha, coluna);
	printStringLCD_i2c("------CAT-BOX------");
	
	while(!flag_btn[left])
	{				
		atualizaRelogio();
		mostrarRelogio();
		lerBtnLeft();
	}
	resetBotoes();
}

// SUB-ROTINA TELA paginaConfiguracoes
void paginaConfiguracoes(void)
{
	cabecalhoPaginaConfiguracoes();
	linha = 0;setCursorLCD_i2c(linha, coluna);
	
	while(!flag_btn[left])
	{
		lerBtnUp();
		lerBtnDown();
		lerBtnLeft();
		lerBtnEnter();
		if(flag_btn[up])
		{
			resetBotoes();
			setCursorLCD_i2c(linha, coluna);
			printCharLCD_i2c('  ');
			if(linha == 0) linha = 3;
			else linha --;			
		}
		if(flag_btn[down])
		{
			resetBotoes();
			setCursorLCD_i2c(linha, coluna);printCharLCD_i2c('  ');
			if(linha == 3) linha = 0;
			else linha ++;	
		}
		
		if(flag_btn[enter])
		{
			configuracoesSelect();	
		}
		
		setCursorLCD_i2c(linha, coluna);
		piscaCursor();
	}
	resetBotoes();
	linha = 1;
}

// SUB-ROTINA TELA paginaMonitoramento
void paginaMonitoramento(void)
{
	setCursorLCD_i2c(0, 0);printStringLCD_i2c("MOTOR TAMB: OFF-00% ");
	setCursorLCD_i2c(1, 0);printStringLCD_i2c("MOTOR COMP: OFF-00% ");
	setCursorLCD_i2c(2, 0);printStringLCD_i2c("LIMPEZAS FEITAS:00  ");
	
	while(!flag_btn[left])
	{
		lerBtnLeft();
	}
	resetBotoes();
	linha = 2;
}

// SUB-ROTINA TELA paginaSobre
void paginaSobre(void)
{
	setCursorLCD_i2c(0, 0);printStringLCD_i2c(" Desenvolvedor: JMFJ");
	setCursorLCD_i2c(1, 0);printStringLCD_i2c("  Medidas da Caixa: ");
	setCursorLCD_i2c(2, 0);printStringLCD_i2c("   450x330x780 cm   ");
	setCursorLCD_i2c(3, 0);printStringLCD_i2c("   Limpeza: DIARIA  ");
	
	while(!flag_btn[left])
	{
		lerBtnLeft();
	}
	resetBotoes();
	linha = 3;
}







