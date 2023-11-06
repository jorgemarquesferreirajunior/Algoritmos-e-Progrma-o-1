# Tendo como entrada a altura e o sexo (codificado da seguinte forma: 1:feminino
# 2:masculino) de uma pessoa, construa um algoritmo que calcule e imprima seu peso
# ideal, utilizando as seguintes fórmulas:
# ○ para homens: (72.7 * h)-58
# ○ para mulheres: (62.1*h)-44.7
print('=-'*10, 'TRAÇADOR DE ALTURA', '=-'*10)
altura = float(input('Qual sua altura? '))
sexo = int(input('Qual seu sexo?[feminino=1][masculino=2] '))
if sexo == 1:
    print(f'Seu peso ideal deve ser: {(62.1 * altura) - 44.7:.2f}KG')
else:
    print(f'Seu peso ideal deve ser: {(72.7 * altura) - 58:.2f}KG')
