#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int calculaFib(int n);

int main()
{
    int n,i=0;
    setlocale(LC_ALL, "portuguese");
    printf ( "%s\n", "EXERCICIO 3 - Escrever um algoritmo em Portugol, para calcular e imprimir o fatorial de um número lido do teclado." );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );
    printf("Escolha um numero para o cálculo de seu fatorial:\n");
    scanf("%d", &n);


    for(i=0;i<n;i++)
    {
        printf("%d\n",calculaFib(i));

    }



    // encerrar
    printf ( "\n\nApertar ENTER para encerrar." );
    fflush ( stdin );
    getchar( );
    return 0;
}

int calculaFib(int i)
{
    int fib;

    if(i==1 || i==0)
    {
        fib=1;
    }

    else
    {
        fib=calculaFib(i-2)+calculaFib(i-1);

    }



    return fib;

}
