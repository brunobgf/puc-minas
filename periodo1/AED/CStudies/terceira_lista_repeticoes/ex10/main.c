#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <time.h> //necess�rio p/ fun��o time()

/*

10. Fa�a um programa para adivinhar um n�mero escolhido pelo usu�rio, entre 1 e 1023. Indique ao
final quantas tentativas foram necess�rias. O programa dever� localizar o n�mero escolhido pelo
usu�rio em no m�ximo 10 tentativas!
Utilize a seguinte proposta. Pegue o valor intermedi�rio e pergunte ao usu�rio se o n�mero �
igual(=), maior(>) ou menor(<) que o que foi escolhido. Se for (=) implica que acertou! Se for maior
escolha agora o n�mero intermedi�rio entre o que foi perguntado e o �ltimo, caso contr�rio escolha o
intermedi�rio entre o primeiro e o que foi perguntado, seguindo assim at� acertar!
*/




int main()
{
    int max=1023, min=1, guess, counter=1;
    char input;
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL));
    printf ( "%s\n", "EXERCICIO 8 - Fazer um algoritmo que dado um numero de 4 d�gitos (verifique se o n�mero pertence a faixa) calcule e escreva se ele possui ou n�o esta caracter�stica." );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );
    guess = (max+min)/2;
    printf("Escolha um n�mero entre 1 e 1023, o n�mero inicial � o: \n");
    printf("%d ?", guess);




    while(counter<10)
    {
    printf(" O n�mero � igual(=), maior(>) ou menor(<) que o que foi escolhido? \n");
    scanf("%c", &input);





        if(input=='>')
        {
            min = guess + 1;
            guess = (max+min)/2;
            printf("%d",guess);

        }
        else
        {
            if(input=='<')
            {
                max = guess-1;
                guess = (max+min)/2;
                printf("%d",guess);
            }
            else
            {
                if(input=='=')
                {
                    printf("Acerteeei!\n");
                    break;

                }

            }
            if(counter==10) {
                printf("Infelizmente n�o consegui advinhar :(");
            }

        }

        printf("\nO n�mero � igual(=), maior(>) ou menor(<) que o que foi escolhido? \n");
        scanf("%c", &input);
        counter++;
        printf("\nTentativa: %d\n",counter);



    }

printf("Levou-se %d tentativas\n", counter);



// encerrar
printf ( "\n\nApertar ENTER para encerrar." );
fflush ( stdin );
getchar( );
return 0;


}
