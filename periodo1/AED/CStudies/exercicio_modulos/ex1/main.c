#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main()
{
    int input, a=1,b=1, counter=0, denominador=2, numerador, sinal =1 ;
    float soma=0, fracao, fracao1,fracao2;
    setlocale(LC_ALL, "portuguese");
    printf ( "%s\n", "EXERCICIO 1 - C�lculo da soma da s�rie em um programa pr�ncipal" );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );
    printf("Escolha um numero N de termos para calcular a soma da serie: \n");
    scanf("%d", &input);

    fracao1 = (float) a/denominador;

    fracao2 = (float) b/(denominador+2);

    if (input>2)
    {
        soma = fracao1+fracao2;
        sinal=-1;
        denominador=4;

        while(counter<input-2)
        {
            numerador = a+b;//mudan�a do numerador
            denominador = denominador+2;   //mudan�a do denominador
            fracao = (float) sinal*numerador/denominador; //resolu��o de uma das fra�oes
            soma = soma + fracao; //soma serie
            a=b; //a recebe valor de b
            b=numerador; //b recebe valor do numerador
            sinal = sinal*-1; //sinal da serie
            counter = counter + 1;
        }
    } else {
        if (input==2){
            soma = fracao1+fracao2;
        } else {
            soma=fracao1;
        }

    }


    printf("A soma dos termos da s�rie descrita �: %5.2f", soma);

    // encerrar
    printf ( "\n\nApertar ENTER para encerrar." );
    fflush ( stdin );
    getchar( );

}

/*

TABELA DE TESTES

Entrada esperada||        Sa�da esperada        ||    Sa�da do programa          || Obs
    3                          0,42                        0,42
    1                          0,50                        0,50
    5                          0,29                        0,29

*/
