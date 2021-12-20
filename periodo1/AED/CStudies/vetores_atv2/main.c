#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
void uniaoVetor(int *vet1, int *vet2, int tam);
void deletaDuplicados(int *vet1,int tam);

int main()
{
    int vetA[15], vetB[15],i;
    setlocale(LC_ALL, "portuguese");
    printf ( "%s\n", "EXERCICIO 2 - Preencher dois vetores A e B de 15 posi��es cada com valores aleat�rios de vi a vf (lidos do teclado). Construir um vetor C, sendo este o resultado da uni�o dos elementos de A e B � sem repeti��o. Apresentar C." );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );
    for(i=0; i<15; i++)
    {
        printf("Escolha um numero para popular o vetor 1:\n");
        scanf("%d", &vetA[i]);
    }
    for(i=0; i<15; i++)
    {
        printf("Escolha um numero para popular o vetor 2:\n");
        scanf("%d", &vetB[i]);
    }
    printf("Escolha um numero para popular o vetor 2:\n");
    uniaoVetor(vetA,vetB,30);

    return 0;
}

void uniaoVetor(int *vet1, int *vet2, int tam)
{
    int vetC[30],i,j;

    for(i=0; i<15; i++)
    {
        vetC[i] = vet1[i];
    }

    for(i=0,j=15; j<30 && i<15; i++,j++)
    {
        vetC[j] = vet2[i];
    }

    printf("Vetor ap�s unir:");
    for(i=0; i<30; i++)
    {
        printf("%d ",vetC[i]);
    }

    printf("\nO vetor sem os n�meros duplicados �: \n");

    deletaDuplicados(vetC,30);
}

void deletaDuplicados(int *vet1,int tam)
{
    int i,j,k,number=30;


    for(i=0; i<number; i++)
    {
        //checa a partir do segundo elemento se h� rpeti��o
        for(j = i+1; j < number; j++)
        {
            //verifica existencia de duplicado
            if(vet1[i] == vet1[j])
            {
                //remove o numero duplicado
                for(k = j; k <number-1; k++)
                {
                    vet1[k] = vet1[k+1];
                }
                number--; // reduz o numero maximo do array por 1
                j--; //se a posi��o dos elementos se altera, o index de j permanecer� o mesmo
            }
        }
    }

    for(i=0; i<number; i++)
    {
        printf(" %d ",vet1[i]);
    }
}
