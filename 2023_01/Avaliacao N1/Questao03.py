# Crie um algoritmo que multiplique dois números sem utilizar o operador de multiplicação ( * ) e mostre o resultado.
# Os dois valores devem ser informados pelo usuário.
# Caso de uso sugerido
# 5 x 7 = 35




n1 = int(input("Digite o primeiro número: "))
n2 = int(input("E agora o segundo número: "))
resultado = 0
for x in range(0, n2):
    resultado += n1
print(f'\nResultado: {n1} X {n2} = {resultado}')

