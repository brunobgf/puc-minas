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
    int num;
    setlocale(LC_ALL, "portuguese");

    printf("Escolha um número\n");
    scanf("%d", &num);

    if(num%2==0){
        printf("Este número é par");
    }
    if(num%2!=0){
        printf("Este é um número impar");
    }
    return 0;
}
