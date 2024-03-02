/*
g) Escreva uma função que receba um número natural n e devolva a string ASCII
de 0s e 1s que represente n em notação binária.

 Por exemplo, o número 123 deve ser convertido na string “1111011".
 */

#include<stdio.h>
#include<string.h>
#include<math.h>

int decToBin(long n) {
    int dec = 0, i = 0, rem;

    while (n != 0) {
        rem = n % 10;
        n /= 10;
        dec += rem * pow(2, i);
        ++i;
    }
    return dec;
}

int binToDec(char bin[100]) {
    unsigned long dec = 0;
    int i = 0;
    int s;

    s = strlen( bin );
    while( s-- ) {
        if (bin[s] == '0' || bin[s] == '1') {
            dec = dec + pow(2, i++) * (bin[s] - '0');
        }
    }
    return dec;
}

int main()
{
    int dec;
    unsigned long bin;

    printf("Informe um número decimal:");
    scanf("%li", &bin);
    dec = decToBin(bin);
    printf("\nEquivalente em binário: \t %u\n", dec);
    return 0;
}
