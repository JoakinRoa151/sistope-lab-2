#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char* argv[]){
	extern char *optarg; //Almacena los argumentos introducidos después de haber indicado la variable.
    extern int optind; // Almacena el número de argumentos introducidos.
    int option;
    int iflag = 0;
    int oflag = 0;
    int dflag = 0;
    int pflag = 0;
    int bflag = 0;
    int nflag = 0;
    int error = 0;
	char * anio;
	char * precioMenor;
    char * nombre_archivo_salida;
    char * nombre_archivo_entrada;
    char * procesoPorPantalla;
    char * cantidadWorkers;
    while((option = getopt(argc, argv, "i:o:d:p:n:b")) != -1){
        switch(option){
            case 'i':
                iflag = 1;
                nombre_archivo_entrada = optarg;
                break;
            case 'o':
                oflag = 1;
                nombre_archivo_salida = optarg;
                break;
            case 'd':
                dflag = 1;
                anio = optarg;
                break;
            case 'p':
                pflag = 1;
                precioMenor = optarg;
                break;
            case 'n':
                nflag = 1;
                cantidadWorkers = optarg;
                break;
            case 'b':
                bflag = 1;
                procesoPorPantalla = optarg;
                break;
            case '?':
                error = 1;
                break;
            exit(0);
        }
    }
        int status;
        int pid= fork();
        if(pid==0){
            execlp("./broker", "broker", nombre_archivo_entrada,nombre_archivo_salida, anio, precioMenor, cantidadWorkers,procesoPorPantalla,NULL);
        }
    return 0;
}
