#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int somaNumeros(int);

int main()
{
    int num, soma = 0, i;
    setlocale(LC_ALL, "portuguese");
    printf ( "%s\n", "EXERCICIO 3 - Escrever um algoritmo em Portugol, para calcular e imprimir o fatorial de um número lido do teclado." );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );
    printf("Escolha um numero para o cálculo de seu fatorial:\n");
    scanf("%d", &num);

    for (i=1; i<=num; i++)
    {
        soma = soma+i;
    }

    printf("%d \n", soma);

    printf("%d \n", somaNumeros(num));

    // encerrar
    printf ( "\n\nApertar ENTER para encerrar." );
    fflush ( stdin );
    getchar( );
    return 0;
}

int somaNumeros(int num)
{
    int soma=0;
    if(num==1)
    {
        soma=1;
    }
    else
    {
        soma = somaNumeros(num-1);
        soma = num + soma;
    }

    return soma;

}
