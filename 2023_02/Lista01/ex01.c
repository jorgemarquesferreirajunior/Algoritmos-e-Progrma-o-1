#include<stdio.h>

int main(void){
unsigned char u, v, w;
u = 255; v = 2;
w = u + v;

printf ("%d\n", w);
printf("%c", w);
/*
Cada caractere possui uma correspondência numérica a partir da tabela ASC, assim quando criamos a char w 
a partir de u e v, estamos na verdado gerando um novo caractere, que nesse caso, é um emogi feliz.
No primeiro print vemos a correspondencia numérica(inteiro - tipo int) da variavel w,
e no segundo print vemos o caractere da tabela ASC que corresponde ao valor inteiro presente na varialvel w 

*/
return 0;
}
