import java.lang.Thread;

public class Test extends Thread {
    public static void main(String args[]){
        // Declaration and initialization of farm objects
        int farm[][] = new int[16][3];
        int farmcopy[][] = new int[16][3];          // This object is used for printing purposes
        boolean different = false;
        for(int i=0; i<16; i++){
            for(int j=0; j<3; j++){
                farm[i][j] = 0;
                farmcopy[i][j] = 0;
            }
        }
        for(int i=0; i<16; i++){
            for(int j=0; j<3; j++){
                System.out.print(farm[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println();

        // Semaphores initializations
        semaphore accessFarm1 = new semaphore(1);   // v = 1 -> the semaphore is green at startup
        semaphore accessFarm2 = new semaphore(1);
        semaphore accessFarm3 = new semaphore(1);
        semaphore sem2 = new semaphore(0);          // v = objects worked on by WorkerA which haven't been worked on by WorkerB yet
        semaphore sem3 = new semaphore(0);          // v = objects worked on by WorkerB which haven't been worked on by WorkerC yet

        // Initializing set of workers
        WorkerA a1 = new WorkerA(accessFarm1, sem2, farm);
        WorkerB b1 = new WorkerB(accessFarm2, sem2, sem3, farm);
        WorkerC c1 = new WorkerC(accessFarm3, sem3, farm);
        WorkerA a2 = new WorkerA(accessFarm1, sem2, farm);
        WorkerB b2 = new WorkerB(accessFarm2, sem2, sem3, farm);
        WorkerC c2 = new WorkerC(accessFarm3, sem3, farm);

        // Starting threads
        a1.start();
        b1.start();
        c1.start();
        a2.start();
        b2.start();
        c2.start();

        // Print farm content only if it's changed
        while(farm[15][2] == 0){
            for(int i=0; i<16 && different == false; i++){
                for(int j=0; j<3 && different == false; j++){
                    if(farm[i][j] != farmcopy[i][j])
                        different = true;
                }
            }
            if(different == true){
                for(int i=0; i<16; i++){
                    for(int j=0; j<3; j++){
                        farmcopy[i][j] = farm[i][j];
                        System.out.print(farm[i][j] + " ");
                    }
                    System.out.print(" | ");
                }
                System.out.println();
                different = false;
            }    
        }
    }
}
