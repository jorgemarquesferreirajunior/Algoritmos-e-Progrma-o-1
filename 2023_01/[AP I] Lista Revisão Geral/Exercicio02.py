# Fulano comprou um saco de ração com peso em quilos. Ele possui dois cachorros,
# para os quais fornece a quantidade de ração em gramas. A quantidade diária de ração fornecida
# para cada cachorro é sempre a mesma. Faça um programa que receba o peso do saco de ração e a
# quantidade de ração fornecida para cada cachorro (em gramas), e calcule e mostre quanto restará
# de ração no saco após cinco dias (em gramas).
peso = float(input("Quantos Kg de ração você comprou? "))
racao1 = float(input("Quantas gramas de ração você dá para o 1° cachorro? "))
racao2 = float(input("Quantas gramas de ração você dá para o 2° cachorro? "))
resto = (peso * 1000) - ((racao1 + racao2) * 5)
print(f"Em 5 dias, os cachorros comerão juntos {(racao1 + racao2) * 5} gramas de ração. Ou seja: ", end="")
if resto < 0:
    print(f"Faltarão {resto:.0f} gramas de ração para alimentar os cachorros durante 5 dias.")
else:
    print(f"Restarão {resto:.0f} gramas de ração.")
    