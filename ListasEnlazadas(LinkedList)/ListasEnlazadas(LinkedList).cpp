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
    Nodo* aux1 = lista, *aux2, *nuevoNodo = new Nodo();

    
    //al inicio de la lista
    lista = nuevoNodo;
}



int main()
{
    
    
}

