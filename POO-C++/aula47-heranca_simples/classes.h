#ifndef CLASSES_H_INCLUDED
#define CLASSES_H_INCLUDED

// classe pai
class Veiculo
{
public:
    short vel;
    short blind;
    short rodas;

    // metodos
    void setTipo(short _tipo);
    void setVelMax(short _vel_max);
    void setArma(bool _arma);
    void setNome(std::string _nome);

    short getTipo();
    short getVelMax();
    bool getArma();

    void info();

private:
    std::string nome;
    short tipo; // 1=Moto 2=Carro 3=Caminhao 4=Tanque
    short vel_max;
    bool arma;
};

void Veiculo::setTipo(short _tipo)
{
    tipo = _tipo;
}
void Veiculo::setVelMax(short _vel_max)
{
    vel_max = _vel_max;
}
void Veiculo::setArma(bool _arma)
{
    arma = _arma;
}

void Veiculo::setNome(std::string _nome)
{
    nome = _nome;
}

short Veiculo::getTipo()
{
    return tipo;
}
short Veiculo::getVelMax()
{
    return vel_max;
}
bool Veiculo::getArma()
{
    return arma;
}

void Veiculo::info()
{
    std::cout << "Nome do Veiculo.....: " << nome << std::endl;
    std::cout << "Tipo do Veiculo.....: ";
    switch(tipo)
    {
    case 1:
        std::cout << "Moto";
        break;
    case 2:
        std::cout << "Carro";
        break;
    case 3:
        std::cout << "Caminhao";
        break;
    case 4:
        std::cout << "Tanque";
        break;
    default:
        std::cout << "Indefinido";
        break;
    }
    std::cout << std::endl;
    std::cout << "Velocidade..........: " << vel << std::endl;
    std::cout << "Velocidade Maxima...: " << vel_max << std::endl;
    std::cout << "Nivel da Blindagem..: " << blind << std::endl;
    std::cout << "Numero de Rodas.....: " << rodas << std::endl;
    std::cout << "Armamento...........: " << arma << std::endl;
    std::cout << "----------------------------------" << std::endl;
}

// classe filho - que herda de outra clase
class Moto:public Veiculo
{
public:
    Moto(std::string nm);
};

// construtor da classe Moto
Moto::Moto(std::string nm)
{
    setNome(nm);
    vel = blind = 0;
    rodas = 2;
    setTipo(1);
    setVelMax(120);
    setArma(false);
}

class Carro:public Veiculo
{
public:
    Carro(std::string nm);
};

// construtor da classe Moto
Carro::Carro(std::string nm)
{
    setNome(nm);
    vel = 0;
    blind = 1;
    rodas = 2;
    setTipo(2);
    setVelMax(180);
    setArma(false);
}

class Caminhao:public Veiculo
{
public:
    Caminhao(std::string nm);
};

// construtor da classe Moto
Caminhao::Caminhao(std::string nm)
{
    setNome(nm);
    vel = 0;
    blind = 3;
    rodas = 6;
    setTipo(3);
    setVelMax(70);
    setArma(true);
}

class Tanque:public Veiculo
{
public:
    Tanque(std::string nm);
};

// construtor da classe Moto
Tanque::Tanque(std::string nm)
{
    setNome(nm);
    vel = 0;
    blind = 8;
    rodas = 12;
    setTipo(4);
    setVelMax(30);
    setArma(true);
}

#endif // CLASSES_H_INCLUDED
