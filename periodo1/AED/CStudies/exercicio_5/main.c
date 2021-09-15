#include <stdio.h>  // para as entradas e saidas
#include <stdlib.h>
#include <stdbool.h> // para valores logicos
#include <locale.h> //para o codeblocks funcionar com o idioma portugues
#include <math.h> //funções matematicas

/*
5) Para cada um dos problemas a seguir, expresse um algoritmo que possa ser utilizado para solucionar, utilize o
Portugol e depois passe para a linguagem C – as respostas serão 1(verdadeiro) 0(falso)

01.) Ler um valor inteiro do teclado e dizer se é par

Aluno: Bruno Gomes Ferreira

Data: 10/09/2021

    */

int main()
{
    //Definição dos dados
    int num1, num2; //Variaveis números inteiros
    float numFloat1, numFloat2, extremoMenor, extremoMaior;//Variaveis números reais (float)
    char firstChar, secondChar, thirdChar; //Variaveis do tipo char
    bool v1 = true, v2 = true, v3 = true; //Verificadores booleanos
    setlocale(LC_ALL, "portuguese");

    printf ( "%s\n", "EXERCICIO 5.01.) Ler um valor inteiro do teclado e dizer se é par" );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" ); //mudança de linha
    printf("Escolha um numero inteiro para verificar se é par:\n");
    scanf("%d", &num1); //guarda a variável escolhida
    v1 = (num1%2==0); //teste se é par ou não
    printf ( "%s (%d) ? %d\n\n", "é par ", num1, v1 );

    printf ( "%s\n", "EXERCICIO 5.02.) Ler um valor inteiro do teclado e dizer se é ímpar" );
    printf ( "\n" );
    printf("Escolha um numero inteiro:\n");
    scanf("%d", &num1);
    v1 = (num1%2!=0); //teste se é impar
    printf ( "%s (%d) ? %d\n\n", "é impar ", num1, v1 );

    printf ( "%s\n", "EXERCICIO 5.03.) ler um valor inteiro do teclado e dizer se ímpar e maior que 100." );
    printf ( "\n" );
    printf("Escolha um numero inteiro:\n");
    scanf("%d", &num1);
    v1 = (num1%2!=0 && num1>100); //teste logico se impar e maior que 100
    printf ( "%s (%d) ? %d\n\n", "é impar e maior que 100 ", num1, v1 );

    printf ( "%s\n", "EXERCICIO 5.04.) ler um valor inteiro do teclado e dizer se é par e menor que 100, ou ímpar e maior que 100." );
    printf ( "\n" );
    printf("Escolha um numero inteiro:\n");
    scanf("%d", &num1);
    v1 =((num1%2==0 && num1 <100) || (num1%2!=0 && num1>100)); //teste se o número é par E menor que 100 OU impar e maior que 100
    printf ( "%s (%d) ? %d\n\n", "é par e menor que 100 OU é impar e maior que 100 ", num1, v1 );

    printf ( "%s\n", "EXERCICIO 5.05.) ler um valor inteiro do teclado e dizer se pertence ao intervalo aberto entre (25:75)." );
    printf ( "\n" );
    printf("Escolha um numero inteiro:\n");
    scanf("%d", &num1);
    v1 =((25<num1) && (num1<75)); //teste para comparação entre intervalos abertos em C
    printf ( "%s (%d) ? %d\n\n", "é um número entre 25 e 75 num (intervalo aberto) ", num1, v1 );

    printf ( "%s\n", "EXERCICIO 5.06.) ler um valor inteiro do teclado e dizer se pertence ao intervalo fechado entre [25:75]. " );
    printf ( "\n" );
    printf("Escolha um numero inteiro:\n");
    scanf("%d", &num1);
    v1 =((25<=num1) && (num1<=75)); //teste para comparação com intervalo fechado em C
    printf ( "%s (%d) ? %d\n\n", "é um número entre 25 e 75 num (intervalo fechado) ", num1, v1 );

    printf ( "%s\n", "EXERCICIO 5.07.) ler um valor inteiro do teclado e dizer se pertence aos intervalos fechados [15:45] ou [66:99]" );
    printf ( "\n" );
    printf("Escolha um numero inteiro:\n");
    scanf("%d", &num1);
    v1 =(((15<=num1) && (num1<=45)) || ((66<=num1) && (num1<=99))) ; //teste para comparação entre intervalos em C
    printf ( "%s (%d) ? %d\n\n", "pertence aos intervalos fechados [15:45] ou [66:99] ", num1, v1 );

    printf ( "%s\n", "EXERCICIO 5.08.) ler dois valores inteiros do teclado e dizer se o primeiro é par e o segundo é ímpar" );
    printf ( "\n" );
    printf("Escolha o primeiro numero inteiro:\n");
    scanf("%d", &num1);
    printf("Escolha o segundo numero inteiro:\n");
    scanf("%d", &num2);
    v1 =(num1%2==0); //teste num1 ser par
    v2 =(num2%2!=0); //teste num2 ser impar
    printf ( "%s (%d) ? %d %s (%d) ? %d \n\n", "o primeiro número é par ", num1, v1, "o segundo número é impar", num2, v2 );

    printf ( "%s\n", "EXERCICIO 5.09.) ler dois valores inteiros do teclado e dizer se o primeiro é par e positivo, e o segundo é ímpar e negativo." );
    printf ( "\n" );
    printf("Escolha o primeiro numero inteiro:\n");
    scanf("%d", &num1);
    printf("Escolha o segundo numero inteiro:\n");
    scanf("%d", &num2);
    v1 =(num1%2==0 && num1>0); //teste num1 ser par e positivo
    v2 =(num2%2!=0 && num2<0); //teste num2 ser impar e negativo
    printf ( "%s (%d) ? %d\n", "O primeiro número é par e positivo ", num1, v1);
    printf ( "%s (%d) ? %d\n\n", "O segundo número é impar e positivo ", num2, v2);

    printf ( "%s\n", "EXERCICIO 5.10.) ler dois valores reais do teclado e dizer se o primeiro é maior, menor ou igual ao segundo." );
    printf ( "\n" );
    printf("Escolha o primeiro numero real:\n");
    scanf("%f", &numFloat1);
    printf("Escolha o segundo numero real:\n");
    scanf("%f", &numFloat2);
    v1 = (numFloat1>numFloat2); //teste se numFloat1>numFloat2
    v2 =(numFloat1<numFloat2); //teste se numFloat1<numFloat2
    v3 =(numFloat1==numFloat2); //teste se numFloat1==numFloat2
    printf ("%s(%5.2f) %s(%5.2f) ? %d\n", "O primeiro numero escolhido é MAIOR que o segundo ", numFloat1, "> ", numFloat2, v1);
    printf ("%s(%5.2f) %s(%5.2f) ? %d\n", "O primeiro numero escolhido é MENOR que o segundo ", numFloat1, "< ", numFloat2, v2);
    printf ("%s(%5.2f) %s(%5.2f) ? %d\n\n", "O primeiro numero escolhido é IGUAL ao segundo ", numFloat1, "= ", numFloat2, v3);

    printf ( "%s\n", "EXERCICIO 5.11.) ler três valores reais do teclado e dizer se o primeiro está entre os outros dois" );
    printf ( "\n" );
    printf("Escolha um número para testar se está entre os dois extremos:\n");
    scanf("%f", &numFloat1);
    printf("Escolha o extremo menor para ser testado:\n");
    scanf("%f", &extremoMenor);
    printf("Escolha o extremo maior para ser testado:\n");
    scanf("%f", &extremoMaior);
    v1 = (extremoMenor<numFloat1 && numFloat1<extremoMaior); //teste se o número escolhido está entre os dois extremos
    printf ("%s(%5.2f) ? %d\n\n", "O numero escolhido está entre os extremos", numFloat1, v1);

    printf ( "%s\n", "EXERCICIO 5.12.) ler três valores reais do teclado e dizer se o primeiro não está entre os outros dois" );
    printf ( "\n" );
    printf("Escolha um número para testar se NÃO está entre os dois extremos:\n");
    scanf("%f", &numFloat1);
    printf("Escolha o extremo menor para ser testado:\n");
    scanf("%f", &extremoMenor);
    printf("Escolha o extremo maior para ser testado:\n");
    scanf("%f", &extremoMaior);
    v1 = !(extremoMenor<numFloat1 && numFloat1<extremoMaior); //teste se o número escolhido NÃO está entre os dois extremos, equivalente ao contrario da comparacao de valores (true igual a false)
    printf ("%s(%5.2f) ? %d\n\n", "O numero escolhido está entre os extremos", numFloat1, v1);

    printf ( "%s\n", "EXERCICIO 5.13.) ler três valores literais (caracteres) do teclado e dizer se o primeiro está entre os outros dois" );
    printf ( "\n" );
    printf("Escolha um carácter (char) para ser convertido para binario e testar se está entre os dois carácteres extremos:\n");
    scanf(" %c", &firstChar);
    printf("Escolha o extremo menor para ser testado:\n");
    scanf(" %c", &secondChar); // Colocar " %c" senão, scanf() considera o ENTER
    printf("Escolha o extremo maior para ser testado:\n");
    scanf(" %c", &thirdChar);
    v1 = (int) (secondChar<firstChar && firstChar<thirdChar); //conversão de char para respectivo numero em binario e verificação da condição do exercicio
    printf ("%s(%c) ? %d\n\n", "O char escolhido está entre os extremos", firstChar, v1);

    printf ( "%s\n", "EXERCICIO 14.) ler três valores literais (caracteres) do teclado e dizer se estão em ordem crescente lexicograficamente." );
    printf ( "\n" );
    printf("Escolha o primeiro caracter:\n");
    scanf(" %c", &firstChar);
    printf("Escolha o segundo caracter:\n");
    scanf(" %c", &secondChar);
    printf("Escolha o terceiro caracter:\n");
    scanf(" %c", &thirdChar);
    v1 = (int) ((secondChar==firstChar+1) && (thirdChar==secondChar+1));  //verificador da ordem alfabética
    printf ("%c , %c e %c %s? %d\n\n", firstChar, secondChar, thirdChar, "Estão em ordem alfabética", v1);

    printf ( "%s\n", "EXERCICIO 15.) ler um valor literal (caractere) do teclado e dizer se é uma letra maiúscula." );
    printf ( "\n" );
    printf("Escolha um caracter para verificar:\n");
    scanf(" %c", &firstChar);
    v1 = (int) ((65<= firstChar) && (firstChar <=90));  //verificador letra maiuscula
    printf ("%c %s? %d\n", firstChar,"é uma letra maíscula", v1);


    // encerrar
    printf ( "\n\nApertar ENTER para terminar." );
    fflush ( stdin ); // limpar a entrada de dados
    getchar( ); // aguardar por ENTER
    return ( 0 ); // voltar ao SO (sem erros)
}
