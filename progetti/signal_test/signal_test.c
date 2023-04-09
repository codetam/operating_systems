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
    printf("Sono nella funzione speciale!\n");
}

int main(){
    int pid;
    pid = fork();
    if(pid == 0){
        printf("Aspetto il segnale, un attimo...\n");
        signal(SIGUSR2,func);
        sleep(40);
        printf("print post segnale \n");
        exit(0);
    }
    else if(pid > 0){
        sleep(2);
        kill(pid,SIGUSR2);
        exit(0);
    }
}