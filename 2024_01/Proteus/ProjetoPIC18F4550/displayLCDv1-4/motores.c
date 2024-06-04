#include "analogico.c"

void giraTambor(unsigned char n1, unsigned char n2);
void InverteGiroTambor(void);
void giraComporta(unsigned char n1, unsigned char n2);
void InverteGiroComporta(void);
void initMotores(void);
char posicaoTambor(void);
char posicaoComporta(void);
void clicoLimpeza(void);
void LedAviso(void);
unsigned char StatusMotorTambor(void);
unsigned char StatusMotorComporta(void);
void AtualizaMotores(void);

void giraTambor(unsigned char n1, unsigned char n2)
{
	GIRO_MOTOR_TAMBOR_N1 = n1;
	GIRO_MOTOR_TAMBOR_N2 = n2;
}

void InverteGiroTambor(void)
{
	GIRO_MOTOR_TAMBOR_N1 = !GIRO_MOTOR_TAMBOR_N1;
	GIRO_MOTOR_TAMBOR_N2 = !GIRO_MOTOR_TAMBOR_N2;
}
void giraComporta(unsigned char n1, unsigned char n2)
{
	GIRO_MOTOR_COMPORTA_N1 = n1;
	GIRO_MOTOR_COMPORTA_N2 = n2;
}
void InverteGiroComporta(void)
{
	GIRO_MOTOR_COMPORTA_N1 = !GIRO_MOTOR_COMPORTA_N1;
	GIRO_MOTOR_COMPORTA_N2 = !GIRO_MOTOR_COMPORTA_N2;
}
void initMotores(void)
{
	if (posicaoTambor() < 1 )// tambor no meio ou no fim
	{
		while(posicaoTambor() != 1)
		{
			giraTambor(1,0); // move tambor para o inicio
			AtualizaMotores();
		}	
		giraTambor(0,0);AtualizaMotores();
	}
	
	if (posicaoComporta() < 1)// comporta no meio ou aberta
	{
		while(posicaoComporta() != 1)
		{
			giraComporta(1,0); // fecha comporta
			AtualizaMotores();
		}
		giraComporta(0,0);AtualizaMotores();
	}	
	
}
char posicaoTambor(void)
{
	if (FIM_CURSO_TB_RECUADO && !FIM_CURSO_TB_AVANCADO) 		return 1; // tambor no incio
	else if (!FIM_CURSO_TB_RECUADO && !FIM_CURSO_TB_AVANCADO) 	return -1; // tambor no meio
	else if (!FIM_CURSO_TB_RECUADO && FIM_CURSO_TB_AVANCADO)	return 0; // tambor no fim
	
}
char posicaoComporta(void)
{
	if (FIM_CURSO_GV_RECUADO && !FIM_CURSO_GV_AVANCADO)			return 1; // comporta fechada
	else if (!FIM_CURSO_GV_RECUADO && !FIM_CURSO_GV_AVANCADO) 	return -1; // comporta no meio
	else if (!FIM_CURSO_GV_RECUADO && FIM_CURSO_GV_AVANCADO) 	return 0; // comporta aberta
	
}
void clicoLimpeza(void)
{
	unsigned char pausa;	
	velocidadePWM_Motor_Tambor		= pwm_motor_tambor;
	velocidadePWM_Motor_Comporta	= pwm_motor_comporta;
	
	initMotores();
	pausa = secs;

	while ((secs - pausa) < 4);
	
	// abre comporta 
	while(posicaoComporta() != 0) // comporta nao aberta
	{
		giraComporta(0,1); // abre comporta
		AtualizaMotores();
	}
	giraComporta(0,0);AtualizaMotores();
	
	// gira tambor para o fim
	while(posicaoTambor() != 0) // tambor para o fim
	{
		giraTambor(0,1); // gira tambor para ate o final
		AtualizaMotores();
	}	
	giraTambor(0,0);AtualizaMotores();
	
	// aciona o purificador de ar e atualiza contador
	SPRAY_PURIFICADOR = 1;
	
	// espera areia cair
	pausa = secs;
	while ((secs - pausa) < 4);
	SPRAY_PURIFICADOR = 0;
	
	// retorna ao inicio
	initMotores();
	AtualizaMotores();
	sprays_utilizado++;
	novo_sprays_utilizado++;
	limpezas_realizadas++;
}
void LedAviso(void)
{
	leitura_balanca = lerAnalogico(1);
	flag_sprays = sprays_utilizado - sprays_capacidade;
	if (flag_sprays < -1 && leitura_balanca < 500) LED_AVISO = 0;
	else if (flag_sprays >=0 || leitura_balanca > 700 ) LED_AVISO = 1;
	else LED_AVISO = !LED_AVISO;
}

unsigned char StatusMotorTambor(void)
{
	if (!GIRO_MOTOR_TAMBOR_N1 && !GIRO_MOTOR_TAMBOR_N2)	return 0;
	return 1;
}
unsigned char StatusMotorComporta(void)
{
	if (!GIRO_MOTOR_COMPORTA_N1 && !GIRO_MOTOR_COMPORTA_N2)	return 0;
	else return 1;
}
void AtualizaMotores(void)
{
	if (tela_monitoramento == 1)
	{
		
		if (StatusMotorTambor())
		{
			setCursorLCD_i2c(0,12);
			printStringLCD_i2c("ON ");
		}	
		else 
		{
			setCursorLCD_i2c(0,12);
			printStringLCD_i2c("OFF");
		}	
		
		
		if (StatusMotorComporta())
		{
			setCursorLCD_i2c(1,12);
			printStringLCD_i2c("ON ");
		}	
		else 
		{
			setCursorLCD_i2c(1,12);
			printStringLCD_i2c("OFF");
		}
	}
}

