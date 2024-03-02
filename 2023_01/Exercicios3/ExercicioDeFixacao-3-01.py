# Escreva um algoritmo que efetue a soma de todos os números ímpares, que são múltiplos de 3
# e que estejam no conjunto de números de 1 até 500
soma = 0
for x in range(0, 1000000000000000):
    if x % 2 != 0:
        if x % 3 == 0:
            soma += x
print(soma)





