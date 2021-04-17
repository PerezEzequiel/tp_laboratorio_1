/*
 ============================================================================
 Name        : TrabajoPractico1.c
 Author      : Ezequiel Perez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "pedirDatos.h"
#include "mostrarDatos.h"
#include "operaciones.h"

int main()
{
	setbuf(stdout, NULL);
    int primerOperando;
    int segundoOperando;

    int flagMenuFuncion=0;
    int flagMenu=0;
    int respuestaMenu=0;

    int retornoSuma;
    int retornoResta;
    int retornoDivision;
    int retornoMultiplicacion;
    int retornoFactorialA;
    int retornoFactorialB;

    int resultadoSuma;
    int resultadoResta;
    float resultadoDivison;
    int resultadoMultiplicacion;
    long int resultadoFactorial_A;
    long int resultadoFactorial_B;

    char salir;

    do
    {
        printf("\t\t\t\t::::Calculadora:::::\n");

        if(mostrarMenu(flagMenuFuncion,primerOperando,segundoOperando,&respuestaMenu)==1)
        {
            switch(respuestaMenu)
            {
            case 1:
                if(flagMenu==0)
                {
                    if(getInt("Ingrese el primer operando: ",&primerOperando,"\nError, ingrese un numero: ")==1)
                    {
                        printf("\n Numero cargado correctamente\n");
                        settearDatoEntero(&flagMenuFuncion,1);
                        settearDatoEntero(&flagMenu,1);
                    }
                }
                else if(flagMenu>=1)
                {
                    if(getInt("Ingrese el primer operando: ",&primerOperando,"\nError, ingrese un numero: ")==1)
                    {
                        printf("\n Numero cargado correctamente\n");
                    }
                }
                system("pause");

                break;
            case 2:
                if(flagMenu>=1)
                {
                    if(getInt("Ingrese el segundo operando: ",&segundoOperando,"\nError, ingrese un numero: ")==1)
                    {
                        printf("\n Numero cargado correctamente\n");
                        settearDatoEntero(&flagMenuFuncion,2);
                        settearDatoEntero(&flagMenu,2);
                    }
                }
                else
                {
                    printf("::::Primero ingrese el primer operando::::\n");
                }
                system("pause");

                break;
            case 3:
                if(flagMenu>=2)
                {
                	settearDatoEntero(&flagMenu,3);
                    retornoSuma = suma(primerOperando,segundoOperando,&resultadoSuma);
                    retornoResta = resta(primerOperando,segundoOperando,&resultadoResta);
                    retornoDivision = division(primerOperando,segundoOperando,&resultadoDivison);
                    retornoMultiplicacion = multiplicacion(primerOperando,segundoOperando,&resultadoMultiplicacion);
                    retornoFactorialA = factorial(primerOperando,&resultadoFactorial_A);
                    retornoFactorialB = factorial(segundoOperando,&resultadoFactorial_B);
                    printf("Calculos realizados\n");
                }
                else
                {
                    printf("::::Primero cargue los operandos::::\n");
                }
                system("pause");

                break;
            case 4:
                if(flagMenu==3)
                {
                    if(retornoSuma==1)
                    {
                        mostrarSuma(resultadoSuma);
                    }
                    else
                    {
                        printf("\nERROR SUMA");
                    }
                    if(retornoResta==1)
                    {
                        mostrarResta(resultadoResta);
                    }
                    else
                    {
                        printf("\nERROR RESTA");
                    }
                    if(retornoDivision==1)
                    {
                        mostrarDivision(resultadoDivison);
                    }
                    else
                    {
                        printf("\nERROR DIVISION");
                    }
                    if(retornoMultiplicacion==1)
                    {
                        mostrarMultiplicacion(resultadoMultiplicacion);
                    }
                    else
                    {
                        printf("\nERROR MULTIPLICACION");
                    }
                    if(retornoFactorialA==1)
                    {
                        mostrarFactorial(resultadoFactorial_A,'A');
                    }
                    else
                    {
                        printf("\nERROR FACTORIAL A");
                    }
                    if(retornoFactorialB==1)
                    {
                        mostrarFactorial(resultadoFactorial_B,'B');
                    }
                    else
                    {
                        printf("\nERROR FACTORIAL B");
                    }
                    settearDatoEntero(&flagMenu,0);
                    settearDatoEntero(&flagMenuFuncion,0);
                }
                else if(flagMenu==2)
                {
                    printf("::::Primero seleccione opcion 3 para calcular::::\n");
                }
                else
                {
                    printf("::::Primero cargue los operandos::::\n");
                }
                system("\npause");

                break;
            case 5:
                if(getCaracter("\nDesea salir? s/n: ",&salir,"\nUsted ingreso un numero, por favor ingrese un caracter: ","\nError, ingrese s o n",'s','n'))
                {
                    if(salir != 'n')
                    {
                        printf("\t\t\t\t::::Hasta luego:::::\n");
                        settearDatoCaracter(&salir,'s');
                    }
                    else
                    {
                        system("\npause");

                    }
                }
                else
                {
                    printf("::::Error::::");
                }
                break;
            default:
                printf("\nNo existe esa opcion\n");
                system("\npause");

                break;
            }
        }
        else
        {
            printf("\nError en el menu");
        }
    }while(salir!='s');

    return 0;
}
