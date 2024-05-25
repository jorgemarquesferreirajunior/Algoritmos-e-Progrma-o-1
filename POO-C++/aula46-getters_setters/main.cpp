#include<iostream>
#include "classes.h"

using namespace std;

int main()
{

    Veiculo *v1 = new Veiculo(1);
    Veiculo *v2 = new Veiculo(2);
    Veiculo *v3 = new Veiculo(3);

    v1->mostraInfo();

    v1->setLigado(1);
    v1->mostraInfo();

    v2->mostraInfo();

    v3->mostraInfo();


    return 0;
}
