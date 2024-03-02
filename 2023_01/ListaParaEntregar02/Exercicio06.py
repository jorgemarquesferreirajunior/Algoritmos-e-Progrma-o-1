# Escreva um programa que peça ao usuário para digitar três números e determine
# qual é o maior. Em seguida, exiba o maior número na tela. Use estruturas
# condicionais aninhadas para comparar os números.
print('=-'*10, 'THE GIGGEST', '=-'*10)
a = float(input('Fala chefia, digite um número aí: '))
c = float(input('Mais um: '))
b = float(input('E agora o último: '))

if a > b:
    if a > c:
        print(f'O maior número é o {a:.2f}')
if b > a:
    if b > c:
        print(f'O maior número é o {b:.2f}')
if c > a:
    if c > b:
        print(f'O maior número é o {c:.2f}')
