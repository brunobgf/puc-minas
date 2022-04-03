public class Aplicacao {



    public static String Combinador(String entrada){
        int i, j,k;
        String strCombinada;

        //Separação da String entrada em dois em Subvetores
        String[] entradaVet = entrada.split(" ");
        String a1 = entradaVet[0];
        String a2 = entradaVet[1];

        //a intercalação começa com o primeiro ''char'' do primeiro subvetor

        strCombinada = String.valueOf(a1.charAt(0));


        //Intercalação das strings para combina-las na variavel strCombinada
        for (i = 1, j = k = 0; (i < a1.length() && j < a2.length()); k++) {
            if (i<= j){
                strCombinada =strCombinada + a1.charAt(i);
                i++;
            }
            else{
                strCombinada =strCombinada + a2.charAt(j);
                j++;
            }
                
        }

        if (i == a1.length()) {
            for (k=j; k < a2.length(); k++) {
                strCombinada = strCombinada + a2.charAt(j);
                j++;
            }
        }
        else{
            for (k=i; k < a1.length(); k++) {
                strCombinada = strCombinada + a1.charAt(i);
                i++;
            }
        }

        return strCombinada;
    }


    public static void main(String[] args) {

        MyIO.setCharset("UTF-8");

        String entrada;
        String combinacao = null;

        entrada = MyIO.readLine();

        while (! entrada.equals("FIM")){
            combinacao = Combinador(entrada);
            System.out.println(combinacao);
            entrada = MyIO.readLine();
        }
    }
}

