#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> //para permitir a função toupper

#include <locale.h>


/*

Aluno: Bruno Gomes Ferreira

Data: 12/10/2021

Lista referente ao estudo das Strings

6 - Ler uma string de no máximo 50 caracteres e mostrar quantas letras possui e quantos caracteres são números e
quantos não são nem números nem letras.

*/

int main()
{
    int i,qtdLetras=0, qtdNumeros = 0, qtdEspeciais=0;
    char word[50];
    setlocale(LC_ALL, "portuguese");
    printf ( "%s\n", "EXERCICIO 6 – Ler uma string de no máximo 50 caracteres e mostrar quantas letras possui e quantos caracteres são números e quantos não são nem números nem letras." );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );
    printf("Digite uma palavra: \n");
    gets(word); //lê uma string do teclado



    for(i=0; word[i]!= '\0'; i++)
    {

        if ((word[i] >= 'a' && word[i] <= 'z') || (word[i] >= 'A' && word[i] <= 'Z'))
        {
            qtdLetras++; //quantidade de letras recebe mais um

        } else {

            if(word[i] >= '0' && word[i] <= '9') {
                    qtdNumeros++; //quantidade de numeros recebe mais um
            }

            else {
                qtdEspeciais++;  //quantidade de caracteres especiais recebe mais um
            }
        }
    }

    printf("Quantidade de letras: %d, quantidade de números: %d, quantidade de carácters especiais: %d\n", qtdLetras, qtdNumeros, qtdEspeciais);


// encerrar
    printf ( "\n\nApertar ENTER para encerrar." );
    fflush ( stdin );
    getchar( );
    return 0;
}

/*

TABELA DE TESTES - Questão 6

Entrada esperada||               Saída esperada                          ||             Saída do programa                      || Obs
      banana123-          6 letras, 3 numeros, 1 caracter especial       6 letras, 3 numeros, 1 caracter especial

*/
