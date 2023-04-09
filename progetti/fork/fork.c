#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
    printf("Sono il processo di partenza, pid è %d\n", getpid());
    int pid;
    if(argc < 2){
        printf("Indicare il numero di processi!\n");
        return 0;
    }
    for(int i=0; i<atoi(argv[1]); i++){
        pid = fork();
        if(pid<0){
            printf("La fork è fallita.");
            return 1;
        }
        if(pid==0){
            printf("Sono il processo figlio! - fork n. %d\nIl mio pid è %d, quello di mio padre è %d\n", i, getpid(), getppid());
            exit(0);
        }
        else if(pid>0){
            int wstatus;
            waitpid(pid, &wstatus, 0);
            printf("Sono il processo padre! - fork n. %d\nIl mio pid è %d, quello di mio padre è %d\nStatus del wait: %d\n", i, getpid(), getppid(),wstatus);
        }
    }
    
}