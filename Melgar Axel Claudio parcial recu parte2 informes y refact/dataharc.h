#include "notebook.h"
#include "trabajo.h"

#ifndef DATAWAREHOUSE_H_INCLUDED
#define DATAWAREHOUSE_H_INCLUDED



#endif // DATAWAREHOUSE_H_INCLUDED

/** \brief Harcodea valores al vector de Notebooks
 *
 * \param notebooks[] eNotebook Vector de notebooks
 * \param tam_n int tamaño del vector de notebooks
 * \param cant int cantidad de parametros a harcodear
 * \param pId int* Puntero id proxima notebook
 * \return int Devuelve la cantidad de parametros que agrego al vector
 *
 */
int hardcodearNotebooks(eNotebook notebooks[], int tam_n, int cant, int* pId);

/** \brief Harcodea valores al vector de Trabajos
 *
 * \param trabajos[] eTrabajo Vector de trabajos
 * \param tam_tt int tamaño del vector de trabajos
 * \param cant int cantidad de parametros a harcodear
 * \param pId int* Puntero id proximo trabajo
 * \return int Devuelve la cantidad de parametros que agrego al vector
 *
 */
int hardcodearTrabajos(eTrabajo trabajos[], int tam_tt, int cant, int* pId);
