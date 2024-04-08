#include <p18f4550.h>
#include <delays.h>

#pragma config FOSC = HS
#pragma config WDT = OFF
#pragma config MCLRE = OFF

#define bt_mais		PORTBbits.RB0
#define bt_menos	PORTBbits.RB1


int estadoAnteriorBTMais = 1;
int estadoAnteriorBTMenos = 1;
int flag_bt_mais = 0;
int flag_bt_menos = 0;
int contador = 3;
int minimo = 0;
int maximo = 8;


void delay_ms(unsigned int tempo){
   while(tempo > 0){
      Delay100TCYx(10);
      tempo--;
      }
   }
   
void delay_bounce(){
   delay_ms(30);
   }
   
void ler_bt_mais(){
   if(bt_mais == 0 && !estadoAnteriorBTMais == 0){
      flag_bt_mais = 1;
   }
   estadoAnteriorBTMais = bt_mais;
}
  
void ler_bt_menos(){
   if(bt_menos == 0 && !estadoAnteriorBTMenos == 0){
      flag_bt_menos = 1;
   }
   estadoAnteriorBTMenos = bt_menos;
}

void atualiza_contador(){
   if (flag_bt_mais == 1){
      flag_bt_mais = 0;
      if (contador < maximo){
	 contador ++; 
      }
      else{
	 contador = maximo;
      }
   }
   
   if (flag_bt_menos == 1){
      flag_bt_menos = 0;
      if (contador > minimo ){
	 contador --; 
      }
      else{
	 contador = minimo;
      }
   }
}

void atualiza_leds(){
   switch(contador){
	case 0:
	 PORTD = 0b00000000;
	 break;
      case 1:
	 PORTD = 0b00000001;
	 break;
      case 2:
	 PORTD = 0b00000011;
	 break;
      case 3:
	 PORTD = 0b00000111;
	 break;
      case 4:
	 PORTD = 0b00001111;
	 break;
      case 5:
	 PORTD = 0b00011111;
	 break;
      case 6:
	 PORTD = 0b00111111;
	 break;
      case 7:
	 PORTD = 0b01111111;
	 break;
      case 8:
	 PORTD = 0b11111111;
	 break;
   }
}


void main(){ 
   PORTB = 0x00; LATB = 0x00; TRISB = 0x03;
   PORTD = 0x00; PORTD = 0x00; TRISD = 0x00;
   ADCON1 = 0x0F;
   PORTD = 0x0F;
   
   while (1){
      ler_bt_mais();
      ler_bt_menos();
      atualiza_contador();
      atualiza_leds();      
      delay_bounce();
   }
 }