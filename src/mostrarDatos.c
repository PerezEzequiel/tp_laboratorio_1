/*
 * mostrarDatos.c
 *
 *  Created on: 12 abr. 2021
 *      Author: Ezequiel Perez
 */

#include <stdio.h>
#include <stdlib.h>
#include "mostrarDatos.h"

void mostrarSuma(int resultadoObtenido)
{
    printf("\nEl resultado de A+B es: %d", resultadoObtenido);
}
void mostrarResta(int resultadoObtenido)
{
    printf("\nEl resultado de A-B es: %d", resultadoObtenido);
}
void mostrarDivision(float resultadoObtenido)
{
    printf("\nEl resultado de A/B es: %.2f", resultadoObtenido);
}
void mostrarMultiplicacion(int resultadoObtenido)
{
    printf("\nEl resultado de A*B es: %d", resultadoObtenido);
}
void mostrarFactorial(long int resultadoObtenido,char nombreNumero)
{
    printf("\nEl factorial de %c es: %ld ",nombreNumero, resultadoObtenido);
}

