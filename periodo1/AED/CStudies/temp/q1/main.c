#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

float * preencheVetor(int tam);
void imprimeVetor(float *v, int tam);

int main()
{
    int tam;
    float *vet,linhaArq;
    int visited = -1;
    FILE *arquivo, *arquivo2;

    setlocale(LC_ALL, "portuguese");
    printf ( "%s\n", "EXERCICIO 1 - PROVA 3" );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );

    printf("Escolha um tamanho para o vetor:\n");
    scanf("%d",&tam);
    vet=preencheVetor(tam);
    printf("O vetor gerado será:\n");
    imprimeVetor(vet,tam);

    system("pause");

    return 0;
}

float * preencheVetor(int tam)
{
    float *v;
    FILE * arquivo;
    //alocação de memória do vetor
    v=malloc(sizeof(float)*tam);

    if ((arquivo = fopen("C:/temp/bruno.txt","w")) == NULL) // modo de escrita ativo
    {
        printf("Erro de abertura! \n");
    }
    else
    {
        for(int i=0; i<tam; i++)
        {

            v[i]=rand()%11+75; //85-75 = 10
            //salva no arquivo a série
            fprintf(arquivo,"%5.2f\n", v[i]);

        }

        //fechamento do arquivo
        fclose(arquivo);
    }

    return v;

}

void imprimeVetor(float *v, int tam)
{
    for(int i=0; i<tam; i++)
    {
        printf("[%d]=%5.2f\n",i,v[i]);
    }
}

