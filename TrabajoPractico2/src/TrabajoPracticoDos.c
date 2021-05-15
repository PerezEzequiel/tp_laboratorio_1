/*
 ============================================================================
 Name        : TrabajoPracticoDos.c
 Author      : Ezequiel Perez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "menu.h"
#include "datos.h"
#define ERROR -1
#define OK 0
#define LEN 1000


int main()
{
	setbuf(stdout, NULL);
    int returnMenu;
    char flag = 'n';

    int returnMenuInform;
    char flagInform = 'n';


    int nextId=1000;

    int cont=0;

    int valueOrder;

    eEmployee listEmployee[LEN];
    initEmployees(listEmployee,LEN);


    do
    {
        if(Countemployees(listEmployee,LEN,&cont)==OK)
        {

            mostrarMenu("\nAbm Empleados.\n\n1. Alta de empleado\n2. Modificar empleado\n3. Baja de Empleado\n4. Informar\n5. Salir\nQue desea hacer?: ",&returnMenu);
            switch(returnMenu)
            {
            case 1:
                if(createEmployee(listEmployee,LEN,&nextId)==OK)
                {
                    printf("\nAlta exitosa!!\n\n");
                }
                else
                {
                    printf("\nPrimero cargue un empleado\n\n");
                }
                break;
            case 2:
                if(cont > 0 && modifyEmployee(listEmployee,LEN)==OK)
                {
                    printf("\nModificacion exitosa!!\n\n");
                }
                else
                {
                    printf("\nPrimero cargue un empleado\n\n");
                }
                break;
            case 3:
                if(cont>0 && printRemoveEmployees(listEmployee,LEN)==OK)
                {
                    printf("\nBaja exitosa!!\n\n");
                }
                else
                {
                    printf("\nPrimero cargue un empleado\n\n");
                }
                break;
            case 4:
                if(cont>0)
                {
                    flagInform = 'n';
                    do
                    {
                        mostrarMenu("\nInformes.\n\n1. Listado de los empleados ordenados alfabeticamente por Apellido y Sector\n2. Total y promedio de los salarios, y cuantos empleados superan el salario promedio\n3. Salir de informes\nQue desea hacer?: ",&returnMenuInform);
                        switch(returnMenuInform)
                        {
                        case 1:
                            if(getOrder(&valueOrder)==OK && sortEmployees(listEmployee,LEN,valueOrder)==OK)
                            {
                                if(valueOrder == 1)
                                {
                                    printf("\nLista ordenada ascendentemente.\n\n");
                                }
                                else
                                {
                                    printf("\nLista ordenada descendentemente.\n\n");
                                }
                                printEmployees(listEmployee,LEN);
                                system("pause");
                            }
                            break;
                        case 2:
                            printInformes(listEmployee,LEN);
                            system("pause");
                            break;
                        case 3:
                            getCaracter("Desea salir?s/n:",&flagInform,"Error, ingrese un caracter: ","Error ingrese s/n",'s','n');
                            break;
                        }

                    }while(flagInform != 's');
                }
                else
                {
                    printf("\nPrimero cargue un empleado\n\n");
                }

                break;
            case 5:
                getCaracter("Desea salir?s/n:",&flag,"Error, ingrese un caracter: ","Error ingrese s/n",'s','n');
                break;

            }
            cont = 0;
            system("pause");
        }
        else
        {
            printf("Hubo un error al querer contar los empleados\n");
            flag = 's';
        }
    }while(flag != 's');

    return 0;
}
