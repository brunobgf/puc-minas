#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*

b) - ler o arquivo letra a e armazenar os dados em uma matriz 8 x 8 imprima essa matriz na tela

*/

int main()
{
    FILE *arquivo;
    int i,j;
    double linhaArq;

    setlocale(LC_ALL, "portuguese");
    printf ( "%s\n", "EXERCICIO 2" );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );

    //abertura do arquivo no modo de leitura
    if((arquivo = fopen("C:/temp/arquivo.txt","r")) == NULL)
    {
        printf("Erro de abertura! \n");
    }
    else
    {
        for(i = 0; i < 8; i++)
        {
            for (j = 0 ; j < 8; j++)
            {
                //imprime e salva a matriz
                fscanf(arquivo,"%lf",&linhaArq);
                printf("%15.01f ",linhaArq);
            }
            printf("\n");
        }

        fclose(arquivo);
    }



    system("pause");
    return 0;
}

