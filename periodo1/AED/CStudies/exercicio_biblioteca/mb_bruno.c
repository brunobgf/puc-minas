#include "mb_bruno.h"


int categoriaNadador(int idade)
{
    int categoria=0;

    if(idade < 7)
    {
        categoria=1;
        printf("O nadador pertence a categoria [%d]\n",categoria);

    }
    else
    {
        if(idade>=7 && idade <13)
        {
            categoria=2;
            printf("O nadador pertence a categoria [%d]\n",categoria);

        }
        else
        {
            if (idade>=13)
            {
                categoria=3;
                printf("O nadador pertence a categoria [%d]\n",categoria);

            }

        }

    }

    return categoria;

}
