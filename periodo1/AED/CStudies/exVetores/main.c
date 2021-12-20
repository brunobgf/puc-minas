#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    int vet[10],i,soma,somaPar=0,somaImp=0,escolha;
    setlocale(LC_ALL, "portuguese");
    for(i=0; i<10; i++)
    {
        printf("Escolha um numero para popular o vetor:\n");
        scanf("%d", &vet[i]);
    }
    printf("Escolha 1: Soma impares e 2:Soma pares\n");
    scanf("%d", &escolha);
    if(escolha==1)
    {
        for(i=0; i<10; i++)
        {
            if(vet[i]%2!=0)
            {
                somaImp=somaImp+vet[i];
            }
        }
        printf("%d", somaImp);

    }
    else
    {
        if (escolha==2)
        {

            for(i=0; i<10; i++)
            {
                if(vet[i]%2==0)
                {
                    somaPar=somaPar+vet[i];
                }
            }
            printf("%d", somaPar);
        }
    }

    return 0;
}

