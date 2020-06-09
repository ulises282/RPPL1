#include "clientes.c"
#include "mascotas.c"
#define TM 20

void mostrarClientesConMascota(eMascota mascotas[], int tamM,eClientes cliente[],int tamD, eRaza raza[], int tamR, eLocalidad localidad[], int tamL);
void eliminarUnCliente(eMascota mascotas[], int tamM,eClientes clientes[], int tamC);
void mascotasPorTipo(eMascota mascotas[], int tamM,eClientes clientes[], int tamC, eRaza raza[], int tamR);
void mostrarClientesConMasDeUnaMascota(eClientes cliente[],int tamC, eMascota mascotas[], int tamM, eLocalidad localidad[], int tamL);
void mostrarClientesConMasDeTresAnios(eClientes cliente[],int tamC, eMascota mascotas[], int tamM, eRaza raza[], int tamR);
void ordenarPorCantidadMascotas (eClientes cliente[],int tamC, eMascota mascotas[], int tamM);
void ordenarPorCantidadMascotasYNombre (eClientes cliente[],int tamC, eMascota mascotas[], int tamM);
void mostrarClientes(eClientes cliente[],int tamC, eMascota mascotas[], int tamM, eLocalidad localidad[], int tamL);
float promedioEdadMascotas(eMascota mascotas[], int tamM);
void contarMascota(eClientes cliente[],int tamC, eMascota mascotas[], int tamM);
void ordenarMascotasPorTipo (eClientes cliente[],int tamC, eMascota mascotas[], int tamM, eRaza raza[], int tamR);
void mostrarMascotas(eMascota mascotas[],int tamM, eClientes cliente[],int tamC, eRaza raza[], int tamR);
eMascota crearUnaMascota (eClientes cliente[],int tamC, eMascota mascotas[], int tamM, eRaza raza[],int tamR);
void cargarUnaMascota(eMascota mascotas[],int tamM, eClientes cliente[],int tamC, eRaza raza[],int tamR);
void modificarUnaMascotaCliente(eMascota mascotas[], int tam, eClientes clientes[], int tamC, eLocalidad localidad[], int tamL);
void ListarClientesPorSexoMascotas (eClientes cliente[],int tamC, eMascota mascotas[], int tamM, eRaza raza[], int tamR, eLocalidad localidad[], int tamL);
