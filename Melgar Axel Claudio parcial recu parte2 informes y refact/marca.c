#include <stdio.h>
#include <stdlib.h>
#include "marca.h"
#include "ctype.h"
#include "string.h"


int mostrarMarcas(eMarca marcas[], int tam_m){
    int todoOk = 0;
    if(marcas != NULL && tam_m > 0){
    //system("cls");
    printf("| *** Marcas *** | \n\n");
    printf("     Id      Descripcion  \n");
        for(int i = 0; i<tam_m; i++){
            printf("   %d     %10s     \n", marcas[i].id, marcas[i].descripcion);
        }

        todoOk = 1;
    }
    return todoOk;
}

int validarIdMarca(eMarca marcas[], int idIng, int tam_m){
    int todoOk = 0;
    if(marcas != NULL && tam_m > 0){
        for(int i = 0; i < tam_m; i++)
        {
            if(idIng == marcas[i].id)
            {
                todoOk = 1;
                break;
            }
        }
    }
    return todoOk;
}

int cargarDescripcionMarca(eMarca marcas[], int tam_m, int idMarca, char descripcion[])
{ // devuelve 0 si no encontro nada, 1 si se valido o -1 si salio todo mal
    int todoOk = 0;
    int flag = 1;
    if(marcas != NULL && tam_m > 0 && descripcion != NULL){
        for(int i = 0; i<tam_m; i++){
            if(marcas[i].id == idMarca){
                todoOk = 1;
                strcpy(descripcion,marcas[i].descripcion);
                flag = 0;
                break;
            }
        }
        if(flag){
        todoOk = -1;
        }
    }

    return todoOk;
}
