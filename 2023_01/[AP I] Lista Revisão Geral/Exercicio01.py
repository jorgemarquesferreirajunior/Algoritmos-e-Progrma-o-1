# Construir um programa que leia três valores numéricos inteiros (representados
# pelas variáveis A, B e C) e apresente como resultado final o valor do quadrado
# da soma dos três valores lidos.
valores = ["A", "B", "C"]
numeros  = []
for c in range(0, 3):
    n = int(input(f"Digite um número para {valores[c]}: "))
    numeros.append(n)

print(f"({numeros[0]} + {numeros[1]} + {numeros[2]})² = ({sum(numeros)})²= {sum(numeros) * sum(numeros)}")

