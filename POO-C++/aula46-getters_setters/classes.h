#ifndef CLASSES_H_INCLUDED
#define CLASSES_H_INCLUDED

class Veiculo{
private:
    std::string nome;
    int vel_max;
    bool ligado;

    // incializar a variavel privada vel_max
    void setVelMax(int valor);
public:
    int vel;
    int tipo;
    //metodo construtor
    Veiculo(int tp);

    // obter o valor da variavel privada vel_max
    int getVelMax();
    bool getLigado();

    // incializar a variavel privada ligado
    void setLigado(int valor);

    // mostra info sobre veiculo
    void mostraInfo();
};

Veiculo::Veiculo(int tp)
{
    switch(tp)
    {
    case 1:
        nome = "Carro";
        setVelMax(200);
        setLigado(0);
        break;
    case 2:
        nome = "Aviao";
        setVelMax(800);
        setLigado(0);
        break;
    case 3:
        nome = "Navio";
        setVelMax(120);
        setLigado(0);
        break;
    }
}

void Veiculo::setVelMax(int valor)
{
    vel_max = valor;
}

void Veiculo::setLigado(int valor)
{
    if (valor == 1) ligado = true;
    else ligado = false;
}

int Veiculo::getVelMax()
{
    return vel_max;
}

bool Veiculo::getLigado()
{
    return ligado;
}

void Veiculo::mostraInfo()
{
    std::cout << "Veiculo: " << nome << std::endl;
    std::cout << "Vel_max: " << getVelMax() << std::endl;
    if (getLigado()) std::cout << "Status.: ligado" << std::endl;
    else std::cout << "Status.: desligado" << std::endl;
    std::cout << "------------------------------" << std::endl;
}

#endif // CLASSES_H_INCLUDED
