#include "analogico.c"

void giraTambor(unsigned char n1, unsigned char n2);
void InverteGiroTambor(void);
void giraComporta(unsigned char n1, unsigned char n2);
void InverteGiroComporta(void);
void initMotores(void);
char posicaoTambor(void);
char posicaoComporta(void);

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
		}	
		giraTambor(0,0);
	}
	
	if (posicaoComporta() < 1)// comporta no meio ou aberta
	{
		while(posicaoComporta() != 1)
		{
			giraComporta(1,0); // fecha comporta
		}
		giraComporta(0,0);
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
