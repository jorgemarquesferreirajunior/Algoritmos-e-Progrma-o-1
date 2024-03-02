# Um banco concederá um crédito especial aos seus clientes, variável com o saldo
# médio no último ano. Faça um algoritmo que leia o saldo médio de um cliente e
# calcule o valor do crédito de acordo com a tabela abaixo. Mostre uma mensagem
# informando o saldo médio e o valor do crédito.
# de 000 a 200 : nenhum crédito
# de 201 a 400 : 20% do valor do saldo médio.
# de 401 a 600 : 30% do valor do saldo médio.
# acima de 601 : 40% do valor do saldo médio.
saldo = float(input("Qual seu saldo médio? R$"))
print(f"{'Tabela de Crédito':=^50}")
print("\nde 000 a 200 : nenhum crédito\nde 201 a 400 : 20% do valor do saldo médio.\nde 401 a 600 : 30% do valor do saldo médio.\nacima de 601 : 40% "
      "do valor do saldo médio.")
print("=" * 50)
print("RESULTADO: ", end="")

if 0 < saldo <= 200:
    print("Nenhum crédito.")
elif 200 < saldo <= 400:
    print(f"Crédito disponível de R${saldo * 0.2}")
elif 400 < saldo <= 600:
    print(f"Crédito disponível de R${saldo * 0.3}")
else:
    print(f"Créditodisponível de R${saldo * 0.4}")
