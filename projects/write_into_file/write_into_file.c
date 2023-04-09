#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if(argc<2){
        printf("You must enter the name of a file and things to write\n");
        return 1;
    }
    umask(0);
    int fd = open(argv[1], O_RDWR | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);
    if(fd < 0){
        printf("File did not open correctly\n");
        return 1;
    }
    char buf[100];
    memset(buf, 0, sizeof(buf));
    for(int i=2; i < argc; i++){
        strcat(buf, argv[i]);
        strcat(buf, " ");
    }
    buf[strlen(buf)] = '\0';
    write(fd,buf,100);
    close(fd);
    return 0;
}