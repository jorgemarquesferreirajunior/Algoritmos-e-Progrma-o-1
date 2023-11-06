print('=-'*10, 'GERENCIADOR DE VENDAS', '=-'*10)
s = 10
m = 12
b = 15

print('Bora calcular suas vendas...')
ss = int(input('Quantas camisetas pequenas você vendeu? '))
mm = int(input('Quantas medias? '))
bb = int(input('E quantas grandes? '))
print(f'Bicho, você fez uma venda de R${(s * ss) + (m * mm) + (b * bb):.2f} PARABÉNS!')
