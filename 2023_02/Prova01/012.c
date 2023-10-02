#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void apostaPlacar(int x, int y, int *placar, int resultado);

int main() {
    int placar[2] = {3, 2};
    int gols_time_x, gols_time_y;
    int resultado = 0;
    printf("Digite o placar de um jogo qualquer[ex: 2 3]: ");
    scanf("%d %d", &gols_time_x, &gols_time_y);

    apostaPlacar(gols_time_x, gols_time_y, placar, resultado);

    printf("Placar final: %d - %d\nResultado: %d\n", placar[0], placar[1], resultado);

    return 0;
}

void apostaPlacar(int x, int y, int *placar, int resultado) {
    if(x == placar[0] && y == placar[1]){// linha 6
    }else if(x == placar[0] && y != placar[1] && y < x){// linha 5
        resultado = 15;
    }else if(x == placar[0] && y != placar[1] && y > x){// linha 3
        resultado = 5;
    }else if(x != placar[0] && y != placar[1] && y < x){// linha 4
        resultado = 10;
    }else if(x != placar[0] && y != placar[1] && y > x){// linha 1
        resultado = 0;
    }else if(x != placar[0] && y == placar[1] && y > x){// linha 2
        resultado = 5;
    }

}
