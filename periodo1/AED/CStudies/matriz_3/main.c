#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
int ** preencheMatriz(int tam);
void imprimeMatriz(int **m, int tam);
void somaDiagonal(int **m, int tam);

/*

3) Escreva uma função que receba uma matriz 10x10 e retorne a soma dos elementos da diagonal.(0,5)

*/

int main()
{
    int **mat;

    srand(time(NULL));
    setlocale(LC_ALL, "portuguese");
    printf ( "%s\n", "EXERCICIO 3" );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );

    mat=preencheMatriz(10);
    imprimeMatriz(mat,10);

    somaDiagonal(mat,10);

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
            m[i][j]=rand()%36+15; //50-15 = 35
        }

    }

    return m;
}

void imprimeMatriz(int **m, int tam)
{
    for(int i=0; i<tam; i++)
    {
        for(int j=0; j<tam; j++)
        {
            printf("[%d][%d] =  %3d ",i,j,m[i][j]); //imprime a matriz
        }
        printf("\n");

    }
}

void somaDiagonal(int **m, int tam)
{

    int soma = 0;

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

    printf("\nA soma dos elementos da diagonal principal será: %d \n",soma);

}


