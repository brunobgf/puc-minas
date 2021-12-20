#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


/*

1 - Preencher um vetor de 15 posi��es posi��es com valores aleat�rios de 15 a 50. Construir um vetor B do
mesmo tipo, em que cada elemento de B deva ser o resultado do fatorial correspondente de cada elemento da matriz
A. Apresentar A e B

*/
int main()
{
    FILE * arquivo;
    int tam=64;
    double v[64]; //vetor contendo os 64 numeros da s�rie de fibonacci
    setlocale(LC_ALL, "portuguese");
    printf ( "%s\n", "EXERCICIO 1" );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );

    //abertura do arquivo
    if ((arquivo = fopen("C:/temp/arquivo.txt","w")) == NULL) // modo de escrita ativo
    {
        printf("Erro de abertura! \n");
    }
    else
    {
        v[0] = 1; //primeiro termo
        v[1] = 1; //segundo termo
        //o for inicia a partir do segundo termo
        for(int i = 2; i < tam; i++)
        {

            v[i] = v[i-1]+v[i-2]; //l�gica da s�rie
        }

        for(int i=0; i<tam; i++)
        {
            //imprime o vetor
            printf("Posi��o[%d] - %5.2f\n",i,v[i]);
            //salva no arquivo a s�rie
            fprintf(arquivo,"%5.2f\n", v[i]);

        }
        //fechamento do arquivo

        fclose(arquivo);
    }
    system("pause");
    return 0;
}

