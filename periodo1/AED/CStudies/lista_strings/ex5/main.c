#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> //para permitir a fun��o toupper

#include <locale.h>


/*

Aluno: Bruno Gomes Ferreira

Data: 12/10/2021

Lista referente ao estudo das Strings

5 - Ler uma string de no m�ximo 50 caracteres e em seguida um caractere (entre A e z - consista se o caracter esta nesse
intervalo), mostrar quais as posi��es esse caractere (mai�scula ou min�scula) na string lida e quantas vezes ele apareceu.

*/

int main()
{
    int i,counter=0;
    char word[50];
    char searchWord;
    setlocale(LC_ALL, "portuguese");
    printf ( "%s\n", "EXERCICIO 5 � Ler uma string de no m�ximo 50 caracteres e em seguida um caractere,(entre A e z - consista se o caracter esta nesseintervalo), mostrar quais as posi��es esse caractere (mai�scula ou min�scula) na string lida e quantas vezes ele apareceu." );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );
    printf("Digite uma palavra: \n");
    gets(word); //l� uma string do teclado
    printf("Escolha um char para que o programa procure por ele: \n");
    searchWord = getchar(); //l� um caracter do teclado

    if((searchWord >= 'a' && searchWord <= 'z') || (searchWord >= 'A' && searchWord <= 'Z'))
    {
        // word[i]!=NULL garante que ir� percorrer a string

        for(i=0; word[i]!= '\0'; i++)
        {
            //toupper transforma em uppercase

            if (word[i]==searchWord || word[i]==toupper(searchWord))
            {
                counter++;
                printf("A letra %c foi achada na posi��o %d\n", searchWord, i); //acessa a posi��o da letra a

            }


        }


        printf("A quantidade de letras foi de: %d \n",  counter);

    }
    else
    {
        printf("O valor escolhido n�o pertence ao alfabeto. Tente novamente");

    }

// encerrar
    printf ( "\n\nApertar ENTER para encerrar." );
    fflush ( stdin );
    getchar( );
    return 0;
}


