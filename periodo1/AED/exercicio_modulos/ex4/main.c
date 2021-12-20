#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
void calculaSerie(int v1, float *soma);

int main()
{
    int input;
    float soma=0;
    setlocale(LC_ALL, "portuguese");
    printf ( "%s\n", "EXERCICIO 4 - passando N como parâmetro e retornando o valor de S em um outro parâmetro" );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );
    printf("Escolha um numero N de termos para calcular a soma da serie: \n");
    scanf("%d", &input);
    calculaSerie(input, &soma);
    printf("A soma dos termos da série descrita é: %5.2f", soma);

    // encerrar
    printf ( "\n\nApertar ENTER para encerrar." );
    fflush ( stdin );
    getchar( );

}

void calculaSerie(int v1, float *soma)
{

    int a=1,b=1, counter=0, denominador=2, numerador, sinal =1;
    float fracao, fracao1,fracao2;

    fracao1 = (float) a/denominador;

    fracao2 = (float) b/(denominador+2);

    if (v1>2)
    {
        *soma = fracao1+fracao2;
        sinal=-1;
        denominador=4;

        while(counter<v1-2)
        {
            numerador = a+b;//mudança do numerador
            denominador = denominador+2;   //mudança do denominador
            fracao = (float) sinal*numerador/denominador; //resolução de uma das fraçoes
            *soma = *soma + fracao; //soma serie
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
            *soma = fracao1+fracao2;
        }
        else
        {
            *soma=fracao1;
        }

    }
}

/*

TABELA DE TESTES

Entrada esperada||        Saída esperada        ||    Saída do programa          || Obs
    3                          0,42                        0,42
    1                          0,50                        0,50
    5                          0,29                        0,29

*/
