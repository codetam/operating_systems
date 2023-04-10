import java.lang.Thread;
import java.lang.Runnable;

public class Drinks{
    public static void main(String args[]){
        Coffee cof = new Coffee();
        Lemonade lem = new Lemonade();
        cof.start();
        lem.start();
        Water wa = new Water();
        Thread thd = new Thread(wa);
        thd.start();
    }
}

class Coffee extends Thread{
    public void run(){
        while(true){
            System.out.println("I'm the coffee!");
            try{
                sleep(1000);
            }
            catch(Exception e){
                e.printStackTrace();
            }
        }
    }
}

class Lemonade extends Thread{
    public void run(){
        while(true){
            System.out.println("I am the lemonade!");
            try{
                sleep(1000);
            }
            catch(Exception e){
                e.printStackTrace();
            }
        }
    }
}

class Water implements Runnable{
    public void run(){
        while(true){
            System.out.println("I am the water!");
            try{
                Thread.sleep(1000);
            }
            catch(Exception e){
                e.printStackTrace();
            }
        }
    }
}