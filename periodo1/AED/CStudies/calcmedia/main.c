#include <stdio.h>
#include <stdlib.h>
int calcMediaNotas(int v1, int v2, int v3);

int main()
{
    int x,y,z,resultado;
    printf("Escolha o valor de x:\n");
    scanf("%d", &x);
    printf("Escolha o valor de y :\n");
    scanf("%d", &y);
    printf("Escolha o valor de z :\n");
    scanf("%d", &z);
    resultado=calcMediaNotas(x,y,z);
    printf("%d", resultado);
    return 0;
}

int calcMediaNotas(int v1, int v2, int v3)
{
    int maior=0;
    float media;
    media = (float) (v1+v2+v3)/3;

    if(v1>media)
    {
        maior = maior +1;
    }
    if(v2>media)
    {
        maior = maior +1;
    }

    if(v3>media)
    {
        maior = maior +1;
    }





    return maior;

}
