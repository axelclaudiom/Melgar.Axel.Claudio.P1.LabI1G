#include "fecha.h"
#include "servicio.h"
#include "notebook.h"
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


/** \brief Da de alta un trabajo
 *
 * \param trabajos[] eTrabajo vector de trabajos
 * \param tam_tt int tamaño del vector de trabajos
 * \param notebooks[] eNotebook vector de notebooks
 * \param tam_n int tamaño del vector de notebooks
 * \param marcas[] eMarca vector de marcas
 * \param tam_m int tamaño del vector de marcas
 * \param tipos[] eTipo vector de tipos
 * \param tam_t int tamaño del vector de tipos
 * \param servicios[] eServicio vector de servicios
 * \param tam_s int tamaño del vector de servicios
 * \param pId int* puntero con el valor del proximo id disponible
 * \return int retorna 0 si ocurrio un problema o 1 si está todo ok.
 *
 */
int altaTrabajo(eTrabajo trabajos[], int tam_tt , eNotebook notebooks[], int tam_n, eMarca marcas[], int tam_m, eTipo tipos[], int tam_t , eServicio servicios[], int tam_s, eCliente clientes[], int tam_cl, int* pId);

/** \brief busca la posicion en la que el campo isEmpty se encuentra en 1 y la retorna
 *
 * \param trabajos[] eTrabajo vector de trabajos
 * \param tam_tt int tamaño del vector de trabajos
 * \return int retorna el lugar disponible o 0 si ocurrio un problema
 *
 */
int buscarLibreT(eTrabajo trabajos[], int tam_tt);

/** \brief Muestra un trabajo especifico por id
 *
 * \param unTrabajo eTrabajo ubicacion del trabajo especifico
 * \param notebooks[] eNotebook vector de notebooks
 * \param tam_n int tamaño del vector de notebooks
 * \param servicios[] eServicio vector de servicios
 * \param tam_s int tamaño del vector de servicios
 * \return void
 *
 */
void mostrarTrabajo(eTrabajo unTrabajo, eNotebook notebooks[], int tam_n, eServicio servicios[], int tam_s);

/** \brief Se encarga de hacer un listado de trabajos disponibles
 *
 * \param trabajos[] eTrabajo vector de trabajos
 * \param tam_tt int tamaño del vector de trabajos
 * \param notebooks[] eNotebook vector de notebooks
 * \param tam_n int tamaño del vector de notebooks
 * \param servicios[] eServicio vector de servicios
 * \param tam_s int tamaño del vector de servicios
 * \return int retorna 1 si salio todo ok o 0 si ocurrio un problema
 *
 */
int mostrarTrabajos(eTrabajo trabajos[], int tam_tt, eNotebook notebooks[], int tam_n, eServicio servicios[], int tam_s);

/** \brief Se encarga de inicializar el campo isEmpty del vector trabajos en 1
 *
 * \param trabajos[] eTrabajo vector de  trabajos
 * \param tam_tt int tamaño del vector de trabajos
 * \return int 0 si ocurrio un problema o 1 si salio todo ok
 *
 */
int inicializarTrabajos(eTrabajo trabajos[], int tam_tt);

 /** \brief muestra los trabajos realizados a una notebook por id
 *
 * \param notebooks[] eNotebook vector de notebooks
 * \param tam_n int tamaño del vector de notebooks
 * \param marcas[] eMarca vector de marca
 * \param tam_m int tamaño del vector de marcas
 * \param tipos[] eTipo vector de tipos
 * \param tam_t int tamaño del vector de tipos
 * \param clientes[] eCliente vector de clientes
 * \param tam_cl int tamaño del vector de clientes
 * \param trabajos[] eTrabajo vector de trabajos
 * \param tam_tt int tamaño del vector de trabajos
 * \param servicios[] eServicio vector de servicios
 * \param tam_s int tamaño del vector de servicios
 * \param idNotebook int id de notebook ingresado por el usuario
 * \return int retorna 1 si salio todo ok o 0 si ocurrio un inconveniente
 *
 */
int mostrarTrabajosIdNotebook(eNotebook notebooks[], int tam_n, eMarca marcas[], int tam_m, eTipo tipos[], int tam_t, eCliente clientes[], int tam_cl, eTrabajo trabajos[], int tam_tt, eServicio servicios[], int tam_s, int idNotebook);



/** \brief Se encarga de pedir el id de una notebook y mostrar los trabajos que se le hicieron a la misma
 *
 * \param notebooks[] eNotebook vector de notebooks
 * \param tam_n int tamaño del vector de notebooks
 * \param marcas[] eMarca vector de marca
 * \param tam_m int tamaño del vector de marcas
 * \param tipos[] eTipo vector de tipos
 * \param tam_t int tamaño del vector de tipos
 * \param clientes[] eCliente vector de clientes
 * \param tam_cl int tamaño del vector de clientes
 * \param trabajos[] eTrabajo vector de trabajos
 * \param tam_tt int tamaño del vector de trabajos
 * \param servicios[] eServicio vector de servicios
 * \param tam_s int tamaño del vector de servicios
 * \return int retorna 1 si salio todo ok o 0 si ocurrio un inconveniente
 *
 */
int mostrarTrabajosNotebook(eNotebook notebooks[], int tam_n, eMarca marcas[], int tam_m, eTipo tipos[], int tam_t, eCliente clientes[], int tam_cl, eTrabajo trabajos[], int tam_tt, eServicio servicios[], int tam_s);

/** \brief Se encarga de pedir una notebook e informar la suma de los importes de los servicios que se le hicieron a la misma
 *
 * \param notebooks[] eNotebook vector de notebooks
 * \param tam_n int tamaño del vector de notebooks
 * \param marcas[] eMarca vector de marca
 * \param tam_m int tamaño del vector de marcas
 * \param tipos[] eTipo vector de tipos
 * \param tam_t int tamaño del vector de tipos
 * \param clientes[] eCliente vector de clientes
 * \param tam_cl int tamaño del vector de clientes
 * \param trabajos[] eTrabajo vector de trabajos
 * \param tam_tt int tamaño del vector de trabajos
 * \param servicios[] eServicio vector de servicios
 * \param tam_s int tamaño del vector de servicios
 * \return int retorna 1 si salio todo ok o 0 si ocurrio un inconveniente
 *
 */
int mostrarImporteServiciosNotebook(eNotebook notebooks[], int tam_n, eMarca marcas[], int tam_m, eTipo tipos[], int tam_t, eCliente clientes[], int tam_cl, eTrabajo trabajos[], int tam_tt, eServicio servicios[], int tam_s);

/** \brief se Encarga de sumar el importe de los servicios de una id
 *
 * \param notebooks[] eNotebook Vector de notebooks
 * \param tam_n int tamaño del vector de notebooks
 * \param trabajos[] eTrabajo vector de trabajo
 * \param tam_t int tamaño del vector de trabajo
 * \param servicios[] eServicio vector de servicios
 * \param tam_s int tamaño del vector de servicios
 * \param idNotebook int id ingresado
 * \return int retorna 1 si salio todo ok o 0 si ocurrio un inconveniente
 *
 */
int mostrarSumaServiciosIdNotebook(eNotebook notebooks[], int tam_n, eTrabajo trabajos[], int tam_t, eServicio servicios[], int tam_s, int idNotebook);

/** \brief Muestra los servicios realizados a una notebook por id
 *
 * \param notebooks[] eNotebook vector de notebooks
 * \param tam_n int tamaño del vector de notebooks
 * \param marcas[] eMarca vector de marca
 * \param tam_m int tamaño del vector de marcas
 * \param tipos[] eTipo vector de tipos
 * \param tam_t int tamaño del vector de tipos
 * \param clientes[] eCliente vector de clientes
 * \param tam_cl int tamaño del vector de clientes
 * \param trabajos[] eTrabajo vector de trabajos
 * \param tam_tt int tamaño del vector de trabajos
 * \param servicios[] eServicio vector de servicios
 * \param tam_s int tamaño del vector de servicios
 * \return int retorna 1 si salio todo ok o 0 si ocurrio un inconveniente
 *
 */
int mostrarServiciosRealizadosNotebook(eNotebook notebooks[], int tam_n, eMarca marcas[], int tam_m, eTipo tipos[], int tam_t, eCliente clientes[], int tam_cl, eTrabajo trabajos[], int tam_tt, eServicio servicios[], int tam_s);

/** \brief Pide al usuario un servicio y muestra las notebooks a las que se les realizo ese servicio
 *
 * \param notebooks[] eNotebook vector de notebooks
 * \param tam_n int tamaño del vector de notebooks
 * \param trabajos[] eTrabajo vector de trabajos
 * \param tam_tt int tamaño del vector de trabajos
 * \param servicios[] eServicio vector de servicios
 * \param tam_s int tamaño del vector de servicios
 * \param idServicio int id ingresado
 * \return int retorna 1 si salio todo ok o 0 si ocurrio un inconveniente
 *
 */
int mostrarServiciosRealizadosIdNotebook(eNotebook notebooks[], int tam_n, eTrabajo trabajos[], int tam_tt, eServicio servicios[], int tam_s, int idServicio);

/** \brief Se encarga de pedirle al usuario un fecha y mostrar los servicios realizados en esa fecha
 *
 * \param notebooks[] eNotebook vector de notebooks
 * \param tam_n int tamaño del vector de notebooks
 * \param marcas[] eMarca vector de marca
 * \param tam_m int tamaño del vector de marcas
 * \param tipos[] eTipo vector de tipos
 * \param tam_t int tamaño del vector de tipos
 * \param clientes[] eCliente vector de clientes
 * \param tam_cl int tamaño del vector de clientes
 * \param trabajos[] eTrabajo vector de trabajos
 * \param tam_tt int tamaño del vector de trabajos
 * \param servicios[] eServicio vector de servicios
 * \param tam_s int tamaño del vector de servicios
 * \return int retorna 1 si salio todo ok o 0 si ocurrio un inconveniente
 * \return int
 *
 */
int mostrarServiciosRealizadosFecha(eNotebook notebooks[], int tam_n, eMarca marcas[], int tam_m, eTipo tipos[], int tam_t, eCliente clientes[], int tam_cl, eTrabajo trabajos[], int tam_tt, eServicio servicios[], int tam_s);

/** \brief muestra los servicios realizados en una fecha determinada
 *
 * \param notebooks[] eNotebook Vector de notebooks
 * \param tam_n int tamaño del vector de notebooks
 * \param trabajos[] eTrabajo vector de trabajos
 * \param tam_tt int tamaño del vector de trabajos
 * \param servicios[] eServicio vector de servicios
 * \param tam_s int tamaño del vector de servicios
 * \param diaIng int dia ingresado
 * \param mesIng int mes ingresado
 * \param anioIng int anio ingresado
 * \return int retorna 1 si salio todo ok o 0 si ocurrio un inconveniente
 *
 */
int mostrarServiciosRealizadosFechaAux(eNotebook notebooks[], int tam_n, eTrabajo trabajos[], int tam_tt, eServicio servicios[], int tam_s, int diaIng, int mesIng, int anioIng);
