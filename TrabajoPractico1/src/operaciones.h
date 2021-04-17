/*
 * operaciones.h
 *
 *  Created on: 12 abr. 2021
 *      Author: ezequ
 */

#ifndef OPERACIONES_H_
#define OPERACIONES_H_

/** \brief Realiza la operacion suma
 *
 * \param numeroUno int Recibe el primer operando
 * \param numeroDos int Recibe el segundo operando
   \param resultado int Recibe un puntero donde se almacena el resultado
 * \return int Retorna 0 si el puntero que recibe es NULL de lo contrario devuelve 1
 *
 */
int suma(int numeroUno, int numeroDos, int* resultado);



/** \brief Realiza la operacion resta
 *
 * \param numeroUno int Recibe el primer operando
 * \param numeroDos int Recibe el segundo operando
   \param resultado int Recibe un puntero donde se almacena el resultado
 * \return int Retorna 0 si el puntero que recibe es NULL de lo contrario devuelve 1
 *
 */
int resta(int numeroUno, int numeroDos,int* resultado);




/** \brief Realiza la operacion multiplicacion
 *
 * \param numeroUno int Recibe el primer operando
 * \param numeroDos int Recibe el segundo operando
   \param resultado int Recibe un puntero y ahi donde se almacena el resultado
 * \return int Retorna 0 si el puntero que recibe es NULL de lo contrario devuelve 1
 *
 */
int multiplicacion(int numeroUno, int numeroDos, int* resultado);





/** \brief Realiza la operacion division
 *
 * \param numeroUno int Recibe el primer operando
 * \param numeroDos int Recibe el segundo operando
   \param resultado int Recibe un puntero, donde se almacena el resultado
 * \return int Retorna 0 si el puntero que recibe es NULL y el parametro "numeroDos" es igual a 0, de lo contrario devuelve 1
 *
 */
int division(int numeroUno, int numeroDos, float* resultado);




/** \brief Realiza el factorial
 *
 * \param numeroRecibido int Recibe el operando
   \param resultado int Recibe un puntero, donde se almacena el resultado
 * \return int Retorna 0 si el puntero que recibe es NULL y si el numero que recibe por parametros es menor a 0, de lo contrario devuelve 1
 *
 */
int factorial(int numeroRecibido, long int* resultado);


#endif /* OPERACIONES_H_ */
