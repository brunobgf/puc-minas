#include "b_funcionarios.h"
#include "b_menus.h"


int main()
{
    int  op;
    setlocale(LC_ALL,"portuguese");
    do
    {
        printf("MENU PRINCIPAL:\n");
        printf("Escolha um tipo de entidade:\n");
        printf ("a - Clientes \n");
        printf ("b - Funcionarios \n");
        printf ("e - sair do programa\n");
        op=getch ();
        switch (op)
        {
        case 'b':
            printf("Cadastrando um novo funcionário...\n");
            menuFuncionarios();
            break;
        }
    }
    while(op!='e');
    return 0;
}

