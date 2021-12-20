#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
3 - Preencher um  vetor A  de 20 elementos com valores aleat�rios de vi a vf (lidos do teclado), em seguida crie um
procedimento que inverta os elementos armazenados. Ou seja, o primeiro elemento de A passar� a ser o ultimo, o
segundo elemento passar� a ser o pen�ltimo e assim por diante. Apresentar A.
Autor: Samara Martins
*/

void inverte(int *);

int main()
{

    setlocale(LC_ALL,"portuguese");

    int i, vetA[20], xInicio, xFim;

    printf("Digite um n�mero inicial\n");
    scanf("%d",&xInicio); // Pega o n�mero inicial

    printf("Digite um n�mero final\n");
    scanf("%d",&xFim);  // Pega o n�mero final

    for (i = 0; i < 20; i++) //Preechendo os vetores A e B com n�meros aleat�rios no intervalo informado pelo usu�rio
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


    printf("\n\nInvers�o: ");

    for(j = 0; j < 20 ; j++)
    {
       printf("%d ", vetA[j]);
    }

}
