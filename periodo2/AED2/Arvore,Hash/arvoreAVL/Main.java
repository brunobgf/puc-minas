import java.util.Scanner;
import java.io.*;

public class Main {

    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in, "UTF-8");

        /* declaração e inicialização das variáveis */
        Series seriesObj = new Series();
        String inputString;
        int seriesQtd, countFileLine = 0;

        /* objeto recebe arquivo de texto */
        TextFileRead inputFile = new TextFileRead("/tmp/data.txt");

        /* leitura do arquivo - START */
        inputFile.read();
        inputString = inputFile.read();

        while (inputString != null) {
            countFileLine++;
            inputString = inputFile.read();
        }

        inputFile.closeFile();
        /* leitura do arquivo - END */

        /* entrada de dados do arquivo - START */
        seriesQtd = countFileLine; // quantidade de séries no arquivo

        inputFile = new TextFileRead("/tmp/data.txt");
        inputFile.read();

        Series[] seriesArray = new Series[seriesQtd];

        /* entrada de dados - preenche vetor com séries */
        for (int i = 0; i < seriesQtd; i++) {
            inputString = inputFile.read();
            seriesObj.reader(seriesObj, inputString);
            seriesArray[i] = new Series(seriesObj.getName(), seriesObj.getFormat(), seriesObj.getDuration(),
                    seriesObj.getCountryOriginal(), seriesObj.getLanguageOriginal(), seriesObj.getTvChannel(),
                    seriesObj.getDateStarting(), seriesObj.getSeasonNumber(), seriesObj.getEpNumber());
        }

        inputFile.closeFile();
        /* entrada de dados do arquivo - END */

        /** Binary Search Tree (BST) - START */

        BST newTree = new BST();
        Series seriesObject;
        String input;

        input = sc.nextLine();

        while(!input.equals("FIM")){
            for (int i = 0; i < seriesQtd; i++){
                if(input.equals(seriesArray[i].getName())){
                    try {
                        newTree.insert(seriesArray[i]);
                    } catch (Exception erro) {
                        System.out.println(erro.getMessage());
                    }
                }
            }
            input = sc.nextLine();
        }

        input = sc.nextLine();

        while(!input.equals("FIM")) {
            seriesObject = newTree.search(input);
            if(seriesObject != null)
                System.out.println("SIM");
            else
                System.out.println("NAO");
            input = sc.nextLine();
        }

        /** Binary Search Tree (BST) */

        sc.close();
    }
}

class Node {

    private Series itemSeries;
    private Node left;
    private Node right;

    /**
     * Constructors - START
     **/

    public Node(){
        itemSeries = new Series();
        left = null;
        right = null;

    }

    public Node(Series register) {
        itemSeries = register;
        left = null;
        right = null;
    }


    /**
     * Constructors - END
     **/

    /**
     * Getters and Setters - START
     **/
    public Node getLeft() {
        return left;
    }

    public void setLeft(Node left) {
        this.left = left;
    }

    public Node getRight() {
        return right;
    }

    public void setRight(Node right) {
        this.right = right;
    }

    public Series getItemSeries() {
        return itemSeries;
    }

    public void setItemSeries(Series itemSeries) {
        this.itemSeries = itemSeries;
    }

    /**
     * Getters and Setters  - END
     **/


}

class BST {
    //BST = Binary Search Tree
    private Node root;

    //Cria uma nova árvore binária de series vazia.
    public BST(){
        root = null;
    }

    // Método booleano que indica se a árvore está vazia ou não.

    public Boolean emptyTree(){
        return (this.root == null);
    }

    // Metodo que encapsula a adição recursiva de series à árvore.
    public void insert(Series newSeries) throws Exception {
        this.root = insertSeries(this.root, newSeries);
    }

    // Método recursivo responsável por adicionar uma serie à árvore.
    private Node insertSeries(Node subRoot, Series newSeries) throws Exception {
        // Se a raiz da árvore ou sub-árvore for null, a árvore está vazia e então é possivel adicionar uma nova Serie
        if (subRoot == null)
            subRoot = new Node(newSeries);
        else if ( newSeries.getName().compareTo(subRoot.getItemSeries().getName()) == 0)
            throw new Exception("Não foi possível inserir o item na árvore: chave já inseriada anteriormente!");
        else if ( newSeries.getName().compareTo(subRoot.getItemSeries().getName()) > 0 )
            subRoot.setRight(insertSeries(subRoot.getRight(),newSeries));
        else
            subRoot.setLeft(insertSeries(subRoot.getLeft(),newSeries));
        /// Retorna a raiz atualizada da árvore ou sub-árvore em que o aluno foi adicionado.
        return subRoot;
    }

    // Metodo que encapsula a pesquisa recursiva de series à árvore.
    public Series search(String newSeries) throws Exception {
        return searchSeries(this.root, newSeries);
    }

    // Método recursivo responsável por pesquisar uma serie à árvore.
    private Series searchSeries(Node subRoot, String newSeries) throws Exception {
        // Se a raiz da árvore ou sub-árvore for null, a árvore está vazia e então é possivel adicionar uma nova Serie
        if (subRoot == null)
            return null;
        else if (newSeries.compareTo(subRoot.getItemSeries().getName()) == 0){
            subRoot.getItemSeries().printName();
            return subRoot.getItemSeries();
        }
        else if (newSeries.compareTo(subRoot.getItemSeries().getName()) > 0){
            subRoot.getItemSeries().printName();
            return searchSeries(subRoot.getRight(),newSeries);
        }
        else{
            subRoot.getItemSeries().printName();
            return searchSeries(subRoot.getLeft(),newSeries);
        }
    }
}

class Series {

    //attribute declaration
    private String name, format, duration, countryOriginal, languageOriginal, tvChannel, dateStarting;
    private int seasonNumber, epNumber;

    //constructors
    Series(String name, String format, String duration, String countryOriginal, String languageOriginal, String tvChannel, String dateStarting, int seasonNumber, int epNumber) {
        this.name = name;
        this.format = format;
        this.duration = duration;
        this.countryOriginal = countryOriginal;
        this.languageOriginal = languageOriginal;
        this.tvChannel = tvChannel;
        this.dateStarting = dateStarting;
        this.seasonNumber = seasonNumber;
        this.epNumber = epNumber;
    }

    //contrutor de inicialização
    Series() {
    }

    //clone
    public Series clone() {
        Series clone = new Series(this.name, this.format, this.duration, this.countryOriginal, this.languageOriginal, this.tvChannel, this.dateStarting, this.seasonNumber, this.epNumber);
        return clone;
    }

    //read
    public Series reader(Series seriesObj, String inputString) {

        String[] splitInput = inputString.split(";");

        seriesObj.setName(splitInput[0]);
        seriesObj.setFormat(splitInput[1]);
        seriesObj.setDuration(splitInput[2]);
        seriesObj.setCountryOriginal(splitInput[3]);
        seriesObj.setLanguageOriginal(splitInput[4]);
        seriesObj.setTvChannel(splitInput[5]);
        seriesObj.setDateStarting(splitInput[6]);
        seriesObj.setSeasonNumber(Integer.parseInt(splitInput[7]));
        seriesObj.setEpNumber(Integer.parseInt(splitInput[8]));

        return seriesObj;
    }

    //print
    public void printer(int i) {
        System.out.println("[" + i + "]" +
                getName() + " ## "
                + getFormat() + " ## "
                + getDuration() + " ## "
                + getCountryOriginal() + " ## "
                + getLanguageOriginal() + " ## "
                + getTvChannel() + " ## "
                + getDateStarting() + " ## "
                + getSeasonNumber() + " ## "
                + getEpNumber());
    }

    public void printName() {
        System.out.printf("[" +getName()+ "]" + " - ");
    }

    //gets n sets
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getFormat() {
        return format;
    }

    public void setFormat(String format) {
        this.format = format;
    }

    public String getDuration() {
        return duration;
    }

    public void setDuration(String duration) {
        this.duration = duration;
    }

    public String getCountryOriginal() {
        return countryOriginal;
    }

    public void setCountryOriginal(String countryOriginal) {
        this.countryOriginal = countryOriginal;
    }

    public String getLanguageOriginal() {
        return languageOriginal;
    }

    public void setLanguageOriginal(String languageOriginal) {
        this.languageOriginal = languageOriginal;
    }

    public String getTvChannel() {
        return tvChannel;
    }

    public void setTvChannel(String tvChannel) {
        this.tvChannel = tvChannel;
    }

    public String getDateStarting() {
        return dateStarting;
    }

    public void setDateStarting(String dateStarting) {
        this.dateStarting = dateStarting;
    }

    public int getSeasonNumber() {
        return seasonNumber;
    }

    public void setSeasonNumber(int seasonNumber) {
        this.seasonNumber = seasonNumber;
    }

    public int getEpNumber() {
        return epNumber;
    }

    public void setEpNumber(int epNumber) {
        this.epNumber = epNumber;
    }


}

class TextFileRead {

    private BufferedReader input;

    TextFileRead(String fileName) {

        try {
            input = new BufferedReader(new FileReader(fileName));
        }
        catch (FileNotFoundException exception) {
            System.out.println("File not found");
        }
    }

    public void closeFile() {

        try {
            input.close();
        }
        catch (IOException exception) {
            System.out.println("Closure file error: " + exception);
        }
    }

    public String read() {

        String inputText = null;

        try {
            inputText = input.readLine();
        }
        catch (EOFException exception) {
            inputText = null;
        }
        catch (IOException exception) {
            System.out.println("Reading error: " + exception);
            inputText = null;
        }
        finally {
            return inputText;
        }
    }
}

