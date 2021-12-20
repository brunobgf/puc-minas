#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
void inverteVetor(int *vet1,int tam);

/*

3 - Preencher um vetor A de 20 elementos com valores aleatórios de vi a vf (lidos do teclado), em seguida
crie um procedimento que inverta os elementos armazenados. Ou seja, o primeiro elemento de A passará a ser o
ultimo, o segundo elemento passará a ser o penúltimo e assim por diante. Apresentar A.

*/

int main()
{
    int vetA[20],i;
    setlocale(LC_ALL, "portuguese");
    printf ( "%s\n", "EXERCICIO 3" );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );
    for(i=0; i<20; i++)
    {
        printf("Escolha um numero para popular o vetor 1:\n");
        scanf("%d", &vetA[i]);
    }

    printf("O inverso do vetor escolhido é:\n");
    inverteVetor(vetA,20);

    return 0;
}

void inverteVetor(int *vet1,int tam)
{
    int vetRev[20],i;

    for(i=0; i<tam; i++)
    {
        vetRev[i]=vet1[tam-i-1]; //5-0-1 = 4 => o vetor reverso receberá o index numero 4 do vetor original
    }
       for(i=0;i<tam;i++)
   {
      printf("%d ",vetRev[i]);
   }
}
