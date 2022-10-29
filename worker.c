#include "fworker.h"

int main(int argc, char *argv[])
{
    // LECTURA WORKERS
    char buff[10000];
    int contador = 0;
    char lectura[100000] = "";
    char *puntero_string;
    while (1)
    {
        read(STDIN_FILENO, buff, sizeof(buff));
        if (strcmp(buff, "FIN") == 0)
        {
            break;
        }
        strcat(lectura, buff);
        strcat(lectura, ",+,");
        contador++;
    }
   

    // declaracion arreglo de lineas
    char **lineas = (char **) malloc(sizeof(char*) * (contador)); 
    // asignando memoria a el arreglo de lineas
    for(int i=0;i<contador;i++){
        lineas[i] = (char*)malloc(sizeof(char)*500);
    }
    puntero_string = strtok(lectura, "+");
    // Se agregan las lineas a 
    for(int i=0; i<contador; i++){
        strcpy(lineas[i] , puntero_string);
        puntero_string = strtok(NULL, "+");
    }
    printf("lectura : %s\n", lectura);
    printf("contador: %d\n", contador);

    juego *listadoJuegos = (juego *)malloc(sizeof(juego) * (contador));
    for (int i = 0; i < contador; i++)
    {
        listadoJuegos[i] = lecturaJuego(lineas[i]);
        printf("ID:%d, nombre: %s, restriccion: %d, precio: %f, proximamente:%s, fechaLanzamiento: %d, gratuidad: %s, windows: %s,mac: %s,linux: %s\n", listadoJuegos[i].id, listadoJuegos[i].nombre, listadoJuegos[i].restriccion, listadoJuegos[i].precio, listadoJuegos[i].proximamente, listadoJuegos[i].fechaLanzamiento, listadoJuegos[i].gratuidad, listadoJuegos[i].windows, listadoJuegos[i].mac, listadoJuegos[i].linuxx);
    }
    
    // ESCRITURA WORKER
    // write(STDOUT_FILENO, "XDDDDDD", 7);}

    // Liberando memoria de  los arreglos
    for(int i=0;i<contador;i++){
        free(lineas[i]);
    }
    free(lineas);
    






    return 0;
}