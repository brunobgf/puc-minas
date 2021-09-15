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
    int idade;
    setlocale(LC_ALL, "portuguese");

    printf("Qual a sua idade?\n");
    scanf("%d", &idade);

    if(idade>=18){
        printf("Você é maior de idade");
    }
    if(idade <18){
        printf("Você não é maior de idade ainda");
    }
    return 0;
}
