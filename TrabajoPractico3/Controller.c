#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "datos.h"
#include "files.h"
#include "Controller.h"
#include "menu.h"
#define OK 1
#define ERROR 0



int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int isOk = ERROR;
    FILE* archivoText = NULL;
    char confirma;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        archivoText = fopen(path,"r");
        if(archivoText!=NULL)
        {
            if(ll_len(pArrayListEmployee)>0)
            {
                getCaracter("La lista ya contiene elementos, desea sobreescribirlos?s/n: ",&confirma,"Error ingrese un caracter: ","Error,ingrese s o n: ",'s','n');

            }
            if(confirma == 's' || ll_len(pArrayListEmployee)<=0)
            {
                parser_EmployeeFromText(archivoText,pArrayListEmployee);
            }
            fclose(archivoText);
        }
        isOk = OK;
    }

    return isOk;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int isOk = ERROR;
    FILE* archivoBin;
    char confirma;

    if(path!=NULL && pArrayListEmployee != NULL)
    {

        archivoBin = fopen(path,"rb");
        if(archivoBin!=NULL)
        {
            if(ll_len(pArrayListEmployee)>0)
            {
                getCaracter("La lista ya contiene elementos, desea sobreescribirlos?s/n: ",&confirma,"Error ingrese un caracter: ","Error,ingrese s o n: ",'s','n');
            }
            if(confirma == 's' || ll_len(pArrayListEmployee)<=0)
            {
                parser_EmployeeFromBinary(archivoBin,pArrayListEmployee);
            }
            fclose(archivoBin);
        }
        isOk = OK;
    }

    return isOk;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int isOk = ERROR;
    int nextId=0;
    Employee* nuevoEmpleado = NULL;

    char nombreAux[127];
    int enteroAux;


    if(pArrayListEmployee!=NULL)
    {
        printf("\n\t****Alta de empleado****\n");
        employee_nextId(pArrayListEmployee,&nextId);

        nuevoEmpleado = employee_new();
        employee_setId(nuevoEmpleado,nextId);

        printf("****Su id sera: %d****\n",nextId);
        getString("Ingrese su nombre: ", "Hubo un error, reingrese: ",nombreAux,127);
        while(!employee_setNombre(nuevoEmpleado,nombreAux))
        {
            getString("Hubo un error, reingrese su nombre: ", "Hubo un error, reingrese: ",nombreAux,127);
        }

        getInt("Ingrese sus horas trabajadas: ",&enteroAux,"Error, ingrese un numero: ");
        while(!employee_setHorasTrabajadas(nuevoEmpleado,enteroAux))
        {
            getInt("Hubo un error, ingrese un valor valido de horas: ",&enteroAux,"Error, ingrese un numero: ");
        }

        getInt("Ingrese su sueldo: ",&enteroAux,"Error, ingrese un numero: ");
        while(!employee_setSueldo(nuevoEmpleado,enteroAux))
        {
            getInt("Hubo un error, ingrese un valor de sueldo: ",&enteroAux,"Error, ingrese un numero: ");
        }

        ll_add(pArrayListEmployee,nuevoEmpleado);

        isOk = OK;

    }

    return isOk;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int isOk = ERROR;
    Employee* empleadoModificar=NULL;
    char opcionElegida;
    char opcionMenu;
    int id;
    int index;

    int enteroAux;
    char nombreAux[128];

    if(pArrayListEmployee!=NULL)
    {
        printf("\n\t****Modificacion de empleado****\n");
        controller_ListEmployee(pArrayListEmployee);


        getInt("Elija el ID del empleado que desea modificar: ",&id,"Error,Ingrese un numero");
        index = employee_findById(pArrayListEmployee,id);
        while(index < ERROR)
        {
            getInt("Error,elija otra vez el ID del empleado que desea eliminar: ",&id,"Error,Ingrese un numero");
            index = employee_findById(pArrayListEmployee,id);
        }
        empleadoModificar = (Employee*)ll_get(pArrayListEmployee,index);


        printf("\n\nId    Nombre    HorasTrabajadas   Sueldo\n");

        showEmployee(empleadoModificar);
        getCaracter("Desea modificar este empleado?: ",&opcionElegida,"Error,ingrese un caracter","Error, ingrese s o n: ",'s','n');
        if(opcionElegida == 's')
        {
            do
            {
                printf("\nId    Nombre    HorasTrabajadas   Sueldo\n");
                showEmployee(empleadoModificar);
                mostrarMenuChar("A. Nombre\nB. HorasTrabajadas\nC. Sueldo\nD. Salir\nQue desea hacer?: ",&opcionMenu);
                switch(opcionMenu)
                {
                case 'a':
                    getString("Ingrese su nombre: ", "Hubo un error, reingrese",nombreAux,128);
                    while(!employee_setNombre(empleadoModificar,nombreAux))
                    {
                        getString("Hubo un error, reingrese su nombre: ", "Hubo un error, reingrese",nombreAux,128);
                    }
                    break;
                case 'b':
                    getInt("Ingrese sus horas trabajadas: ",&enteroAux,"Error, ingrese un numero");
                    while(!employee_setHorasTrabajadas(empleadoModificar,enteroAux))
                    {
                        getInt("Hubo un error, ingrese un valor valido de horas: ",&enteroAux,"Error, ingrese un numero");
                    }
                    break;
                case 'c':
                    getInt("Ingrese su sueldo: ",&enteroAux,"Error, ingrese un numero");
                    while(!employee_setSueldo(empleadoModificar,enteroAux))
                    {
                        getInt("Hubo un error, ingrese un valor de sueldo",&enteroAux,"Error, ingrese un numero");
                    }
                    break;
                case 'd':
                    getCaracter("Desea salir? s/n: ",&opcionMenu,"Error, ingrese un caracter: ","Error,ingrese s/n",'s','n');
                    break;
                default:
                    printf("Opcion invalida\n");
                    break;
                }
            }
            while(opcionMenu != 's');
        }
        else
        {
            printf("Modificacion cancelada.\n");
        }
        isOk = OK;
    }


    return isOk;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int isOk = ERROR;
    int id;
    int index;
    Employee* empleadoEliminar=NULL;
    char opcionElegida;

    if(pArrayListEmployee!=NULL)
    {
        printf("\n\t****Baja de empleado****\n");
        controller_ListEmployee(pArrayListEmployee);

        getInt("Elija el ID del empleado que desea eliminar: ",&id,"Error,Ingrese un numero");
        index = employee_findById(pArrayListEmployee,id);

        while(index < ERROR)
        {
            getInt("Error,elija otra vez el ID del empleado que desea eliminar: ",&id,"Error,Ingrese un numero");
            index = employee_findById(pArrayListEmployee,id);
        }
        empleadoEliminar = (Employee*)ll_get(pArrayListEmployee,index);

        system("cls");
        printf("Id    Nombre    HorasTrabajadas   Sueldo\n");

        showEmployee(empleadoEliminar);
        getCaracter("Desea eliminar este empleado?: ",&opcionElegida,"Error,ingrese un caracter","Error, ingrese s o n",'s','n');
        if(opcionElegida == 's')
        {
            ll_remove(pArrayListEmployee,index);
        }
        else
        {
            printf("Baja cancelada.\n");
        }
        isOk = OK;

    }
    return isOk;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int isOk = ERROR;

    if(pArrayListEmployee!=NULL)
    {
        showEmployees(pArrayListEmployee);
        isOk=OK;
    }

    return isOk;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int isOk = ERROR;
    int option;
    int order;
    if(pArrayListEmployee!=NULL)
    {
        printf("\n\tOrdenamiento.\n");
        getEntero("1. ID\n2. Nombre\n3. Horas trabajadas\n4. Sueldo\nComo desea ordenar?: ",&option,"Error, ingrese un numero","Error, ingrese un numero entre 1 y 4",1,4);
        getEntero("\n0. Descendente\n1. Ascendente\nComo desea ordenar?: ",&order,"Error, ingrese un numero","Error, ingrese un numero entre 0 y 1",0,1);
        switch(option)
        {
        case 1:
            ll_sort(pArrayListEmployee,employee_CmpId,order);
            break;
        case 2:
            ll_sort(pArrayListEmployee,employee_CmpNombre,order);
            break;
        case 3:
            ll_sort(pArrayListEmployee,employee_CmpHoursWorked,order);
            break;
        case 4:
            ll_sort(pArrayListEmployee,employee_CmpSalary,order);
            break;
        }

        isOk = OK;
    }
    return isOk;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int isOk = ERROR;
    FILE* archivoTexto;
    char respuesta;

    Employee* empleadoAuxiliar;
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;

    if(path!=NULL && pArrayListEmployee != NULL)
    {
        if(file_verifyPathText(path))
        {
            getCaracter("\n*****CUIDADO*****\n\nEste archivo ya existe. Desea sobreescribir los cambios?s/n: ",&respuesta,"Error, ingrese un caracter: ","Error,ingrese s o n: ",'s','n');
        }
        if(!file_verifyPathText(path) || respuesta == 's')
        {
            archivoTexto = fopen(path,"w");

            if(archivoTexto!=NULL)
            {
                fprintf(archivoTexto,"id,nombre,horasTrabajadas,sueldo\n");
                for(int i=0; i<ll_len(pArrayListEmployee); i++)
                {
                    empleadoAuxiliar = (Employee*)ll_get(pArrayListEmployee,i);

                    if(employee_getId(empleadoAuxiliar,&id) &&
                            employee_getNombre(empleadoAuxiliar,nombre) &&
                            employee_getHorasTrabajadas(empleadoAuxiliar,&horasTrabajadas) &&
                            employee_getSueldo(empleadoAuxiliar,&sueldo))
                    {
                        fprintf(archivoTexto,"%d,%s,%d,%d\n", id,nombre,horasTrabajadas,sueldo);
                    }
                }
                fclose(archivoTexto);
            }
        }

        isOk = OK;
    }

    return isOk;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int isOk = ERROR;
    FILE* archivoBinario;
    char respuesta;

    Employee* empleadoAuxiliar;


    if(path!=NULL && pArrayListEmployee != NULL)
    {
        if(file_verifyPathBinary(path))
        {
            getCaracter("*****CUIDADO*****\nEste archivo ya existe. Desea sobreescribir los cambios?s/n: ",&respuesta,"Error, ingrese un caracter: ","Error,ingrese s o n: ",'s','n');
        }

        if(!file_verifyPathText(path) || respuesta == 's')
        {
            archivoBinario = fopen(path,"wb");
            if(archivoBinario!=NULL)
            {
                for(int i=0; i<ll_len(pArrayListEmployee); i++)
                {
                    empleadoAuxiliar = (Employee*)ll_get(pArrayListEmployee,i);

                    fwrite(empleadoAuxiliar,sizeof(Employee),1,archivoBinario);

                }
                fclose(archivoBinario);
            }

        }

        isOk = OK;
    }

    return isOk;
}
