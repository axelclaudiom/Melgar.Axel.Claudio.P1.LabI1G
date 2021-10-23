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
                notebooks[i].precio=precios[i];
                notebooks[i].isEmpty = 0;
                contador++;
        }
    }
    return contador;
}
