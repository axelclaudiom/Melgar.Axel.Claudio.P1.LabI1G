
#include <stdio.h>
#include <stdlib.h>
#include "trabajo.h"
#include "notebook.h"
#include "tipo.h"
#include "marca.h"
#include "servicio.h"
#include "inputs.h"
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
            /*printf("Ingrese ID notebook: ");
            scanf("%d", &auxTrabajo.idNotebook);*/
            auxTrabajo.idNotebook =  getInt("Ingrese ID notebook: ");

            while(buscarNotebookId(notebooks, tam_n, auxTrabajo.idNotebook) == -1)
            {
                /*printf("Error.. Reingrese ID Notebook: ");
                scanf("%d", &auxTrabajo.idNotebook);*/
                auxTrabajo.idNotebook =  getInt("Error.. ReIngrese ID notebook: ");
            }

            // marcas
            mostrarServicios(servicios, tam_s);

            /*printf("Ingrese ID Servicio: ");
            scanf("%d", &auxTrabajo.idServicio);*/
            auxTrabajo.idServicio = getInt("Ingrese ID Servicio: ");
            while(!validarIdServicio(servicios, auxTrabajo.idServicio, tam_s))
            {
                /*printf("Error.. Reingrese ID Servicio: ");
                scanf("%d", &auxTrabajo.idServicio);*/
                auxTrabajo.idServicio = getInt("Error. ReIngrese ID Servicio: ");
            }

            printf("Ingrese fecha: ");
            scanf("%d/%d/%d", &auxTrabajo.fecha.dia, &auxTrabajo.fecha.mes, &auxTrabajo.fecha.anio);

            auxTrabajo.isEmpty = 0;

            trabajos[indice] = auxTrabajo;

            todoOk = 1;
        }

    }

    return todoOk;
}
/*
int mostrarTrabajos(eTrabajo trabajos[], int tam_tt){
    int todoOk = 0;
    if(trabajos != NULL && tam_tt > 0){
    //system("cls");
    printf("| *** Trabajos *** | \n\n");
    printf("     Id      servicio  \n");
        for(int i = 0; i<tam_tt; i++){
            printf("   %d     %d     \n", trabajos[i].id, trabajos[i].idServicio);
        }

        todoOk = 1;
    }
    return todoOk;
}*/

int inicializarTrabajos(eTrabajo trabajos[], int tam_tt)
{
    int todoOk = 0;
    if (trabajos != NULL && tam_tt > 0)
    {
        for(int i = 0; i<tam_tt; i++)
        {
            trabajos[i].isEmpty = 1;
        }
        todoOk = 1;
    }

    return todoOk;
}

void mostrarTrabajo(eTrabajo unTrabajo, eNotebook notebooks[], int tam_n, eServicio servicios[], int tam_s)
{
    char modelo[20];
    char servicio[20];
    if(cargarModeloNotebook(notebooks, tam_n, unTrabajo.idNotebook, modelo) == 1 && cargarDescripcionServicio(servicios, tam_s, unTrabajo.idServicio, servicio) == 1)
    {
        printf("  %d  %10s       %10s      %02d/%02d/%d  \n", unTrabajo.id, modelo, servicio, unTrabajo.fecha.dia, unTrabajo.fecha.mes, unTrabajo.fecha.anio);
        /*printf("aca entra");*/
    }
}

int mostrarTrabajos(eTrabajo trabajos[], int tam_tt, eNotebook notebooks[], int tam_n, eServicio servicios[], int tam_s)
{
    int todoOk = 0;
    int flag = 1;
    if (trabajos != NULL && tam_tt > 0 && notebooks != NULL && tam_n >0 && servicios!= NULL && tam_s > 0)
    {
        //system("cls");
        printf(" | ********* Lista de Trabajos ********* |\n");
        printf("---------------------------------------------------------\n");
        printf("    Id        Modelo         Servicio       Fecha\n");
        printf("---------------------------------------------------------\n");
        for(int i = 0; i< tam_tt; i++)
        {
            if(!trabajos[i].isEmpty)
            {
                mostrarTrabajo(trabajos[i], notebooks,tam_n,servicios,tam_s);
                flag = 0;
            }
        }
        if(flag)
        {
            printf("No hay Trabajos para mostrar\n");
        }
        todoOk = 1;
    }
    return todoOk;

}
