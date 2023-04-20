# Escreva um programa que simule um jogo de adivinhação em que o usuário deve adivinhar um número gerado aleatoriamente.
# O programa deve solicitar ao usuário que tente adivinhar o número e informar se o número digitado é maior ou menor do
# que o número gerado pelo programa. O jogo deve continuar até que o usuário acerte o número.

from random import randint
print('Pensei em um número entre 0 e 10. Tente advinhar se for capaz')
numero = randint(0, 10)
while True:
    chute = int(input('Palpite: '))
    if chute == numero:
        print('Parabéns, você acertou!')
        break
    if chute > numero:
        print('Vishhhh, pensei num bem menor')
    if chute < numero:
        print(f'Hahaha, você só sabe contar até {chute} ?')
