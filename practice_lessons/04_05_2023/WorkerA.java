import java.lang.Thread;
import java.util.Random;

public class WorkerA extends Thread {
    Random rand = new Random();
    private semaphore sem2;
    private semaphore accessFarm;           // Semaphore to access farm column 0       
    int farm[][];
    static int currentJob = -1;             // The amount of jobs completed

    public WorkerA(semaphore accessFarm, semaphore sem2, int farm[][]) {
        this.accessFarm = accessFarm;
        this.sem2 = sem2;
        this.farm = farm;
    }

    public void run() {
        for(int k=0; k<8; k++) {
            accessFarm.down();
            try{
                sleep(rand.nextInt(10));
            }
            catch(Exception e){
                e.printStackTrace();
            }
            if (currentJob < 15) {
                currentJob++;
                farm[currentJob][0] = 1;
            }
            accessFarm.up();
            sem2.up();                      // Wakes up WorkerB                       
        }
    }
}