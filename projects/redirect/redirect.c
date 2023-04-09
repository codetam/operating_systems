#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
    int pid = fork();
    if(pid == 0){
        umask(0);
        int fd = open(argv[1], O_RDWR | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);
        close(1);
        dup(fd);
        close(fd);
        char* lista[] = {argv[2], (char *)NULL};
        execv(argv[2],lista);
    }
}