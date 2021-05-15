/*
 * datos.c
 *
 *  Created on: 15 may. 2021
 *     Author: Ezequiel Perez
 */

#include <stdio.h>
#include <stdlib.h>
#include "Datos.h"
#include "string.h"
#include "ctype.h"

int getString(char msg[],char msgError[],char cadena[], int tam)
{
    int retorno=0;
    char buffer[200];

    if(msg!=NULL && msgError != NULL && cadena != NULL)
    {

    printf("%s",msg);
    fflush(stdin);
    gets(buffer);


    while(validarBuffer(buffer,tam) != 1 || esCaracteres(buffer) != 1)
    {
        printf("\n%s",msgError);
        printf("%s",msg);
        fflush(stdin);
        gets(buffer);
    }
    strcpy(cadena,buffer);
    retorno=1;
    }
    return retorno;
}

int validarBuffer(char buffer[],int tamCadena)
{
    int retorno = 0;
    int len;
    len = strlen(buffer);
    if(len<tamCadena-1)
    {
        retorno = 1;
    }
    return retorno;
}

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
        for( ; i < strlen(numero) ; i++)
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

int getFloat(char mensaje[], float* resultado,char mensajeError[])
{
    char buffer[20];
    int retorno=0;
    if(mensaje!=NULL && resultado!=NULL && mensajeError != NULL)
    {
        printf("%s",mensaje);
        fflush(stdin);
        scanf("%s",buffer);

        retorno = esNumero(buffer);
        while(retorno != 0)
        {
            printf("%s: ",mensajeError);
            fflush(stdin);
            scanf("%s",buffer);
            retorno = esNumero(buffer);
        }
        *resultado = atoi(buffer);
        retorno = 1;
    }
    return retorno;
}


int esLetra(char caracterRecibido)
{
    int retorno=0;
    if((caracterRecibido >= 65 && caracterRecibido<= 90) || (caracterRecibido >= 97 && caracterRecibido <= 122) || caracterRecibido == ' ')
    {
        retorno = 1;
    }

    return retorno;
}

int esCaracteres(char cadena[])
{
    int i;
    int retorno;
    for(i=0; cadena[i]!='\0'; i++)
    {
        if(esLetra(cadena[i]) == 1)
        {
            retorno = 1;
        }
        else
        {
            retorno = 0;
            break;
        }
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
        while(esLetra(*caracterRecibido)!=1)
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
        while(getChar(mensaje,caracterRecibido,mensajeError) != 1 ||  (*caracterRecibido != primerCaracter && *caracterRecibido != segundoCaracter))
        {
            printf("%s\n", mensajeErrorValidacion);
        }
        retorno = 1;
    }

    return retorno;
}

int getEntero(char mensaje[],int* enteroRecibido,char mensajeError[],char mensajeErrorValidacion[],int minimo,int maximo)
{
    int retorno = 0;
    if(mensaje != NULL && enteroRecibido != NULL && mensajeError != NULL && mensajeErrorValidacion != NULL)
    {
        while(getInt(mensaje,enteroRecibido,mensajeError) != 1 || *enteroRecibido < minimo ||  *enteroRecibido > maximo)
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
