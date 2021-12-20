#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
void vetorOrdenado(int *vet1,int tam);

int main()
{
    int vetA[10],i;
    setlocale(LC_ALL, "portuguese");
    printf ( "%s\n", "EXERCICIO 5 - Preencher um vetor A de 10 elementos com valores aleatórios de vi a vf (lidos do teclado).Ordene e imprima o vetor A." );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );
    for(i=0; i<10; i++)
    {
        printf("Escolha um numero para popular o vetor 1:\n");
        scanf("%d", &vetA[i]);
    }

    printf("Vetor após ordenar:\n");
    vetorOrdenado(vetA,10);

    return 0;
}

void vetorOrdenado(int *vet1,int tam)
{
    int i,j,temp=0;

    for(i=0; i<10; i++)
    {
        for(j=i+1; j<10; j++)
        {

            if (vet1[i] > vet1[j])
            {
                temp = vet1[i];
                vet1[i] = vet1[j];
                vet1[j] = temp;
            }
        }
    }


    for(i=0; i<10; i++)
    {
        printf("%d ",vet1[i]);
    }

}

