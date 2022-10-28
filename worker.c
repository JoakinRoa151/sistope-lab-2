#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
#include "estructura.h"
int main(int argc, char *argv[])
{
    // LECTURA WORKERS
    char buff[100000];
    int contador = 0;
    char lectura[100000] = "";
    //char *puntero_string;
    while (1)
    {
        read(STDIN_FILENO, buff, sizeof(buff));
        if (strcmp(buff, "FIN") == 0)
        {
            break;
        }
        strcat(lectura, buff);
        strcat(lectura, "+");
        contador++;
    }

    printf("lectura : %s\n",lectura);
    printf("contador: %d\n",contador);
    /*juego *listadoJuegos = (juego *)malloc(sizeof(juego) * (contador));
    for (int i = 0; i < contador; i++)
    {

        puntero_string = strtok(lectura, ",");
        if (strcmp(puntero_string, "+") == 1)
        {
        }
        else
        {
            listadoJuegos[contador].id = atoi(puntero_string);
            puntero_string = strtok(NULL, ",");
            strcpy(listadoJuegos[contador].nombre, puntero_string);
            puntero_string = strtok(NULL, ",");
            listadoJuegos[contador].restriccion = atoi(puntero_string);
            puntero_string = strtok(NULL, ",");
            listadoJuegos[contador].precio = atof(puntero_string);
            puntero_string = strtok(NULL, ",");
            strcpy(listadoJuegos[contador].proximamente, puntero_string);
            puntero_string = strtok(NULL, ",");
            listadoJuegos[contador].fechaLanzamiento = atoi(puntero_string);
            puntero_string = strtok(NULL, ",");
            strcpy(listadoJuegos[contador].gratuidad, puntero_string);
            puntero_string = strtok(NULL, ",");
            strcpy(listadoJuegos[contador].windows, puntero_string);
            puntero_string = strtok(NULL, ",");
            strcpy(listadoJuegos[contador].mac, puntero_string);
            puntero_string = strtok(NULL, ",");
            strcpy(listadoJuegos[contador].linuxx, puntero_string);
            printf("ID:%d, nombre: %s, restriccion: %d, precio: %f, proximamente:%s, fechaLanzamiento: %d, gratuidad: %s, windows: %s,mac: %s,linux: %s\n", listadoJuegos[contador].id, listadoJuegos[contador].nombre, listadoJuegos[contador].restriccion, listadoJuegos[contador].precio, listadoJuegos[contador].proximamente, listadoJuegos[contador].fechaLanzamiento, listadoJuegos[contador].gratuidad, listadoJuegos[contador].windows, listadoJuegos[contador].mac, listadoJuegos[contador].linuxx);
        }
    }*/

    // ESCRITURA WORKER
    // write(STDOUT_FILENO, "XDDDDDD", 7);}
    return 0;
}