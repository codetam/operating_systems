#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <strings.h> //to add bzero function

void func(){
    printf("I just entered the secret function!\n");
}

int main(){
    int pid;
    pid = fork();
    if(pid == 0){
        signal(SIGUSR2,func);
        printf("Waiting for the signal...\n");  
        sleep(40);
        printf("This has been printed after the signal.\n");
        exit(0);
    }
    else if(pid > 0){
        sleep(2);
        kill(pid,SIGUSR2);
        exit(0);
    }
}