#include <stdio.h>
#include <stdlib.h>
#include "servicio.h"

int mostrarServicios(eServicio servicios[], int tam_s){
    int todoOk = 0;
    if(servicios != NULL && tam_s > 0){
    //system("cls");
    printf("| *** Servicios *** | \n\n");
    printf("     Id      Descripcion  \n");
        for(int i = 0; i<tam_s; i++){
            printf("   %d     %10s     \n", servicios[i].id, servicios[i].descripcion);
        }

        todoOk = 1;
    }
    return todoOk;
}

int validarIdServicio(eServicio servicios[], int idIng, int tam_s){
    int todoOk = 0;
    if(servicios != NULL && tam_s > 0){
        for(int i = 0; i < tam_s; i++)
        {
            if(idIng == servicios[i].id)
            {
                todoOk = 1;
                break;
            }
        }
    }
    return todoOk;
}

int cargarDescripcionServicio(eServicio servicios[], int tam_s, int idMarca, char descripcion[])
{ // devuelve 0 si no encontro nada, 1 si se valido o -1 si salio todo mal
    int todoOk = 0;
    int flag = 1;
    if(servicios != NULL && tam_s > 0 && descripcion != NULL){
        for(int i = 0; i<tam_s; i++){
            if(servicios[i].id == idMarca){
                todoOk = 1;
                strcpy(descripcion,servicios[i].descripcion);
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
