#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
    if(argc != 2){
        printf("Inserire solo il numero dei processi");
        exit(0);
    }
    int statloc;
    int numero;
    sscanf(argv[1],"%d",&numero);
    for(int i=0; i<numero; i++){
        pid_t pid = fork();
        if(!pid){
            printf("Sono il figlio!\n");
            printf("pid proprio: %d, pid del padre %d, pid della fork: %d\n", getpid(), getppid(), pid);
        }
        else{
            printf("Sono il padre!\n");
            printf("pid proprio: %d, pid del padre %d, pid della fork: %d\n", getpid(), getppid(), pid);
        }
        wait(&statloc);
    }
    exit(0);
    
}