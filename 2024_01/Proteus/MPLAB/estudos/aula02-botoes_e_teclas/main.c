#include<18F4550.h>
#fuses XT, NOLVP, NOWDT
#use delay(clock=4000000)

struct botao
{
	int pino, clicado, liberado;
};

int dado = 0;
struct botao botaoA0, botaoA1;

// prototipos
void atualiza_dado(int *valor);
int botao_pressionado(struct botao *botao, int borda=0);

void main()
{
	botaoA0.pino = pin_a0;
	botaoA1.pino = pin_a1;


	while(1)
	{
		atualiza_dado(&dado);
		output_b(dado);
		delay_ms(30);
	}
}

// funcoes

int botao_pressionado(struct botao *botao, int borda)
{
	if(input(botao->pino) == borda)
	{
		botao->clicado = 1;
		botao->liberado = 0;
	}
	else
	{
		botao->liberado = 1;
	}

	if(botao->clicado && botao->liberado)
	{
		botao->clicado = botao->liberado = 0;
		return 1;
	}
	else
	{
		return 0;
	}
}

void atualiza_dado(int *valor)
{
	if(botao_pressionado(&botaoA0))
		{
			if(*valor < 255)
			{
				(*valor)++;
			}
			else
			{
				(*valor) = 255;
			}
		}
	else if(botao_pressionado(&botaoA1))
	{
		if(*valor > 0)
		{
			(*valor)--;
		}
		else
		{
			(*valor) = 0;
		}
	}
}