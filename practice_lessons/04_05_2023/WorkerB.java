import java.lang.Thread;
import java.util.Random;

public class WorkerB extends Thread{
    Random rand = new Random();
    private semaphore sem2;
    private semaphore sem3;
    private semaphore accessFarm;           // Semaphore to access farm column 1  
    int farm[][];
    static int currentJob = -1;             // The amount of jobs completed

    public WorkerB(semaphore accessFarm, semaphore sem2, semaphore sem3, int farm[][]){
        this.sem2 = sem2;
        this.sem3 = sem3;
        this.farm = farm;
        this.accessFarm = accessFarm;
    }

    public void run(){
        for(int k=0; k<8; k++){
            sem2.down();
            accessFarm.down();
            try{
                sleep(rand.nextInt(10));
            }
            catch(Exception e){
                e.printStackTrace();
            }
            if(currentJob < 15){
                currentJob++;
            farm[currentJob][1] = 1;
        }
            accessFarm.up();
            sem3.up();                      // Wakes up WorkerC
        }
    }
}
