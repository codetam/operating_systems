#include <unistd.h>
#include <sys/syscall.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

#define SIZE 100
int main(int argc, char* argv[]){
    umask(0);
    int fd = open(argv[1], O_RDWR);
    if(fd < 0){
        printf("File could not be opened.\n");
        return 1;
    }
    char buf[100];
    //Reads a maximum of SIZE characters from the file
    read(fd,buf,100);
    buf[strlen(buf)] = '\0';
    printf("%s", buf);
    return 0;
}