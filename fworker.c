#include "fworker.h"

juego lecturaJuego(char *lineaJuego)
{
    char *puntero_string;
    juego nuevoJuego;
    puntero_string = strtok(lineaJuego, ",");
    nuevoJuego.id = atoi(puntero_string);
    puntero_string = strtok(NULL, ",");
    strcpy(nuevoJuego.nombre, puntero_string);
    puntero_string = strtok(NULL, ",");
    nuevoJuego.restriccion = atoi(puntero_string);
    puntero_string = strtok(NULL, ",");
    nuevoJuego.precio = atof(puntero_string);
    puntero_string = strtok(NULL, ",");
    strcpy(nuevoJuego.proximamente, puntero_string);
    puntero_string = strtok(NULL, ",");
    nuevoJuego.fechaLanzamiento = atoi(puntero_string);
    puntero_string = strtok(NULL, ",");
    strcpy(nuevoJuego.gratuidad, puntero_string);
    puntero_string = strtok(NULL, ",");
    strcpy(nuevoJuego.windows, puntero_string);
    puntero_string = strtok(NULL, ",");
    strcpy(nuevoJuego.mac, puntero_string);
    puntero_string = strtok(NULL, ",");
    strcpy(nuevoJuego.linuxx, puntero_string);
    printf("ID:%d, nombre: %s, restriccion: %d, precio: %f, proximamente:%s, fechaLanzamiento: %d, gratuidad: %s, windows: %s,mac: %s,linux: %s\n", nuevoJuego.id, nuevoJuego.nombre, nuevoJuego.restriccion, nuevoJuego.precio, nuevoJuego.proximamente, nuevoJuego.fechaLanzamiento, nuevoJuego.gratuidad, nuevoJuego.windows, nuevoJuego.mac, nuevoJuego.linuxx);
    return nuevoJuego;
}