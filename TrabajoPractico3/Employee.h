#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "LinkedList.h"
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief Reserva un empleado en la memoria dinamica
 *
 * \return Employee* Retorna un puntero a la memoria asignada por el sistema, si, el sistema no pudo conseguir memoria, retorna NULL
 *
 */
Employee* employee_new();


/** \brief Reserva un empleado en la memoria dinamica y, carga los valores recibidos por parametros
 *
 * \param idStr char* Id recibido.
 * \param nombreStr char* Nombre recibido.
 * \param horasTrabajadasStr char* Horas recibidas.
 * \param sueldoStr char* Sueldo recibido.
 * \return Employee* Employee* Retorna un puntero a empleado cargado con los parametros recibidos y reservado en la memoria asignada por el sistema. Si, el sistema no pudo conseguir memoria  retorna NULL
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);


void employee_delete();



/** \brief Setea el id recibido en el puntero a empleado recibido.
 *
 * \param this Employee* Puntero a empleado.
 * \param id int Id a setear.
 * \return int Devuelve 0 si, el puntero es igual a NULL o si el id recibido es igual o menor a 0. Si pudo setear correctamente devuelve 1.
 *
 */
int employee_setId(Employee* this,int id);



/** \brief Obtiene del empleado recibido, su id.
 *
 * \param this Employee* Puntero a empleado.
 * \param id int* Puntero a id.
 * \return int Retorna 0 si, los punteros son diferente de NULL, de lo contrario retorna 1.
 *
 */
int employee_getId(Employee* this,int* id);






/** \brief Setea el Nombre recibido en el puntero a empleado recibido.
 *
 * \param this Employee* Puntero a empleado.
 * \param nombre char* Nombre a setear.
 * \return int Devuelve 0 si, los punteros son igual a NULL o, si el nombre contiene mas/igual de 128 caracteres. Si pudo setear correctamente devuelve 1.
 *
 */
int employee_setNombre(Employee* this,char* nombre);


/** \brief Obtiene del empleado recibido, su nombre.
 *
 * \param this Employee* Puntero a empleado.
 * \param nombre char* Puntero a almacenar.
 * \return int Retorna 0 si, los punteros son diferente de NULL, de lo contrario retorna 1.
 *
 */
int employee_getNombre(Employee* this,char* nombre);







/** \brief Setea las horas recibidas en el puntero a empleado recibido.
 *
 * \param this Employee* Puntero a empleado.
 * \param horasTrabajadas int Horas a setear.
 * \return int Devuelve 0 si, el puntero es igual a NULL o si las horas recibidas son igual o menor a 0. Si pudo setear correctamente devuelve 1.
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/** \brief Obtiene del empleado recibido, sus horas trabajadas.
 *
 * \param this Employee* Puntero a empleado.
 * \param horasTrabajadas int* Puntero a horas trabajadas.
 * \return int Retorna 0 si, los punteros son diferente de NULL, de lo contrario retorna 1.
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);





/** \brief Setea el sueldo recibido en el puntero a empleado recibido.
 *
 * \param this Employee* Puntero a empleado.
 * \param sueldo int Sueldo a setear.
 * \return int Devuelve 0 si, el puntero es igual a NULL o si el sueldo recibido son igual o menor a 0. Si pudo setear correctamente devuelve 1.
 *
 */
int employee_setSueldo(Employee* this,int sueldo);

/** \brief Obtiene del empleado recibido, su sueldo.
 *
 * \param this Employee* Puntero a empleado.
 * \param sueldo int* Puntero a horas trabajadas.
 * \return int Retorna 0 si, los punteros son diferente de NULL, de lo contrario retorna 1.
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);



/** \brief Busca un empleado por su id.
 *
 * \param this LinkedList* Lista recibida.
 * \param id int id a buscar.
 * \return int Retorna -1 si, la lista es igual a NULL o, si el id es menor a 0 o, si no encontro lugar. Si encontro lugar, devuelve la posicion.
 *
 */
int employee_findById(LinkedList* this,int id);


/** \brief Busca, en la lista, el id mas grande para asignar el nuevo id.
 *
 * \param this LinkedList* Lista recibida.
 * \param nextId int* Next id devuelto con el nuevo id.
 * \return int Retorna 0 si los punteros son igual a NULL, de lo contrario, retorna 1.
 *
 */
int employee_nextId(LinkedList* this,int* nextId);



/** \brief Compara dos empleados por nombre.
 *
 * \param e1 void* Puntero a void, luego se castea empleado(emp1).
 * \param e2 void* Puntero a void, luego se castea empleado(emp2).
 * \return int retorna -1 si emp2 es mayor a emp1, retorna 0 si, son iguales, si emp1 es mayor a emp2 retorna 1.
 *
 */
int employee_CmpNombre(void* e1, void* e2);




/** \brief Compara dos empleados por su id.
 *
 * \param e1 void* Puntero a void, luego se castea empleado(emp1).
 * \param e2 void* Puntero a void, luego se castea empleado(emp2).
 * \return int retorna -1 si emp2 es mayor a emp1, retorna 0 si son iguales o, si los punteros recibidas son igual a NULL,retorna 1 si, emp1 es mayor a emp2.
 *
 */
int employee_CmpId(void* e1, void* e2);


/** \brief Compara dos empleados por sus horas trabajadas.
 *
 * \param e1 void* Puntero a void, luego se castea empleado(emp1).
 * \param e2 void* Puntero a void, luego se castea empleado(emp2).
 * \return int retorna -1 si emp2 es mayor a emp1, retorna 0 si son iguales o, si los punteros recibidas son igual a NULL,retorna 1 si, emp1 es mayor a emp2.
 *
 */
int employee_CmpHoursWorked(void* e1, void* e2);



/** \brief Compara dos empleados por su salario.
 *
 * \param e1 void* Puntero a void, luego se castea empleado(emp1).
 * \param e2 void* Puntero a void, luego se castea empleado(emp2).
 * \return int retorna -1 si emp2 es mayor a emp1, retorna 0 si son iguales o, si los punteros recibidas son igual a NULL,retorna 1 si, emp1 es mayor a emp2.
 *
 */
int employee_CmpSalary(void* e1, void* e2);











/** \brief Muestra un empleado.
 *
 * \param employee Employee* Puntero del empleado a mostrar.
 * \return int Retorna 0 si, el empleado recibido es igual a NULL, de lo contrario retorna 1.
 *
 */
int showEmployee(Employee* employee);


/** \brief Muestra la lista de empleados.
 *
 * \param this LinkedList* Lista recibida.
 * \return int Retorna 0 si, la lista es igual a NULL, de lo contrario retorna 1.
 *
 */
int showEmployees(LinkedList* this);



#endif // employee_H_INCLUDED

