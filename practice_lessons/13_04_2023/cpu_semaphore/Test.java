package cpu_semaphore;

public class Test {
    public static void main(String args[]){
        semaphore sem = new semaphore(4);
        CPU centralControlUnit = new CPU();

        Processo proc1 = new Processo(sem, centralControlUnit, 1, 5);
        Processo proc2 = new Processo(sem, centralControlUnit, 2, 11);
        Processo proc3 = new Processo(sem, centralControlUnit, 3, 15);
        Processo proc4 = new Processo(sem, centralControlUnit, 4, 6);
        Processo proc5 = new Processo(sem, centralControlUnit, 5, 10);

        proc1.start();
        proc2.start();
        proc3.start();
        proc4.start();
        proc5.start();
    }
}
