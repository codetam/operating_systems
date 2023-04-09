#include <unistd.h>
#include <sys/syscall.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){
    umask(0);
    int fd = open(argv[1], O_RDWR);
    if(fd < 0){
        printf("File non aperto correttamente\n");
        return 1;
    }
    char buf[100];
    read(fd,buf,100);
    buf[strlen(buf)] = '\0';
    printf("%s", buf);
    return 0;

}