/*
 * pedirDatos.c
 *
 *  Created on: 12 abr. 2021
 *      Author: Ezequiel Perez
 */

#include <stdio.h>
#include <stdlib.h>
#include "pedirDatos.h"
#include "string.h"
#include "ctype.h"

int esNumero(char numero[])
{
    int i=0;
    int retorno=0;
    if(numero!=NULL)
    {
        if(numero[0] == '-')
        {
            i = 1;
        }
        for( ;i < strlen(numero) ; i++)
        {
            if(numero[i]<'0' ||  numero[i]>'9')
            {
                retorno = 1;
            }
        }
    }

    return retorno;
}

int getInt(char mensaje[], int* resultado,char mensajeError[])
{
    char buffer[20];
    int retorno=0;
    if(mensaje!=NULL && resultado!=NULL && mensajeError != NULL)
    {
        printf("%s",mensaje);
        fflush(stdin);
        scanf("%s",buffer);

        *resultado = esNumero(buffer);
        while(*resultado != 0)
        {
            printf("%s: ",mensajeError);
            fflush(stdin);
            scanf("%s",buffer);
            *resultado = esNumero(buffer);
        }
        *resultado = atoi(buffer);
        retorno = 1;
    }
    return retorno;
}


int esCaracter(char caracterRecibido)
{
    int retorno=0;
    if((caracterRecibido >= 65 && caracterRecibido<= 90) || (caracterRecibido >= 97 && caracterRecibido <= 122))
    {
        retorno = 1;
    }

    return retorno;
}

int getChar(char mensaje[],char* caracterRecibido,char mensajeError[])
{
    int retorno = 0;
    if(mensaje!=NULL && caracterRecibido != NULL && mensajeError != NULL)
    {
        printf("%s",mensaje);
        fflush(stdin);
        scanf("%c",caracterRecibido);
        while(esCaracter(*caracterRecibido)!=1)
        {
            printf("%s",mensajeError);
            fflush(stdin);
            scanf("%c",caracterRecibido);
        }
        *caracterRecibido = tolower(*caracterRecibido);
        retorno = 1;
    }

    return retorno;
}

int getCaracter(char mensaje[],char* caracterRecibido,char mensajeError[],char mensajeErrorValidacion[],char primerCaracter,char segundoCaracter)
{
    int retorno = 0;
    if(mensaje != NULL && caracterRecibido != NULL && mensajeError != NULL && mensajeErrorValidacion != NULL)
    {
        while(getChar(mensaje,caracterRecibido,mensajeError) == 1 && *caracterRecibido != primerCaracter && *caracterRecibido != segundoCaracter)
        {
            printf("%s\n", mensajeErrorValidacion);
        }
        retorno = 1;
    }

    return retorno;
}

int settearDatoEntero(int* datoRecibido,int valorRecibido)
{
    int retorno=0;
    if(datoRecibido!=NULL)
    {
        *datoRecibido = valorRecibido;
        retorno = 1;
    }

    return retorno;
}

int settearDatoCaracter(char* datoRecibido, char valorRecibido)
{
    int retorno=0;
    if(datoRecibido!=NULL)
    {
        *datoRecibido = valorRecibido;
        retorno = 1;
    }

    return retorno;
}



