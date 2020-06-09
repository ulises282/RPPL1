#include "clientes_mascotas.h"

void mostrarClientesConMascota(eMascota mascotas[], int tamM,eClientes cliente[],int tamD, eRaza raza[], int tamR, eLocalidad localidad[], int tamL)
{
    int i;
    int j;
    int k;
    for(i=0;i<tamD;i++)
    {
        if(cliente[i].estado==OCUPADO)
        {
            for(j=0;j<tamL;j++)
            {
                if(cliente[i].idLocalidad == localidad[j].id)
                {
                    printf("\n\n----------------------------------------CLIENTE------------------------------------------\n");
                    printf(" ID                nombre             apellido                localidad         telefono\n");
                    printf("-----------------------------------------------------------------------------------------\n");
                    printf("%4d %20s %20s %20s %20s\n\n",cliente[i].id
                                                        ,cliente[i].nombre
                                                        ,cliente[i].apellido
                                                        ,localidad[j].descripcion
                                                        ,cliente[i].telefono);
                }
            }
            printf("\n");
            printf("----------------------------------------MASCOTAS---------------------------------------\n");
            printf(" ID               nombre                  raza                pais        edad\n");
            printf("---------------------------------------------------------------------------------------\n");
            for(j=0;j<tamM;j++)
            {
                if(mascotas[j].estado==OCUPADO && cliente[i].id==mascotas[j].idCliente)
                {
                    for(k=0;k<tamR;k++)
                    {
                        if(raza[k].estado==OCUPADO && mascotas[j].idRaza==raza[k].id)
                        {
                            printf("%4d %20s %20s %20s %8d\n\n"   ,mascotas[j].id
                                                                ,mascotas[j].nombre
                                                                ,raza[k].nombre
                                                                ,raza[k].pais
                                                                ,mascotas[j].edad);
                        }
                    }
                }
            }
        }
    }
    system("pause");
}
/****************************************************************************************/
void eliminarUnCliente(eMascota mascotas[], int tamM,eClientes clientes[], int tamC)
{
    int idCliente;
    int i;
    printf("Ingrese el id del cliente a eliminar: ");
    scanf("%d", &idCliente);
    for(i=0; i<tamC;i++)
    {
        if(idCliente == clientes[i].id)
        {
            printf("Cliente %s eliminado\n",clientes[i].nombre);
            clientes[i].estado=LIBRE;
            break;
        }
    }
    for(i=0; i<tamM;i++)
    {
        if(idCliente == mascotas[i].idCliente)
        {
            eliminarUnaMascota(mascotas, TM, mascotas[i].id);
            printf("Mascota  %s eliminada\n",mascotas[i].nombre);
        }
    }
    system("pause");
}
/****************************************************************************************/
void mascotasPorTipo(eMascota mascotas[], int tamM,eClientes clientes[], int tamC, eRaza raza[], int tamR)
{
    int i;
    int j;
    eMascota aux;

    for(i=0; i<tamM-1; i++)
    {
        for(j=i+1; j<tamM; j++)
        {
            if(mascotas[i].idRaza<mascotas[j].idRaza)
            {
                aux = mascotas[i];
                mascotas[i] = mascotas[j];
                mascotas[j] = aux;
            }
        }
    }
}
/********************************************************************************************/


void mostrarClientesConMasDeUnaMascota(eClientes cliente[],int tamC, eMascota mascotas[], int tamM, eLocalidad localidad[], int tamL)
{
    int i;
    int j;
    printf("\n\n----------------------------CLIENTES CON MAS DE UNA MASCOTA------------------------------\n");
    printf(" ID                nombre             apellido               localidad          cantidad de mascotas\n");
    printf("----------------------------------------------------------------------------------------\n");
    contarMascota(cliente, tamC, mascotas, tamM);
    for (i=0;i<tamC;i++)
    {
        if (cliente[i].cantidadMascotas>1 && cliente[i].estado==OCUPADO)
        {
            for(j=0;j<tamL;j++)
            {
                if(cliente[i].idLocalidad == localidad[j].id)
                {
                    printf("%4d %20s %20s %20s %20d\n"  ,cliente[i].id
                                                        ,cliente[i].nombre
                                                        ,cliente[i].apellido
                                                        ,localidad[j].descripcion
                                                        ,cliente[i].cantidadMascotas);
                }
            }

        }
    }
    printf("\n\n");
    system ("pause");
}
/********************************************************************************************/

void contarMascota(eClientes cliente[],int tamC, eMascota mascotas[], int tamM)
{
    int i;
    int j;
    for(i=0;i<tamC;i++)
    {
        if(cliente[i].estado==OCUPADO)
        {
            cliente[i].cantidadMascotas=0;
            for(j=0;j<tamM;j++)
            {
                if(cliente[i].id==mascotas[j].idCliente)
                {
                    cliente[i].cantidadMascotas++;
                }
            }
        }
    }
}
/********************************************************************************************/
void mostrarClientesConMasDeTresAnios(eClientes cliente[],int tamC, eMascota mascotas[], int tamM, eRaza raza[], int tamR)
{
    int i;
    int j;
    int k;
    printf("\n\n----------------------------MASCOTAS CON MAS DE 3 ANIOS-----------------------------------------------\n");
    printf(" ID              nombre                   nombre               pais             cliente          anios \n");
    printf("------------------------------------------------------------------------------------------------------\n");
    for(i=0;i<tamM;i++)
    {
        if(mascotas[i].estado==OCUPADO && mascotas[i].edad>3)
        {
            for(j=0;j<tamC;j++)
            {
                if(cliente[j].id==mascotas[i].idCliente)
                {
                    for(k=0;k<tamR;k++)
                    {
                        if(mascotas[i].idRaza == raza[k].id)
                        {
                            printf("%4d %20s %20s %20s %20s %8d\n"  ,mascotas[i].id
                                                            ,mascotas[i].nombre
                                                            ,raza[k].nombre
                                                            ,raza[k].pais
                                                            ,cliente[j].nombre
                                                            ,mascotas[i].edad);
                        }
                    }
                }
            }
        }
    }
    printf("\n\n");
    system ("pause");
}
/********************************************************************************************/
void ordenarPorCantidadMascotas (eClientes cliente[],int tamC, eMascota mascotas[], int tamM)
{
    int i;
    int j;
    eClientes aux;
    contarMascota(cliente, tamC, mascotas, tamM);
    for(i=0; i<tamC-1; i++)
    {
        for(j=i+1; j<tamC; j++)
        {
            if(cliente[i].cantidadMascotas<cliente[j].cantidadMascotas)
            {
                aux = cliente[i];
                cliente[i] = cliente[j];
                cliente[j] = aux;
            }
        }

    }
}
/********************************************************************************************/
void ordenarPorCantidadMascotasYNombre (eClientes cliente[],int tamC, eMascota mascotas[], int tamM)
{
    int i;
    int j;
    eClientes aux;

    for(i=0; i<tamC-1; i++)
    {
        for(j=i+1; j<tamC; j++)
        {
            if(cliente[i].cantidadMascotas<cliente[j].cantidadMascotas)
            {
                aux = cliente[i];
                cliente[i] = cliente[j];
                cliente[j] = aux;
            }
            else
            {
               if(cliente[i].cantidadMascotas==cliente[j].cantidadMascotas)
               {
                   if(strcmp(cliente[i].nombre,cliente[j].nombre)>0)
                   {
                        aux = cliente[i];
                        cliente[i] = cliente[j];
                        cliente[j] = aux;
                   }
               }
            }
        }

    }
}
/********************************************************************************************/
void mostrarClientes(eClientes cliente[],int tamC, eMascota mascotas[], int tamM, eLocalidad localidad[], int tamL)
{
    contarMascota(cliente, tamC, mascotas, tamM);
    int i;
    int j;
    printf("\n\n----------------------------------------CLIENTES-------------------------------------------------------------\n");
    printf(" ID                nombre             apellido               localidad          telefono      cant. mascotas\n");
    printf("-------------------------------------------------------------------------------------------------------------\n");
    for(i=0;i<tamC;i++)
    {
        if(cliente[i].estado==OCUPADO)
        {
            for(j=0;j<tamL;j++)
            {
                if(cliente[i].idLocalidad == localidad[j].id)
                {
                    printf("%4d %20s %20s %20s %20s %10d\n"  ,cliente[i].id
                                                            ,cliente[i].nombre
                                                            ,cliente[i].apellido
                                                            ,localidad[j].descripcion
                                                            ,cliente[i].telefono
                                                            ,cliente[i].cantidadMascotas);
                }
            }
        }
    }
    printf("\n\n");
    system ("pause");
}
/********************************************************************************************/
float promedioEdadMascotas(eMascota mascotas[], int tamM)
{
    int i;
    int contador=0 ;
    int acumulador= 0;
    float promedio;
    for (i=0; i<tamM ; i++)
    {
        if(mascotas[i].estado==OCUPADO)
        {
            contador++;
            acumulador=acumulador+mascotas[i].edad;
        }
    }
    promedio=(float)acumulador/contador;

    return promedio;
}
/********************************************************************************************/
eMascota crearUnaMascota (eClientes cliente[],int tamC, eMascota mascotas[], int tamM, eRaza raza[],int tamR)
{
    eMascota mascota;
    char opcionTipo;
    int i;
    int flag;

    printf ("Ingrese nombre a la mascota: ");
    fflush (stdin);
    fgets(mascota.nombre,51,stdin);
    mascota.nombre[strlen(mascota.nombre)-1]='\0';


    printf ("Ingrese tipo de mascota:\n");
    int contadorRaza=0;
    for(i=0;i<tamR;i++)
    {
        if(raza[i].nombre[0]=='0')
        {
            break;
        }
        contadorRaza++;
        printf ("%d. %s %s\n",i+1, raza[i].nombre, raza[i].pais);
    }
    opcionTipo = validarOpcion(1,7);

    switch(opcionTipo)
    {
        case 1:
            mascota.idRaza=300;
            break;

        case 2:
            mascota.idRaza=301;
            break;

        case 3:
            mascota.idRaza=302;
            break;

        case 4:
            mascota.idRaza=303;
            break;

        case 5:
            mascota.idRaza=304;
            break;

        case 6:
            mascota.idRaza=305;
            break;

        case 7:
            mascota.idRaza=306;
            break;

    }

    printf ("Ingrese edad: ");
    scanf ("%d", &mascota.edad);

    printf ("Ingrese peso: ");
    scanf ("%f", &mascota.peso);

    printf ("Ingrese sexo (F o M): ");
    scanf ("%s", &mascota.sexo);

    while(mascota.sexo!='M' && mascota.sexo!='F')
    {
        printf ("ERROR!! Ingrese sexo (F o M): ");
        scanf ("%s", &mascota.sexo);
    }

    for(i=0; i<tamC;i++)
    {
        if(i==0)
        {
            printf ("Ingrese id del cliente: ");
            scanf ("%d", &mascota.idCliente);
        }
        if(mascota.idCliente == cliente[i].id && (mascota.idCliente!=0))
        {
            flag = 1;
            break;
        }
        else
        {
            if(i==tamC-1)
            {
                i=-1;
            }
        }
    }

    mascota.estado = OCUPADO;

  return mascota;
}

/********************************************************************************************/
void ordenarMascotasPorTipo (eClientes cliente[],int tamC, eMascota mascotas[], int tamM, eRaza raza[], int tamR)
{
    int i;
    int j;
    eMascota aux;

    for(i=0; i<tamM-1; i++)
    {
        for(j=i+1; j<tamM; j++)
        {
            if(mascotas[i].idRaza < mascotas[j].idRaza)
            {
                aux = mascotas[i];
                mascotas[i] = mascotas[j];
                mascotas[j] = aux;
            }
        }
    }

}
/********************************************************************************************/
void mostrarMascotas(eMascota mascotas[],int tamM, eClientes cliente[],int tamC, eRaza raza[], int tamR)
{
    int i;
    int j;
    int k;
    printf("\n----------------------------------------Mascotas---------------------------------------\n");
    printf(" ID              nombre                 tipo                 pais        nombre Cliente \n");
    printf("---------------------------------------------------------------------------------------\n");
    for(i=0;i<tamM;i++)
    {
        if(mascotas[i].estado==OCUPADO)
        {
            for(j=0;j<tamC;j++)
            {
                if (mascotas[i].idCliente==cliente[j].id)
                {
                    for(k=0;k<tamR;k++)
                    {
                        if (mascotas[i].idRaza==raza[k].id)
                        {
                            printf("%4d %20s %20s %20s %17s\n"  ,mascotas[i].id
                                                                ,mascotas[i].nombre
                                                                ,raza[k].nombre
                                                                ,raza[k].pais
                                                                ,cliente[j].nombre);
                        }
                    }
                }
            }
        }
    }
    printf("\n\n");
    system("pause");
}
///////////////////////////////////////////////////////////////////////////////////
void cargarUnaMascota(eMascota mascotas[],int tamM, eClientes cliente[],int tamC, eRaza raza[],int tamR)
{
    int index;

    index = buscarLibreMascota(mascotas, tamM);

    if(index!=-1)
    {
        mascotas[index] = crearUnaMascota(cliente, tamC, mascotas, tamM, raza, tamR);
        mascotas[index].id = index +200;
        printf("Carga con exito");
        system("pause");
    }
    else
    {
        printf("No hay espacio para mas mascotas");
    }
}
//////////////////////////////////////////////////////////////////////////////////
void modificarUnaMascotaCliente(eMascota mascotas[], int tam, eClientes clientes[], int tamC, eLocalidad localidad[], int tamL)
{
    int idMascota;
    int i;
    int flag =0;
    int j;
    int auxCliente;
    printf("Ingrese el ID de la mascota a modificar: ");
    scanf("%d", &idMascota);
    for(i=0; i<tam;i++)
    {
        if(idMascota == mascotas[i].id)
        {
            flag = 1;
            printf("clientes disponibles: \n");
            mostrarClientes(clientes, tamC, mascotas, tam, localidad, tamL);
            printf("Reingrese Cliente:");
            scanf("%d", &auxCliente);

            for(j=0; j<tamC;j++)
            {
                if(auxCliente == clientes[j].id)
                {
                    mascotas[i].idCliente=auxCliente;
                    break;
                }
                else
                {
                    if(i==tamC-1)
                    {
                        printf("no se encontro ese ID");
                    }
                }
            }
        }
    }
    if(flag == 0)
    {
        printf("Mascota no encontrada\n");
    }
}
//////////////////////////////////////////////////////////////////////////////////
void ListarClientesPorSexoMascotas (eClientes cliente[],int tamC, eMascota mascotas[], int tamM, eRaza raza[], int tamR, eLocalidad localidad[], int tamL)
{
    int i;
    int j;
    int k;
    contarMascota(cliente, tamC, mascotas, tamM);

    printf("\nClientes con mascotas del mismo sexo: \n\n");

    for(i=0;i<tamC;i++)
    {
        int contM=0;
        int contF=0;
        if(cliente[i].estado==OCUPADO)
        {
            for(j=0;j<tamM;j++)
            {
                if(mascotas[j].idCliente==cliente[i].id && mascotas[j].sexo=='M')
                {
                    contM++;
                }
                else
                {
                    if (mascotas[j].idCliente==cliente[i].id && mascotas[j].sexo=='F')
                    {
                        contF++;
                    }
                }
            }
        }

        if(cliente[i].estado==OCUPADO && (contF>=2 || contM>=2))
        {
            for(j=0;j<tamL;j++)
            {
                if(cliente[i].idLocalidad == localidad[j].id)
                {
                    printf("\n\n----------------------------------------CLIENTE------------------------------------------\n");
                    printf(" ID                nombre             apellido                localidad         telefono\n");
                    printf("-----------------------------------------------------------------------------------------\n");
                    printf("%4d %20s %20s %20s %20s\n\n",cliente[i].id
                                                        ,cliente[i].nombre
                                                        ,cliente[i].apellido
                                                        ,localidad[j].descripcion
                                                        ,cliente[i].telefono);
                }
            }
            printf("\n");
            printf("----------------------------------------MASCOTAS---------------------------------------\n");
            printf(" ID               nombre                  raza                pais        sexo\n");
            printf("---------------------------------------------------------------------------------------\n");
            for(j=0;j<tamM;j++)
            {
                if(mascotas[j].estado==OCUPADO && cliente[i].id==mascotas[j].idCliente)
                {
                    for(k=0;k<tamR;k++)
                    {
                        if(mascotas[j].idRaza == raza[k].id)
                        {
                            printf("%4d %20s %20s %20s %10c\n\n"    ,mascotas[j].id
                                                                    ,mascotas[j].nombre
                                                                    ,raza[k].nombre
                                                                    ,raza[k].pais
                                                                    ,mascotas[j].sexo);
                        }
                    }
                }
            }
        }
    }
system("pause");
}

    /*for(i=0;i<tamC;i++)
    {
        int contM=0;
        int contF=0;
        if(cliente[i].estado==OCUPADO)
        {
            for(j=0;j<tamM;j++)
            {
                if(mascotas[j].idCliente==cliente[i].id && mascotas[j].sexo=='M')
                {
                    contM++;
                }
                else
                {
                    if (mascotas[j].idCliente==cliente[i].id && mascotas[j].sexo=='F')
                    {
                        contF++;
                    }
                }
            }
            if(contM>1)
            {
                for(k=0;k<tamL;k++)
                {
                    if(cliente[i].idLocalidad == localidad[k].id)
                    {
                        printf("---------------------------------------CLIENTE--------------------------------------------\n");
                        printf(" ID                nombre             apellido               localidad          telefono\n");
                        printf("----------------------------------------------------------------------------------------\n");
                        printf("%4d %20s %20s %20s %20s\n",cliente[i].id
                                                            ,cliente[i].nombre
                                                            ,cliente[i].apellido
                                                            ,localidad[k].descripcion
                                                            ,cliente[i].telefono);
                        printf("\n%s tiene %d mascotas masculinas \n\n", cliente[i].nombre, contM);

                    }
                }
            }
            else
            {
                if(contF>1)
                {
                    for(k=0;k<tamL;k++)
                    {
                        if(cliente[i].idLocalidad == localidad[k].id)
                        {
                            printf("----------------------------------------------------------------------------------------\n");
                            printf(" ID                nombre             apellido               localidad          telefono\n");
                            printf("----------------------------------------------------------------------------------------\n");
                            printf("%4d %20s %20s %20s %20s\n",cliente[i].id
                                                                ,cliente[i].nombre
                                                                ,cliente[i].apellido
                                                                ,localidad[k].descripcion
                                                                ,cliente[i].telefono);
                            printf("\n%s tiene %d mascotas femeninas \n\n", cliente[i].nombre, contF);
                        }
                    }
                }
            }
        }
    }*/
