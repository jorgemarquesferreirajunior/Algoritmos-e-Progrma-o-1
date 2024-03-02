/*
j) Busca em orig por possíveis candidatos a endereços de e-mail.
 Copia em dest a primeira sequência de caracteres não brancos encontrada que
 contenha o caractere '@', ou uma string vazia caso contrário.
 Assuma que o vetor dest é grande o suficiente para conter a palavra encontrada.
Exemplo:
Para orig="Enviar mensagem para lucas@ig.com.br ou para outro moderador"
temos "lucas@ig.com.br" que ficará em dest.

void ProcuraEmail(char dest[], char orig[]);
 */

#include <stdio.h>
#include <string.h>


void ProcuraEmail(char dest[], char orig[]);
void CopiaSubString(char dest[], char orig[], int inic, int fim);

int main(){
    char str3[] = "Enviar mensagem para lucas@ig.com.br ou para outro moderador";
    char email[500];

    ProcuraEmail(email, str3);
    printf("Email: %s.\n",email);
    return 0;
}


/* função auxiliar */
void CopiaSubString(char dest[], char orig[], int inic, int fim){
    int i,j;
    j = 0;
    for(i = inic; i <= fim; i++){
        dest[j] = orig[i];
        j++;
    }
    dest[j] = '\0';
}

void ProcuraEmail(char dest[], char orig[]){
    int i,inic,fim;
    /* Procura índice do caractere '@'*/
    i = 0;
    while(orig[i] != '\0'){
        if(orig[i] == '@')
            break;
        i++;
    }
    /* Nenhum email encontrado */
    if(orig[i] == '\0'){
        dest[0] = '\0';
        return;
    }
    inic = fim = i;
    while(inic > 0){
        if(orig[inic-1] == ' ') break;
        inic--;
    }

    while(orig[fim+1] != ' ' && orig[fim+1] != '\0')
        fim++;
    CopiaSubString(dest, orig, inic, fim);
}
