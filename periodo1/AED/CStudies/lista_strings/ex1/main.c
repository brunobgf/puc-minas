#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include<string.h>


/*

Aluno: Bruno Gomes Ferreira

Data: 12/10/2021

Lista referente ao estudo das Strings

1 - Leia um conjunto indeterminado de palavras e ao final (estipule você um flag) informe qual foi a maior palavra e a
menor palavra digitada, em tamanho e lexicograficamente
*/

int main()
{

    char word[50], maiorPalavra[50], menorPalavra[50],lexMaior[50],lexMenor[50];

    setlocale(LC_ALL, "portuguese");
    printf ( "%s\n", "EXERCICIO 1 - informe qual foi a maior palavra e a menor palavra digitada, em tamanho e lexicograficamente" );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );
    printf("Digite palavras, para finalizar o programa, digite => pare \n");
    gets(word); //lê uma string do teclado

    strcpy(maiorPalavra, word); //strcpy (string_destino,string_origem);  A função strcpy() copia a string-origem para a string- destino.
    strcpy(menorPalavra, word);
    strcpy(lexMenor,word);
    strcpy(lexMaior,word);

    // A função strcmp() compara a string 1 com a string 2. Se as duas forem idênticas a função retorna zero. Se elas forem diferentes a função retorna não-zero.
    //strcasecomp => Faz o mesmo que a strcmp porém não importa se é maiuscula ou minuscula, é ideal para procurar a string lexicograficamente

    while (strcasecmp(word,"pare") != 0)



    {
        //A função strlen() retorna o comprimento da string fornecida. O terminador nulo não é contado. Isto quer dizer que, de fato, o comprimento do vetor da string deve ser um a mais que o inteiro retornado por strlen().
        if(strlen(word)> strlen(maiorPalavra))
        {
            strcpy(maiorPalavra,word);

        }

        if(strlen(word)<strlen(menorPalavra))
        {
            strcpy(menorPalavra,word);

        }
        if(strcasecmp(word,lexMenor)<0)
        {
            strcpy(lexMenor,word);
        }
        if(strcasecmp(word,lexMaior)>0)
        {
            strcpy(lexMaior,word);
        }
        printf("\nDigite Uma palavra\n");
        gets(word); //para continuar perguntando no loop
    }
    printf(" Maior lex = %s, Menor lex = %s\n", lexMaior, lexMenor);
    printf("Maior palavra = %s,menor palavra = %s\n",maiorPalavra, menorPalavra);

    // encerrar
    printf ( "\n\nApertar ENTER para encerrar." );
    fflush ( stdin );
    getchar( );
    return 0;
}

/*

TABELA DE TESTES - Questão 1

Entrada esperada||           Saída esperada                                                               || Saída do programa ||
uva, biscoito, pera           maiorPalavra: biscoito, menorPalavra: uva maiorLex:uva menorLex: biscoito      maiorPalavra: biscoito, menorPalavra: uva maiorLex:uva menorLex: biscoito


*/
