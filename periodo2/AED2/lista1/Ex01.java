//package br.com.puc.studies;

//Aluno: Bruno Gomes Ferreira Data: 18/02/2022

import java.util.Scanner;

public class Ex01 {
	public static void main(String[] args) {
		
		int salario;
		float novoSalario;
		
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Digite o salario do funcionario");
		salario = sc.nextInt();
		
		if (salario<=1200) {
			novoSalario =(float) (salario*0.1)+salario;
		} else {
			novoSalario = (float) (salario*0.05)+salario;
		}
		
		System.out.println("O novo salario do funcionario será:R$" + novoSalario + " Reais");
		
	}

}
