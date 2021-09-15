#include <stdio.h>  // para as entradas e saidas
#include <stdlib.h>
#include <stdbool.h> // para valores logicos
#include <locale.h> //para o codeblocks funcionar com o idioma portugues
#include <math.h> //fun��es matematicas

/*
5) Para cada um dos problemas a seguir, expresse um algoritmo que possa ser utilizado para solucionar, utilize o
Portugol e depois passe para a linguagem C � as respostas ser�o 1(verdadeiro) 0(falso)

01.) Ler um valor inteiro do teclado e dizer se � par

Aluno: Bruno Gomes Ferreira

Data: 10/09/2021

    */

int main()
{
    //Defini��o dos dados
    int num1, num2; //Variaveis n�meros inteiros
    float numFloat1, numFloat2, extremoMenor, extremoMaior;//Variaveis n�meros reais (float)
    char firstChar, secondChar, thirdChar; //Variaveis do tipo char
    bool v1 = true, v2 = true, v3 = true; //Verificadores booleanos
    setlocale(LC_ALL, "portuguese");

    printf ( "%s\n", "EXERCICIO 5.01.) Ler um valor inteiro do teclado e dizer se � par" );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" ); //mudan�a de linha
    printf("Escolha um numero inteiro para verificar se � par:\n");
    scanf("%d", &num1); //guarda a vari�vel escolhida
    v1 = (num1%2==0); //teste se � par ou n�o
    printf ( "%s (%d) ? %d\n\n", "� par ", num1, v1 );

    printf ( "%s\n", "EXERCICIO 5.02.) Ler um valor inteiro do teclado e dizer se � �mpar" );
    printf ( "\n" );
    printf("Escolha um numero inteiro:\n");
    scanf("%d", &num1);
    v1 = (num1%2!=0); //teste se � impar
    printf ( "%s (%d) ? %d\n\n", "� impar ", num1, v1 );

    printf ( "%s\n", "EXERCICIO 5.03.) ler um valor inteiro do teclado e dizer se �mpar e maior que 100." );
    printf ( "\n" );
    printf("Escolha um numero inteiro:\n");
    scanf("%d", &num1);
    v1 = (num1%2!=0 && num1>100); //teste logico se impar e maior que 100
    printf ( "%s (%d) ? %d\n\n", "� impar e maior que 100 ", num1, v1 );

    printf ( "%s\n", "EXERCICIO 5.04.) ler um valor inteiro do teclado e dizer se � par e menor que 100, ou �mpar e maior que 100." );
    printf ( "\n" );
    printf("Escolha um numero inteiro:\n");
    scanf("%d", &num1);
    v1 =((num1%2==0 && num1 <100) || (num1%2!=0 && num1>100)); //teste se o n�mero � par E menor que 100 OU impar e maior que 100
    printf ( "%s (%d) ? %d\n\n", "� par e menor que 100 OU � impar e maior que 100 ", num1, v1 );

    printf ( "%s\n", "EXERCICIO 5.05.) ler um valor inteiro do teclado e dizer se pertence ao intervalo aberto entre (25:75)." );
    printf ( "\n" );
    printf("Escolha um numero inteiro:\n");
    scanf("%d", &num1);
    v1 =((25<num1) && (num1<75)); //teste para compara��o entre intervalos abertos em C
    printf ( "%s (%d) ? %d\n\n", "� um n�mero entre 25 e 75 num (intervalo aberto) ", num1, v1 );

    printf ( "%s\n", "EXERCICIO 5.06.) ler um valor inteiro do teclado e dizer se pertence ao intervalo fechado entre [25:75]. " );
    printf ( "\n" );
    printf("Escolha um numero inteiro:\n");
    scanf("%d", &num1);
    v1 =((25<=num1) && (num1<=75)); //teste para compara��o com intervalo fechado em C
    printf ( "%s (%d) ? %d\n\n", "� um n�mero entre 25 e 75 num (intervalo fechado) ", num1, v1 );

    printf ( "%s\n", "EXERCICIO 5.07.) ler um valor inteiro do teclado e dizer se pertence aos intervalos fechados [15:45] ou [66:99]" );
    printf ( "\n" );
    printf("Escolha um numero inteiro:\n");
    scanf("%d", &num1);
    v1 =(((15<=num1) && (num1<=45)) || ((66<=num1) && (num1<=99))) ; //teste para compara��o entre intervalos em C
    printf ( "%s (%d) ? %d\n\n", "pertence aos intervalos fechados [15:45] ou [66:99] ", num1, v1 );

    printf ( "%s\n", "EXERCICIO 5.08.) ler dois valores inteiros do teclado e dizer se o primeiro � par e o segundo � �mpar" );
    printf ( "\n" );
    printf("Escolha o primeiro numero inteiro:\n");
    scanf("%d", &num1);
    printf("Escolha o segundo numero inteiro:\n");
    scanf("%d", &num2);
    v1 =(num1%2==0); //teste num1 ser par
    v2 =(num2%2!=0); //teste num2 ser impar
    printf ( "%s (%d) ? %d %s (%d) ? %d \n\n", "o primeiro n�mero � par ", num1, v1, "o segundo n�mero � impar", num2, v2 );

    printf ( "%s\n", "EXERCICIO 5.09.) ler dois valores inteiros do teclado e dizer se o primeiro � par e positivo, e o segundo � �mpar e negativo." );
    printf ( "\n" );
    printf("Escolha o primeiro numero inteiro:\n");
    scanf("%d", &num1);
    printf("Escolha o segundo numero inteiro:\n");
    scanf("%d", &num2);
    v1 =(num1%2==0 && num1>0); //teste num1 ser par e positivo
    v2 =(num2%2!=0 && num2<0); //teste num2 ser impar e negativo
    printf ( "%s (%d) ? %d\n", "O primeiro n�mero � par e positivo ", num1, v1);
    printf ( "%s (%d) ? %d\n\n", "O segundo n�mero � impar e positivo ", num2, v2);

    printf ( "%s\n", "EXERCICIO 5.10.) ler dois valores reais do teclado e dizer se o primeiro � maior, menor ou igual ao segundo." );
    printf ( "\n" );
    printf("Escolha o primeiro numero real:\n");
    scanf("%f", &numFloat1);
    printf("Escolha o segundo numero real:\n");
    scanf("%f", &numFloat2);
    v1 = (numFloat1>numFloat2); //teste se numFloat1>numFloat2
    v2 =(numFloat1<numFloat2); //teste se numFloat1<numFloat2
    v3 =(numFloat1==numFloat2); //teste se numFloat1==numFloat2
    printf ("%s(%5.2f) %s(%5.2f) ? %d\n", "O primeiro numero escolhido � MAIOR que o segundo ", numFloat1, "> ", numFloat2, v1);
    printf ("%s(%5.2f) %s(%5.2f) ? %d\n", "O primeiro numero escolhido � MENOR que o segundo ", numFloat1, "< ", numFloat2, v2);
    printf ("%s(%5.2f) %s(%5.2f) ? %d\n\n", "O primeiro numero escolhido � IGUAL ao segundo ", numFloat1, "= ", numFloat2, v3);

    printf ( "%s\n", "EXERCICIO 5.11.) ler tr�s valores reais do teclado e dizer se o primeiro est� entre os outros dois" );
    printf ( "\n" );
    printf("Escolha um n�mero para testar se est� entre os dois extremos:\n");
    scanf("%f", &numFloat1);
    printf("Escolha o extremo menor para ser testado:\n");
    scanf("%f", &extremoMenor);
    printf("Escolha o extremo maior para ser testado:\n");
    scanf("%f", &extremoMaior);
    v1 = (extremoMenor<numFloat1 && numFloat1<extremoMaior); //teste se o n�mero escolhido est� entre os dois extremos
    printf ("%s(%5.2f) ? %d\n\n", "O numero escolhido est� entre os extremos", numFloat1, v1);

    printf ( "%s\n", "EXERCICIO 5.12.) ler tr�s valores reais do teclado e dizer se o primeiro n�o est� entre os outros dois" );
    printf ( "\n" );
    printf("Escolha um n�mero para testar se N�O est� entre os dois extremos:\n");
    scanf("%f", &numFloat1);
    printf("Escolha o extremo menor para ser testado:\n");
    scanf("%f", &extremoMenor);
    printf("Escolha o extremo maior para ser testado:\n");
    scanf("%f", &extremoMaior);
    v1 = !(extremoMenor<numFloat1 && numFloat1<extremoMaior); //teste se o n�mero escolhido N�O est� entre os dois extremos, equivalente ao contrario da comparacao de valores (true igual a false)
    printf ("%s(%5.2f) ? %d\n\n", "O numero escolhido est� entre os extremos", numFloat1, v1);

    printf ( "%s\n", "EXERCICIO 5.13.) ler tr�s valores literais (caracteres) do teclado e dizer se o primeiro est� entre os outros dois" );
    printf ( "\n" );
    printf("Escolha um car�cter (char) para ser convertido para binario e testar se est� entre os dois car�cteres extremos:\n");
    scanf(" %c", &firstChar);
    printf("Escolha o extremo menor para ser testado:\n");
    scanf(" %c", &secondChar); // Colocar " %c" sen�o, scanf() considera o ENTER
    printf("Escolha o extremo maior para ser testado:\n");
    scanf(" %c", &thirdChar);
    v1 = (int) (secondChar<firstChar && firstChar<thirdChar); //convers�o de char para respectivo numero em binario e verifica��o da condi��o do exercicio
    printf ("%s(%c) ? %d\n\n", "O char escolhido est� entre os extremos", firstChar, v1);

    printf ( "%s\n", "EXERCICIO 14.) ler tr�s valores literais (caracteres) do teclado e dizer se est�o em ordem crescente lexicograficamente." );
    printf ( "\n" );
    printf("Escolha o primeiro caracter:\n");
    scanf(" %c", &firstChar);
    printf("Escolha o segundo caracter:\n");
    scanf(" %c", &secondChar);
    printf("Escolha o terceiro caracter:\n");
    scanf(" %c", &thirdChar);
    v1 = (int) ((secondChar==firstChar+1) && (thirdChar==secondChar+1));  //verificador da ordem alfab�tica
    printf ("%c , %c e %c %s? %d\n\n", firstChar, secondChar, thirdChar, "Est�o em ordem alfab�tica", v1);

    printf ( "%s\n", "EXERCICIO 15.) ler um valor literal (caractere) do teclado e dizer se � uma letra mai�scula." );
    printf ( "\n" );
    printf("Escolha um caracter para verificar:\n");
    scanf(" %c", &firstChar);
    v1 = (int) ((65<= firstChar) && (firstChar <=90));  //verificador letra maiuscula
    printf ("%c %s? %d\n", firstChar,"� uma letra ma�scula", v1);


    // encerrar
    printf ( "\n\nApertar ENTER para terminar." );
    fflush ( stdin ); // limpar a entrada de dados
    getchar( ); // aguardar por ENTER
    return ( 0 ); // voltar ao SO (sem erros)
}
