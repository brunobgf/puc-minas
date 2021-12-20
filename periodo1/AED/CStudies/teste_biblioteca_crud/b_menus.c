#include "b_menus.h"
#include "b_funcionario.h"

int menuCadastros(FILE *f)
{
    int op;
    do
    {

        printf("Escolha:\n");
        printf ("a - Cadastro de Clientes \n");
        printf("b - Cadastro de Funcionários\n");
        printf ("c - Cadastro de Fornecedores\n");
        printf ("d - Cadastro de Festa\n");
        printf ("e - Voltar para o menu principal\n");
        op=getch ();
        switch (op)
        {
        case 'b':
            printf("Cadastrando um novo funcionário...\n");
            printf("preenchendo o arquivo...\n");
            inclui_funcionario(f);
            break;
        case 't':
            printf("Cadastrando um novo funcionário...\n");
            printf("preenchendo o arquivo...\n");
            imprime_funcionario(f);
            break;
        }
    }
    while(op!='e');
    printf("\nVoltando para o menu principal...\n\n");

    return 0;
}
