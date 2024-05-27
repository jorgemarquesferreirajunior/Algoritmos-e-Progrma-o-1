#include "Vetor.h"
#include<iostream>

using namespace std;

/*
Vetor::Vetor()
{
    x = y = 0;
    cout << "construtor padrao" << endl;
}
*/

Vetor::Vetor(float _x, float _y)
{
    setX(_x);setY(_y);
    cout << "construtor com argumentos" << endl;
}

Vetor::~Vetor()
{
    cout << "destrutor padrao" << endl;
}

void Vetor::setX(float _x)
{
    x = _x;
}
void Vetor::setY(float _y)
{
    y = _y;
}

float Vetor::getX(void)
{
    return x;
}
float Vetor::getY(void)
{
    return y;
}
