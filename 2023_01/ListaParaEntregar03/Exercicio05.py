# Escreva um programa que solicite ao usuário uma sequência de números inteiros
# e determine qual é o maior número digitado. O programa deve continuar pedindo
# números até que o usuário digite um número negativo. Use um laço
maior = 0
while True:
    num = int(input("Digite um número: "))
    if num > maior:
        maior = num
    if num < 0:
        break
    print(f'O maior número é {maior}')
