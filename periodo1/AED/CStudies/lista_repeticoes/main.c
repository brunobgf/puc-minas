#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <time.h> //necessário p/ função time()
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

Exercícios referentes a Lista de Exercícios 03 - Estruturas De Repetição no C

Aluno: Bruno Gomes Ferreira

Data: 11/10/2021

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
    int num, qtdPares=0, qtdImpares=0;
    setlocale(LC_ALL, "portuguese"); //permite usar carácteres em portugues
    printf ( "%s\n", "EXERCICIO 1 - Faça um algoritmo que leia um conjunto de números (X) e imprima a quantidade de números pares(QPares) e a quantidade de números impares (QImpares) lidos. 9999 para o programa " );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );
    printf("Escolha um numero:\n");
    scanf("%d", &num);


    while (num < 9999)
    {
        //Verificação se é par ou impar através do %
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
    printf("Quantidade de números pares é %d, e a quantidade de números impares é: %d\n", qtdPares, qtdImpares);

    // encerrar
    printf ( "\n\nApertar ENTER para encerrar." );
    fflush ( stdin );
    getchar( );
}




/*

TABELA DE TESTES - Questão 1

Entrada esperada||   Saída esperada || Saída do programa || Obs
    3,3,2,1,9999  Pares:1 Impares:3    Pares:1 Impares:3
   -3,-2,-1,9999  Pares:1 Impares:2    Pares:1 Impares:2

*/

/*

2 - Faça um programa que leia um conjunto indeterminado de números inteiros positivos e imprima o maior, o
menor e a média aritmética desse conjunto de dados. (Flag -1).
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
    printf ( "%s\n", "EXERCICIO 2 - Fazer um algoritmo que dado um numero de 4 dígitos (verifique se o número pertence a faixa) calcule e escreva se ele possui ou não esta característica." );
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

            printf("Escolha um número positivo \n");
        }


        printf("Escolha um numero inteiro positivo(-1 Encerra o programa):\n");
        scanf("%d", &num);
    }
    avg = (float) sum/count; //calculo media
    printf("O menor número foi: %d, O maior número foi: %d, a média dos números escolhidos foi de: %5.2f \n", menorNum, maiorNum, avg);

    // encerrar
    printf ( "\n\nApertar ENTER para encerrar." );
    fflush ( stdin );
    getchar( );
}

/*

TABELA DE TESTES - Questão 2

Entrada esperada||        Saída esperada        ||    Saída do programa          || Obs
    1,2,3,-1        Menor: 1 Maior: 3 Média 2,00    Menor: 1 Maior: 3 Média 2,00
   3,2,1,-1         Menor: 1 Maior: 3 Média 2,00    Menor: 1 Maior: 3 Média 2,00
   1,2,3-1          Menor: 1 Maior: 3 Média 2,00    Menor: 1 Maior: 3 Média 2,00

*/

/*

3 - Escrever um algoritmo em Portugol, para calcular e imprimir o fatorial de um número lido do teclado.
Ex. Fatorial de 5! = 5x4x3x2x1=120

*/


void ex03()
{
    int num, fat = 1, i;
    setlocale(LC_ALL, "portuguese");
    printf ( "%s\n", "EXERCICIO 3 - Escrever um algoritmo em Portugol, para calcular e imprimir o fatorial de um número lido do teclado." );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );
    printf("Escolha um numero para o cálculo de seu fatorial:\n");
    scanf("%d", &num);


    if(num>=0) //condição do numero ser positivo
    {
        for (i=1; i<=num; i++)
        {
            fat = fat*i;//fatorial recebe o index
        }
        printf("O fatorial de %d é: %d", num, fat);
    }
    else
    {
        printf("Não existe fatorial de número negativo");
    }

    // encerrar
    printf ( "\n\nApertar ENTER para encerrar." );
    fflush ( stdin );
    getchar( );
}
/*


TABELA DE TESTES - Questão 3

Entrada esperada||           Saída esperada             ||         Saída do programa                  || Obs
     0                   O fatorial de 0 é 1                      O fatorial de 0 é 1
     1                   O fatorial de 1 é 1                      O fatorial de 1 é 1
     5                   O fatorial de 5 é 120                    O fatorial de 5 é 120
     -5           Não existe fatorial de número negativo    Não existe fatorial de número negativo

*/

void ex04()
{
    int input, counter=0, denominador=1, numerador =1, sinal =1 ;
    float soma=0, fracao;
    setlocale(LC_ALL, "portuguese");
    printf ( "%s\n", "EXERCICIO 4 - Calcule a soma da série" );
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

    printf("A soma dos termos da série descrita é: %5.2f", soma);

    // encerrar
    printf ( "\n\nApertar ENTER para encerrar." );
    fflush ( stdin );
    getchar( );
}

/*

TABELA DE TESTES - Questão 4

Entrada esperada||           Saída esperada             ||         Saída do programa                  || Obs
     1                         0.97                                      0.97
     2                         0.97                                      0.97
     3                         0.97                                      0.97
     -5           Não existe fatorial de número negativo    Não existe fatorial de número negativo

*/


/*

5 - A série de fibonacci é formada pela seqüência:
1, 1, 2, 3, 5, 8, 13, 21, 34, ...
Escreva um algoritmo que peça um número N maior que 2. Gere e imprima a série até este n-ésimo
termo.

*/

void ex05()
{
    int a=1, b=1, c, input, i;
    setlocale(LC_ALL, "portuguese");
    printf ( "%s\n", "EXERCICIO 5 - Escreva um algoritmo que peça um número N maior que 2. Gere e imprima a série até este n-ésimo termo" );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );
    printf("Escolha um numero maior que 2:\n");
    scanf("%d", &input);

    if(input>2)
    {
        printf("O primeiro termo é: %d \n", a);
        printf("O segundo termo é: %d \n", b);
        printf("Os proximos termos serão: \n");

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
        printf("O número deve ser maior que 2 \n");

    }

    // encerrar
    printf ( "\n\nApertar ENTER para encerrar." );
    fflush ( stdin );
    getchar( );

}


/*

TABELA DE TESTES - Questão 5

Entrada esperada||        Saída esperada        ||    Saída do programa          || Obs
    5                    1, 1, 2, 3, 5                 1, 1, 2, 3, 5
    1       O número deve ser maior que 2     O número deve ser maior que 2
    8         1, 1, 2, 3, 5, 8, 13, 21          1, 1, 2, 3, 5, 8, 13, 21

*/



/*

6 - Fazer um algoritmo para calcular o valor de s, dado por, sendo o valor de N deverá se lido do teclado
S = +1/N - 2/N-1 + 3/N-2 - 4/N-3... N/1
*/

void ex06()
{
    int input, counter=0, denominador, numerador, sinal =1 ;
    float soma=0, fracao;
    setlocale(LC_ALL, "portuguese");
    printf ( "%s\n", "EXERCICIO 6 - Fazer um algoritmo para calcular o valor de s, dado por, sendo o valor de N deverá se lido do teclado" );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );
    printf("Escolha um numero para calcular a soma da serie: \n");
    scanf("%d", &input);

    denominador = input;
    numerador = 1;
    fracao = 1/denominador;

    while(counter<input)
    {

        fracao = (float) sinal*numerador/denominador; //resolução de uma das fraçoes
        soma = soma + fracao; //soma serie
        numerador = numerador + 1; //mudança do numerador
        sinal = sinal*-1; //sinal da serie
        counter = counter + 1;
        denominador = input - counter; //mudança do denominador

    }

    printf("A soma dos termos da série descrita é: %5.2f", soma);

    // encerrar
    printf ( "\n\nApertar ENTER para encerrar." );
    fflush ( stdin );
    getchar( );

}

/*

TABELA DE TESTES - Questão 6

Entrada esperada||        Saída esperada        ||    Saída do programa          || Obs
    4                        -2,92                        -2,92
    1                          1                              1
    2                         -1,50                        -1,50

*/



/*

7 - Números palíndromos são aqueles que escritos da direita para esquerda ou da esquerda para direita
tem o mesmo valor. Exemplo:929, 44, 97379. Fazer um algoritmo que imprima todos os números
palíndromos de 10000 a 99999

*/

void ex07()
{
    int num,a, b, c, d, e, f, g, h, i, inverso;
    setlocale(LC_ALL, "portuguese");
    printf ( "%s\n", "EXERCICIO 5 - Escreva um algoritmo que peça um número N maior que 2. Gere e imprima a série até este n-ésimo termo" );
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

        inverso = a*10000 + c*1000 + e*100 + g*10 + i; //calculo do número inverso utilizando os restos das variaveis acima

        //Verificando se o número digitado é palindromo ou não
        if(num==inverso)
        {
            printf("O %d é número é palindromo já que o seu inverso é %d\n", num, inverso);
        }
    }


// encerrar
    printf ( "\n\nApertar ENTER para encerrar." );
    fflush ( stdin );
    getchar( );

}



/*

8 - O numero 3025 possui a seguinte característica:
30 + 25 = 55
55^2 = 3025
Quantos e quais são os números de 4 dígitos possuem essa característica?

*/

void ex08()
{
     int a, b, c, soma, somaElevada, counter=0;
    setlocale(LC_ALL, "portuguese");
    printf ( "%s\n", "EXERCICIO 8 - Fazer um algoritmo que dado um numero de 4 dígitos (verifique se o número pertence a faixa) calcule e escreva se ele possui ou não esta característica." );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );


    for(a=1000; a<9999; a++)
    {
        b = a/100; //para extrair os dois primeiros números Ex: 3025/100 = 30
        c = a%100; //para extrair os dois ultimos numeros (RESTO) Ex 3025%100 = 25
        soma = b + c; //soma das extrações que foram feitas
        somaElevada = pow(soma,2); //eleva-se o resultado

        if (somaElevada == a) //Condição se o número possuí aquela caracteristica
        {
            printf("O número possúi esta característica, %d = %d \n", a, somaElevada);
            counter++;
        }
    }

    printf("A quantidade de números de 4 dígitos que seguem esse padrão é de: %d \n", counter);

    // encerrar
    printf ( "\n\nApertar ENTER para encerrar." );
    fflush ( stdin );
    getchar( );

}

/*

TABELA DE TESTES - Questão 8

Entrada esperada||   Saída esperada || Saída do programa || Obs
      3025            3025 = 3025         3025 = 3025
      3125            3125 != 3136        3125 != 3136
      4025            4025 != 4225        4025 != 4225

*/

/*

9. Faça um programa para um jogo de cara ou coroa. Neste caso, o jogador escolhe cara ou coroa (0 –
cara e 1 – para coroa) mostre ao final de 10 tentativas, quantas foram certas e quantas erradas.
(utilize o comando - para que o computador escolha o resultado).

*/

void ex09()
{
    int input, n, acertos=0, erros=0, counter=0, jogadaMaquina;
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL)); //para gerar numero aleatorio
    printf ( "%s\n", "EXERCICIO 9 - Faça um programa para um jogo de cara ou coroa.." );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );
    printf("Escolha cara ou coroa, cara=0 coroa=1:\n");
    scanf("%d", &input);

    while(counter<10)
    {

        for (n = 0; n < 1; n++)
        {
            /* gerando valores aleatórios entre 0 e 1 */
            jogadaMaquina = rand() % 2;
        }
        printf("%d \n", jogadaMaquina);
        //verificação acertos e erros
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

OBS: AVALIAR O EX 10 NO OUTRO ARQUIVO, NESTE EM ESPECIFICO ESTÁ DANDO ALGUM ERRO AO TER PASSADO DE INT PARA VOID

*/

/*

10. Faça um programa para adivinhar um número escolhido pelo usuário, entre 1 e 1023. Indique ao
final quantas tentativas foram necessárias. O programa deverá localizar o número escolhido pelo
usuário em no máximo 10 tentativas!
Utilize a seguinte proposta. Pegue o valor intermediário e pergunte ao usuário se o número é
igual(=), maior(>) ou menor(<) que o que foi escolhido. Se for (=) implica que acertou! Se for maior
escolha agora o número intermediário entre o que foi perguntado e o último, caso contrário escolha o
intermediário entre o primeiro e o que foi perguntado, seguindo assim até acertar!
*/

void ex10()
{
    int max=1023, min=1, guess, counter=1;
    char input;
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL));
    printf ( "%s\n", "EXERCICIO 10 - Faça um programa para adivinhar um número escolhido pelo usuário, entre 1 e 1023." );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );
    guess = (max+min)/2;
    printf("Escolha um número entre 1 e 1023, o número inicial é o: \n");
    printf("%d ?", guess);




    while(counter<10)
    {
        printf(" O número é igual, digite: (==), maior: (>>) ou menor: (<<) que o que foi escolhido? \n");
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
                printf("Infelizmente não consegui advinhar :(");
            }

        }

        printf(" O número é igual(=), maior(>) ou menor(<) que o que foi escolhido? \n");
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

