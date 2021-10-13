#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> //para permitir a fun��o toupper

#include <locale.h>


/*

Aluno: Bruno Gomes Ferreira

Data: 12/10/2021

Lista referente ao estudo das Strings

7 � Ler uma string de no m�ximo 50 caracteres e criar uma nova string com seu inverso, isso � a ultima letra da primeira
string ser� a primeira na nova string e assim sucessivamente

*/

int main()
{
    int i;
    char word[50], revWord[50] ;
    char temp;
    setlocale(LC_ALL, "portuguese");

    printf ( "%s\n", "EXERCICIO 7 � Ler uma string de no m�ximo 50 caracteres e criar uma nova string com seu inverso, isso � a ultima letra da primeira string ser� a primeira na nova string e assim sucessivamente" );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );
    printf("Digite uma palavra: \n");
    gets(word); //l� uma string do teclado
    printf("A string original �: %s \n", word);

    size_t size = strlen(word); //tamanhho da string digitada

    for(i=0; i < size/2; i++)
    {
        temp = word[i]; //armazena o char inicial
        word[i] = word[size-i-1];//troca pelo char da ponta oposta
        word[size-i-1] = temp; //armazena o char inicial

    }

    printf("A string reversa �: %s\n", word);


// encerrar
    printf ( "\n\nApertar ENTER para encerrar." );
    fflush ( stdin );
    getchar( );
    return 0;
}

/*

TABELA DE TESTES - Quest�o 7

Entrada esperada||   Sa�da esperada || Sa�da do programa || Obs
    bruno                 onurb             onurb

*/
