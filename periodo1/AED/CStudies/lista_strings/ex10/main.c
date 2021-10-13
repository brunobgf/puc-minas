#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> //para permitir a função toupper
#include<conio.h>

#include <locale.h>


/*

Aluno: Bruno Gomes Ferreira

Data: 12/10/2021

Lista referente ao estudo das Strings

10 - Ler uma string de no máximo 50 caracteres em seguida leia outra string de no máximo 3 caracteres, informe quantas
vezes a segunda string aparece na primeira string, e diga as posições iniciais em que ela aparece.

*/

int main()
{
    char str[50], sub[3];
    int count = 0, count1 = 0;
    int i, j, l1, l2;

    printf("\n Escolha uma string : ");
    gets(str);

    l1 = strlen(str);

    printf("\nEscolha uma substring : ");
    gets(sub);

    l2 = strlen(sub);

    for (i = 0; str[i] != '\0';)
    {
        j = 0;
        count = 0;
        while ((str[i] == sub[j]))
        {
            count++;
            i++;
            j++;

        }
        if (count == l2)
        {
            count1++;
            count = 0;
        }
        else
            i++;
    }
    printf("%s ocorre %d vezes em %s", sub, count1, str);


// encerrar
    printf ( "\n\nApertar ENTER para encerrar." );
    fflush ( stdin );
    getchar( );
    return 0;
}


/*

TABELA DE TESTES - Questão 10

Entrada esperada                    ||   Saída esperada    || Saída do programa || Obs
      String: banana  Substring: na      aparece 2 vezes       aparece 2 vezes
      pera                1 A                 1 A
      pdf                 0 A                 0 A

*/
