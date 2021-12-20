#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
void menu();
void ex01();
void ex02();
void ex03();
void ex04();
void ex05();
void vetorFatorial(double *v, double tam); //foi utilizado double porque os números obtidos são muito grandes
void uniaoVetor(int *vet1, int *vet2, int tam);
void deletaDuplicados(int *vet1,int tam);
void inverteVetor(int *vet1,int tam);
void contaParImpar(int *vet1,int tam);
void vetorOrdenado(int *vet1,int tam);


int main()
{
    setlocale(LC_ALL, "portuguese"); //permite usar carácteres em portugues
    menu();
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
    printf("-1 Finaliza o programa\n");
    scanf("%d",&op);

    do
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
        default:
            printf("Codigo invalido, tente novamente");
        }

        printf("\nEscolha o número referente aos exercícios no menu para serem executados:\n");
        printf("1 - Exercicio 1 \n");
        printf("2 - Exercicio 2 \n");
        printf("3 - Exercicio 3 \n");
        printf("4 - Exercicio 4 \n");
        printf("5 - Exercicio 5 \n");
        printf("-1 Finaliza o programa\n");
        scanf("%d",&op);
    }
    while(op!= -1);
}

void ex01()
{

    double vet[15];
    int i;
    srand(time(NULL));
    setlocale(LC_ALL, "portuguese");
    printf ( "%s\n", "EXERCICIO 1 - Preencher um vetor de 15 posições posições com valores aleatórios de 15 a 50. Construir um vetor B domesmo tipo, em que cada elemento de B deva ser o resultado do fatorial correspondente de cada elemento da matrizA. Apresentar A e B" );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );
    printf("Vetor original \n");
    for(i=0; i<15; i++) // criação do vetor aleatorio
    {
        vet[i]=rand()%36+15; //50-15 = 35
        printf("%5.2f \n",vet[i]);

    }
    printf("Vetor com fatorial \n");
    vetorFatorial(vet,15);
}

void vetorFatorial(double *v, double tam)
{
    int i,j;
    double vet2[15],fat=1;
    for(i=0; i<15; i++)
    {
        fat=1;
        for(j=1; j<=v[i] ; j++)
        {
            fat=fat*j; // calculo do fatorial p/ cada [i] do vetor
        }

        vet2[i]=fat;
        printf("%5.2f \n",vet2[i]);
    }
}


void ex02()
{
    int vetA[15], vetB[15],i;
    setlocale(LC_ALL, "portuguese");
    printf ( "%s\n", "EXERCICIO 2 - Preencher dois vetores A e B de 15 posições cada com valores aleatórios de vi a vf (lidos do teclado). Construir um vetor C, sendo este o resultado da união dos elementos de A e B – sem repetição. Apresentar C." );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );
    for(i=0; i<15; i++)
    {
        printf("Escolha um numero para popular o vetor 1:\n");
        scanf("%d", &vetA[i]);
    }
    for(i=0; i<15; i++)
    {
        printf("Escolha um numero para popular o vetor 2:\n");
        scanf("%d", &vetB[i]);
    }
    printf("Escolha um numero para popular o vetor 2:\n");
    uniaoVetor(vetA,vetB,30);

}

void uniaoVetor(int *vet1, int *vet2, int tam)
{
    int vetC[30],i,j;

    for(i=0; i<15; i++)
    {
        vetC[i] = vet1[i];
    }

    for(i=0,j=15; j<30 && i<15; i++,j++)
    {
        vetC[j] = vet2[i];
    }

    printf("Vetor após unir:");
    for(i=0; i<30; i++)
    {
        printf("%d ",vetC[i]);
    }

    printf("\nO vetor sem os números duplicados é: \n");

    deletaDuplicados(vetC,30);
}

void deletaDuplicados(int *vet1,int tam)
{
    int i,j,k,number=30;


    for(i=0; i<number; i++)
    {
        //checa a partir do segundo elemento se há rpetição
        for(j = i+1; j < number; j++)
        {
            //verifica existencia de duplicado
            if(vet1[i] == vet1[j])
            {
                //remove o numero duplicado
                for(k = j; k <number-1; k++)
                {
                    vet1[k] = vet1[k+1];
                }
                number--; // reduz o numero maximo do array por 1
                j--; //se a posição dos elementos se altera, o index de j permanecerá o mesmo
            }
        }
    }

    for(i=0; i<number; i++)
    {
        printf(" %d ",vet1[i]);
    }
}



/*

3 - Preencher um vetor A de 20 elementos com valores aleatórios de vi a vf (lidos do teclado), em seguida
crie um procedimento que inverta os elementos armazenados. Ou seja, o primeiro elemento de A passará a ser o
ultimo, o segundo elemento passará a ser o penúltimo e assim por diante. Apresentar A.

*/

void ex03()
{
    int vetA[20],i;
    setlocale(LC_ALL, "portuguese");
    printf ( "%s\n", "EXERCICIO 3" );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );
    printf("Escolha 20 numeros para obter o inverso do vetor\n");
    for(i=0; i<20; i++)
    {
        printf("Escolha um numero para popular o vetor 1:\n");
        scanf("%d", &vetA[i]);
    }

    printf("O inverso do vetor escolhido é:\n");
    inverteVetor(vetA,20);

}

void inverteVetor(int *vet1,int tam)
{
    int vetRev[20],i;

    for(i=0; i<tam; i++)
    {
        vetRev[i]=vet1[tam-i-1]; //5-0-1 = 4 => o vetor reverso receberá o index numero 4 do vetor original
    }
    for(i=0; i<tam; i++)
    {
        printf("%d ",vetRev[i]);
    }
}


/*

4 - Preencher um vetor A de x elementos (x deverá ser lido do teclado) com valores aleatórios de vi a vf
(lidos do teclado). Crie um vetor ParImpar de 2 posições e armazene no índice 0 quantos elementos de A são par e
no índice 1 quantos elementos de A são ímpar. Apresentar o vetor ParImpar. Obs.: não utilize nenhum comando
condicional(if,switch).

*/

void ex04()
{
    int i,vetA[5],num;
    setlocale(LC_ALL, "portuguese");
    printf ( "%s\n", "EXERCICIO 4" );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );
    printf("Escolha o tamanho do vetor:\n");
    scanf("%d", &num);

    for(i=0; i<num; i++)
    {
        printf("Escolha um numero para popular o vetor 1:\n");
        scanf("%d", &vetA[i]);
    }

    printf("O numero de pares e impares são respectivamente:\n");
    contaParImpar(vetA,5);
}

void contaParImpar(int *vet1,int tam)
{
    int i, impar=0,par=0, vetParImpar[2];

    for(i=0; i<tam; i++)
    {
        (vet1[i] & 1 && printf("impar \n",impar++))|| printf("par \n",par++);
    }
    vetParImpar[1]=impar;
    vetParImpar[0]=par;
    for(i=0; i<2; i++)
    {
        printf("%d ",vetParImpar[i]);
    }

}


void ex05()
{
    int vetA[10],i;
    setlocale(LC_ALL, "portuguese");
    printf ( "%s\n", "EXERCICIO 5 - Preencher um vetor A de 10 elementos com valores aleatórios de vi a vf (lidos do teclado).Ordene e imprima o vetor A." );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );
    for(i=0; i<10; i++)
    {
        printf("Escolha um numero para popular o vetor 1:\n");
        scanf("%d", &vetA[i]);
    }

    printf("Vetor após ordenar:\n");
    vetorOrdenado(vetA,10);
}

void vetorOrdenado(int *vet1,int tam)
{
    int i,j,temp=0;

    for(i=0; i<10; i++)
    {
        for(j=i+1; j<10; j++)
        {
//se o vetor na posição zero for maior que o vetor na posição 1, o temp recebe vet1[i], e assim é feito a troca do valor de i por j
            if (vet1[i] > vet1[j])
            {
                temp = vet1[i];
                vet1[i] = vet1[j];
                vet1[j] = temp;
            }

        }
    }


    for(i=0; i<10; i++)
    {
        printf("%d ",vet1[i]);
    }

}

