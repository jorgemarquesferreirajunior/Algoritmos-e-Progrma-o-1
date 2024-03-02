#include <iostream>

using namespace std;

class Aviao{

public:
    int vel=12;
    int velMax;
    string tipoAviao;
    void ini(int tipo);
private:
    int cal=0;

};
//construindo a funcao ini
void Aviao::ini(int tipo){//1=jato,2==Monomotor,3=Planador
    if(tipo == 1){
        this->velMax = 800;
        this->tipoAviao = "Jato";
    }else if(tipo == 2){
        this->velMax = 350;
        this->tipoAviao = "Monomotor";
    }else if(tipo == 3){
        this->velMax = 180;
        this->tipoAviao = "Planador";
    }
}
int main(){

    Aviao *av1 = new Aviao();//Criando o objeto aviao - instanciando...
    Aviao *av2 = new Aviao();
    Aviao *av3 = new Aviao();
    av1->ini(1);
    av2->ini(2);
    av3->ini(3);
    cout << av1 -> velMax;//chamando o metodo vel atravez do comando -cout << nome do objeto -> atributo
    printf(" - ");
    cout << av1 -> tipoAviao;
    printf("\n");
    cout << av2 -> velMax;
    printf(" - ");
    cout << av2 -> tipoAviao;
    printf("\n");
    cout << av3 -> velMax;
    printf(" - ");
    cout << av3 -> tipoAviao;
    printf("\n");

return 0;
}
