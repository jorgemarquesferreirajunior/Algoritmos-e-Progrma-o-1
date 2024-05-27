#ifndef EQUIPAMENTO_H
#define EQUIPAMENTO_H


class Equipamento
{
    public:
        Equipamento();
        virtual ~Equipamento();

        // setters
        void setNome (const char *_nome);
        void setFabricante (const char *_fabricante);
        void setPreco (float _preco);

        // getters
        char* getNome (void);
        char* getFabricante (void);
        float getPreco(void);


    protected:
        float preco;

    private:
        char nome[100];
        char fabricante[100];
};

#endif // EQUIPAMENTO_H
