# Construa um algoritmo que leia valores do usuário até que seja digitado um valor negativo.
# Este algoritmo deve calcular a média de valores PARES e ÍMPARES, que serão digitados pelo usuário.
# Ao final, o algoritmo deve mostrar estas duas médias. O algoritmo deve mostrar também
# o maior número PAR digitado e o menor número ÍMPAR digitado.
med_par = med_impar = qtd_par = qtd_impar = sum_par = sum_impar = cont_i = cont_p = 0
while True:
    num = int(input("Digite um número: "))
    if num < 0:
        break

    if num % 2 == 0:
        sum_par += num
        if cont_p == 0:
            maior = num
            cont_p += 1
        if num != 0:
            qtd_par += 1

        if num > maior:
            maior = num

    if num % 2 != 0:
        sum_impar += num
        qtd_impar += 1
        if cont_i == 0:
            menor = num
            cont_i += 1

        if num < menor:
            menor = num

if qtd_par > 0:
    print('-=-=- Números pares -=-=-')
    print(f'{"MÉDIA":^8} | {"MAIOR N° PAR":^15} ')
    print(f"  {(sum_par / qtd_par):.2f}   {maior:^15}")
if qtd_impar > 0:
    print('-=-=- Números ímpares -=-=-')
    print(f'{"MÉDIA":^8} | {"MENOR N° ÍMPAR":^15} ')
    print(f"  {(sum_impar / qtd_impar):.2f}   {menor:^15}")
