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
    char nombre_archivo_salida[100];
	strcpy(nombre_archivo_salida,argv[2]);
    char nombre_archivo_entrada[100];
	strcpy(nombre_archivo_entrada,argv[1]);
    char  procesoPorPantalla[100];
	strcpy(procesoPorPantalla,argv[6]);
    int cantidadWorkers= atoi(argv[5]);

    printf("anio: %d\n",anio);
	printf("precio menor: %d\n",precioMenor);
	printf("Nombre archivo salida: %s\n",nombre_archivo_salida);
	printf("Nmbre archivo entrada: %s\n",nombre_archivo_entrada);
	printf("workers: %d\n",cantidadWorkers);
    printf("bflag: %s\n",procesoPorPantalla);
    
	
	// pid de los procesos hijos;
	int workers_pid[cantidadWorkers];

	// pipes
	int fds1[cantidadWorkers][2]; // padre escritura 1
	int fds2[cantidadWorkers][2]; // padre lectura 0
	//cantidad de pipes por proceso que es igual al numero de workers
	
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
    
        }else if(workers_pid[cont] > 0){

			// ESCRITURA PADRE
			close(fds1[cont][0]);
			if(dup2(fds1[cont][1],STDOUT_FILENO) == -1){
				printf("Error al duplicar el descriptor de archivo");
				exit(1);
			}
			write(STDOUT_FILENO,nombre_archivo_entrada,sizeof(nombre_archivo_entrada));
			
			close(fds1[cont][1]);
			
			
			// LECTURA PADRE
			
			/*close(fds1[cont][1]);
			dup2(fds1[cont][0],STDIN_FILENO);
			char buff[100];
			read(STDIN_FILENO,buff,sizeof(buff));
			printf("HOLA SOY EL PADRE Y RECIBI EL MENSAJE DE MI HIJO: %s\n",buff);
			*/
			waitpid(workers_pid[cont],NULL,0);
        }
		else{
			// ESCRITURA HIJO
			/*close(fds1[cont][0]);
			dup2(fds1[cont][1],STDOUT_FILENO);*/
			// LECTURA HIJO
			printf(" cuantas veces entro al hijo \n");
			close(fds1[cont][1]);
			if(dup2(fds1[cont][0],STDIN_FILENO) == -1){
				printf("Error al duplicar el descriptor de archivo");
				exit(1);
			}
			close(fds1[cont][0]);
            execlp("./worker", "worker",NULL);
			break;
		}
	}


    
    return 0;
}