# Escreva um algoritmo em que mostre quantos são os divisores de um dado número N
# informado pelo usuário.
print('=-'*10, 'DIVISORES DE UM NÚMERO', '=-'*10)

num = int(input("Escreva um número e lhe direi quantos divisores ele possui:  "))
divisores = 0

for c in range(1, num + 1):
    if num % c == 0:
        divisores += 1

print(f'O número {num} possui {divisores} divisores.')
