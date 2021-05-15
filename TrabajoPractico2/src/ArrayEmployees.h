/*
 * ArrayEmployees.h
 *
 *  Created on: 15 may. 2021
 *      Author: Ezequiel Perez
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

typedef struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}eEmployee;


/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(eEmployee list[], int len);








/** \brief Modify an employee
 *
 * \param list eEmployee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int modifyEmployee(eEmployee* list,int len);



/** \brief Get data from an employee
 *
 * \param list eEmployee*
 * \param len int
 * \param nextId int*
 * \return int
 *
 */
int createEmployee(eEmployee* list, int len,int* nextId);



/** \brief print an employee of the employees array
 *
 * \param received eEmployee employee received
 * \return void
 *
 */
void printEmployee(eEmployee received);



/** \brief Count the employees on the list
 *
 * \param list eEmployee* Pointer to array of employees
 * \param len int Array length
 * \param cont int* Pointer to count
 * \return int Return (-1) if Error [Invalid length or NULL pointers] - (0) if Ok
 *
 */
int Countemployees(eEmployee* list, int len,int* cont);



/** \brief print the content of employees array and remove a Employee by Id
 *
 * \param list eEmployee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointers] - (0) if Ok
 *
 */
int printRemoveEmployees(eEmployee* list, int len);



/** \brief Get sort order
 *
 * \param value int* pointer of value
 * \return int Return (-1) if Error [NULL pointer] - (0) if Ok
 *
 */
int getOrder(int* value);





/** \brief Calculate and return total salaries
 *
 * \param list eEmployee* Pointer to array of employees
 * \param len int Array length
 * \param value float* Pointer to calculated value
 * \return int Return (-1) if Error [Invalid length or NULL pointers] - (0) if Ok
 *
 */
int calculateTotalSalaries(eEmployee* list, int len, float* value);



/** \brief Calculate and return the average number of employees
 *
 * \param list eEmployee* Pointer to array of employees
 * \param len int Array length
 * \param value float* Pointer to calculated value
 * \return int Return (-1) if Error [Invalid length or NULL pointers] - (0) if Ok
 *
 */
int calculatePromedySalaries(eEmployee* list, int len, float* value);



/** \brief Calculate and return the number of employees who exceed the average salary
 *
 * \param list eEmployee* Pointer to array of employees
 * \param len int Array length
 * \param value int* Puntero al valor del contador
 * \return int Return (-1) if Error [Invalid length or NULL pointers] - (0) if Ok
 *
 */
int employeesExceedAverageSalarys(eEmployee* list, int len, int* cont);




/** \brief Print calculated reports
 *
 * \param list eEmployee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int printInformes(eEmployee* list,int len);



/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 *
 */

int addEmployee(eEmployee list[], int len, int id, char name[],char
lastName[],float salary,int sector);




/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(eEmployee* list, int len,int id);



/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(eEmployee* list, int len, int id);



/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(eEmployee* list, int len, int order);


/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int printEmployees(eEmployee* list, int length);

#endif /* ARRAYEMPLOYEES_H_ */
