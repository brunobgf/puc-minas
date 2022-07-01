import java.io.*;
import java.util.Scanner;

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

        /*Queue - START*/
        Queue newQueue;
        Series dequeued;
        double avg = 0;
        String input;
        String seriesName;

        newQueue = new Queue(21);

        input = sc.nextLine();

        while (!input.equals("FIM")) {
            for (int i = 0; i < seriesArray.length; i++) {

                if (input.equals(seriesArray[i].getName())) {

                    if (newQueue.fullQueue()) {
                        try {
                            dequeued = newQueue.dequeue();
                        } catch (Exception e) {
                            System.out.println(e.getMessage());
                        }
                    }

                    try {
                        newQueue.enqueue(seriesArray[i]);
                        avg = newQueue.seasonsAvg(seriesArray);
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

                            if (newQueue.fullQueue()) {
                                dequeued = newQueue.dequeue();
                            }

                            newQueue.enqueue(seriesArray[k]);
                            avg = newQueue.seasonsAvg(seriesArray);
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
            newQueue.show(seriesObj);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

        sc.close();

    }

    /*queue - END*/
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
    public void printer(Series[] seriesObj, int i, int j) {
        System.out.println("["+j+"]" +
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
/* Series class - END */

/* Queue class - START */
class Queue {

    private Series[] queueSeries;
    private int front;
    private int back;
    private int size;

    //tamanho 21

    public Queue(int size) {

        queueSeries = new Series[size];
        front = 0;
        back = 0;
        this.size = size;
    }

    /*
    Criação de uma fila vazia
     */

    public Queue() {
        queueSeries = new Series[0];
        front = 0;
        back=0;
        this.size=0;
    }

    public boolean emptyQueue() {
        return (front == back ? true : false);
    }


    public boolean fullQueue() {
        return (((back + 1) % size) == (front % size) ? true : false);
    }

    public void enqueue(Series newElement) throws Exception{

        int position;

        if (! fullQueue()) {
            position = back % size;
            queueSeries[position] = newElement;
            back++;
        } else{
            throw new Exception("Não foi possível enfileirar o novo elemento: a fila está cheia!");

        }
    }

    public Series dequeue() throws Exception{

        Series dequeuedElement;

        int position;

        if (! emptyQueue()) {
            position = front % size;
            dequeuedElement = queueSeries[position];
            front++;
            return dequeuedElement;
        } else
            throw new Exception("Não foi possível desenfileirar nenhum elemento: a fila está vazia!");
    }

    public void show(Series sQueue) throws Exception{

        int position, count=0;
        if (! emptyQueue()) {
            for (int i = front; i < back; i++) {
                position = i % size;
                sQueue.printer(queueSeries, position, count);
                count++;
            }
        } else
            throw new Exception ("Não foi possível mostrar o conteúdo da fila: a fila está vazia!");
    }
    
    /*Calculo da média das temporadas*/
    public double seasonsAvg(Series[] seriesObj){
        double sum = 0, avg =0, count = 0;
        int position = 0;
        for(int i = front; i<back;i++){
            position = i%size;
            sum = sum + queueSeries[position].getSeasonNumber();
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

