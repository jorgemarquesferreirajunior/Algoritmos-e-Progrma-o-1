#ifndef MOTOR_H
#define MOTOR_H

#include "Equipamento.h"


class Motor : public Equipamento
{
    public:
        Motor();
        virtual ~Motor();

        // setters
        void setVelocidade (float _velocidade);
        void setPotencia (float _potencia);
        // getters
        float getVelocidade (void);
        float getPotencia (void);

    private:
        float velocidade, potencia;
};

#endif // MOTOR_H
