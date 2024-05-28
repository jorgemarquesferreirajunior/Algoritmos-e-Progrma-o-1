#include "timer_relogio_pwm.c"

void atualizaIndice(void);
void configuracoesSelect(void);
void configSprays(void);
void configMotores(void);
void configRelogio(void);
void configData(void);
void atualizaInfoSpray(void);

//---------------------------------controle-de-paginas---------------------------------//

// SUB-ROTINA PARA ATUALIZAR A QTD DE SPRAYS
void atualizaInfoSpray(void)
{
	info_sprays_capacidade[2] = novo_sprays_capacidade % 10 + '0';
	info_sprays_capacidade[1] = (novo_sprays_capacidade / 10) % 10 + '0';
	info_sprays_capacidade[0] = (novo_sprays_capacidade / 10) / 10 + '0';

	info_sprays_utilizado[2] = novo_sprays_utilizado % 10 + '0';
	info_sprays_utilizado[1] = (novo_sprays_utilizado / 10) % 10 + '0';
	info_sprays_utilizado[0] = (novo_sprays_utilizado / 10) / 10 + '0';
}

// SUB-ROTINA PARA IDENTIFICAR A PAGINA ATUAL SELECIONADA
void atualizaIndice(void)
{
	if (linha == 0) 	 				indice = 1; //home
	else if (linha == 0 && coluna == 8) indice = 2; // configuracoes
	else if (linha == 1 && coluna == 0) indice = 3; // monitoramento
	else if (linha == 1 && coluna == 8) indice = 4; // sobre
}

// SUB-ROTINA PARA SELECIONAR A PAGINA DE ACESSO DENTRO DE CONFIGURACOES
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

// SUB-ROTINA PARA CONFIGURAR O SPRAY
void configSprays(void)
{
	int s;
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
		setCursorLCD_i2c(linha, coluna);
		piscaCursor();
	}
	linha = 0, coluna = 0, sair = 0;
	resetBotoes();
	cmdLCD_i2c(_LCD_LIMPA);
	cabecalhoPaginaConfiguracoes();
}

// SUB-ROTINA PARA CONFIGURAR OS MOTORES
void configMotores(void)
{
	maskMotores();
	linha = 0;coluna = 0;
	setCursorLCD_i2c(linha, coluna);
	new_pwm_motor_tambor = pwm_motor_tambor;
	new_pwm_motor_comporta = pwm_motor_comporta;
	while(!sair)
	{				
		lerBtnUp();
		lerBtnDown();
		lerBtnRight();
		lerBtnLeft();
		lerBtnEnter();
		
		setCursorLCD_i2c(0, 18);
		printShortLCD_i2c(new_pwm_motor_tambor);
		
		setCursorLCD_i2c(1, 18);
		printShortLCD_i2c(new_pwm_motor_comporta);	
		
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
					setCursorLCD_i2c(linha, coluna);printCharLCD_i2c('  ');
					if(new_pwm_motor_tambor == 0) new_pwm_motor_tambor = 99;
					else new_pwm_motor_tambor --;
				}
				if (flag_btn[right])
				{
					resetBotoes();
					setCursorLCD_i2c(linha, coluna);printCharLCD_i2c('  ');
					if(new_pwm_motor_tambor == 99) new_pwm_motor_tambor = 0;
					else new_pwm_motor_tambor ++;
				}
				break;
			case 1:
				if (flag_btn[left])
				{
					resetBotoes();
					setCursorLCD_i2c(linha, coluna);printCharLCD_i2c('  ');
					if(new_pwm_motor_comporta == 0) new_pwm_motor_comporta = 99;
					else new_pwm_motor_comporta --;
				}
				if (flag_btn[right])
				{
					resetBotoes();
					setCursorLCD_i2c(linha, coluna);printCharLCD_i2c('  ');
					if(new_pwm_motor_comporta == 99) new_pwm_motor_comporta = 0;
					else new_pwm_motor_comporta ++;
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
						pwm_motor_comporta = new_pwm_motor_comporta;
						pwm_motor_tambor = new_pwm_motor_tambor;
					}
				}
				break;
		}		
		setCursorLCD_i2c(linha, coluna);
		piscaCursor();
	}
	linha = 1, coluna = 0, sair = 0;
	resetBotoes();
	cmdLCD_i2c(_LCD_LIMPA);
	cabecalhoPaginaConfiguracoes();
}

// SUB-ROTINA PARA CONFURAR A HORA
void configRelogio(void)
{
	maskRelogio();
	linha = 0;coluna = 0;
	setCursorLCD_i2c(linha, coluna);
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

// SUB-ROTINA PARA CONFIGURAR A DATA
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

