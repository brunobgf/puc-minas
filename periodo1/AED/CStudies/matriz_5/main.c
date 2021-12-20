#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
int ** preencheMatriz(int tam);
void imprimeMatriz(int **m, int tam);
void imprimeElemento(int **m, int tam);

/*

5) Escreva um procedimento que receba uma matriz 10x10, e um número. O procedimento deverá verificar se o número está ou não na
matriz. Se estiver imprima a(s) posição(ões) desse número e se não estiver imprima a mensagem valor não encontrado.(0,5)

*/

int main()
{
    int **mat;

    srand(time(NULL));
    setlocale(LC_ALL, "portuguese");
    printf ( "%s\n", "EXERCICIO 5" );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );

    mat=preencheMatriz(10);
    imprimeMatriz(mat,10);

    imprimeElemento(mat,10);


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


void imprimeElemento(int **m, int tam)
{

    int n1 = 0,cont=0;
    printf ( "escolha um numero para verificar se ele pertence ou não a matriz, -1 sai do loop \n" );
    scanf("%d", &n1);


    while(n1!=-1)
    {
        for(int i=0; i<tam; i++)
        {
            for(int j=0; j<tam; j++)
            {
                if(m[i][j]==n1)
                {
                    printf("numero igual encontrado na posição [%d][%d] \n",i,j);
                    cont++;
                }
                else {
                    cont=0;
                }
            }
        }

        if(cont==0){
            printf("Número não está na matriz\n");
        }

        printf ( "escolha um numero para verificar se ele pertence ou não a matriz, -1 sai do loop \n" );
        scanf("%d", &n1);
    }
}


