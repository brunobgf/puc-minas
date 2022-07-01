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

        /*entrada padrão com nomes das séries - START*/
        int inputCount = 0;

        seriesQtd = sc.nextInt();

        sc.nextLine();

        Series[] sortSeriesArray = new Series[seriesQtd];

        while (inputCount < seriesQtd) {
            inputString = sc.nextLine();
            for (int i = 0; i < seriesArray.length; i++) {
                if (inputString.equals(seriesArray[i].getName())) {
                    sortSeriesArray[inputCount] = new Series(seriesArray[i].getName(), seriesArray[i].getFormat(), seriesArray[i].getDuration(), seriesArray[i].getCountryOriginal(), seriesArray[i].getLanguageOriginal(), seriesArray[i].getTvChannel(), seriesArray[i].getDateStarting(), seriesArray[i].getSeasonNumber(), seriesArray[i].getEpNumber());
                }
            }
            inputCount++;
        }
        /*entrada padrão - END*/


        /*ordenação bubble sort - START*/
        Bubblesort bubbleSortSeries = new Bubblesort();

        Series[] sortMethodArray = bubbleSortSeries.sortArray(sortSeriesArray,seriesQtd);

        for(int i = 0; i < seriesQtd; i++){
            sortMethodArray[i].printer(sortMethodArray[i]);
        }
        /*ordenação bubble sort - END*/

        /*Arquivo log de armazenamento - START*/
        long executionTime = System.currentTimeMillis();

        TextFileWrite writeFile = new TextFileWrite("754901_bolha.txt");

        writeFile.write("Matricula: 754901\t" + "Tempo de execução em milisegundos: " + executionTime + "\t Numero de trocas entre elementos: " + bubbleSortSeries.countSwitch + "\t Numero de movimentacoes no vetor: " + bubbleSortSeries.countCompare);

        writeFile.closeFile();
        /*Arquivo log de armazenamento - END*/

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
    public void printer(Series seriesObj) {
        System.out.println(
                seriesObj.getName() + " ## "
                        + seriesObj.getFormat() + " ## "
                        + seriesObj.getDuration() + " ## "
                        + seriesObj.getCountryOriginal() + " ## "
                        + seriesObj.getLanguageOriginal() + " ## "
                        + seriesObj.getTvChannel() + " ## "
                        + seriesObj.getDateStarting() + " ## "
                        + seriesObj.getSeasonNumber() + " ## "
                        + seriesObj.getEpNumber());
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

/* Bubblesort class - START */
class Bubblesort {

    public int countSwitch, countCompare = 0;

    private boolean compare(Series serie1, Series serie2) {
        if (serie1.getDuration().compareTo(serie2.getDuration()) > 0) {
            countCompare++;
            return true;
        }
        else if (serie1.getDuration().compareTo(serie2.getDuration()) == 0) {
            if (serie1.getName().compareTo(serie2.getName()) > 0) {
                return true;
            }
        }
        return false;
    }

    public Series[] sortArray(Series[] sortSeriesArray, int n) {

        for (int i = (n - 1); i > 0; i--) {
            for (int j = 0; j < i; j++) {
                if (compare(sortSeriesArray[j], sortSeriesArray[j + 1]) == true) {
                    Series temp = sortSeriesArray[j];
                    sortSeriesArray[j] = sortSeriesArray[j + 1];
                    sortSeriesArray[j + 1] = temp;
                    countSwitch++;
                }
            }
        }
        return sortSeriesArray;
    }
}
/* Bubblesort class - END */

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

/* TextFileWrite - START */

class TextFileWrite {
    private BufferedWriter output;

    TextFileWrite(String fileName) {

        try {
            output = new BufferedWriter(new FileWriter(fileName));
        } catch (FileNotFoundException exception) {
            System.out.println("File not found");
        } catch (IOException exception) {
            System.out.println("Opening file error " + exception);
        }
    }

    public void closeFile() {

        try {
            output.close();
        } catch (IOException exception) {
            System.out.println("Closure file error: " + exception);
        }
    }

    public void write(String inputText) {

        try {
            output.write(inputText);
            output.newLine();
        } catch (IOException exception) {
            System.out.println("Input/output error " + exception);
        }
    }
}


/* TextFileWrite - END */