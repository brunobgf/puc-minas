public class Aplicacao {


    /*
    Autor: Bruno Gomes Ferreira
    Data: 24/03/2022

    Impressão aleatória de dados de séries

Crie uma classe Serie com os atributos privados: nome (String), formato (String),
duração (String), país de origem (String), idioma de origem (String), emissora de
televisão original (String), data de início da transmissão original (String), número
de temporadas (int), número de episódios (int).
Sua classe também terá, pelo menos, dois construtores, e os métodos gets, sets,
clone, ler e imprimir. O método imprimir exibe os valores dos atributos do objeto
(observe  o  formato  de  cada  linha  da  saída  esperada)  e  o  ler  lê  os  atributos  de
um objeto.
Seu  programa  deve  ler  e  processar  a  entrada  padrão  que  apresenta,  em  sua
primeira linha, a quantidade de séries que devem ser tratadas em seguida. Você
deve  então  preencher  um  vetor  de  objetos  da  classe  Serie  com  os  dados  das
diversas séries informadas na entrada padrão.
Depois,  serão  informadas,  também  na  entrada  padrão,  várias  linhas,  cada  uma
contendo uma string indicando o nome da série cujos dados devem ser exibidos
na saída padrão. A última linha da entrada contém a palavra FIM.
Na  saída  padrão,  para  cada  nome  lido  da  entrada,  escreva  uma  linha  com  os
dados do registro correspondente.
A saída padrão deve obedecer o seguinte formato:
nome  ##  formato  ##  duração  ##  país  de  origem  ##  idioma  de  origem  ##
emissora  de  televisão  original  ##  data  de  início  da  transmissão  original  ##
número de temporadas ## número de episódios
 
     */


    public static void main(String[] args) {
        int i;
        MyIO.setCharset("UTF-8");
        Serie s = new Serie();
        int qtdSeries;
        qtdSeries = Integer.parseInt(MyIO.readLine());
        Serie[] vetorSerie = new Serie[qtdSeries];
        String entrada = null;


        //Popula o vetor de objetos (serie) lendo as strings


        for (i = 0; i < qtdSeries; i++) {
            entrada = MyIO.readLine();
            s.ler(s, entrada);
            vetorSerie[i] = new Serie(s.getNome(), s.getFormato(), s.getDuracao(), s.getPaisDeOrigem(), s.getIdiomaDeOrigem(), s.getEmissoraOriginal(), s.getDataInicioTransmissao(), s.getNumeroTemporadas(), s.getNumeroEpisodios());
        }

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
}

