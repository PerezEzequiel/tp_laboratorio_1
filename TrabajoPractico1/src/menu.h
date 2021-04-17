/*
 * menu.h
 *
 *  Created on: 12 abr. 2021
 *      Author: ezequ
 */

#ifndef MENU_H_
#define MENU_H_

/** \brief Muestra un menu que segun el valor de la variable "flagMenu" se va modificando
 *
 * \param flagMenu int Segun su valor, va a cambiar el menu.
          Valor 0-->Menu por defecto. Valor 1-->Menu con primer operando. Valor 2-->Menu con los dos operandos.
 * \param valorA int Recibe el primero operando.
 * \param valorB int Recibe el segundo operando.
 * \param respuesta int Devuelve la opcion elegida.
 * \return int Retorna 0 si los valores que recibe del parametro "flagMenu" no estan en el rango y, si el puntero que recibe es NULL. Si esta los parametros actuales son los correctos y, si al momento de pedir un numero, ingresa un numero, retorna 1.
 *
 */
int mostrarMenu(int flagMenu, int valorA, int valorB,int* respuesta);


#endif /* MENU_H_ */
