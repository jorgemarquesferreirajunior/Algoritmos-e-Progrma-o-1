# Escreva um algoritmo para ler as 4 notas obtidas por um aluno em 4 avaliações.
# Calcular a média usando a seguinte fórmula:
#
#           media = (n1 + n2*2 + n3*3 + n4) / 7
#
# A seguir imprima a média e o conceito do aluno baseado na seguinte relação:
#   ○ 9,0 ou acima de 9,0 -> Conceito A
#   ○ entre 7,5 (inclusive) e 9,0 -> Conceito B
#   ○ entre 6,0 (inclusive) e 7,5 -> Conceito C
#   ○ abaixo de 6,0 -> Conceito D
print('=-'*10, 'BOLETIM ESCOLAR', '=-'*10)
print('Eai brow, vamos calcular sua média de notas...')
print('Dados:   [Nota1 -> Peso 1.0] [Nota2 -> Peso 2.0] [Nota3 -> Peso 3.0] [Nota4 -> Peso 1.0]')

notas = list()

for c in range(0, 4):
    n = float(input(f'Diz a tua {c + 1}° nota: '))
    notas.append(n)

media = (notas[0] + (notas[1] * 2) + (notas[2] * 3) + notas[3]) / 7
print(f'Média | Conceito \n {media:.1f}', end="       ")
if media >= 9:
    print('A')
if 7.5 <= media < 9:
    print('B')
if 6 <= media < 7.5:
    print('C')
if media < 6:
    print('D')
