#include "config.c"

signed short lerAnalogico(char CANAL);
void lerBotoes(void);
void lerBtnLeft(void);
void lerBtnRight(void);
void lerBtnUp(void);
void lerBtnDown(void);
void lerBtnEnter(void);
void atualizaBotoes(void);
void resetBotoes(void);

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

// SUB-ROTINA PARA MONITORAMENTO DE TODOS OS BOTOES ANALOGICOS
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

// SUB-ROTINA PARA MONITORAMENTO DO BOTAO ENTER
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

// SUB-ROTINA PARA MONITORAMENTO DO BOTAO LEFT
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

// SUB-ROTINA PARA MONITORAMENTO DO BOTAO UP
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

// SUB-ROTINA PARA MONITORAMENTO DO BOTAO RIGHT
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

// SUB-ROTINA PARA MONITORAMENTO DO BOTAO DOWN
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

// SUB-ROTINA PARA VERIFICAR AS FLAGS DE TODOS OS BOTOES
void atualizaBotoes(void)
{
	VAN0 = lerAnalogico(0);
	lerBotoes();
}

// SUB-ROTINA PARA RESETAR AS FLAGS DE TODOS OS BOTOES
void resetBotoes(void)
{
	unsigned char i;
	for(i = 0; i < QTD_BTNS; i++)
	{
		flag_btn[i]= 0;
	}
}
