#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
int ** preencheMatriz(int tam);
void imprimeMatriz(int **m, int tam);
void imprimeMaior(int **m, int tam);
void imprimeMenor(int **m, int tam);

/*

2) Escreva um procedimento que receba uma matriz 10x10 (passagem de par�metro), imprimir o maior e o menor elemento da matriz bem
como a posi��o de cada um.(0,5)

*/

int main()
{
    int **mat;

    srand(time(NULL));
    setlocale(LC_ALL, "portuguese");
    printf ( "%s\n", "EXERCICIO 2" );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );

    mat=preencheMatriz(10);
    imprimeMatriz(mat,10);

    imprimeMaior(mat,10);
    imprimeMenor(mat,10);

    return 0;
}

//Aloca��o da matriz na mem�ria
int ** preencheMatriz(int tam)
{
    int **m;
    //int * refere-se ao vetor
    m=malloc(sizeof(int *)*tam);
    //aloca��o de mem�ria
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

void imprimeMaior(int **m, int tam)
{

    int maiorElemento = m[0][0],i,j,cx=0,cy=0;


    for(i=0; i<tam; i++)
    {
        for(j=0; j<tam; j++)
        {
            if(m[i][j]>maiorElemento)
            {
                maiorElemento = m[i][j]; //guarda o maior elemento
                cx=i; //guarda a posi��o da linha
                cy=j; //guarda posi��o da coluna
            }
        }

    }

    printf("\nO maior elemento da matriz �: %d e a posi��o � [%d][%d] \n",maiorElemento,cx,cy);

}


void imprimeMenor(int **m, int tam)
{

    int menorElemento = m[0][0],i,j,cx=0,cy=0;


    for( i=0; i<tam; i++)
    {
        for( j=0; j<tam; j++)
        {
            if(m[i][j]<menorElemento)
            {
                menorElemento = m[i][j];
                cx=i;
                cy=j;
            }
        }

    }

    printf("\nO menor elemento da matriz �: %d e a posi��o � [%d][%d] \n",menorElemento,cx,cy);

}
