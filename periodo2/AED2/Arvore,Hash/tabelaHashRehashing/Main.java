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

        Hash newHashMap = new Hash(71);
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
                position = newHashMap.printPosition(input);
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

        writeFile.write("/t Comparações: " + newHashMap.countCompare + " /t Matricula: 754901 /t Tempo de execução em milisegundos: " + executionTime);

        writeFile.closeFile();
        /*Arquivo log de armazenamento - END*/

        sc.close();
    }
}

class Hash {

    private int M;
    private Series hashMap[];
    public int countCompare = 0;

    public Hash(int size) {
        this.M = size;
        hashMap = new Series[this.M];
        for(int i=0;i<this.M;i++)
            hashMap[i] = null;
    }

    /*
    ((valor ASCII correspondente ao nome da série) mod tamanho da tabela hash + k *
    ((valor ASCII correspondente ao nome da série) mod 23)) mod tamanho da tabela hash
     */

    private int hashFunction(int key, int i){
        return  (((key % this.M) + i * (key%23))%this.M);
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
        int convertedString, position, tryInsert;
        boolean inserted = false;
        convertedString = getASCII(newSeries.getName());

        tryInsert = 0;

        while((!inserted) && (tryInsert < this.M)){
            position = hashFunction(convertedString,tryInsert);
            if (hashMap[position] == null){
                hashMap[position] = newSeries;
                inserted = true;

            }else if(hashMap[position].getName().equals(newSeries.getName())){
                throw new Exception("Não foi possivel inserir o novo elemento na tabela hash: elemento inserido anteriormente");
            }
            else
                tryInsert++;
        }
    }

    public Series search(String key){
        int convertedKey,position, tryInsert;

        convertedKey = getASCII(key);

        tryInsert = 0;

        while(tryInsert<this.M){
            position = hashFunction(convertedKey, tryInsert);

            if((hashMap[position]==null)||(hashMap[position].getName().equals(key))) {
                countCompare++;
                return hashMap[position];
            }
            else
                tryInsert++; //colisao
        }
        return null;
    }

    public int printPosition(String input){
        int position;
        int tryInsert = 0;
        int convertedKey = getASCII(input);

        while(tryInsert<this.M){
            position = hashFunction(convertedKey, tryInsert);

            if((hashMap[position]==null)||(hashMap[position].getName().equals(input)))
                return position;
            else
                tryInsert++; //colisao
        }

        return 0;
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
