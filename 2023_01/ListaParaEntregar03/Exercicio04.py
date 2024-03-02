# Construa um algoritmo que verifique se um número fornecido pelo usuário é primo ou não.
print('=-'*10, 'NÚMEROS PRIMOS', '=-'*10)

num = int(input("Digite um número: "))

cont = 0
for c in range(1, num + 1):
    if num % c == 0:
        print("\033[34m", end=" ")
        cont += 1
    else:
        print("\033[32m", end=" ")
    print(c, end=" ")
print(f"\n\033[m O número {num} é DIVISÍVEL {cont} vezes")
if cont == 2:
    print(f" Por tanto {num} É PRIMO")
else:
    print(f" Por tanto {num} NÃO É PRIMO")
