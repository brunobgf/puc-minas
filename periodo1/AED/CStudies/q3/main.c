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
a) Fa�a um procedimento que receba uma matriz 10x10  como par�metro de entrada e devolva essa matriz preenchida com valores compreendidos entre 20 e 30 - utilize a fun��o rand()

b) Fa�a um procedimento que receba uma matriz 10x10 como par�metro de entrada e imprima essa matriz

c) Fa�a uma fun��o que receba uma matriz 10x10 como par�metro de entrada  e devolva a m�dia dos elementos que est�o na diagonal prim�ria desta matriz

d) Fa�a um procedimento  que receba como par�metros de entrada  uma matriz 10x10  e um valor e escreva a localiza��o (linha e coluna) de todos os elementos da matriz que sejam menores que esse valor ou a mensagem que n�o existe valores com essa restri��o.

e) Fa�a um programa que chame os m�dulos  criados.

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

    printf("\nA media dos elementos da diagonal principal ser�: %5.2f \n",media);

    return media;

}

void imprimeElementoMenor(int **m, int tam)
{

    int n1 = 0,cont;
    printf ( "Escolha um numero para verificar se existem numeros menores que ele na matriz e as suas posi��es \n" );
    scanf("%d", &n1);

        for(int i=0; i<tam; i++)
        {
            for(int j=0; j<tam; j++)
            {
                if(m[i][j]<n1)
                {
                    printf("numero menor que o escolhido encontrado na posi��o [%d][%d] \n",i,j);
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
            printf("N�mero n�o corresponde a restri��o\n");
        }

}

