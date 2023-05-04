# Um motorista deseja calcular a despesa de uma viagem de carro. Escreva um algoritmo que atenda este objetivo,
# sendo que o usuário deve informar a distância, o valor total dos pedágios no trajeto, a média de consumo de
# combustível (km/l ) do carro , e  preço do combustível.
#
# O algoritmo deve mostrar o custo da viagem, considerando ida e volta
# Exemplo:
# distância = R$ 279
# pedágios = R$ 28
# média consumo = 15 km/l
# combustível = R$ 7,00 por litro
# Custo Total = R$ 316,00



print(f"{'Despesas de Viagem':=^40}")

distanciaPercorrida = float(input("Distância entre início e fim [Km]: "))
pedagios = float(input("Total a pagar em pedágios: R$ "))
mediaConsumo = float(input("Qual a média de consumo do seu carro? [Km/l]"))
precoCombustivel = float(input("Qual o preço do litro de combústivel? R$ "))

custoTotal = (((distanciaPercorrida / mediaConsumo) * precoCombustivel) + pedagios) * 2
print(f"{':Resumo:':%^40}")
print(f'distância = {distanciaPercorrida}Km | Ida e Volta = {distanciaPercorrida * 2}Km')
print(f'pedágios = R${pedagios}')
print(f'média consumo = {mediaConsumo} km/l')
print(f'Custo Total = R${custoTotal:.2f}')
print(f"{':FIM:':%^40}")


