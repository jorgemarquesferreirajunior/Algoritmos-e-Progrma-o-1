# Crie um programa que permita ao usuário escolher entre três opções diferentes:
# calcular o fatorial de um número, calcular a soma dos n primeiros números naturais, ou sair do programa.
# Utilize uma estrutura condicional para determinar qual opção o usuário escolheu e uma estrutura de repetição
# para permitir que o usuário faça várias escolhas.
opcao = int(input('Eai brow, oque você quer fazer?\n[1] Calcular FATORIAL\n[2] Calcular a soma dos N primeiros números '
      'naturais\n[3] SAIR do programa\nResposta: '))
fat = 1
if opcao == 1:
    print("-=-=-=-=-FATORIAL-=-=-=-=-")
    x = int(input("Digite um número: "))
    if x == 0 or x == 1:
        fat = 1
    if x > 1:
        for r in range(1, x + 1):
            pass
        # fazer calculo do fatorial...