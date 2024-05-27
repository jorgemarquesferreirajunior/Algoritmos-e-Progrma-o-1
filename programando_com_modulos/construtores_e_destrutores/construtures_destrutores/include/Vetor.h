#ifndef VETOR_H
#define VETOR_H


class Vetor
{
    public:
        // metodo construtor default(padrao) - mesmo nome da classe
        //Vetor();

        // metodo construtor com argumentos
        /* ao predefinir _x e _y podemos instanciar a classe sem precisar indicar os valores iniciais de x e y
        desse modo o construtor padrao pode ser substituido pelo construtor abaixo...*/
        Vetor(float _x=0, float _y=0);

        // metodo destrutor
        ~Vetor();

        // outros metodos
        void setX(float _x);
        void setY(float _y);
        float getX(void);
        float getY(void);
    private:
        float x, y;
};

#endif // VETOR_H
