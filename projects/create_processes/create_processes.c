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
    int numero;
    sscanf(argv[1],"%d",&numero);
    for(int i=0; i<numero; i++){
        pid_t pid = fork();
        if(!pid){
            printf("I am the child!\n");
            printf("Own PID: %d, Parent PID %d, Fork PID: %d\n", getpid(), getppid(), pid);
        }
        else{
            printf("I am the parent!\n");
            printf("Own PID: %d, Parent PID %d, Fork PID: %d\n", getpid(), getppid(), pid);
        }
        wait(&statloc);
    }
    exit(0);
    
}