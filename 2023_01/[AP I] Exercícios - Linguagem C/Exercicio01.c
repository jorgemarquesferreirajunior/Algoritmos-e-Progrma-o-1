//Escreva um programa em C que leia dois valores e mostre qual o maior. Se os dois
//números forem iguais, escreva uma mensagem indicando que os números são iguais.
#include <stdio.h>

int main()
{
	
	int x, y;
	
	printf("Digite um numero: \n");
	scanf("%d", &x);
	printf("Digite outro numero: \n");
	scanf("%d", &y);
	
	if (x > y)
	{
		printf("O maior numero vale %d", x);
	}
	
	else if (x == y)
	{
		printf("Os numeros sao iguais");
	}
	
	else
	{
		printf("O maior numero vale %d", y);
	}
	
	return 0;
}










