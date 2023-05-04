# Escreva um programa que leia uma sequência de números inteiros  informados pelo usuário e verifique se a lista está
# em ordem crescente. Retorne uma mensagem informando Sim ou Não. O programa deve encerrar quando o usuário digitar 0
# (ZERO).
lista = []
while True:
    n = int(input("Digite um número: "))
    if n == 0:
        break
    else:
        lista.append(n)
listaOrdenada = lista.copy()
listaOrdenada.sort()

if lista == listaOrdenada:
    print('Sim - A lista está ordenada.')
else:
    print('Não - A lista está desordenada.')
