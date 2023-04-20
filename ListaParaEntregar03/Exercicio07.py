# Um concurso público possui provas de Português (peso 2,5), Inglês (peso 2,5), Conhecimentos Específicos (peso 3),
# Legislação (peso 2). Escreva um programa em PORTUGOL que receba as notas (0 a 10) de um candidato em cada uma das
# provas e calcule e mostre:
# Média aritmética
# Média ponderada

boletim = {"Disciplina": "Português Inglês Conhecimentos_Epecíficos Legislação".split(), "Pesos": [2.5, 2.5, 3, 2]}
notas = []
soma_pesos = media_pon = media_ari = 0

for c in boletim["Disciplina"]:
    nota = input(f"Qual foi a sua nota na prova de {c} ? ")
    nota = float(nota)
    notas.append(nota)
boletim['Notas'] = notas

for i, x in enumerate(boletim['Notas']):
    media_ari += x
    media_pon += x * boletim["Pesos"][i]

print('-=' * 40)
for a in boletim["Pesos"]:
    soma_pesos += a

media_ari = media_ari / 4
media_pon = media_pon / soma_pesos

print(f'Média Aritmética: {media_ari:.1f}')
print(f'Média Ponderada: {media_pon:.1f}')
