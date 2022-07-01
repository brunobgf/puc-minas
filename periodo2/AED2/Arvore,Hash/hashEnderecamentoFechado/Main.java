import java.util.HashMap;
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

        /** Hash Map - START */

        Hash newHashMap = new Hash(31);
        Series seriesObject;
        String input;
        int position;

        input = sc.nextLine();

        while(!input.equals("FIM")){
            for (int i = 0; i < seriesQtd; i++){
                if(input.equals(seriesArray[i].getName())){
                    try {
                        newHashMap.insert(seriesArray[i]);
                    } catch (Exception erro) {
                        System.out.println(erro.getMessage());
                    }
                    break;
                }
            }
            input = sc.nextLine();
        }

        input = sc.nextLine();


        while(!input.equals("FIM")){
            seriesObject = newHashMap.search(input);
            if(seriesObject!=null){
                position = newHashMap.print(input);
                System.out.println(position +" " + "SIM");
            }

            else
                System.out.println("NAO");
            input = sc.nextLine();
        }

        /** Hash Map  - END */

        /*Arquivo log de armazenamento - START*/
        long executionTime = System.currentTimeMillis();

        TextFileWrite writeFile = new TextFileWrite("754901_hashSeparado.txt");

        writeFile.write("Comparações: " + newHashMap.countCompare + " /t Matricula: 754901 /t Tempo de execução em milisegundos: " + executionTime);

        writeFile.closeFile();
        /*Arquivo log de armazenamento - END*/

        sc.close();
    }
}

class Cell {

    private Series listSeries;
    private Cell nextCell;

    /**
     * Constructors - START
     **/
    public Cell(Series newElement) {
        listSeries = newElement;
        nextCell = null;
    }

    public Cell() {
        listSeries = new Series();
        nextCell = null;
    }

    /**
     * Constructors - END
     **/

    /**
     *Getters and Setters - START
     */

    public Series getListSeries() {return listSeries;}

    public void setListSeries(Series listSeries) {this.listSeries = listSeries;}

    public Cell getNextCell() {return nextCell;}

    public void setNextCell(Cell nextCell) {this.nextCell = nextCell;}

    /**
     *Getters and Setters - END
     */
}

class List {

    private Cell first;
    private Cell last;
    private int listSize; //posição das células da lista
    public int countCompare = 0;

    /*Contructor*/
    public List() {
        Cell sentinel;

        sentinel = new Cell();
        first = sentinel;
        last = sentinel;
        listSize = 0;
    }

    public boolean emptyList() {
        return (first == last);
    }

    public void insert(Series newSeries, int position) throws Exception {

        Cell aux, newCell, nextCell;
        int i;

        if ((position >= 0) && (position <= listSize)) {
            for (i = 0, aux = first; i < position; i++) { //passa por cada célula
                aux = aux.getNextCell();
            }
            newCell = new Cell(newSeries);

            nextCell = aux.getNextCell();

            aux.setNextCell(newCell);
            newCell.setNextCell(nextCell);

            if (position == listSize) {  // a inserção ocorreu na última posição da lista
                last = newCell;
            }

            listSize++;

        } else
            throw new Exception("Não foi possível inserir o item na lista: a posição informada é inválida!");
    }

    public Series remove(int position) throws Exception {

        Cell aux, removedCell, nextCell;
        Series item = null;
        int i;

        if (! emptyList()) {
            if ((position >= 0) && (position <= listSize)) {
                for (i = 0, aux=first; i < position; i++) {
                    aux = aux.getNextCell();
                }

                removedCell = aux.getNextCell();
                nextCell = removedCell.getNextCell();

                aux.setNextCell(nextCell);

                if(last == removedCell)
                    last = aux;

                listSize--;

                item = removedCell.getListSeries();

            } else
                throw new Exception("Não foi possível remover o item da lista: a posição informada é inválida!");
        } else
            throw new Exception("Não foi possível remover o item da lista: a lista está vazia!");

        return item;
    }

    public Series search(String data){
        Cell aux;
        aux = first.getNextCell();

        while(aux != null){
            if(aux.getListSeries().getName().equals(data)){
                countCompare++;
                return aux.getListSeries();
            }
            aux = aux.getNextCell();
        }
        return null;

    }



    public void show() throws Exception {

        Cell aux;
        int count = 0;

        if (! emptyList()) {
            aux = first.getNextCell();

            while (aux != null) {
                aux.getListSeries().printer(count);
                aux = aux.getNextCell();
                count++;
            }

        } else
            throw new Exception("Não foi possível imprimir o conteúdo da lista: a lista está vazia!");
    }
}

class Hash {

    private int M;
    private List hashMap[];
    public int countCompare;

    public Hash(int size) {
        this.M = size;
        hashMap = new List[this.M];
        for(int i=0;i<M;i++){
            hashMap[i] = new List();
        }
    }

    //Função que recebe a função de transformação
    //((valor ASCII correspondente ao nome da série) mod tamanho da tabela hash)
    //Tamanho da tabela = 31

    private int hashFunction(int key){
        return (key % this.M);
    }

    public int getASCII(String input){
        int convertedToASCII = 0;

        for(int i=0; i<input.length(); i++)
        {
            int asciiValue = input.charAt(i);
            convertedToASCII = convertedToASCII+ asciiValue;
        }

        return convertedToASCII;
    }

    public void insert(Series newSeries) throws Exception {
        int convertedString;
        int position;
        convertedString = getASCII(newSeries.getName());
        //valor ASCII correspondente ao nome da série
        position = hashFunction(convertedString);


        if(hashMap[position].search(newSeries.getName())==null) {
            hashMap[position].insert(newSeries, 0);
        }
        else
            throw new Exception("Não foi possivel inserir o novo elemento na tabela hash: elemento inserido anteriormente");
    }

    public Series search(String key){
        int convertedKey;
        int position;
        convertedKey = getASCII(key);
        position = hashFunction(convertedKey);

        //Função da lista de pesquisar
        return hashMap[position].search(key);
    }

    public int print(String input){
        int convertedInput;
        int position;
        convertedInput = getASCII(input);
        position = hashFunction(convertedInput);

        return position;

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

class TextFileWrite {

    private BufferedWriter output;

    TextFileWrite(String fileName) {

        try {
            output = new BufferedWriter(new FileWriter(fileName));
        }
        catch (FileNotFoundException exception) {
            System.out.println("File not found");
        }
        catch (IOException exception) {
            System.out.println("Opening file error " + exception);
        }
    }

    public void closeFile() {

        try {
            output.close();
        }
        catch (IOException exception) {
            System.out.println("Closure file error: " + exception);
        }
    }

    public void write(String inputText) {

        try {
            output.write(inputText);
            output.newLine();
        }
        catch (IOException exception){
            System.out.println("Input/output error " + exception);
        }
    }
}


