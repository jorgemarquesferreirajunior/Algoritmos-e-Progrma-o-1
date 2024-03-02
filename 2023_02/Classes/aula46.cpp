#include <iostream>
#include "classes.h"

using namespace std;

int main(){

Veiculo *carro = new Veiculo(1);
Veiculo *aviao = new Veiculo(2);
Veiculo *navio = new Veiculo(3);

carro->getVelMax();
aviao->getVelMax();
navio->getVelMax();

navio->setLigado(1);

carro->imprimir();
aviao->imprimir();
navio->imprimir();
return 0;
}
