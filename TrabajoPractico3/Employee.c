#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#include <string.h>
#define OK 1
#define ERROR 0

Employee* employee_new()
{
    Employee* empleadoAuxiliar = (Employee*)malloc(sizeof(Employee));

    if(empleadoAuxiliar!=NULL)
    {
        employee_setId(empleadoAuxiliar,0);
        employee_setNombre(empleadoAuxiliar,"");
        employee_setSueldo(empleadoAuxiliar,0);
        employee_setHorasTrabajadas(empleadoAuxiliar,0);
    }
    return empleadoAuxiliar;

}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* empleadoAuxiliar = employee_new();

    if(empleadoAuxiliar!=NULL)
    {
        employee_setId(empleadoAuxiliar,atoi(idStr));
        employee_setNombre(empleadoAuxiliar,nombreStr);
        employee_setHorasTrabajadas(empleadoAuxiliar,atoi(horasTrabajadasStr));
        employee_setSueldo(empleadoAuxiliar,atoi(sueldoStr));
    }
    return empleadoAuxiliar;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int isOk = ERROR;
    if(this!=NULL && nombre != NULL && strlen(nombre)<127)
    {
        strcpy(this->nombre,nombre);
        isOk = OK;
    }
    return isOk;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int isOk = ERROR;
    if(this!=NULL && nombre != NULL)
    {
        strcpy(nombre,this->nombre);
        isOk = OK;
    }
    return isOk;
}



int employee_setSueldo(Employee* this,int sueldo)
{
    int isOk = ERROR;
    if(this!=NULL && sueldo > 0)
    {
        this->sueldo = sueldo;
        isOk = OK;
    }
    return isOk;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int isOk = ERROR;
    if(this!=NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        isOk = OK;
    }
    return isOk;
}

int employee_setId(Employee* this,int id)
{
    int isOk = ERROR;
    if(this!=NULL && id >= 0)
    {
        this->id = id;
        isOk = OK;
    }
    return isOk;
}
int employee_getId(Employee* this,int* id)
{
    int isOk = ERROR;
    if(this!=NULL && id != NULL)
    {
        *id = this->id;
        isOk = OK;
    }
    return isOk;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int isOk = ERROR;
    if(this!=NULL && horasTrabajadas > 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        isOk = OK;
    }
    return isOk;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int isOk = ERROR;
    if(this!=NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        isOk = OK;
    }
    return isOk;
}

int showEmployee(Employee* employee)
{
    int isOk = ERROR;
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
    if(employee!=NULL)
    {
        if(employee_getId(employee,&id) &&
                employee_getNombre(employee,nombre) &&
                employee_getHorasTrabajadas(employee,&horasTrabajadas) &&
                employee_getSueldo(employee,&sueldo))
        {
            printf("%4d %15s %8d %8d\n", id,nombre,horasTrabajadas,sueldo);
        }
        isOk = OK;
    }
    return isOk;
}


int showEmployees(LinkedList* this)
{
    int isOk =ERROR;
    int size;
    Employee* empleadoAuxiliar=NULL;

    if(this!=NULL)
    {
        size = ll_len(this);
        if(size>0)
        {
            printf("Id    Nombre    HorasTrabajadas   Sueldo\n");
            for(int i=0; i<size; i++)
            {
                empleadoAuxiliar = (Employee*)ll_get(this,i);
                showEmployee(empleadoAuxiliar);
            }
        }
        else
        {
            printf("La lista esta vacia.\n");
        }
        isOk = OK;
    }
    return isOk;
}


int employee_nextId(LinkedList* this,int* nextId)
{
    int isOk = ERROR;
    Employee* aux;
    int auxId;
    int max=0;
    int size;

    if(this!=NULL && nextId!=NULL)
    {
        size = ll_len(this);
        for(int i=0; i<size; i++)
        {
            aux = ll_get(this,i);
            employee_getId(aux,&auxId);
            if(i==0 || auxId>max)
            {
                max = auxId;
            }
        }
        *nextId = max + 1;
        isOk=OK;
    }
    return isOk;
}

int employee_findById(LinkedList* this,int id)
{
    int isOk=-1;
    int size;
    Employee* aux;
    int idAux;

    if(this!=NULL && id>0)
    {
        size = ll_len(this);
        for(int i=0; i<size; i++)
        {
            aux = ll_get(this,i);
            employee_getId(aux,&idAux);
            if(idAux == id)
            {
                isOk = i;
                break;
            }
        }
    }
    return isOk;
}


int employee_CmpId(void* e1, void* e2)
{
    int retorno = 0;
    Employee* emp1=NULL;
    Employee* emp2=NULL;

    int idEmp1;
    int idEmp2;

    if(e1!=NULL && e2!=NULL)
    {
        emp1 = (Employee*)e1;
        emp2 = (Employee*)e2;

        if(employee_getId(emp1,&idEmp1) && employee_getId(emp2,&idEmp2))
        {
            if(idEmp1 > idEmp2)
            {
                retorno = 1;
            }
            else
            {
                retorno = -1;
            }
        }

    }
    return retorno;
}

int employee_CmpNombre(void* e1, void* e2)
{
    Employee* emp1=NULL;
    Employee* emp2=NULL;

    char nombreEmp1[127];
    char nombreEmp2[127];

    int retorno;

    if(e1!=NULL && e2 != NULL)
    {
        emp1 = (Employee*)e1;
        emp2 = (Employee*)e2;

        if(employee_getNombre(emp1,nombreEmp1) && employee_getNombre(emp2,nombreEmp2))
        {
            retorno = strcmp(nombreEmp1,nombreEmp2);
        }
    }
    return retorno;
}

int employee_CmpHoursWorked(void* e1, void* e2)
{
    int retorno = 0;
    Employee* emp1=NULL;
    Employee* emp2=NULL;

    int horasTrabajadasEmp1;
    int horasTrabajadasEmp2;

    if(e1!=NULL && e2!=NULL)
    {
        emp1 = (Employee*)e1;
        emp2 = (Employee*)e2;

        if(employee_getHorasTrabajadas(emp1,&horasTrabajadasEmp1) && employee_getHorasTrabajadas(emp2,&horasTrabajadasEmp2))
        {
            if(horasTrabajadasEmp1 > horasTrabajadasEmp2)
            {
                retorno = 1;
            }
            else
            {
                retorno = -1;
            }
        }

    }
    return retorno;
}


int employee_CmpSalary(void* e1, void* e2)
{
    int retorno = 0;
    Employee* emp1=NULL;
    Employee* emp2=NULL;

    int salarioEmp1;
    int salarioEmp2;

    if(e1!=NULL && e2!=NULL)
    {
        emp1 = (Employee*)e1;
        emp2 = (Employee*)e2;

        if(employee_getSueldo(emp1,&salarioEmp1) && employee_getSueldo(emp2,&salarioEmp2))
        {

            if(salarioEmp1 > salarioEmp2)
            {
                retorno = 1;
            }
            else
            {
                retorno = -1;
            }
        }
    }
    return retorno;
}







