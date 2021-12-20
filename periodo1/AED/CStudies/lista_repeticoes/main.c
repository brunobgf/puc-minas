#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <time.h> //necess�rio p/ fun��o time()
void ex01();
void ex02();
void ex03();
void ex04();
void ex05();
void ex06();
void ex07();
void ex08();
void ex09();
void ex10();
void menu();


/*

Exerc�cios referentes a Lista de Exerc�cios 03 - Estruturas De Repeti��o no C

Aluno: Bruno Gomes Ferreira

Data: 11/10/2021

*/

int main()
{
    setlocale(LC_ALL, "portuguese"); //permite usar car�cteres em portugues
    menu(); //chamar a fun��o menu
    return 0;
}



void menu()
{

    int op;
    printf("Escolha o n�mero referente aos exerc�cios no menu para serem executados:\n");
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
        case 3:
            ex03();
            break;
        case 4:
            ex04();
            break;
        case 5:
            ex05();
            break;
        case 6:
            ex06();
            break;
        case 7:
            ex07();
            break;
        case 8:
            ex08();
            break;
        case 9:
            ex09();
            break;
        case 10:
            ex10();
            break;
        default:
            printf("Codigo invalido, tente novamente");
        }

        printf("Escolha o n�mero referente aos exerc�cios no menu para serem executados:\n");
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
    int num, qtdPares=0, qtdImpares=0;
    setlocale(LC_ALL, "portuguese"); //permite usar car�cteres em portugues
    printf ( "%s\n", "EXERCICIO 1 - Fa�a um algoritmo que leia um conjunto de n�meros (X) e imprima a quantidade de n�meros pares(QPares) e a quantidade de n�meros impares (QImpares) lidos. 9999 para o programa " );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );
    printf("Escolha um numero:\n");
    scanf("%d", &num);


    while (num < 9999)
    {
        //Verifica��o se � par ou impar atrav�s do %
        if (num%2==0)
        {
            qtdPares++;
        }
        else
        {
            if(num%2!=0)
            {
                qtdImpares++;
            }


        }
        printf("Escolha um numero:\n");
        scanf("%d", &num);
    }
    printf("Quantidade de n�meros pares � %d, e a quantidade de n�meros impares �: %d\n", qtdPares, qtdImpares);

    // encerrar
    printf ( "\n\nApertar ENTER para encerrar." );
    fflush ( stdin );
    getchar( );
}




/*

TABELA DE TESTES - Quest�o 1

Entrada esperada||   Sa�da esperada || Sa�da do programa || Obs
    3,3,2,1,9999  Pares:1 Impares:3    Pares:1 Impares:3
   -3,-2,-1,9999  Pares:1 Impares:2    Pares:1 Impares:2

*/

/*

2 - Fa�a um programa que leia um conjunto indeterminado de n�meros inteiros positivos e imprima o maior, o
menor e a m�dia aritm�tica desse conjunto de dados. (Flag -1).
Execute este programa para os seguintes valores
1.1,2,3,-1
2.3,2,1,-1
3.1,3,2,-1

*/
void ex02()
{
    int num, maiorNum, menorNum, count=0, sum=0;
    float avg;
    setlocale(LC_ALL, "portuguese");
    printf ( "%s\n", "EXERCICIO 2 - Fazer um algoritmo que dado um numero de 4 d�gitos (verifique se o n�mero pertence a faixa) calcule e escreva se ele possui ou n�o esta caracter�stica." );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );
    printf("Escolha um numero inteiro positivo (-1 Encerra o programa):\n");
    scanf("%d", &num);
    maiorNum = num;
    menorNum = num;

    while (num != -1)
    {
        if (num>0)
        {
            count++;
            sum = sum+num; //calculo da soma dos numeros

            if (num>maiorNum)
            {
                maiorNum = num; //se input maior que o antigo maior numero, maiorNum recebe num
            }
            else
            {
                if(num<menorNum)
                {
                    menorNum = num;
                }
            }

        }
        else

        {

            printf("Escolha um n�mero positivo \n");
        }


        printf("Escolha um numero inteiro positivo(-1 Encerra o programa):\n");
        scanf("%d", &num);
    }
    avg = (float) sum/count; //calculo media
    printf("O menor n�mero foi: %d, O maior n�mero foi: %d, a m�dia dos n�meros escolhidos foi de: %5.2f \n", menorNum, maiorNum, avg);

    // encerrar
    printf ( "\n\nApertar ENTER para encerrar." );
    fflush ( stdin );
    getchar( );
}

/*

TABELA DE TESTES - Quest�o 2

Entrada esperada||        Sa�da esperada        ||    Sa�da do programa          || Obs
    1,2,3,-1        Menor: 1 Maior: 3 M�dia 2,00    Menor: 1 Maior: 3 M�dia 2,00
   3,2,1,-1         Menor: 1 Maior: 3 M�dia 2,00    Menor: 1 Maior: 3 M�dia 2,00
   1,2,3-1          Menor: 1 Maior: 3 M�dia 2,00    Menor: 1 Maior: 3 M�dia 2,00

*/

/*

3 - Escrever um algoritmo em Portugol, para calcular e imprimir o fatorial de um n�mero lido do teclado.
Ex. Fatorial de 5! = 5x4x3x2x1=120

*/


void ex03()
{
    int num, fat = 1, i;
    setlocale(LC_ALL, "portuguese");
    printf ( "%s\n", "EXERCICIO 3 - Escrever um algoritmo em Portugol, para calcular e imprimir o fatorial de um n�mero lido do teclado." );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );
    printf("Escolha um numero para o c�lculo de seu fatorial:\n");
    scanf("%d", &num);


    if(num>=0) //condi��o do numero ser positivo
    {
        for (i=1; i<=num; i++)
        {
            fat = fat*i;//fatorial recebe o index
        }
        printf("O fatorial de %d �: %d", num, fat);
    }
    else
    {
        printf("N�o existe fatorial de n�mero negativo");
    }

    // encerrar
    printf ( "\n\nApertar ENTER para encerrar." );
    fflush ( stdin );
    getchar( );
}
/*


TABELA DE TESTES - Quest�o 3

Entrada esperada||           Sa�da esperada             ||         Sa�da do programa                  || Obs
     0                   O fatorial de 0 � 1                      O fatorial de 0 � 1
     1                   O fatorial de 1 � 1                      O fatorial de 1 � 1
     5                   O fatorial de 5 � 120                    O fatorial de 5 � 120
     -5           N�o existe fatorial de n�mero negativo    N�o existe fatorial de n�mero negativo

*/

void ex04()
{
    int input, counter=0, denominador=1, numerador =1, sinal =1 ;
    float soma=0, fracao;
    setlocale(LC_ALL, "portuguese");
    printf ( "%s\n", "EXERCICIO 4 - Calcule a soma da s�rie" );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );
    printf("Escolha um numero:\n");
    scanf("%d", &input);

    while(counter<input)
    {
        fracao = (float) sinal*numerador/pow(denominador,3);
        soma = soma + fracao;
        denominador = denominador + 2;
        sinal = sinal*-1;
        counter = counter + 1;

    }

    printf("A soma dos termos da s�rie descrita �: %5.2f", soma);

    // encerrar
    printf ( "\n\nApertar ENTER para encerrar." );
    fflush ( stdin );
    getchar( );
}

/*

TABELA DE TESTES - Quest�o 4

Entrada esperada||           Sa�da esperada             ||         Sa�da do programa                  || Obs
     1                         0.97                                      0.97
     2                         0.97                                      0.97
     3                         0.97                                      0.97
     -5           N�o existe fatorial de n�mero negativo    N�o existe fatorial de n�mero negativo

*/


/*

5 - A s�rie de fibonacci � formada pela seq��ncia:
1, 1, 2, 3, 5, 8, 13, 21, 34, ...
Escreva um algoritmo que pe�a um n�mero N maior que 2. Gere e imprima a s�rie at� este n-�simo
termo.

*/

void ex05()
{
    int a=1, b=1, c, input, i;
    setlocale(LC_ALL, "portuguese");
    printf ( "%s\n", "EXERCICIO 5 - Escreva um algoritmo que pe�a um n�mero N maior que 2. Gere e imprima a s�rie at� este n-�simo termo" );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );
    printf("Escolha um numero maior que 2:\n");
    scanf("%d", &input);

    if(input>2)
    {
        printf("O primeiro termo �: %d \n", a);
        printf("O segundo termo �: %d \n", b);
        printf("Os proximos termos ser�o: \n");

        for(i=0; i<input-2; i++)
        {

            c = a + b; //termo auxiliar para fazer a soma dos termos anteriores
            printf("%d \n", c);
            a = b; //a recebe valor de b
            b = c; //b recebe valor de c

        }
    }
    else
    {
        printf("O n�mero deve ser maior que 2 \n");

    }

    // encerrar
    printf ( "\n\nApertar ENTER para encerrar." );
    fflush ( stdin );
    getchar( );

}


/*

TABELA DE TESTES - Quest�o 5

Entrada esperada||        Sa�da esperada        ||    Sa�da do programa          || Obs
    5                    1, 1, 2, 3, 5                 1, 1, 2, 3, 5
    1       O n�mero deve ser maior que 2     O n�mero deve ser maior que 2
    8         1, 1, 2, 3, 5, 8, 13, 21          1, 1, 2, 3, 5, 8, 13, 21

*/



/*

6 - Fazer um algoritmo para calcular o valor de s, dado por, sendo o valor de N dever� se lido do teclado
S = +1/N - 2/N-1 + 3/N-2 - 4/N-3... N/1
*/

void ex06()
{
    int input, counter=0, denominador, numerador, sinal =1 ;
    float soma=0, fracao;
    setlocale(LC_ALL, "portuguese");
    printf ( "%s\n", "EXERCICIO 6 - Fazer um algoritmo para calcular o valor de s, dado por, sendo o valor de N dever� se lido do teclado" );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );
    printf("Escolha um numero para calcular a soma da serie: \n");
    scanf("%d", &input);

    denominador = input;
    numerador = 1;
    fracao = 1/denominador;

    while(counter<input)
    {

        fracao = (float) sinal*numerador/denominador; //resolu��o de uma das fra�oes
        soma = soma + fracao; //soma serie
        numerador = numerador + 1; //mudan�a do numerador
        sinal = sinal*-1; //sinal da serie
        counter = counter + 1;
        denominador = input - counter; //mudan�a do denominador

    }

    printf("A soma dos termos da s�rie descrita �: %5.2f", soma);

    // encerrar
    printf ( "\n\nApertar ENTER para encerrar." );
    fflush ( stdin );
    getchar( );

}

/*

TABELA DE TESTES - Quest�o 6

Entrada esperada||        Sa�da esperada        ||    Sa�da do programa          || Obs
    4                        -2,92                        -2,92
    1                          1                              1
    2                         -1,50                        -1,50

*/



/*

7 - N�meros pal�ndromos s�o aqueles que escritos da direita para esquerda ou da esquerda para direita
tem o mesmo valor. Exemplo:929, 44, 97379. Fazer um algoritmo que imprima todos os n�meros
pal�ndromos de 10000 a 99999

*/

void ex07()
{
    int num,a, b, c, d, e, f, g, h, i, inverso;
    setlocale(LC_ALL, "portuguese");
    printf ( "%s\n", "EXERCICIO 5 - Escreva um algoritmo que pe�a um n�mero N maior que 2. Gere e imprima a s�rie at� este n-�simo termo" );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );


    for(num=10000; num<99999; num++)
    {
        a = num%10; //para extrair o ultimo numero Ex: 97379 = 9

        b = num/10; //para extrair o ultimo numero 97379/10 = 9737

        c = b%10;// 9737%10 =>  7

        d = b/10; // 9737/10 => 973

        e = d%10;

        f = d/10;

        g = f%10;

        h = f/10;

        i = h%10;

        inverso = a*10000 + c*1000 + e*100 + g*10 + i; //calculo do n�mero inverso utilizando os restos das variaveis acima

        //Verificando se o n�mero digitado � palindromo ou n�o
        if(num==inverso)
        {
            printf("O %d � n�mero � palindromo j� que o seu inverso � %d\n", num, inverso);
        }
    }


// encerrar
    printf ( "\n\nApertar ENTER para encerrar." );
    fflush ( stdin );
    getchar( );

}



/*

8 - O numero 3025 possui a seguinte caracter�stica:
30 + 25 = 55
55^2 = 3025
Quantos e quais s�o os n�meros de 4 d�gitos possuem essa caracter�stica?

*/

void ex08()
{
     int a, b, c, soma, somaElevada, counter=0;
    setlocale(LC_ALL, "portuguese");
    printf ( "%s\n", "EXERCICIO 8 - Fazer um algoritmo que dado um numero de 4 d�gitos (verifique se o n�mero pertence a faixa) calcule e escreva se ele possui ou n�o esta caracter�stica." );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );


    for(a=1000; a<9999; a++)
    {
        b = a/100; //para extrair os dois primeiros n�meros Ex: 3025/100 = 30
        c = a%100; //para extrair os dois ultimos numeros (RESTO) Ex 3025%100 = 25
        soma = b + c; //soma das extra��es que foram feitas
        somaElevada = pow(soma,2); //eleva-se o resultado

        if (somaElevada == a) //Condi��o se o n�mero possu� aquela caracteristica
        {
            printf("O n�mero poss�i esta caracter�stica, %d = %d \n", a, somaElevada);
            counter++;
        }
    }

    printf("A quantidade de n�meros de 4 d�gitos que seguem esse padr�o � de: %d \n", counter);

    // encerrar
    printf ( "\n\nApertar ENTER para encerrar." );
    fflush ( stdin );
    getchar( );

}

/*

TABELA DE TESTES - Quest�o 8

Entrada esperada||   Sa�da esperada || Sa�da do programa || Obs
      3025            3025 = 3025         3025 = 3025
      3125            3125 != 3136        3125 != 3136
      4025            4025 != 4225        4025 != 4225

*/

/*

9. Fa�a um programa para um jogo de cara ou coroa. Neste caso, o jogador escolhe cara ou coroa (0 �
cara e 1 � para coroa) mostre ao final de 10 tentativas, quantas foram certas e quantas erradas.
(utilize o comando - para que o computador escolha o resultado).

*/

void ex09()
{
    int input, n, acertos=0, erros=0, counter=0, jogadaMaquina;
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL)); //para gerar numero aleatorio
    printf ( "%s\n", "EXERCICIO 9 - Fa�a um programa para um jogo de cara ou coroa.." );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );
    printf("Escolha cara ou coroa, cara=0 coroa=1:\n");
    scanf("%d", &input);

    while(counter<10)
    {

        for (n = 0; n < 1; n++)
        {
            /* gerando valores aleat�rios entre 0 e 1 */
            jogadaMaquina = rand() % 2;
        }
        printf("%d \n", jogadaMaquina);
        //verifica��o acertos e erros
        if(input==jogadaMaquina)
            {
                printf("Acertou!\n");
                acertos++;
            }
            else
            {
                printf("Errou!\n");
                erros++;
            }

        counter++;
        printf("Escolha cara ou coroa, cara=0 coroa=1:\n");
        scanf("%d", &input);
    }

    printf("Acertos: %d, Erros: %d\n", acertos, erros);

// encerrar
    printf ( "\n\nApertar ENTER para encerrar." );
    fflush ( stdin );
    getchar( );

}




/*

OBS: AVALIAR O EX 10 NO OUTRO ARQUIVO, NESTE EM ESPECIFICO EST� DANDO ALGUM ERRO AO TER PASSADO DE INT PARA VOID

*/

/*

10. Fa�a um programa para adivinhar um n�mero escolhido pelo usu�rio, entre 1 e 1023. Indique ao
final quantas tentativas foram necess�rias. O programa dever� localizar o n�mero escolhido pelo
usu�rio em no m�ximo 10 tentativas!
Utilize a seguinte proposta. Pegue o valor intermedi�rio e pergunte ao usu�rio se o n�mero �
igual(=), maior(>) ou menor(<) que o que foi escolhido. Se for (=) implica que acertou! Se for maior
escolha agora o n�mero intermedi�rio entre o que foi perguntado e o �ltimo, caso contr�rio escolha o
intermedi�rio entre o primeiro e o que foi perguntado, seguindo assim at� acertar!
*/

void ex10()
{
    int max=1023, min=1, guess, counter=1;
    char input;
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL));
    printf ( "%s\n", "EXERCICIO 10 - Fa�a um programa para adivinhar um n�mero escolhido pelo usu�rio, entre 1 e 1023." );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );
    guess = (max+min)/2;
    printf("Escolha um n�mero entre 1 e 1023, o n�mero inicial � o: \n");
    printf("%d ?", guess);




    while(counter<10)
    {
        printf(" O n�mero � igual, digite: (==), maior: (>>) ou menor: (<<) que o que foi escolhido? \n");
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
            if(counter==10)
            {
                printf("Infelizmente n�o consegui advinhar :(");
            }

        }

        printf(" O n�mero � igual(=), maior(>) ou menor(<) que o que foi escolhido? \n");
        scanf("%c", &input);
        counter++;
        printf("\nTentativa: %d\n",counter);



    }

printf("Levou-se %d tentativas\n", counter);



// encerrar
    printf ( "\n\nApertar ENTER para encerrar." );
    fflush ( stdin );
    getchar( );

}

