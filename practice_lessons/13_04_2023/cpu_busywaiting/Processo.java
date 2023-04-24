package cpu_busywaiting;

import java.lang.Thread;
import java.util.Random;

public class Processo extends Thread {
    private int numThread;
    private int numEsecuzioni;
    private Random random = new Random();
    private CPU cpu;
    public Processo(CPU cpu, int numThread, int numEsecuzioni){
        this.cpu = cpu;
        this.numThread = numThread;
        this.numEsecuzioni = numEsecuzioni;
    }
    public void run(){
        for(int i=0; i<numEsecuzioni; i++){
            //Checks if CPU is available and if it is, executes the access, sleep and release functions
            if(cpu.access(numThread)){
                try{                
                    sleep(random.nextInt(1000));
                }
                catch(Exception e){
                    e.printStackTrace();
                }
                cpu.release(numThread);
            }
            else{
                //The CPU is not available
                try{                
                    //Sleeps for 10 ms before trying again
                    sleep(10);
                }
                catch(Exception e){
                    e.printStackTrace();
                }
                i--;
            }
            
        }
    }
}
