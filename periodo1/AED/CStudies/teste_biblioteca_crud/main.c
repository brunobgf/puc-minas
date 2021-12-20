#include "b_funcionario.h"
#include "b_menus.h"


int main()
{
    int  op;
    FILE *f;
    setlocale(LC_ALL,"portuguese");

    if ((f = fopen("controleSalaoDeFestas.dat", "r+b"))==NULL) // arquivo existe
    {
        printf("Arquivo não existia ... criando arquivo!");
        if((f = fopen("controleSalaoDeFestas.dat", "w+b"))==NULL) //arq não existe
        {
            printf("Erro na criação do arquivo!!");
            exit(1);
        }
    }

    do
    {
        printf("MENU:\n");
        printf("Escolha uma opção:\n");
        printf ("a - Cadastrar uma entidade\n\n");
        printf ("e - sair do programa\n");
        op=getch ();
        switch (op)
        {
        case 'a':
            printf("Cadastrando um novo funcionário...\n");
            menuCadastros(f);
            break;
        }
    }
    while(op!='e');
    fclose(f);
    return 0;
}


/*

    do
    {

        printf("Escolha:\n");
        printf ("a - incluir funcionario \n");
        printf("b - alterar funcionario\n");
        printf ("c - imprimir funcionario\n");
        printf ("d - excluir funcionario\n");
        printf ("e - sair do programa\n");
        op=getch ();
        switch (op)
        {
        case 'a':
            printf("preenchendo o arquivo...\n");
            inclui_funcionario(f);
            break;

        case 'b':
            printf("alterando o arquivo...\n");
            altera_funcionario(f);
            break;

        case 'c':
            printf("imprmindo o arquivo...\n");
            imprime_funcionario(f);
            system("pause");
            break;

        case 'd':
            printf("deletando linha...\n");
            exclui_funcionario(f);
            system("pause");
            break;
        }
    }
    while(op!='e');
    fclose(f);

    return 0;
}
*/
