# Escreva um algoritmo que verifique a validade de uma senha (literal) fornecida pelo
# usuário. A senha válida é o literal “1234”. Deve ser impresso as seguintes mensagens:
# ○ ACESSO PERMITIDO caso a senha seja válida.
# ○ ACESSO NEGADO caso a senha seja inválida.
print('=-'*10, 'VALIDADOR DE SENHA', '=-'*10)
password = "1234"
s = str(input('DIGITE A SENHA DE ACESSO: ')).strip()[:4]
if s == "1234":
    print('ACESSO \033[32mPERMITIDO\033[m')
else:
    print('ACESSO \033[31mNEGADO\033[m')




