#include "fbroker.h"

/*
Entrada: lista de struct anioPosicion, posicion final, anio, tamaño de la lista
Salida: lista de struct anioPosicion con un dato agregado
Descripción: funcion que agrega datos de una lista tipo struct anio Posicion
*/
calculosJuegoPorAnio *agregarCalculoLista(calculosJuegoPorAnio *listaCalculos, calculosJuegoPorAnio calculoAgregar, int *n)
{
    calculosJuegoPorAnio *nuevaLista = malloc(sizeof(calculosJuegoPorAnio) * (*n + 1));
    for (int i = 0; i < *n; i++)
    {
        nuevaLista[i]=listaCalculos[i];
    }
    nuevaLista[*n]=calculoAgregar;
    *n = *n + 1;
    free(listaCalculos);
    return nuevaLista;
}

int verificarCalculoEnLista(calculosJuegoPorAnio * listaCalculos,calculosJuegoPorAnio calculo, int n){
    for(int i=0;i<n;i++){
        if(listaCalculos[i].anioJuego == calculo.anioJuego){
            return 1;
        }
    }
    return 0;
}



calculosJuegoPorAnio lecturaCalculo(char *lineaCalculo)
{
    char *puntero_string;
    
    calculosJuegoPorAnio nuevoCalculo;
    puntero_string = strtok(lineaCalculo, "+");
    nuevoCalculo.anioJuego = atoi(puntero_string);

    
    puntero_string = strtok(NULL, "+");
    nuevoCalculo.cantidadJuegos = atoi(puntero_string);
 
    
    puntero_string = strtok(NULL, "+");
    nuevoCalculo.windows = atoi(puntero_string);

    
    puntero_string = strtok(NULL, "+");
    nuevoCalculo.mac = atoi(puntero_string);

    
    puntero_string = strtok(NULL, "+");
    nuevoCalculo.linuxx = atoi(puntero_string);

   
    puntero_string = strtok(NULL, "+");
    strcpy(nuevoCalculo.nombreJuegoMasCaro, puntero_string);

    
    puntero_string = strtok(NULL, "+");
    strcpy(nuevoCalculo.nombreJuegoMasBarato, puntero_string);

    
    puntero_string = strtok(NULL, "+");
    strcpy(nuevoCalculo.juegosGratis, puntero_string);

    
    puntero_string = strtok(NULL, "+");
    nuevoCalculo.precioJuegoMasCaro = atof(puntero_string);

    
    puntero_string = strtok(NULL, "+");
    nuevoCalculo.precioJuegoMasBarato = atof(puntero_string);

    
    puntero_string = strtok(NULL, "+");
    nuevoCalculo.sumaPreciosPorAnio = atof(puntero_string);
    //printf("%d %d %d %d %d %s %s %s %f %f %f", nuevoCalculo.anioJuego, nuevoCalculo.cantidadJuegos, nuevoCalculo.windows, nuevoCalculo.mac, nuevoCalculo.linuxx, nuevoCalculo.nombreJuegoMasCaro, nuevoCalculo.nombreJuegoMasBarato, nuevoCalculo.juegosGratis, nuevoCalculo.precioJuegoMasCaro, nuevoCalculo.precioJuegoMasBarato, nuevoCalculo.sumaPreciosPorAnio);
    //printf("XDD\n");
    return nuevoCalculo;
}

calculosJuegoPorAnio * evaluacionCalculo(calculosJuegoPorAnio * listaCalculo, calculosJuegoPorAnio calculoPorAnio, int  *n){
    int posicionCalculo;
    calculosJuegoPorAnio * listaCalculoNueva;
    if(verificarCalculoEnLista(listaCalculo,calculoPorAnio,*n)==1){
        posicionCalculo=buscarPosicionCalculo(listaCalculo,calculoPorAnio,*n);
        if (listaCalculo[posicionCalculo].precioJuegoMasCaro < calculoPorAnio.precioJuegoMasCaro)
        {
            listaCalculo[posicionCalculo].precioJuegoMasCaro= calculoPorAnio.precioJuegoMasCaro;
            strcpy(listaCalculo[posicionCalculo].nombreJuegoMasCaro , calculoPorAnio.nombreJuegoMasCaro);
        }
        // Se calcula el juego mas barato
        if (listaCalculo[posicionCalculo].precioJuegoMasBarato > calculoPorAnio.precioJuegoMasBarato)
        {
            listaCalculo[posicionCalculo].precioJuegoMasBarato= calculoPorAnio.precioJuegoMasBarato;
            strcpy(listaCalculo[posicionCalculo].nombreJuegoMasBarato , calculoPorAnio.nombreJuegoMasBarato);
        }
        listaCalculo[posicionCalculo].windows=listaCalculo[posicionCalculo].windows+calculoPorAnio.windows;
        listaCalculo[posicionCalculo].mac =listaCalculo[posicionCalculo].mac+calculoPorAnio.mac;
        listaCalculo[posicionCalculo].linuxx= listaCalculo[posicionCalculo].linuxx+calculoPorAnio.linuxx;
        listaCalculo[posicionCalculo].sumaPreciosPorAnio=listaCalculo[posicionCalculo].sumaPreciosPorAnio+calculoPorAnio.sumaPreciosPorAnio;
        listaCalculo[posicionCalculo].cantidadJuegos=listaCalculo[posicionCalculo].cantidadJuegos+calculoPorAnio.cantidadJuegos;
        return (listaCalculo);
    }
    else{
       listaCalculoNueva=agregarCalculoLista(listaCalculo,calculoPorAnio,n);
       return(listaCalculoNueva);
    }
}

// Entrada: lista de struct anioPosicion, posicion final, anio, tamaño de la lista
// Salida: lista de struct anioPosicion con un dato agregado.
// Descripción: Función que busca la posición de un calculo en la lista.

int buscarPosicionCalculo(calculosJuegoPorAnio * listaCalculo, calculosJuegoPorAnio calculoPorAnio, int  n){
    int posicionCalculo;
    for (int i = 0; i < n; i++)
    {
        if (listaCalculo[i].anioJuego == calculoPorAnio.anioJuego)
        {
            posicionCalculo=i;
        }
    }
    return posicionCalculo;
}