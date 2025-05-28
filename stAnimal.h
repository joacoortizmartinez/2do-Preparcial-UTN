#ifndef STANIMAL_H_INCLUDED
#define STANIMAL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "stEspecie.h"
typedef struct
{
    int nro_identificacion;
    int idEspecie;
    char nombreAnimal[30];
    int poblacion;    // cantidad de animales
} stAnimal;

stAnimal cargar_un_animal();
int cargar_arreglo_animal(stAnimal an[], int dim, int v);

#endif // STANIMAL_H_INCLUDED
