#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*

Treino de Estrutura Condicional em C

Aluno: Bruno Gomes Ferreira

Data: 14/09/2021

*/

int main()
{
    int cod;
    setlocale(LC_ALL, "portuguese");

    printf("Escolha um código do produto\n");
    scanf("%d", &cod);

    if(cod==1)
    {
        printf("Hamburguer - R$30,00\n");
    }
    if(cod==2)
    {
        printf("Cheeseburguer - R$35,00\n");
    }
    if(cod==3)
    {
        printf("Fritas - R$20,50\n");
    }
    if(cod==4)
    {
        printf("Refrigerante - R$10,00\n");
    }
    if(cod==5)
    {
        printf("Milk-Shake - R$30,00\n");
    }
    if(cod>5 || cod<1)
    {
        printf("Este código não corresponde a nenhum dos produtos\n");
    }
    return 0;
}
