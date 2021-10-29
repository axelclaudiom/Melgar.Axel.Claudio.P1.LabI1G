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


/** \brief Da de alta un trabajo
 *
 * \param trabajos[] eTrabajo vector de trabajos
 * \param tam_tt int tama�o del vector de trabajos
 * \param notebooks[] eNotebook vector de notebooks
 * \param tam_n int tama�o del vector de notebooks
 * \param marcas[] eMarca vector de marcas
 * \param tam_m int tama�o del vector de marcas
 * \param tipos[] eTipo vector de tipos
 * \param tam_t int tama�o del vector de tipos
 * \param servicios[] eServicio vector de servicios
 * \param tam_s int tama�o del vector de servicios
 * \param pId int* puntero con el valor del proximo id disponible
 * \return int retorna 0 si ocurrio un problema o 1 si est� todo ok.
 *
 */
int altaTrabajo(eTrabajo trabajos[], int tam_tt , eNotebook notebooks[], int tam_n, eMarca marcas[], int tam_m, eTipo tipos[], int tam_t , eServicio servicios[], int tam_s, int* pId);

/** \brief busca la posicion en la que el campo isEmpty se encuentra en 1 y la retorna
 *
 * \param trabajos[] eTrabajo vector de trabajos
 * \param tam_tt int tama�o del vector de trabajos
 * \return int retorna el lugar disponible o 0 si ocurrio un problema
 *
 */
int buscarLibreT(eTrabajo trabajos[], int tam_tt);

/** \brief Muestra un trabajo especifico por id
 *
 * \param unTrabajo eTrabajo ubicacion del trabajo especifico
 * \param notebooks[] eNotebook vector de notebooks
 * \param tam_n int tama�o del vector de notebooks
 * \param servicios[] eServicio vector de servicios
 * \param tam_s int tama�o del vector de servicios
 * \return void
 *
 */
void mostrarTrabajo(eTrabajo unTrabajo, eNotebook notebooks[], int tam_n, eServicio servicios[], int tam_s);

/** \brief Se encarga de hacer un listado de trabajos disponibles
 *
 * \param trabajos[] eTrabajo vector de trabajos
 * \param tam_tt int tama�o del vector de trabajos
 * \param notebooks[] eNotebook vector de notebooks
 * \param tam_n int tama�o del vector de notebooks
 * \param servicios[] eServicio vector de servicios
 * \param tam_s int tama�o del vector de servicios
 * \return int retorna 1 si salio todo ok o 0 si ocurrio un problema
 *
 */
int mostrarTrabajos(eTrabajo trabajos[], int tam_tt, eNotebook notebooks[], int tam_n, eServicio servicios[], int tam_s);

/** \brief Se encarga de inicializar el campo isEmpty del vector trabajos en 1
 *
 * \param trabajos[] eTrabajo vector de  trabajos
 * \param tam_tt int tama�o del vector de trabajos
 * \return int 0 si ocurrio un problema o 1 si salio todo ok
 *
 */
int inicializarTrabajos(eTrabajo trabajos[], int tam_tt);
