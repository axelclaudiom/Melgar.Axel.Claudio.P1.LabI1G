#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct{
    int id;
    char descripcion[20];
}eTipo;

#endif // TIPO_H_INCLUDED

int mostrarTipos(eTipo tipos[], int tam_t);
int validarIdTipo(eTipo tipos[], int idIng, int tam_t);
int cargarDescripcionTipos(eTipo tipos[], int tam_t, int idTipo, char descripcion[]);
