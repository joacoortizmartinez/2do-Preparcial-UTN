#ifndef STESPECIE_H_INCLUDED
#define STESPECIE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct {

	int idEspecie;
	int cantEjemplares; // cantidad de animales de esa especie
	char nombreEspecie[30];
}stEspecie;

int buscar_idespecies(char nombre_archivo[50], int id_buscado);
int cargar_arreglo_especies(stEspecie esp[], int v, int dim, char nombre_archivo[50]);
void actualizar_cantidad_ejemplares(char nombre_archivo[], int idBuscado, int cantidad_a_sumar);

#endif // STESPECIE_H_INCLUDED
