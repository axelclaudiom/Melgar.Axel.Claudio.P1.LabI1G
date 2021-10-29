#include <string.h>
#include "dataharc.h"

char modelo[5][20] = {
    "mod1",
    "mod2",
    "mod3",
    "mod4",
    "mod5"
};


int marcas[5] = {1001,1002,1001,1003,1002};

int tipos[5] = {5000,5001,5000,5003,5002};

float precios[5] = {3000,7000,2000,5000,3000};

int clientes[5] = {30000, 30001, 30002,30000,30001};

int hardcodearNotebooks(eNotebook notebooks[], int tam_n, int cant, int* pId)
{
    int contador = -1;
    if( notebooks != NULL && tam_n >0 && cant >= 0 && cant <= tam_n && pId != NULL){
        contador = 0;
        for(int i=0; i< cant; i++){
                notebooks[i].id = *pId;
                (*pId)++;
                strcpy(notebooks[i].modelo, modelo[i]);
                notebooks[i].idMarca = marcas[i];
                notebooks[i].idTipo=tipos[i];
                notebooks[i].idCliente=clientes[i];
                notebooks[i].precio=precios[i];
                notebooks[i].isEmpty = 0;
                contador++;
        }
    }
    return contador;
}


int notebooks[5] = {50000, 50002,50000,50001,50003};
int servicios[5] = {20000,20001,20003,20000,20004};
int fechadia[5] = {8,5,3,4,9};
int fechames[5] = {4,1,7,5,7};
int fechaanio[5] = {2001,2003,2006,2010,2015};


int hardcodearTrabajos(eTrabajo trabajos[], int tam_tt, int cant, int* pId)
{
    int contador = -1;
    if( trabajos != NULL && tam_tt >0 && cant >= 0 && cant <= tam_tt && pId != NULL){
        contador = 0;
        for(int i=0; i< cant; i++){
                trabajos[i].id = *pId;
                (*pId)++;
                trabajos[i].idNotebook = notebooks[i];
                trabajos[i].idServicio=servicios[i];
                trabajos[i].fecha.dia=fechadia[i];
                trabajos[i].fecha.mes=fechames[i];
                trabajos[i].fecha.anio=fechaanio[i];
                trabajos[i].isEmpty = 0;
                contador++;
        }
    }
    return contador;
}
