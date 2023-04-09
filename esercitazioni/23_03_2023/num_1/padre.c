#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <time.h>

void receiveSig1();
void receiveSig2();

int aspetta = 1;

int main(){
    srand(time(NULL));
    int r = rand() % 2;
    int pid = fork();
    if(pid < 0){
        printf("fork fallita\n");
        exit(1);
    }
    if(pid == 0){
        sleep(5);
        char intero[5];
        sprintf(intero, "%d", r);
        char* stringhe[4] = {"figlio", intero, NULL};
        execv("figlio", stringhe);
        exit(0);
    }
    else if(pid > 0){
        signal(SIGUSR1, receiveSig1);
        signal(SIGUSR2, receiveSig2);
        while(aspetta == 1){
            printf("Aspetto l'arrivo del signal\n");
            sleep(2);
        }
        exit(0);
    }
}

void receiveSig1(){
    printf("Ho ricevuto il primo segnale!\n");
    aspetta=0;
}
void receiveSig2(){
    printf("Ho ricevuto il secondo segnale!\n");
    aspetta=0;
}