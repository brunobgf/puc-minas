#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
void contaParImpar(int *vet1,int tam);

/*

4 - Preencher um vetor A de x elementos (x dever� ser lido do teclado) com valores aleat�rios de vi a vf
(lidos do teclado). Crie um vetor ParImpar de 2 posi��es e armazene no �ndice 0 quantos elementos de A s�o par e
no �ndice 1 quantos elementos de A s�o �mpar. Apresentar o vetor ParImpar. Obs.: n�o utilize nenhum comando
condicional(if,switch).

*/

int main()
{
    int i,vetA[5],num;
    setlocale(LC_ALL, "portuguese");
    printf ( "%s\n", "EXERCICIO 4" );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );
    printf("Escolha o tamanho do vetor:\n");
    scanf("%d", &num);

    for(i=0; i<num; i++)
    {
        printf("Escolha um numero para popular o vetor 1:\n");
        scanf("%d", &vetA[i]);
    }

    printf("O numero de pares e impares s�o respectivamente:\n");
    contaParImpar(vetA,5);
    return 0;
}

void contaParImpar(int *vet1,int tam)
{
    int i, odd=0,even=0, vetParImpar[2];

    for(i=0; i<tam; i++)
    {
        (vet1[i] & 1 && printf("odd \n",odd++))|| printf("even \n",even++);
    }
    vetParImpar[1]=odd;
    vetParImpar[0]=even;
    for(i=0; i<2; i++)
    {
        printf("%d ",vetParImpar[i]);
    }

}
