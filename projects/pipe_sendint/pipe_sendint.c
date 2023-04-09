#include <stdio.h> //Includes printf
#include <unistd.h> //Includes pipe, fork and i/o
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
    int piped[2];
    if(pipe(piped)<0){
        printf("Pipe non aperta correttamente.\n");
        exit(1);
    }
    int pid = fork();
    if(pid == 0){
        close(piped[0]);
        int readInt;
        char stringInt[10];
        for(int i=0; i<5; i++){
            printf("Sono il figlio, inserire un intero: ");
            scanf("%d", &readInt);
            sprintf(stringInt,"%d",readInt);
            write(piped[1],stringInt,sizeof(int));
            printf("Ho scritto l'intero nella pipe.\n");
        }      
    }
    else if(pid > 0){
        int status;
        wait(&status);
        close(piped[1]);
        char valoreLetto[10];
        int readInt;
        for(int i=0; i<5; i++){
            read(piped[0],valoreLetto,sizeof(int));
            readInt = atoi(valoreLetto);
            printf("Sono il padre, ho letto: %d\n", readInt);
        }
    }
}