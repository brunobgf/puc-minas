import java.io.*;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in, "UTF-8");

        /**declaração e inicialização das variáveis*/
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
        /**entrada de dados do arquivo - END*/

        /**Queue - START**/
        Queue newQueue = new Queue();;
        Series dequeued;
        double avg = 0;
        String input;
        String seriesName;

        input = sc.nextLine();

        while (!input.equals("FIM")) {
            for (int i = 0; i < seriesArray.length; i++) {

                if (input.equals(seriesArray[i].getName())) {
                    try {
                        newQueue.enqueue(seriesArray[i]);
                        avg = newQueue.seasonsAvg();
                        System.out.println((int) Math.round(avg));
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

        avg = 0;

        try {
            for (int j = 0; j < qtd; j++) {

                input = sc.nextLine();

                if (input.equals("R")) {
                    dequeued = newQueue.dequeue();
                    System.out.print("(R) ");
                    dequeued.printName();

                } else {
                    seriesName = input.substring(2);

                    for (int k = 0; k < seriesArray.length; k++) {
                        if (seriesName.equals(seriesArray[k].getName())) {

                            newQueue.enqueue(seriesArray[k]);
                            avg = newQueue.seasonsAvg();
                            System.out.println((int) Math.round(avg));
                            break;
                        }
                    }
                }
            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

        try {
            newQueue.show();
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

        sc.close();

    }
}

/* Series class - START */

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
    public void printer(int j) {
        System.out.println("["+j+"]" +
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

class Cell {

    private Series queueSeries;
    private Cell nextCell;

    /**Constructors - START**/
    public Cell(Series newElement) {
        queueSeries = newElement;
        nextCell = null;
    }

    public Cell() {
        queueSeries = new Series();
        nextCell = null;
    }
    /**Constructors - END**/

    public Series getQueueSeries() {
        return queueSeries;
    }

    public void setQueueSeries(Series queueSeries) {
        this.queueSeries = queueSeries;
    }

    public Cell getNextCell() { return nextCell; }

    public void setNextCell(Cell nextCell) {
        this.nextCell = nextCell;
    }
}


/*
Cell class END
 */

/* Queue class - START */
class Queue {

    private Cell front;
    private Cell back;
    private int size;

    public Queue() { //cria celula sentinela
        Cell sentinel;

        sentinel = new Cell();
        front = sentinel;
        back = sentinel;
    }

    /*Retorna se a fila está vazia*/
    public boolean emptyQueue() {
        return (front == back ? true : false);
    }

    public void enqueue(Series newElement) { //enfileiramento

        Cell newCell = new Cell(newElement);

        back.setNextCell(newCell);
        back = newCell;
    }

    public Series dequeue() throws Exception {

        Cell unqueuedCell;
        Cell nexCell;

        if (!emptyQueue()) {
            unqueuedCell = front.getNextCell();
            nexCell = unqueuedCell.getNextCell();
            front.setNextCell(nexCell);

            if (unqueuedCell == back) {
                back = front;
            }
            return (unqueuedCell.getQueueSeries());

        } else {
            throw new Exception("Não foi possível desenfileirar nenhum item: a fila está vazia!");
        }
    }

    public void show() throws Exception {
        Cell aux;
        int count=0;

        if (! emptyQueue()) {

            aux = front.getNextCell();

            while (aux != null) {
                aux.getQueueSeries().printer(count);
                count++;
            }

        } else {
            throw new Exception("Não foi possível mostrar o conteúdo da fila: a fila está vazia!");
        }
    }

    /*Calculo da média das temporadas*/
    public double seasonsAvg(){
        Cell aux;
        double sum = 0, avg = 0, count = 0;

        aux = front.getNextCell();

        while (aux != null){
            sum = sum + aux.getQueueSeries().getSeasonNumber();
            count++;
        }

        avg = sum/count;
        return avg;
    }
}

/* TextFileRead - START */


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
            System.out.println("File closure error: " + exception);
        }
    }

    @SuppressWarnings("finally")
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

/* TextFileRead - END */

