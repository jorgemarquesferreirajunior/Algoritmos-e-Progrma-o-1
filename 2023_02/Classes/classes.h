#ifndef CLASSES_H_INCLUDED
#define CLASSES_H_INCLUDED
#include <locale.h>

class Veiculo{

public:
    int tipo;
    int vel;
    Veiculo(int tp);
    int getVelMax();
    bool getLigado();
    void imprimir();
    void setLigado(int estado);

private:
    int setVelMax(int vm);
    std::string nome;
    int velMax;
    bool ligado;
};

bool Veiculo::getLigado(){
    return ligado;
}

void Veiculo::setLigado(int estado){
    switch(estado){
        case 1:
            ligado = true;
            break;
        case 0:
            ligado = false;
            break;
    }
}
Veiculo::Veiculo(int tp){
    switch(tp){
        case 1:
            nome = "Carro";
            //velMax = 200;
            setVelMax(200);
            setLigado(0);
            break;
        case 2:
            nome = "Aviao";
            //velMax = 800;
            setVelMax(800);
            setLigado(0);
            break;
        case 3:
            nome = "Navio";
            //velMax = 120;
            setVelMax(120);
            setLigado(0);
            break;
    }
}

Veiculo::getVelMax(){
    return velMax;
}

Veiculo::setVelMax(int vm){
    velMax = vm;
}

void Veiculo::imprimir(){
    setlocale(LC_ALL, "Portuguese");
    std::cout << "Nome................:" << nome << std::endl;
    std::cout << "Velocidade máxima...:" << velMax << std::endl;
    if(ligado == true){
        std::cout << "Motor...............:Ligado " << ligado <<  std::endl;
    }else{
        std::cout << "Motor...............:Desigado " << ligado << std::endl;
    }
    printf("\n");

}
#endif // CLASSES_H_INCLUDED
