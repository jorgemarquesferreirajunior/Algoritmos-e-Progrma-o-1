
int main(void){

unsigned char u;

for (u = 0; u < 256; ++u)
    {
        printf(".");
    }

char c;

for (c = 0; c < 128; ++c)
    {
        printf(".");
    }

/*
Nesse código nunca sairemos da primeira ou da seguda estrutura de repetição, como nunca sairemos da primeira, nunca alcançaremos a segunda.

Isso acontece pois ao tratarmos a variavel u como uma unsigned char, teremos para ela, 
uma faixa de valores entre 0 e 255, assim u nunca sera igual a 256

e para a variavel tipo char c é similar, indo de -127 até 127, ela nunca alcançará o valor 
de 128 para sair do laço for

*/
return 0;

}
