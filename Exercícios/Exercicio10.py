# Um motorista deseja colocar no tanque do seu carro x reais de gasolina.
# Escreva um algoritmo para ler do usuário o preço do litro da gasolina
# (tipo real) e o valor total do pagamento, e exibir quantos litros ele
# conseguiu colocar no tanque.
# 	Teste:
# preco_litro = 4.7 , total = 100
# = 21,27

print('=-'*10, 'POSTO IPÍRANGA', '=-'*10)
preco_litro = 4.7
print('Fala chefia, quantos reais de gasosa vai querer por no possante?')
money = float(input(':> '))
print(f'OK, veja bem, a queridinha está custando {preco_litro:.2f} / LITRO.')
print(f'Então calculando de cabeça.... R${money} = {money / preco_litro:.2f} Litro(s) de gasosa.')
print('\n Ahh, não esquece da minha grojeta né!! Valeu querido, abraço')