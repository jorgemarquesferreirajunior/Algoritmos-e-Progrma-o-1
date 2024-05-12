#ifndef RTC_H
#define RTC_H

// ================================================================= //
// BIBLIOTECA PARA CONTROLE DO MODULO RTC DS1307		             //
// ================================================================= //
#include <i2c.h>
#include "lcd_i2c.h"

#define DS1307W   0xD0  // Endereço i2c do RTC DS1307 e o operação de escrita
#define DS1307R   0xD1  // Endereço i2c do RTC DS1307 e o operação de leitura

// Variáveis globais
unsigned char SECONDS, MINUTES, HOURS, DAY_WEEK, DAY, MONTH, YEAR;

void StartRTC(void);
void ReadRTC(void);
void ShowRTCInfo(void);

// Rotina que inicializa o RTC
void StartRTC(void)
{
	IdleI2C();
	StartI2C();     		IdleI2C(); // Inicia comunicação I2C
	WriteI2C(DS1307W); 	IdleI2C(); // Define dispositivo e operação de escrita
	WriteI2C(0x00); 		IdleI2C(); // Define endereço inicial de escrita
	WriteI2C(0x00); 		IdleI2C(); // Escreve dado de segundos
	WriteI2C(0x19); 		IdleI2C(); // Escreve dado de minutos
	WriteI2C(0x16); 		IdleI2C(); // Escreve dado de horas
	WriteI2C(0x06); 		IdleI2C(); // Escreve dado do dia da semana
	WriteI2C(0x23); 		IdleI2C(); // Escreve dado do dia
	WriteI2C(0x10); 		IdleI2C(); // Escreve dado do mês
	WriteI2C(0x14); 		IdleI2C(); // Escreve dado do ano
	StopI2C();                 		 // Finaliza comunicação I2C
}

// Rotina que realiza a leitura do RTC
void ReadRTC(void)
{
	IdleI2C();
	StartI2C();           IdleI2C();                         // Inicia comunicação I2C
	WriteI2C(DS1307W);    IdleI2C();                         // Define dispositivo e operação de escrita
	WriteI2C(0x00);       IdleI2C();                         // Define endereço inicial para leitura
	RestartI2C();         IdleI2C();                         // Reinicia comunicação I2C
	WriteI2C(DS1307R);    IdleI2C();                      	 // Define dispositivo e operação de leitura
	SECONDS = ReadI2C();  IdleI2C(); AckI2C();    IdleI2C(); // Leitura dos segundos
	MINUTES = ReadI2C();  IdleI2C(); AckI2C();    IdleI2C(); // Leitura dos minutos
	HOURS = ReadI2C();    IdleI2C(); AckI2C();    IdleI2C(); // Leitura das horas
	DAY_WEEK = ReadI2C(); IdleI2C(); AckI2C();    IdleI2C(); // Leitura do dia da semana
	DAY = ReadI2C();      IdleI2C(); AckI2C();    IdleI2C(); // Leitura do dia
	MONTH = ReadI2C();    IdleI2C(); AckI2C();    IdleI2C(); // Leitura do mês
	YEAR = ReadI2C();     IdleI2C(); NotAckI2C(); IdleI2C(); // Leitura do ano
	StopI2C();                                               // Finaliza comunicação I2C
}

// Rotina que apresenta as informações de data e hora do RTC no display
void ShowRTCInfo(void)
{
	// Apresenta data e hora no display
	ControlLCDi2c(0x80);
	WriteLCDi2c((HOURS>>4)+0x30);
	WriteLCDi2c((HOURS & 0x0F)+0x30);
	WriteLCDi2c(':');
	WriteLCDi2c((MINUTES>>4)+0x30);
	WriteLCDi2c((MINUTES & 0x0F)+0x30);
	WriteLCDi2c(':');
	WriteLCDi2c((SECONDS>>4)+0x30);
	WriteLCDi2c((SECONDS & 0x0F)+0x30);
	ControlLCDi2c(0xC0);
	WriteLCDi2c((DAY>>4)+0x30);
	WriteLCDi2c((DAY & 0x0F)+0x30);
	WriteLCDi2c('/');
	WriteLCDi2c((MONTH>>4)+0x30);
	WriteLCDi2c((MONTH & 0x0F)+0x30);
	WriteLCDi2c('/');
	WriteLCDi2c('2');
	WriteLCDi2c('0');
	WriteLCDi2c((YEAR>>4)+0x30);
	WriteLCDi2c((YEAR & 0x0F)+0x30);
}

#endif //RTC_H