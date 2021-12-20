#include <stdio.h>
#include <stdlib.h>
int main()
{
    char buffer[128];
    FILE *arquivo;
    if ((arquivo = fopen("C:/Users/bruno/OneDrive/Documentos/folder/CStudies/arquivo1/arquivo.txt","r")) == NULL)
    {
        printf("Erro de abertura! \n");
    }
    else
    {
        fgets(buffer, 80, arquivo);
        while (!feof(arquivo))
        {
            printf("%s", buffer);
            fgets(buffer, 80, arquivo);
        }
        fclose(arquivo);
    }
    system("pause");
    return 0;
}
