//***************************************Includes***************************************//
#include <delays.h>
#include "mascaras.c"

//****************************************pragma****************************************//
#pragma config FOSC		= HS
#pragma config PWRT 	= ON
#pragma config WDT 		= OFF
#pragma config MCLRE	= ON
#pragma config LVP 		= OFF

//--------------------------------mapeamento-de-hardware--------------------------------//
// entrada analogica BALANCA			PORTAbits.RA1
#define GIRO_MOTOR_TAMBOR_N1			PORTBbits.RB2
#define GIRO_MOTOR_TAMBOR_N2			PORTBbits.RB3
#define GIRO_MOTOR_COMPORTA_N1			PORTBbits.RB4
#define GIRO_MOTOR_COMPORTA_N2			PORTBbits.RB5
// interrupcao baixa prioridade			PORTBbits.RB7
#define SPRAY_PURIFICADOR				PORTCbits.RC0
// saida pwm motor comporta				PORTCbits.RC1
// saida pwm motor tambor				PORTCbits.RC2
#define LED_ON							PORTCbits.RC4
#define LED_MANUAL						PORTCbits.RC5
#define LED_AVISO						PORTCbits.RC6
#define FIM_CURSO_TB_RECUADO			PORTDbits.RD0
#define FIM_CURSO_TB_AVANCADO			PORTDbits.RD1
#define FIM_CURSO_GV_RECUADO			PORTDbits.RD2
#define FIM_CURSO_GV_AVANCADO			PORTDbits.RD3
#define velocidadePWM_Motor_Tambor		CCPR1L
#define velocidadePWM_Motor_Comporta	CCPR2L
//--------------------------------------diretivas--------------------------------------//
#define QTD_BTNS 		5
#define VARIACAO		5
//--------------------------------------variaveis--------------------------------------//

char 
	relogio[14] 					= "00h00min00sec",
	info_sprays_capacidade[4] 		= "000",
	info_sprays_utilizado[4] 		= "000",
	info_limpezas_realizadas[4]		= "000";
signed short
	flag_sprays						= 0;

unsigned char
	status[2] 						= {"ON ", "OFF"},
	estado_anterior_btn[QTD_BTNS]	= {0},
	flag_btn[QTD_BTNS] 				= {0},
	coluna 							= 0,
	linha 							= 0,
	cursor_visivel 					= 1,
	indice 							= 0,
	flag_manual						= 0,
	estado_btn,
	sair,
	conta_cursor 					= 0,
	j, k,
	secs 							= 0x26,
	new_secs 						= 0x00,
	mins 							= 0x3B,
	new_mins 						= 0x00,
	hours 							= 0x17,
	new_hours 						= 0x00,
	dias 							= 0x00,
	new_dias						= 0x00,
	tela_monitoramento				= 0x00;
	
unsigned short 
	VAN0,
	leitura_balanca 				= 0,
	sprays_capacidade 				= 3,
	sprays_utilizado 				= 0,
	novo_sprays_capacidade 			= 0,
	novo_sprays_utilizado 			= 0,
	limpezas_realizadas 			= 0,
	pwm_motor_tambor				= 80,
	new_pwm_motor_tambor,
	pwm_motor_comporta				= 50,
	new_pwm_motor_comporta;
	
unsigned short
	faixas[QTD_BTNS] 				= {767, 682, 512, 731, 614};// enter,left,up,right,down

enum {enter=0, left, up, right, down};

//****************************************testes****************************************//
unsigned short variavel_teste = 10;
unsigned char variavel_teste2 = 0;
