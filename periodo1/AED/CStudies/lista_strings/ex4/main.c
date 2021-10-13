#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <locale.h>


/*

Aluno: Bruno Gomes Ferreira

Data: 12/10/2021

Lista referente ao estudo das Strings

4 – Ler uma string de no máximo 50 caracteres e em seguida um caractere, mostrar quais as posições esse caractere
aparece na string lida e quantas vezes ele apareceu.

*/

int main()
{
    int i,counter=0;
    char word[50];
    char searchWord;
    setlocale(LC_ALL, "portuguese");
    printf ( "%s\n", "EXERCICIO 4 – Ler uma string de no máximo 50 caracteres e em seguida um caractere, mostrar quais as posições esse caractere aparece na string lida e quantas vezes ele apareceu." );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );
    printf("Digite uma palavra: \n");
    gets(word); //lê uma string do teclado
    printf("Escolha um char para que o programa procure por ele: \n");
    searchWord = getchar(); //lê um caracter do teclado


    // word[i]!=NULL garante que irá percorrer a string

    for(i=0; word[i]!= '\0'; i++)
    {

        if (word[i]==searchWord || word[i]==searchWord)
        {
            counter++;
            printf("A letra %c foi achada na posição %d\n", searchWord, i); //acessa a posição da letra a

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

TABELA DE TESTES - Questão 3

Entrada esperada||   Saída esperada || Saída do programa                      || Obs
      banana           3 letras A posição 1,3,5       3 letras A posição 1,3,5
      pera              1 letra A posição 3             1 letra  A posição3

*/
