#include <stdio.h>
#include <stdlib.h>
#include "notebook.h"
#include "servicio.h"
#include "marca.h"
#include "dataharc.h"
#include "trabajo.h"

#define TAM_N 6
#define TAM_M 4
#define TAM_T 4
#define TAM_S 4
#define TAM_TT 5

int main()
{
    char seguir = 's';

    eNotebook notebooks[TAM_N];
    eTrabajo trabajos[TAM_T];
    int nextIdNotebook = 50000;
    int nextIdTrabajo = 90000;
    int flagAltaNotebook = 0;
    int flagAltaTrabajo = 0;

    eMarca marcas[TAM_M] = {
    {1000, "Compq"},
    {1001, "Asus"},
    {1002, "Acer"},
    {1003, "HP"}
    };

    eTipo tipos[TAM_T] = {
    {5000 ,"Gamer"},
    {5001 ,"Disenio"},
    {5002 ,"Ultrabook"},
    {5003 ,"Normalita"}
    };

    eServicio servicios[TAM_S] = {
    {20000 ,"Bateria", 2250},
    {20001 ,"Display", 10300},
    {20002 ,"Mantenimiento", 4400},
    {20003 ,"Fuente", 5600}
    };

    if(!inicializarNotebooks(notebooks, TAM_N))
    {
        printf("Problema al inicializar!\n");
    }

    if(!inicializarTrabajos(trabajos, TAM_TT))
    {
        printf("Problema al inicializar trabajos!\n");
    }
    hardcodearNotebooks(notebooks,TAM_N, 5, &nextIdNotebook);
    hardcodearTrabajos(trabajos, TAM_TT, 3, &nextIdTrabajo);
    do
    {
        system("cls");
        switch(menu())
        {
        case 'a':
            if(!altaNotebook(notebooks,TAM_N, marcas, TAM_M, tipos, TAM_T, &nextIdNotebook)){
                printf("No se pudo realizar el alta \n");
            }
            else{
                printf("Alta exitosa \n");
                flagAltaNotebook = 1;
            }
            break;
        case 'b':
            if(flagAltaNotebook){
                if(!modificarNotebook(notebooks, TAM_N,marcas,TAM_M,tipos,TAM_T)){
                    printf("No se pudo realizar la modificacion \n");
                }
                else{
                    printf("modificacion exitosa \n");
                }
            }
            else{
                printf("Para hacer una modificacion primero tenes que hacer un Alta \n");
            }
            break;
        case 'c':
            if(flagAltaNotebook){
                if(!bajaNotebook(notebooks, TAM_N,marcas,TAM_M, tipos, TAM_T)){
                    printf("No se pudo realizar la baja \n");
                }
                else{
                    printf("Baja exitosa \n");
                }
            }
            else{
                printf("Para hacer una baja primero tenes que hacer una Alta \n");
            }
            break;
        case 'd':
            if(flagAltaNotebook){
                ordenarNotebooks(notebooks, TAM_N, marcas, TAM_M);
                mostrarNotebooks(notebooks,TAM_N, marcas, TAM_M, tipos, TAM_T);
            }
            else{
                printf("Para mostrar primero tenes que hacer un alta \n");
            }
            break;
        case 'e':
            mostrarMarcas(marcas, TAM_M);
            break;
        case 'f':
            mostrarTipos(tipos,TAM_T);
            break;
        case 'g':
            mostrarServicios(servicios,TAM_S);
        break;
        case 'h':
            if(flagAltaNotebook){
                if(!altaTrabajo(trabajos, TAM_TT, notebooks,TAM_N,marcas,TAM_M,tipos,TAM_T,servicios,TAM_S,&nextIdTrabajo)){
                    printf("No se pudo realizar el alta \n");
                }
                else{
                    printf("Alta Exitosa \n");
                    flagAltaTrabajo = 1;
                }
            }
            else{
                printf("Para dar un trabajo de alta, primero tenes que dar de alta una notebook \n");
            }
        break;
        case 'i':
            if(flagAltaNotebook && flagAltaTrabajo){
                mostrarTrabajos(trabajos,TAM_TT, notebooks, TAM_N, servicios, TAM_S);
            }
            else{
                printf("Para listar trabajos primero tenes que hacer un Alta de trabajo \n");
            }
        break;
        case 20:
            printf("salir \n");
            seguir = 'n';
            break;
        default:
            printf("opcion invalida");

        }
        system("pause");
    }
    while (seguir=='s');
    return 0;
}
