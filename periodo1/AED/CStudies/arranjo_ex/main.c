#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
3 - Preencher um  vetor A  de 20 elementos com valores aleatórios de vi a vf (lidos do teclado), em seguida crie um
procedimento que inverta os elementos armazenados. Ou seja, o primeiro elemento de A passará a ser o ultimo, o
segundo elemento passará a ser o penúltimo e assim por diante. Apresentar A.
Autor: Samara Martins
*/

void inverte(int *);

int main()
{

    setlocale(LC_ALL,"portuguese");

    int i, vetA[20], xInicio, xFim;

    printf("Digite um número inicial\n");
    scanf("%d",&xInicio); // Pega o número inicial

    printf("Digite um número final\n");
    scanf("%d",&xFim);  // Pega o número final

    for (i = 0; i < 20; i++) //Preechendo os vetores A e B com números aleatórios no intervalo informado pelo usuário
    {
        vetA[i] = rand()%(xFim - xInicio + 1) + xInicio;
    }

    printf("Vetor: ");
    for(i = 0; i < 20 ; i++)
    {
       printf("%d ", vetA[i]);
    }

   inverte(vetA);

}

void inverte(int *vetA)
{
    int i,j, vetB[20];

    for(j = 0, i = 19; j < 20 ; i--, j++)
    {
        vetB[j] = vetA[i];
    }

    for(i = 0; i < 20 ; i++)
    {
        vetA[i] = vetB[i];
    }


    printf("\n\nInversão: ");

    for(j = 0; j < 20 ; j++)
    {
       printf("%d ", vetA[j]);
    }

}
