# Escreva um programa que simule um caixa eletrônico. O programa deve solicitar ao
# usuário o valor a ser sacado e verificar se o valor é um número múltiplo de 10 e se há
# saldo suficiente na conta. Se as duas condições forem atendidas, o programa deve
# exibir uma mensagem informando que o saque foi realizado com sucesso. Caso
# contrário, o programa deve exibir uma mensagem informando o erro.
print('=-'*10, 'CAIXA ELETRÔNICO', '=-'*10)
a = float(input('Bom dia, quanto voceê quer sacar hoje? R$ '))
if a % 10 == 0:
    print('[multiplo de 10 - ok]')
    if a < 10000:
        print('Saque realizado com sucesso!')
    else:
        print('SALDO INSUFICIENTE')
else:
    print('ERRO:Saque apenas valores multiplos de 10')



