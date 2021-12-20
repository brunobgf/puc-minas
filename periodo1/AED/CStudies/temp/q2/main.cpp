#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
using namespace std;


//SUPER-CLASSE
class ContaBancaria
{

private:

    string nome;
    int codigo;
    float saldo;
public:
    ContaBancaria();
    string getNome();
    void setNome(string n);
    int getCodigo();
    void setCodigo(int c);
    float getSaldo();
    void setSaldo(float s);
    float sacarValor(float s);
    int verificaSaldo(float s);
    void imprimeObj();

};
//Métodos da classe ContaBancaria
ContaBancaria::ContaBancaria()
{
    cout<<"\nExecutando construtor da classe conta bancaria\n";
}

string ContaBancaria::getNome()
{
    return nome;
}

void ContaBancaria::setNome(string n)
{
    nome = n;
}


int ContaBancaria::getCodigo()
{

    return codigo;
}

void ContaBancaria::setCodigo(int c)
{

    codigo = c;

}

float ContaBancaria::getSaldo()
{

    return saldo;
}

void ContaBancaria::setSaldo(float s)
{

    saldo = s;

}

float ContaBancaria::sacarValor(float s)
{
    float valorEscolhido;
    s = getSaldo();
    printf("Escolha o valor que deseja sacar:");
    scanf("%f",&valorEscolhido);

    return s-valorEscolhido;
}

int ContaBancaria::verificaSaldo(float s)
{
    s = getSaldo();
    if (s<0)
    {
        return 0;
    }
    return 1;
}


    ContaBancaria(const char n[20], const float saldo, const int codigo)
    {

        printf("\nexecutando o método construtor com parametros\n");

        strcpy(nome,n);
        saldo = v;
        anoFabricacao = ano;

    }

int main()
{
    setlocale(LC_ALL,"portuguese");
    //Criação de objetos
    ContaBancaria c;
    float saque,saldo;

    cout<<"\n\nCriando objeto da classe ContaBancaria";

    c.setNome("Bruno");
    c.setCodigo(1);
    c.setSaldo(500);

    cout << "\n\nDados cadastrados do objeto da classe ContaBancaria";
    cout << "\nNome:" << c.getNome();
    cout << "\nCodigo:" << c.getCodigo();
    cout << "\nSaldo:" << c.getSaldo()<<"\n";
    saque = c.getSaldo();
    saque = c.sacarValor(saque);
    saldo = c.verificaSaldo(saque);
    cout << "\nSaldo:" << saque <<"\n";
    cout << "\nSaldo Positivo = 1 e Saldo Negativo = 0 :" << saldo <<"\n";



    system("pause");
    return 0;
}
