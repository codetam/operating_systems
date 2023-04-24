package cpu_busywaiting;

public class CPU{

    int core;
    public CPU(){
        core = 4;
    }
    public synchronized boolean access(int threadNum) {
        if(core <= 0)
            return false;
        core--;
        System.out.println("Using CPU resource by thread n." + threadNum);
        return true;
    }
    public synchronized void release(int threadNum){
        System.out.println("Leaving CPU by thread n." + threadNum);
        core++;
    }
}