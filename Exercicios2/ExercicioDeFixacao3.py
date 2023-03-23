# As maçãs custam R$ 0,30 cada se forem compradas menos do que uma dúzia, e R$
# 0,25 se forem compradas pelo menos doze. Escreva um algoritmo que leia o número
# de maçãs compradas, calcule e escreva o valor total da compra.
print('=-'*10, 'FRUTEIRA BOA VENDA', '=-'*10)
print('PROMOÇÃO DO DIA: MAÇÃS \n Menos de 1 duzia = R$ 0,30/cada\n 1 duzia ou mais = R$ 0,25/cada')

qtd = int(input('Fala chefia, quantas maçãs você quer ? '))
price = [0.25, 0.30]
if qtd < 12:
    print(f'Certo, para {qtd} maçãs cobro R${price[1]:.2f}/cada. Total == R${qtd * price[1]:.2f}')
else:
    print(f'Certo, para {qtd} maçãs cobro R${price[0]:.2f}/cada. Total == R${qtd * price[0]:.2f}')
print('!!!VOLTE SEMPRE!!!')

