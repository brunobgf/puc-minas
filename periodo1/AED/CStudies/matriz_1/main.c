#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

/*

1) Preencher uma matriz de 10 x 10 posi��es com valores aleat�rios de 15 a 50 (utilize para cada n�mero a fun��o rand � fa�a uma
fun��o que dados os valores inicial e final devolva um n�mero aleat�rio dentro deste intervalo) Em seguida imprima os �ndices (i,j) da
matriz e o valor correspondente, na forma de matriz, bem como chame os m�dulos abaixo(0,5)

*/

int main()
{
    int mat[10][10];
    int i,j;
    srand(time(NULL));
    setlocale(LC_ALL, "portuguese");
    printf ( "%s\n", "EXERCICIO 1" );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );
    printf("Matriz com numeros aleatorios: \n");
    for(i=0; i<10; i++) // cria��o das linhas
    {
        for(j=0; j<10; j++)
        {
            mat[i][j]=rand()%36+15; //50-15 = 35
            printf("[%d][%d] =  %3d ",i,j,mat[i][j]);
        }
        printf("\n"); //linha debaixo

    }

    return 0;
}

