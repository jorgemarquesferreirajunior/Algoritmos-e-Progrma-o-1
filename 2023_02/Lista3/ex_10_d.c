/*
d) Escreva uma função que apague todos os # de um vetor c[0..n-1] de caracteres ASCII.
Exemplo: Se n vale 7 e o vetor contém   a b c # # d #   então o resultado deve ser   a b c d .
*/
#include <stdio.h>
#include <stdlib.h>
//#include <locale.h>
#include <time.h>

#include <string.h>

int main () {
   int val;
   char str[100];
   char str_n[100] = "";
   char vazio[10] = "";

    printf("Digite uma palavra que contenha #: ");
    //scanf("%s", &str);
    scanf("%[^\n]", &str);
    fflush(stdin);

    printf("%s\n", str);
    printf("%s\n", str_n);

    for(int i = 0; i < strlen(str); i++){
        if((int)str[i] != 35){
            //printf("%c\n", str[i]);
            strcpy(vazio, str[i]);
            strcat(str_n,vazio);
        }
    }
    printf("str_n: %s \n",str_n);
   /*
   int i = 0;
   while (str[i] != '\0') {

        if((int)str[i] == 35){
            strcat(str_n,str_n);

        }else{
            strcat(str_n,str[i]);
        }
        i++;
        printf("%s\n", str_n);
   }
   */

   return(0);
}
