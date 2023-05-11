import java.lang.Thread;
import java.util.Random;

public class WorkerC extends Thread {
    Random rand = new Random();
    private semaphore sem3;
    private semaphore accessFarm;           // Semaphore to access farm column 0 
    int farm[][];
    static int currentJob = -1;             // The amount of jobs completed

    public WorkerC(semaphore accessFarm, semaphore sem3, int farm[][]){
        this.accessFarm = accessFarm;
        this.sem3 = sem3;
        this.farm = farm;
    }

    public void run(){
        for(int k=0; k<8; k++){
            sem3.down();
            accessFarm.down();
            try{
                sleep(rand.nextInt(10));
            }
            catch(Exception e){
                e.printStackTrace();
            }
            if(currentJob < 15){
                currentJob++;
                farm[currentJob][2] = 1;
            }
            accessFarm.up();
        }
    }
}
