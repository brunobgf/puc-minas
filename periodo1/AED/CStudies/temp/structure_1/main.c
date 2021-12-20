#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


struct Taluno
{
    int matricula;
    char nome[50];
    float nota1,nota2,nota3;
};
typedef struct Taluno aluno;
int main()
{
    setlocale(LC_ALL,"portuguese");
    aluno a1;
    a1.matricula=1234;
    strcpy(a1.nome,"Ama");
    a1.nota1=9.5;
    a1.nota2=8.0;
    a1.nota3=10.0;
    printf("Matricula:%d\n",a1.matricula);
    printf("Nome.:%s\n",a1.nome);
    printf("Notal.:%.2f\n",a1.nota1);
    printf("Nota2.:%.2f\n",a1.nota2);
    printf("Nota3.:%.2f\n",a1.nota3);
    return 0;
}
