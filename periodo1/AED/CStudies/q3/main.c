#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
int ** preencheMatriz(int tam);
void imprimeMatriz(int **m, int tam);
float mediaDiagonal(int **m, int tam);
void imprimeElementoMenor(int **m, int tam);

/*
PROVA EX - 03
a) Faça um procedimento que receba uma matriz 10x10  como parâmetro de entrada e devolva essa matriz preenchida com valores compreendidos entre 20 e 30 - utilize a função rand()

b) Faça um procedimento que receba uma matriz 10x10 como parâmetro de entrada e imprima essa matriz

c) Faça uma função que receba uma matriz 10x10 como parâmetro de entrada  e devolva a média dos elementos que estão na diagonal primária desta matriz

d) Faça um procedimento  que receba como parâmetros de entrada  uma matriz 10x10  e um valor e escreva a localização (linha e coluna) de todos os elementos da matriz que sejam menores que esse valor ou a mensagem que não existe valores com essa restrição.

e) Faça um programa que chame os módulos  criados.

*/

int main()
{
    int **mat;

    srand(time(NULL));
    setlocale(LC_ALL, "portuguese");
    printf ( "%s\n", "PROVA - EXERCICIO 3" );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );

    mat=preencheMatriz(10);
    imprimeMatriz(mat,10);
    mediaDiagonal(mat,10);
    imprimeElementoMenor(mat,10);




    return 0;
}

//Alocação da matriz na memória
int ** preencheMatriz(int tam)
{
    int **m;
    //int * refere-se ao vetor
    m=malloc(sizeof(int *)*tam);
    //alocação de memória
    for(int i=0; i<tam; i++)
    {
        m[i]=malloc(sizeof(int)*tam);
    }
    for(int i=0; i<tam; i++)
    {
        for(int j=0; j<tam; j++)
        {
            m[i][j]=rand()%11+20; //30-10 = 20
        }

    }

    return m;
}

void imprimeMatriz(int **m, int tam)
{
    int i,j;
    for(i=0; i<tam; i++)
    {
        for(j=0; j<tam; j++)
        {
            printf("[%d][%d] =  %3d ",i,j,m[i][j]); //imprime a matriz
        }
        printf("\n");

    }
}


float mediaDiagonal(int **m, int tam)
{

    int soma = 0,denominador=10;
    float media;


    for(int i=0; i<tam; i++)
    {
        for(int j=0; j<tam; j++)
        {
            if(m[i]==m[j]) //verifica se corresponde a diagonal principal
            {
                soma=soma+m[i][j];
            }
        }

    }
    media = (float)soma/denominador;

    printf("\nA media dos elementos da diagonal principal será: %5.2f \n",media);

    return media;

}

void imprimeElementoMenor(int **m, int tam)
{

    int n1 = 0,cont;
    printf ( "Escolha um numero para verificar se existem numeros menores que ele na matriz e as suas posições \n" );
    scanf("%d", &n1);

        for(int i=0; i<tam; i++)
        {
            for(int j=0; j<tam; j++)
            {
                if(m[i][j]<n1)
                {
                    printf("numero menor que o escolhido encontrado na posição [%d][%d] \n",i,j);
                    cont++;
                }
                if(m[i][j]>n1)
                {
                    cont=0;
                }
            }
        }

        if(cont==0)
        {
            printf("Número não corresponde a restrição\n");
        }

}

