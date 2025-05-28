#include "stAnimal.h"s

char nombre_archi[50] = "especies.dat";

void mostrar_un_animal(stAnimal an)
{
    printf(" ID especie %d \n", an.idEspecie);
    printf(" ID animal %d \n", an.nro_identificacion);
    printf("Nombre animal  %s \n", an.nombreAnimal);
    printf(" cantidad de animales %d \n", an.poblacion);
}

stAnimal cargar_un_animal()
{
    stAnimal aux;
    int flag = 0;

    printf("Ingrese el numero de identificacion del animal: \n");
    scanf("%d", &aux.nro_identificacion);

    while(flag == 0)
    {
        printf("Ingrese el idEspecie del animal: \n");
        scanf(" %d", &aux.idEspecie);

        if(buscar_idespecies(nombre_archi, aux.idEspecie))
        {
            flag = 1;
        }
        else
        {
                printf("El id no esta registrado \n");
        }

    }

    printf("Ingrese el nombre del animal: \n");
    scanf(" %s", &aux.nombreAnimal);

    printf("Ingrese cantidad de poblacion: \n");
    scanf(" %d", &aux.poblacion);

    actualizar_cantidad_ejemplares(nombre_archi, aux.idEspecie, aux.poblacion);

    return aux;
}

int cargar_arreglo_animal(stAnimal an[], int dim, int v)
{
    char op = 's';

    while(op == 's' && v < dim)
    {
        an[v] = cargar_un_animal();
        v++;

        printf("¿Querés seguir cargando? s / n: ");
        scanf(" %c", &op);
    }

    return v;
}



