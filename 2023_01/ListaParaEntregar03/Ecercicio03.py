# Escreva um programa que solicite ao usuário um número inteiro e imprima
# todos os números pares entre 0 e o número digitado.
print('=-'*10, 'NÚMEROS PARES', '=-'*10)


num = int(input("Escreva um número:  "))

print(f'Esses são os números pares de 0 até {num}:')
for c in range(0, num + 1):
    if c % 2 == 0:
        print(f' {c} ', end="")












