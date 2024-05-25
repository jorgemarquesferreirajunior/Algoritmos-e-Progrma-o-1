#include<iostream>
#include "classes.h"
using namespace std;

int main()
{
    Moto *cg        = new Moto("CG-125");
    Carro *uno      = new Carro("UNO FIRE");
    Caminhao *cargo = new Caminhao("CARGO 4565");
    Tanque *tanque  = new Tanque("T-5000");

    cg->info();
    uno->info();
    cargo->info();
    tanque->info();

    return 0;
}
