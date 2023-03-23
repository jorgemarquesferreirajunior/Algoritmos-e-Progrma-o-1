# Boletim escolar

n1 = float(input('Nota 1: '))
n2 = float(input('Nota 2: '))
media = (n1 + n2) / 2
print('--------MÉDIA MÍNIMA PARA PASSAR: 7 --------')
print(f'Sua média foi {media}')
if media >= 7:
    print('Você está APROVADO !')
else:
    print('Você REPROVOU !')
