#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
int verificaPrimo(double v);

/*

e) - ler o arquivo letra a e armazenar em um vetor apenas os primos, imprima esse vetor, e salve os dados
desse vetor em um arquivo.


*/

int main()
{
    FILE *arquivo, *arquivoPrimos;
    int i,j;
    double m[8][8],linhaArq;
    setlocale(LC_ALL, "portuguese");
    printf ( "%s\n", "EXERCICIO 2" );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );

    if((arquivoPrimos = fopen("arquivoPrimos.txt","w")) == NULL)
    {
        printf("Erro de abertura! \n");
    }
    if((arquivo = fopen("C:/temp/arquivo.txt","r")) == NULL)
    {
        printf("Erro de abertura! \n");
    }
    else
    {
        //leitura da matriz
        fscanf(arquivo,"%lf",&linhaArq);
        i=0;
        j=0;
        while (!feof(arquivo))
        {
            m[i][j] = linhaArq;
            j++;
            if(j>7)
            {
                i++;
                j=0;
            }
            fscanf(arquivo,"%lf",&linhaArq);
        }

        for(i = 0; i < 8; i++)
        {
            for (j = 0 ; j < 8; j++)
            {
                if(verificaPrimo(m[i][j])==1) //se retornar 1, significa que o numero é primo
                {
                    fprintf(arquivoPrimos, " %15.0lf\n", m[i][j]); //salva o numero primo no arquivo
                }
            }
        }
    }
    fclose(arquivo);
    fclose(arquivoPrimos);

    system("pause");
    return 0;
}

//função para cálculo dos numeros primos

int verificaPrimo(double v)
{
    double i;

    for (i = 2; i <= (v / 2); i++)
    {
        if (fmod(v, i) == 0)
        {
            return 0;

        }
    }

    return 1;

}


