#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

/*
PROVA - EXERCICIO 2

Escrever uma função que receba um valor e devolva no comando return um vetor de tamanho (valor) com elementos entre 01 e 15.Utilize a função rand() para preencher o vetor.

Utilize o comando malloc para criação do vetor.

Escreva uma função que receba o vetor criado ,seu tamanho e um valor. Remova desse vetor todas as ocorrências  valores menores que valor. Lembre-se de atualizar a variável tamanho.

O programa principal deverá chamar as funções e mostrar o vetor antes e após a chamada da função que retira valor.
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
    printf("O vetor gerado será:\n");
    imprimeVetor(vet,tam);

    printf("Escolha um numero de comparação:\n");
    scanf("%d",&n1);
    deletaMenores(vet,tam,n1);

    free(vet);
    vet=NULL;


    return 0;

}

int * preencheVetor(int tam)
{

    int *v;
    //alocação de memória do vetor
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

//a minha ideia nessa questão foi ordenar os numeros de forma descrescente antes de utilizar o realloc
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
    tam=novoTamanho; //tam é atualizado com o valor do novo tamanho

    v=realloc(v,tam*sizeof(int)); //realloc utilizando o novo tamanho, sendo assim irá diminuir e deletar os numeros menores que o escolhido
    printf("Novo vetor:\n");
    for(i=0; i<tam; i++)
    {
        printf("[%d]=%d\n",i,v[i]);
    }
}
