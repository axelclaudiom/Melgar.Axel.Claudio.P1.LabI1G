#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct{
    int id;
    char nombre[20];
    char sexo;
}eCliente;

#endif // CLIENTE_H_INCLUDED


int mostrarClientes(eCliente clientes[], int tam_cl);
int validarIdCliente(eCliente clientes[], int idIng, int tam_cl);
int cargarDescripcionCliente(eCliente clientes[], int tam_cl, int idMarca, char descripcion[]);
