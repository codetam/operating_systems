#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
    if(argc != 2){
        printf("Insert the number of processes.\n");
        exit(0);
    }
    int statloc;
    int number;
    sscanf(argv[1],"%d",&number);
    for(int i=0; i<number; i++){
        pid_t pid = fork();
        if(!pid){
            printf("I am the child! Own PID: %d, Parent PID %d, Fork PID: %d\n", getpid(), getppid(), pid);
        }
        else{
            printf("I am the parent! Own PID: %d, Parent PID %d, Fork PID: %d\n", getpid(), getppid(), pid);
        }
        wait(&statloc);
    }
    exit(0);
    
}