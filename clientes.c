#include "clientes.h"
#include "funciones.h"
/***********************************************************************/
void hardcodeoClientes (eClientes clientes[], int tamClientes, eLocalidad localidad[], int tamL)
{
    hardcodeoLocalidad(localidad, tamL);
    int id[20] = {100,101,102,103,104};
    char nombre[20][51] = {"Ludmila","Juan","Florencia","Pepe","Roberto"};
    char apellido[20][51] = {"Garcia","Fernandez","Gomez","Paredes","Castillo"};
    int idLocalidad[20] = {400,402,402,401,400};
    char telefono[20][15] = {"1574895","5484234","5418233","84554246","15784622"};
    int edad[20] = {20,40,18,18,45};
    char sexo[20] = {'F','M','F','M','M'};
    int estado[20] = {1,1,1,1,1};

    int i;
    for(i=0; i<tamClientes; i++)
    {
        clientes[i].id=id[i];
        strcpy(clientes[i].nombre,nombre[i]);
        strcpy(clientes[i].apellido,apellido[i]);
        clientes[i].idLocalidad=idLocalidad[i];
        strcpy(clientes[i].telefono,telefono[i]);
        clientes[i].edad=edad[i];
        clientes[i].sexo=sexo[i];
        clientes[i].estado=estado[i];
    }
}
/***********************************************************************/
void hardcodeoLocalidad(eLocalidad localidad[], int tamL)
{
    int id[3] ={400,401,402};
    char provincia[3][51] ={"Buenos Aires","Santa Fe","La Pampa"};
    char codigoPostal[3][20] ={"B1878","S2000","L6300"};
    char descripcion[3][51] ={"Quilmes","Rosario","Santa Rosa"};

    int i;
    for (i=0;i<tamL;i++)
    {
        localidad[i].id=id[i];
        strcpy(localidad[i].provincia,provincia[i]);
        strcpy(localidad[i].codigoPostal,codigoPostal[i]);
        strcpy(localidad[i].descripcion,descripcion[i]);
    }
}
/***********************************************************************/
void inicializarCliente(eClientes cliente[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        cliente[i].estado=LIBRE;
        cliente[i].id=0;
    }
}
/***********************************************************************/
void inicializarLocalidad(eLocalidad localidad[],int tamL)
{
    int i;
    for(i=0; i<tamL; i++)
    {
        localidad[i].id=0;
    }
}
/***********************************************************************/
int buscarLibreCliente(eClientes clientes[],int tamC)
{
    int i;
    int index = -1;
    for(i=0; i<tamC; i++)
    {
        if(clientes[i].estado==LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}
/***********************************************************************/
void cargarUnCliente(eClientes clientes[], int tamC, eLocalidad localidad[], int tamL)
{
    int index;

    index = buscarLibreCliente(clientes, tamC);

    if(index!=-1)
    {
        clientes[index] = crearUnCliente(localidad, tamL);
        clientes[index].id = index +100;
        printf("Cliente cargado con exito\n");
        system("pause");
    }
    else
    {
        printf("No hay mas espacio para clientes\n");
        system("pause");
    }

}
/***********************************************************************/
eClientes crearUnCliente (eLocalidad localidad[], int tamL)
{
    int opcionTipo;
    eClientes clientes;
    char aux[51];
    int valido;

    /*printf ("Ingrese nombre: ");
    fflush (stdin);
    fgets(clientes.nombre,51,stdin);
    clientes.nombre[strlen(clientes.nombre)-1]='\0';*/


    do{
        valido = validar_string(aux, "Ingresar nombre: ");
    }while(valido!=1);
    strcpy(clientes.nombre, aux);

    do{
        valido = validar_string(aux, "Ingresar apellido");
    }while(valido!=1);
    strcpy(clientes.apellido, aux);

    printf ("Ingrese localidad: \n");
    int cont = 0;
    int i;
    for(i=0;i<tamL;i++)
    {
        cont++;
        printf("    %d.%s\n", cont, localidad[i].descripcion);
    }

    opcionTipo = validarOpcion(1,3);

    switch(opcionTipo)
    {
        case 1:
            clientes.idLocalidad=400;
            break;

        case 2:
            clientes.idLocalidad=401;
            break;

        case 3:
            clientes.idLocalidad=402;
            break;
    }

    do{
        printf ("Ingrese telefono: ");
        fflush (stdin);
        fgets(clientes.telefono,51,stdin);
        clientes.telefono[strlen(clientes.telefono)-1]='\0';
    }while(clientes.telefono<0);

    do{
        printf ("Ingrese edad: ");
        scanf ("%d", &clientes.edad);
    }while(clientes.edad<5 || clientes.edad>110);


    printf ("Ingrese sexo (F o M): ");
    scanf ("%s", &clientes.sexo);

    while(clientes.sexo!='M' && clientes.sexo!='F')
    {
        printf ("ERROR!! Ingrese sexo (F o M): ");
        scanf ("%s", &clientes.sexo);
    }

    clientes.estado = OCUPADO;

  return clientes;
}
/***********************************************************************/
void modificarUnCliente(eClientes clientes[], int tam, eLocalidad localidad[], int tamL)
{
    char opcion;
    menuModificacioClientes();
    opcion = validarOpcion(1, 7);

    switch(opcion)
    {
        case 1:
            modificarUnClienteNombre(clientes, tam);
            break;

        case 2:
            modificarUnClienteApellido(clientes, tam);
            break;

        case 3:
            modificarUnClienteLocalidad(clientes, tam, localidad, tamL);
            break;

        case 4:
            modificarUnClienteTelefono(clientes, tam);
            break;

        case 5:
            modificarUnClienteEdad(clientes, tam);
            break;

        case 6:
            modificarUnClienteSexo(clientes, tam);
            break;

        case 7:
            break;
    }
    system("pause");
}
/********************************************************************************************/
void modificarUnClienteNombre(eClientes clientes[], int tam)
{
    int id;
    int i;
    int flag =0;
    printf("Ingrese el ID del cliente a modificar: ");
    scanf("%d", &id);
    for(i=0; i<tam;i++)
    {
        if(id == clientes[i].id)
        {
            flag = 1;
            printf("Reingrese Nombre:");
            fflush(stdin);
            fgets(clientes[i].nombre,40,stdin);
            clientes[i].nombre[strlen(clientes[i].nombre)-1]='\0';

            break;
        }
    }
    if(flag == 0)
    {
        printf("Cliente no encontrada\n");
    }

}
/********************************************************************************************/
void modificarUnClienteApellido(eClientes clientes[], int tam)
{
    int id;
    int i;
    int flag =0;
    printf("Ingrese el ID del cliente a modificar: ");
    scanf("%d", &id);
    for(i=0; i<tam;i++)
    {
        if(id == clientes[i].id)
        {
            flag=1;
            printf("Reingrese apellido:");
            fflush(stdin);
            fgets(clientes[i].apellido,40,stdin);
            clientes[i].apellido[strlen(clientes[i].apellido)-1]='\0';
        }
    }
    if(flag == 0)
    {
        printf("cliente no encontrada\n");
    }
}
/********************************************************************************************/
void modificarUnClienteLocalidad(eClientes clientes[], int tam, eLocalidad localidad[], int tamL)
{
    int id;
    int i;
    int opcionTipo;
    int flag;
    printf("Ingrese el ID del cliente a modificar: ");
    scanf("%d", &id);
    for(i=0; i<tam;i++)
    {
        if(id == clientes[i].id)
        {
            flag = 1;
            printf ("Reingrese localidad: \n");
            int cont = 0;
            int i;
            for(i=0;i<tamL;i++)
            {
                cont++;
                printf("    %d. %s\n", cont, localidad[i].descripcion);
            }

            opcionTipo = validarOpcion(1,3);

            switch(opcionTipo)
            {
                case 1:
                    clientes[i].idLocalidad = 400;
                    break;

                case 2:
                    clientes[i].idLocalidad=401;
                    break;

                case 3:
                    clientes[i].idLocalidad=402;
                    break;
            }
        }
    }
    if(flag == 0)
    {
        printf("cliente no encontrada\n");
    }
}
/********************************************************************************************/
void modificarUnClienteTelefono(eClientes clientes[], int tam)
{
    int id;
    int i;
    int flag = 0;
    printf("Ingrese el ID del cliente a modificar: ");
    scanf("%d", &id);
    for(i=0; i<tam;i++)
    {
        if(id == clientes[i].id)
        {
            flag = 1;
            printf("Reingrese telefono:");
            fflush(stdin);
            fgets(clientes[i].telefono,40,stdin);
            clientes[i].telefono[strlen(clientes[i].telefono)-1]='\0';

            break;
        }
    }
    if(flag == 0)
    {
        printf("cliente no encontrada\n");
    }
}
/********************************************************************************************/
void modificarUnClienteEdad(eClientes clientes[], int tam)
{
    int id;
    int i;
    int flag =0;
    printf("Ingrese el ID del cliente a modificar: ");
    scanf("%d", &id);
    for(i=0; i<tam;i++)
    {
        if(id == clientes[i].id)
        {
            flag = 1;
            printf ("reingrese edad: ");
            scanf ("%d", &clientes[i].edad);

            break;
        }
    }
    if(flag == 0)
    {
        printf("cliente no encontrada\n");
    }
}
/********************************************************************************************/
void modificarUnClienteSexo(eClientes clientes[], int tam)
{
    int id;
    int i;
    int flag =0 ;
    printf("Ingrese el ID del cliente a modificar: ");
    scanf("%d", &id);
    for(i=0; i<tam;i++)
    {
        if(id == clientes[i].id)
        {
            printf ("Reingrese sexo (F o M): ");
            scanf ("%s", &clientes[i].sexo);

            while(clientes[i].sexo!='M' && clientes[i].sexo!='F')
            {
                printf ("ERROR!! Reingrese sexo (F o M): ");
                scanf ("%s", &clientes[i].sexo);
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
void promedioClientes(eClientes cliente[], int tamC)
{
    int i;
    int contadorMasculino=0 ;
    int contadorFemenino= 0;
    float promedioMasculino;
    float promedioFemenino;
    for (i=0; i<tamC ; i++)
    {
        if(cliente[i].estado==OCUPADO && cliente[i].sexo=='M')
        {
            contadorMasculino++;
        }
        else
        {
            if(cliente[i].estado==OCUPADO && cliente[i].sexo=='F')
            {
                contadorFemenino++;
            }
        }
    }
    promedioMasculino=(float)contadorMasculino/(contadorMasculino+contadorFemenino);
    promedioFemenino=(float)contadorFemenino/(contadorMasculino+contadorFemenino);

    printf("Hay %.2f hombres por cada mujer\n", promedioMasculino);
    printf("Hay %.2f mujeres por cada hombre\n\n", promedioFemenino);

}
/********************************************************************************************/
void porcentajeClientes(eClientes cliente[], int tamC)
{
    int i;
    int contadorMasculino=0 ;
    int contadorFemenino=0 ;
    int contadorTotal=0 ;
    float promedioMasculino;
    float promedioFemenino;
    for (i=0; i<tamC ; i++)
    {
        if(cliente[i].estado==OCUPADO&&cliente[i].sexo=='M')
        {
            contadorMasculino++;
        }
        else
        {
            if(cliente[i].estado==OCUPADO&&cliente[i].sexo=='F')
            {
                contadorFemenino++;
            }
        }
    }
    contadorTotal=contadorMasculino+contadorFemenino;
    promedioMasculino =(float)contadorMasculino*100/contadorTotal;

    promedioFemenino = (float)contadorFemenino*100/contadorTotal;+


    printf("un %.2f porciento de los clientes es hombre y el otro %.2f porciento son mujeres\n\n",promedioMasculino, promedioFemenino);
    system("pause");
}
/********************************************************************************************/
void clientesDelLaLocalidadSeleccionada(eClientes cliente[], int tamC, eLocalidad localidad[], int tamL)
{
    int i;
    int j;
    int opcion;
    for(i = 0; i< tamL;i++)
    {
        printf("%d. %s\n", i+1, localidad[i].descripcion);
    }

    opcion = validarOpcion(1,3);

    opcion = opcion + 399;

    printf("\n\n-----------------------------------------------------------------------------------------\n", localidad[j].descripcion);
    printf(" ID                nombre             apellido               localidad          telefono      \n");
    printf("-----------------------------------------------------------------------------------------\n");

    for(i=0;i<tamC;i++)
    {
        if(cliente[i].idLocalidad == opcion)
        {
            for(j=0;j<tamL;j++)
            {
                if(cliente[i].idLocalidad == localidad[j].id)
                {
                    printf("%4d %20s %20s %20s %20s \n" ,cliente[i].id
                                                            ,cliente[i].nombre
                                                            ,cliente[i].apellido
                                                            ,localidad[j].descripcion
                                                            ,cliente[i].telefono);

                }
            }
        }
    }
    system("pause");
}
/********************************************************************************************/
void ordenarPorLocalidadYNombre(eClientes cliente[], int tamC, eLocalidad localidad[], int tamL)
{
    int i;
    int j;
    eClientes aux;

    for(i=0; i<tamC-1; i++)
    {
        for(j=i+1; j<tamC; j++)
        {
            if(cliente[i].idLocalidad<cliente[j].idLocalidad)
            {
                aux = cliente[i];
                cliente[i] = cliente[j];
                cliente[j] = aux;
            }
            else
            {
               if(cliente[i].idLocalidad==cliente[j].idLocalidad)
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
