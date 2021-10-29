#include "marca.h"
#include "tipo.h"
#include "cliente.h"
//#include "trabajo.h"

#ifndef NOTEBOOK_H_INCLUDED
#define NOTEBOOK_H_INCLUDED



typedef struct{
    int id;
    char modelo[20];
    int idMarca;
    int idTipo;
    int idCliente;
    float precio;
    int isEmpty; // 1 esta vacio, 0 esta lleno
}eNotebook;


#endif // NOTEBOOK_H_INCLUDED

/** \brief Menu de usuario
 *
 * \return int
 *
 */
int menu();

/** \brief Inicializa las notebooks poniendo el campo isEmpty en 1
 *
 * \param notebooks[] eNotebook Vector de notebooks
 * \param tam_n int tamaño del vector de notebooks
 * \return int retorna 1 si salio todo bien o 0 si ocurrio un problema
 *
 */
int inicializarNotebooks(eNotebook notebooks[], int tam_n);

/** \brief Busca la proxima notebook libre usando isEmpty y retorna el id
 *
 * \param notebooks[] eNotebook vector de notebooks
 * \param tam_n int tamaño del vector de notebooks
 * \return int retorna 1 si salio todo bien o 0 si ocurrio un problema
 *
 */
int buscarLibre(eNotebook notebooks[], int tam_n);

/** \brief Pide al usuario los datos necesarios y verifica para poder realizar el alta de un equipo
 *
 * \param notebooks[] eNotebook vector de notebooks
 * \param tam_n int tamaño del vector de notebooks
 * \param marcas[] eMarca vector de marcas
 * \param tam_m int tamaño del vector de marcas
 * \param tipos[] eTipo vector de tipos
 * \param tam_t int tamaño del vector de tipos
 * \param pId int* puntero que indica cual es el siguiente ID
 * \return int retorna 0 si ocurrio un problema o 1 si está todoOk.
 *
 */
int altaNotebook(eNotebook notebooks[], int tam_n, eMarca marcas[], int tam_m, eTipo tipos[], int tam_t, eCliente clientes[], int tam_cl, int* pId);
/** \brief Muestra el detalle de una notebook por id
 *
 * \param p eNotebook ubicacion de la notebooks especifica
 * \param marcas[] eMarca vector de marcas
 * \param tam_m int tamaño del vector de marcas
 * \param tipos[] eTipo vector de tipos
 * \param tam_t int tamaño del vector de tipos
   * \param clientes[] eClientes vector de clientes
 * \param tam_cl int tamaño del vector de clientes
 * \return void
 *
 */
void mostrarNotebook(eNotebook p, eMarca marcas[], int tam_m, eTipo tipos[], int tam_t, eCliente clientes[], int tam_cl);

/** \brief Muestra el listado de notebooks total
 *
 * \param notebooks[] eNotebook vector de notebooks
 * \param tam_n int tamaño del vector de notebooks
 * \param marcas[] eMarca vector de marcas
 * \param tam_m int tamaño del vector de marcas
 * \param tipos[] eTipo vector de tipos
 * \param tam_t int tamaño del vector de tipos
  * \param clientes[] eClientes vector de clientes
 * \param tam_cl int tamaño del vector de clientes
 * \return int 1 si salio todo bien o 0 si ocurrio un problema
 *
 */
int mostrarNotebooks(eNotebook notebooks[], int tam_n, eMarca marcas[], int tam_m, eTipo tipos[], int tam_t, eCliente clientes[], int tam_cl);
/** \brief Busca una notebook por id
 *
 * \param notebooks[] eNotebook vector a notebooks
 * \param tam_n int tamaño del vector de notebooks
 * \param id int id ingresado por el usuario
 * \return int retorna la ubicacion en el vector de esa id o -1 si ocurrio un problema
 *
 */
int buscarNotebookId(eNotebook notebooks[], int tam_n, int id);
/** \brief modificar datos de una notebook
 *
 * \param notebooks[] eNotebook vector de notebooks
 * \param tam_n int tamaño del vector de notebooks
 * \param marcas[] eMarca vector de marcas
 * \param tam_m int tamaño del vector de marcas
 * \param tipos[] eTipo vector de tipos
 * \param tam_t int tamaño del vector de tipos
 * \return int retorna 1 si esta todo bien o 0 si ocurrio un problema
 *
 */
int modificarNotebook(eNotebook notebooks[], int tam_n, eMarca marcas[], int tam_m, eTipo tipos[], int tam_t, eCliente clientes[], int tam_cl);

/** \brief Menu de modificacion
 *
 * \return int
 *
 */
int menuModificacion();

/** \brief Hace una baja logica a una notebook poniendo isEmpty en 1
 *
 * \param notebooks[] eNotebook vector de notebooks
 * \param tam_n int tamaño del vector de notebooks
 * \param marcas[] eMarca vector de marcas
 * \param tam_m int tamaño del vector de marcas
 * \param tipos[] eTipo vector de tipos
 * \param tam_t int tamaño del vector de tipos
 * \return int retorna 1 si salio todo ok o 0 si ocurrio un problema
 *
 */
int bajaNotebook(eNotebook notebooks[], int tam_n, eMarca marcas[], int tam_m, eTipo tipos[], int tam_t, eCliente clientes[], int tam_cl);

/** \brief Ordena las notebooks por tipo y por marca
 *
 * \param notebooks[] eNotebook vector de notebooks
 * \param tam_n int tamaño del vector de notebooks
 * \param marcas[] eMarca vector de marcas
 * \param tam_m int tamaño del vector de marcas
 * \return int retorna 1 si salio todo ok o 0 si ocurrio un problema
 *
 */
int ordenarNotebooks(eNotebook notebooks[], int tam_n, eMarca marcas[], int tam_m);

/** \brief Carga el modelo de una notebook
 *
 * \param notebooks[] eNotebook vector de notebooks
 * \param tam_n int tamaño del vector de notebooks
 * \param idNotebook int id de la notebook
 * \param modelo[] char puntero donde se carga el modelo de la notebook
 * \return int retorna 0 si ocurrio un problema o 1 si esta todo ok
 *
 */
int cargarModeloNotebook(eNotebook notebooks[], int tam_n, int idNotebook, char modelo[]);

/** \brief pide al usuario un marca e Informa las notebooks de la marca seleccionada por el usuario
 *
 * \param notebooks[] eNotebook vector de notebooks
 * \param tam_n int tamaño del vector de notebooks
 * \param marcas[] eMarca vector de marcas
 * \param tam_m int tamaño del vector de marcas
 * \param tipos[] eTipo vector de tipos
 * \param tam_t int tamaño del vector de tipos
 * \param clientes[] eCliente vector de clientes
 * \param tam_cl int tamaño del vector de clientes
 * \return int retorna 1 si esta todo ok o 0 si ocurrio un problema
 *
 */
int informarMarcaSeleccionadaByUser(eNotebook notebooks[], int tam_n, eMarca marcas[], int tam_m, eTipo tipos[], int tam_t, eCliente clientes[], int tam_cl);

/** \brief muestra la informacion de notebooks por id ingresado
 *
 * \param notebooks[] eNotebook vector de notebooks
 * \param tam_n int tamaño del vector de notebooks
 * \param marcas[] eMarca vector de marcas
 * \param tam_m int tamaño del vector de marcas
 * \param tipos[] eTipo vector de tipos
 * \param tam_t int tamaño del vector de  tipos
 * \param clientes[] eCliente vector de clientes
 * \param tam_cl int tamaño del vector de clientes
 * \param idMarca int id ingresado
 * \return int retorna 1 si salio todo ok o 0 si ocurrio un problema
 *
 */
int mostrarNotebooksIdMarca(eNotebook notebooks[], int tam_n, eMarca marcas[], int tam_m, eTipo tipos[], int tam_t, eCliente clientes[], int tam_cl, int idMarca);

/** \brief Pide al usuario un tipo e informa la informacion de las notebooks que tengan ese tipo
 *
 * \param notebooks[] eNotebook vector de notebooks
 * \param tam_n int tamaño del vector de notebooks
 * \param marcas[] eMarca vector de marcas
 * \param tam_m int tamaño del vector de marcas
 * \param tipos[] eTipo vector de tipos
 * \param tam_t int tamaño del vector de tipos
 * \param clientes[] eCliente vector de clientes
 * \param tam_cl int tamaño del vector de clientes
 * \return int retorna 1 si salio todo ok o 0 si ocurrio un inconveniente
 *
 */
int informarTipoSeleccionadaByUser(eNotebook notebooks[], int tam_n, eMarca marcas[], int tam_m, eTipo tipos[], int tam_t, eCliente clientes[], int tam_cl);

/** \brief muestra la informacion de notebooks por id ingresado
 *
 * \param notebooks[] eNotebook vector de notebooks
 * \param tam_n int tamaño del vector de notebooks
 * \param marcas[] eMarca vector de marcas
 * \param tam_m int tamaño del vector de marcas
 * \param tipos[] eTipo vector de tipos
 * \param tam_t int tamaño del vector de tipos
 * \param clientes[] eCliente vector de clientes
 * \param tam_cl int tamaño del vector de clientes
 * \return int retorna 1 si salio todo ok o 0 si ocurrio un inconveniente
 *
 */
int mostrarNotebooksIdTipo(eNotebook notebooks[], int tam_n, eMarca marcas[], int tam_m, eTipo tipos[], int tam_t, eCliente clientes[], int tam_cl, int idTipo);


/** \brief Informa las notebooks de menor precio
 *
 * \param notebooks[] eNotebook vector de notebooks
 * \param tam_n int tamaño del vector de notebooks
 * \param marcas[] eMarca vector de marcas
 * \param tam_m int tamaño del vector de marcas
 * \param tipos[] eTipo vector de tipos
 * \param tam_t int tamaño del vector de tipos
 * \param clientes[] eCliente vector de clientes
 * \param tam_cl int tamaño del vector de clientes
 * \return int retorna 1 si salio todo ok o 0 si ocurrio un inconveniente
 *
 */
int notebookMenorPrecio(eNotebook notebooks[], int tam_n, eMarca marcas[], int tam_m, eTipo tipos[], int tam_t, eCliente clientes[], int tam_cl);

/** \brief Muestra todas las notebooks separadas por marca
 *
 * \param notebooks[] eNotebook vector de notebooks
 * \param tam_n int tamaño del vector de notebooks
 * \param marcas[] eMarca vector de marcas
 * \param tam_m int tamaño del vector de marcas
 * \param tipos[] eTipo vector de tipos
 * \param tam_t int tamaño del vector de tipos
 * \param clientes[] eCliente vector de clientes
 * \param tam_cl int tamaño del vector de clientes
 * \return int retorna 1 si salio todo ok o 0 si ocurrio un inconveniente
 *
 */
int mostrarNotebooksAllMarcas(eNotebook notebooks[], int tam_n, eMarca marcas[], int tam_m, eTipo tipos[], int tam_t, eCliente clientes[], int tam_cl);

/** \brief Pide al usuario Marca y tipo y muestra la cantidad de notebooks de esa marca y de ese tipo
 *
 * \param notebooks[] eNotebook vector de notebooks
 * \param tam_n int tamaño del vector de notebooks
 * \param marcas[] eMarca vector de marca
 * \param tam_m int tamaño del vector de marcas
 * \param tipos[] eTipo vector de tipos
 * \param tam_t int tamaño del vector de tipos
 * \return int retorna 1 si salio todo ok o 0 si ocurrio un problema
 *
 */
int informeCantidadNotebooksMarcaTipo(eNotebook notebooks[], int tam_n, eMarca marcas[], int tam_m, eTipo tipos[], int tam_t);

/** \brief Muestra la marca mas elegida
 *
 * \param notebooks[] eNotebook vector de notebooks
 * \param tam_n int tamaño del vector de notebooks
 * \param marcas[] eMarca vector de marca
 * \param tam_m int tamaño del vector de marcas
 * \return int retorna 1 si salio todo ok o 0 si ocurrio un problema
 *
 */
int marcaMasElegida(eNotebook notebooks[], int tam_n, eMarca marcas[], int tam_m);

/** \brief Valida una id de una notebook ingresada por el usuario
 *
 * \param notebooks[] eNotebook  vector de notebooks
 * \param idIng int id ingresado por el usuario
 * \param tam_n int tamaño del vector de notebooks
 * \return int retorna 1 si salio todo ok o 0 si ocurrio un problema
 *
 */
int validarIdNotebook(eNotebook notebooks[], int idIng, int tam_n);
