#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>

/*
b) Elabore um algoritmo que calcule o que deve ser pago por um produto, considerando
o preço normal de etiqueta e a escolha da condição de pagamento. Utilize os códigos da
tabela a seguir para ler qual a condição de pagamento escolhida e efetuar o cálculo adequado.
Código Condição de pagamento  1 À vista em dinheiro ou cheque, recebe 10% de desconto
2 À vista no cartão de crédito, recebe 15% de desconto
3 Em duas vezes, preço normal de etiqueta sem juros
4 Em duas vezes, preço normal de etiqueta mais juros de 10%
*/

int main()
{
    setlocale(LC_ALL, "Portuguese");
    float preco_etiqueta;
    int opcao;
    char payment[5][200] = {""};
    strcpy(payment[1],"[1]À vista em dinheiro ou cheque, recebe 10% de desconto" );
    strcpy(payment[2],"[2]À vista no cartão de crédito, recebe 15% de desconto" );
    strcpy(payment[3],"[3]Em duas vezes, preço normal de etiqueta sem juros" );
    strcpy(payment[4],"[4]Em duas vezes, preço normal de etiqueta mais juros de 10%" );

    printf("Qual o preço da etiqueta? R$");
    scanf("%f", &preco_etiqueta);

    do
    {
    printf("Escolha uma forma de pagamento:\n%s\n%s\n%s\n%s\nResp.>: ",payment[1],payment[2],payment[3],payment[4]);
    scanf("%d", &opcao);
    }while(opcao > 4 || opcao < 1);

    printf("Opção escolhida: %s\n\n", payment[opcao]);
    switch(opcao)
    {
    case(1):
        printf("Pagamento: Total R$ %.2f\n ", preco_etiqueta * 0.9);
        break;
    case(2):
        printf("Pagamento: Total R$ %.2f\n", preco_etiqueta * 0.85);
        break;
    case(3):
        printf("Pagamento em duas vezes de: R$%.2f Total R$%.2f\n", preco_etiqueta / 2, preco_etiqueta);
        break;
    case(4):
        printf("Pagamento em duas vezes de: R$ %.2f\ Total R$%.2f\n", (preco_etiqueta * 1.1) / 2,preco_etiqueta * 1.1);
        break;
    }

    system("pause");
    return 0;
}
