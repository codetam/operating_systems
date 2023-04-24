package cpu_semaphore;
import java.lang.Thread;

public class Processo extends Thread {
    private semaphore sem;
    private int numThread;
    private int numEsecuzioni;
    private CPU cpu;
    public Processo(semaphore sem, CPU cpu, int numThread, int numEsecuzioni){
        this.sem = sem;
        this.cpu = cpu;
        this.numThread = numThread;
        this.numEsecuzioni = numEsecuzioni;
    }
    public void run(){
        for(int i=0; i<numEsecuzioni; i++){
            sem.down();
            cpu.execute(numThread);
            sem.up();
        }
    }
}
