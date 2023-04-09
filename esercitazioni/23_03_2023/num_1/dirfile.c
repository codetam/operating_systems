#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int main(int argc, char* argv[]){  
    umask(0);
    int fd = open(argv[1], O_RDWR | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);
    close(1);
    dup(fd);
    char* stringhe[3] = {"/bin/ls","-la", NULL};
    execv("/bin/ls", stringhe);
    exit(0);
}