//package br.com.puc.studies;

//Aluno: Bruno Gomes Ferreira Data: 18/02/2022

import java.util.Scanner;

public class Ex02 {
	public static void main(String[] args) {
		int i, soma = 0;
		float media=0;
		int notas[] = new int[3];
		Scanner sc = new Scanner(System.in);

		for (i = 0; i < notas.length; i++) {
			System.out.println("Digite a nota do aluno:");
			notas[i] = sc.nextInt();
			soma = notas[i] + soma;
		}

		media = (float) soma / notas.length;

		System.out.println("A media é:" + media);

		if (media >= 0 && media < 4) {
			System.out.println("Reprovado");
		} else if (media >= 4 && media < 6) {
			System.out.println("Exame Especial");
		} else if(media >= 6 && media < 10) {
			System.out.println("Aprovado");
		}
	}
}
