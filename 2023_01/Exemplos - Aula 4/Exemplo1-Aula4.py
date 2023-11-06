# verificando se um número é maior ou menor que zero
n = float(input('Escreva um número qualquer: '))
if n > 0:
    print(f'O número {n:.1f} é MAIOR que zero. ')
elif n < 0:
    print(f'O número {n:.1f} é MENOR que zero. ')
else:
    print(f'Digite um número DIFERENTE de {n:.2f} ')
