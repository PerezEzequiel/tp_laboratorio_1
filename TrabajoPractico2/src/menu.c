/*
 * menu.c
 *
 *  Created on: 15 may. 2021
 *      Author: Ezequiel Perez
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"

void mostrarMenu(char opciones[],int* pRespuesta)
{
    if(opciones!=NULL && pRespuesta !=NULL)
    {
        printf("%s", opciones);
        scanf("%d",pRespuesta);
    }
    else
    {
        printf("Error menu\n");
    }

}
