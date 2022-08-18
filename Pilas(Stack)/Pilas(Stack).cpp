#include <iostream>
#include <string>

using namespace std;

Nodo* pila = NULL;
struct Nodo
{
	int dato;
	Nodo* siguiente;
};

void agregarPila(Nodo*& pila, int n) {
	Nodo* nuevoNodo = new Nodo();
	nuevoNodo->dato = n;
	nuevoNodo->siguiente = pila;
};

	

int main()
{
	return 0;
}