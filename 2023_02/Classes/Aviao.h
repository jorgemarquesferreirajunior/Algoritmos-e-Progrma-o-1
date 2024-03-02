#ifndef AVIAO_H_INCLUDED
#define AVIAO_H_INCLUDED
#include <locale.h>

class Aviao{
public:
    int vel = 0;
    int velMax;
    std::string tipoAviao;
    Aviao(int tp);

    void imprimir();

    private:

};

Aviao::Aviao(int tp){
    switch(tp){
        case 1:
            velMax = 800;
            tipoAviao = "Jato";
            break;
        case 2:
            velMax = 350;
            tipoAviao = "Monomotor";
            break;
        case 3:
            velMax = 180;
            tipoAviao = "Planador";
            break;
    }

}
void Aviao::imprimir(){
    setlocale(LC_ALL, "Portuguese");
    std::cout << "Tipo................: " << tipoAviao << std::endl;
    std::cout << "Velocidade máxima...: " << velMax << std::endl;
    std::cout << "Velocidade atual....: " << vel << std::endl;
    printf("\n");
}
#endif // AVIAO_H_INCLUDED
