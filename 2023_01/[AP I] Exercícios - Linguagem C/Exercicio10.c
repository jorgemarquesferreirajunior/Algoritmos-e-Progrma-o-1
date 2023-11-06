//Escreva um programa C para um posto de gasolina, que calcule o valor final do
//abastecimento de um veículo. Sabendo que o litro da gasolina comum custa R$ 4,5
//e da gasolina aditivada custa R$ 4,65, o programa deve receber a quantidade de litros
//de gasolina, o tipo da gasolina (0 - comum; 1 - aditivada) e a forma de pagamento (2 - dinheiro; 3 - débito; 4 - crédito).
//# pagamento em dinheiro 15% de desconto
//# pagamento em débito 10% de desconto
//# pagamento em crédito 5% de desconto

#include<stdio.h>

int main()
{

    //gasosas
    float gas_comum = 4.5;
    float gas_aditi = 4.65;

    //descontos
    float desc_din = 0.15;
    float desc_deb = 0.1;
    float desc_cre = 0.05;

    //entradas
    int qtd_litros, tipo_gas, forma_pgto;

    //saidas
    float total;

    printf("\nOla, quantos litros voce quer abastecer? ");
    scanf("%d", &qtd_litros);
    printf("\n\nOk, gasolina comum (Digite 1) ou aditivada (Digite2)?\nResp:> ");
    scanf("%d", &tipo_gas);
    printf("\nForma de pagamento...\n3 - dinheiro\n4 - debito\n5 - credito\nResp:> ");
    scanf("%d", &forma_pgto);

    if (tipo_gas == 1)//gasolina comum
    {
        total = qtd_litros * gas_comum;
        if (forma_pgto == 3)//pagamento no dinheiro
        {
            printf("Voce abasteceu %d litros de gasolina comum ao preco de R$%.2f/litro\ntotalizando uma compra de R$%.2f.", qtd_litros, gas_comum, total);
            total = total - (total * desc_din);
            printf("\nPagando no dinheiro o total fica R$%.2f desc = %f", total, desc_din);
        }
        if (forma_pgto == 4)//pagamento no debito
        {
            printf("Voce abasteceu %d litros de gasolina comum ao preco de R$%.2f/litro\ntotalizando uma compra de R$%.2f.", qtd_litros, gas_comum, total);
            total = total - (total * desc_deb);
            printf("\nPagando no debito o total fica R$%.2f", total);
        }
        if (forma_pgto == 5)//pagamento no credito
        {
            printf("Voce abasteceu %d litros de gasolina comum ao preco de R$%.2f/litro\ntotalizando uma compra de R$%.2f.", qtd_litros, gas_comum, total);
            total = total - (total * desc_cre);
            printf("\nPagando no credito o total fica R$%.2f", total);
        }
    }
    else if (tipo_gas == 2)//gasolina aditivada
    {
        total = qtd_litros * gas_aditi;
        if (forma_pgto == 3)//pagamento no dinheiro
        {
            printf("Voce abasteceu %d litros de gasolina aditivada ao preco de R$%.2f/litro\ntotalizando uma compra de R$%.2f.", qtd_litros, gas_aditi, total);
            total = total - (total * desc_din);
            printf("\nPagando no dinheiro o total fica R$%.2f", total);
        }
        if (forma_pgto == 4)//pagamento no debito
        {
            printf("Voce abasteceu %d litros de gasolina aditivada ao preco de R$%.2f/litro\ntotalizando uma compra de R$%.2f.", qtd_litros, gas_aditi, total);
            total = total - (total * desc_deb);
            printf("\nPagando no debito o total fica R$%.2f", total);
        }
        if (forma_pgto == 5)//pagamento no credito
        {
            printf("Voce abasteceu %d litros de gasolina aditivada ao preco de R$%.2f/litro\ntotalizando uma compra de R$%.2f.", qtd_litros, gas_aditi, total);
            total = total - (total * desc_cre);
            printf("\nPagando no credito o total fica R$%.2f", total);
        }
    }

    return 0;
}