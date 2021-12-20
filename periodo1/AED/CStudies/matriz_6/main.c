#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

/*
- Construa uma função que retorne um vetor real com dados informados pelo teclado de
tamanho N – passe o tamanho N por valor.
- Construa um procedimento para imprimir um vetor real de tamanho N – passe o vetor e o
tamanho N por valor
*/

float * preencheVetor(int tam);
void imprimeVetor(float *v, int tam);

int main()
{
    float *vet;
    int tam;
    srand(time(NULL));
    setlocale(LC_ALL, "portuguese");
    printf ( "%s\n", "EXERCICIO 6" );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );

    printf("Escolha um tamanho para o vetor:\n");
    scanf("%d",&tam);

    vet=preencheVetor(tam);
    printf("O vetor gerado será:\n");
    imprimeVetor(vet,tam);
    free(vet);
    vet=NULL;


    return 0;

}

/*

- Construa uma função que retorne um vetor real com dados informados pelo teclado de
tamanho N – passe o tamanho N por valor.

*/

float * preencheVetor(int tam)
{

    float *v;
    //alocação de memória do vetor
    v=malloc(sizeof(float)*tam);
    for(int i=0; i<tam; i++)
    {

        v[i]=rand()%36+15; //50-15 = 35

    }

    return v;

}

/*

- Construa um procedimento para imprimir um vetor real de tamanho N – passe o vetor e o
tamanho N por valor

*/

void imprimeVetor(float *v, int tam)
{
    for(int i=0; i<tam; i++)
    {

        printf("[%d]=%5.2f\n",i,v[i]);
    }
}
