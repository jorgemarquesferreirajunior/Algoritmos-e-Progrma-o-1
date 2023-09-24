#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<string.h>

int encaixa(int x, int y);
int main(){
    int a, b;

    setlocale(LC_ALL, "Portuguese");
    printf("Digite dois valores inteiros positivos: ");
    scanf("%d %d", &a, &b);
    int result = encaixa(a, b);
    if (result == 1){
        printf("\n%d Encaixa em %d\n", b, a);
    }else{
        printf("\n%d Não encaixa em %d\n", b, a);
    }

    return 0;
}

int encaixa(int x, int y){
    char x_str[20], y_str[20];

    sprintf(x_str, "%d", x);
    sprintf(y_str, "%d", y);
    int len_xy = strlen(x_str) - strlen(y_str);

    if(len_xy < 0){
        return 0;
    }else if(len_xy == 0){
        for(int i = 0; i < strlen(y_str); i++){
            if(x_str[i] != y_str[i]){
                return 0;
            }
        }
    }
    else{
        for(int i = 0; i < strlen(y_str); i++){
            if(x_str[i + len_xy] != y_str[i]){
                return 0;
            }
        }
    }
    return 1;
}









