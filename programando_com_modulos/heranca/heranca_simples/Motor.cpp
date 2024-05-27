#include "Motor.h"

Motor::Motor()
{
    //ctor
}

Motor::~Motor()
{
    //dtor
}

// setters
void Motor::setVelocidade (float _velocidade)
{
    velocidade = _velocidade;
}
void Motor::setPotencia (float _potencia)
{
    potencia = _potencia;
}
// getters
float Motor::getVelocidade (void)
{
    return velocidade;
}
float Motor::getPotencia (void)
{
    return potencia;
}
