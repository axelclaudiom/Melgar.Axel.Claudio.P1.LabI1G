#include "fecha.h"
#include "notebook.h"
#include "servicio.h"
#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct{
    int id;
    int idNotebook;
    int idServicio;
    int isEmpty;
    eFecha fecha;
}eTrabajo;

#endif // TRABAJO_H_INCLUDED


int altaTrabajo(eTrabajo trabajos[], int tam_tt , eNotebook notebooks[], int tam_n, eMarca marcas[], int tam_m, eTipo tipos[], int tam_t , eServicio servicios[], int tam_s, int* pId);
int buscarLibreT(eTrabajo trabajos[], int tam_tt);
