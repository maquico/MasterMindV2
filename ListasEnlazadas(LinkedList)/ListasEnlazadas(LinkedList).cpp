/*
* ENUNCIADO: TAREA 5. LISTAS ENLAZADAS (LINKED LIST)
* ASUNTO: ESTE PROGRAMA PERMITE HACER LAS OPERACIONES INSERTAR, ELIMINAR, BUSCAR, Y MOSTRAR LISTA
AUTORES: ANGEL MORENO ID:1104666
*        GLEIDY ESPINAL ID:1104225
*        ALLEN SILVERIO ID:1104220
*        CRISTIAN JIMÉNEZ ID:1106166
*        WILLIAM FERREIRA ID:1104228
* FECHA: 29/08/2022
*/

#include <stdlib.h> // new, delete
#include <string>
#include <conio.h> // getch
#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

void Insertar(Nodo*& lista, int entrada) {
    Nodo* aux1 = lista;
    Nodo* aux2 = new Nodo();
    Nodo *nuevoNodo = new Nodo();

        while (aux1!=NULL && aux1->dato < entrada)
        {
            aux2 = aux1;
            aux1 = aux1->siguiente;
        }
        if (lista==aux1)
        {
            lista = nuevoNodo;
            
        }
        else
        {
            aux2->siguiente = nuevoNodo;
        } 
        nuevoNodo->siguiente = aux1;  
        nuevoNodo->dato = entrada;
}

void Mostrar(Nodo* lista) {
    Nodo* actual = new Nodo();
    actual = lista;
    while (actual!=NULL)
    {
        if (actual->siguiente != NULL) cout << actual->dato << " , ";
        else cout << actual->dato << ".";
        actual = actual->siguiente;
    }
}

void BuscarElemento(Nodo *lista, int entrada) { //Se le pasa el nodo lista de tipo puntero (que representa el primer elemento de la lista) y se le pasa el dato buscar.

    bool elementoExiste = false; 
    Nodo *actual = new Nodo(); //Se crea un nodo auxiliar que representara el nodo actual que se esta comparando con el dato a buscar.
    actual = lista; // Se le asigna al nodo actual el nodo que representa el primer elemento de la lista.

    while (actual!=NULL && actual->dato<=entrada) //Mientras el nodo actual sea diferente de nulo (no sea el que le sigue al ultimo nodo de la lista) y el dato del nodo actual sea menor o igual que el dato a buscar
    {
        if (actual->dato == entrada) //Se verifica si el dato del nodo actual es igual al dato a buscar
        {
            bool elementoExiste = true; 
            break;//El elemento existe asi que se sale del bucle
        }

        actual = actual->siguiente; 
    }

    if (elementoExiste) 
    {
        cout << "El elemento " << entrada << " se encuentra en la lista ";
    }
    else 
    {
        cout << "El elemento " << entrada << " NO se encuentra en la lista ";
    }
}

int main()
{
    Nodo* lista = NULL; 
}

