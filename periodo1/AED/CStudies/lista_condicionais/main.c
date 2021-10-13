#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
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

Exerc�cios referentes a Lista de Exerc�cios 02 - Estruturas Condicionais no C

Aluno: Bruno Gomes Ferreira

Data: 24/09/2021

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
    scanf("%d",&op);

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
        printf("C�digo invalido, tente novamente");
    }
}

void ex01()
{
    int num;
    setlocale(LC_ALL, "portuguese"); //permite usar car�cteres em portugues
    printf ( "%s\n", "EXERCICIO 1. Fazer um algoritmo que leia um numero inteiro e mostre uma mensagem indicando se este numero e par ou impar." );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );
    printf("Escolha um n�mero: \n");
    scanf("%d", &num);

    //Verifica��o se � par ou impar
    if(num%2==0)
    {

        printf("O n�mero %d � par\n", num);
    }
    else
    {
        printf("O n�mero %d � impar \n", num);
    }
    // encerrar
    printf ( "\n\nApertar ENTER para encerrar." );
    fflush ( stdin );
    getchar( );
}


/*

TABELA DE TESTES - Quest�o 1

Entrada esperada|| Sa�da esperada || Sa�da do programa || Obs
        3               Impar             Impar
        8                Par               Par
        0                Par               Par
       -1               Impar             Impar

*/

/*

2. Fazer um algoritmo pe�a o nome e as 3 notas de um aluno e mostre, al�m do nome e do valor da media do aluno,
uma mensagem de "Aprovado", caso a media seja igual ou superior a 6, ou a mensagem "reprovado", caso
contrario

*/
void ex02()
{
    int nota1,nota2,nota3,soma;
    const int denominador = 3;
    float media;
    char nome[25];
    setlocale(LC_ALL, "portuguese"); //permite usar car�cteres em portugues
    printf ( "%s\n", "EXERCICIO 2. Nome, 3 notas, do valor da media do aluno e uma mensagem de Aprovado, caso a media seja igual ou superior a 6, ou a mensagem reprovado, caso contrario." );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );
    printf("Escolha o nome do aluno: \n");
    scanf("%s", nome); //N�o � necess�rio colocar o & aqui
    printf("Escolha nota 1 do aluno de 0 � 10:\n");
    scanf("%d", &nota1);
    printf("Escolha nota 2 do aluno de 0 � 10:\n");
    scanf("%d", &nota2);
    printf("Escolha nota 3 do aluno de 0 � 10:\n");
    scanf("%d", &nota3);

    soma = nota1 + nota2 + nota3;
    media = (float) soma/denominador; //calculo da media das notas dos alunos

    if (media >= 6)
    {
        printf("O aluno %s teve a m�dia %5.2f: Aprovado", nome, media);
    }
    else
    {
        printf("O aluno %s teve a m�dia %5.2f: Reprovado", nome, media);
    }
    // encerrar
    printf ( "\n\nApertar ENTER para encerrar." );
    fflush ( stdin );
    getchar( );
}

/*

TABELA DE TESTES - Quest�o 2

Nome:        Entrada 1 || Entrada 2 || Entrada 3 ||          Sa�da esperada            ||           Sa�da do programa            || Obs
Maria          10          10            10                     Aprovado                                 Aprovado
Julia           7          5              3                     Reprovado                                Reprovado
Eustaquio      10          7              3                     Aprovado                                 Aprovado

*/


void ex03()
{
    int temp;
    setlocale(LC_ALL, "portuguese"); //permite usar car�cteres em portugues
    printf ( "%s\n", "EXERCICIO 3 - Fazer um algoritmo que leia a temperatura da �gua e mostre se est� no estado solido, l�quido ou gasoso." );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );

    printf("Escolha a temperatura da �gua para saber o seu estado f�sico:\n");
    scanf("%d", &temp);

    //Teste da temperatura
    if (temp > 0 && temp <100)
    {
        printf("No %d �C a �gua est� em estado l�quido \n", temp);
    }
    else
    {
        if(temp > 100)
        {
            printf("No %d �C a �gua est� em estado gasoso\n", temp);
        }
        else
        {
            printf("No %d �C a �gua est� em estado s�lido \n", temp);
        }
    }
    // encerrar
    printf ( "\n\nApertar ENTER para encerrar." );
    fflush ( stdin );
    getchar( );
}


/*

TABELA DE TESTES - Quest�o 3

Entrada   ||   Sa�da esperada  ||   Sa�da do programa  || Obs
    100          Gasoso                 Gasoso
     50          Liquido                Liquido
    -10          S�lido                 S�lido

*/

void ex04()
{
    int x, y;
    setlocale(LC_ALL, "portuguese"); //permite usar car�cteres em portugues
    printf ( "%s\n", "EXERCICIO 4 - Leia um valor X e se ele for menor que 0 avalie Y = x2 + 4. Se ele for maior que 0 avalie x3 -3 e se ele for igual a 0 de uma mensagem de erro" );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );
    printf("Escolha um valor de x:\n");
    scanf("%d", &x);
    if (x<0)
    {
        y = pow(x,2) + 4;
        printf("Avaliando a express�o x^2 + 4. Para o valor de x = %d, y = %d", x, y);
    }
    else
    {
        if(x>0)
        {
            y = pow(x,3) - 3;
            printf("Avaliando a express�o x^3 - 3. Para o valor de x = %d, y = %d", x, y);
        }
        else
        {
            printf("Erro: Escolha um n�mero diferente de 0");
        }
    }
    // encerrar
    printf ( "\n\nApertar ENTER para encerrar." );
    fflush ( stdin );
    getchar( );
}

/*

TABELA DE TESTES - Quest�o 4

Entrada   ||   Sa�da esperada  ||   Sa�da do programa  || Obs
    5              122                 122
   -8               68                  68
    8              509                 509

*/

void ex05()
{
    int a, b, c, maior, menor, numInterno;
    setlocale(LC_ALL, "portuguese"); //permite usar car�cteres em portugues
    printf ( "%s\n", "EXERCICIO 5 - Construa um algoritmo que receba como entrada tr�s valores (A,B e C). Ap�s o processamento o menor valor dever� estar em A e o maior valor em C, e o valor intermedi�rio em B. Imprima A,B e C." );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );
    printf("Escolha o primeiro numero:\n");
    scanf("%d", &a);
    printf("Escolha o segundo numero:\n");
    scanf("%d", &b);
    printf("Escolha o terceiro numero:\n");
    scanf("%d", &c);

    //Compara��es entre maior e menor valor para que seja feito a ordena��o
    if(a > b)
    {
        maior = a;
        menor = b;
    }
    else
    {
        maior = b;
        menor = a;
    }

    if (c > maior)
    {
        numInterno = maior;
        maior = c;
    }
    else
    {
        if(c<menor)
        {
            numInterno = menor;
            menor = c;
        }
        else
        {
            numInterno = c;
        }
    }

    printf("Ordenando A = %d, B= %d, C=%d Teremos => A = %d, B= %d, C=%d", a, b, c, maior, numInterno, menor);



    // encerrar
    printf ( "\n\nApertar ENTER para encerrar." );
    fflush ( stdin );
    getchar( );
}


/*

TABELA DE TESTES - Quest�o 5

Entrada 1 || Entrada 2 || Entrada 3 ||          Sa�da esperada            ||           Sa�da do programa            || Obs
    7           8            3                     8,7,3                                   8,7,3
    5           2            4                     5,4,2                                   5,4,2


*/



/*

6. Desenvolver um algoritmo que leia tr�s n�meros inteiros: X, Y, Z e verifique se o n�mero X � divis�vel por Y e por Z.
O algoritmo dever� mostrar as poss�veis mensagens:
- o n�mero � divis�vel por Y e Z.
- o n�mero � divis�vel por Y mas n�o por Z.
- o n�mero � divis�vel por Z mas n�o por Y.
- o n�mero n�o � divis�vel nem Y nem por Z.

*/

void ex06()
{
    int x, y, z;
    setlocale(LC_ALL, "portuguese"); //permite usar car�cteres em portugues
    printf ( "%s\n", "EXERCICIO 6 - Desenvolver um algoritmo que leia tr�s n�meros inteiros: X, Y, Z e verifique se o n�mero X � divis�vel por Y e por Z." );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );
    printf("Escolha o primeiro n�mero:\n");
    scanf("%d", &x);
    printf("Escolha o segundo n�mero:\n");
    scanf("%d", &y);
    printf("Escolha o terceiro n�mero:\n");
    scanf("%d", &z);
    if (x%y==0 && x%z==0)
    {
        printf("%d � divisivel ao mesmo tempo por %d e %d", x,y,z);
    }
    else
    {
        if(x%y==0)
        {
            printf("%d � divisivel SOMENTE por %d", x,y);
        }
        else
        {
            if(x%z==0)
            {
                printf("%d � divisivel SOMENTE por %d", x,z);
            }

            else
            {
                printf("%d n�o � divisivel por nenhum dos n�meros", x);
            }
        }
    }
    // encerrar
    printf ( "\n\nApertar ENTER para encerrar." );
    fflush ( stdin );
    getchar( );
}

/*

TABELA DE TESTES - Quest�o 6

Entrada 1 || Entrada 2 || Entrada 3 ||          Sa�da esperada            ||           Sa�da do programa            || Obs
    15          5            3           S�o divisiveis ao mesmo tempo         S�o divisiveis ao mesmo tempo
     7          5            3         N�o � divisivel por nenhum dos dois     N�o � divisivel por nenhum dos dois
    10          5            3             � divisivel somente por 5              � divisivel somente por 5
     9          5            3             � divisivel somente por 3              � divisivel somente por 3

*/

/*
7. O numero 3025 possui a seguinte caracter�stica:
30 + 25 = 55
552 = 3025
Fazer um algoritmo que dado um numero de 4 d�gitos (verifique se o n�mero pertence a faixa) calcule e escreva se ele
possui ou n�o esta caracter�stica.

*/

void ex07()
{
    int a, b, c, soma, somaElevada;
    setlocale(LC_ALL, "portuguese"); //permite usar car�cteres em portugues
    printf ( "%s\n", "EXERCICIO 7 - Fazer um algoritmo que dado um numero de 4 d�gitos (verifique se o n�mero pertence a faixa) calcule e escreva se ele possui ou n�o esta caracter�stica." );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );
    printf("Escolha um numero de 4 digitos:\n");
    scanf("%d", &a);
    if (a > 999 && a < 9999)
    {
        b = a/100; //para extrair os dois primeiros n�meros Ex: 3025/100 = 30
        c = a%100; //para extrair os dois ultimos numeros (RESTO) Ex 3025%100 = 25
        soma = b + c; //soma das extra��es que foram feitas
        somaElevada = pow(soma,2); //eleva-se o resultado

        if (somaElevada == a) //Condi��o se o n�mero possu� aquela caracteristica
        {
            printf("O n�mero poss�i esta caracter�stica, %d = %d", a, somaElevada);
        }
        else
        {
            printf("o n�mero n�o possui esta caractrist�ca, %d != %d\n", a, somaElevada);
        }
    }
    else
    {
        printf("Este n�mero n�o tem 4 digitos");
    }
    // encerrar
    printf ( "\n\nApertar ENTER para encerrar." );
    fflush ( stdin );
    getchar( );
}

/*

TABELA DE TESTES - Quest�o 7

Entrada esperada||   Sa�da esperada || Sa�da do programa || Obs
      3025            3025 = 3025         3025 = 3025
      3125            3125 != 3136        3125 != 3136
      4025            4025 != 4225        4025 != 4225

*/

/*
Exercicio 8 - ler um c�digo do teclado e mostrar o nome correspondente, de acordo com a lista :
221 Bernardo
211 Eust�quio
311 Luiz
312 M�rio
332 Artur

*/

void ex08()
{
    int userId;
    setlocale(LC_ALL, "portuguese"); //permite usar car�cteres em portugues
    printf ( "%s\n", "EXERCICIO 8 - ler um c�digo do teclado e mostrar o nome correspondente, de acordo com a lista" );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );
    setlocale(LC_ALL, "portuguese"); //permite usar car�cteres em portugues
    printf("Escolha um id:\n");
    scanf("%d", &userId);
    switch(userId) //Estrutura switch-case para selecionar os c�digos
    {
    case 221:
        printf("Bernado \n");
        break;
    case 211:
        printf("Eust�quio \n");
        break;
    case 311:
        printf("Luiz \n");
        break;
    case 312:
        printf("M�rio \n");
        break;
    case 332:
        printf("Arthur \n");
        break;
    default:
        printf("C�digo invalido");

    }

    // encerrar
    printf ( "\n\nApertar ENTER para encerrar." );
    fflush ( stdin );
    getchar( );
}

/*

TABELA DE TESTES - Quest�o 8

Entrada esperada|| Sa�da esperada || Sa�da do programa || Obs
      221             Bernardo            Bernardo
      311             Luiz                Luiz
      332             Arthur              Arthur
      500          C�digo invalido     C�digo invalido

*/

/*


9. N�meros pal�ndromos s�o aqueles que escritos da direita para esquerda ou da esquerda para direita tem o mesmo valor.
Exemplo:929, 44, 97379. Fazer um algoritmo que dado um numero de 5 d�gitos; calcule e escreva se este e ou n�o pal�ndromo

*/

void ex09()
{
    int input, a, b, c, d, e, f, g, h, i, inverso;
    setlocale(LC_ALL, "portuguese"); //permite usar car�cteres em portugues
    printf ( "%s\n", "EXERCICIO 9 - Fazer um algoritmo que dado um numero de 5 d�gitos; calcule e escreva se este e ou n�o pal�ndromo" );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );
    printf("Escolha um numero de 5 digitos:\n");
    scanf("%d", &input);
    if (input > 9999 && input < 99999)
    {
        a = input%10; //para extrair o ultimo numero Ex: 97379 = 9

        b = input/10; //para extrair o ultimo numero 97379/10 = 9737

        c = b%10;// 9737%10 =>  7

        d = b/10; // 9737/10 => 973

        e = d%10;

        f = d/10;

        g = f%10;

        h = f/10;

        i = h%10;

        inverso = a*10000 + c*1000 + e*100 + g*10 + i; //calculo do n�mero inverso utilizando os restos das variaveis acima

        //Verificando se o n�mero digitado � palindromo ou n�o
        if(input==inverso)
        {
            printf("O %d � n�mero � palindromo j� que o seu inverso � %d", input, inverso);
        }
        else
        {
            printf("O %d � n�mero N�O � palindromo j� que o seu inverso � %d", input, inverso);
        }
    }
    else
    {
        printf("Este n�mero n�o tem 5 digitos");
    }
    // encerrar
    printf ( "\n\nApertar ENTER para encerrar." );
    fflush ( stdin );
    getchar( );
}

/*

TABELA DE TESTES - Quest�o 9

Entrada esperada|| Sa�da esperada || Sa�da do programa || Obs
      97379             97379            97379 � palindromo
      97378             87379            97378 N�O  � palindromo
      332     o numero n�o tem 5 digitos o numero n�o tem 5 digitos

*/


/*


10. Desenvolver um algoritmo para calcular a conta de �gua para a SANEAGO. O custo da �gua varia dependendo do tipo do
consumidor - residencial, comercial ou industrial. A regra para calcular a conta e:
� Residencial: R$ 75,00 de taxa mais R$ 3,50 por m3 gastos;
� Comercial: R$ 500,00 para os primeiros 80 m3 gastos mais R$ 5,50 por m3 gastos acima dos 80 m3;
� Industrial: R$ 800,00 para os primeiros 100 m3 gastos mas R$ 8,00 por m3 gastos acima dos 100 m3;
O algoritmo devera ler a conta do cliente, seu tipo (residencial, comercial e industrial) e o seu consumo de �gua em metros cubos.
Como resultado imprimir o valor a ser pago pelo mesmo.

*/

void ex10()
{
    int tipoConta;
    float consumoCliente, valorConta;
    setlocale(LC_ALL, "portuguese"); //permite usar car�cteres em portugues
    printf ( "%s\n", "EXERCICIO 10 - O algoritmo devera ler a conta do cliente, seu tipo (residencial, comercial e industrial) e o seu consumo de �gua em metros cubos. Como resultado imprimir o valor a ser pago pelo mesmo." );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );
    printf("Digite o numero referente a conta que deseja avaliar: Digite 1 se for residencial, 2 se for comercial ou 3 se for industrial\n");
    scanf("%d", &tipoConta);
    printf("Informe a quantidade consumida em metros cubicos, lembrando que 1 metro cubico = 1000 litros \n");
    scanf("%f", &consumoCliente);

    switch(tipoConta)
    {
    case 1:
        valorConta = 75.00 + (3.50*consumoCliente); //calculo da conta de residencia
        printf("A conta da residencia ser� %5.2f reais", valorConta);
        break;
    case 2:
        if(consumoCliente<=80)
        {
            valorConta = 500.00; //calculo de comercio se for consumo menor que 80 metros cubicos
            printf("A conta do comercio ser� %5.2f reais", valorConta);
        }
        else
        {
            valorConta = 500.00 + (5.50*(consumoCliente-80)); //calculo de comercio se for consumo maior que 80 metros cubicos
            printf("A conta da comercio ser� %5.2f reais", valorConta);
        }
        break;
    case 3:
        if(consumoCliente<=100)
        {
            valorConta = 800.00; //calculo de industria se for consumo menor que 100 metros cubicos
            printf("A conta do industria ser� %5.2f reais", valorConta);
        }
        else
        {
            valorConta = 800.00 + (8.00*(consumoCliente-100));
            printf("A conta da industria ser� %5.2f reais", valorConta);
        }
        break;
    default:
        printf("C�digo invalido, tente novamente");

    }

    //encerrar

    printf ( "\n\nApertar ENTER para encerrar." );
    fflush ( stdin );
    getchar( );
}

/*

TABELA DE TESTES - Quest�o 10

Entrada 1 || Entrada 2 ||   Sa�da esperada    ||   Sa�da do programa  || Obs
    1          5                 92,50                  92,50
    2          90                555,00                 555,00
    3          100               800,00                 800,00
    3          120               960,00                 960,00


*/
