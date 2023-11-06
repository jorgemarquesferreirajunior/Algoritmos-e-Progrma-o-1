# Escreva um algoritmo para ler 2 valores inteiros e escrever o maior deles. Se os dois
# números forem iguais, escreva uma mensagem indicando que os números são iguais.
print('=-'*10, 'MAGO DOS NÚMEROS', '=-'*10)
print('Escreva dois números...')
a = float(input('1°NÚMERO: '))
b = float(input('2°NÚMERO: '))
if a > b:
    print(f'O MAIOR número é {a}')
if a < b:
    print(f'O MAIOR número é {b}')
else:
    print('Os números são IGUAIS')
