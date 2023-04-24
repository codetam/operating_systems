package robot_multithreading;

public class Test {
    public static void main(String[] args) {
        semaphore mutex = new semaphore(1);
        semaphore sem1 = new semaphore(0);
        semaphore sem2 = new semaphore(0);
        Deposit depositA = new Deposit(0);
        Deposit depositB = new Deposit(1);
        Robot robot1 = new Robot(mutex, sem1, sem2, depositA, depositB, 1);
        Robot robot2 = new Robot(mutex, sem1, sem2, depositA, depositB, 2);

        robot1.start();
        robot2.start();
    }
}
