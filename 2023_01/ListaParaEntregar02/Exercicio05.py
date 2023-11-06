# Escreva um algoritmo para ler um número inteiro (considere que serão lidos apenas
# valores positivos e inteiros) e escrever se é par ou ímpar
print('=-'*10, 'PAR OU ÍMPAR', '=-'*10)
a = int(input('Digite um número qualquer inteiro e positivo: '))
if a % 2 == 0:
    print(f'Bem, o número {a} é PAR')
else:
    print(f'Olha só, o numero {a} é ÍMPAR')
