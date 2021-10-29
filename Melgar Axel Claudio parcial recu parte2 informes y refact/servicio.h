#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct{
    int id;
    char descripcion[20];
    float precio;
}eServicio;

#endif // SERVICIO_H_INCLUDED

/** \brief hace un listado de servicios
 *
 * \param servicios[] eServicio vector de servicios
 * \param tam_s int tamaño del vector de servicios
 * \return int 0 si ocurrio un problema o 1 si salio todo ok
 *
 */
int mostrarServicios(eServicio servicios[], int tam_s);

/** \brief Valida un servicio por id ingresado
 *
 * \param servicios[] eServicio vector de servicios
 * \param idIng int id ingresado por el usuario
 * \param tam_s int tamaño del vector de servicios
 * \return int 1 si salio todo ok o 0 si ocurrio un problema
 *
 */
int validarIdServicio(eServicio servicios[], int idIng, int tam_s);

/** \brief Carga la descripcion de un servicio
 *
 * \param servicios[] eServicio vector de servicios
 * \param tam_s int tamaño del vector de servicios
 * \param idMarca int id ingresado por el usuario
 * \param descripcion[] char puntero donde se carga la descripcion del servicio
 * \return int 0 si ocurrio un problema o 1 si está todo ok
 *
 */
int cargarDescripcionServicio(eServicio servicios[], int tam_s, int idMarca, char descripcion[]);
