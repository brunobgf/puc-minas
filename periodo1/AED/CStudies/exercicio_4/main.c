#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int ex4a();
int ex4b();
int ex4c();
int ex4d();
int ex4e();
int ex4f();
int ex4g();
int ex4h();
int ex4i();
int ex4j();

/*

Lista de Exercícios 01 - Atividade 4

Aluno: Bruno Gomes Ferreira

Data: 10/09/2021

*/


int main()
{
    ex4a();
    ex4b();
    ex4c();
    ex4d();
    ex4e();
    ex4f();
    ex4g();
    ex4h();
    ex4i();
    ex4j();

    return 0;
}

int ex4a()

{
    int x, y;
    setlocale(LC_ALL, "portuguese"); //permite usar carácteres em portugues
    printf ( "%s\n", "EXERCICIO 4.a - Leia um número e imprima seu sucessor" );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" ); // mudar de linha

    printf("Escolha um número\n");
    scanf("%d", &x);

    y=x+1; //Calculo do sucessor
    printf("O sucessor de %d é: %d \n", x,y);

    // encerrar
    printf ( "\n\nApertar ENTER para ir ao próximo exercicio.\n" );
    fflush ( stdin ); // limpar a entrada de dados
    getchar( ); // aguardar por ENTER
    return ( 0 ); // voltar ao SO (sem erros)
}


int ex4b()
{
    int num1, num2, num3, num4, soma;
    const int denominador = 4;
    float media;
    setlocale(LC_ALL, "portuguese");

    printf ( "%s\n", "EXERCICIO 4.b. - Calcule a média aritmética de quatro números inteiros dados" );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );

    printf("Escolha o primeiro número\n");
    scanf("%d", &num1);
    printf("Escolha o segundo número\n");
    scanf("%d", &num2);
    printf("Escolha o terceiro número\n");
    scanf("%d", &num3);
    printf("Escolha o quarto número\n");
    scanf("%d", &num4);

    soma = num1+num2+num3+num4; //Calculo da soma
    media = (float) soma/denominador; //Calculo da média, utilizando type casting

    printf("A média dos números escolhidos será será: %5.2f\n", media);
    // encerrar
    printf ( "\n\nApertar ENTER para ir ao próximo exercicio.\n" );
    fflush ( stdin );
    getchar( );
    return ( 0 );
}

int ex4c()
{
    int num1, num2, num3, peso1, peso2, peso3, numerador;
    const int denominador=3;
    float mediaPonderada;
    setlocale(LC_ALL, "portuguese");

    printf ( "%s\n", "EXERCICIO 4.c - Faça um algoritmo que receba 3 (três) notas e seus respectivos pesos, calcule e mostre a média ponderada dessas notas" );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );

    printf("Escolha o primeira nota\n");
    scanf("%d", &num1);
    printf("Escolha o peso da primeira nota\n");
    scanf("%d", &peso1);
    printf("Escolha a segunda nota\n");
    scanf("%d", &num2);
    printf("Escolha o peso da segunda nota\n");
    scanf("%d", &peso2);
    printf("Escolha a terceira nota\n");
    scanf("%d", &num3);
    printf("Escolha o peso da terceira nota\n");
    scanf("%d", &peso3);

    numerador = num1*peso1 + num2*peso2 + num3*peso3;
    mediaPonderada = (float) numerador/denominador; //Média ponderada é calculada pelo numero*peso.../quantidade de números
    printf("O valor da média ponderada é de: %5.2f\n", mediaPonderada);

    // encerrar
    printf ( "\n\nApertar ENTER para ir ao próximo exercicio.\n" );
    fflush ( stdin );
    getchar( );
    return ( 0 );
}


int ex4d()
{
    int tempCelsius;
    float tempFarenheit;
    setlocale(LC_ALL, "portuguese");

    printf ( "%s\n", "EXERCICIO 4.d - Leia uma temperatura dada na escala Celsius (C) e imprima o equivalente em Fahrenheit (F)" );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );

    printf("Escolha uma temperatura em Celsius (°C)\n");
    scanf("%d", &tempCelsius);

    tempFarenheit = (float) (9*tempCelsius)/5 + 32; //conversão de Celsius -> Farenheit

    printf("A temperatura em Farenheit é: %5.2f%s \n", tempFarenheit,"°F");

    tempCelsius = (int) ((tempFarenheit - 32)*5)/9; //Conversão Farenheit -> Celsius

    printf("Convertendo a temperatura em Farenheit para Celsius teremos: %d%s",tempCelsius,"°C");

    // encerrar
    printf ( "\n\nApertar ENTER para ir ao próximo exercicio.\n" );
    fflush ( stdin );
    getchar( );
    return ( 0 );
}


int ex4e()
{
    float salario, porcentagem, porcentagemAumento, novoSalario;
    setlocale(LC_ALL, "portuguese");

    printf ( "%s\n", "EXERCICIO 4.e - Faça um algoritmo que receba o salário de um funcionário e o percentual de aumento, calcule e mostre onovo salário" );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );

    printf("Escolha um salário:\n");
    scanf("%f", &salario);
    printf("Escolha a porcentagem de aumento:\n");
    scanf("%f", &porcentagem);
    porcentagemAumento = porcentagem/100; //transformação de porcentagem em decimal para os calculos seguintes
    novoSalario = (float) salario + salario*porcentagemAumento; //Calculo do novo salario considerando a porcentagem de aumento

    printf("O novo salário será R$ %5.2f\n", novoSalario);

    // encerrar
    printf ( "\n\nApertar ENTER para ir ao próximo exercicio.\n" );
    fflush ( stdin );
    getchar( );
    return ( 0 );
}


int ex4f()
{
    float base, altura, area;
    setlocale(LC_ALL, "portuguese");

    printf ( "%s\n", "EXERCICIO 4.f. Faça um algoritmo que peça ao usuário a base e a altura e calcule a área de um triangulo." );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );

    printf("Digite a base do triangulo:\n");
    scanf("%f", &base);
    printf("Digite a altura do triangulo:\n");
    scanf("%f", &altura);

    area = (base*altura)/2; //calculo da area

    printf("A área do triângulo é: %5.2f\n",area);

    // encerrar
    printf ( "\n\nApertar ENTER para ir ao próximo exercicio.\n" );
    fflush ( stdin );
    getchar( );
    return ( 0 );
}

/*

4.g. Pedro comprou um saco de Ração com peso em quilos. Pedro possui 2 (dois) gatos para os quais fornece a
quantidade de ração em gramas. Faça um algoritmo que receba o peso do Saco de ração e a quantidade de ração
fornecida para cada gato. Calcule e mostre quanto restará de ração no saco após 5 (cinco) dias

    */

int ex4g()
{

    float pesoSaco, racaoDiaria, consumoDiario, restoCincoDias;
    setlocale(LC_ALL, "portuguese");
    printf ( "%s\n", "EXERCICIO 4.g. Calcule e mostre quanto restará de ração no saco após 5 (cinco) dias" );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );
    printf("Digite a quantidade de ração em Kg que terá o saco:\n");
    scanf("%f",&pesoSaco);
    printf("Digite a quantidade de gramas de ração fornecida para cada gato:\n");
    scanf("%f",&racaoDiaria);
    consumoDiario = (racaoDiaria*2)/1000; //Consumo diario dos dois gatos. 1Kg = 1g/1000
    restoCincoDias = pesoSaco - consumoDiario*5; //Calculo do peso do saco após 5 dias de consumo pelos 2 gatos
    printf("A quantidade restante de ração após 5 dias será: %5.2f", restoCincoDias);

    // encerrar
    printf ( "\n\nApertar ENTER para ir ao próximo exercicio.\n" );
    fflush ( stdin );
    getchar( );
    return ( 0 );
}

int ex4h()
{
    int a,b,c;
    setlocale(LC_ALL, "portuguese");

    printf ( "%s\n", "EXERCICIO 4.h. Ler dois números inteiros para variáveis a e b. Trocar o valor de b com o de a, e imprimi-los. " );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );

    printf("Escolha o valor de a:\n");
    scanf("%d", &a);
    printf("Escolha o valor de b:\n");
    scanf("%d", &b);

    c=a; //a variavel c armazena o valor de a, para que possa ser feita as trocas entre os valores de a e b
    a=b;
    b=c;

    printf("Os novos valores de a e b são respectivamente: %d %s %d\n", a," e ",b);
    // encerrar
    printf ( "\n\nApertar ENTER para ir ao próximo exercicio.\n" );
    fflush ( stdin );
    getchar( );
    return ( 0 );

    }

    int ex4i()
    {
        int num;
        float resto;
        setlocale(LC_ALL, "portuguese");

        printf ( "%s\n", "EXERCICIO 4.i. Leia um número e imprima o resto da divisão por 7. Utilize o comando resto (a,b) na linguagem C (a % b)" );
        printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
        printf ( "\n" );

        printf("Escolha um número:\n");
        scanf("%d", &num);

        resto = (float) (num%7); //calculo do resto atraves do modulo (%)

        printf("O resto da divisão será: %5.2f\n", resto);

        // encerrar
        printf ( "\n\nApertar ENTER para ir ao próximo exercicio.\n" );
        fflush ( stdin );
        getchar( );
        return ( 0 );
    }

    int ex4j()
    {
        int primeiroTermo, segundoTermo, numDeTermos, razao, enesimoTermo, somaDosTermos;
        setlocale(LC_ALL, "portuguese");

        printf ( "%s\n", "EXERCICIO 4.j. Calcular a soma dos termos de uma P.A. lendo os valores do primeiro termo, do segundo termo e do número determos.)" );
        printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
        printf ( "\n" );

        printf("Escolha o primeiro termo da PA:\n");
        scanf("%d", &primeiroTermo);
        printf("Escolha o segundo termo da PA:\n");
        scanf("%d", &segundoTermo);
        printf("Escolha o numero de termos da PA:\n");
        scanf("%d", &numDeTermos);

        razao = segundoTermo - primeiroTermo; //calculo da razao da PA
        enesimoTermo = primeiroTermo + razao*(numDeTermos - 1); //calculo de do enesimo termo (an)
        somaDosTermos = (numDeTermos*(primeiroTermo+enesimoTermo))/2; //calculo da soma dos termos da PA

        printf("A soma de termos da PA será: %d", somaDosTermos);

        // encerrar
        printf ( "\n\nApertar ENTER para encerrar." );
        fflush ( stdin );
        getchar( );
        return ( 0 );
    }

