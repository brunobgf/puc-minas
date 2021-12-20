#include <stdio.h>
#include <stdlib.h>
#include <locale.h>



/*

1 - Preencher um vetor de 15 posições posições com valores aleatórios de 15 a 50. Construir um vetor B do
mesmo tipo, em que cada elemento de B deva ser o resultado do fatorial correspondente de cada elemento da matriz
A. Apresentar A e B

*/
int main()
{
    FILE * arquivo;
    int tam;
    double v[]; //vetor contendo os 64 numeros da série de fibonacci
    setlocale(LC_ALL, "portuguese");
    printf ( "%s\n", "EXERCICIO 1" );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );

    //abertura do arquivo
    if ((arquivo = fopen("C:/temp/bruno.txt","w")) == NULL) // modo de escrita ativo
    {
        printf("Erro de abertura! \n");
    }
    else
    {
        printf("Digite um numero inteiro: \n");
        scanf("%d",&tam);
        for(i=0; i<tam; i++) // criação do vetor aleatorio
        {
            vet[i]=rand()%11+75; //50-15 = 35  85-75 = 10
            printf("%5.2f \n",vet[i]);

        }
        printf("Vetor com fatorial \n");
        vetorFatorial(vet,15);
        //fechamento do arquivo

        fclose(arquivo);
    }
    system("pause");
    return 0;
}

