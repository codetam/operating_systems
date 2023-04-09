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
    int a;
    sscanf(argv[1],"%d",&a);
    if(strcmp(argv[1],"0")){
        kill(getppid(),SIGUSR1);
    }
    else if(strcmp(argv[1],"1")){
        kill(getppid(),SIGUSR2);
    }
}