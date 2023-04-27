# Um Coronel dispõe seu batalhão de soldados conforme o triângulo a seguir:
# Escreva um programa que a partir de um número de soldados (valor lido), determine
# quantas filas se formarão e, se for o caso, quantos soldados restarão na fila incompleta.
# ---|---
# --|-|--
# -|-|-|-
# |-|-|-|

batalhao = int(input("Número de soldados: "))
linha = 0

while True:
    linha += 1  # incrementando uma linha a cada loop
    batalhao -= linha # subtraindo a quantidade de soldados para cada linha do total (batalhao)
    print(f"linha:{linha}")
    if batalhao <= linha:
        if batalhao != 0:
            print(f"Restante: {batalhao}")
        break
