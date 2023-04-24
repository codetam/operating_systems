package robot_multithreading;

import java.lang.Thread;

public class Robot extends Thread {
    private Deposit depositA;
    private Deposit depositB;
    private int numRobot;
    private semaphore mutex;
    private semaphore sem1;
    private semaphore sem2;

    public Robot(semaphore mutex, semaphore sem1, semaphore sem2, Deposit depositA, Deposit depositB, int numRobot) {
        this.mutex = mutex;
        this.sem1 = sem1;
        this.sem2 = sem2;
        this.depositA = depositA;
        this.depositB = depositB;
        this.numRobot = numRobot;
    }

    public void run() {
        // First step: the robots will extract objects from DepositA at a random order
        while (depositA.getExtracted() < 5) {
            mutex.down();
            if (depositA.getExtracted() == 4) {
                sem1.up();
            }
            if (depositA.getExtracted() < 5) {
                depositA.extract(numRobot);
            }
            mutex.up();
        }
        // Second step: the robots will insert the objects in DepositB alternating, but Robot 1 is the first one.
        switch (numRobot) {
            case 1:
                while (depositB.size() < 5) {
                    sem1.down();
                    if (depositB.size() < 5) {
                        depositB.insert(depositB.size(), numRobot);
                    }
                    sem2.up();
                }
                break;
            case 2:
                while (depositB.size() < 5) {
                    sem2.down();
                    if (depositB.size() < 5) {
                        depositB.insert(depositB.size(), numRobot);
                    }
                    sem1.up();
                }
                break;
        }
    }
}
