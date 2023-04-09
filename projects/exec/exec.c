#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>


#define BUFFSIZE 100

int main(int argc, char* argv[]){
    if(argc < 2){
        printf("Inserire il nome di un file di testo! (Il file deve contenere il nome di un file eseguibile)\n");
        return 1;
    }
    int fd = open(argv[1], O_RDONLY);
    if(fd < 0){
        printf("File non aperto correttamente.\n");
        return 1;
    }
    char buffer[BUFFSIZE];
    read(fd,buffer,100);
    int pid = fork();
    if(pid == 0){
        printf("Sono il processo figlio! Mio PID: %d\n", getpid());
        printf("Here is the buffer: %s", buffer);
        int len = strlen(buffer);
        if (buffer[len-1] == '\n') {
            buffer[len-1] = '\0';
        }
        char* argsForExec[2] = {buffer, NULL};
        execvp(buffer,argsForExec);
        printf("Executing new file...\n"); //will not be read
    }
    else if(pid > 0){
        int status;
        wait(&status);
        printf("Sono il processo padre! Mio PID: %d\n", getpid());
        exit(0);
    }
    return 0;
}