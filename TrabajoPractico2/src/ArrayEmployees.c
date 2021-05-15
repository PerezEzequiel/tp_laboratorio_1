/*
 * ArrayEmployees.c
 *
 *  Created on: 15 may. 2021
 *      Author: Ezequiel Perez
 */
#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "datos.h"
#include "menu.h"
#include <string.h>
#define ERROR -1
#define OK 0
#define TRUE 1
#define FALSE 0
#define TAMNAME 51

int initEmployees(eEmployee* list, int len)
{
    int i;
    int isOk = ERROR;

    if(list!=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            list[i].isEmpty = TRUE;
        }
        isOk = OK;
    }
    return isOk;
}
int Countemployees(eEmployee* list, int len,int* cont)
{
    int retorno = ERROR;
    if(list!=NULL && len > 0 && cont != NULL)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty == FALSE)
            {
                *cont = *cont+1;
            }
        }
        retorno = OK;
    }
    return retorno;
}

int searchFreeIndex(eEmployee* list, int len)
{
    int i;
    int index = ERROR;


    if(list!=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty == TRUE)
            {
                index = i;
                break;
            }

        }
    }

    return index;
}

int createEmployee(eEmployee* list, int len,int* nextId)
{
    int isOk = ERROR;
    eEmployee employeeAux;

    if(list!=NULL && len>0 && nextId)
    {
        printf("\nAlta empleados.\n\n");

        printf("Su proximo id va a ser: %d", *nextId);
        getString("\nIngrese nombre: ","Error, ingrese algo mas corto o solo letras",employeeAux.name,TAMNAME);
        getString("\nIngrese apellido: ","Error, ingrese algo mas corto o solo letras",employeeAux.lastName,TAMNAME);


        getFloat("\nIngrese su salario: ",&employeeAux.salary,"Error, ingrese un numero");
        while(employeeAux.salary<=0)
        {
            printf("Usted ingreso un salario igual o menor a 0 y eso no es posible\n");
            getFloat("Ingrese su salario: ",&employeeAux.salary,"Error, ingrese un numero");
        }

        getInt("\nIngrese su sector: ", &employeeAux.sector,"Error, ingrese un numero");
        while(employeeAux.sector<=0)
        {
            printf("Usted ingreso un sector igual o menor a 0 y eso no es posible\n");
            getInt("Ingrese su sector: ", &employeeAux.sector,"Error, ingrese un numero");
        }

        employeeAux.id = *nextId;

        if(addEmployee(list,len,employeeAux.id,employeeAux.name,employeeAux.lastName,employeeAux.salary,employeeAux.sector)==OK)
        {
            *nextId = *nextId + 1;
            isOk = OK;
        }
        else
        {
            printf("Se encontro un problema al buscar lugar\n\n");
        }
    }


    return isOk;

}

int addEmployee(eEmployee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
    int isOk=ERROR;
    int index;

    if(list!=NULL && len>0 && id>=100 && name!= NULL && lastName != NULL && salary > 0)
    {
        index = searchFreeIndex(list,len);
        if(index != ERROR)
        {
            list[index].id = id;
            strcpy(list[index].name,name);
            strcpy(list[index].lastName,lastName);
            list[index].salary = salary;
            list[index].sector = sector;
            list[index].isEmpty = FALSE;
            isOk = OK;
        }
    }
    return isOk;
}

void printEmployee(eEmployee received)
{
    printf("%5d %15s %15s %18.2f %13d\n", received.id, received.name,received.lastName,received.salary,received.sector);
}


int printEmployees(eEmployee* list, int length)
{
    int isOk=ERROR;
    char flag= 'n';
    if(list!=NULL && length>0)
    {
        printf("\nLista De Empleados.\n\n");
        printf("  ID          NOMBRE          APELLIDO          SALARIO          SECTOR\n");
        for(int i=0; i<length; i++)
        {
            if(list[i].isEmpty == FALSE)
            {
                printEmployee(list[i]);
                flag = 's';
            }
        }
        if(flag == 's')
        {
            isOk=OK;
        }
        else
        {
            printf("\n\nNo hay empleados cargados en la lista para mostrar\n\n");
        }
        printf("\n\n");
    }
    return isOk;
}

int findEmployeeById(eEmployee* list, int len,int id)
{
    int index = ERROR;
    if(list!=NULL && len > 0)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].id == id)
            {
                index = i;
                break;
            }
        }
    }
    return index;
}


int modifyEmployee(eEmployee* list,int len)
{
    int isOk=ERROR;
    int index;
    int id;
    char answer;
    int answerMenu;
    char flagMenu='n';
    //char flagModify='n';
    eEmployee employeeAux;



    if(list!=NULL && len>0)
    {
        printf("\nModificacion de empleados.\n\n");
        if(printEmployees(list,len)==OK)
        {
            getInt("Ingrese el ID del empleado que desea modificar: ",&id,"Error,ingrese un numero");
            index = findEmployeeById(list,len,id);
            while(index == ERROR)
            {
                getInt("Error,ese ID no existe en la lista\nIngrese el ID del empleado que desea modificar: ",&id,"Error,ingrese un numero");
                index = findEmployeeById(list,len,id);
            }
            printf("\n\n\n  ID          NOMBRE          APELLIDO          SALARIO          SECTOR\n");
            printEmployee(list[index]);
            getCaracter("\nDesea modificar este empleado?s/n: ",&answer,"Error, ingrese un caracter: ","Error ingrese s/n",'s','n');
            if(answer == 's')
            {
                employeeAux = list[index];
                do
                {
                    printf("  ID             NOMBRE       APELLIDO           SALARIO       SECTOR\n");
                    printEmployee(employeeAux);
                    mostrarMenu("\n\n1.Nombre\n2.Apellido\n3.Salario\n4.Sector\n5.Salir\nQue desea modificar?: ",&answerMenu);
                    switch(answerMenu)
                    {
                    case 1:
                        getString("\nIngrese nombre: ","Error, ingrese algo mas corto o solo letras",employeeAux.name,TAMNAME);
                        break;
                    case 2:
                        getString("\nIngrese apellido: ","Error, ingrese algo mas corto o solo letras",employeeAux.lastName,TAMNAME);
                        break;
                    case 3:
                        getFloat("\nIngrese su salario: ",&employeeAux.salary,"Error, ingrese un numero");
                        while(employeeAux.salary<=0)
                        {
                            printf("Usted ingreso un salario igual o menor a 0 y eso no es posible\n");
                            getFloat("Ingrese su salario: ",&employeeAux.salary,"Error, ingrese un numero");
                        }

                        break;
                    case 4:

                        getInt("\nIngrese su sector: ", &employeeAux.sector,"Error, ingrese un numero");
                        while(employeeAux.sector<=0)
                        {
                            printf("Usted ingreso un sector igual o menor a 0 y eso no es posible\n");
                            getInt("Ingrese su sector: ", &employeeAux.sector,"Error, ingrese un numero");
                        }
                        break;
                    case 5:
                        getCaracter("\nDesea salir?s/n: ",&flagMenu,"Error, ingrese un caracter: ","Error ingrese s/n",'s','n');
                        if(flagMenu == 's')
                        {
                            getCaracter("\nDesea impactar estos cambios?s/n: ",&flagMenu,"Error, ingrese un caracter: ","Error ingrese s/n",'s','n');
                            if(flagMenu == 's')
                            {
                                list[index] = employeeAux;

                            }
                            else
                            {
                                printf("No se impactaron estos cambios\n");
                            }
                            flagMenu = 's';
                        }
                        break;
                    default:
                        printf("No existe esa opcion\n");
                        break;
                    }
                }
                while(flagMenu !='s');

            }
            else
            {
                printf("\nModificacion cancelada\n");
            }

        }
        isOk = OK;

    }
    return isOk;
}


int printRemoveEmployees(eEmployee* list, int len)
{
    int isOk = ERROR;
    int id;

    if(list!=NULL && len > 0)
    {
        printf("\nBaja de empleados. \n\n");
        printEmployees(list,len);

        getInt("Ingrese el id del empleado que desea dar de baja: ", &id,"Error,Ingrese un numero");

        while(removeEmployee(list,len,id)!=OK)
        {
            getInt("Error, Ingrese un id valido\nIngrese el id del empleado que desea dar de baja: ", &id,"Error,Ingrese un numero");
        }
        isOk = OK;

    }
    return isOk;
}


int removeEmployee(eEmployee* list, int len, int id)
{
    int isOk=ERROR;
    int indice;
    char flag;

    if(list!=NULL && len>0)
    {
        indice = findEmployeeById(list,len,id);
        if(indice != ERROR)
        {
            printf("\n\n");
            printEmployee(list[indice]);
            getCaracter("\n\nDesea dar de baja este empleado?s/n: ",&flag,"Error, ingrese un caracter: ","Error ingrese s/n",'s','n');
            if(flag == 's')
            {
                list[indice].isEmpty = TRUE;

            }
            else
            {
                printf("\nBaja cancelada\n");
            }
            isOk = OK;
        }
    }
    return isOk;
}


int getOrder(int* value)
{
    int isOk = ERROR;
    if(value!=NULL)
    {
        if(getEntero("\nIngrese el orden del ordenamiento\n0. Descendente\n1. Ascendente\nIngrese uno de estos valores: ",value,"Error, ingrese un numero","Error ingrese 1 o 0",0,1)==1)
        {
            isOk = OK;
        }
    }
    return isOk;
}

int sortEmployees(eEmployee* list, int len, int order)
{
    int isOk = ERROR;
    eEmployee employeeAux;

    if(list!=NULL && len > 0)
    {
        for(int i=0; i<len-1; i++)
        {
            for(int j=i+1; j<len; j++)
            {
                if((order == 1 && strcmp(list[i].lastName,list[j].lastName)>0) || (order == 1 && strcmp(list[i].lastName,list[j].lastName)==0 && list[i].sector > list[j].sector))
                {
                    employeeAux = list[i];
                    list[i] = list[j];
                    list[j] = employeeAux;
                }
                else if((order == 0 && strcmp(list[i].lastName,list[j].lastName)<0) || (order == 0 && strcmp(list[i].lastName,list[j].lastName)==0 && list[i].sector < list[j].sector))
                {
                    employeeAux = list[i];
                    list[i] = list[j];
                    list[j] = employeeAux;
                }
            }
        }
        isOk = OK;
    }
    return isOk;

}

int calculateTotalSalaries(eEmployee* list, int len, float* value)
{
    int isOk=ERROR;

    if(list!=NULL && len > 0 && value != NULL)
    {
        for(int i=0;i<len;i++)
        {
            if(list[i].isEmpty == FALSE)
            {
                *value = *value + list[i].salary;
            }
        }

        isOk = OK;
    }
    return isOk;
}

int calculatePromedySalaries(eEmployee* list, int len, float* value)
{
    int isOk=ERROR;
    float salaries;
    int cont=0;

    *value = 0;

    if(list!=NULL && len>0)
    {
        if(calculateTotalSalaries(list,len,&salaries)==OK && Countemployees(list,len,&cont) == OK)
        {
            *value = salaries / cont;
        }
        isOk = OK;
    }
    return isOk;
}

int employeesExceedAverageSalarys(eEmployee* list, int len, int* cont)
{
    int isOk=ERROR;
    float value;


    if(list!=NULL && len > 0 && cont != NULL)
    {
        if(calculatePromedySalaries(list,len,&value)==OK)
        {
            for(int i=0;i<len;i++)
            {
                if(list[i].salary >= value && list[i].isEmpty == FALSE)
                {
                    *cont = *cont + 1;
                }
            }
            isOk = OK;
        }
    }
    return isOk;
}

int printInformes(eEmployee* list,int len)
{
    int isOk=ERROR;
    float total=0;
    float promedy=0;
    int contador=0;

    if(list != NULL && len > 0 && calculateTotalSalaries(list,len,&total) == OK && calculatePromedySalaries(list,len,&promedy)==OK && employeesExceedAverageSalarys(list,len,&contador)==OK)
    {
        printf("El total de los salarios es: %.2f\nEl promedio de los salarios es: %.2f\nLa cantidad de empleados que superan el promedio es: %d\n\n",total,promedy,contador);
        isOk = OK;

    }
    return isOk;
}


