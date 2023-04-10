package monitor_consumer_producer;
import java.util.Random;
public class Test {
    public static void main(String args[]){
        Monitor_class monitor = new Monitor_class(30);
        Producer prod = new Producer(monitor);
        Consumer cons = new Consumer(monitor);

        prod.start();
        cons.start();
    }
}

class Producer extends Thread{
    Monitor_class monitor;
    public Producer(Monitor_class monitor){
        this.monitor = monitor;
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
            monitor.insert();
        }
    }
}

class Consumer extends Thread{
    Monitor_class monitor;
    public Consumer(Monitor_class monitor){
        this.monitor = monitor;
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
            monitor.remove();
        }
    }
}