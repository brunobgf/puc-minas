#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <locale.h>


/*

Aluno: Bruno Gomes Ferreira

Data: 12/10/2021

Lista referente ao estudo das Strings

4 � Ler uma string de no m�ximo 50 caracteres e em seguida um caractere, mostrar quais as posi��es esse caractere
aparece na string lida e quantas vezes ele apareceu.

*/

int main()
{
    int i,counter=0;
    char word[50];
    char searchWord;
    setlocale(LC_ALL, "portuguese");
    printf ( "%s\n", "EXERCICIO 4 � Ler uma string de no m�ximo 50 caracteres e em seguida um caractere, mostrar quais as posi��es esse caractere aparece na string lida e quantas vezes ele apareceu." );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );
    printf("Digite uma palavra: \n");
    gets(word); //l� uma string do teclado
    printf("Escolha um char para que o programa procure por ele: \n");
    searchWord = getchar(); //l� um caracter do teclado


    // word[i]!=NULL garante que ir� percorrer a string

    for(i=0; word[i]!= '\0'; i++)
    {

        if (word[i]==searchWord || word[i]==searchWord)
        {
            counter++;
            printf("A letra %c foi achada na posi��o %d\n", searchWord, i); //acessa a posi��o da letra a

        }


    }


printf("A quantidade de letras foi de: %d \n",  counter);


// encerrar
printf ( "\n\nApertar ENTER para encerrar." );
fflush ( stdin );
getchar( );
return 0;
}

/*

TABELA DE TESTES - Quest�o 3

Entrada esperada||   Sa�da esperada || Sa�da do programa                      || Obs
      banana           3 letras A posi��o 1,3,5       3 letras A posi��o 1,3,5
      pera              1 letra A posi��o 3             1 letra  A posi��o3

*/
