#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
float calculaSerie(int v1);

int main()
{
    int input;
    float s;
    setlocale(LC_ALL, "portuguese");
    printf ( "%s\n", "EXERCICIO 6 - função passando N como parametro e retornando S" );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );
    printf("Escolha um numero N de termos para calcular a soma da serie: \n");
    scanf("%d", &input);

    s= calculaSerie(input);

    printf("A soma dos termos da série descrita é: %5.2f", s);

    // encerrar
    printf ( "\n\nApertar ENTER para encerrar." );
    fflush ( stdin );
    getchar( );

}

float calculaSerie(int v1)
{

    int a=1,b=1, counter=0, denominador=2, numerador, sinal =1;
    float fracao, fracao1,fracao2, soma=0;

    fracao1 = (float) a/denominador;

    fracao2 = (float) b/(denominador+2);

    if (v1>2)
    {
        soma = fracao1+fracao2;
        sinal=-1;
        denominador=4;

        while(counter<v1-2)
        {
            numerador = a+b;//mudança do numerador
            denominador = denominador+2;   //mudança do denominador
            fracao = (float) sinal*numerador/denominador; //resolução de uma das fraçoes
            soma = soma + fracao; //soma serie
            a=b; //a recebe valor de b
            b=numerador; //b recebe valor do numerador
            sinal = sinal*-1; //sinal da serie
            counter = counter + 1;
        }
    }
    else
    {
        if (v1==2)
        {
            soma = fracao1+fracao2;
        }
        else
        {
            soma=fracao1;
        }

    }

    return soma;

}

/*

TABELA DE TESTES

Entrada esperada||        Saída esperada        ||    Saída do programa          || Obs
    3                          0,42                        0,42
    1                          0,50                        0,50
    5                          0,29                        0,29

*/
