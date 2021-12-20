#include <stdio.h>
#include <stdlib.h>

void procr(int x) ;

int main ()
{

    procr (10);
    return 0;

}



void procr(int x)
{
    printf ("entrada: valor de x=%i\n", x) ;
    if (x>0)
    {
        procr(x-1);

    }

    printf("saindo do procr valor de x= %d \n",x);

}
