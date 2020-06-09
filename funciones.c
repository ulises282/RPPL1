#include "funciones.h"
/***************************************************************/
void menu(void)
{
    system("cls");
    printf("-------VETERINARIA-------\n");
    printf("1. Listado de clientes\n");
    printf("2. Listado de mascotas\n");
    printf("3. Listado de clientes con mascotas\n");
    printf("4. Alta de mascota\n");
    printf("5. Baja de mascota\n");
    printf("6. Modificar mascota\n");
    printf("7. Alta duenio\n");
    printf("8. Borrado de duenio\n");
    printf("9. Ordenar mascotas por tipo\n");
    printf("10. Modificar duenio\n");
    printf("11. Listar clientes con mas de una mascota\n");
    printf("12. Listar mascotas de mas de 3 anios\n");
    printf("13. Listar las mascotas por tipo\n");
    printf("14. Ordenar a los duenios por cantidad de mascotas\n");
    printf("15. Ordenar a los duenios por cantidad de mascotas y por orden alfabetico\n");
    printf("16. Promedio de edad entre las mascotas\n");
    printf("17. Promedio de edad entre las mascotas por tipo\n");
    printf("18. porcentaje de clientes mujeres\n");
    printf("19. Listar duenios con mascotas del mismo sexo\n");
    printf("20. Mostrar clientes de la localidad seleccionada\n");
    printf("21. Ordenar por localidad y por nombre\n");
    printf("22. Salir\n");
}
/***************************************************************/
int validar_numero(char opcion[])
{
    int i;
    for(i=0;i<strlen(opcion);i++)
    {
        if (!isdigit(opcion[i]) || strlen(opcion)>2)
        {
            return 0;
        }
    }
    return 1;
}
/***************************************************************/
int validarOpcion(int min, int max)
{
    int numero_valido;

    do{
        numero_valido = validar();
    }while(numero_valido<min || numero_valido>max);
    return  numero_valido;
}
/***************************************************************/
int validar ()
{
    int valido;
    int numero_valido;
    char opcion[128];
    printf("Ingrese una opcion: ");
    scanf("%s", opcion);
    valido = validar_numero (opcion);
    while(valido != 1)
    {
        printf("ERROR! Ingrese una opcion: ");
        scanf("%s", opcion);
        valido = validar_numero (opcion);
    }
    numero_valido = atoi(opcion);
    return numero_valido;
}
/***************************************************************/
void menuClientes(void)
{
    system("cls");
    printf("-------CLIENTES-------\n");
    printf("1. Listado de clientes\n");
    printf("2. Alta de clientes\n");
    printf("3. Modificacion de clientes\n");
    printf("4. Baja de clientes\n");
    printf("5. Volver\n");
}
/***************************************************************/
void menuMascotas (void)
{
    system("cls");
    printf("-------MASCOTAS-------\n");
    printf("1. Listado de mascotas\n");
    printf("2. Alta de mascotas\n");
    printf("3. Modificacion de mascotas\n");
    printf("4. Baja de mascotas\n");
    printf("5. Volver\n");
}
/***************************************************************/
void menuClientes_Mascotas(void)
{
    system("cls");
    printf("-------CLIENTES_MASCOTAS-------\n");
    printf("1. Listado de clientes con mascotas\n");
    printf("2. Listado de mascotas por tipo\n");
    printf("3. Lista de clientes con mas de una mascota \n");
    printf("4. Mascotas con mas de 3 anios  \n");
    printf("5. Clientes ordenados por cantidad de mascotas\n");
    printf("6. Clientes ordenados por cantidad de mascotas y nombre\n");
    printf("7. ordenar mascotas por tipo\n");
    printf("8. ordenar clientes por sexo de mascotas\n");
    printf("9. Volver\n");
}
/***************************************************************/
void menuPromedios(void)
{
    system("cls");
    printf("-------PROMEDIOS-------\n");
    printf("1. Promedio de edad entre las mascotas  \n");
    printf("2. Promedio de edad entre las mascotas por tipo  \n");
    printf("3. Promedio entre clientes varones y mujeres  \n");
    printf("4.  Salir\n");

}
/***************************************************************/
void menuModificacioClientes(void)
{
    printf("Que desea modificar?\n");
    printf("1. Nombre\n");
    printf("2. Apellido\n");
    printf("3. Localidad\n");
    printf("4. Telefono\n");
    printf("5. Edad\n");
    printf("6. Sexo\n");
    printf("7. Salir\n");
}
