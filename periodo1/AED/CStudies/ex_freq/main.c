#include <stdio.h>
#include <stdlib.h>

int main()
{
    int v[10];
    int freq[3]={0,0,0};
    for(int i=0;i<10;i++){
        v[i]=rand()%3;
        printf("v[%i]=%i\n",i,v[i]);
        freq[v[i]]++;
    }
    for(int i=0;i<3;i++){
        printf("o %i saiu %i vezes\n",i,freq[i]);
    }
    printf("Hello world!\n");
    return 0;
}
