#include <iostream>

using namespace std;

// Passagem por valor: altera apenas a variável interna x
void func(int x)
{
    cout << "x (dentro de func, antes)= " << x << endl;
    x = 4;
    cout << "x (dentro de func, depois)= " << x << endl;
}

// Passagem por ponteiro: altera a variável original usando o endereço
void func_p(int *x)
{
    cout << "x (dentro de func_p, antes)= " << *x << endl;
    *x = 4;
    cout << "x (dentro de func_p, depois)= " << *x << endl;
}

// Passagem por referência: altera a variável original diretamente
void func_r(int &x)
{
    cout << "x (dentro de func_r, antes)= " << x << endl;
    x = 4;
    cout << "x (dentro de func_r, depois)= " << x << endl;
}

int main()
{
    int y = 3;
    cout << "y (antes da chamada de funcao)= " << y << endl;

    // Chame uma das funções para ver o efeito
    // func(y);      // Passagem por valor
    // func_p(&y);   // Passagem por ponteiro
    func_r(y);     // Passagem por referência

    cout << "y (depois da chamada de funcao)= " << y << endl;
    return 0;
}
