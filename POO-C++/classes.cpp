#include<iostream>
#include<string>

using namespace std;

class Aviao
{
    public:
        // propriedades
        int velocidade = 0;
        int velocidade_maxima;
        string tipo;
        //metodos (prototipos)
        void ini(int tipo);
    private:

};

// funcoes
void Aviao::ini(int tipo) //implementar a inicializacao da velocidade maxima conforme o tipo do aviao
{
    switch (tipo)
    {
        case 1:
            this->velocidade_maxima = 800;
            this->tipo = "Jato";
            break;
        case 2:
            this->velocidade_maxima = 350;
            this->tipo = "Monomotor";
            break;
        case 3:
            this->velocidade_maxima = 180;
            this->tipo = "Planador";
            break;
        default:
            break;
    }
    
}


int main(int argc, char const **argv)
{ 
    Aviao *av1 = new Aviao(); // instanciando a classe
    Aviao *av2 = new Aviao(); // instanciando a classe
    Aviao *av3 = new Aviao(); // instanciando a classe

    av1->ini(1); // incializando as variaveis tipo e velocidade_maxima
    av2->ini(2); // incializando as variaveis tipo e velocidade_maxima
    av3->ini(3); // incializando as variaveis tipo e velocidade_maxima

    cout << av1->tipo << "\t" << av1->velocidade_maxima << endl << endl;
    cout << av2->tipo << "\t"<< av2->velocidade_maxima << endl << endl;
    cout << av3->tipo << "\t"<< av3->velocidade_maxima << endl << endl;

    return 0;
}
