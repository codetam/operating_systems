package monitor_consumer_producer;

public class Monitor_class {
    private int size;
    private static int count = 0;
    public Monitor_class(int size){
        this.size = size;
    }
    public synchronized void insert(){
        if(count == size){
            try{
                wait();
            }
            catch(Exception e){
                e.printStackTrace();
            }
        }
        count++;
        System.out.println("Item inserted, current size: " + count);
        if(count == 1) notify();
    }

    public synchronized void remove(){
        if(count == 0){
            try{
                wait();
            }
            catch(Exception e){
                e.printStackTrace();
            }
        }
        count--;
        System.out.println("Item removed, current size: " + count);
        if(count == size - 1) notify();
    }
}
