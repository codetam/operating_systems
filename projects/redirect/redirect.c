#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
    if(argc != 3){
        printf("Some arguments are missing. (arg1: executable, arg2: text file)\n");
        exit(1);
    }
    int pid = fork();
    if(pid == 0){
        umask(0);
        //Creates a text file (read and write permissions to everyone)
        int fd = open(argv[2], O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
        //Closes standard output
        close(1);
        //Sets the new file as the standard output
        dup(fd);
        close(fd);
        char* list[] = {argv[1], (char *)NULL};
        //Executes the program, which will print into the file
        execv(argv[1],list);
    }
}