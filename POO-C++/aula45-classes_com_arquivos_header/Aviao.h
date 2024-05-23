#ifndef AVIAO_H_INCLUDED
#define AVIAO_H_INCLUDED

class Aviao
{
private:
public:
    int velocidade_atual = 0;
    int velocidade_maxima;
    std::string tipo;

    //Metodo construtor
    Aviao(int tp);

    //metodos auxiliares
    void info();
};

//Metodo Construtor - executado automaticamente ao instanciar a classe
Aviao::Aviao(int tp)
{
    switch(tp)
    {
    case 1:
        tipo = "Jato";
        velocidade_maxima = 800;
        break;
    case 2:
        tipo = "Monomotor";
        velocidade_maxima = 350;
        break;
    case 3:
        tipo = "Planador";
        velocidade_maxima = 180;
        break;
    }
}

// metodos auxiliares
void Aviao::info()
{
    std::cout << "Tipo de Aviao.....: " << tipo << std::endl;
    std::cout << "Velocidade Maxima.: " << velocidade_maxima << std::endl;
    std::cout << "Velocidade Atual..: " << velocidade_atual << std::endl << std::endl;
}

#endif // AVIAO_H_INCLUDED
