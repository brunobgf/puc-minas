import java.io.*;

/*

Aluno: Bruno Gomes Ferreira
Data: 03/04/2022

Leitura do arquivo de séries
Utilize a classe Serie especificada e desenvolvida na prática anterior.
Seu programa deve ler um arquivo-texto chamado data.txt que, no VERDE,
localiza-se na pasta /tmp. Você deve preencher um vetor de objetos da
classe Serie com os dados das diversas séries informadas nesse arquivo.
A primeira linha desse arquivo deve ser descartada, pois apenas informa os
diversos campos presentes em cada uma das linhas seguintes. Cada uma das
linhas seguintes indica os dados de uma série, separados por um ponto e vírgula
(‘;’).
Depois, seu programa deve processar a entrada padrão que apresenta várias
linhas, cada uma contendo uma string indicando o nome da série cujos dados
devem ser exibidos na saída padrão. A última linha da entrada contém a palavra
FIM.
Na saída padrão, para cada nome lido da entrada padrão, escreva uma linha com
os dados do registro correspondente.
A saída padrão deve obedecer o seguinte formato:
nome ## formato ## duração ## país de origem ## idioma de origem ##
emissora de televisão original ## data de início da transmissão original ##
número de temporadas ## número de episódios


*/

public class Aplicacao {

    public static void main(String[] args) {
        int i,count=0;
        MyIO.setCharset("UTF-8");
        Serie s = new Serie();
        int qtdSeries;

        String entrada = null;

        ArquivoTextoLeitura arqEntrada;

        arqEntrada =new ArquivoTextoLeitura("/tmp/data.txt");
        //descarta primeira leitura
        arqEntrada.ler();

        entrada = arqEntrada.ler();

        while(entrada != null) {
            count++;
            entrada = arqEntrada.ler();


        }
        arqEntrada.fecharArquivo();

        qtdSeries = count;


        Serie[] vetorSerie = new Serie[qtdSeries];


        arqEntrada =new ArquivoTextoLeitura("/tmp/data.txt");


        //descarta a primeira leitura
        arqEntrada.ler();



        //Popula o vetor de objetos (serie) lendo as strings

        for (i = 0; i < qtdSeries; i++) {
            entrada = arqEntrada.ler();
            s.ler(s, entrada);
            vetorSerie[i] = new Serie(s.getNome(), s.getFormato(), s.getDuracao(), s.getPaisDeOrigem(), s.getIdiomaDeOrigem(), s.getEmissoraOriginal(), s.getDataInicioTransmissao(), s.getNumeroTemporadas(), s.getNumeroEpisodios());
        }

        arqEntrada.fecharArquivo();

        //Compara as strings com o vetor de Serie criado

        entrada = MyIO.readLine();

        while (!entrada.equals("FIM")) {
            for(int j=0;j<qtdSeries;j++) {

                if(entrada.equals(vetorSerie[j].getNome())) {
                    vetorSerie[j].imprimir(vetorSerie[j]);
                }
            }

            entrada = MyIO.readLine();
        }
    }

    public static class Serie {


        private String nome;
        private String formato;
        private String duracao;
        private String paisDeOrigem;
        private String idiomaDeOrigem;
        private String emissoraOriginal;
        private String dataInicioTransmissao;
        private int numeroTemporadas;
        private int numeroEpisodios;

        //Construtores

        Serie(String nome, int numeroEpisodios, int numeroTemporadas){
            this.nome = nome;
            this.numeroEpisodios = numeroEpisodios;
            this.numeroTemporadas = numeroTemporadas;
        }

        Serie(String nome, String formato, String duracao, String paisDeOrigem, String idiomaDeOrigem, String emissoraOriginal, String dataInicioTransmicao, int numeroTemporadas, int numeroEpisodios){
            this.nome = nome;
            this.formato=formato;
            this.duracao=duracao;
            this.paisDeOrigem=paisDeOrigem;
            this.idiomaDeOrigem=idiomaDeOrigem;
            this.emissoraOriginal=emissoraOriginal;
            this.dataInicioTransmissao = dataInicioTransmicao;
            this.numeroTemporadas=numeroTemporadas;
            this.numeroEpisodios = numeroEpisodios;
        }

        public Serie() {

        }


        public Serie clone(){
            Serie clone = new Serie(this.nome, this.numeroEpisodios, this.numeroTemporadas);
            return clone;
        }

        public void imprimir(Serie s){

            System.out.println(
                    s.getNome() + " ## "
                            + s.getFormato() + " ## "
                            + s.getDuracao() + " ## "
                            + s.getPaisDeOrigem() + " ## "
                            + s.getIdiomaDeOrigem() + " ## "
                            + s.getEmissoraOriginal()+ " ## "
                            + s.getDataInicioTransmissao()+ " ## "
                            + s.getNumeroTemporadas()+ " ## "
                            + s.getNumeroEpisodios());
        }

        public Serie ler(Serie s, String entrada){

            String[] textoSeparado = entrada.split(";");



            s.setNome(textoSeparado[0]);
            s.setFormato(textoSeparado[1]);
            s.setDuracao(textoSeparado[2]);
            s.setPaisDeOrigem(textoSeparado[3]);
            s.setIdiomaDeOrigem(textoSeparado[4]);
            s.setEmissoraOriginal(textoSeparado[5]);
            s.setDataInicioTransmissao(textoSeparado[6]);
            s.setNumeroTemporadas(Integer.parseInt(textoSeparado[7]));
            s.setNumeroEpisodios(Integer.parseInt(textoSeparado[8]));


            return s;
        }

        //Getters e Setters

        public String getNome() {

            return nome;
        }

        public void setNome(String nome) {

            this.nome = nome;
        }

        public String getFormato() {

            return formato;
        }

        public void setFormato(String formato) {

            this.formato = formato;
        }

        public String getDuracao() {

            return duracao;
        }

        public void setDuracao(String duracao) {

            this.duracao = duracao;
        }

        public String getPaisDeOrigem() {

            return paisDeOrigem;
        }

        public void setPaisDeOrigem(String paisDeOrigem) {

            this.paisDeOrigem = paisDeOrigem;
        }

        public String getIdiomaDeOrigem() {

            return idiomaDeOrigem;
        }

        public void setIdiomaDeOrigem(String idiomaDeOrigem) {

            this.idiomaDeOrigem = idiomaDeOrigem;
        }

        public String getEmissoraOriginal() {

            return emissoraOriginal;
        }

        public void setEmissoraOriginal(String emissoraOriginal) {

            this.emissoraOriginal = emissoraOriginal;
        }

        public String getDataInicioTransmissao() {

            return dataInicioTransmissao;
        }

        public void setDataInicioTransmissao(String dataInicioTransmissao) {
            this.dataInicioTransmissao = dataInicioTransmissao;
        }

        public int getNumeroTemporadas() {
            return numeroTemporadas;
        }

        public void setNumeroTemporadas(int numeroTemporadas) {

            this.numeroTemporadas = numeroTemporadas;
        }

        public int getNumeroEpisodios() {

            return numeroEpisodios;
        }

        public void setNumeroEpisodios(int numeroEpisodios) {

            this.numeroEpisodios = numeroEpisodios;
        }
    }


    public static class ArquivoTextoLeitura {

        private BufferedReader entrada;

        ArquivoTextoLeitura(String nomeArquivo) {

            try {
                entrada = new BufferedReader(new FileReader(nomeArquivo));
            }
            catch (FileNotFoundException excecao) {
                System.out.println("Arquivo nao encontrado");
            }
        }

        public void fecharArquivo() {

            try {
                entrada.close();
            }
            catch (IOException excecao) {
                System.out.println("Erro no fechamento do arquivo de leitura: " + excecao);
            }
        }

        @SuppressWarnings("finally")
        public String ler() {

            String textoEntrada = null;

            try {
                textoEntrada = entrada.readLine();
            }
            catch (EOFException excecao) { //Excecao de final de arquivo.
                textoEntrada = null;
            }
            catch (IOException excecao) {
                System.out.println("Erro de leitura: " + excecao);
                textoEntrada = null;
            }
            finally {
                return textoEntrada;
            }
        }
    }
}

