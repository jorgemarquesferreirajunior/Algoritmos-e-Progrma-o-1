# Na eleição para coordenação de curso, existem 3 candidatos. Os votantes podem digitar 1, 2 ou 3 para escolher um
# dos candidatos; 4 para votar em branco; 5 para votar nulo. A votação se encerra quando o fiscal digitar 0 (zero).
#  Escreva um algoritmo que mostre
# O número do candidato vencedor;
# O número de votos em branco;
# O número de votos nulos;
# O número de eleitores que compareceram às urnas.
tot_eleitor = candidato_1 = candidato_2 = candidato_3 = vt_branco = vt_nulo = vencedor = 0
while True:
    print("-=" * 40)
    print('\n* [1] Candidato N°1 * [2] Candidato N°2 * [3] Candidato N°3 * [4] Voto em Branco * [5] Voto Nulo')
    voto = int(input('Selecione uma das opções anteriores: '))
    if voto == 0:
        break
    if voto > 5:
        print("Selecione uma das opções entre 1 e 5")
    else:
        tot_eleitor += 1
        print(f"Eleitor n°{tot_eleitor}")
        if voto == 1:
            candidato_1 += 1
        if voto == 2:
            candidato_2 += 1
        if voto == 3:
            candidato_3 += 1
        if voto == 4:
            vt_branco += 1
        if voto == 5:
            vt_nulo += 1
        if 0 < voto < 4:
            if candidato_1 > candidato_2:
                if candidato_1 > candidato_3:
                    vencedor = 1
            if candidato_2 > candidato_1:
                if candidato_2 > candidato_3:
                    vencedor = 2
            if candidato_3 > candidato_1:
                if candidato_3 > candidato_2:
                    vencedor = 3
print('-=-=-=-=-FEEDBACK-=-=-=-=-')
print('\n      Candidato N°1 | Candidato N°2 | Candidato N°3')
print(f"VOTOS:{candidato_1:^13} | {candidato_2:^13} | {candidato_3:^13}")
print('-=-=-=-=-RESUMO-=-=-=-=-')
if vencedor == 0 and vt_nulo == 0 and vt_branco == 0:
    print('Não houveram eleitores')
else:
    if vencedor == 0:
        print('Nenhum candidato foi votado.')
    if candidato_1 == candidato_2:
        print(f'Deu emmpate entre o candidato N°{candidato_1} e o candidato N°{candidato_2}')
    if candidato_1 == candidato_3:
        print(f'Deu emmpate entre o candidato N°{candidato_1} e o candidato N°{candidato_3}')
    if candidato_2 == candidato_3:
        print(f'Deu emmpate entre o candidato N°{candidato_2} e o candidato N°{candidato_3}')
    else:
        print(f"Vencedor: Candicato N°{vencedor}")
    print(f"Votos em Branco: {vt_branco}")
    print(f"Votos Nulos: {vt_nulo}")
    print(f"Quantidade de Eleitores: {tot_eleitor}")
