#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*

d) - ler o arquivo letra a e armazenar os valores pares em um arquivo e os impares em outro arquivo

*/

int main()
{
    FILE *arquivo, *arquivoPares,*arquivoImpares;
    int i,j;
    double m[8][8],linhaArq;
    setlocale(LC_ALL, "portuguese");
    printf ( "%s\n", "EXERCICIO 2" );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );

    //abertura dos arquivos para armazenar par e impar

    if((arquivoPares = fopen("arquivoPares.txt","w")) == NULL)
    {
        printf("Erro de abertura! \n");
    }
    if((arquivoImpares = fopen("arquivoImpares.txt","w")) == NULL)
    {
        printf("Erro de abertura! \n");
    }
    if((arquivo = fopen("C:/temp/arquivo.txt","r")) == NULL)
    {
        printf("Erro de abertura! \n");
    }
    else
    {
        //outra forma de leitura do arquivo inicial em formato de matriz, para esse exercicio foi melhor utilizar while do que o for
        fscanf(arquivo,"%lf",&linhaArq);
        i=0; //zera os contadores
        j=0;
        while (!feof(arquivo)) //enquanto NÃO encontrar o final do arquivo lido
        {
            m[i][j] = linhaArq; //o termo da matriz é igual a linha lida
            j++; //soma a coluna
            if(j>7) //quando o INDICE da coluna for maior que 7 (0~7)
            {
                i++; //desce uma linha
                j=0; //o indice referente a coluna zera e continua o looping
            }
            fscanf(arquivo,"%lf",&linhaArq); //grava no arquivo
        }
        for(i = 0; i < 8; i++)
        {
            for (j = 0 ; j < 8; j++)
            {
                //não é possível utilizar o % em double, então foi necessário usar a função fmod para comparar os termos da matriz
                if(fmod(m[i][j],2)==0)
                {
                    fprintf(arquivoPares, " %15.0lf\n", m[i][j]); //grava os pares no arquivoPares
                }
                else
                {
                    fprintf(arquivoImpares, " %15.0f\n", m[i][j]); //grava os pares no arquivoImpares

                }
            }
        }
    }

    //fechamento dos arquivos

    fclose(arquivo);
    fclose(arquivoPares);
    fclose(arquivoImpares);

    system("pause");
    return 0;
}


