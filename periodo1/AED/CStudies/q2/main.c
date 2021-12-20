#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

/*
PROVA - EXERCICIO 2

Escrever uma fun��o que receba um valor e devolva no comando return um vetor de tamanho (valor) com elementos entre 01 e 15.Utilize a fun��o rand() para preencher o vetor.

Utilize o comando malloc para cria��o do vetor.

Escreva uma fun��o que receba o vetor criado ,seu tamanho e um valor. Remova desse vetor todas as ocorr�ncias  valores menores que valor. Lembre-se de atualizar a vari�vel tamanho.

O programa principal dever� chamar as fun��es e mostrar o vetor antes e ap�s a chamada da fun��o que retira valor.
*/

int * preencheVetor(int tam);
void imprimeVetor(int *v, int tam);
void deletaMenores(int *v,int tam, int n1);

int main()
{
    int *vet;
    int tam;
    int n1;
    srand(time(NULL));
    setlocale(LC_ALL, "portuguese");
    printf ( "%s\n", "PROVA - EXERCICIO 2" );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );

    printf("Escolha um tamanho para o vetor:\n");
    scanf("%d",&tam);

    vet=preencheVetor(tam);
    printf("O vetor gerado ser�:\n");
    imprimeVetor(vet,tam);

    printf("Escolha um numero de compara��o:\n");
    scanf("%d",&n1);
    deletaMenores(vet,tam,n1);

    free(vet);
    vet=NULL;


    return 0;

}

int * preencheVetor(int tam)
{

    int *v;
    //aloca��o de mem�ria do vetor
    v=malloc(sizeof(int)*tam);
    for(int i=0; i<tam; i++)
    {

        v[i]=rand()%15+1; //15-1 = 14

    }

    return v;

}


void imprimeVetor(int *v, int tam)
{
    for(int i=0; i<tam; i++)
    {

        printf("[%d]=%d\n",i,v[i]);
    }
}

//a minha ideia nessa quest�o foi ordenar os numeros de forma descrescente antes de utilizar o realloc
void deletaMenores(int *v,int tam, int n1)
{
    int i,j, temp=0,count=0,novoTamanho;

    for(i=0; i<tam; i++)
    {
        for(j=i+1; j<tam; j++)
        {

            if (v[i] < v[j])
            {
                temp = v[i]; //variavel temporaria recebe v[i]
                v[i] = v[j]; //v[i] recebe o valor de v[j]
                v[j] = temp; //v[j] recebe o valor de v[i]
            }
        }
    }
    for(i=0; i<tam; i++)
    {
        if(v[i]<n1)
        {
            count++; //se v[i] for menor que o numero escolhido contador ++
        }
    }
    novoTamanho=tam-count; //novoTamanho = tamanho original - contador contendo qtd de numeros menores que o escolhido
    tam=novoTamanho; //tam � atualizado com o valor do novo tamanho

    v=realloc(v,tam*sizeof(int)); //realloc utilizando o novo tamanho, sendo assim ir� diminuir e deletar os numeros menores que o escolhido
    printf("Novo vetor:\n");
    for(i=0; i<tam; i++)
    {
        printf("[%d]=%d\n",i,v[i]);
    }
}
