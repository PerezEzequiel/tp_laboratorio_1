/*
 * pedirDatos.h
 *
 *  Created on: 13 abr. 2021
 *      Author: ezequ
 */

#ifndef PEDIRDATOS_H_
#define PEDIRDATOS_H_


/** \brief Valida si lo que recibe es un numero.
 *
 * \param numero[] char Recibe una cadena de caracteres a analizar.
 * \return int Devuelve 0 si no es un numero o si el parametro recibido es igual a NULL. Si es un numero y si el puntero es diferente de NULL, devuelve un 1.
 *
 */
int esNumero(char numero[]);




/** \brief Pide y almacena, en un puntero, un entero.
 *
 * \param mensaje[] char Mensaje a mostrar para pedir el entero.
 * \param resultado int* Recibe un puntero del entero donde se va a almacenar el dato.
 * \param mensajeError[] char Mensaje de error, se implementa si, lo que ingreso el usuario, no es un numero.
 * \return int Devuelve 0 si los parametros son NULL, si esta todo correcto devuelve 1.
 *
 */
int getInt(char mensaje[], int* resultado,char mensajeError[]);



/** \brief Analiza si lo que recibe es una letra o un numero.
 *
 * \param caracterRecibido char Recibe el caracter a analizar.
 * \return int Devuelve 0 si no es una letra, si es una letra, devuelve 1.
 *
 */
int esCaracter(char caracterRecibido);




/** \brief Pide y almacena, en un puntero, un caracter.
 *
 * \param mensaje[] char Mensaje a mostrar para pedir el caracter.
 * \param caracterRecibido char* Recibe un puntero del caracter para almacenar el dato.
 * \param mensajeError[] char Mensaje de error para mostrar al validar si es caracter.
 * \return int  Devuelve 0 si los parametros son igual a NULL, devuelve 1 si esta todo correcto.
 *
 */
int getChar(char mensaje[],char* caracterRecibido,char mensajeError[]);






/** \brief Se encarga de pedir un dato a traves de la funcion getChar y validar el caracter ingresado con los caracteres recibidos por parametros.
 *
 * \param mensaje[] char Mensaje a mostrar para pedir
 * \param caracterRecibido char* Recibe un puntero del caracter para almacenar el dato
 * \param mensajeError[] char Mensaje de error para mostrar al validar si es caracter.
 * \param mensajeErrorValidacion[] char Mensaje de error, se muestra si el valor del puntero "caracterRecibido" es diferente a los parametros formales "primerCaracter","SegundoCaracter"
 * \param primerCaracter char Recibe un caracter para validar.
 * \param segundoCaracter char Recibe un caracter para validar.
 * \return int Devuelve 0 si los parametros formales "mensaje","caracterRecibido","mensajeError", "mensajeErrorValidacion" son NULL, si esta todo correcto devuelve 1.
 *
 */
int getCaracter(char mensaje[],char* caracterRecibido,char mensajeError[],char mensajeErrorValidacion[],char primerCaracter,char segundoCaracter);



/** \brief Cambia el valor de un puntero.
 *
 * \param datoRecibido int* Recibe un puntero.
 * \param valorRecibido int Recibe el valor que se desea settear en el puntero.
 * \return int Devuelve un 0 si el puntero que recibe es NULL, de lo contrario, retorna 1
 *
 */
int settearDatoEntero(int* datoRecibido,int valorRecibido);


/** \brief Cambia el valor de un puntero.
 *
 * \param datoRecibido char* Recibe un puntero.
 * \param valorRecibido char Recibe el valor que se desea settear en el puntero.
 * \return int Devuelve un 0 si el puntero que recibe es NULL, de lo contrario, retorna 1
 *
 */
int settearDatoCaracter(char* datoRecibido,char valorRecibido);


#endif /* PEDIRDATOS_H_ */
