#include "Vetor.h"
#include<iostream>
using namespace std;

Vetor::Vetor(){
  x = y = 0;
  cout << "Construtor padrao" << endl;
}

Vetor::Vetor(float _x, float _y){
  x = _x; y = _y;
  cout << "Construtor com argumentos" << endl;
}

Vetor::Vetor(const Vetor &_vetor){
  x = _vetor.x; y = _vetor.y;
  cout << "Construtor de copia" << endl;
}

Vetor::~Vetor(){
  cout << "Destrutor" << endl;
}

Vetor Vetor::soma(Vetor _vetor){
  Vetor _result;
  _result.x = x+_vetor.x;
  _result.y = y+_vetor.y;

  return _result;
}

// (3,4)
void Vetor::print(){
  cout << "(" << x << "," << y << ")" << endl;
}

float Vetor::produto(Vetor _vetor)
{
    return (x*_vetor.x) + (y*_vetor.y);
}
Vetor Vetor::produto(float escalar)
{
    return Vetor(x*escalar, y*escalar);
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

void Vetor::getInfo(void)
{
    std::cout << "(" <<  x << "," << y << ")";
}


