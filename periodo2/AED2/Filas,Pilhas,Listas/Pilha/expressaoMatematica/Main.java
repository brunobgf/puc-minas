import java.util.Scanner;

public class Main {

    /*
    Função para transformar uma função Infixa para Pósfixa, exemplo: 3+5*(7-2)/4 - infixa
    3572-*4/+ - posfixa
     */

    public static String toPostFix(String s) {
        Stack newStack = new Stack();
        String outputString = "";
        String aux;
        String[] vetString;
        vetString = s.split("");


        for(int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);

            if(priority(c)>0){

                //para olhar o item do topo e comparar a prioridade dele com a prioridade da String que chegou
                //se a prioridade do item que chegou for maior ou igual que o topo, o topo vai para a string de saida
                aux = newStack.top.getStackStrings();

                while(!(newStack.emptyStack()) && priority(aux.charAt(0))>= priority(c)){
                    outputString= outputString + newStack.unstack();
                    aux = newStack.top.getStackStrings();
                }
                //empilha o item que chegou
                newStack.stackUp(vetString[i]);
            }else if(c==')'){

                char z;
                z = newStack.top.getStackStrings().charAt(0);
                newStack.unstack();

                //enquanto for diferente de ''('', desempilha e soma a string de saida

                while(z!='('){
                    outputString= outputString + z;
                    z = newStack.top.getStackStrings().charAt(0);
                    newStack.unstack();

                }
            }else if(c=='('){
                newStack.stackUp(vetString[i]);
            }else{
                //não é operador e nem '')''
                if(!(vetString[i].equals(" "))){
                    outputString= outputString + vetString[i];
                }
            }
        }
        //desempilha o resto que estiver na pilha e adiciona a string de saida
        while(!newStack.emptyStack()){
            outputString= outputString + newStack.unstack();

        }
        return outputString;
    }

    //Checa a prioridade das operações

    static int priority(char c)
    {
        switch (c)
        {
            case '+':
            case '-':
                return 1;
            case '*':
            case '/':
                return 2;
        }
        return -1;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in, "UTF-8");

        /*declaração e inicialização das variáveis*/

        String input;

        /**Stack - START*/

        input = sc.nextLine();

        /*entrada padrão com as expressões */

        while (!input.equals("FIM")) {
            String answer = toPostFix(input);
            String[] spacedAnswer = answer.split("");
            for(int i=0; i<answer.length();i++){
                System.out.printf(spacedAnswer[i]+" ");
            }
            System.out.println("");
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