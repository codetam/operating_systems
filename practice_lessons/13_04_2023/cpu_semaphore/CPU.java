package cpu_semaphore;
import java.lang.Thread;

public class CPU{
    int core;
    public CPU(){
        core = 4;
    }
    public void execute(int numThread){
        System.out.println("Executing CPU process by thread n." + numThread);
        try{
            Thread.sleep(1000);
        }
        catch(Exception e){
            e.printStackTrace();
        }
        System.out.println("CPU has been released by thread n." + numThread);
    }
}