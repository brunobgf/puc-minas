#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
int ** preencheMatriz(int tam);
void imprimeMatriz(int **m, int tam);
void imprimeElemento(int **m, int tam);

/*

4) Escreva um procedimento que receba uma matriz 10x10, peça ao usuário a posição [i,j] da matriz , e em seguida exiba o valor que esta
na matriz nesta posição. FLAG -1(0,5)

*/

int main()
{
    int **mat;

    srand(time(NULL));
    setlocale(LC_ALL, "portuguese");
    printf ( "%s\n", "EXERCICIO 4" );
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

    int n1 = 0, n2=0;
    printf ( "escolha o indice i da matriz, -1 sai do loop \n" );
    scanf("%d", &n1);

    printf ( "escolha o indice j da matriz \n" );
    scanf("%d", &n2);
    while(n1!=-1)
    {
        for(int i=1; i<tam; i++)
        {
            for(int j=1; j<tam; j++)
            {
                if(m[i]==m[n1] && m[j]==m[n2]) //verifica a igualdade do que o usuário escolheu, com a matriz gerada
                {
                    printf("O valor para o indice [%d][%d] é: %d \n",i,j,m[i][j]);
                }
            }

        }

        printf ( "escolha o indice i da matriz, -1 sai do loop \n" );
        scanf("%d", &n1);

        printf ( "escolha o indice j da matriz \n" );
        scanf("%d", &n2);



    }


}


