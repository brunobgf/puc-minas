#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
void imprimeCarro();

class Produto
{
public:
// atributos nome,valor
    char nome[20];
    float valor;
//método que calcula o valor do imposto
    float valorImposto();
};
float Produto::valorImposto()
{
    float vi;
    if (valor<500)
        vi= valor*10/100;
    else
        vi=valor*15/100;
    return vi;
}

class Carro
{

public:
    char marca[20];
    char cor[20];
    int anoFabricacao;
    float valor;

    float valorIpva(int anoAtual)
    {
        float ipva = valor*(float)5/100;

        ipva = ipva - (0.1*(anoAtual-anoFabricacao)*ipva);
        return ipva;

    }
    void imprimeCarro()
{
    printf("Dados do carro\n");
    printf("\nMarca:%s",marca);
    printf("\nCor:%s",cor);
    printf("\nPreço:%d",anoFabricacao);
    printf("\nPreço:%5.2f",valor);
    printf("\nValor Imposto IPVA:%5.2f\n",valorIpva(2021));
}
    //Criação do construtor
    Carro()
    {

        printf("\nexecutando o método construtor\n");

        printf("digite a marca do carro:");
        fflush(stdin);
        gets(marca);
        printf("digite a cor do carro:");
        fflush(stdin);
        gets(cor);
        printf("digite o preço do produto:");
        scanf("%f",&valor);
        printf("digite o ano de fabricação:");
        scanf("%d",&anoFabricacao);

    }

    Carro(const char m[20], const char c[20], float v, int ano)
    {

        printf("\nexecutando o método construtor com parametros\n");

        strcpy(marca,m);
        strcpy(cor,c);
        valor = v;
        anoFabricacao = ano;

    }
    ~Carro()
    {
        printf("\n\nExecutando o método destrutor\n");
        printf("o produto %s foi destruido!\n",marca);

    }

};


int main()
{
    setlocale(LC_ALL,"portuguese");
    Carro c[3];
    int i;
    //Carro nc("Fiat","Preto",2000,2020);

    for(i=0;i<3;i++){
        c[i].imprimeCarro();
    }


    //c.imprimeCarro();
    // nc.imprimeCarro();



    /*
    c.anoFabricacao = 2020;
    strcpy(c.cor,"Preto");
    strcpy(c.marca,"Honda");
    c.valor = 1000;
    printf("Dados do carro\n");
    printf("\nMarca:%s",c.marca);
    printf("\nCor:%s",c.cor);
    printf("\nPreço:%5.2f",c.valor);
    */


    system("pause");
    return 0;
}


/*

    Produto p;
    float preco;
    char nomeProduto[30];
    setlocale(LC_ALL,"portuguese");
    printf("digite o nome do produto:");
    gets(nomeProduto);
    printf("digite o preço do produto:");
    scanf("%f",&preco);
    strcpy(p.nome,nomeProduto);
    p.valor=preco;
    printf("Dados do produto\n");
    printf("\nnome:%s",p.nome);
    printf("\nPreço:%5.2f",p.valor);
    printf("\nValor Imposto:%5.2f\n",p.valorImposto());


*/

