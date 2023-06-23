#include <stdio.h>
#include <math.h>

float calcularDistancias(float x1, float y1, float z1, float x2, float y2, float z2); //calcula la distancia entre dos puntos
float calcularPerimetro(float puntos[4][3]); //calcula el perimetro total de la piramide sumando las distancias entre los puntos
float calcularArea(float x1, float y1, float z1, float x2, float y2, float z2,float x3, float y3, float z3); //calcula el área de un triangulo utilizando las componente de los 3 puntos que lo conforman
float calcularAreaSuperficial(float puntos[4][3]); //calcula el área surficial de toda la piramide
float calcularDistancias(float x1, float y1, float x2, float y2);
float calcularPerimetro(float puntos[3][2], float *a, float *b, float *c);
float calcularArea(float a, float b, float c);

int main(int argc, char *argv[])
{

    float puntos[4][3]={{3,0,0},{0,0,3},{0,0,0},{1,7,1}};
    float puntos[3][2]={{3,0},{0,3},{0,0}};
    float a, b, c;

    float perimetro = calcularPerimetro(puntos);
    printf("El perimetro de la piramide es %f\n", perimetro);
    float areaSuperficial = calcularAreaSuperficial(puntos);
    printf("El area superficial de la piramide es %f\n", areaSuperficial);
    float perimetro = calcularPerimetro(puntos,&a,&b,&c);
    printf("El perimetro del triangulo es %f\n", perimetro);
    float area = calcularArea(a,b,c);
    printf("El area del triangulo es %f\n", area);


    return 0;
}

float calcularDistancias(float x1, float y1, float z1, float x2, float y2, float z2){
    return sqrt(pow(x1-x2,2)+pow(y1-y2,2)+pow(z1-z2,2));
float calcularDistancias(float x1, float y1, float x2, float y2){
    return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}

float calcularPerimetro(float puntos[4][3]){
    float l1 = calcularDistancias(puntos[0][0],puntos[0][1],puntos[0][2],puntos[1][0],puntos[1][1],puntos[1][2]);
    float l2 = calcularDistancias(puntos[1][0],puntos[1][1],puntos[1][2],puntos[2][0],puntos[2][1],puntos[2][2]);
    float l3 = calcularDistancias(puntos[0][0],puntos[0][1],puntos[0][2],puntos[2][0],puntos[2][1],puntos[2][2]);

    float l4 = calcularDistancias(puntos[0][0],puntos[0][1],puntos[0][2],puntos[3][0],puntos[3][1],puntos[3][2]);
    float l5 = calcularDistancias(puntos[1][0],puntos[1][1],puntos[1][2],puntos[3][0],puntos[3][1],puntos[3][2]);
    float l6 = calcularDistancias(puntos[3][0],puntos[3][1],puntos[3][2],puntos[2][0],puntos[2][1],puntos[2][2]);

    return l1+l2+l3+l4+l5+l6;
}

float calcularArea(float x1, float y1, float z1, float x2, float y2, float z2,float x3, float y3, float z3){

    float l1 = calcularDistancias(x1,y1,z1,x2,y2,z2);
    float l2 = calcularDistancias(x2,y2,z2,x3,y3,z3);
    float l3 = calcularDistancias(x1,y1,z1,x3,y3,z3);
    float s = (l1+l2+l3)/2;
    return sqrt(s*(s-l1)*(s-l2)*(s-l3));
float calcularPerimetro(float puntos[3][2], float *a, float *b, float *c){
    *a = calcularDistancias(puntos[0][0],puntos[0][1],puntos[1][0],puntos[1][1]);
    *b = calcularDistancias(puntos[1][0],puntos[1][1],puntos[2][0],puntos[2][1]);
    *c = calcularDistancias(puntos[0][0],puntos[0][1],puntos[2][0],puntos[2][1]);
    float per=*a+*b+*c;
    return per;
}

float calcularAreaSuperficial(float puntos[4][3]){
    float areabase = calcularArea(puntos[0][0],puntos[0][1],puntos[0][2],puntos[1][0],puntos[1][1],puntos[1][2],puntos[2][0],puntos[2][1],puntos[2][2]);
    float area1 = calcularArea(puntos[0][0],puntos[0][1],puntos[0][2],puntos[1][0],puntos[1][1],puntos[1][2],puntos[3][0],puntos[3][1],puntos[3][2]);
    float area2 = calcularArea(puntos[0][0],puntos[0][1],puntos[0][2],puntos[2][0],puntos[2][1],puntos[2][2],puntos[3][0],puntos[3][1],puntos[3][2]);
    float area3 = calcularArea(puntos[1][0],puntos[1][1],puntos[1][2],puntos[2][0],puntos[2][1],puntos[2][2],puntos[3][0],puntos[3][1],puntos[3][2]);
    return areabase+area1+area2+area3;
float calcularArea(float a, float b, float c){
    float s = (a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}