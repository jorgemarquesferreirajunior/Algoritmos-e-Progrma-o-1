//***************************************Includes***************************************//
#include <delays.h>
#include "mascaras.c"

//****************************************pragma****************************************//
#pragma config FOSC		= HS
#pragma config PWRT 	= ON
#pragma config WDT 		= OFF
#pragma config MCLRE	= OFF
#pragma config LVP 		= OFF
#pragma interrupt interrupcaoRelogio // Funcaoo de tratamento de interrupcoes - interrupcao

//--------------------------------mapeamento-de-hardware--------------------------------//
#define BALANCA						PORTAbits.RA1
#define GIRO_MOTOR_TAMBOR_N1		PORTBbits.RB2
#define GIRO_MOTOR_TAMBOR_N2		PORTBbits.RB3
#define FIM_CURSO_TB_SUPERIOR		PORTDbits.RD0
#define FIM_CURSO_TB_INFERIOR		PORTDbits.RD1
#define FIM_CURSO_GV_ABERTO			PORTDbits.RD2
#define FIM_CURSO_GV_FECHADO		PORTDbits.RD3
#define LED_ON						PORTDbits.RD4
#define velocidadePWM_Motor_Tambor	CCPR1L
//--------------------------------------diretivas--------------------------------------//
#define QTD_BTNS 		5
#define VARIACAO		5
//--------------------------------------variaveis--------------------------------------//

char 
	relogio[14] 					= "00h00min00sec",
	info_sprays_capacidade[4] 		= "000",
	info_sprays_utilizado[4] 		= "000";

unsigned char
	status[2] 						= {"ON", "OFF"},
	estado_anterior_btn[QTD_BTNS]	= {0},
	flag_btn[QTD_BTNS] 				= {0},
	coluna 							= 0,
	linha 							= 0,
	cursor_visivel 					= 1,
	indice 							= 0,
	estado_btn,
	sair,
	conta_cursor 					= 0,
	s			 					= 0,
	secs 							= 0x26,
	new_secs 						= 0x00,
	mins 							= 0x3B,
	new_mins 						= 0x00,
	hours 							= 0x17,
	new_hours 						= 0x00,
	dias 							= 0x00,
	new_dias						= 0x00;
	
unsigned short 
	VAN0,
	sprays_capacidade 				= 0,
	sprays_utilizado 				= 0,
	novo_sprays_capacidade,
	novo_sprays_utilizado,
	pwm_motor_tambor,
	new_pwm_motor_tambor,
	pwm_motor_comporta,
	new_pwm_motor_comporta;
	
unsigned short
	faixas[QTD_BTNS] 				= {767, 682, 512, 731, 614};// enter,left,up,right,down

enum {enter=0, left, up, right, down};

//****************************************testes****************************************//
unsigned short variavel_teste = 10;
unsigned char variavel_teste2 = 0;
