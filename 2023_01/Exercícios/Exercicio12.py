# Faça um algoritmo para ler o salário de um funcionário e aumentá-lo em 15%.
# Após o aumento, desconte 8% de impostos. Imprima o salário inicial, o
# salário com o aumento e o salário final.
# Teste:
# salario = 5000
# salario_apos_aumento = 5750
# sala_apos_impostos = 5290
print('=-'*10, 'R.H.', '=-'*10)
print('Compadre, qual seu salário atual?')
salario = float(input(':> R$ '))
salario = salario * 1.15
print(f'Olha só, vou te dar um aumento de 15% ou seja, agora é R${salario:.2f}')
print('Mas como nem tudo são flores, vou descontar 8% de impostos...')
print(f"Ou seja, seu salário agora passa a ser {salario * 0.92:.2f}")
