/*
 * operaciones.c
 *
 *  Created on: 12 abr. 2021
 *      Author: ezequ
 */

#include "stdio.h"
#include "stdlib.h"
#include "operaciones.h"

int suma(int numeroUno, int numeroDos,int* resultado)
{
    int retorno=0;
    if(resultado!=NULL)
    {
        *resultado = numeroUno+numeroDos;
        retorno = 1;
    }

    return retorno;
}
int resta(int numeroUno, int numeroDos,int* resultado)
{
    int retorno=0;
    if(resultado!=NULL)
    {
        *resultado = numeroUno-numeroDos;
        retorno = 1;
    }
    return retorno;
}
int multiplicacion(int numeroUno, int numeroDos,int* resultado)
{
    int retorno=0;
    if(resultado!=NULL)
    {
     *resultado = numeroUno*numeroDos;
     retorno = 1;
    }
    return retorno;
}

int division(int numeroUno, int numeroDos,float* resultado)
{
   int retorno=0;
   if(resultado != NULL && numeroDos != 0)
   {

     *resultado = (float)numeroUno/numeroDos;
     retorno = 1;

   }
   return retorno;

}
int factorial(int numeroRecibido,long int* resultado)
{
    int i;
    int retorno=0;
    int aux=1;

    if(resultado!=NULL && numeroRecibido >= 0)
    {
    	if(numeroRecibido == 0)
    	{
    		*resultado = 1;
    	}
        for(i=1; i<=numeroRecibido; i++)
        {
            aux = aux*i;
            *resultado=aux;
        }
        retorno = 1;
    }

    return retorno;
}
