#include "stEspecie.h"


int buscar_idespecies(char nombre_archivo[50], int id_buscado)
{
    FILE *archi = fopen(nombre_archivo, "rb");
    int flag = 0;
    stEspecie aux;

    if(archi)
    {
        while(flag == 0 && fread(&aux, sizeof(stEspecie), 1, archi) == 1)
        {
            if(aux.idEspecie == id_buscado)
            {
                flag = 1;
            }
        }

        fclose(archi);
    }

    return flag;
}

int cargar_arreglo_especies(stEspecie esp[], int v, int dim, char nombre_archivo[50])
{

    FILE *archi = fopen(nombre_archivo, "rb");
    int i = 0;
    if(archi)
    {
        while(i<dim && fread(&esp[i], sizeof(stEspecie), 1, archi))
        {
            i++;
        }
        fclose(archi);
    }

    return i;
}

void actualizar_cantidad_ejemplares(char nombre_archivo[], int idBuscado, int cantidad_a_sumar)
{
    FILE *archi = fopen(nombre_archivo, "rb+");
    stEspecie aux;
    int flag=0;
    if(archi)
    {
        while(flag == 0 && fread(&aux, sizeof(stEspecie), 1, archi) == 1)
        {
            if(idBuscado == aux.idEspecie)
            {
                aux.cantEjemplares += cantidad_a_sumar;

                fseek(archi, -1 * sizeof(stEspecie), SEEK_CUR);
                fwrite(&aux, sizeof(stEspecie), 1, archi);
                flag=1;
            }
        }

        fclose(archi);
    }
}

int cargar_arreglo_especies_condicion(stEspecie esp[], int v, int dim, char nombre_archivo[50])
{

    FILE *archi = fopen(nombre_archivo, "rb");
    int i = 0;
    stEspecie aux;

    if(archi)
    {
        while(i<dim && fread(&aux, sizeof(stEspecie), 1, archi) == 1)
        {
            if(aux.cantEjemplares>2)
            {
                esp[i] = aux;
                i++;
            }

        }
        fclose(archi);
    }

    return i;
}
