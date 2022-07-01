import java.util.Scanner;
import java.io.*;

public class Main {

    public static void main(String[] args) {

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

        /** Stack - START */
        Stack newStack;
        Series unstacked;
        String input;
        String seriesName;

        newStack = new Stack();

        input = sc.nextLine();

        /* entrada padrão com os nomes das séries e empilhamento das mesmas */
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

        /* quantidade de séries que serão empilhadas */
        int qtd = sc.nextInt();
        sc.nextLine();

        /* processos de desempilhar e empilhar */
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

        Stack inverseStack;
        inverseStack = new Stack();

        while (!newStack.emptyStack()) {
            try {
                inverseStack.stackUp(newStack.unstack());

            } catch (Exception e) {
                System.out.println(e.getMessage());
            }
        }

        try {
            inverseStack.show();
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

        sc.close();

    }

    /** Stack - END */
}

class Stack {

    private Cell bottom;
    private Cell top;

    /** Constructors - Start */
    public Stack() {
        Cell sentinel;

        sentinel = new Cell();
        bottom = sentinel;
        top = sentinel;
    }

    /** Constructors - End */

    /* Retorna se a pilha está vazia */
    public boolean emptyStack() {
        boolean resp;
        if (top == bottom) {
            resp = true;
        } else
            resp = false;
        return resp;
    }

    /* método de empilhamento LIFO */
    public void stackUp(Series newElement) {
        Cell newCell = new Cell(newElement);

        newCell.setNextCell(top);
        top = newCell;
    }

    /* método de desempilhar LIFO */
    public Series unstack() throws Exception {

        Cell unstacked;

        if (!emptyStack()) {
            unstacked = top;
            top = top.getNextCell();
            unstacked.setNextCell(null);
            return (unstacked.getStackSeries());
        } else {
            throw new Exception("Não foi possível desempilhar: a pilha está vazia!");
        }
    }

    /* método mostrar LIFO */
    public void show() throws Exception {
        Cell aux;
        int count = 0;

        if (!emptyStack()) {
            aux = top;

            
            while ((aux != null) && (aux != bottom)) {
                if (aux.getStackSeries().getName().equals(null)) {
                    break;
                }
                aux.getStackSeries().printer(count);
                aux = aux.getNextCell();
                count++;
            }
            

        } else {
            throw new Exception("Não foi possível consultar o elemento do topo da pilha: a pilha está vazia!");
        }
    }
}

class Cell {

    private Series stackSeries;
    private Cell nextCell;

    /** Constructors - START **/
    public Cell(Series newElement) {
        stackSeries = newElement;
        nextCell = null;
    }

    public Cell() {
        stackSeries = new Series();
        nextCell = null;
    }

    /** Constructors - END **/

    public Series getStackSeries() {
        return stackSeries;
    }

    public void setStackSeries(Series stackSeries) {
        this.stackSeries = stackSeries;
    }

    public Cell getNextCell() {
        return nextCell;
    }

    public void setNextCell(Cell nextCell) {
        this.nextCell = nextCell;
    }
}

class Series {

    // attribute declaration
    private String name, format, duration, countryOriginal, languageOriginal, tvChannel, dateStarting;
    private int seasonNumber, epNumber;

    // constructors
    Series(String name, String format, String duration, String countryOriginal, String languageOriginal,
            String tvChannel, String dateStarting, int seasonNumber, int epNumber) {
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

    // contrutor de inicialização
    Series() {
    }

    // clone
    public Series clone() {
        Series clone = new Series(this.name, this.format, this.duration, this.countryOriginal, this.languageOriginal,
                this.tvChannel, this.dateStarting, this.seasonNumber, this.epNumber);
        return clone;
    }

    // read
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

    // print
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
        System.out.println(getName());
    }

    // gets n sets
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
        } catch (FileNotFoundException exception) {
            System.out.println("File not found");
        }
    }

    public void closeFile() {

        try {
            input.close();
        } catch (IOException exception) {
            System.out.println("Closure file error: " + exception);
        }
    }

    public String read() {

        String inputText = null;

        try {
            inputText = input.readLine();
        } catch (EOFException exception) {
            inputText = null;
        } catch (IOException exception) {
            System.out.println("Reading error: " + exception);
            inputText = null;
        } finally {
            return inputText;
        }
    }
}
