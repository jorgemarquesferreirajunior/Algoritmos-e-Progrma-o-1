# Uma empresa de desenvolvimento de software cobra anuidades pelas licenças do seu sistema. Atualmente,
# esse valor é de R$ 20.000.00 por ano mas, devido a inflação, esse valor tem subido 4% a cada ano.
# a)Faça um programa que simule o valor dessa anualidade durante os próximos 10 anos;
# b)Modifique o programa anterior para que seja o usuário que informe qual é a taxa de inflação que deve ser
# aplicada a cada ano;
anuidade = 20000
inflação = 0.04
for x in range(0, 10):
    acrescimo = anuidade * inflação
    anuidade += acrescimo
    print(f'Valor da anuidade no {x + 1}° de inflação: R${anuidade:.2f}')
print('\nAgora vamos simular com outro valor de  inflação...\n')
anuidade = 20000
inflação2 = float(input("Qual a nova taxa de inflação? [%] "))
inflação2 /= 100
for x in range(0, 10):
    acrescimo = anuidade * inflação2
    anuidade += acrescimo
    print(f'Valor da anuidade no {x + 1}° de inflação: R${anuidade:.2f}')