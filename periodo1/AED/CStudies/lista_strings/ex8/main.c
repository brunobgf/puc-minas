#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> //para permitir a função toupper

#include <locale.h>


/*

Aluno: Bruno Gomes Ferreira

Data: 12/10/2021

Lista referente ao estudo das Strings

8 – Ler uma string de no máximo 50 caracteres e retire dessa string todos os espaços em branco. Utilize uma string
auxiliar.

*/

int main()
{
    int i,j=0;
    char word[50], newWord[50] ;
    char temp;
    setlocale(LC_ALL, "portuguese");

    printf ( "%s\n", "EXERCICIO 8 – Ler uma string de no máximo 50 caracteres e retire dessa string todos os espaços em branco. Utilize uma stringauxiliar" );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );
    printf("Digite uma palavra: \n");
    gets(word); //lê uma string do teclado
    printf("A string original é: %s \n", word);

    size_t size = strlen(word); //tamanhho da string digitada

    for(i=0; word[i] != '\0'; i++)
    {

        if(word[i] != ' '){
                newWord[j]=word[i];
                j++;

        }

    }

    newWord[j] = '\0';

    printf("A nova string sem espaços é: %s\n", newWord);


// encerrar
    printf ( "\n\nApertar ENTER para encerrar." );
    fflush ( stdin );
    getchar( );
    return 0;
}


/*

TABELA DE TESTES - Questão 8

Entrada esperada||   Saída esperada || Saída do programa || Obs
      muito bom           muitobom         muitobom

*/
