#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes_mascotas.c"
#include "funciones.c"
#define TC 10
#define TM 20
#define TR 10
#define TL 3

int main()
{

    eClientes clientes[TC];
    eMascota mascotas[TM];
    eRaza razas[TR];
    eLocalidad localidad[TL];
    int opcion;
    float promedio;

    inicializarCliente(clientes, TC);
    inicializarMascota(mascotas, TM);
    inicializarRaza(razas, TR);
    inicializarLocalidad(localidad, TL);

    hardcodeoClientes(clientes, TC, localidad, TL);
    hardcodeoMascotas(mascotas, TM, razas, TR);
    do
    {
        menu();
        opcion = validarOpcion(1,22);

        switch(opcion)/*MENU PRINCIPAL*/
        {
            case 1:
                mostrarClientes(clientes, TC,mascotas, TM, localidad, TL);
                break;

            case 2:
                mostrarMascotas(mascotas, TM, clientes, TC, razas, TR);
                break;

            case 3:
                mostrarClientesConMascota(mascotas, TM, clientes, TC, razas, TR, localidad, TL);
                break;

            case 4:
                printf("\n\n--------------------------------CLIENTES DISPONIBLES--------------------------------------\n");
                mostrarClientes(clientes, TC, mascotas, TM, localidad, TM);
                cargarUnaMascota(mascotas, TM, clientes, TC, razas, TR);
                break;

            case 5:
                mostrarMascotas(mascotas, TM, clientes, TC, razas, TR);
                eliminarUnaMascotaPorID(mascotas, TM);
                break;

            case 6:
                mostrarMascotas(mascotas, TM, clientes, TC, razas, TR);
                modificarUnaMascota(mascotas, TM, razas, TR, clientes, TC, localidad, TL);
                break;

            case 7:
                cargarUnCliente(clientes, TC, localidad, TL);
                break;

            case 8:
                mostrarClientes(clientes, TC,mascotas, TM, localidad, TM);
                eliminarUnCliente(mascotas, TM, clientes, TC);
                break;

            case 9:
                ordenarMascotasPorTipo(clientes, TC, mascotas, TM, razas, TR);
                mostrarMascotas(mascotas, TM, clientes, TC, razas, TR);
                break;

            case 10:
                mostrarClientes(clientes, TC,mascotas, TM, localidad, TM);
                modificarUnCliente(clientes, TC, localidad, TL);
                break;

            case 11:
                mostrarClientesConMasDeUnaMascota(clientes, TC, mascotas, TM, localidad, TM);
                break;

            case 12:
                mostrarClientesConMasDeTresAnios(clientes, TC, mascotas, TM, razas, TR);
                break;

            case 13:
                mascotasPorTipo(mascotas, TM, clientes, TC, razas, TR);
                mostrarMascotas(mascotas, TM, clientes, TC, razas, TR);
                break;

            case 14:
                ordenarPorCantidadMascotas(clientes, TC, mascotas, TM);
                mostrarClientes(clientes, TC, mascotas, TM, localidad, TM);
                break;

            case 15:
                ordenarPorCantidadMascotas(clientes, TC, mascotas, TM);
                ordenarPorCantidadMascotasYNombre(clientes, TC, mascotas, TM);
                mostrarClientes(clientes, TC, mascotas, TM, localidad, TM);
                break;

            case 16:
                promedio=promedioEdadMascotas(mascotas, TM);
                printf("El promedio de edad de las mascotas es de: %.2f\n", promedio);
                system("pause");
                break;

            case 17:
                promedioEdadMascotasPorTipo(mascotas, TM, razas, TR);
                break;

            case 18:
                promedioClientes(clientes, TC);
                porcentajeClientes(clientes, TC);
                break;

            case 19:
                ListarClientesPorSexoMascotas(clientes, TC, mascotas, TM, razas, TR, localidad, TL);
                break;

            case 20:
                clientesDelLaLocalidadSeleccionada(clientes, TC, localidad, TL);
                break;

            case 21:
                ordenarPorLocalidadYNombre(clientes, TC, localidad, TL);
                mostrarClientes(clientes, TC, mascotas, TM, localidad, TM);
                break;

            case 22:
                break;

        }
    }while  (opcion != 22);
    return 0;
}
