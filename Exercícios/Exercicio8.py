print('=-'*10, 'CONVERSOR DE MOEDAS', '=-'*10)
print('\033[1:31m OBS: \033[m \033[31m Não esqueça que voce deve trocar a vírgula pelo ponto ex: 1.75\033[m')
print('')
print('DADOS>')
print('Cotação do dólar em 16/03  = 5.27 reais')
print('Cotação do euro em 16/03 = 5.59 reais')
print()
dolar = 5.27
euro = 5.59
real = float(input('Bora lá campeão, quanto de dinheiro você tem ai? R$ '))
print(f'Bem, seus R${real} valem US${real / dolar:.2f} e €{real / euro:.2f}')
