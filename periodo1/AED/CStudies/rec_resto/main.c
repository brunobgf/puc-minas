#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int calcResto(int v1, int v2);

int main()
{
    int x,y,resultado;
    setlocale(LC_ALL, "portuguese");
    printf ( "%s\n", "Calculo do resto da divisão de dois números" );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );
    printf("Escolha o valor de x:\n");
    scanf("%d", &x);
    printf("Escolha o valor de y :\n");
    scanf("%d", &y);
    resultado=calcResto(x,y);
    printf("O resto da divisao de %d por %d é %d",x,y,resultado);
    return 0;
}

int calcResto(int v1, int v2)
{
    int resto;

    if(v1<v2)
    {
        resto=v1;
    }
    else
    {
            resto = calcResto((v1-v2),v2);
    }

    return resto;
}
