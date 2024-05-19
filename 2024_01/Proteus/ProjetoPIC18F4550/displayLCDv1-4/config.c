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
#define LED_BTN_LEFT 			PORTBbits.RB2 
#define LED_BTN_UP				PORTBbits.RB3 
#define LED_BTN_RIGHT 			PORTBbits.RB4 
#define LED_BTN_DOWN 			PORTBbits.RB5 
#define LED_BTN_ENTER 			PORTBbits.RB6
#define FIM_CURSO_TB_SUPERIOR	PORTDbits.RD0
#define FIM_CURSO_TB_INFERIOR	PORTDbits.RD1
#define FIM_CURSO_GV_ABERTO		PORTDbits.RD2
#define FIM_CURSO_GV_FECHADO	PORTDbits.RD3
#define LED_ON					PORTDbits.RD4

//--------------------------------------diretivas--------------------------------------//
#define QTD_BTNS 		5
#define VARIACAO		5
//--------------------------------------variaveis--------------------------------------//
unsigned char estado_anterior_btn[QTD_BTNS]	= {0}, flag_btn[QTD_BTNS] = {0}, coluna = 0, linha = 0, cursor_visivel = 1, indice = 0, estado_btn, sair, status[2] = {"ON", "OFF"};
unsigned short VAN0, sprays_capacidade = 500, sprays_utilizado = 18;
unsigned short faixas[QTD_BTNS] = {767, 682, 512, 731, 614};// enter,left,up,right,down
enum {enter=0, left, up, right, down};
char secs = 0x26, mins = 0x3B, hours = 0x17, dias = 0x00, relogio[14] = "00h00min00sec";
//****************************************testes****************************************//
unsigned short variavel_teste = 0;


