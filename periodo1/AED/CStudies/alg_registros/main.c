#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <conio.h>
#include <locale.h>
//Definição da estrutura de dados
struct Taluno
{
    char nome[50];
    int mat;
    float n1,n2,n3;
};
typedef struct Taluno aluno;

void menu();
//void imprimeAluno(aluno a);
void imprime_arquivo(FILE *f);
void altera_notas(FILE *f);
int localiza_aluno(FILE *f,int mat);
void inclui_aluno(FILE *f);
//aluno leAluno();
void exclui_aluno(FILE *f);





int main()
{
    int  op;
    FILE *f;
    setlocale(LC_ALL,"portuguese");

    if ((f = fopen("teste.dat", "r+b"))==NULL) // arquivo existe
    {
        printf("Arquivo não existia ... criando arquivo!");
        if((f = fopen("teste.dat", "w+b"))==NULL) //arq não existe
        {
            printf("Erro na criação do arquivo!!");
            exit(1);
        }
    }


    do
    {

        printf("Escolha:\n");
        printf ("a - incluir aluno\n");
        printf("b - alterar aluno\n");
        printf ("c - imprimir aluno\n");
        printf ("d - excluir aluno\n");
        printf ("e - sair do programa\n");
        op=getch ();
        switch (op)
        {
        case 'a':
            printf("preenchendo o arquivo...\n");
            inclui_aluno(f);
            break;
        case 'b':
            printf("alterando o arquivo...\n");
            altera_notas(f);
            break;
        case 'c':
            printf("imprmindo o arquivo...\n");
            imprime_arquivo(f);
            system("pause");
            break;
        case 'd':
            printf("deletando linha...\n");
            exclui_aluno(f);
            system("pause");
            break;

        }
    }
    while(op!='e');
    fclose(f);




    return 0;
}

/*
aluno leAluno()
{
    aluno a;
    printf("Matricula:");
    fflush(stdin);
    scanf("%d", &a.mat);
    printf("Aluno:");
    fflush(stdin);
    gets(a.nome);
    printf("Nota 1:");
    fflush(stdin);
    scanf("%f", &a.n1);
    printf("Nota 2:");
    fflush(stdin);
    scanf("%f", &a.n2);
    printf("Nota 3:");
    fflush(stdin);
    scanf("%f", &a.n3);

    return a;

}

*/

/*
void imprimeAluno(aluno a)
{


    printf("Matricula:%d\n",a.mat);
    printf("Nome.....:%s\n",a.nome);
    printf("Nota1....:%.2f\n",a.n1);
    printf("Nota2....:%.2f\n",a.n2);
    printf("Nota3....:%.2f\n",a.n3);


}

*/



void inclui_aluno(FILE *f)
{
    aluno a;
    int posicao;
    //lendo os dados do teclado
    printf("Digite o numero da matricula...:");
    fflush(stdin);
    scanf("%d",&a.mat);
    posicao=localiza_aluno(f,a.mat);
    if (posicao==-1) //não tinha codigo no arquivo
    {

        printf("Digite o nome do aluno...:");
        fflush(stdin);
        gets(a.nome);
        printf("Digite a nota 1...:");
        fflush(stdin);
        scanf("%f",&a.n1);
        printf("Digite a nota 2...:");
        fflush(stdin);
        scanf("%f",&a.n2);
        printf("Digite a nota 3...:");
        fflush(stdin);
        scanf("%f",&a.n3);
        fseek(f,0,SEEK_END); // posicionado o arquivo no final
        fwrite(&a, sizeof(a),1,f); //gravando os dados
        fflush(f);
    }
    else
    {
        printf("Código %d já existe no arquivo. Inclusão não realizada!\n",a.mat);
    }
}

int localiza_aluno(FILE *f,int mat)
{
    int posicao=-1,achou=0;
    aluno a;
    fseek(f,0,SEEK_SET);
    fread(&a, sizeof(a),1, f);
    while (!feof(f) && !achou)
    {
        posicao++; // semelhante a posicao = posicao +1;
        if (a.mat==mat)
        {
            achou=1;
        }
        fread(&a, sizeof(a),1, f);
    }
    if (achou)
    {
        return posicao;
    }
    else
    {
        return -1;
    }
}


void altera_notas(FILE *f)
{
    int mat,posicao;
    aluno a;
    printf("Diga qual o numero da matricula para alterar:");
    scanf("%d",&mat);
    posicao=localiza_aluno(f,mat);
    if (posicao!=-1) // localizou a mercadoria
    {
        fseek(f,sizeof(a)*(posicao),SEEK_SET); //encontra posição escolhida
        fread(&a, sizeof(a),1, f);
        printf("Matricula atual:%d - %s nota 1:%.2f nota 2:%.2f nota 3:%.2f\n",a.mat,a.nome,a.n1,a.n2,a.n3);
        printf("Novo nome:");
        fflush(stdin);
        gets(a.nome);
        printf("Nova nota 1....:");
        scanf("%f",&a.n1);
        printf("Nova nota 2....:");
        scanf("%f",&a.n2);
        printf("Nova nota 3....:");
        scanf("%f",&a.n3);
        fseek(f,sizeof(a)*(posicao),SEEK_SET);
        fwrite(&a, sizeof(a),1, f); //escreve a alteração
        fflush(f);
    }
}


void exclui_aluno(FILE *f)
{
    int mat,posicao;
    int escolha;
    aluno a;
    printf("Diga qual o numero da matricula para excluir:");
    scanf("%d",&mat);
    printf("Realmente deseja excluir? Digite 1 para confirmar ou outra tecla para desfazer a operação\n");
    scanf("%d",&escolha);

    if(escolha==1)
    {
        posicao=localiza_aluno(f,mat);
        if (posicao!=-1) // localizou a mercadoria
        {
            fseek(f,sizeof(a)*(posicao),SEEK_SET); //encontra posição escolhida
            fread(&a, sizeof(a),1, f);


            // a.nome[50]='excluida';
            a.mat=0;
            a.n1=0;
            a.n2=0;
            a.n3=0;

            fseek(f,sizeof(a)*(posicao),SEEK_SET);
            fwrite(&a, sizeof(a),1, f); //escreve a alteração
            printf("Matricula excluida\n");
            fflush(f);
        }

    }
    else
    {
        printf("O aluno não foi excluido.\n");

    }
}


void imprime_arquivo(FILE *f)
{
    aluno a;
    fseek(f,0,SEEK_SET);
    fread(&a, sizeof(a),1, f);
    while (!feof(f))
    {
        if(a.mat!=0)
        {
            printf("Matricula....:%d \n",a.mat);
            printf("Nome.:%s \n",a.nome);
            printf("Preço.....:%.2f\n",a.n1);
            printf("Preço.....:%.2f\n",a.n2);
            printf("Preço.....:%.2f\n",a.n3);

        }

        fread(&a, sizeof(a),1, f);
    }
}





