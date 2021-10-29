#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct{
    int id;
    char descripcion[20];
}eTipo;

#endif // TIPO_H_INCLUDED

/** \brief hace un listado de tipos
 *
 * \param tipos[] eTipo vector de tipos
 * \param tam_t int tamaño del vector de tipos
 * \return int 0 si ocurrio un problema o 1 si esta todo ok
 *
 */
int mostrarTipos(eTipo tipos[], int tam_t);

/** \brief valida un id ingresado por el usuario
 *
 * \param tipos[] eTipo vector de tipos
 * \param idIng int id ingresado por el usuario
 * \param tam_t int tamaño del vector de tipos
 * \return int retorna 1 si existe o 0 si ocurrio un problema
 *
 */
int validarIdTipo(eTipo tipos[], int idIng, int tam_t);

/** \brief Carga la descripcion de un tipo ingresado por id
 *
 * \param tipos[] eTipo vector de tipos
 * \param tam_t int tamaño del vector de tipos
 * \param idTipo int id de tipo ingresado por el usuario
 * \param descripcion[] char puntero donde retorna la descripcion del id ingresado por el user
 * \return int 0 si ocurrio un problema o 1 si esta todo ok
 *
 */
int cargarDescripcionTipos(eTipo tipos[], int tam_t, int idTipo, char descripcion[]);
