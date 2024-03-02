# Escreva um programa que simule uma calculadora com as operações básicas de
# adição, subtração, multiplicação e divisão. O programa deve solicitar ao usuário qual
# operação ele deseja realizar e os valores a serem calculados. Em seguida, o programa
# deve exibir o resultado da operação escolhida. Use estruturas condicionais para
# implementar cada operação.
print('=-'*10, 'CALCULADORA', '=-'*10)
a = int(input(f'Qual operação você quer fazer? \n   [1]Adição\n   [2]Subtração\n   [3]Multiplicação\n   ['
              f'4]Divisão\nOperação Selecionada: '))

x = float(input('1° Número: '))
y = float(input('2° Número: '))

if a == 1:
    print(f"{x} + {y} = {(x + y):.2f}")
if a == 2:
    print(f"{x} - {y} = {(x - y):.2f}")
if a == 3:
    print(f"{x} * {y} = {(x * y):.2f}")
if a == 4:
    print(f"{x} / {y} = {(x / y):.2f}")

# a
