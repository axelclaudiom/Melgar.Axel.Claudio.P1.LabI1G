#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipo.h"


int mostrarTipos(eTipo tipos[], int tam_t){
    int todoOk = 0;
    if(tipos != NULL && tam_t > 0){
    //system("cls");
    printf("| *** Tipos *** | \n\n");
    printf("     Id      Descripcion  \n");
        for(int i = 0; i<tam_t; i++){
            printf("   %d     %10s     \n", tipos[i].id, tipos[i].descripcion);
        }

        todoOk = 1;
    }
    return todoOk;
}

int validarIdTipo(eTipo tipos[], int idIng, int tam_t){
    int todoOk = 0;
    if(tipos != NULL && tam_t > 0){
        for(int i = 0; i < tam_t; i++)
        {
            if(idIng == tipos[i].id)
            {
                todoOk = 1;
                break;
            }
        }
    }
    return todoOk;
}

int cargarDescripcionTipos(eTipo tipos[], int tam_t, int idTipo, char descripcion[])
{ // devuelve 0 si no encontro nada, 1 si se valido o -1 si salio todo mal
    int todoOk = 0;
    int flag = 1;
    if(tipos != NULL && tam_t > 0 && descripcion != NULL){
        for(int i = 0; i<tam_t; i++){
            if(tipos[i].id == idTipo){
                todoOk = 1;
                strcpy(descripcion,tipos[i].descripcion);
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
