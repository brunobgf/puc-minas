//package br.com.puc.studies;

//Aluno: Bruno Gomes Ferreira Data: 18/02/2022

import java.util.Scanner;

public class Ex03 {
	public static void main(String[] args) {
		int i, veiculosAcimaVel = 0;
		float velocidade = 0, multa, valorMulta=150;
		int veiculos[] = new int[5];
		Scanner sc = new Scanner(System.in);

		for (i = 0; i < veiculos.length; i++) {
			System.out.println("Digite a velocidade do veiculo em km/h:");
			veiculos[i] = sc.nextInt();
			velocidade = veiculos[i];
			
			if(velocidade>60) {
				veiculosAcimaVel++;
			}
		}

		multa =(float) valorMulta*veiculosAcimaVel;

		System.out.println("O numero de veiculos multados foi de: " + veiculosAcimaVel + " A multa arrecadada foi de " + multa + "reais");

	}

}
