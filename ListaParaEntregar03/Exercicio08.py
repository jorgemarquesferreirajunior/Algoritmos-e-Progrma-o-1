# Imprima uma tabela de conversão de polegadas para centímetros, de 1 a 20.
# Considere que Polegada = Centímetro * 2,54.
print('TABELA cm -> in')
inc = 2.54
for x in range(1, 21):
    y = x * inc
    print(f"{x:^2} inch == {y:.2f} cm")
    