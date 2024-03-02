# Escreva um algoritmo que mostra para o usuário quais são os números entre 1000 e 2000
# que quando divididos por 11, dão resto igual a 5.
x = 1000
while x <= 2000:
    if x % 11 == 5:
        print(x)
    x += 1


