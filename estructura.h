#ifndef estructuras_h_
#define estructuras_h_
#include <stdio.h>
// estructura para los juegos
typedef struct juego juego;
struct juego{
    int id;
    char nombre [100] ;
    int restriccion;
    float precio;
    char proximamente [100];
    int fechaLanzamiento;
    char gratuidad [100];
    char windows [1000];
    char mac [100];
    char linuxx [100];
    };


#endif /* estructuras_h_ */