#include <stdio.h>
#include<locale.h>

typedef struct {
    int day, month, year;
}data;

data novaData(data date);
int ehAnoBissexto(int ano);

int main() {
    data periodo, new_periodo;
    char dados[11];

    printf("Digite uma data qualquer (DD/MM/AAAA)");
    scanf("%s", dados);
    sscanf(dados, "%2d/%2d/%4d", &periodo.day, &periodo.month, &periodo.year);
    printf("Data inserida: %.2d/%.2d/%.4d\n", periodo.day, periodo.month, periodo.year);
    new_periodo = novaData(periodo);
    printf("Data seguinte: %.2d/%.2d/%.4d\n", new_periodo.day, new_periodo.month, new_periodo.year);

    return 0;
}

data novaData(data date){
    int fimDoMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    data new_date = date;

    if (date.month == 12 && date.day == 31) {//se for 31 de dezembro...
        new_date.year++;
        new_date.month = 1;
        new_date.day = 1;
    } else if (date.month == 2 && date.day == fimDoMes[date.month - 1] && ehAnoBissexto(date.year) == 1) {//se for 28/fev e ano bissexto
        new_date.day ++;
    } else if (date.day == fimDoMes[date.month - 1]) {// se for ultimo dia do mes exceto dezembro
        new_date.month++;
        new_date.day = 1;
    }
    else {//qualquer outra data, soma o dia apenas
        new_date.day++;
    }

    return new_date;
}

int ehAnoBissexto(int ano) {
    size_t bissexto = 0;//bissexto = 1, nao bissexto = 0;
    if(ano % 4 == 0){
        if(ano % 100 != 0){
            bissexto = 1;
        } else if(ano % 100 == 0 && ano % 400 == 0){
            bissexto = 1;
        }
    }
    return bissexto;
}
