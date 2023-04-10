package consumer_producer;

public class Semaphore{
    private int value, suspended;
    
    public Semaphore(int value){
        this.value = value;
        suspended = 0;
    }

    public synchronized void down(){
        if(value == 0){
            suspended++;
            try{
                wait();
            }
            catch( Exception e ){
                e.printStackTrace();
            }
            suspended--;
        }
        else{
            value--;
        }
    }

    public synchronized void up(){
        if(suspended > 0){
            notify();
        }  
        else{
            value++;
        }
    }
}