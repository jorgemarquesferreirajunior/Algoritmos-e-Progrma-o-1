# O TRE (Tribunal Regional Eleitoral) informatizou as eleições para prefeito. Escreva um
# programa que:
# a. Inicialmente leia o número de eleitores esperados para uma determinada
# seção eleitoral. Encerrado esse procedimento, inicia-se o processo de
# votação.
# b. Disponibilize uma tela ao eleitor onde deve ser lido o código do seu
# candidato: 1 - Fulano; 2 - Beltrano.
# c. A eleição só pode ser encerrada pelo presidente da seção. Isto é, a coleta dos
# votos deve ser repetida até que o valor código seja digitado. Para isso o
# presidente deverá digitar o valor -12345 como entrada para o código do
# candidato da tela anterior. O Presidente da seção deve confirmar o
# encerramento da seção através de senha (Considere a senha –35719).
# d. Após encerrada a eleição, o programa deve exibir na tela:
# ● O total de votos esperados na seção.
# ● Total e porcentagem de votos efetivamente “depositados” na urna
# eletrônica.
# ● Totalização de votos para cada um dos candidatos, bem como o total
# de votos nulos e brancos (considere a tabela de códigos dada a
# seguir).
# ● A porcentagem de abstenções.

tot_eleitor = candidato_1 = candidato_2 = candidato_3 = vt_branco = vt_nulo = vencedor = erros = 0
senha = -12345
senha_master = -35719
nomes_candidatos = ["Genézio", "Raimundo"]
print("Quantos eleitores você espera para essa seção? ")
tot_eleitor_esp = int(input('Resposta >: '))
print("Ok, vamos comecar a seção de votos...")
while True:
    print("-=" * 30)
    print(f'[1] Para o candidato - {nomes_candidatos[0]}\n[2] Para o candidato - {nomes_candidatos[1]}\n[3] '
          f'Para Voto em Branco\n[4] Para Voto Nulo')
    voto = int(input('Resposta >: '))
    if voto == senha:
        cancel = int(input("Digite a senha para encerrar a seção.\n>:"))
        if cancel == senha_master:
            print('Seção encerrada.')
            break
        else:
            print("Senha Inválida.")
            erros = 1
    if voto > 4 or voto < 1:
        if voto != senha:
            print("Selecione uma das opções entre 1 e 4")
    else:
        tot_eleitor += 1    # contabilizando o total de votos
        tot_eleitor -= erros
        print(f"[Eleitor n°{tot_eleitor}]")
        if voto == 1:
            candidato_1 += 1    # contabilizando votos do Genézio
        if voto == 2:
            candidato_2 += 1    # contabilizando votos do Raimundo
        if voto == 3:
            vt_branco += 1  # contabilizando votos em branco
        if voto == 4:
            vt_nulo += 1    # contabilizando votos nulos
        if tot_eleitor == tot_eleitor_esp:
            break

# print('\033[33m-=-=-=-=-=-FEEDBACK-=-=-=-=-=-\033[m')
print("\033[33mVotos Esperados | Votos Efetivados\033[m")
print(f"Total: {tot_eleitor_esp:^8} | Total: {tot_eleitor} = {((tot_eleitor * 100) / tot_eleitor_esp):.2f}%\n")
print('Candidato N°1 | Candidato N°2 |')
print(f"VOTOS:{candidato_1:^8} | {candidato_2:^8}")

print('\033[33m-=-=-=-=-=-=RESUMO=-=-=-=-=-=-\033[m')
if candidato_1 == candidato_2:
    print(f'Deu emmpate entre {nomes_candidatos[0]} e {nomes_candidatos[1]}')
if candidato_1 > candidato_2:
    print(f"Vencedor: Candicato N°1 - {nomes_candidatos[0]}")
if candidato_2 > candidato_1:
    print(f"Vencedor: Candicato N°2 - {nomes_candidatos[1]}")
print(f"Votos em Branco: {vt_branco}")
print(f"Votos Nulos: {vt_nulo}")
print(f"Quantidade de Eleitores: {tot_eleitor}")
abstencoes = vt_branco + vt_nulo
abstencoes = (abstencoes * 100) / tot_eleitor
print(f"Porcentagem de Abstenções: {abstencoes:.2f}%")
