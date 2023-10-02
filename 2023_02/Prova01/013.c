#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void apostaPlacar(int x, int y, int *placar, int *resultado);

int main() {
    int placar[2] = {3, 2};
    int gols_time_x, gols_time_y;
    int resultado = 0;

    while(resultado != 25){
        printf("Digite o placar de um jogo qualquer [ex: 2 3]: ");
        scanf("%d %d", &gols_time_x, &gols_time_y);fflush(stdin);
        apostaPlacar(gols_time_x, gols_time_y, placar, &resultado);
        printf("Placar final: %d - %d\nResultado: %d\n", placar[0], placar[1], resultado);
    }
    return 0;
}

void apostaPlacar(int x, int y, int *placar, int *resultado) {
    if(x != placar[0] && y != placar[1] && x < y){
        // nao acertou vencedor, nem perdedor, nem numero de gosl
        *resultado = 0;
    }else if (x < placar[0] && y == placar[1]) {
        // nao acertou vencedor, mas acertou o n° de gols do segundo time
        *resultado = 5;
    } else if (x == placar[0] && y > placar[1]) {
        // nao acertou vencedor, mas acertou o n° de gols do primeiro time
        *resultado = 5;
    } else if (x != placar[0] && y != placar[1] && x > y) {
        // Acertou o acertou vencedor, mas acertou o n° de gols dos times
        *resultado = 10;
    } else if (x == placar[0] && y < placar[1]) {
        // Acertou o time vencedor, mas errou n° de gols do segundo time
        *resultado = 15;
    }else if (x == placar[0] && y == placar[1]) {
        // acertou tudo
        *resultado = 25;
    }
}
