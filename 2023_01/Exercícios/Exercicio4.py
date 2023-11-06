print('=-'*10, 'MÉDIA ARITMÉTICA', '=-'*10)
notas = list()
for c in range(0, 3):
    x = float(input(f'Qual o {c + 1}° valor? '))
    notas.append(x)
print(f'A média entre {notas[0]} {notas[1]} e {notas[2]} vale: {(notas[0] + notas[1] + notas[2]) / 3:.2f}')