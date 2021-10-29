#include <stdio.h>
#include <stdlib.h>
#include "notebook.h"
#include <strings.h>
#include "inputs.h"
//#include "trabajo.h"

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
    printf("E - Listar Tipos \n");
    printf("F - Listar Marcas \n");
    printf("G - Listar Servicios \n");
    printf("H - Alta Trabajo \n");
    printf("I - Listar Trabajos \n");
    printf("J - Mostrar Clientes \n");
    printf("K - Informar Notebooks de una Marca \n");
    printf("L - Informar Notebooks de un Tipo \n");
    printf("M - Informar Notebooks de menor precio \n");
    printf("N - Informar Notebooks separadas por Marca \n");
    printf("O - Informar Cantidad de Notebooks Marca y tipo \n");
    printf("P - Informar Marca Mas elegida \n");
    printf("Q - Informar Trabajos  realizados en una notebook \n");
    printf("R - Informar Suma de importes de una notebook \n");
    printf("S - Informar notebooks por servicio\n");
    printf("T - Informar servicios realizados por fecha  \n");
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

int altaNotebook(eNotebook notebooks[], int tam_n, eMarca marcas[], int tam_m, eTipo tipos[], int tam_t, eCliente clientes[], int tam_cl, int* pId)
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
            fflush(stdin);
            pedirCadena("Ingrese Modelo: \n" , auxNotebook.modelo);
           /* printf("Ingrese Modelo:");
            fflush(stdin);
            gets(auxNotebook.modelo);*/

            // marcas
            mostrarMarcas(marcas, tam_m);

            /*printf("Ingrese ID Marca: ");
            scanf("%d", &auxNotebook.idMarca);*/
            auxNotebook.idMarca = getInt("\n Ingrese Id Marca: ");

            while(!validarIdMarca(marcas, auxNotebook.idMarca, tam_m))
            {
                /*printf("Error.. Reingrese ID Marca: ");
                scanf("%d", &auxNotebook.idMarca);*/
                auxNotebook.idMarca = getInt("\n Error.. ReIngrese Id Marca: ");
            }

            // tipos
            mostrarTipos(tipos, tam_t);

            /*printf("Ingrese ID Tipo: ");
            scanf("%d", &auxNotebook.idTipo);*/

            auxNotebook.idTipo = getInt("\n Ingrese ID Tipo: ");

            while(!validarIdTipo(tipos, auxNotebook.idTipo, tam_t))
            {
                /*printf("Error.. Reingrese ID Tipo: ");
                scanf("%d", &auxNotebook.idTipo);*/
                auxNotebook.idTipo = getInt("\n Error.. ReIngrese ID Tipo: ");
            }

            // precio
            /*printf("Ingrese precio:");
            scanf("%f", &auxNotebook.precio);*/

            auxNotebook.precio = getFloat("Ingrese precio:");

            auxNotebook.isEmpty = 0;

            notebooks[indice] = auxNotebook;

            todoOk = 1;
        }

    }

    return todoOk;
}

void mostrarNotebook(eNotebook p, eMarca marcas[], int tam_m, eTipo tipos[], int tam_t, eCliente clientes[], int tam_cl)
{
    char descMarca[20];
    char descTipo[20];
    char descCliente[20];
    if(cargarDescripcionMarca(marcas, tam_m, p.idMarca, descMarca) == 1 && cargarDescripcionTipos(tipos,tam_t,p.idTipo, descTipo) && cargarDescripcionCliente(clientes,tam_cl,p.idCliente, descCliente))
    {
        printf("  %d  %10s  %10s   %10s   %.2f   %10s\n", p.id, p.modelo, descMarca, descTipo, p.precio, descCliente);
    }
}

int mostrarNotebooks(eNotebook notebooks[], int tam_n, eMarca marcas[], int tam_m, eTipo tipos[], int tam_t, eCliente clientes[], int tam_cl)
{
    int todoOk = 0;
    int flag = 1;
    if(notebooks != NULL && tam_n > 0)
    {
        system("cls");
        printf(" | ********* Lista de Notebooks ********* |\n");
        printf("--------------------------------------------------------------------\n");
        printf("   Id          Modelo     Marca      Tipo      Precio       NombreCl\n");
        printf("---------------------------------------------------------------------\n");
        for(int i = 0; i< tam_n; i++)
        {
            if(!notebooks[i].isEmpty)
            {
                mostrarNotebook(notebooks[i], marcas, tam_m, tipos, tam_t, clientes, tam_cl);
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

int modificarNotebook(eNotebook notebooks[], int tam_n, eMarca marcas[], int tam_m, eTipo tipos[], int tam_t, eCliente clientes[], int tam_cl)
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
        mostrarNotebooks(notebooks,tam_n, marcas, tam_n, tipos, tam_t, clientes, tam_cl);
        /*printf("Ingrese id: ");
        scanf("%d", &id);*/
        id = getInt("\n Ingrese id: ");
        indice = buscarNotebookId(notebooks, tam_n, id);
        if (indice == -1)
        {
            printf("El ID %d no se encuentra en el sistema \n", id);
        }
        else
        {
            mostrarNotebook(notebooks[indice], marcas, tam_m, tipos, tam_t, clientes, tam_cl);

            printf("Confirma modificacion?: ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                switch(menuModificacion())
                {
                case 1:
                    /*printf("Ingrese nuevo precio:");
                    scanf("%f", &auxPrecio);*/
                    auxPrecio = getFloat("Ingrese precio: ");
                    notebooks[indice].precio = auxPrecio;
                    break;
                case 2:

                    mostrarTipos(tipos, tam_t);

                    /*printf("Ingrese Nuevo ID Tipo: ");
                    scanf("%d", &auxTipo);*/
                    auxTipo = getInt("\n Ingrese nuevo ID Tipo: ");
                    while(!validarIdTipo(tipos, auxTipo, tam_t))
                    {
                        /*printf("Error.. Reingrese ID Tipo: ");
                        scanf("%d", &auxTipo);*/
                        auxTipo = getInt("\n Ingrese nuevo ID Tipo: ");
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

int bajaNotebook(eNotebook notebooks[], int tam_n, eMarca marcas[], int tam_m, eTipo tipos[], int tam_t, eCliente clientes[], int tam_cl)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;
    if(notebooks != NULL && tam_n > 0)
    {
        system("cls");
        printf("        *** Baja Notebook *** \n\n");
        mostrarNotebooks(notebooks,tam_n, marcas, tam_m, tipos, tam_t, clientes, tam_cl);
        /*printf("Ingrese id notebook: ");
        scanf("%d", &id);*/
        id = getInt("\n Ingrese id Notebook: ");
        indice = buscarNotebookId(notebooks, tam_n, id);
        if (indice == -1)
        {
            printf("El ID %d no se encuentra en el sistema \n", id);
        }
        else
        {
            mostrarNotebook(notebooks[indice], marcas,tam_m,tipos,tam_t, clientes, tam_cl);
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
            //printf("Aca entro %s  %d\n" , descMarcai , notebooks[i].idMarca);
            for(int j= i+1; j< tam_n; j++)
            {
                char descMarcaj[20];
                cargarDescripcionMarca(marcas, tam_m, notebooks[j].idMarca, descMarcaj);
                //printf("Aca entro %s  %d\n" , descMarcaj , notebooks[j].idMarca);
                if((notebooks[i].precio < notebooks[j].precio) || (notebooks[j].precio == notebooks[j].precio && strcmp(descMarcai, descMarcaj) >0 ))
                {
                  //  printf("entra al if");
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

int cargarModeloNotebook(eNotebook notebooks[], int tam_n, int idNotebook, char modelo[])
{ // devuelve 0 si no encontro nada, 1 si se valido o -1 si salio todo mal
    int todoOk = 0;
    int flag = 1;
    if(notebooks != NULL && tam_n > 0 && modelo != NULL){
        for(int i = 0; i<tam_n; i++){
            //printf("%d %d \n" notebooks[i].id , idNotebook);
            if(notebooks[i].id == idNotebook){
                todoOk = 1;
                strcpy(modelo,notebooks[i].modelo);
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
// mostrar notebooks de la marca seleccionado por el usuario
int informarMarcaSeleccionadaByUser(eNotebook notebooks[], int tam_n, eMarca marcas[], int tam_m, eTipo tipos[], int tam_t, eCliente clientes[], int tam_cl){
    int todoOk = 0;
    int idMarca;
    // ePersona auxPersona;
    if(notebooks != NULL && tam_n > 0 && marcas != NULL && tam_m > 0)
    {
        system("cls");
        printf(" | ********* Mostrar Notebboks de una marca ********* |\n");

        mostrarMarcas(marcas,tam_m);
        idMarca = getInt("\n Ingrese ID Marca: ");
        while(!validarIdMarca(marcas,idMarca, tam_m))
        {
            idMarca = getInt("\n Error.. ReIngrese ID Marca: ");
        }
        /*for(int i = 0; i<tam; i++){
            if(lista[i].idLocalidad == idLocalidad){
                mostrarPersona(lista[i], localidades, tamLoc);
            }
        }*/

        mostrarNotebooksIdMarca(notebooks, tam_n, marcas, tam_m, tipos, tam_t, clientes, tam_cl, idMarca);
        todoOk = 1;
    }

    return todoOk;
}

int mostrarNotebooksIdMarca(eNotebook notebooks[], int tam_n, eMarca marcas[], int tam_m, eTipo tipos[], int tam_t, eCliente clientes[], int tam_cl, int idMarca){
    int todoOk = 0;
    int flag = 1;
    char descMarca[20];
    if(notebooks != NULL && tam_n > 0 && marcas != NULL && tam_m > 0 && validarIdMarca(marcas, idMarca, tam_m))
    {
        printf("--------------------------------------------------------------------\n");
        printf("   Id          Modelo     Marca      Tipo      Precio       NombreCl\n");
        printf("---------------------------------------------------------------------\n");
        for(int i = 0; i<tam_n; i++)
        {
            if( !notebooks[i].isEmpty && notebooks[i].idMarca == idMarca)
            {
                mostrarNotebook(notebooks[i], marcas, tam_m, tipos, tam_t, clientes,tam_cl);
                flag = 0;
            }
        }
        if(flag)
        {
            cargarDescripcionMarca(marcas,tam_m, idMarca, descMarca);
            printf("No hay Notebooks en %s\n", descMarca);
        }
        todoOk = 1;
    }
    return todoOk;
}

int informarTipoSeleccionadaByUser(eNotebook notebooks[], int tam_n, eMarca marcas[], int tam_m, eTipo tipos[], int tam_t, eCliente clientes[], int tam_cl){
    int todoOk = 0;
    int idTipo;
    // ePersona auxPersona;
    if(notebooks != NULL && tam_n > 0 && tipos != NULL && tam_m > 0)
    {
        system("cls");
        printf(" | ********* Mostrar Notebooks de un Tipo********* |\n");

        mostrarTipos(tipos,tam_t);
        idTipo = getInt("\n Ingrese ID Tipo: ");
        while(!validarIdTipo(tipos,idTipo, tam_t))
        {
            idTipo = getInt("\n Error.. ReIngrese ID Tipo: ");
        }
        /*for(int i = 0; i<tam; i++){
            if(lista[i].idLocalidad == idLocalidad){
                mostrarPersona(lista[i], localidades, tamLoc);
            }
        }*/

        mostrarNotebooksIdTipo(notebooks, tam_n, marcas, tam_m, tipos, tam_t, clientes, tam_cl, idTipo);
        todoOk = 1;
    }

    return todoOk;
}

int mostrarNotebooksIdTipo(eNotebook notebooks[], int tam_n, eMarca marcas[], int tam_m, eTipo tipos[], int tam_t, eCliente clientes[], int tam_cl, int idTipo){
    int todoOk = 0;
    int flag = 1;
    char descTipo[20];
    if(notebooks != NULL && tam_n > 0 && tipos != NULL && tam_t > 0 && validarIdTipo(tipos, idTipo, tam_t))
    {
        printf("--------------------------------------------------------------------\n");
        printf("   Id          Modelo     Marca      Tipo      Precio       NombreCl\n");
        printf("---------------------------------------------------------------------\n");
        for(int i = 0; i<tam_n; i++)
        {
            if( !notebooks[i].isEmpty && notebooks[i].idTipo == idTipo)
            {
                mostrarNotebook(notebooks[i], marcas, tam_m, tipos, tam_t, clientes,tam_cl);
                flag = 0;
            }
        }
        if(flag)
        {
            cargarDescripcionTipos(tipos,tam_t, idTipo, descTipo);
            printf("No hay Notebooks en %s\n", descTipo);
        }
        todoOk = 1;
    }
    return todoOk;
}

// 3- informar la o las notebooks de menor precio
int notebookMenorPrecio(eNotebook notebooks[], int tam_n, eMarca marcas[], int tam_m, eTipo tipos[], int tam_t, eCliente clientes[], int tam_cl)
{
    int todoOk = 0;
    int flag = 1;
    int flagPrecio = 0;
    float menorPrecio = 0;
//int idPersonaMayorEdad;
    if(notebooks != NULL && tam_n > 0)
    {
        system("cls");
        printf(" | ********* Notebook de menor precio ********* |\n");
        printf("---------------------------------------------------------\n");
        for(int i = 0; i< tam_n; i++)
        {
            if(notebooks[i].isEmpty == 0)
            {
                if(!flagPrecio || menorPrecio > notebooks[i].precio)
                {
                    menorPrecio = notebooks[i].precio;
                    //idPersonaMayorEdad = lista[i].id;
                    flagPrecio = 1;
                }
                flag = 0;
            }
        }
        if(flag)
        {
            printf("No hay Varones para mostrar\n");
        }
        else{
            printf("--------------------------------------------------------------------\n");
            printf("   Id          Modelo     Marca      Tipo      Precio       NombreCl\n");
            printf("---------------------------------------------------------------------\n");
            for(int i=0; i<tam_n; i++)
            {
                if(notebooks[i].isEmpty == 0 && notebooks[i].precio == menorPrecio)
                {
                    mostrarNotebook(notebooks[i], marcas, tam_m, tipos, tam_t, clientes,tam_cl);
                //printf("El nombre del varon con mas edad es: %s \n", lista[i].nombre);
                }
            }
        }
        printf("\n\n");
        todoOk = 1;
    }
    return todoOk;
}

int mostrarNotebooksAllMarcas(eNotebook notebooks[], int tam_n, eMarca marcas[], int tam_m, eTipo tipos[], int tam_t, eCliente clientes[], int tam_cl)
{
    int todoOk = 0;
    //int flag = 1;
    //char descLocalidad[20];
    if(notebooks != NULL && tam_n > 0 && marcas != NULL && tam_m > 0/* && verificarLocalidad(localidades, idLoca, tam)*/)
    {
        system("cls");
        printf("\n\n---------------------------------------------------------\n");
        printf(" Mostrar Notebooks por Marca \n");
        printf("---------------------------------------------------------\n");
        for(int i = 0; i<tam_m; i++)
        {
            //if( !lista[i].isEmpty && lista[i].idLocalidad == idLoca){
            //cargarDescripcionLocalidad(localidades,tamLoc, localidades[i].id, descLocalidad);
            printf("- Marca: %10s \n", marcas[i].descripcion);
            mostrarNotebooksIdMarca(notebooks,tam_n,marcas,tam_m,tipos,tam_t,clientes,tam_cl, marcas[i].id);
            printf("\n -------------------------------------------------------- \n");
            //flag = 0;
        }
        /* if(flag){
             cargarDescripcionLocalidad(localidades,tamLoc, idLoca, descLocalidad);
             printf("No hay personas en %s\n" , descLocalidad);
         }*/
        todoOk = 1;
    }

    return todoOk;
}

int informeCantidadNotebooksMarcaTipo(eNotebook notebooks[], int tam_n, eMarca marcas[], int tam_m, eTipo tipos[], int tam_t)
{
    int todoOk = 0;
    char descTipo[20];
    char descMarca[20];
    int idMarcaIng;
    int idTipoIng;
    //int flag = 1;
    //char descLocalidad[20];
    if(notebooks != NULL && tam_n > 0 && marcas != NULL && tam_m > 0/* && verificarLocalidad(localidades, idLoca, tam)*/)
    {
        system("cls");
        printf("\n\n---------------------------------------------------------\n");
        printf(" Informe cantidad de Notebooks por Marca y Tipo \n");
        printf("---------------------------------------------------------\n");

        mostrarMarcas(marcas,tam_m);
        idMarcaIng = getInt("\n Ingrese ID Marca: ");
        while(!validarIdMarca(marcas,idMarcaIng, tam_m))
        {
            idMarcaIng = getInt("\n Error.. ReIngrese ID Marca: ");
        }

        mostrarTipos(tipos,tam_t);
        idTipoIng = getInt("\n Ingrese ID Tipo: ");
        while(!validarIdTipo(tipos,idTipoIng, tam_t))
        {
            idTipoIng = getInt("\n Error.. ReIngrese ID Tipo: ");
        }

            int cont = 0;
            for(int i=0; i<tam_n; i++)
            {
                if(!notebooks[i].isEmpty && idMarcaIng == notebooks[i].idMarca && idTipoIng == notebooks[i].idTipo)
                {
                    cont ++;
                }
            }

            cargarDescripcionTipos(tipos,tam_t, idTipoIng, descTipo);
            cargarDescripcionMarca(marcas,tam_m, idMarcaIng, descMarca);
            printf("- Marca: %10s Tipo: %10s [%d]\n", descMarca, descTipo, cont);

            printf("\n -------------------------------------------------------- \n");

        todoOk = 1;
    }

    return todoOk;
}

int marcaMasElegida(eNotebook notebooks[], int tam_n, eMarca marcas[], int tam_m)
{
    int todoOk = 0;
    //int flag = 1;
    //char descLocalidad[20];
    int contadores[] = {0, 0,0,0,0};
    int maximo;
    if(notebooks != NULL && tam_n > 0 && marcas != NULL && tam_m > 0)
    {
        {
            system("cls");
            printf("\n\n---------------------------------------------------------\n");
            printf(" Marca Mas Elegida\n");
            printf("---------------------------------------------------------\n");
            for(int i = 0; i<tam_m; i++)
            {
                for(int j=0; j<tam_n; j++)
                {
                    if(!notebooks[j].isEmpty && marcas[i].id == notebooks[j].idMarca)
                    {
                        contadores[i]++;
                    }
                }
            }

            for(int i = 0; i<tam_m; i++)
            {
                if(i == 0 || contadores[i]> maximo)
                {
                    maximo = contadores[i];
                }
            }
            // ya conozco la cantidad minima de habitantes

            for(int i = 0; i<tam_m; i++)
            {
                if(contadores[i] == maximo)
                {
                    printf("%s \n", marcas[i].descripcion);
                }
            }
            todoOk = 1;
        }
    }
    return todoOk;
}

int validarIdNotebook(eNotebook notebooks[], int idIng, int tam_n){
    int todoOk = 0;
    if(notebooks != NULL && tam_n > 0){
        for(int i = 0; i < tam_n; i++)
        {
            if(idIng == notebooks[i].id)
            {
                todoOk = 1;
                break;
            }
        }
    }
    return todoOk;
}
