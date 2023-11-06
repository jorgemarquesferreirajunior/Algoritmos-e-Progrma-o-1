#include <stdio.h>


int main()
{
	int soma = 0;
	int numero, divisores;

	for (int i = 0; i <= 1000000; i++)
	{
		divisores = 0;
		numero = i;
		 while(numero > 0)
		 {
		 	if (i % numero == 0)
		 	{
		 		
		 		divisores ++;
		 		
			}
		 	
		 	numero--;
		 	
		 }
		 
		if (divisores == 2)
		{
			printf("Numero primo: %d \n", i);
			soma += i;	
		}
		
	}
	
	printf("Soma dos numeros primos: %d \n", soma);
	
	return 0;
}

