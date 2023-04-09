#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int main(){
    int n = 5;
    int fd[5][2];
    int pid;
    for(int i=0; i<n; i++)
        pipe(fd[i]);
    for(int i=0; i<n-1; i++){
        pid = fork();
        if(pid == 0){
            char stringa[sizeof(int)];
            read(fd[i][0],stringa,sizeof(int));
            printf("Sono PID:%d, Ho appena letto: %s\n", getpid(), stringa);
            write(fd[i+1][1],stringa,sizeof(int));
        }
        else if(pid > 0){
            if(i==0){
                char stringa[sizeof(int)];
                sprintf(stringa, "%d", getpid());
                write(fd[i][1],stringa,sizeof(int));
            }
        }

    }
}