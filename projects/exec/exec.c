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
        printf("Insert the name of a text file! (The file must contain an executable command)\n");
        return 1;
    }
    int fd = open(argv[1], O_RDONLY);
    if(fd < 0){
        printf("File could not be opened.\n");
        return 1;
    }
    char buffer[BUFFSIZE];
    read(fd,buffer,100);
    int pid = fork();
    if(pid == 0){
        printf("I am the child process! My PID: %d\n", getpid());
        int len = strlen(buffer);
        if (buffer[len-1] == '\n') {
            buffer[len-1] = '\0';
        }
        printf("Here is the buffer: %s\n", buffer);
        char* argsForExec[2] = {buffer, NULL};
        execvp(buffer,argsForExec);
    }
    else if(pid > 0){
        int status;
        wait(&status);
        printf("I am the parent process! My PID: %d\n", getpid());
        exit(0);
    }
    return 0;
}