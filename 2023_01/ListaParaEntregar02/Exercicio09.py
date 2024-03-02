# Elabore um algoritmo que, dada a idade de um nadador (caso o usuário informe um
# valor negativo ou maior que vinte, deve ser mostrada uma mensagem informando o
# seu erro), classifique-o em uma das seguintes categorias:
# ○ Não aceito: 0 a 4 anos
# ○ Infantil: 5 a 10 anos
# ○ Juvenil: 11 a 17 anos
# ○ Adulto: 18 a 20 anos
print('=-'*10, 'YOUR AGE PLEASE', '=-'*10)
a = int(input('Eai atleta, qual sua idade? '))
if a < 0:
    print('ERRO: Idades negativas não existem! Comece de novo.')
elif a > 20:
    print('Idade acima de 20 anos - Infelizmente você está fora de categoria.')
else:
    if 0 <= a <= 4:
        print('Atleta Não aceito: 0 a 4 anos')
    else:
        print('Voce está classificado na categoria: ', end="")
        if 4 < a <= 10:
            print('Infantil')
        if 10 < a <= 17:
            print('Juvenil')
        if 17 < a <= 20:
            print('Adulto')

