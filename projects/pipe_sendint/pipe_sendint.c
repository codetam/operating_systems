#include <stdio.h> //Includes printf
#include <unistd.h> //Includes pipe, fork and i/o
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
    if(argc != 2){
        printf("Insert the number of integers to move to the pipe.\n");
        exit(1);
    }
    int num = atoi(argv[1]);
    int piped[2];
    if(pipe(piped)<0){
        printf("Pipe couldn't be opened.\n");
        exit(1);
    }
    int pid = fork();
    if(pid == 0){
        close(piped[0]);
        int readInt;
        char stringInt[10];
        for(int i=0; i<num; i++){
            printf("I am the child, insert an integer: ");
            scanf("%d", &readInt);
            sprintf(stringInt,"%d",readInt);
            write(piped[1],stringInt,sizeof(int));
            printf("I have written the integer in the pipe.\n");
        }      
    }
    else if(pid > 0){
        int status;
        wait(&status);
        close(piped[1]);
        char valueRead[10];
        int readInt;
        for(int i=0; i<num; i++){
            read(piped[0],valueRead,sizeof(int));
            readInt = atoi(valueRead);
            printf("I am the parent, I have read: %d\n", readInt);
        }
    }
}