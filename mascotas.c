#include "mascotas.h"

/********************************************************************************************/
void hardcodeoRaza(eRaza razas[],int tamRaza)
{
    int id[10]= {300,301,302,303,304,305,306};
    char nombre[10][51]= {"Bulldog","pitbull","Labrador","Escino","Lagarto Overo","Angora","Gato","0","0","0"};
    char pais[10][51]= {"Aleman","Siberiano","Argentino","Argelino","Argentina","Turco","Persa","0","0","0"};
    char tipo[10][51]= {"Perro","Perro","Perro","Raro","Raro","Gato","Gato","","",""};
    int i;

    for(i=0; i<tamRaza; i++)
    {
        razas[i].id=id[i];
        strcpy(razas[i].nombre,nombre[i]);
        strcpy(razas[i].pais,pais[i]);
        strcpy(razas[i].tipo,tipo[i]);
        razas[i].estado=1;
    }
}
/********************************************************************************************/
void hardcodeoMascotas(eMascota mascotas[],int tamMascotas, eRaza razas[],int tamRaza)
{
    hardcodeoRaza(razas, tamRaza);
    int id[20]= {200,201,202,203,204,205,206,207,208,209,210};
    int idCliente[20]= {100,100,101,101,101,102,102,103,104,104,104};
    int idRaza[20] = {306,306,300,301,305,301,304,302,305,306,300};
    char nombre[20][40]= {"Michi","MichiSegunda","Tutuca","Potter","michifusi","Brutus","pepe","Manchita","Michooox","Micheeex","Tyson"};
    int edad[20]= {3,3,2,1,2,5,7,8,5,2,3};
    float peso[20]= {4.75,3.55,4.37,7.10,6.75,3.64,15.23,3.85,9.43,8.86,3.19};
    char sexo[20]= {'F','F','M','M','M','M','F','M','M','M','M'};
    int estado[20]= {1,1,1,1,1,1,1,1,1,1,1};
    int i;


    for(i=0; i<tamMascotas; i++)
    {
        mascotas[i].id=id[i];
        mascotas[i].idCliente=idCliente[i];
        mascotas[i].idRaza=idRaza[i];
        strcpy(mascotas[i].nombre,nombre[i]);
        mascotas[i].edad=edad[i];
        mascotas[i].peso=peso[i];
        mascotas[i].sexo=sexo[i];
        mascotas[i].estado=estado[i];
    }
}
/********************************************************************************************/
void inicializarMascota(eMascota mascota[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        mascota[i].estado=LIBRE;
        mascota[i].id=0;
    }
}

void inicializarRaza(eRaza raza[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        raza[i].estado=LIBRE;
        raza[i].id=0;
    }
}
/********************************************************************************************/
void menuModificacioMascota(void)
{
    printf("Que desea modificar?\n");
    printf("1.Nombre\n");
    printf("2.Tipo\n");
    printf("3.Edad\n");
    printf("4.peso\n");
    printf("5.Sexo\n");
    printf("6.Cliente\n");
    printf("7.salir\n");
}
/********************************************************************************************/
void promedioEdadMascotasPorTipo(eMascota mascotas[], int tamM,eRaza raza[], int tamR)
{
    int i;
    int j;
    int contadorPerro = 0;
    int contadorGato = 0;
    int contadorRaro = 0;
    int acumuladorPerro = 0;
    int acumuladorGato = 0;
    int acumuladorRaro = 0;
    float promedioPerro;
    float promedioGato;
    float promedioRaro;
    for (i=0; i<tamM ; i++)
    {
        if(mascotas[i].estado==OCUPADO)
        {
            for(j=0;j<tamR;j++)
            {
                if(mascotas[i].idRaza == raza[j].id)
                {
                   switch(raza[j].tipo[0])
                    {
                        case 'P':
                            contadorPerro++;
                            acumuladorPerro=acumuladorPerro+mascotas[i].edad;
                            break;

                        case 'G':
                            contadorGato++;
                            acumuladorGato=acumuladorGato+mascotas[i].edad;
                            break;

                        case 'R':
                            contadorRaro++;
                            acumuladorRaro=acumuladorRaro+mascotas[i].edad;
                            break;
                    }
                }
            }

        }
    }
    promedioPerro=(float)acumuladorPerro/contadorPerro;
    promedioGato=(float)acumuladorGato/contadorGato;
    promedioRaro=(float)acumuladorRaro/contadorRaro;

    printf("El promedio de edad de los perros es de: %.2f\n",promedioPerro);
    printf("El promedio de edad de los gatos es de: %.2f\n",promedioGato);
    printf("El promedio de edad de los raros es de: %.2f\n",promedioRaro);
    system("pause");
}
/********************************************************************************************/
int buscarLibreMascota(eMascota mascotas[],int tam)
{
    int i;
    int index = -1;
    for(i=0; i<tam; i++)
    {
        if(mascotas[i].estado==LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}
/********************************************************************************************/

/********************************************************************************************/


/********************************************************************************************/


void eliminarUnaMascotaPorID(eMascota mascotas[], int tam)
{
    int idMascota;
    int i;
    int flag =0;
    printf("Ingrese el id de la mascota a eliminar: ");
    scanf("%d", &idMascota);
    for(i=0; i<tam;i++)
    {
        if(idMascota == mascotas[i].id)
        {
            mascotas[i].estado=LIBRE;
            printf("mascota eliminada\n");
            flag=1;
            system("pause");
            break;
        }
    }
    if(flag != 1)
    {
        printf("no se encontro la mascota\n");
        system("pause");
    }
}
/********************************************************************************************/
void eliminarUnaMascota(eMascota mascotas[], int tam,int index)
{
    int i;
    for(i=0; i<tam;i++)
    {
        if(index == mascotas[i].id)
        {
            mascotas[i].estado=LIBRE;
            break;
        }
    }
}
/********************************************************************************************/
void modificarUnaMascota(eMascota mascotas[], int tam, eRaza raza[], int tamR, eClientes cliente[], int tamC, eLocalidad localidad[], int tamL)
{
    char opcion;
    menuModificacioMascota();
    opcion = validarOpcion(1, 7);

    switch(opcion)
    {
        case 1:
            modificarUnaMascotaNombre(mascotas, tam);
            break;

        case 2:
            modificarUnaMascotaTipo(mascotas, tam, raza, tamR);
            break;

        case 3:
            modificarUnaMascotaEdad(mascotas, tam);
            break;

        case 4:
            modificarUnaMascotaPeso(mascotas, tam);
            break;

        case 5:
            modificarUnaMascotaSexo(mascotas, tam);
            break;

        case 6:
            modificarUnaMascotaCliente(mascotas, tam, cliente, tamC, localidad, tamL);
            break;

        case 7:
            break;

    }
    system("pause");
}
/********************************************************************************************/
void modificarUnaMascotaNombre(eMascota mascotas[], int tam)
{
    int idMascota;
    int i;
    int flag =0;
    printf("Ingrese el ID de la mascota a modificar: ");
    scanf("%d", &idMascota);
    for(i=0; i<tam;i++)
    {
        if(idMascota == mascotas[i].id)
        {
            flag = 1;
            printf("Reingrese Nombre:");
            fflush(stdin);
            fgets(mascotas[i].nombre,40,stdin);
            mascotas[i].nombre[strlen(mascotas[i].nombre)-1]='\0';

            break;
        }
    }
    if(flag == 0)
    {
        printf("Mascota no encontrada\n");
    }

}
/********************************************************************************************/
void modificarUnaMascotaTipo(eMascota mascotas[], int tam, eRaza raza[], int tamR)
{
    int idMascota;
    int i;
    int cont;
    int j;
    char opcionTipo;
    int flag =0;
    printf("Ingrese el ID de la mascota a modificar: ");
    scanf("%d", &idMascota);

    for(i=0; i<tam;i++)
    {
        if(idMascota == mascotas[i].id)
        {
            for (j=0;j<tamR;j++)
            {
                if(raza[j].id!=0)
                {
                    cont++;
                }
            }
            flag=1;
            system("cls");
            printf ("Ingrese tipo de mascota:\n");
            for(j=0;j<cont-1;j++)
            {
                printf ("%d.%s %s\n", j+1,raza[j].nombre,raza[j].pais);
            }
            printf("9.Salir");
            opcionTipo = validarOpcion(49, 57);

            switch(opcionTipo)
            {
                case 49:
                    for(j=0;j<tamR;j++)
                    {
                        if(raza[j].id==300 && raza[j].estado==OCUPADO)
                        {
                            mascotas[i].idRaza=300;
                        }
                    }
                    if (mascotas[i].idRaza==300)
                    {
                        printf("carga exitosa\n");
                    }
                    else
                    {
                        printf("error\n");
                    }
                    break;

                case 50:
                    for(j=0;j<tamR;j++)
                    {
                        if(raza[j].id==301 && raza[j].estado==OCUPADO)
                        {
                            mascotas[i].idRaza=301;
                        }
                    }
                    if (mascotas[i].idRaza==301)
                    {
                        printf("carga exitosa\n");
                    }
                    else
                    {
                        printf("error\n");
                    }
                    break;

                case 51:
                    for(j=0;j<tamR;j++)
                    {
                        if(raza[j].id==302 && raza[j].estado==OCUPADO)
                        {
                            mascotas[i].idRaza=302;
                        }
                    }
                    if (mascotas[i].idRaza==302)
                    {
                        printf("carga exitosa\n");
                    }
                    else
                    {
                        printf("error\n");
                    }
                    break;

                case 52:
                    for(j=0;j<tamR;j++)
                    {
                        if(raza[j].id==303 && raza[j].estado==OCUPADO)
                        {
                            mascotas[i].idRaza=303;
                        }
                    }
                    if (mascotas[i].idRaza==303)
                    {
                        printf("carga exitosa\n");
                    }
                    else
                    {
                        printf("error\n");
                    }
                    break;

                case 53:
                    for(j=0;j<tamR;j++)
                    {
                        if(raza[j].id==304 && raza[j].estado==OCUPADO)
                        {
                            mascotas[i].idRaza=304;
                        }
                    }
                    if (mascotas[i].idRaza==304)
                    {
                        printf("carga exitosa\n");
                    }
                    else
                    {
                        printf("error\n");
                    }
                    break;

                case 54:
                    for(j=0;j<tamR;j++)
                    {
                        if(raza[j].id==305 && raza[j].estado==OCUPADO)
                        {
                            mascotas[i].idRaza=305;
                        }
                    }
                    if (mascotas[i].idRaza==305)
                    {
                        printf("carga exitosa\n");
                    }
                    else
                    {
                        printf("error\n");
                    }
                    break;

                case 55:
                    for(j=0;j<tamR;j++)
                    {
                        if(raza[j].id==306 && raza[j].estado==OCUPADO)
                        {
                            mascotas[i].idRaza=306;
                        }
                    }
                    if (mascotas[i].idRaza==306)
                    {
                        printf("carga exitosa\n");
                    }
                    else
                    {
                        printf("error\n");
                    }
                    break;

                case 56:
                    for(j=0;j<tamR;j++)
                    {
                        if(raza[j].id==307 && raza[j].estado==OCUPADO)
                        {
                            mascotas[i].idRaza=307;
                        }
                    }
                    if (mascotas[i].idRaza==307)
                    {
                        printf("carga exitosa\n");
                    }
                    else
                    {
                        printf("error\n");
                    }
                    break;

                case 57:
                    break;
            }

        }
    }

    if(flag == 0)
    {
        printf("Mascota no encontrada\n");
    }
}
/********************************************************************************************/
void modificarUnaMascotaEdad(eMascota mascotas[], int tam)
{
    int idMascota;
    int i;
    int flag = 0;
    printf("Ingrese el ID de la mascota a modificar: ");
    scanf("%d", &idMascota);
    for(i=0; i<tam;i++)
    {
        if(idMascota == mascotas[i].id)
        {
            flag = 1;
            printf ("Ingrese edad: ");
            scanf ("%d", &mascotas[i].edad);

            break;
        }
    }
    if(flag == 0)
    {
        printf("Mascota no encontrada\n");
    }
}
/********************************************************************************************/
void modificarUnaMascotaPeso(eMascota mascotas[], int tam)
{
    int idMascota;
    int i;
    int flag =0;
    printf("Ingrese el ID de la mascota a modificar: ");
    scanf("%d", &idMascota);
    for(i=0; i<tam;i++)
    {
        if(idMascota == mascotas[i].id)
        {
            flag = 1;
            printf ("reingrese peso: ");
            scanf ("%d", &mascotas[i].edad);

            break;
        }
    }
    if(flag == 0)
    {
        printf("Mascota no encontrada\n");
    }
}
/********************************************************************************************/
void modificarUnaMascotaSexo(eMascota mascotas[], int tam)
{
    int idMascota;
    int i;
    int flag =0 ;
    printf("Ingrese el ID de la mascota a modificar: ");
    scanf("%d", &idMascota);
    for(i=0; i<tam;i++)
    {
        if(idMascota == mascotas[i].id)
        {
            flag= 1;
            printf ("Reingrese sexo (F o M): ");
            scanf ("%s", &mascotas[i].sexo);

            while(mascotas[i].sexo!='M' && mascotas[i].sexo!='F')
            {
                printf ("ERROR!! Reingrese sexo (F o M): ");
                scanf ("%s", &mascotas[i].sexo);
            }
            break;
        }
    }
    if(flag == 0)
    {
        printf("Mascota no encontrada\n");
    }
}
/********************************************************************************************/

