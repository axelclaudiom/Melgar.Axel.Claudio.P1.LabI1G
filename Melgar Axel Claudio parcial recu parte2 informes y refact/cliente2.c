#include <stdio.h>
#include <stdlib.h>
#include "notebook.h"
#include <strings.h>
#include "inputs.h"
#include "cliente.h"

int mostrarClientes(eCliente clientes[], int tam_cl){
    int todoOk = 0;
    if(clientes != NULL && tam_cl > 0){
    //system("cls");
    printf("| *** Clientes *** | \n\n");
    printf("     Id         Nombre    Sexo\n");
        for(int i = 0; i<tam_cl; i++){
            printf("   %d     %10s    %c \n", clientes[i].id, clientes[i].nombre, clientes[i].sexo);
        }

        todoOk = 1;
    }
    return todoOk;
}

int validarIdCliente(eCliente clientes[], int idIng, int tam_cl){
    int todoOk = 0;
    if(clientes != NULL && tam_cl > 0){
        for(int i = 0; i < tam_cl; i++)
        {
            if(idIng == clientes[i].id)
            {
                todoOk = 1;
                break;
            }
        }
    }
    return todoOk;
}

int cargarDescripcionCliente(eCliente clientes[], int tam_cl, int idMarca, char descripcion[])
{ // devuelve 0 si no encontro nada, 1 si se valido o -1 si salio todo mal
    int todoOk = 0;
    int flag = 1;
    if(clientes != NULL && tam_cl > 0 && descripcion != NULL){
        for(int i = 0; i<tam_cl; i++){
            if(clientes[i].id == idMarca){
                todoOk = 1;
                strcpy(descripcion,clientes[i].nombre);
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
