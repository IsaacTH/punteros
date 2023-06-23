#include <stdio.h>
#include <math.h>

float calcularDistancia(float x1, float y1, float z1, float x2, float y2, float z2);
float calcularPerimetro(float puntos[4][3], float *a, float *b, float *c, float *d, float *e, float *f);
float calcularArea(float a, float b, float c);
float AS(float areabase, float area1, float area2, float area3);

int main(int argc, char *argv[])
{

    float puntos[4][3] = {{0, 0, 0}, {0, 0, 3}, {3, 0, 0}, {1, 7, 1}};
    float a, b, c, d, e, f;

    float perimetro = calcularPerimetro(puntos, &a, &b, &c, &d, &e, &f);
    float aBase = calcularArea(a, b, c);
    float a1 = calcularArea(a, e, d);
    float a2 = calcularArea(c, e, f);
    float a3 = calcularArea(b, d, f);
    float areaSuperficial = AS(aBase, a1, a2, a3);
    float g1 = calcularBaricentro(puntos[0][0], puntos[1][0], puntos[2][0]);
    float g2 = calcularBaricentro(puntos[0][1], puntos[1][1], puntos[2][1]);
    float g3 = calcularBaricentro(puntos[0][2], puntos[1][2], puntos[2][2]);

    printf("El perimetro de la piramide es: %0.2f\n", perimetro);
    printf("El area de la piramide es: %.02f", areaSuperficial);
    printf("El volumen de la piramide es: ");

    return 0;
}

float calcularDistancia(float x1, float y1, float z1, float x2, float y2, float z2)
{
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2) + pow(z1 - z2, 2));
}

float calcularPerimetro(float puntos[4][3], float *a, float *b, float *c, float *d, float *e, float *f)
{
    *a = calcularDistancia(puntos[0][0], puntos[0][1], puntos[0][2], puntos[1][0], puntos[1][1], puntos[1][2]);
    *b = calcularDistancia(puntos[0][0], puntos[0][1], puntos[0][2], puntos[2][0], puntos[2][1], puntos[2][2]);
    *c = calcularDistancia(puntos[1][0], puntos[1][1], puntos[1][2], puntos[2][0], puntos[2][1], puntos[2][2]);
    *d = calcularDistancia(puntos[0][0], puntos[0][1], puntos[0][2], puntos[3][0], puntos[3][1], puntos[3][2]);
    *e = calcularDistancia(puntos[1][0], puntos[1][1], puntos[1][2], puntos[3][0], puntos[3][1], puntos[3][2]);
    *f = calcularDistancia(puntos[2][0], puntos[2][1], puntos[2][2], puntos[3][0], puntos[3][1], puntos[3][2]);
    float per = *a + *b + *c + *d + *e + *f;
    return per;
}

float calcularArea(float x, float y, float z)
{
    float s = (x + y + z) / 2;
    float areabase = sqrt(s * (s - x) * (s - y) * (s - z));
    return areabase;
}

float AS(float areabase, float area1, float area2, float area3)
{
    float areaSuperficial = areabase + area1 + area2 + area3;
    return areaSuperficial;
}

float calcularBaricentro(float x1, float x2, float x3){
    float G = (x1 + x2 + x3) / 3;
    return G;
}