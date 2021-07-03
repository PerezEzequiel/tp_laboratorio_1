#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"

static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* lista = (LinkedList*) malloc(sizeof(LinkedList));

    if(lista!=NULL)
    {
        lista->size = 0;
        lista->pFirstNode = NULL;
    }

    return lista;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;
    int i=0;

    if(this!=NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
    {
        pNode = this->pFirstNode;
        if(nodeIndex > 0)
        {
            while(i!=nodeIndex)
            {
                pNode=pNode->pNextNode;
                i++;
            }
        }

    }
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* nodoAnterior;
    Node* nuevoNodo;

    if(this!=NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
    {
        nuevoNodo = (Node*) malloc(sizeof(Node));
        if(nuevoNodo != NULL)
        {
            nuevoNodo->pNextNode = NULL;
            nuevoNodo->pElement = pElement;

            if(nodeIndex == 0)
            {
                nuevoNodo->pNextNode = this->pFirstNode;
                this->pFirstNode = nuevoNodo;
            }
            else
            {
                nodoAnterior = getNode(this,nodeIndex-1);
                nuevoNodo->pNextNode = nodoAnterior->pNextNode;
                nodoAnterior->pNextNode = nuevoNodo;
            }
        }
        this->size++;
        returnAux = 0;
    }
    return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int indice = 0;

    if(this!=NULL)
    {
        indice = ll_len(this);
        if(!addNode(this,indice,pElement))
        {
        	returnAux = 0;
        }

    }

    return returnAux;
}



void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* nodoAux;

    if(this!=NULL && index >= 0 && index<ll_len(this))
    {
        nodoAux = getNode(this,index);
        if(nodoAux != NULL)
        {
        	returnAux = nodoAux->pElement;
        }
    }

    return returnAux;
}


/** \brief Inserta un elemento en el LinkedList, en el �ndice especificado. Verificando que el puntero this
sea distinto de NULL y que index sea positivo e inferior al tama�o del array. Si la verificaci�n
falla la funci�n retorna (-1) y si tiene �xito (0).
*/
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* nodeAux=NULL;

    if(this!=NULL && index>=0 && index<ll_len(this))
    {
        nodeAux = getNode(this,index);
        if(nodeAux!=NULL)
        {
            nodeAux->pElement = pElement;
            returnAux = 0;
        }

    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* nodoAnterior=NULL;
    Node* nodoActual=NULL;

    if(this!=NULL && index>=0 && index<ll_len(this))
    {
        if(index == 0)
        {
            nodoActual = this->pFirstNode;
            this->pFirstNode = nodoActual->pNextNode;
        }
        else
        {
            nodoAnterior = getNode(this,index-1);
            nodoActual = getNode(this,index);
            nodoAnterior->pNextNode = nodoActual->pNextNode;
        }

        free(nodoActual);

        this->size--;
        returnAux = 0;

    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int retornoAux=-1;
    int flag = 1;
    if(this!=NULL)
    {

        while(!ll_isEmpty(this))
        {
            if(ll_remove(this,0))
            {
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            retornoAux = 0;
        }
    }
    return retornoAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int retornoAux = -1;
    if(this!=NULL)
    {
        if(!ll_clear(this))
        {
            free(this);
            retornoAux = 0;
        }
    }
    return retornoAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int retornoAux = -1;
    void* pElementAux;

    if(this!=NULL)
    {
        for(int i=0; i<ll_len(this); i++)
        {
            pElementAux = ll_get(this,i);
            if(pElementAux == pElement)
            {
                retornoAux = i;
                break;
            }
        }
    }
    return retornoAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int retornoAux = -1;
    if(this!=NULL)
    {
        retornoAux = 1;
        if(ll_len(this)>0)
        {
            retornoAux = 0;
        }
    }
    return retornoAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    return addNode(this,index,pElement);
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    if(this!=NULL && index>=0 && index<ll_len(this))
    {
        returnAux = ll_get(this,index);
        ll_remove(this,index);
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
        returnAux = 0;
        if(ll_indexOf(this,pElement)>=0)
        {
            returnAux = 1;
        }
    }

    return returnAux;
}


/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;

    if(this!=NULL && this2 != NULL)
    {
        returnAux = 1;
        for(int i=0;i<ll_len(this2);i++)
        {
            if(!ll_contains(this,ll_get(this2,i)))
            {
                returnAux = 0;
                break;
            }
        }
    }
    return returnAux;
}


/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* linkedListAux = NULL;

    if(this!=NULL && from>=0 && from<ll_len(this) && to>from && to<=ll_len(this))
    {
        linkedListAux = ll_newLinkedList();
        if(linkedListAux!=NULL)
        {
            while(from!=to)
            {
                ll_add(linkedListAux,ll_get(this,from));
                from++;
            }
        }
    }
    return linkedListAux;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* lista=NULL;
    if(this!=NULL)
    {
        lista = ll_subList(this,0,ll_len(this));
    }
    return lista;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux=-1;
    void* pElementAux=NULL;

    if(this!=NULL && pFunc!=NULL && (order == 1 || order == 0))
    {
        for(int i=0; i<ll_len(this)-1; i++)
        {
            for(int j=i+1; j<ll_len(this); j++)
            {
                if((order && pFunc(ll_get(this,i),ll_get(this,j)) > 0) || (!order  && pFunc(ll_get(this,i),ll_get(this,j))<0))
                {
                    pElementAux = ll_get(this,i);
                    ll_set(this,i,ll_get(this,j));
                    ll_set(this,j,pElementAux);

                    pElementAux = NULL;
                }
            }
        }
        returnAux = 0;
    }
    return returnAux;
}

