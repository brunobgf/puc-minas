#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <locale.h>


/*

Aluno: Bruno Gomes Ferreira

Data: 12/10/2021

Lista referente ao estudo das Strings

3 � Ler uma string de no m�ximo 50 caracteres e indicar quais as posi��es da letra A nessa palavra.

*/

int main()
{
    int i;
    char word[50];
    setlocale(LC_ALL, "portuguese");
    printf ( "%s\n", "EXERCICIO 3 � Ler uma string de no m�ximo 50 caracteres e indicar quais as posi��es da letra A nessa palavra." );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );
    printf("Digite uma palavra para indicar as posi��es da letra A na palavra \n");
    gets(word); //l� uma string do teclado


    // word[i]!=NULL garante que ir� percorrer a string

    for(i=0; word[i]!= '\0'; i++)
    {

        if (word[i]=='a')
        {
            printf("A letra ''a'' foi achada na posi��o %d\n ", i); //acessa a posi��o da letra a
        }
        else
        {
            if (word[i]=='A')
            {
                printf("A letra ''A'' foi achada na posi��o %d\n ", i);
            }


        }
    }

    // encerrar
    printf ( "\n\nApertar ENTER para encerrar." );
    fflush ( stdin );
    getchar( );
    return 0;
}

s
