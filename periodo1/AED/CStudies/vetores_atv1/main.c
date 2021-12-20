#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

void vetorFatorial(double *v, double tam); //foi utilizado double porque os números obtidos são muito grandes

int main()
{

    double vet[15];
    int i;
    srand(time(NULL));
    setlocale(LC_ALL, "portuguese");
    printf ( "%s\n", "EXERCICIO 1 - Preencher um vetor de 15 posições posições com valores aleatórios de 15 a 50. Construir um vetor B domesmo tipo, em que cada elemento de B deva ser o resultado do fatorial correspondente de cada elemento da matrizA. Apresentar A e B" );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );
    printf("Vetor original \n");
    for(i=0; i<15; i++) // criação do vetor aleatorio
    {
        vet[i]=rand()%36+15; //50-15 = 35
        printf("%5.2f \n",vet[i]);

    }
    printf("Vetor com fatorial \n");
    vetorFatorial(vet,15);
}

void vetorFatorial(double *v, double tam)
{
    int i,j;
    double vet2[15],fat=1;
    for(i=0; i<15; i++)
    {
        fat=1;
        for(j=1; j<=v[i] ; j++)
        {
            fat=fat*j; // calculo do fatorial p/ cada [i] do vetor
        }

        vet2[i]=fat;
        printf("%5.2f \n",vet2[i]);
    }



}
