#include <iostream>
#include "Motor.h"

using namespace std;

int main()
{

    Motor porche;

    porche.setFabricante("VolksWagen");
    porche.setNome("Refrigerado a Ar");
    porche.setPotencia(1600);
    porche.setPreco(2540.45);
    porche.setVelocidade(135);

    cout <<
        "Fabricante: " << porche.getFabricante() << endl <<
        "Nome......: " << porche.getNome() << endl <<
        "Potencia..: " << porche.getPotencia() << endl <<
        "Preco.....: " << porche.getPreco() << endl <<
        "Velocidade: " << porche.getVelocidade() << endl;

    return 0;
}
