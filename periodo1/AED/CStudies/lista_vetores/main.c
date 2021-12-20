#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "mb_bruno.h"


void menu();

int main()
{
    setlocale(LC_ALL, "portuguese"); //permite usar carácteres em portugues
    menu();
    return 0;
}

void menu()
{

    int op,a,b,resultado;
    printf("Escolha o número referente aos exercícios no menu para serem executados:\n");
    printf("1 - Exercicio 1 \n");
    printf("2 - Exercicio 2 \n");
    printf("3 - Exercicio 3 \n");
    printf("-1 Finaliza o programa\n");
    scanf("%d",&op);

    do
    {
        //Estrutura switch-case para poder acessar o menu
        switch(op)
        {
        case 1:
            printf("Digite o primeiro numero \n");
            scanf("%d",&a);
            printf("Digite o segundo numero \n");
            scanf("%d",&b);
            resultado = calcMult(a,b);
            printf("%d \n", resultado);

            break;
        case 2:
            printf("Digite o limite inferior \n");
            scanf("%d",&a);
            printf("Digite o limite superior \n");
            scanf("%d",&b);
            somaNumeros(a,b);
            printf("%d \n", soma);
            break;
        case 3:
            printf("Digite o limite inferior \n");
            scanf("%d",&a);
            printf("Digite o limite superior \n");
            scanf("%d",&b);
            resultado = qtdNumerosImpares(a,b);
            printf("%d \n", resultado);
            break;
            break;
        default:
            printf("Codigo invalido, tente novamente");
        }

        printf("Escolha o número referente aos exercícios no menu para serem executados:\n");
        printf("1 - Exercicio 1 \n");
        printf("2 - Exercicio 2 \n");
        printf("3 - Exercicio 3 \n");
        printf("-1 Finaliza o programa\n");
        scanf("%d",&op);
    }
    while(op!= -1);
}


