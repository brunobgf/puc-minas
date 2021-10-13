#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <locale.h>


/*

Aluno: Bruno Gomes Ferreira

Data: 12/10/2021

Lista referente ao estudo das Strings

2 – Ler um string de no máximo 50 caracteres e contar quantas letras A essa palavra possui.
*/

int main()
{
    int i,counter=0;
    char word[50];
    setlocale(LC_ALL, "portuguese");
    printf ( "%s\n", "EXERCICIO 2 – Ler um string de no máximo 50 caracteres e contar quantas letras A essa palavra possui." );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );
    printf("Digite uma palavra para contar o número de A's \n");
    gets(word); //lê uma string do teclado


    // word[i]!=NULL garante que irá percorrer a string

    for(i=0; word[i]!= '\0'; i++)
    {

        if (word[i]=='a')
        {
            counter++;
        }
        else
        {
            if (word[i]=='A')
            {
                counter++;
            }


        }
    }

    printf("A quantidade de letras A foi de: %d \n", counter);


    // encerrar
    printf ( "\n\nApertar ENTER para encerrar." );
    fflush ( stdin );
    getchar( );
    return 0;
}

/*

TABELA DE TESTES - Questão 2

Entrada esperada||   Saída esperada || Saída do programa || Obs
      banana             3 A's                3 A's
      pera                1 A                 1 A
      pdf                 0 A                 0 A

*/
