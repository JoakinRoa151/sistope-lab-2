#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <sys/wait.h>
#include "estructura.h"

juego lecturaJuego(char *lineaJuego);
juego *agregarJuegoLista(juego *lista, juego juegoAgregar, int *n);