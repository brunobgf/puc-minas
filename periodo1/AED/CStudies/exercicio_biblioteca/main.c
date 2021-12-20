#include "mb_bruno.h"

int main()
{
    int idade;
    setlocale(LC_ALL, "portuguese");
    printf ( "%s\n", "PROVA - EXERCICIO 1" );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );
    printf("Digite uma idade para saber a categoria do nadador:");
    scanf("%d",&idade);

    categoriaNadador(idade);
    return 0;
}



