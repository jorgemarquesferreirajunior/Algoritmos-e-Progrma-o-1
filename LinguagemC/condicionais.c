#include <stdio.h>

int main(){
	
	float x;
	
	printf("Digite um numero: \n");
	scanf("%f", &x);
	printf("Voce digitou o numero %.2f \n", x);
	
	if (x > 0){
		
		printf("numero maior que zero \n");
		
	} else if (x < 0){
		
		printf("Numero menor que zero \n");
		
	}else{
		
		printf("Digite um numeo diferente de zero \n");
	}
	
	return 0;
}
