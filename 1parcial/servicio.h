#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct{
    int id;
    char descripcion[20];
    float precio;
}eServicio;

#endif // SERVICIO_H_INCLUDED

int mostrarServicios(eServicio servicios[], int tam_s);
int validarIdServicio(eServicio servicios[], int idIng, int tam_s);
int cargarDescripcionServicio(eServicio servicios[], int tam_s, int idMarca, char descripcion[]);
