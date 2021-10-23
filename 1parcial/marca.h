#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED

typedef struct{
    int id;
    char descripcion[20];
}eMarca;

#endif // MARCA_H_INCLUDED

int mostrarMarcas(eMarca marcas[], int tam_m);
int validarIdMarca(eMarca marcas[], int idIng, int tam_m);
int cargarDescripcionMarca(eMarca marcas[], int tam_m, int idMarca, char descripcion[]);
