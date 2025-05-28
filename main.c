#include <stdio.h>
#include <stdlib.h>
#include "stAnimal.h"
#include "stEspecie.h"

void mostrar_recursiva_animal(int i, stAnimal animal[], int v);

int main()
{
    stEspecie especies[100];
    int v_especies = 0;
    int dim_especies = 100;
    char nom_archi_especies[50] = "especies.dat";


    v_especies = cargar_arreglo_especies(especies, v_especies, dim_especies, nom_archi_especies);
    for(int i = 0; i<v_especies; i++)
    {
        printf("\n\n");
        printf(" Id especie: %d \n", especies[i].idEspecie);
        printf(" Cantidad de ejemplares: %d \n" ,especies[i].cantEjemplares);
        printf(" Nombre de especie: %s\n", especies[i].nombreEspecie);
    }

    stAnimal animal[30];
    int v_animal = 0;
    int dim_animal = 30;

    v_animal = cargar_arreglo_animal(animal, dim_animal, v_animal);


    mostrar_recursiva_animal(0, animal, v_animal);
    printf(" validos animal %d \n", v_animal);
   /** v_especies = cargar_arreglo_especies_condicion(especies, v_especies, dim_especies, nom_archi_especies);
    for(int i = 0; i<v_especies; i++)
    {
        printf("\n\n");
        printf(" Id especie: %d \n", especies[i].idEspecie);
        printf(" Cantidad de ejemplares: %d \n" ,especies[i].cantEjemplares);
        printf(" Nombre de especie: %s\n", especies[i].nombreEspecie);
    }*/
    return 0;
}


void mostrar_recursiva_animal(int i, stAnimal animal[], int v)
{
    if(i<v)
    {
        mostrar_un_animal(animal[i]);
        mostrar_recursiva_animal(i+1, animal, v);
    }
}

void array_animales_a_archivo(stAnimal animal[], int v, char nomb[])
{
    FILE *archi = fopen(nomb, "wb");
    stAnimal aux;
    if(archi)
    {
        for(int i = 0; i<v; i++)
        {
            if(animal[i].poblacion>100)
            {
                aux = animal[i];
                fwrite(&aux, sizeof(stAnimal), 1, archi);
            }
        }
        fclose(archi);
    }
}

float suma_recursiva(int i, int v, stAnimal ani[])
{
    float suma = 0;
    float suma_total = 0;

    if (i < v)
    {
        suma = ani[i].poblacion;
        suma_total = suma_recursiva(i+1, v, ani) + suma;
    }

    return suma;
}

