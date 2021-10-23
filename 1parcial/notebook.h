#include "marca.h"
#include "tipo.h"

#ifndef NOTEBOOK_H_INCLUDED
#define NOTEBOOK_H_INCLUDED

typedef struct{
    int id;
    char modelo[20];
    int idMarca;
    int idTipo;
    float precio;
    int isEmpty; // 1 esta vacio, 0 esta lleno
}eNotebook;


#endif // NOTEBOOK_H_INCLUDED

int menu();
int inicializarNotebooks(eNotebook notebooks[], int tam_n);
int buscarLibre(eNotebook notebooks[], int tam_n);
int altaNotebook(eNotebook notebooks[], int tam_n, eMarca marcas[], int tam_m, eTipo tipos[], int tam_t ,int* pId);
void mostrarNotebook(eNotebook p, eMarca marcas[], int tam_m, eTipo tipos[], int tam_t);
int mostrarNotebooks(eNotebook notebooks[], int tam_n, eMarca marcas[], int tam_m, eTipo tipos[], int tam_t);
int buscarNotebookId(eNotebook notebooks[], int tam_n, int id);
int modificarNotebook(eNotebook notebooks[], int tam_n, eMarca marcas[], int tam_m, eTipo tipos[], int tam_t);
int menuModificacion();
int bajaNotebook(eNotebook notebooks[], int tam_n, eMarca marcas[], int tam_m, eTipo tipos[], int tam_t);
int ordenarNotebooks(eNotebook notebooks[], int tam_n, eMarca marcas[], int tam_m);
