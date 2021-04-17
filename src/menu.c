/*
 * menu.c
 *
 *  Created on: 12 abr. 2021
 *      Author: Ezequiel Perez
 */

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "pedirDatos.h"
#include <conio.h>

int mostrarMenu(int flagMenu, int valorA, int valorB,int* respuesta)
{
    int retorno=0;

    if(flagMenu >= 0 && flagMenu <=2 && respuesta != NULL)
    {
        switch(flagMenu)
        {
        case 0:
            printf("1-Ingresar 1er operando(A=x)");
            printf("\n2-Ingresar 2do operando(B=y)");
            break;
        case 1:
            printf("1-Ingresar 1er operando(A=%d)",valorA);
            printf("\n2-Ingresar 2do operando(B=y)");
            break;
        case 2:
            printf("1-Ingresar 1er operando(A=%d)",valorA);
            printf("\n2-Ingresar 2do operando(B=%d)", valorB);
            break;
        }

        printf("\n3-Calcular todas las operaciones");
        printf("\n4-Mostrar todas las operaciones");
        printf("\n5-Salir");
        if(getInt("\nQue desea hacer?: ",respuesta,"\nError,Ingrese un numero")==1)
        {
            retorno = 1;
        }
    }

    return retorno;
}




