#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <sys/wait.h>
int main(int argc, char* argv[]){
    // LECTURA WORKERS
    char buff[100];
    read(STDIN_FILENO, buff, sizeof(buff));
    printf("Este es el nombre del archivo de entrada que nos dio nuestro padre: %s", buff);
    
    
    // ESCRITURA WORKER
    //write(STDOUT_FILENO, "XDDDDDD", 7);}
    return 0;
}