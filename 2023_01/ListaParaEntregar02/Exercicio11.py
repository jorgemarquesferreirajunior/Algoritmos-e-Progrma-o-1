# Um posto está vendendo combustíveis com a seguinte tabela de descontos:
# ○ Álcool:
# ✓ Até 20 litros, desconto de 3 % por litro.
# ✓ Acima de 20 litros, desconto de 5 % por litro.
# ○ Gasolina:
# ✓ até 15 litros, desconto de 3,5 % por litro.
# ✓ Acima de 15 litros, desconto de 6 % por litro
# Escreva um algoritmo que leia o número de litros vendidos, o tipo de combustível
# (codificado da seguinte forma: 1 - álcool; 2 - gasolina), o preço do litro do combustível,
# calcule e imprima o valor a ser pago pelo cliente
print('=-'*10, 'POSTO IPIRANGA', '=-'*10)
alc = 2.5
gas = 3
fuel_name = ''
tot = 0

qtd = float(input('Bom dia, quantos litros quer abastecer? '))
fuel = int(input('Álcool[1] ou Gasolina[2]? '))

if fuel != 1:
    if fuel != 2:
        print('ERRO: Digite apenas 1 ou 2 para a escolha do combustível.')
        fuel_name = "-"
if qtd == 0:
    print('Coloque uma quantidade de combustível acima de zero [0]')
    fuel_name = "-"
else:
    if fuel == 1:
        fuel_name = 'Álcool'
        if qtd <= 20:
            tot = qtd * (alc - (alc * (3 / 100)))
        else:
            tot = qtd * (alc - (alc * (5 / 100)))
    if fuel == 2:
        fuel_name = 'Gasolina'
        if qtd <= 15:
            tot = qtd * (gas - (gas * (3.5 / 100)))
        else:
            tot = qtd * (gas - (gas * (6 / 100)))
print('QTD. LITROS | COMBUSTÍVEL | TOTAL R$')
print(f'{qtd:^12}|{fuel_name:^13}| R${tot:^7}')







