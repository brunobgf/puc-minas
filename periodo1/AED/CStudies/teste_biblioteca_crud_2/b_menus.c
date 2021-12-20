#include "b_menus.h"
#include "b_funcionarios.h"

void menuFuncionarios()
{
    int op;
    FILE *f;
    setlocale(LC_ALL,"portuguese");

    if ((f = fopen("controleFuncionarios.dat", "r+b"))==NULL) // arquivo existe
    {
        printf("Arquivo não existia ... criando arquivo!\n");
        if((f = fopen("controleFuncionarios.dat", "w+b"))==NULL) //arq não existe
        {
            printf("Erro na criação do arquivo!!");
            exit(1);
        }
    }
    do
    {

        printf("Escolha:\n");
        printf ("a - Cadastro de Funcionarios \n");
        printf ("b - Imprimir funcionario por código\n");
        printf ("c - Imprimir todos os funcionarios\n");
        printf ("d - Alterar funcionario\n");
        printf ("e - Excluir funcionario\n");
        printf ("f - Voltar para o menu principal\n");
        op=getch ();
        switch (op)
        {
        case 'a':
            printf("Cadastrando um novo funcionário...\n");
            printf("preenchendo o arquivo...\n");
            inclui_funcionario(f);
            break;
        case 'c':
            printf("Cadastrando um novo funcionário...\n");
            printf("preenchendo o arquivo...\n");
            imprime_funcionario(f);
            break;
        }
    }
    while(op!='e');
    fclose(f);
    printf("\nVoltando para o menu principal...\n\n");
}
