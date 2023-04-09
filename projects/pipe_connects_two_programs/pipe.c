#include <stdio.h> //Includes printf
#include <unistd.h> //Includes pipe, fork and i/o
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
    if(argc<3){
        printf("Arguments needed: arg1 = file that prints, arg2 = file that reads input\n");
        exit(1);
    }
    int fd[2];
    if(pipe(fd)<0){
        printf("Pipe couldn't be opened.\n");
        exit(1);
    }
    int pid = fork();
    if(pid == 0){
        //Lets the outputs_2_strings program write two strings in the pipe
        close(1);
        dup(fd[1]);
        close(fd[1]);
        close(fd[0]);
        char* arguments[2] = {argv[1], NULL};
        execv(argv[1], arguments);
    }
    else if(pid > 0){
        int status;
        wait(&status);
        close(0);
        dup(fd[0]);
        close(fd[0]);
        close(fd[1]);
        char inputString[100];
        //Reads the strings from the pipe
        read(STDIN_FILENO,inputString,100);
        const char s[2] = " ";
        char *token;
        char* strings[2];
        //Tokenizes the string to get the arguments
        token = strtok(inputString,s);
        strings[0] = token;
        token = strtok(NULL,s);
        strings[1] = token;
        //executes the second file with the two strings as arguments
        char* arguments[4] = {argv[2], strings[0], strings[1], NULL};
        execv(argv[2], arguments);
    }
}