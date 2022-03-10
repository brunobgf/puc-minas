import java.util.Scanner;

/*

Lista de Exercícios

ALUNO: Bruno Gomes Ferreira
Data: 04/03/2022

Exercicio 1 - Faça um programa, em Java, para corrigir provas de múltipla escolha. Cada prova tem oito
questões e cada questão vale um ponto. O primeiro conjunto de dados a ser lido é o
gabarito da prova. Os outros dados são os números dos alunos e suas respectivas respostas
às questões da prova. Existem dez alunos matriculados. Calcule e mostre:
a) o número e a nota de cada aluno;
b) a porcentagem de aprovação, sabendo-se que a nota mínima necessária para
aprovação é cinco.

 */

public class Ex01 {

    public static void prctAprovados (int alunoAprovado, int numeroAlunosTotais) {
        int porcAprovados;
        //calculo da porcentagem de alunos aprovados através de uma regra de 3
        porcAprovados = 100*alunoAprovado/ numeroAlunosTotais;

        System.out.println("A porcentagem de alunos aprovados foi de: " + porcAprovados + "%");
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in); //criando um novo objeto scanner e guardando o endereço na variavel sc
        String resposta;
        int pontoQuestao, alunoAprovado=0;

        //Criação dos arrays

        int numeroAlunos[] =new int[10]; //qtd de alunos da turma
        int pontosTotais[] = new int[10];
        String gabarito[] = new String[] {"a","b","c","d","d","c","c","b"}; //gabarito para comparação

        //Primeiro for => iteração entre os alunos
        //segundo for => iteração entre as respostas de determinado aluno

        for(int i=0; i<numeroAlunos.length; i++){
            pontoQuestao = 0;
            for(int j=0;j<8;j++){
                System.out.println("Aluno:"+ (i+1) +" - Digite a resposta da questão " + (j+1)  );
                resposta = sc.nextLine(); //a variavel resposta guarda o que foi digitado
                //comparação da resposta do aluno com o gabarito e alocação no vetor de pontuação total
                if(resposta.equals(gabarito[j])){
                    pontoQuestao++;
                    pontosTotais[i]=pontoQuestao;
                }
            }
        }

        //Checa se o aluno foi aprovado ou não

        for(int i=0; i<numeroAlunos.length; i++){
            System.out.println("Aluno " + (i+1) + " Pontos totais obtidos:" + pontosTotais[i]);
            if(pontosTotais[i]>=5){
                alunoAprovado++;
            }
        }

        //chamando o método para calcular a porcentagem dos alunos

        prctAprovados(alunoAprovado, numeroAlunos.length);

    }
}
