import java.util.Scanner;
import java.io.*;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in, "UTF-8");

        /*declaração e inicialização das variáveis*/
        Series seriesObj = new Series();
        String inputString;
        int seriesQtd, countFileLine = 0;

        /*objeto recebe arquivo de texto */
        TextFileRead inputFile = new TextFileRead("/tmp/data.txt");

        /*leitura do arquivo - START*/
        inputFile.read();
        inputString = inputFile.read();

        while (inputString != null) {
            countFileLine++;
            inputString = inputFile.read();
        }

        inputFile.closeFile();
        /*leitura do arquivo - END*/

        /*entrada de dados do arquivo - START*/
        seriesQtd = countFileLine; //quantidade de séries no arquivo

        inputFile = new TextFileRead("/tmp/data.txt");
        inputFile.read();

        Series[] seriesArray = new Series[seriesQtd];

        /*entrada de dados - preenche vetor com séries*/
        for (int i = 0; i < seriesQtd; i++) {
            inputString = inputFile.read();
            seriesObj.reader(seriesObj, inputString);
            seriesArray[i] = new Series(seriesObj.getName(), seriesObj.getFormat(), seriesObj.getDuration(), seriesObj.getCountryOriginal(), seriesObj.getLanguageOriginal(), seriesObj.getTvChannel(), seriesObj.getDateStarting(), seriesObj.getSeasonNumber(), seriesObj.getEpNumber());
        }

        inputFile.closeFile();
        /*entrada de dados do arquivo - END*/

        /**Stack - START*/
        Stack newStack;
        Series unstacked;
        String input;
        String seriesName;

        newStack = new Stack(62);

        input = sc.nextLine();

        while (!input.equals("FIM")) {
            for (int i = 0; i < seriesArray.length; i++) {

                if (input.equals(seriesArray[i].getName())) {
                    try {
                        newStack.stackUp(seriesArray[i]);
                    } catch (Exception e) {
                        System.out.println(e.getMessage());
                    }
                    break;
                }
            }
            input = sc.nextLine();
        }

        int qtd = sc.nextInt();
        sc.nextLine();

        try {
            for (int j = 0; j < qtd; j++) {

                input = sc.nextLine();

                if (input.equals("D")) {
                    unstacked = newStack.unstack();
                    System.out.print("(D) ");
                    unstacked.printName();

                } else {
                    seriesName = input.substring(2);

                    for (int k = 0; k < seriesArray.length; k++) {
                        if (seriesName.equals(seriesArray[k].getName())) {

                            newStack.stackUp(seriesArray[k]);
                        }
                    }
                }
            }

        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

        try {
            newStack.show(seriesObj);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

        sc.close();

    }

    /**Stack - END*/
}

class Stack {

    private Series[] stackSeries;
    private int top;
    private int size;

    /**Constructors - Start*/
    public Stack() {
        stackSeries = new Series[0];
        top = 0;
        this.size = 0;
    }

    public Stack(int size) {
        stackSeries = new Series[size];
        top = 0;
        this.size = size;
    }
    /** Constructors - End*/

    /*Retorna se a pilha está vazia*/
    public boolean emptyStack() {
        return (top == 0 ? true : false);
    }

    /*Retorna se a pilha está cheia*/
    public boolean fullStack() {
        return (top == stackSeries.length ? true : false);
    }

    /*método de empilhamento LIFO*/
    public void stackUp(Series newElement) {
        if (!fullStack()) {
            stackSeries[top] = newElement;
            top++;
        }
    }

    /*método de desempilhar LIFO*/
    public Series unstack() throws Exception {
        Series unstacked;

        if (!emptyStack()) {
            top--;
            unstacked = stackSeries[top];
            return unstacked;
        } else {
            throw new Exception("Não foi possível desempilhar: a pilha está vazia!");
        }
    }

    /*método mostrar LIFO*/
    public void show(Series sStack) throws Exception {


        if (!emptyStack()) {
            for (int i = 0; i < top; i++) {

                sStack.printer(stackSeries, i);
            }

        } else {
            throw new Exception("Não foi possível consultar o elemento do topo da pilha: a pilha está vazia!");
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
    public void printer(Series[] seriesObj, int i) {
        System.out.println("[" + i + "] " +
                seriesObj[i].getName() + " ## "
                + seriesObj[i].getFormat() + " ## "
                + seriesObj[i].getDuration() + " ## "
                + seriesObj[i].getCountryOriginal() + " ## "
                + seriesObj[i].getLanguageOriginal() + " ## "
                + seriesObj[i].getTvChannel() + " ## "
                + seriesObj[i].getDateStarting() + " ## "
                + seriesObj[i].getSeasonNumber() + " ## "
                + seriesObj[i].getEpNumber());
    }

    public void printName() {
        System.out.println(getName());
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

