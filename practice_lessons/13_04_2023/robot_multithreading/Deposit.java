package robot_multithreading;

import java.util.ArrayList;

public class Deposit {
    private ArrayList<Integer> oggetti = new ArrayList<>();
    int numExtracted = 0;
    public Deposit(int num){
        if(num == 0){ //Deposit A
            for(int i=0; i<5; i++){
                oggetti.add(i);
            }
        }
    }
    public int getExtracted(){
        return numExtracted;
    }
    public int size(){
        return oggetti.size();
    }
    public int extract(int numRobot){
        int oggetto = oggetti.remove(oggetti.size() - 1);
        System.out.println("Robot n." + numRobot + " has extracted " + oggetto);
        numExtracted++;
        return oggetto;
    }
    public void insert(int oggetto, int numRobot){
        System.out.println("Robot n." + numRobot + " has inserted " + oggetto);
        oggetti.add(oggetto);
    }
}
