/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"

typedef struct
{
    int id;
    char nombre[20];
    char sexo;
    int edad;
} eMascota;

void mostrarMascota(eMascota* m);
void mostrarMascotas(LinkedList* list);
int ordenarMascotasId(void* m1, void* m2);

int main(void)
{
	setbuf(stdout,NULL);
    eMascota* aux=NULL;
    eMascota* popReturn=NULL;
    eMascota m1= {1234,"Bobby",'m',2};
    eMascota m2= {3322,"Pepe",'m',5};
    eMascota m3= {6543,"Lola",'h',1};
    eMascota m4= {1111,"Bunny",'h',7};
    eMascota m5= {9891,"Susy",'h',2};
    eMascota m6= {2310,"Lolo",'m',1};

    eMascota m7 = {3333,"Firu",'m',3};
    eMascota m8 = {3156,"Floki",'m',6};
    LinkedList* listaDos=NULL;
    LinkedList* listaTres=NULL;


    printf("****Creo linkedList.****\n");
    LinkedList* lista = ll_newLinkedList();
    if(lista!=NULL)
    {
        printf("LinkedList creada.\n");
        printf("\n");
        system("pause");
        printf("\n\n------------------------------------------------------------------------------------------------------------------------\n");


        printf("\n****Agrego y muestro mascotas en la LinkedList(ll_add).****\n");
        if(!ll_add(lista,&m1) && !ll_add(lista,&m2) &&!ll_add(lista,&m3) && !ll_add(lista,&m4) && !ll_add(lista,&m5) && !ll_add(lista,&m6))
        {
            printf("\nNumero de mascotas agregadas(ll_len):%d\n\n", ll_len(lista));
            mostrarMascotas(lista);

        }
        printf("\n");
        system("pause");
        printf("\n\n------------------------------------------------------------------------------------------------------------------------\n");



        printf("\n****Obtengo y muestro la primer mascota de la LinkedList(ll_get).****\n\n");
        aux = (eMascota*)ll_get(lista,0);
        if(aux!=NULL)
        {
            mostrarMascota(aux);
        }
        printf("\n");
        system("pause");
        printf("\n\n------------------------------------------------------------------------------------------------------------------------\n");

        printf("\n****Inserto un nuevo elemento en un indice de la LinkedList(ll_set) y muestro el nuevo listado.****\n\n");
        if(!ll_set(lista,0,&m7))
        {
            mostrarMascotas(lista);
        }
        printf("\n");
        system("pause");
        printf("\n\n------------------------------------------------------------------------------------------------------------------------\n");


        printf("\n****Elimino la primer mascota de la LinkedList(ll_remove).****\n\n");
        if(!ll_remove(lista,0))
        {
            mostrarMascotas(lista);
            printf("\nNumero nuevo de mascotas (ll_len):%d\n\n\n", ll_len(lista));
        }

        printf("\n");
        system("pause");
        printf("\n\n------------------------------------------------------------------------------------------------------------------------\n");


        printf("\n****Agrego un nuevo nodo en la primer posicion e inserto un elemento en la LinkedList(ll_push).****\n\n");
        if(!ll_push(lista,0,&m8))
        {
            printf("\nNumero nuevo de mascotas (ll_len):%d\n\n\n", ll_len(lista));
            mostrarMascotas(lista);
        }
        printf("\n");
        system("pause");
        printf("\n\n------------------------------------------------------------------------------------------------------------------------\n");



        printf("\n****Utilizo la funcion ll_pop con el ultimo elemento.****\n\n");
        popReturn = (eMascota*)ll_pop(lista,ll_len(lista)-1);
        if(popReturn!=NULL)
        {
            printf("La mascota obtenida y eliminada con ll_pop\n");
            mostrarMascota(popReturn);

            printf("\n\nLista actualizada.\n");
            mostrarMascotas(lista);
        }
        printf("\n");
        system("pause");
        printf("\n\n------------------------------------------------------------------------------------------------------------------------\n");



        printf("\n****Utilizo la funcion ll_indexOf, para verificar el retorno.****\n\n");
        printf("Mascota pasada a indexOf: ");
        mostrarMascota(&m5);
        printf("\n\nEl elemento pasado en indexOf esta en la posicion:%d\n",ll_indexOf(lista,&m5));
        mostrarMascotas(lista);

        printf("\n");
        system("pause");

        printf("\n\n------------------------------------------------------------------------------------------------------------------------\n");

        printf("\n****Utilizo la funcion ll_contains con la mascota del indice numero 0.****\n\n");
        printf("Mascota elegida: ");
        mostrarMascota(&m8);
        if(ll_contains(lista,&m8))
        {
            printf("Existe en la lista.\n");
        }
        mostrarMascotas(lista);

        printf("\n");
        system("pause");
        printf("\n\n------------------------------------------------------------------------------------------------------------------------\n");

        printf("\n****Creo una sublista del indice 0 al 2(no incluido)(ll_subList).****\n\n");
        listaDos = ll_subList(lista,0,2);
        if(listaDos!=NULL)
        {
            printf("****Nueva lista.****\n\n");
            mostrarMascotas(listaDos);
        }
        printf("\n");
        system("pause");
        printf("\n\n------------------------------------------------------------------------------------------------------------------------\n");



        printf("\n****Utilizo la funcion ll_containsAll con la sublista obtenida anteriormente.****\n\n");
        if(ll_containsAll(lista,listaDos))
        {
            printf("Todos los elementos de la lista 2, estan contenidos en la lista 1\n");
        }

        printf("\n");
        system("pause");
        printf("\n\n------------------------------------------------------------------------------------------------------------------------\n");

        printf("\n****Utilizo la funcion ll_clone para una nueva lista con todos los elementos.****\n\n");
        listaTres = ll_clone(lista);
        if(listaTres!=NULL)
        {
            printf("****Nueva lista.****\n\n");
            mostrarMascotas(listaTres);
        }

        printf("\n");
        system("pause");
        printf("\n\n------------------------------------------------------------------------------------------------------------------------\n");

        printf("Ordeno los ids de las mascotas de la lista(ascendente).\n");
        if(!ll_sort(lista,ordenarMascotasId,1))
        {
            mostrarMascotas(lista);
        }



        printf("\n");
        system("pause");
        printf("\n\n------------------------------------------------------------------------------------------------------------------------\n");

        printf("\n****Utilizo la funcion ll_isEmpty y, luego utilizo ll_clear, para verificar nuevamente el retorno de ll_isEmpty.****\n\n");
        if(!ll_isEmpty(lista))
        {
            printf("La lista contiene elementos.\n");
            mostrarMascotas(lista);
        }
        printf("****Hago ll_clear****\n");
        if(!ll_clear(lista))
        {

            if(ll_isEmpty(lista))
            {
                printf("La lista esta vacia.\n");
            }
        }
        printf("\n");
        system("pause");
        printf("\n\n------------------------------------------------------------------------------------------------------------------------\n");


        printf("****Elimino las listas creadas con ll_deleteLinkedList.****\n");
        if(!ll_deleteLinkedList(lista) && !ll_deleteLinkedList(listaDos) && !ll_deleteLinkedList(listaTres))
        {
            printf("Listas eliminadas.\n");
        }

        printf("\n");
        system("pause");
        printf("\n\n------------------------------------------------------------------------------------------------------------------------\n");

    }

     lista = NULL;
     listaDos=NULL;
     listaTres=NULL;

     aux=NULL;
     popReturn=NULL;


 /* startTesting(1);  // ll_newLinkedList
    startTesting(2);  // ll_len
	startTesting(3);  // getNode - test_getNode
	startTesting(4);  // addNode - test_addNode
	startTesting(5);  // ll_add
	startTesting(6);  // ll_get
	startTesting(7);  // ll_set
	startTesting(8);  // ll_remove
	startTesting(9);  // ll_clear
	startTesting(10); // ll_deleteLinkedList
	startTesting(11); // ll_indexOf
	startTesting(12); // ll_isEmpty
	startTesting(13); // ll_push
	startTesting(14); // ll_pop
	startTesting(15); // ll_contains
	startTesting(16); // ll_containsAll
	startTesting(17); // ll_subList
	startTesting(18); // ll_clone
	startTesting(19); // ll_sort*/

    return 0;
}



void mostrarMascota(eMascota* m)
{

    printf("%d %7s %5c %7d\n",m->id,m->nombre,m->sexo,m->edad);

}
void mostrarMascotas(LinkedList* list)
{
    int size;
    eMascota* pElementAux = NULL;

    if(list!=NULL)
    {
        size = ll_len(list);
        printf("ID    NOMBRE   SEXO   EDAD\n");
        for(int i=0; i<size; i++)
        {
            pElementAux = (eMascota*) ll_get(list,i);
            mostrarMascota(pElementAux);

        }
        pElementAux = NULL;
    }
}

int ordenarMascotasId(void* m1, void* m2)
{
    int retorno = 0;
    eMascota* mascota1=NULL;
    eMascota* mascota2=NULL;

    mascota1=(eMascota*) m1;
    mascota2=(eMascota*)m2;

    if(mascota1->id > mascota2->id)
    {
        retorno = 1;
    }
    else
    {
        retorno = -1;
    }
    return retorno;
}






























