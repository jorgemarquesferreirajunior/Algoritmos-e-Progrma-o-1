# Leia uma variável inteira até que o usuário informe um valor negativo para a mesma. Para cada valor lido
# mostre a sequência de 0 até este valor.

while True:
    n = int(input("Digite um número: "))
    if n < 0:
        break
    else:
        for c in range(0, n):
            print(f" {c} -> ", end="")
        print(n)
