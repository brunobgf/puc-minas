import java.util.Scanner;
import java.io.*;
public class Main {

    /*
    Função para verificar se a expressão é bem formada, ou seja, se ela abrir com [ deve fechar com]
    A verificação é feita através dos métodos de empilhar(stackUp) e desempilhar(unstack)
     */

    public static boolean bemFormada(String s) {
        Stack newStack = new Stack();
        String[] vetString;
        vetString = s.split("");

        for(int i = 0; i < s.length(); i++) {
            if((vetString[i].equals("[")) ||(vetString[i].equals("(")) ||(vetString[i].equals("{")))  {
                newStack.stackUp(vetString[i]);

            } else if(vetString[i].equals("]") ) {

                if((newStack.emptyStack()) || (!(newStack.unstack().charAt(0)=='['))) {
                    return false;
                }
            } else if(vetString[i].equals(")") ) {
                if((newStack.emptyStack()) || (!(newStack.unstack().charAt(0)=='('))) {
                    return false;
                }
            } else if(vetString[i].equals("}")){
                if((newStack.emptyStack()) || (!(newStack.unstack().charAt(0)=='{'))) {
                    return false;
                }
            }

        }
        return newStack.emptyStack();

    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in, "UTF-8");

        /*declaração e inicialização das variáveis*/

        String input;

        /**Stack - START*/

        input = sc.nextLine();

        /*entrada padrão com as expressões para verificar se é bem formada*/

        while (!input.equals("FIM")) {
            boolean answer = bemFormada(input);
            if(answer){
                System.out.println("correto");  // Se tudo foi desempilhado (Tudo que abriu fechou) esta correto
            } else {
                System.out.println("incorreto");
            }
            input = sc.nextLine();
        }
        sc.close();
    }

    /** Stack - END */
}

class Stack {

    private Cell bottom;
    public Cell top;

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
    public void stackUp(String newElement) {
        Cell newCell = new Cell(newElement);

        newCell.setNextCell(top);
        top = newCell;
    }

    /* método de desempilhar LIFO */
    public String unstack()  {

        Cell unstacked;

        if (!emptyStack()) {
            unstacked = top;
            top = top.getNextCell();
            unstacked.setNextCell(null);
            return (unstacked.getStackStrings());
        } else {
            return null;
        }
    }
}

class Cell {

    private String stackStrings;
    private Cell nextCell;

    /** Constructors - START **/
    public Cell(String newElement) {
        stackStrings = newElement;
        nextCell = null;
    }

    public Cell() {
        stackStrings = new String();
        nextCell = null;
    }

    /** Constructors - END **/

    public String getStackStrings() {
        return stackStrings;
    }

    public void setStackStrings(String stackSeries) {
        this.stackStrings = stackStrings;
    }

    public Cell getNextCell() {
        return nextCell;
    }

    public void setNextCell(Cell nextCell) {
        this.nextCell = nextCell;
    }
}

