#include <stdio.h> //Includes printf
#include <unistd.h> //Includes pipe, fork and i/o
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
    if(argc<3){
        printf("Inserire funzioni e pipe: arg1 = file che stampa, arg2 = file che prende l'input");
        exit(1);
    }
    int fd[2];
    if(pipe(fd)<0){
        printf("Pipe non aperta correttamente.\n");
        exit(1);
    }
    int pid = fork();
    if(pid == 0){
        close(1);
        dup(fd[1]);
        close(fd[1]);
        close(fd[0]);
        char* argomenti[2] = {argv[1], NULL};
        execv(argv[1], argomenti);
    }
    else if(pid > 0){
        int status;
        wait(&status);
        close(0);
        dup(fd[0]);
        close(fd[0]);
        close(fd[1]);
        char stringaInput[100];
        read(STDIN_FILENO,stringaInput,100);
        const char s[2] = " ";
        char *token;
        char* stringhe[2];
        token = strtok(stringaInput,s);
        stringhe[0] = token;
        token = strtok(NULL,s);
        stringhe[1] = token;
        
        char* argomenti[4] = {argv[2], stringhe[0], stringhe[1], NULL};
        execv(argv[2], argomenti);
    }
}