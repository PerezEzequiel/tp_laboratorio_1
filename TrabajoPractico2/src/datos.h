/*
 * datos.h
 *
 *  Created on: 15 may. 2021
 *      Author: Ezequiel Perez
 */

#ifndef DATOS_H_
#define DATOS_H_



/** \brief Valida si lo que recibe son todas letras y si no sobrepasa el largo del array de la cadena.
 *
 * \param msg[] char Mensaje a mostrar para pedir el entero.
 * \param mesgError[] char Mensaje de error, se implementa si, lo que ingreso el usuario, no es una letra.
 * \param cadena[] char Recibe el array de la cadena para almacenar el dato.
 * \param tam int Recibe el largo de la cadena
 * \return int Devuelve 0 si los parametros son NULL, de lo contrario devuelve 1.
 *
 */
int getString(char msg[],char msgError[],char cadena[], int tam);



/** \brief Valida si lo que recibe es un numero.
 *
 * \param numero[] char Recibe una cadena de caracteres a analizar.
 * \return int Devuelve 0 si no es un numero o si el parametro recibido es igual a NULL. Si es un numero y si el puntero es diferente de NULL, devuelve un 1.
 *
 */
int esNumero(char numero[]);



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


int getFloat(char mensaje[], float* resultado,char mensajeError[]);


/** \brief Analiza si lo que recibe es una letra o un numero.
 *
 * \param caracterRecibido char Recibe el caracter a analizar.
 * \return int Devuelve 0 si no es una letra, si es una letra, devuelve 1.
 *
 */
int esLetra(char caracterRecibido);


/** \brief Analiza si el buffer sobrepasa el tamanio de tamCadena
 *
 * \param buffer[] char Recibe el buffer a analizar.
 * \param tamCadena int Tamanio a comparar.
 * \return int Devuelve 0 si no son todas letras, si son todas letras, devuelve 1.
 *
 */
int validarBuffer(char buffer[],int tamCadena);




/** \brief Analiza si en el array que recibe son todas letras.
 *
 * \param cadena[] char Recibe el array a analizar.
 * \return int Devuelve 0 si no son todas letras, si son todas letras, devuelve 1.
 *
 */
int esCaracteres(char cadena[]);




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



/** \brief Se encarga de pedir un dato a traves de la funcion getInt y validar el entero ingresado con los enteross recibidos por parametros.
 *
 * \param mensaje[] char Mensaje a mostrar para pedir
 * \param caracterRecibido int* Recibe un puntero del entero para almacenar el dato
 * \param mensajeError[] char Mensaje de error para mostrar al validar si es entero.
 * \param mensajeErrorValidacion[] char Mensaje de error, se muestra si el valor del puntero "enteroRecibido" es menor que la variable minimo y mayor que la variable maximo
 * \param minimo int Recibe un entero minimo para validar.
 * \param maximo int Recibe un entero maximo para validar.
 * \return int Devuelve 0 si los parametros formales "mensaje","enteroRecibido","mensajeError", "mensajeErrorValidacion" son NULL, si esta todo correcto devuelve 1.
 *
 */
int getEntero(char mensaje[],int* enteroRecibido,char mensajeError[],char mensajeErrorValidacion[],int minimo,int maximo);


#endif /* DATOS_H_ */
