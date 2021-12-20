#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*

c) - ler o arquivo letra a e armazenar os dados em uma matriz 8 x 8 armazene essa matriz em um arquivo

*/

int main()
{
    //declaração de variaveis de dois arquivos
    FILE *arquivo, *novoArquivo;
    int i,j;
    double linhaArq, m[8][8];
    setlocale(LC_ALL, "portuguese");
    printf ( "%s\n", "EXERCICIO 3" );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );


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
                fscanf(arquivo,"%lf",&linhaArq);
                printf("%.1f ",linhaArq);
                m[i][j]=linhaArq;
            }
            printf("\n");
        }

        fclose(arquivo);
    }

    //abertura do arquivo no modo de escrita

    if((novoArquivo = fopen("novoArquivo.txt","w")) == NULL)
    {
        printf("Erro de abertura! \n");
    }
    else
    {

        for(i = 0; i < 8; i++)
        {
            for (j = 0 ; j < 8; j++)
            {
                //salva a matriz no novo arquivo
                printf(" %15.0lf", m[i][j]);
                fprintf(arquivo, " %15.0lf", m[i][j]);
            }
            fprintf(arquivo, "\n");
            printf("\n");
        }


        fclose(arquivo);
    }




    system("pause");
    return 0;
}
