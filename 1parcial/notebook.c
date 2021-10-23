#include <stdio.h>
#include <stdlib.h>
#include "notebook.h"
#include <strings.h>
int menu()
{
    char opcion;
    //system("cls");
    fflush(stdin);
    printf("     ***ABM Notebooks ***\n");
    printf("A - Alta Notebook \n");
    printf("B - Modificar Notebooks \n");
    printf("C - Baja Notebook \n");
    printf("D - Listar Notebook \n");
    printf("E - Listar Marcas \n");
    printf("F - Listar Tipos \n");
    printf("G - Listar Servicios \n");
    printf("H - Alta Trabajo \n");
    printf("Z - Salir \n");
    printf("Ingrese opcion: ");
    scanf("%c", &opcion);
    return opcion;
}

int inicializarNotebooks(eNotebook notebooks[], int tam_n)
{
    int todoOk = 0;
    if (notebooks != NULL && tam_n > 0)
    {
        for(int i = 0; i<tam_n; i++)
        {
            notebooks[i].isEmpty = 1;
        }
        todoOk = 1;
    }

    return todoOk;
}

int buscarLibre(eNotebook notebooks[], int tam_n)
{
    int todoOk = -1;
    if (notebooks != NULL && tam_n > 0)
    {
        for(int i = 0; i<tam_n; i++)
        {
            if(notebooks[i].isEmpty)
            {
                todoOk = i;
                break;
            }
        }
    }

    return todoOk;
}

int altaNotebook(eNotebook notebooks[], int tam_n, eMarca marcas[], int tam_m, eTipo tipos[], int tam_t ,int* pId)
{
    int todoOk = 0;
    int indice;
    //int verifLoca;
    eNotebook auxNotebook;

    if (notebooks != NULL && tam_n > 0)
    {
        system("cls");
        printf("         **** Alta Notebook **** \n\n");
        indice = buscarLibre(notebooks, tam_n);
        if(indice == -1)
        {
            printf("No hay lugar \n");
        }
        else
        {

            auxNotebook.id = *pId;
            *pId += 1;

            // modelo

            printf("Ingrese Modelo:");
            fflush(stdin);
            gets(auxNotebook.modelo);

            // marcas
            mostrarMarcas(marcas, tam_m);

            printf("Ingrese ID Marca: ");
            scanf("%d", &auxNotebook.idMarca);
            while(!validarIdMarca(marcas, auxNotebook.idMarca, tam_m))
            {
                printf("Error.. Reingrese ID Marca: ");
                scanf("%d", &auxNotebook.idMarca);
            }

            // tipos
            mostrarTipos(tipos, tam_t);

            printf("Ingrese ID Tipo: ");
            scanf("%d", &auxNotebook.idTipo);
            while(!validarIdTipo(tipos, auxNotebook.idTipo, tam_t))
            {
                printf("Error.. Reingrese ID Tipo: ");
                scanf("%d", &auxNotebook.idTipo);
            }

            // precio
            printf("Ingrese precio:");
            scanf("%f", &auxNotebook.precio);

            auxNotebook.isEmpty = 0;

            notebooks[indice] = auxNotebook;

            todoOk = 1;
        }

    }

    return todoOk;
}

void mostrarNotebook(eNotebook p, eMarca marcas[], int tam_m, eTipo tipos[], int tam_t)
{
    char descMarca[20];
    char descTipo[20];
    if(cargarDescripcionMarca(marcas, tam_m, p.idMarca, descMarca) == 1 && cargarDescripcionTipos(tipos,tam_t,p.idTipo, descTipo))
    {
        printf("  %d  %10s  %10s   %10s   %.2f \n", p.id, p.modelo, descMarca, descTipo, p.precio);
    }
}

int mostrarNotebooks(eNotebook notebooks[], int tam_n, eMarca marcas[], int tam_m, eTipo tipos[], int tam_t)
{
    int todoOk = 0;
    int flag = 1;
    if(notebooks != NULL && tam_n > 0)
    {
        //system("cls");
        printf(" | ********* Lista de Notebooks ********* |\n");
        printf("---------------------------------------------------------\n");
        printf(" Id    Modelo   Marca   Precio    \n");
        printf("---------------------------------------------------------\n");
        for(int i = 0; i< tam_n; i++)
        {
            if(!notebooks[i].isEmpty)
            {
                mostrarNotebook(notebooks[i], marcas, tam_m, tipos, tam_t);
                flag = 0;
            }
        }
        if(flag)
        {
            printf("No hay personas para mostrar\n");
        }
        todoOk = 1;
    }
    return todoOk;

}

int buscarNotebookId(eNotebook notebooks[], int tam_n, int id)
{
    int todoOk = -1;
    if(notebooks != NULL && tam_n > 0)
    {
        for(int i = 0; i < tam_n; i++)
        {
            if(notebooks[i].id == id && !notebooks[i].isEmpty)
            {
                todoOk = i;
                break;
            }
        }
    }
    return todoOk;
}

int modificarNotebook(eNotebook notebooks[], int tam_n, eMarca marcas[], int tam_m, eTipo tipos[], int tam_t)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;
    float auxPrecio;
    int auxTipo;


    if(notebooks != NULL && tam_n > 0)
    {
        system("cls");
        printf("        *** Modificar Notebook *** \n\n");
        mostrarNotebooks(notebooks,tam_n, marcas, tam_n, tipos, tam_t);
        printf("Ingrese id: ");
        scanf("%d", &id);
        indice = buscarNotebookId(notebooks, tam_n, id);
        if (indice == -1)
        {
            printf("El ID %d no se encuentra en el sistema \n", id);
        }
        else
        {
            mostrarNotebook(notebooks[indice], marcas, tam_m, tipos, tam_t);

            printf("Confirma modificacion?: ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                switch(menuModificacion())
                {
                case 1:
                    printf("Ingrese nuevo precio:");
                    scanf("%f", &auxPrecio);
                    notebooks[indice].precio = auxPrecio;
                    break;
                case 2:

                    mostrarTipos(tipos, tam_t);

                    printf("Ingrese Nuevo ID Tipo: ");
                    scanf("%d", &auxTipo);
                    while(!validarIdTipo(tipos, auxTipo, tam_t))
                    {
                        printf("Error.. Reingrese ID Tipo: ");
                        scanf("%d", &auxTipo);
                    }
                    notebooks[indice].idTipo = auxTipo;

                    break;
                case 3:
                    confirma = 'n';
                default:
                    printf("Opcion invalida!");
                }

                todoOk = 1;
            }
            else
            {
                printf("Modificacion cancelada por el usuario");
            }

        }
        //todoOk = 1;
    }
    return todoOk;
}

int menuModificacion()
{
    int opcion;
    //system("cls");
    fflush(stdin);
    printf("1 - Precio \n");
    printf("2 - Tipo \n");
    printf("3 - Salir \n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

int bajaNotebook(eNotebook notebooks[], int tam_n, eMarca marcas[], int tam_m, eTipo tipos[], int tam_t)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;
    if(notebooks != NULL && tam_n > 0)
    {
        system("cls");
        printf("        *** Baja Notebook *** \n\n");
        mostrarNotebooks(notebooks,tam_n, marcas, tam_n, tipos, tam_t);
        printf("Ingrese id notebook: ");
        scanf("%d", &id);
        indice = buscarNotebookId(notebooks, tam_n, id);
        if (indice == -1)
        {
            printf("El ID %d no se encuentra en el sistema \n", id);
        }
        else
        {
            mostrarNotebook(notebooks[indice], marcas,tam_m,tipos,tam_t);
            printf("Confirma Baja?: ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                notebooks[indice].isEmpty = 1;
                todoOk = 1;
            }
            else
            {
                printf("Baja cancelada por el usuario");
            }

        }
        //todoOk = 1;
    }
    return todoOk;
}

int ordenarNotebooks(eNotebook notebooks[], int tam_n, eMarca marcas[], int tam_m)
{
    int todoOk = 0;
    eNotebook auxNotebook;
    if(notebooks != NULL && tam_n > 0)
    {
        for(int i=0; i < tam_n -1; i++)
        {
            char descMarcai[20];
            cargarDescripcionMarca(marcas, tam_m, notebooks[i].idMarca, descMarcai);
            for(int j= i+1; j< tam_n; j++)
            {
                char descMarcaj[20];
                cargarDescripcionMarca(marcas, tam_m, notebooks[j].idMarca, descMarcaj);
                if((notebooks[i].precio > notebooks[j].precio) || (notebooks[j].precio == notebooks[j].precio && strcmp(descMarcai, descMarcaj) >0 ))
                {
                    auxNotebook = notebooks[i];
                    notebooks[i] = notebooks[j];
                    notebooks[j] = auxNotebook;
                }
            }
        }
        todoOk = 1;
    }

    return todoOk;
}
