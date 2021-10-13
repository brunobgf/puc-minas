#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <time.h> //necessário p/ função time()

/*

10. Faça um programa para adivinhar um número escolhido pelo usuário, entre 1 e 1023. Indique ao
final quantas tentativas foram necessárias. O programa deverá localizar o número escolhido pelo
usuário em no máximo 10 tentativas!
Utilize a seguinte proposta. Pegue o valor intermediário e pergunte ao usuário se o número é
igual(=), maior(>) ou menor(<) que o que foi escolhido. Se for (=) implica que acertou! Se for maior
escolha agora o número intermediário entre o que foi perguntado e o último, caso contrário escolha o
intermediário entre o primeiro e o que foi perguntado, seguindo assim até acertar!
*/




int main()
{
    int max=1023, min=1, guess, counter=1;
    char input;
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL));
    printf ( "%s\n", "EXERCICIO 8 - Fazer um algoritmo que dado um numero de 4 dígitos (verifique se o número pertence a faixa) calcule e escreva se ele possui ou não esta característica." );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );
    guess = (max+min)/2;
    printf("Escolha um número entre 1 e 1023, o número inicial é o: \n");
    printf("%d ?", guess);




    while(counter<10)
    {
    printf(" O número é igual(=), maior(>) ou menor(<) que o que foi escolhido? \n");
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
                printf("Infelizmente não consegui advinhar :(");
            }

        }

        printf("\nO número é igual(=), maior(>) ou menor(<) que o que foi escolhido? \n");
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
