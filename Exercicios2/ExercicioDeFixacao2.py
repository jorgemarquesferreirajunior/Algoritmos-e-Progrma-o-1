# Escreva um algoritmo para ler o ano de nascimento de uma pessoa e escrever uma
# mensagem que diga se ela poderá ou não votar nas eleições deste ano (não é
# necessário considerar o mês em que ela nasceu).
print('=-'*10, 'ELEIÇÃO DA DEPRESSÃO', '=-'*10)
hj = 2023
nasc = int(input('Você nasceu em que ano ? '))
idade = hj - nasc
print(idade)
if idade < 16:
    print(f'Com {idade} anos você ainda não pode votar ...')
elif 16 <= idade < 18:
    print(f'Com {idade} anos você já pode votar ...')
elif 16 <= idade < 70:
    print(f'Se liga! com {idade} anos, seu voto é obrigatório!')
else:
    print(f'Com  {idade} anos você já não precisa mais votar se não quiser.')


