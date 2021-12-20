#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
void ex01();
void ex02();
void menu();

/*

Exercícios referentes a Lista de Exercícios 04 - Manipulação de Strings no C

Aluno: Bruno Gomes Ferreira

Data: 12/10/2021

*/

int main()
{
    setlocale(LC_ALL, "portuguese"); //permite usar carácteres em portugues
    menu(); //chamar a função menu
    return 0;
}

void menu()
{

    int op;
    printf("Escolha o número referente aos exercícios no menu para serem executados:\n");
    printf("1 - Exercicio 1 \n");
    printf("2 - Exercicio 2 \n");
    printf("3 - Exercicio 3 \n");
    printf("4 - Exercicio 4 \n");
    printf("5 - Exercicio 5 \n");
    printf("6 - Exercicio 6 \n");
    printf("7 - Exercicio 7 \n");
    printf("8 - Exercicio 8 \n");
    printf("9 - Exercicio 9 \n");
    printf("10 - Exercicio 10\n");
    printf("-1 Finaliza o programa\n");
    scanf("%d",&op);

    while(op!= -1)
    {
        //Estrutura switch-case para poder acessar o menu
        switch(op)
        {
        case 1:
            ex01();
            break;

        case 2:
            ex02();
            break;
        default:
            printf("Codigo invalido, tente novamente");
        }

        printf("Escolha o número referente aos exercícios no menu para serem executados:\n");
        printf("1 - Exercicio 1 \n");
        printf("2 - Exercicio 2 \n");
        printf("3 - Exercicio 3 \n");
        printf("4 - Exercicio 4 \n");
        printf("5 - Exercicio 5 \n");
        printf("6 - Exercicio 6 \n");
        printf("7 - Exercicio 7 \n");
        printf("8 - Exercicio 8 \n");
        printf("9 - Exercicio 9 \n");
        printf("10 - Exercicio 10\n");
        printf("-1 Finaliza o programa\n");
        scanf("%d",&op);
    }
}

void ex01()
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
}

/*

2 – Ler um string de no máximo 50 caracteres e contar quantas letras A essa palavra possui.
*/

void ex02()
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
}


