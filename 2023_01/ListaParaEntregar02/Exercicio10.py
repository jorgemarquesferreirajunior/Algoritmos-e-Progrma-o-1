# Escreva um algoritmo que leia as medidas dos lados de um triângulo e escreva se ele
# é EQUILÁTERO, ISÓSCELES ou ESCALENO.
# ○ triângulo equilátero: Possui os 3 lados iguais.
# ○ triângulo isósceles: Possui 2 lados iguais.
# ○ triângulo escaleno: Possui 3 lados diferentes
print('=-'*10, 'MEDIDAS DE UM TRIÂNGULO', '=-'*10)

print('Eai, vamos classicar esse seu triângulo...')

reta1 = float(input('Primeiro segmento: '))
reta2 = float(input('Segundo segmento: '))
reta3 = float(input('Terceiro segmento: '))

if reta1 < reta2 + reta3 and reta2 < reta1 + reta3 and reta3 < reta1 + reta2:
    print('Os segmentos acima formam um triângulo', end=' ')
    if reta1 == reta2 == reta3:
        print('EQUILÁTERO.')
    elif reta1 != reta2 != reta3:
        print('ESCALENO')
    else:
        print('ISÓSCELES.')
else:
    print('Os segmentos acima NÃO podem formar um triângulo')
