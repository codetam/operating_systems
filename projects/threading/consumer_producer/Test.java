package consumer_producer;

public class Test {
    static int currentSize;
    public static void main(String args[]){
        //Capacity of the list
        int capacity = 30;
        currentSize = 0;
        //Initializes semaphores
        Semaphore full = new Semaphore(0);
        Semaphore empty = new Semaphore(capacity);
        Semaphore mutex = new Semaphore(1);

        //Initializes threads
        Producer prod = new Producer(full, empty, mutex);
        Consumer cons = new Consumer(full, empty, mutex);
        prod.start();
        cons.start();
    }
}