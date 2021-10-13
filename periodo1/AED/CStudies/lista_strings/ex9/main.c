#include <stdio.h>
#include <ctype.h>
#include <locale.h>



/*

Aluno: Bruno Gomes Ferreira

Data: 12/10/2021

Lista referente ao estudo das Strings


9 � Ler uma string de no m�ximo 50 caracteres e retire dessa string todos os espa�os em branco. Sem utilize string auxiliar
*/


int main()
{
    int i, len = 0,j;
    char str[50];
    setlocale(LC_ALL, "portuguese");

    printf ( "%s\n", "9 � Ler uma string de no m�ximo 50 caracteres e retire dessa string todos os espa�os em branco. Sem utilize string auxiliar" );
    printf ( "%s\n", "Autor: Bruno Gomes Ferreira" );
    printf ( "\n" );
    printf("Digite uma palavra: \n");
    gets(str); //l� uma string do teclado

    //Calculo do comprimento da string
    len = sizeof(str)/sizeof(str[0]);

    //checa se tem o caracter ''espa�o'', caso tenha � ignorado e troca str[i] por str[i+1]
    for(i = 0; i < len; i++)
    {
        if(str[i] == ' ')
        {
            for(j=i; j<len; j++)
            {
                str[j]=str[j+1];
            }
            len--;
        }
    }
    printf("String apos remover os espa�os: %s", str);

    // encerrar
    printf ( "\n\nApertar ENTER para encerrar." );
    fflush ( stdin );
    getchar( );
    return 0;
}

/*

TABELA DE TESTES - Quest�o 9

Entrada esperada||   Sa�da esperada || Sa�da do programa || Obs
      muito bom           muitobom         muitobom
      string sem espacos stringsemespacos  stringsemespacos

*/
