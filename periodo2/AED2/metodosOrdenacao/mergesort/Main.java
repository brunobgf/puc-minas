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

        /*ordenação merge - START*/
        Merge mergeSortObject = new Merge();

        Series[] sortMethodArray = mergeSortObject.mergesort(sortSeriesArray,0, seriesQtd-1); //recebe o vetor ordenado, esquerda = 0 e direito = length -1

        for (int i = 0; i < seriesQtd; i++) {
            sortMethodArray[i].printer(sortMethodArray[i]); //leitura do vetor ordenado
        }
        /*ordenação merge sort - END*/



        /*Arquivo log de armazenamento - START*/
        long executionTime = System.currentTimeMillis();

        TextFileWrite writeFile = new TextFileWrite("754901_mergesort.txt");

        writeFile.write("Matricula: 754901 \t" + "Tempo de execução em milisegundos: " + executionTime + "\t Numero de trocas entre elementos: " + mergeSortObject.countSwitch + "\t Numero de movimentacoes no vetor: " + mergeSortObject.countCompare);

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

/* Insertion class - START */
class Merge {

    public int countSwitch, countCompare = 0;

    public Series[] mergesort(Series[] sortSeriesArray, int left, int right) {

        if (left < right) {

            int middle = (left + right) / 2;
            mergesort(sortSeriesArray, left, middle);
            mergesort(sortSeriesArray, middle + 1, right);
            intercalar(sortSeriesArray, left, middle, right);
            countSwitch++;
        }
        return sortSeriesArray;
    }

    private boolean compare(Series serie1, Series serie2) {
        if (serie1.getLanguageOriginal().compareTo(serie2.getLanguageOriginal()) < 0) {
            countCompare++;
            return true;
        }
        else if (serie1.getLanguageOriginal().compareTo(serie2.getLanguageOriginal()) == 0) {
            if (serie1.getName().compareTo(serie2.getName()) < 0) {
                return true;
            }
        }
        return false;
    }

    private void intercalar(Series[] array, int left, int middle, int right) {

        int n1, n2, i, j, k;


        //Definir tamanho dos dois subarrays
        n1 = middle - left + 1;
        n2 = right - middle;

        Series[] a1 = new Series[n1];
        Series[] a2 = new Series[n2];

        //Inicializar primeiro subarray
        for (i = 0; i < n1; i++) {
            a1[i] = array[left + i];
        }

        //Inicializar segundo subarray
        for (j = 0; j < n2; j++) {
            a2[j] = array[middle + j + 1];
        }

        //Intercalação propriamente dita
        for (i = j = 0, k = left; (i < n1 && j < n2); k++) {
            if (compare(a1[i], a2[j]) == true) {
                array[k] = a1[i++];
            }
            else {
                array[k] = a2[j++];
            }
        }

        if (i == n1)
            for (; k <= right; k++) {
                array[k] = a2[j++];
            }
        else
            for (; k <= right; k++) {
                array[k] = a1[i++];
            }
    }
}
/* Merge class - END */

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