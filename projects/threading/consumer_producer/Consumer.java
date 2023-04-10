package consumer_producer;

import java.lang.Thread;
import java.util.Random;

public class Consumer extends Thread{
    private Semaphore full;
    private Semaphore empty;
    private Semaphore mutex;

    public Consumer(Semaphore full, Semaphore empty, Semaphore mutex){
        this.full = full;
        this.empty = empty;
        this.mutex = mutex;
    }

    private void remove_item(){
        Test.currentSize--;
        System.out.println("Consumer has purchased an item! Number: " + Test.currentSize);
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
            //If full > 0, the consumer can go further (there is at least one available item)
            full.down();
            //If mutex > 0, the consumer can go further (no one is in the critical region)
            mutex.down();
            remove_item();
            //Next in line can enter the critical region
            mutex.up();
            //Increasing empty, so that a producer can insert an item
            empty.up();
        }
    }
}
