#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
#include "menu.h"
#include "datos.h"
#include "files.h"
#define TEXT 0
#define BIN 1

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
	setbuf(stdout,NULL);
    LinkedList* miLista = ll_newLinkedList();
    char path[100];
    char pathSave[100];
    int opcion;
    char opcionElegida = 'n';

    if(miLista == NULL)
    {
        printf("No se pudo conseguir memoria.\n");
        exit(1);
    }

    do
    {
        mostrarMenuInt("\tTrabajo practico 3.\n\n1. Cargar los datos de los empleados desde el archivo csv (modo texto).\n2. Cargar los datos de los empleados desde el archivo bin (modo binario).\n3. Alta de empleado\n4. Modificar datos de empleado\n5. Baja de empleado\n6. Listar empleados\n7. Ordenar empleados\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n10. Salir\nQue desea hacer?: ",&opcion);
        switch(opcion)
        {
        case 1:
            if(file_getAndValidatePath("Ingrese path csv: ",path,TEXT))
            {
                if(controller_loadFromText(path,miLista))
                {
                    printf("Opcion 1 con exito.\n");
                }
            }
            else
            {
                printf("Path csv invalido.\n");
            }
            break;
        case 2:
            if(file_getAndValidatePath("Ingrese path bin: ",path,BIN))
            {
                if(controller_loadFromBinary(path,miLista))
                {
                    printf("Opcion 2 con exito.\n");
                }
                else
                {
                    printf("No fue posible cargar el archivo binario.\n");
                }
            }
            else
            {
                printf("Path bin invalido.\n");
            }
            break;
        case 3:
            if(controller_addEmployee(miLista))
            {
                printf("Opcion 3 con exito.\n");
            }
            else
            {
                printf("Error en la opcion 3.\n");
            }
            break;
        case 4:
            if(ll_len(miLista)>0)
            {
                if(controller_editEmployee(miLista))
                {
                    printf("Opcion 4 con exito.\n");
                }
                else
                {
                    printf("Error en la opcion 4.\n");
                }
            }
            else
            {
                printf("Lista vacia.\n");
            }
            break;
        case 5:
            if(ll_len(miLista)>0)
            {
                if(controller_removeEmployee(miLista))
                {
                    printf("Opcion 5 con exito.\n");
                }
                else
                {
                    printf("Error en la opcion 5.\n");
                }
            }
            else
            {
                printf("Lista vacia.\n");
            }

            break;
        case 6:
            if(controller_ListEmployee(miLista))
            {
                printf("Opcion 6 con exito.\n");
            }
            else
            {
                printf("Error en la opcion 6.\n");
            }
            break;
        case 7:
            if(ll_len(miLista)>0)
            {
                if(controller_sortEmployee(miLista))
                {
                     printf("Opcion 7 con exito.\n");
                }
            }
            else
            {
            	printf("Lista vacia.\n");
            }
            break;
        case 8:
            if(ll_len(miLista)>0)
            {
                if(file_getPath("Ingrese path csv: ",pathSave))
                {
                    if(controller_saveAsText(pathSave,miLista))
                    {
                        printf("Opcion 8 con exito.\n");
                    }
                    else
                    {
                        printf("Error en la opcion 8.\n");
                    }
                }
            }
            else
            {
                printf("Lista vacia.\n");
            }
            break;
        case 9:
            if(ll_len(miLista)>0)
            {
                if(file_getPath("Ingrese path bin: ",pathSave))
                {
                    if(controller_saveAsBinary(pathSave,miLista))
                    {
                        printf("Opcion 9 con exito.\n");
                    }
                    else
                    {
                        printf("Error en la opcion 9.\n");
                    }
                }
            }
            else
            {
                printf("Lista vacia.\n");
            }
            break;
        case 10:
            getCaracter("Desea salir? s/n: ",&opcionElegida,"Error, ingrese un caracter: ","Error,ingrese s/n",'s','n');
            break;
        default:
            printf("Opcion invalida.\n");
            break;
        }
        system("pause");
    }
    while(opcionElegida!='s');
    ll_deleteLinkedList(miLista);
    return 0;
}
