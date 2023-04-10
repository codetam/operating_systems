package consumer_producer;

import java.lang.Thread;
import java.util.Random;

public class Producer extends Thread{
    private Semaphore full;
    private Semaphore empty;
    private Semaphore mutex;

    public Producer(Semaphore full, Semaphore empty, Semaphore mutex){
        this.full = full;
        this.empty = empty;
        this.mutex = mutex;
    }
    
    private void add_item(){
        Test.currentSize++;
        System.out.println("Producer has added an item! Number: " + Test.currentSize);
    }

    public void run(){
        Random ran = new Random();
        
        while(true){
            //Creates a random int between 0 and 999
            int x = ran.nextInt(1000);
            try{  
                sleep(x);
            }catch(Exception e){
                e.printStackTrace();
            }
            //If empty > 0, the producer can go further (the queue isn't full yet)
            empty.down();
            //If mutex > 0, the producer can go further (no one is in the critical region)
            mutex.down();
            add_item();
            //Next in line can enter the critical region
            mutex.up();
            //Increasing full, so that a producer can buy
            full.up();
        }
        
    }
}
