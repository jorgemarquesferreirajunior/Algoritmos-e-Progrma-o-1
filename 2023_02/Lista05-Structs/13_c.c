#include <stdio.h>
#include<locale.h>
#include<math.h>

typedef struct{
    float segmento1, segmento2, segmento3;
}triangulo;

typedef struct{
    int xpos, ypos;
}coordenada;

float distancia(coordenada vertice1, coordenada vertice2);
float quadrado(float x);
int testaTriangulo(float, float, float);
float calculaPerimetro(triangulo x);

int main() {
    setlocale(LC_ALL, "Portuguese");
    triangulo figura;
    coordenada vertice_A, vertice_B, vertice_C;
    float perimetro;

    vertice_A.xpos = 4;vertice_A.ypos = 4;
    vertice_B.xpos = 3;vertice_B.ypos = 3;
    vertice_C.xpos = 5;vertice_C.ypos = 3;


    figura.segmento1 = distancia(vertice_A, vertice_B);
    figura.segmento2 = distancia(vertice_B, vertice_C);
    figura.segmento3 = distancia(vertice_A, vertice_C);
    perimetro = calculaPerimetro(figura);

    printf("segmentos:\nAB:%.2f\nBC:%.2f\nAC:%.2f\n",figura.segmento1, figura.segmento2, figura.segmento3);
    if(testaTriangulo(figura.segmento1, figura.segmento2, figura.segmento3) == 1){
        printf("Os segmentos formam um triângulo.\n");
        printf("Perímetro: %.2f\n", perimetro);
    }else{
        printf("Os segmentos NÃO formam um triângulo.\n");
    }

    return 0;
}
float calculaPerimetro(triangulo x){
    return x.segmento1 + x.segmento2 + x.segmento3;
}
int testaTriangulo(float a, float b, float c){
    if((a + b) > c && (a + c) > b && (b + c) > a){
        return 1;
    }else{
        return 0;
    }
}
float distancia(coordenada vertice1, coordenada vertice2){
    float segmento = 0;
    int delta_x = vertice2.xpos - vertice1.xpos;
    int delta_y = vertice2.ypos - vertice1.ypos;

    segmento =sqrt(quadrado(delta_x) + quadrado(delta_y));
    return segmento;
}

float quadrado(float x){
    return x * x;
}

