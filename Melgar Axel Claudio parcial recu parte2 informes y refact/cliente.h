#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct{
    int id;
    char nombre[20];
    char sexo;
}eCliente;

#endif // CLIENTE_H_INCLUDED


/** \brief Muestra el total de clientes
 *
 * \param clientes[] eCliente vector clientes
 * \param tam_cl int tamaño del vector de clientes
 * \return int 1 si salio todo bien o 0 si ocurrio un problema
 *
 */
int mostrarClientes(eCliente clientes[], int tam_cl);

/** \brief Valida un id ingresado con un id dentro del vector
 *
 * \param clientes[] eCliente vector de clientes
 * \param idIng int id ingresado por el usuario
 * \param tam_cl int tamaño del vector de clientes
 * \return int retorna 1 si salio todo ok o 0 si ocurrio un inconveniente
 *
 */
int validarIdCliente(eCliente clientes[], int idIng, int tam_cl);


/** \brief Carga el nombre de un cliente
 *
 * \param clientes[] eCliente Vector de clientes
 * \param tam_cl int tamaño del vector de clientes
 * \param idMarca int id ingresada por el usuario
 * \param descripcion[] char puntero donde se copia el nombre del cliente
 * \return int retorna 1 si salio todo ok o 0 si ocurrio un problema
 *
 */
int cargarDescripcionCliente(eCliente clientes[], int tam_cl, int idMarca, char descripcion[]);
