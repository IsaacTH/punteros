#include <stdio.h>
#include <math.h>

float calcularDistancia(float x1, float y1, float x2, float y2);
float calcularPerimetro(float puntos[3][2], float *a, float *b, float *c);
float calcularArea(float a, float b, float c);

int main(int argc, char *argv[]){

    float puntos[3][2] = {{0, 0}, {0, 3}, {3, 0}};
    float a, b, c;

    float perimetro = calcularPerimetro(puntos,&a,&b,&c);
    float area = calcularArea(a,b,c);

    printf("El perimetro del triangulo es: %0.2f\n", perimetro);
    printf("El area del triangulo es: %.02f", area);

    return 0;
}

float calcularDistancia(float x1, float y1, float x2, float y2){
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

float calcularPerimetro(float puntos[3][2], float *a, float *b, float *c){
    *a = calcularDistancia(puntos[0][0],puntos[0][1],puntos[1][0],puntos[1][1]);
    *b = calcularDistancia(puntos[1][0],puntos[1][1],puntos[2][0],puntos[2][1]);
    *c = calcularDistancia(puntos[0][0],puntos[0][1],puntos[2][0],puntos[2][1]);
    float per = *a + *b + *c;
    return per;
}

float calcularArea(float a, float b, float c){
    float s = (a+b+c)/2;
    float area = sqrt(s*(s-a)*(s-b)*(s-c));
    return area;
}