#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <locale.h>
using namespace std;


//SUPER-CLASSE
class Veiculo
{

private:

    string placa;
    int anoFabricacao;
public:
    Veiculo();
    string getPlaca();
    void setPlaca(string p);
    int getAnoFabricacao();
    void setAnoFabricacao(int a);

    //Função abstrata
    virtual float calculaFreteVeiculos(float k)
    {
        cout <<"\ncalculo ainda nao implementado \n";
        return 0;
    }

};
//Métodos da classe Veiculo
Veiculo::Veiculo()
{
    cout<<"\nExecutando construtor da classe veículo\n";
}

string Veiculo::getPlaca()
{
    return placa;
}

void Veiculo::setPlaca(string p)
{
    placa = p;
}


int Veiculo::getAnoFabricacao()
{

    return anoFabricacao;
}

void Veiculo::setAnoFabricacao(int a)
{

    anoFabricacao = a;

}

//SUB-CLASSE

class Carro:public Veiculo
{
private:
    float valorBandeirada;
    float valorBaseCarro;
    float kmRodadosCarro;
    string modelo;
public:
    Carro(); //criação do construtor
    //Definição dos getters e setters
    string getModelo();
    void setModelo(string m);
    float getValorBandeirada();
    void setValorBandeirada(float vban);
    float getValorBaseCarro();
    void setValorBaseCarro( float vcar);
    float getkmRodadosCarro();
    void setkmRodadosCarro(float k);
    float calculaFreteVeiculos(float k);

};

Carro::Carro()
{
    cout<<"\nExecutando construtor Carro\n";
}

float Carro::getValorBandeirada()
{
    return valorBandeirada;
}

void Carro::setValorBandeirada(float vban)
{
    valorBandeirada = vban;
}

float Carro::getValorBaseCarro()
{

    return valorBaseCarro;
}

void Carro::setValorBaseCarro(float vcar)
{

    valorBaseCarro = vcar;

}

string Carro::getModelo()
{
    return modelo;
}

void Carro::setModelo(string m)
{
    modelo = m;
}

//Calculo da função polimorfica para automoveis
float Carro::calculaFreteVeiculos(float k)
{
    k = getkmRodadosCarro();

    return k*valorBaseCarro+valorBandeirada;
}

float Carro::getkmRodadosCarro()
{
    return kmRodadosCarro;
}

void Carro::setkmRodadosCarro(float k)
{
    kmRodadosCarro = k;
}


class Caminhao:public Veiculo
{
private:
    int nPneus;
    float valorBaseCaminhao;
    float kmRodadosCaminhao;
public:
    Caminhao();
    int getNPneus();
    void setNPneus(int np);
    float getValorBaseCaminhao();
    void setValorBaseCaminhao(float vcam);
    float getkmRodadosCaminhao();
    void setkmRodadosCaminhao(float k);
    float calculaFreteVeiculos(float k);


};

Caminhao::Caminhao()
{
    cout<<"Executando o construtor do Caminhão\n";
}

int Caminhao::getNPneus()
{
    return nPneus;
}

void Caminhao::setNPneus(int np)
{
    nPneus = np;
}
float Caminhao::getValorBaseCaminhao()
{

    return valorBaseCaminhao;
}

void Caminhao::setValorBaseCaminhao(float vcam)
{

    valorBaseCaminhao = vcam;

}

float Caminhao::calculaFreteVeiculos(float k)
{
    k = getkmRodadosCaminhao();

    return k*nPneus*valorBaseCaminhao;
}

float Caminhao::getkmRodadosCaminhao()
{
    return kmRodadosCaminhao;
}

void Caminhao::setkmRodadosCaminhao(float k)
{
    kmRodadosCaminhao = k;
}


//retorna um valor real (float) e recebe como parâmetro um ponteiro para a classe Veiculo
//O parâmetro é um ponteiro para o tipo Veiculo e não uma variável do tipo Veiculo


float obterFreteVeiculo(Veiculo *veiculo)
{
//default
    return veiculo->calculaFreteVeiculos(100);
}


int main()
{
    setlocale(LC_ALL,"portuguese");
    //Criação de objetos usando ponteiros
    Veiculo *v[2];
    Carro *car;
    Caminhao *cam;
    int i,nP,anoF;
    float vBCarro, vBCaminhao,vBan,kMCar, kMCam;
    string placa,modelo;
    char tipo;


    for (i=0; i<2; i++)
    {
        cout << "Placa do veiculo: ";
        cin>>placa;
        cout << "Ano Fabricação: ";
        cin>>anoF;
        cout << "Deseja cadastrar (A - Carro ou B - Caminhao)?";
        tipo=getche();
        if (toupper(tipo)=='A')
        {
            cout << "Modelo: ";
            cin>>modelo;
            cout << "\nValor base do carro: ";
            cin >>vBCarro;
            cout << "\nValor bandeirada: ";
            cin >>vBan;
            cout << "\nKm rodados: ";
            cin >> kMCar;
            car = new (Carro);
            car->setPlaca(placa);
            car->setModelo(modelo);
            car->setAnoFabricacao(anoF);
            car->setValorBaseCarro(vBCarro);
            car->setkmRodadosCarro(kMCar);
            car->setValorBandeirada(vBan);
            v[i]=car;
        }
        else
        {
            cout << "\nNumero de Pneus: ";
            cin >>nP;
            cout << "\nValor base do caminhão: ";
            cin >>vBCaminhao;
            cout << "\nKm rodados: ";
            cin >> kMCam;
            cam = new (Caminhao);
            cam->setPlaca(placa);
            car->setAnoFabricacao(anoF);
            cam->setValorBaseCaminhao(vBCaminhao);
            cam->setkmRodadosCaminhao(kMCam);
            cam->setNPneus(nP);
            v[i]=cam;
        }
    }

    // imprimindo o calculo do frete
    cout << "\n****Frete dos veículos ***\n-----------------------------\n";
    for (i=0; i<2; i++)
    {
        cout <<"Frete de "<< v[i]->getPlaca();
        cout << " = R$" << obterFreteVeiculo(v[i]) << "\n";
    }


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

/*
  cout<<"\n\nCriando objeto da classe Veiculo";
  Veiculo v;
  v.setPlaca("ABC1234");
  v.setKmAtual(1000);
  v.setAnoFabricacao(2020);

  cout << "\n\nCriando um objeto da classe Carro";
  Carro a;

  a.setPlaca("VXF4455");
  a.setKmAtual(0);
  a.setNPortas(4);
  a.setAnoFabricacao(2019);
  a.setUltimaRevisao(2020);

  cout << "\n\nCriando um objeto da classe Caminhao";
  Caminhao c;

  c.setPlaca("CCP3245");
  c.setAnoFabricacao(2017);
  c.setCapacidadeFrete(100);
  c.setValorFreteKm(300);
  c.setNPneus(8);
  c.setKmAtual(3000);


  cout << "\n\nDados cadastrados do objeto da classe Veiculo";
  cout << "\nPlaca:" << v.getPlaca();
  cout << "\nkm atual:" << v.getKmAtual();
  cout << "\nAno de fabricação:" << v.getAnoFabricacao();


  cout << "\n\nDados cadastrados do objeto da classe Automovel";
  cout << "\nPlaca:" << a.getPlaca();
  cout << "\nUltima revisão:" << a.getNPortas();
  cout << "\nAno de frabricação:" << a.getAnoFabricacao();
  cout << "\nkm atual = :" << a.getKmAtual();
  cout << "\nAno de fabricação:" << a.getAnoFabricacao();


  cout << "\n\nDados cadastrados do objeto da classe Caminhao";
  cout << "\nPlaca:" << c.getPlaca();
  cout << "\nNumero de pneus:" << c.getNPneus();
  cout << "\nAno de frabricação:" << c.getAnoFabricacao();
  cout << "\nkm atual:" << c.getKmAtual();
  cout << "\nValor frete:R$" <<c.getValorFreteKm();
  cout << "\nCapacidade do frete em kg:" <<c.getCapacidadeFrete();
  */
