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

        /** List - START */

        List newList;
        Series removed, newInsertion;
        String input, seriesName;
        String[] parts;
        int position;

        newList = new List();

        input = sc.nextLine();

        /* entrada com os nomes das séries e listagem senquencial das mesmas*/
        while (!input.equals("FIM")) {
            for (int i = 0; i < seriesArray.length; i++) {

                if (input.equals(seriesArray[i].getName())) {
                    try {
                        newList.insertLast(seriesArray[i]);
                    } catch (Exception e) {
                        System.out.println(e.getMessage());
                    }
                    break;
                }
            }
            input = sc.nextLine();
        }

        /* quantidade de séries que serão inseridas ou retiradas*/
        int qtd = sc.nextInt();
        sc.nextLine();

        /* processos inserir/remover */
        try {
            for (int j = 0; j < qtd; j++) {

                input = sc.nextLine();

                if (input.equals("RI")) {
                    removed = newList.removeFirst();
                    System.out.print("(R) ");
                    removed.printName();

                } else if (input.equals("RF")) {
                    removed = newList.removeLast();
                    System.out.print("(R) ");
                    removed.printName();

                } else {
                    seriesName = input.substring(0, 2);

                    if (seriesName.equals("R*")) {
                        seriesName = input.substring(3);

                        removed = newList.remove(Integer.parseInt(seriesName));

                        System.out.print("(R) ");
                        removed.printName();

                    } else if (seriesName.equals("II")) {
                        seriesName = input.substring(3);

                        for(int i=0;i<qtd;i++) {
                            newInsertion = seriesArray[i];

                            if (seriesName.equals(seriesArray[i].getName())) {
                                newList.insertFirst(newInsertion);
                            }
                        }

                    } else if (seriesName.equals("IF")) {
                        seriesName = input.substring(3);

                        for(int i=0;i<qtd;i++){
                            newInsertion=seriesArray[i];

                            if(seriesName.equals(seriesArray[i].getName())){
                                newList.insertLast(newInsertion);

                            }
                        }

                    } else if (seriesName.equals("I*")) {
                        parts = input.split(" ");
                        position = Integer.parseInt(parts[1]);
                        seriesName = parts[2];

                        for(int i = 0; i < qtd; i++){
                            newInsertion=seriesArray[i];
                            if(seriesName.equals(seriesArray[i].getName())){
                                newList.insert(newInsertion,position);
                            }
                        }

                    }
                }
            }

            /*Mostrar todas as series*/
            newList.show();

        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

        /** List - END */

        sc.close();


    }
}


class Cell {

    private Series listSeries;
    private Cell previousCell;
    private Cell nextCell;

    /**
     * Constructors - START
     **/
    public Cell(Series newElement) {
        listSeries = newElement;
        previousCell = null;
        nextCell = null;
    }

    public Cell() {
        listSeries = new Series();
        previousCell = null;
        nextCell = null;
    }

    /**
     * Constructors - END
     **/

    public Series getListSeries() {
        return listSeries;
    }

    public void setListSeries(Series listSeries) {
        this.listSeries = listSeries;
    }

    public Cell getPreviousCell() {
        return previousCell;
    }

    public void setPreviousCell(Cell previousCell) {
        this.previousCell = previousCell;
    }

    public Cell getNextCell() {
        return nextCell;
    }

    public void setNextCell(Cell nextCell) {
        this.nextCell = nextCell;
    }
}


class List {

    private Cell first;
    private Cell last;
    private int listSize; //posição das células da lista

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


    public void insertLast(Series newElement) {
        Cell newCell = new Cell(newElement);

        last.setNextCell(newCell);
        newCell.setPreviousCell(last);

        last = newCell;
        listSize++;
    }

    public void insert(Series newSeries, int position) throws Exception {

        Cell previous, newCell, nextCell;

        if ((position >= 0) && (position <= listSize)) {
            previous = first;

            for (int i = 0; i < position; i++) { //passa por cada célula
                previous = previous.getNextCell();
            }

            newCell = new Cell(newSeries);

            nextCell = previous.getNextCell();

            previous.setNextCell(newCell);
            newCell.setNextCell(nextCell);

            nextCell.setPreviousCell(newCell);
            newCell.setPreviousCell(previous);

            if (position == listSize) {  // a inserção ocorreu na última posição da lista
                last = newCell;
            }

            listSize++;

        } else
            throw new Exception("Não foi possível inserir o item na lista: a posição informada é inválida!");
    }

    public void insertFirst(Series newElement) {
        Cell newCell = new Cell(newElement);

        first.getNextCell().setPreviousCell(newCell);
        newCell.setNextCell(first.getNextCell());
        newCell.setPreviousCell(first);
        first.setNextCell(newCell);

        listSize++;
    }

    public Series removeFirst() throws Exception {
        Cell removed;

        if(! emptyList()){
            removed = first.getNextCell();
            removed.getNextCell().setPreviousCell(first);
            first.setNextCell(removed.getNextCell());

            removed.setNextCell(null);
            removed.setPreviousCell(null);

            listSize--;

            return (removed.getListSeries());
        }else
            throw new Exception("Não foi possível remover o último item da lista: a lista está vazia!");
    }


    public Series remove(int position) throws Exception {

        Cell previousCell, removedCell, nextCell;

        if (! emptyList()) {
            if ((position >= 0) && (position <= listSize)) {
                removedCell = first.getNextCell();
                for (int i = 0; i < position; i++) {
                    removedCell = removedCell.getNextCell();
                }


                if (!(removedCell == last)) {
                    previousCell = removedCell.getPreviousCell();
                    nextCell = removedCell.getNextCell();

                    previousCell.setNextCell(nextCell);
                    nextCell.setPreviousCell(previousCell);

                    removedCell.setNextCell(null);
                    removedCell.setPreviousCell(null);
                    listSize--;
                    return (removedCell.getListSeries());


                } else{
                    listSize--;
                    return removeLast();
                }

            } else
                throw new Exception("Não foi possível remover o item da lista: a posição informada é inválida!");
        } else
            throw new Exception("Não foi possível remover o item da lista: a lista está vazia!");
    }

    public Series removeLast() throws Exception {
        Cell removed, secondLast;

        if(! emptyList()){
            removed = last;
            secondLast = last.getPreviousCell();
            secondLast.setNextCell(null);
            removed.setPreviousCell(null);

            last = secondLast;

            listSize--;

            return (removed.getListSeries());

        } else
            throw new Exception("Não foi possível remover o último item da lista: a lista está vazia!");
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

