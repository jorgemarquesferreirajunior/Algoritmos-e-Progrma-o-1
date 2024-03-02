# Escrever um algoritmo que lê um conjunto de 4 valores i, a, b, c, onde i é um
# valor inteiro e positivo e a, b, c, são quaisquer valores reais e os escreva. A seguir:
# Se i=1 escrever os três valores a, b, c em ordem crescente.
# Se i=2 escrever os três valores a, b, c em ordem decrescente.
# Se i=3 escrever os três valores a, b, c de forma que o maior entre a, b, c fique dentre os dois.
def mostrarValores(lista, ordenacao):
    ordenacao = ordenacao.upper()
    print("-=" * 20)
    if ordenacao == "crescente".upper():
        print("Números em ordem crescente: ", end="")
    elif ordenacao == "decrescente".upper():
        print("Números em ordem decrescente: ", end="")
    else:
        print("Maior número no meio: ", end="")
    for valor in lista:
        print(valor, end=" ")
    print()
    print("-=" * 20)


bd = []
valores = ["i", "a", "b", "c"]
for c in range(0, 4):
    n = int(input(f"Digite um valor inteiro para {valores[c]}: "))
    bd.append(n)

bd_cresc = bd.copy()
bd_cresc.pop(0)
bd_decresc = bd.copy()
bd_decresc.pop(0)
bd_cresc.sort()
bd_decresc.sort(reverse=True)
bd_meio = [bd_cresc[0], bd_cresc[2], bd_cresc[1]]
if bd[0] == 1:
    mostrarValores(bd_cresc, ordenacao="crescente")
if bd[0] == 2:
    mostrarValores(bd_decresc, ordenacao="decrescente")
if bd[0] == 3:
    mostrarValores(bd_meio, ordenacao="central")
