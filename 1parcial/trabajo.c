
#include <stdio.h>
#include <stdlib.h>
#include "trabajo.h"
#include "notebook.h"
#include "tipo.h"
#include "marca.h"
#include "servicio.h"
int buscarLibreT(eTrabajo trabajos[], int tam_t)
{
    int todoOk = -1;
    if (trabajos != NULL && tam_t > 0)
    {
        for(int i = 0; i<tam_t; i++)
        {
            if(trabajos[i].isEmpty)
            {
                todoOk = i;
                break;
            }
        }
    }

    return todoOk;
}

int altaTrabajo(eTrabajo trabajos[], int tam_tt , eNotebook notebooks[], int tam_n, eMarca marcas[], int tam_m, eTipo tipos[], int tam_t , eServicio servicios[], int tam_s, int* pId)
{
    int todoOk = 0;
    int indice;
    //int verifLoca;
    //eNotebook auxNotebook;
    eTrabajo auxTrabajo;

    if (trabajos != NULL && tam_tt > 0)
    {
        system("cls");
        printf("         **** Alta Trabajo **** \n\n");
        indice = buscarLibreT(trabajos, tam_t);
        if(indice == -1)
        {
            printf("No hay lugar \n");
        }
        else
        {

            auxTrabajo.id = *pId;
            *pId += 1;

            mostrarNotebooks(notebooks,tam_n,marcas,tam_m,tipos,tam_t);
            printf("Ingrese ID notebook: ");
            scanf("%d", &auxTrabajo.idNotebook);

            while(buscarNotebookId(notebooks, tam_n, auxTrabajo.idNotebook) == -1)
            {
                printf("Error.. Reingrese ID Notebook: ");
                scanf("%d", &auxTrabajo.idNotebook);
            }

            // marcas
            mostrarServicios(servicios, tam_s);

            printf("Ingrese ID Servicio: ");
            scanf("%d", &auxTrabajo.idServicio);
            while(!validarIdServicio(servicios, auxTrabajo.idServicio, tam_s))
            {
                printf("Error.. Reingrese ID Servicio: ");
                scanf("%d", &auxTrabajo.idServicio);
            }

            printf("Ingrese fecha");
            scanf("%d/%d/%d", &auxTrabajo.fecha.dia, &auxTrabajo.fecha.mes, &auxTrabajo.fecha.anio);

            auxTrabajo.isEmpty = 0;

            trabajos[indice] = auxTrabajo;

            todoOk = 1;
        }

    }

    return todoOk;
}
