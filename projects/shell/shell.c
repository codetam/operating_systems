#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <strings.h> //to add bzero function

int main () {
	pid_t pid,procid;
	int status,k;
	size_t n;
    char buffer[80], prompt[30];
    sprintf(prompt,"sugoma:>");
    write(1, prompt,strlen(prompt));
    bzero(buffer,80);	
    while (read(STDIN_FILENO,buffer,80) > 0) {
        /* command line processing */
        k=strlen(buffer);
        buffer[k-1]=buffer[k]; //This removes the newline character
        if (strcmp(buffer,"esci")==0) exit(0);
        if ((pid=fork()) == 0) {
            /* I/O redirection */
            // printf("attivazione processo figlio\n");
            char* search = " ";
            char* token;
            char* args[100];
            token = strtok(buffer,search);
            args[0] = token;
            int i=1;
            while(token != NULL){
                token = strtok(NULL, search);
                args[i] = token;
                i++;
            }
            if (execv(args[0],args)==-1) exit(1);
        }
        procid=wait(&status);
        if (status!=0 && buffer[0] != '\0') 
            write(2,"cmd not found\n",14);
        bzero(buffer,80);	
        write(1, prompt,10);
    }
    exit(0);
}