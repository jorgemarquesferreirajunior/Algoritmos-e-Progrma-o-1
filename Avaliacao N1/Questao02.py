# Crie um algoritmo para um restaurante que receba o valor do consumo total da mesa, ovalor do couvert artístico
# e o número de pessoas a se dividir a conta. No final, deve calcular e mostrar ao usuário a taxa de serviço
# (10% sobre o consumo total), o valor total da conta da mesa e o valor por pessoa.
# Obs:
# cada pessoa deve pagar  seu couvert artístico
# a taxa de serviço deve ser dividida entre todas as pessoas que estão na mesa.
# Caso de teste sugerido
# total da mesa = 840
# couvert = 25
# pessoas = 6
# taxa de serviço = 84
# valor final total = 924
# valor por pessoa = 179


consumoDaMesa = float(input("Consumo total da mesa: R$ "))
couverArtistico = float(input("Valor do couvert artístico: R$ "))
numeroDePessoas = float(input("Número de pessoas a se dividir a conta: "))
taxaDeServico = consumoDaMesa * 0.1
totalConta = consumoDaMesa + taxaDeServico
totalPorPessoa = (taxaDeServico / numeroDePessoas) + couverArtistico + (consumoDaMesa / numeroDePessoas)
print(f"{':RESUMO:':=^40}")
print(f'taxa de serviço = R${taxaDeServico}')
print(f'total da mesa = R${totalConta}')
print(f'valor por pessoa = R${totalPorPessoa}')
print(f"{':FIM:':=^40}")
