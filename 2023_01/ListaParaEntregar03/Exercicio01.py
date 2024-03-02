# Leia uma variável N e, a seguir, mostre a tabuada de N:
# 1xN = N,
# 2xN = 2N,
# ..
# 10xN=10N
print('=-'*10, 'TABUADA', '=-'*10)

num = int(input("Qual tabuada você quer saber? "))

for c in range(0, 11):
    tabuada = num * c
    print(f" {num:2} X {c:2} = {tabuada:2}")

print("FIM")
