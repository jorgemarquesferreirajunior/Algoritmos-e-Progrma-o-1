#include<stdio.h>

int main()
{
    int lado1, lado2, lado3;
    printf("Lado1: ");
    scanf("%d", &lado1);
    printf("\nLado2: ");
    scanf("%d", &lado2);
    printf("\nLado3: ");
    scanf("%d", &lado3);
if ((lado1 + lado2) < lado3 || (lado1 + lado3) < lado2 || (lado2 + lado3) < lado1)
{
    printf("\nAs medidas dos lados 1, 2 e 3 não formam um triângulo");
}
else
{
    if (lado1 !=  lado2 && lado1 != lado3 && lado2 != lado3)
    {
        printf("\nE um triangulo Escaleno");
    }

    else if (lado1 == lado2 && lado1 == lado3 && lado2 == lado3 )
    {
        printf("\nE um triangulo Equilatero");
    }

    else
    
    {
        printf("\nE um triangulo Isosceles.");
    }
    
}

return 0;
}