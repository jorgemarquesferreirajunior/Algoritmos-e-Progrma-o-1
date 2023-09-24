#include <stdio.h>
#include <ctype.h>
#include<locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    char ch;

    printf("Digite um caractere qualquer [ex:j]: ");
    ch = getchar();

    if (isalpha(ch)) {
        printf("%c É uma letra.\n", ch);
    } else {
        printf("%c Não é uma letra.\n", ch);
    }

    if (isdigit(ch)) {
        printf("%c É um dígito.\n", ch);
    } else {
        printf("%c Não é um dígito.\n", ch);
    }

    if (islower(ch)) {
        printf("%c Está em minúsculas.\n", ch);
    } else {
        printf("%c Não está em minúsculas.\n", ch);
    }

    if (isupper(ch)) {
        printf("%c Está em maiúsculas.\n", ch);
    } else {
        printf("%c Não está em maiúsculas.\n", ch);
    }

    if (isspace(ch)) {
        printf("%c É um espaço em branco.\n", ch);
    } else {
        printf("%c Não é um espaço em branco.\n", ch);
    }

    return 0;
}
