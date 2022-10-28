#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char* argv[]){
    // LECTURA WORKERS
    char buff[10000];
    int contador = 0;
    char lectura[100000];
    while(1){
        read(STDIN_FILENO, buff, sizeof(buff));
        if(strcmp(buff,"FIN")==0){
            break;
        }
		printf("El worker  recibio: %s\n",buff);
        contador++;
    }
    printf("Contador %d\n",contador);
    
    
    
    
    // ESCRITURA WORKER
    //write(STDOUT_FILENO, "XDDDDDD", 7);}
    return 0;
}