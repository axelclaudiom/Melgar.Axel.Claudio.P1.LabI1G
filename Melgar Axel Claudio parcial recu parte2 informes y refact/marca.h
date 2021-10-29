#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED

typedef struct{
    int id;
    char descripcion[20];
}eMarca;

#endif // MARCA_H_INCLUDED

/** \brief  Muestra/Lista las marcas
 *
 * \param marcas[] eMarca vector a marcas
 * \param tam_m int tamaño del vector de marcas
 * \return int 1 si esta todo bien 0 si ocurrio un error
 *
 */
int mostrarMarcas(eMarca marcas[], int tam_m);

/** \brief Valida una marca por id
 *
 * \param marcas[] eMarca Vector a marcas
 * \param idIng int id a validar ingresado por el usuario
 * \param tam_m int tamaño del vector de marcas
 * \return int retorna 1 si esta todo bien o 0 si ocurrio un error
 *
 */
int validarIdMarca(eMarca marcas[], int idIng, int tam_m);

/** \brief Carga la descripcion de una marca
 *
 * \param marcas[] eMarca vector a marcas
 * \param tam_m int tamaño del vector de marcas
 * \param idMarca int id de marca ingreasado por el usuario
 * \param descripcion[] char descripcion  de merca
 * \return int  retorna 1 si esta todo bien o 0 si ocurrio un error
 *
 */
int cargarDescripcionMarca(eMarca marcas[], int tam_m, int idMarca, char descripcion[]);
