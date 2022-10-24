#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <sys/wait.h>
#include "fbroker.c"
#include "padre.h"
#include "hijo.h"
#include "estructura.h"

int main(int argc, char* argv[]){
    /*printf("Esta es i: %s\n",argv[1]);
	printf("Esta es o: %s\n",argv[2]);
	printf("Esta es d: %s\n",argv[3]);
	printf("Esta es p: %s\n",argv[4]);
	printf("Esta es n: %s\n",argv[5]);
    printf("Esta es b: %s\n",argv[6]);*/
    // conversion de los argumentos a enteros
    int anio= atoi(argv[3]);
	int precioMenor= atoi(argv[4]);
    char * nombre_archivo_salida= argv[2];
    char * nombre_archivo_entrada=argv[1];
    char * procesoPorPantalla= argv[5];
    int cantidadWorkers= atoi(argv[5]);

    printf("anio: %d\n",anio);
	printf("precio menor: %d\n",precioMenor);
	printf("Nombre archivo salida: %s\n",nombre_archivo_salida);
	printf("NOmbre archivo entrada: %s\n",nombre_archivo_entrada);
	printf("workers: %d\n",cantidadWorkers);
    printf("bflag: %s\n",procesoPorPantalla);
    // pid de los procesos hijos;
	int workers_pid[cantidadWorkers];

	// pipes
	int fds1[cantidadWorkers][2];
	int fds2[cantidadWorkers][2];
	//cantidad de pipes por proceso que es igual al numero de anios
	
	for(int cont = 0; cont < cantidadWorkers; cont++){
		pipe(fds1[cont]);
		pipe(fds2[cont]);
	}
    // creacion de los procesos hijos
    for(int cont = 0; cont < cantidadWorkers; cont++){
        workers_pid[cont] = fork();
        if(workers_pid[cont] == -1){
			printf("Error al crear el proceso hijo");
			exit(1);
    
        }else if(workers_pid[cont] == 0){
            
        }

    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}