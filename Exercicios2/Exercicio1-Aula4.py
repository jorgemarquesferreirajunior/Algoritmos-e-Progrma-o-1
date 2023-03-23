# Elaborar um algoritmo que efetue o cálculo do reajuste de salário de um funcionário.
# Considere que o funcionário deverá receber um reajuste de 15% se seu salário for
# menor ou igual a 5000. Caso contrário, seu reajuste será de 10%

salario = float(input("Qual o seu salário atual? R$"))
aumento = [10 / 100, 15 / 100]
salario_novo = 0
if salario >= 5000:
    salario_novo = salario + (salario * aumento[0])
    print(f'Como seu salário ataul é R${salario:.2f} seu aumento será de {aumento[0] * 100}% . Novo salário = R${salario_novo:.2f}')
else:
    salario_novo = salario + (salario * aumento[1])
    print(f'Como seu salário ataul é R${salario:.2f} seu aumento será de {aumento[1] * 100}% . Novo salário = R${salario_novo:.2f}')

