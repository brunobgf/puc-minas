import java.util.Random;
/*

Lista de Exercícios

ALUNO: Bruno Gomes Ferreira
Data: 04/03/2022

Exercicio 2 - Faça um programa, em Java, que preencha uma matriz de ordem 3 x 4 (3 linhas e 4
colunas) com números inteiros e positivos; calcule e mostre:
a) o maior elemento da matriz e sua posição (linha e coluna);
b) o menor elemento da matriz e sua posição (linha e coluna).

 */

public class Ex02 {
    //Método para preencher a matriz com valores aleatórios
    public static int[][] preencheMatriz(int[][] matriz) {
        int qtdValores = 101; //valores de 0-100
        Random rand = new Random(); //instanciando a classe random/criando o objeto random
        for(int i=0;i< matriz.length; i++){
            for(int j=0;j< matriz[i].length;j++){
                matriz[i][j]=rand.nextInt(qtdValores);
            }
        }
        return matriz;
    }

    //Método para imprimir a matriz preenchida
    public static int[][] imprimeMatriz(int[][] matrizPreenchida){
        for(int i=0;i< matrizPreenchida.length; i++){
            for(int j=0;j< matrizPreenchida[i].length;j++) {
                System.out.print(" [" + i + "][" + j + "] = " + matrizPreenchida[i][j]);
            }
            System.out.println();
        }
        return matrizPreenchida;
    }

    //Método para imprimir o MAIOR elemento da matriz e a sua posição
    public static int[][] imprimeMaior(int[][] mat){
        int cx=0, cy=0, maiorElemento=0;
        for(int i=0;i< mat.length; i++) {
            for (int j = 0; j < mat[i].length; j++) {
                if(mat[i][j]>maiorElemento){
                    maiorElemento = mat[i][j]; //guarda o maior elemento
                    cx=i; //guarda linha do maior elemento
                    cy=j; //guarda coluna do maior elemento
                }
            }
        }
        System.out.println("O maior elemento é o número: " + maiorElemento + " Na posição: [" + cx + "][" + cy + "] ");
        return mat;
    }

    //Método para imprimir o MENOR elemento da matriz e a sua posição
    public static int[][] imprimeMenor(int[][] mat){
        int cx=0, cy=0, menorElemento=999;
        for(int i=0;i< mat.length; i++) {
            for (int j = 0; j < mat[i].length; j++) {
                if(mat[i][j]<menorElemento){
                    menorElemento = mat[i][j]; //guarda o menor elemento
                    cx=i; //guarda linha do menor elemento
                    cy=j; //guarda coluna do menor elemento
                }
            }
        }
        System.out.println("O menor elemento é o número: " + menorElemento + " Na posição: [" + cx + "][" + cy + "] ");
        return mat;
    }


    public static void main(String[] args) {

        int mat[][] = new int[3][4]; //criação da matriz/alocação na memoria e passagem do endereço para a variavel mat

        mat = preencheMatriz(mat);

        mat = imprimeMatriz(mat);

        mat = imprimeMaior(mat);

        mat = imprimeMenor(mat);

    }
}
