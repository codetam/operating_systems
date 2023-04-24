package cpu_busywaiting;

public class Test {
    public static void main(String args[]){
        CPU centralControlUnit = new CPU();
        Processo proc1 = new Processo(centralControlUnit, 1, 5);
        Processo proc2 = new Processo(centralControlUnit, 2, 11);
        Processo proc3 = new Processo(centralControlUnit, 3, 15);
        Processo proc4 = new Processo(centralControlUnit, 4, 6);
        Processo proc5 = new Processo(centralControlUnit, 5, 10);

        proc1.start();
        proc2.start();
        proc3.start();
        proc4.start();
        proc5.start();
    }
}
