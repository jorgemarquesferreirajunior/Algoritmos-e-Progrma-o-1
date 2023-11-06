# Construa um algoritmo que, dado o primeiro elemento e a razão de uma progressão aritmética (PA) [link], imprima todos
# os n primeiros elementos da PA, onde n também é informado pelo usuário. Lembre-se que uma PA pode ser crescente ou
# decrescente.
print(f'{" Progressão Aritmética Simples ":¨^50}')
first = int(input("Qual é o primeiro elemento da PA? "))
razao = int(input("E a razão? "))
qtd = int(input("Quantos números você quer ver dessa PA?  "))
print(f'Resultado :')
for c in range(0, qtd):
    if c < qtd - 1:
        print(first, end=" - ")
    else:
        print(f'{first}')
    first += razao
