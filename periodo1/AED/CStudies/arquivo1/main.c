#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE * arquivo;
    char mensagem[80];
    printf("Entre o texto: \n");
    gets(mensagem);
    if ((arquivo = fopen("arquivo.txt","w")) == NULL) // modo de escrita ativo
    {
        printf("Erro de abertura! \n");
    }
    else
    {
        fprintf(arquivo, "%s \n", mensagem);
        fclose(arquivo);
    }
    system("pause");
    return 0;
}
