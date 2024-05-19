#include "config.c"

unsigned char s = 0;

void paginaHome(void);
void paginaConfiguracoes(void);
void paginaMonitoramento(void);
void paginaSobre(void);

void configSprays(void);
void cabecalhoPaginaConfiguracoes(void);
void configMotores(void);
void configRelogio(void);
void configData(void);

void atualizaInfoSpray(void);


void atualizaIndice(void);
void atualizaIndiceInfo(void);
void atualizaIndiceConfiguracoes(void);
void menuSelect(void);
//void infoSelect(void);
void configuracoesSelect(void);
void TelaInicializacao(void);
void atualizaSensores(void);
void atualizaMotores(void);
void atualizaMotores(void);
void piscaCursor(void);

signed short lerAnalogico(char CANAL);
void lerBotoes(void);
void lerBtnLeft(void);
void lerBtnRight(void);
void lerBtnUp(void);
void lerBtnDown(void);
void lerBtnEnter(void);
void atualizaBotoes(void);
void resetBotoes(void);

void convertShortToChar(unsigned short num, char *str) ;

void delay_ms (unsigned int tempo);

// Prot?tipos das Rotinas de Tratamento de Interrup??es (interrupcaoRelogio)
void configTimer1(void);
void setTimer1(void);
void configInterrupcaoRelogio(void);
void configPWM(void);
void interrupcaoRelogio(void);
void atualizaRelogio(void);
void mostrarRelogio(void);
void setupRelogio(void);

// Redirecionamento para a interrupcaoRelogio
#pragma code high_vector=0x08 // alta prioridade
void interrupt_at_high_vector(void)
{
  _asm GOTO interrupcaoRelogio _endasm
}
#pragma code

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

void cabecalhoPaginaConfiguracoes(void)
{
	setCursorLCD_i2c(0,0);printStringLCD_i2c("  SPRAY PUIFICADOR  ");
	setCursorLCD_i2c(1,0);printStringLCD_i2c("  VELOCIDADE MOTORES");
	setCursorLCD_i2c(2,0);printStringLCD_i2c("  HORA DO RELOGIO   ");
	setCursorLCD_i2c(3,0);printStringLCD_i2c("  DATA              ");
}
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

// SUB-ROTINA TELA Sprays
void configSprays(void)
{
	maskPurificador();
	linha = 0;coluna = 0;
	setCursorLCD_i2c(linha, coluna);
	novo_sprays_capacidade = sprays_capacidade;
	novo_sprays_utilizado = sprays_utilizado;

	while(!sair)
	{				
		lerBtnUp();
		lerBtnDown();
		lerBtnRight();
		lerBtnLeft();
		lerBtnEnter();
		
		atualizaInfoSpray();

		

		for(s=0;s<3;s++)
		{
			setCursorLCD_i2c(0,15+s);
			printCharLCD_i2c(info_sprays_capacidade[s]);
			setCursorLCD_i2c(1,15+s);
			printCharLCD_i2c(info_sprays_utilizado[s]);
		}

		if (flag_btn[up])
		{
			resetBotoes();
			setCursorLCD_i2c(linha, coluna);printCharLCD_i2c('  ');
			if(linha == 0) linha = 2;
			else linha --;	
		}
		
		if (flag_btn[down])
		{
			resetBotoes();
			setCursorLCD_i2c(linha, coluna);printCharLCD_i2c('  ');
			if(linha == 2) linha = 0;
			else linha ++;	
		}
		
		switch(linha)
		{
			case 0:
				if (flag_btn[left])
				{
					resetBotoes();
					if(novo_sprays_capacidade == 0) novo_sprays_capacidade = 0;
					else novo_sprays_capacidade --;	
				}
	
				if (flag_btn[right])
				{
					resetBotoes();
					if(novo_sprays_capacidade == 999 ) novo_sprays_capacidade = 999;
					else novo_sprays_capacidade ++;	
				}
				break;
			case 1:
				if (flag_btn[left])
				{
					resetBotoes();
					if(novo_sprays_utilizado == 0) novo_sprays_utilizado = 0;
					else novo_sprays_utilizado --;	
				}
	
				if (flag_btn[right])
				{
					resetBotoes();
					if(novo_sprays_utilizado == 999 ) novo_sprays_utilizado = 999;
					else novo_sprays_utilizado ++;	
				}
				break;
			case 2:
				if (flag_btn[left])
				{
					resetBotoes();
					setCursorLCD_i2c(linha, coluna);printCharLCD_i2c('  ');
					if(coluna == 0) coluna = 11;
					else coluna -= 11;	
				}
				
				if (flag_btn[right])
				{
					resetBotoes();
					setCursorLCD_i2c(linha, coluna);printCharLCD_i2c('  ');
					if(coluna == 11) coluna = 0;
					else coluna += 11;	
				}
				
				if (flag_btn[enter])
				{
					resetBotoes();
					sair = 1;
					if(coluna == 0)
					{
						sprays_capacidade = novo_sprays_capacidade;
						sprays_utilizado = novo_sprays_utilizado;
					}
				}
				break;
		}		
		//setCursorLCD_i2c(3, 19);
		//printShortLCD_i2c(linha);
		setCursorLCD_i2c(linha, coluna);
		piscaCursor();
	}
	linha = 0, coluna = 0, sair = 0;
	resetBotoes();
	cmdLCD_i2c(_LCD_LIMPA);
	cabecalhoPaginaConfiguracoes();
}

void configMotores(void)
{
	maskMotores();
	linha = 0;coluna = 0;
	setCursorLCD_i2c(linha, coluna);
	
	while(!sair)
	{				
		lerBtnUp();
		lerBtnDown();
		lerBtnRight();
		lerBtnLeft();
		lerBtnEnter();
		
		if (flag_btn[up])
		{
			resetBotoes();
			setCursorLCD_i2c(linha, coluna);printCharLCD_i2c('  ');
			if(linha == 0) linha = 2;
			else linha --;	
		}
		
		if (flag_btn[down])
		{
			resetBotoes();
			setCursorLCD_i2c(linha, coluna);printCharLCD_i2c('  ');
			if(linha == 2) linha = 0;
			else linha ++;	
		}
		if (linha > 1)
		{
			if (flag_btn[left])
			{
				resetBotoes();
				setCursorLCD_i2c(linha, coluna);printCharLCD_i2c('  ');
				if(coluna == 0) coluna = 11;
				else coluna -= 11;	
			}
			
			if (flag_btn[right])
			{
				resetBotoes();
				setCursorLCD_i2c(linha, coluna);printCharLCD_i2c('  ');
				if(coluna == 11) coluna = 0;
				else coluna += 11;	
			}
			
			if (flag_btn[enter])
			{
				resetBotoes();
				sair = 1;
			}
		}
		
		//setCursorLCD_i2c(3, 19);
		//printShortLCD_i2c(linha);
		setCursorLCD_i2c(linha, coluna);
		piscaCursor();
		
	}
	linha = 1, coluna = 0, sair = 0;
	resetBotoes();
	cmdLCD_i2c(_LCD_LIMPA);
	cabecalhoPaginaConfiguracoes();
	//implementar
}

void configRelogio(void)
{
	maskRelogio();
	linha = 0;coluna = 0;
	setCursorLCD_i2c(linha, coluna);
	//PIE1bits.TMR1IE = !PIE1bits.TMR1IE; // Desabilita interrupcao do Timer1
	new_secs = secs, new_mins = mins, new_hours = hours;

	while(!sair)
	{				
		lerBtnUp();
		lerBtnDown();
		lerBtnRight();
		lerBtnLeft();
		lerBtnEnter();
	
		setCursorLCD_i2c(0, 14);
		printShortLCD_i2c(new_hours);

		setCursorLCD_i2c(1, 14);
		printShortLCD_i2c(new_mins);

		setCursorLCD_i2c(2, 14);
		printShortLCD_i2c(new_secs);		

		if (flag_btn[up])
		{
			resetBotoes();
			setCursorLCD_i2c(linha, coluna);printCharLCD_i2c('  ');
			if(linha == 0) linha = 3;
			else linha --;	
		}
		
		if (flag_btn[down])
		{
			resetBotoes();
			setCursorLCD_i2c(linha, coluna);printCharLCD_i2c('  ');
			if(linha == 3) linha = 0;
			else linha ++;	
		}

		switch(linha)
		{
			case 0:
				if (flag_btn[left])
				{
					resetBotoes();
					setCursorLCD_i2c(linha, coluna);printCharLCD_i2c('  ');
					if(new_hours == 0) new_hours = 24;
					else new_hours --;	
				}
				
				if (flag_btn[right])
				{
					resetBotoes();
					setCursorLCD_i2c(linha, coluna);printCharLCD_i2c('  ');
					if(new_hours == 24) new_hours = 0;
					else new_hours ++;		
				}
				break;
			case 1:
				if (flag_btn[left])
				{
					resetBotoes();
					setCursorLCD_i2c(linha, coluna);printCharLCD_i2c('  ');
					if(new_mins == 0) new_mins = 60;
					else new_mins --;	
				}
				
				if (flag_btn[right])
				{
					resetBotoes();
					setCursorLCD_i2c(linha, coluna);printCharLCD_i2c('  ');
					if(new_mins == 60) new_mins = 0;
					else new_mins ++;		
				}
				break;
			case 2:
				if (flag_btn[left])
				{
					resetBotoes();
					setCursorLCD_i2c(linha, coluna);printCharLCD_i2c('  ');
					if(new_secs == 0) new_secs = 60;
					else new_secs --;	
				}
				
				if (flag_btn[right])
				{
					resetBotoes();
					setCursorLCD_i2c(linha, coluna);printCharLCD_i2c('  ');
					if(new_secs == 60) new_secs = 0;
					else new_secs ++;		
				}
				break;
			case 3:
				if (flag_btn[left])
				{
					resetBotoes();
					setCursorLCD_i2c(linha, coluna);printCharLCD_i2c('  ');
					if(coluna == 0) coluna = 11;
					else coluna -= 11;	
				}
				
				if (flag_btn[right])
				{
					resetBotoes();
					setCursorLCD_i2c(linha, coluna);printCharLCD_i2c('  ');
					if(coluna == 11) coluna = 0;
					else coluna += 11;	
				}
				
				if (flag_btn[enter])
				{
					resetBotoes();
					sair = 1;
					if(coluna == 0)
					{
						hours = new_hours;
						mins = new_mins;
						secs = new_secs;
					}
				}
				break;
	
		}
		setCursorLCD_i2c(linha, coluna);
		piscaCursor();
	}
	linha = 2, coluna = 0, sair = 0;
	resetBotoes();
	cmdLCD_i2c(_LCD_LIMPA);
	cabecalhoPaginaConfiguracoes();
}

void configData(void)
{
	maskData();
	linha = 1;coluna = 0;
	setCursorLCD_i2c(linha, coluna);
	new_dias = dias;

	while(!sair)
	{				
		lerBtnUp();
		lerBtnDown();
		lerBtnRight();
		lerBtnLeft();
		lerBtnEnter();	
	
		setCursorLCD_i2c(1,13);
		printShortLCD_i2c(new_dias);
		
		setCursorLCD_i2c(1,14);
		
		switch(new_dias)
		{
			case 0:
				printStringLCD_i2c("-DOM");
				break;
			case 1:
				printStringLCD_i2c("-SEG");
				break;
			case 2:
				printStringLCD_i2c("-TER");
				break;
			case 3:
				printStringLCD_i2c("-QUA");
				break;
			case 4:
				printStringLCD_i2c("-QUI");
				break;
			case 5:
				printStringLCD_i2c("-SEX");
				break;
			case 6:
				printStringLCD_i2c("-SAB");
				break;			
		}

		if (flag_btn[up])
		{
			resetBotoes();
			setCursorLCD_i2c(linha, coluna);printCharLCD_i2c('  ');
			if(linha == 1) linha = 2;
			else linha --;	
		}
		
		if (flag_btn[down])
		{
			resetBotoes();
			setCursorLCD_i2c(linha, coluna);printCharLCD_i2c('  ');
			if(linha == 2) linha = 1;
			else linha ++;	
		}
		
		switch(linha)
		{
			case 1:
				if (flag_btn[left])
				{
					resetBotoes();
					if(new_dias == 0) new_dias = 6;
					else new_dias --;	
				}
	
				if (flag_btn[right])
				{
					resetBotoes();
					if(new_dias == 6) new_dias = 0;
					else new_dias ++;
				}
				break;
			case 2:
				if (flag_btn[left])
				{
					resetBotoes();
					setCursorLCD_i2c(linha, coluna);printCharLCD_i2c('  ');
					if(coluna == 0) coluna = 11;
					else coluna -= 11;	
				}
				
				if (flag_btn[right])
				{
					resetBotoes();
					setCursorLCD_i2c(linha, coluna);printCharLCD_i2c('  ');
					if(coluna == 11) coluna = 0;
					else coluna += 11;	
				}
				
				if (flag_btn[enter])
				{
					resetBotoes();
					sair = 1;
					if(coluna == 0) dias = new_dias;
				}
				break;
		}		
		setCursorLCD_i2c(linha, coluna);
		piscaCursor();
	}
	linha = 3, coluna = 0, sair = 0;
	resetBotoes();
	cmdLCD_i2c(_LCD_LIMPA);
	cabecalhoPaginaConfiguracoes();
}
//------------------------------------controle-telas------------------------------------//
void atualizaInfoSpray(void)
{
	info_sprays_capacidade[2] = novo_sprays_capacidade % 10 + '0';
	info_sprays_capacidade[1] = (novo_sprays_capacidade / 10) % 10 + '0';
	info_sprays_capacidade[0] = (novo_sprays_capacidade / 10) / 10 + '0';

	info_sprays_utilizado[2] = novo_sprays_utilizado % 10 + '0';
	info_sprays_utilizado[1] = (novo_sprays_utilizado / 10) % 10 + '0';
	info_sprays_utilizado[0] = (novo_sprays_utilizado / 10) / 10 + '0';
}

void configuracoesSelect(void)
{
	cmdLCD_i2c(_LCD_LIMPA);
	switch(linha)
	{
		case 0:
			configSprays();
			break;
		case 1:
			configMotores();
			break;
		case 2:
			configRelogio();
			break;
		case 3:
			configData();
			break;
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
	//setCursorLCD_i2c(3, 19);
	//printShortLCD_i2c(linha);
	setCursorLCD_i2c(linha, coluna);
	piscaCursor();
	resetBotoes();
}

// SUB-ROTINA P/ ATUALIZAR O INDICE DO DISPLAY
void piscaCursor(void)
{	
	if(cursor_visivel)	printCharLCD_i2c('>');
	else				printCharLCD_i2c('  ');
}

void atualizaIndice(void)
{
	if (linha == 0) 	 indice = 1; //home
	else if (linha == 0 && coluna == 8) indice = 2; // config
	else if (linha == 1 && coluna == 0) indice = 3; // info
	else if (linha == 1 && coluna == 8) indice = 4; // me
}

void atualizaIndiceInfo(void)
{
	if(linha == 1)		indice = 1; // motores
	else if(linha == 2) 	indice = 2; // sensores
	else if(linha == 3) 	indice = 3; // purificador
}

void atualizaIndiceConfiguracoes(void)
{
	if(linha == 1)		indice = 1; // motores
	else if(linha == 2)	indice = 2; // sensores
	else if(linha == 3)	indice = 3; // relogio
}

void atualizaSensores(void)
{
	atualizaBotoes();
	
	while(!flag_btn[left])
	{
		flag_btn[left] = 0;
		setCursorLCD_i2c(0, 16);
		if(FIM_CURSO_TB_SUPERIOR)	printStringLCD_i2c("ON ");
		else 						printStringLCD_i2c("OFF");
		
		setCursorLCD_i2c(1, 16);
		if(FIM_CURSO_TB_INFERIOR)	printStringLCD_i2c("ON ");
		else						printStringLCD_i2c("OFF");

		setCursorLCD_i2c(2, 16);
		if(FIM_CURSO_GV_ABERTO)		printStringLCD_i2c("ON ");
		else						printStringLCD_i2c("OFF");
		
		setCursorLCD_i2c(3, 16);
		if(FIM_CURSO_GV_FECHADO)	printStringLCD_i2c("ON ");	
		else						printStringLCD_i2c("OFF");
		atualizaBotoes();
	}
	flag_btn[left] = 0;
	linha = 2; coluna = 0;
	atualizaIndiceInfo();paginaMonitoramento();
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
	linha = 1; coluna = 0;
	atualizaIndiceInfo();paginaMonitoramento();
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
	atualizaIndiceInfo();paginaMonitoramento();
}

/*
void infoSelect(void)
{
	if(flag_btn[enter])
	{
		flag_btn[enter] = 0;
		cmdLCD_i2c(_LCD_LIMPA);
		switch(indice)
		{
			case 1:
				maskMotores();
				atualizaMotores();
				break;
			case 2:
				maskMonitoramento();
				atualizaSensores();
				break;
			case 3:
				maskPurificador();
				mostraPurificador();
				break;
		}
	}
	if(flag_btn[left])
	{
		flag_btn[left] = 0;
		linha = 1;coluna = 0;
		atualizaIndice();
		maskInit();TelaInicializacao();
	}
}
*/


//------------------------------controle-botoes-analogicos------------------------------//
// SUB-ROTINA PARA LEITURA DE UMA PORTA ANALOGICA DO PIC
signed short lerAnalogico(char CANAL)
{
	ADCON0bits.CHS = CANAL;		// Seleciona canal A/D
	Delay100TCYx(1);				// Aguarda tempo para troca de canal antes de iniciar convers?o
	ADCON0bits.GO_DONE = 1;    	// Inicia a convers?o
	while(ADCON0bits.GO_DONE);  // Aguarda t?rmino da convers?o
	
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
			
			if(estado_atual && !estado_anterior_btn[i])	flag_btn[i]= 1;
		}
		estado_anterior_btn[i] = estado_atual;
	}
}

// enter,left,up,right,down
void lerBtnEnter(void)
{
	VAN0 = lerAnalogico(0);
	estado_btn = 0;
	
	if ((faixas[enter] - VARIACAO) <= VAN0 && (faixas[enter] + VARIACAO) >= VAN0)
	{
		estado_btn = 1;
		if(estado_btn && !estado_anterior_btn[enter]) flag_btn[enter]= 1;
	}
	estado_anterior_btn[enter] = estado_btn;
}
void lerBtnLeft(void)
{
	VAN0 = lerAnalogico(0);
	estado_btn = 0;
	
	if ((faixas[left] - VARIACAO) <= VAN0 && (faixas[left] + VARIACAO) >= VAN0)
	{
		estado_btn = 1;
		if(estado_btn && !estado_anterior_btn[left]) flag_btn[left]= 1;
	}
	estado_anterior_btn[left] = estado_btn;
}

void lerBtnUp(void)
{
	VAN0 = lerAnalogico(0);
	estado_btn = 0;
	
	if ((faixas[up] - VARIACAO) <= VAN0 && (faixas[up] + VARIACAO) >= VAN0)
	{
		estado_btn = 1;
		if(estado_btn && !estado_anterior_btn[up]) flag_btn[up]= 1;
	}
	estado_anterior_btn[up] = estado_btn;
}

void lerBtnRight(void)
{
	VAN0 = lerAnalogico(0);
	estado_btn = 0;
	
	if ((faixas[right] - VARIACAO) <= VAN0 && (faixas[right] + VARIACAO) >= VAN0)
	{
		estado_btn = 1;
		if(estado_btn && !estado_anterior_btn[right]) flag_btn[right]= 1;
	}
	estado_anterior_btn[right] = estado_btn;
}

void lerBtnDown(void)
{
	VAN0 = lerAnalogico(0);
	estado_btn = 0;
	
	if ((faixas[down] - VARIACAO) <= VAN0 && (faixas[down] + VARIACAO) >= VAN0)
	{
		estado_btn = 1;
		if(estado_btn && !estado_anterior_btn[down]) flag_btn[down]= 1;
	}
	estado_anterior_btn[down] = estado_btn;
}

void atualizaBotoes(void)
{
	VAN0 = lerAnalogico(0);
	lerBotoes();
}

void resetBotoes(void)
{
	unsigned char i;
	for(i = 0; i < QTD_BTNS; i++)
	{
		flag_btn[i]= 0;
	}
}
//---------------------------------manipulacao-de-dados---------------------------------//

// SUB-ROTINA PARA CONVERSAO DE UM INT PARA CHAR
void convertShortToChar(unsigned short num, char *str) 
{
	
	int length = lenShort(num); // Come?amos com um d?gito para o caractere nulo
	int i = 0;
		
	// Converte o n?mero em uma string de caracteres
	for (i = length - 1; i >= 0; i--)
	{
		str[i] = num % 10 + '0'; // Converte o d?gito para seu caractere correspondente
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

void interrupcaoRelogio(void)
{
	if(PIR1bits.TMR1IF == 1)
	{
		if(boas_vindas > 0 ) boas_vindas --;
		variavel_teste --;
		secs++;
		cursor_visivel = !cursor_visivel;
		if(secs == 0x3c)
		{
			secs = 0x00;
			mins++;
			if(mins == 0x3c)
			{
				mins = 0x00;
				hours++;
				if(hours == 0x18)
				{
					hours = 0x00;
					if (dias == 6) dias = 0x00;
					else dias++;
				}
			}
		}
		setTimer1();
	}
}

void configInterrupcaoRelogio(void)
{
   // Configura??o das interrup??es	
   
   RCONbits.IPEN 	= 0; // Desabilita atribui??o de prioridades ?s interrup??es
   INTCONbits.GIE 	= 1; // Habilita todas as interrup??es
   INTCONbits.PEIE 	= 1; // Habilita interrup??es geradas a partir de perif?ricos do PIC
   PIE1bits.TMR1IE	= 1; // Habilita interrup??o do Timer1
}

void configTimer1(void)
{
	T1CONbits.RD16		= 1; //contador de 8 bits (0) / contador de 16 bits (1)
	T1CONbits.T1RUN 	= 1; //fonte de clock: oscilador interno (1) / outra fonte (0)
	T1CONbits.T1CKPS1	= 0; // T1CKPS1:T1CKPS0 ? Configura??o do prescaler ? 00 (1:1), 01 (1:2), 10 (1:4), 11 (1:8)
	T1CONbits.T1CKPS0	= 0;
	T1CONbits.T1OSCEN 	= 1; // (modo de eco. de ener.) ? habilita (1) desliga o oscilador interno (0)
	T1CONbits.T1SYNC	= 0; // (somente no modo contador) ? modo s?ncrono (0) ou ass?ncrono (1)
	T1CONbits.TMR1CS	= 1; //modo contador ou economia de energia (1) / temporizador (0)
	T1CONbits.TMR1ON	= 1; //habilita o contador (1) , para o contador (0)
	setTimer1();
	
}

void setTimer1(void)
{
   PIR1bits.TMR1IF = 0;
   TMR1H = 0xC0;          
   TMR1L = 0x00;
}

void atualizaRelogio(void)
{
	relogio[1] = hours%10 + '0';
	relogio[0] = hours/10 + '0';
	
	relogio[4] = mins%10 + '0';
	relogio[3] = mins/10 + '0';
	
	relogio[9] = secs%10 + '0';
	relogio[8] = secs/10 + '0';
}

void mostrarRelogio(void)
{
	unsigned char i = 0;
	setCursorLCD_i2c(1,4);
	
	for(i=0;i<14;i++) printCharLCD_i2c(relogio[i]);
	setCursorLCD_i2c(2,0);
	switch(dias)
	{
		case 0:
			printStringLCD_i2c("      DOMINGO       ");
			break;
		case 1:
			printStringLCD_i2c("   SEGUNDA-FEIRA    ");
			break;
		case 2:
			printStringLCD_i2c("    TERCA-FEIRA     ");
			break;
		case 3:
			printStringLCD_i2c("    QUARTA-FEIRA    ");
			break;
		case 4:
			printStringLCD_i2c("    QUINTA-FEIRA    ");
			break;
		case 5:
			printStringLCD_i2c("    SEXTA-FEIRA     ");
			break;
		case 6:
			printStringLCD_i2c("       SABADO       ");
			break;
		default:
			printStringLCD_i2c("                    ");
			break;
	}
}

void setupRelogio(void)
{
	linha = 0; coluna = 12;

	while(!flag_btn[left])
	{
		lerBtnUp();
		lerBtnDown();
		lerBtnLeft();

		setCursorLCD_i2c(0, coluna+2); printShortLCD_i2c(hours);
		setCursorLCD_i2c(1, coluna+2); printShortLCD_i2c(mins);
		setCursorLCD_i2c(2, coluna+2); printShortLCD_i2c(secs);

		if (flag_btn[up])
		{
			flag_btn[up] = 0;
			setCursorLCD_i2c(linha, coluna); printCharLCD_i2c('  ');
			if (linha == 0) linha = 2;
			else linha --;
		}

		if (flag_btn[down])
		{
			flag_btn[down] = 0;
			setCursorLCD_i2c(linha, coluna); printCharLCD_i2c('  ');
			if (linha == 2) linha = 0;
			else linha ++;
		}

		setCursorLCD_i2c(3, 19);printShortLCD_i2c(indice);
		setCursorLCD_i2c(linha, coluna);piscaCursor();
	}
	resetBotoes();
	linha = 1, coluna = 0;
}

void configPWM(void)
{
	// Inicializa do Timer2: responsável por determinar a frequência dos canais PWM

	// Configuracao do POSTSCALER - T2OUTPS3:T2OUTPS0 - 0000 (1:1) ATE 1111 (1:16)
	T2CONbits.T2OUTPS3 = 0;T2CONbits.T2OUTPS2 = 0;T2CONbits.T2OUTPS1 = 0;T2CONbits.T2OUTPS0 = 0;
	T2CONbits.TMR2ON = 1; // Habilita (1) / Desabilita (0) o contador
	
	//Configuração do prescaler - T2CKPS1:T2CKPS0 - 00 (SEM DIVISAO) 01 (1:4) 1X (1:16)
	T2CONbits.T2CKPS1 = 0;T2CONbits.T2CKPS0 = 0;
	PIR1bits.TMR2IF = 0; // Limpa flag de overflow do Timer2
	
	/*
	Fosc = Frequencia do microcontrolador
	1/Fosc = Tosc = Periodo do microcontrolador
	Tpwm = Tosc*4*TMR2Prescale*(PR2+1) = Periodo do PWM
	PR2 = (Tpwm / (Tosc*4*TMR2Prescale)) - 1
	*/
	
	// Fpwm = 10KHz -> Tpwm = 1/Fpwm = 100us
	// Fosc = 4MHz  -> Tosc = 1/Fosc = 250ns
	// PR2 = (100us / (250ns*4*1)) - 1 = 99

	PR2 = 100;
	/*
	DC1B1:DC1B0 – bits 1 e 0 do Duty Cycle do PWM1
	CCP1M3:CCP1M0 – Configuração do módulo CCP1
	0000 (CCP desabilitado)
	0001 (reservado)
	0010 (Modo Comparação)
	0011 (reservado) ATE 1011 (reservado) 1011 (Modo Comparação)
	11xx (Modo PWM)
	1100 – saída ativo alto
	1101 – saída ativo alto
	1111 – saída ativo baixo (pwm invertido)
	1111 – saída ativo baixo (pwm invertido)
	*/

	CCP1CONbits.DC1B1 = 0;CCP1CONbits.DC1B0 = 0;
	CCP1CONbits.CCP1M3 = 1;CCP1CONbits.CCP1M2 = 1;CCP1CONbits.CCP1M1 = 0;CCP1CONbits.CCP1M0 = 0;
	
	// DCpwm = DUTY CYCLE
	// CCPR1L = DCpwm * (PR2+1) = 0,5*100 = 50
	// Ton = Tosc*CCPR1L*4*TRM2Prescaler = 125us
	
	CCPR1L  = 30;

	// Inicializa do Timer2: responsável por determinar a frequência dos canais PWM
  //T2CON = 0x04;        // POSTSCALER: 1:1, ligado, PRESCALER 1:1
  //PIR1bits.TMR2IF = 0; // Limpa flag de overflow do Timer2
  //PR2 = 100;            // Período do Timer2 (Fpwm=10KHz, Fosc=4MHz)
	
  // Inicializa PMW 1 com Ajuste 30%
  //CCP1CON = 0x0C; // LSBs do duty cycle = 00 (não usado em 8 bits), operação como PWM (canal 1 Ativo alto)
  //CCPR1L  = 30;   // 8 bits mais significativos do duty cycle (PWM1)
}

