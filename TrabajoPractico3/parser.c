#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include <string.h>
#define OK 1
#define ERROR 0

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int isOk = ERROR;
    Employee* empleadoAux;
    char id[20];
    char nombre[128];
    char horasTrabajadas[20];
    char sueldo[20];


    if(pFile!=NULL && pArrayListEmployee != NULL)
    {
        ll_clear(pArrayListEmployee);
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo); // Falsa lectura.
        while(!feof(pFile))
        {
            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo)==4)
            {
                empleadoAux = employee_newParametros(id,nombre,horasTrabajadas,sueldo);
                ll_add(pArrayListEmployee,empleadoAux);
            }
            else
            {
                break;
            }
        }
        isOk = OK;
    }
    return isOk;

}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int isOk = ERROR;
    Employee* empleadoAux=NULL;


    if(pFile != NULL && pArrayListEmployee !=NULL)
    {
        ll_clear(pArrayListEmployee);
        while(!feof(pFile))
        {
            empleadoAux = employee_new();
            if(fread(empleadoAux,sizeof(Employee),1,pFile)<1)
            {
                break;
            }
            else
            {
                ll_add(pArrayListEmployee,empleadoAux);
                empleadoAux = NULL;
            }
        }
        isOk = OK;
    }

    return isOk;
}
