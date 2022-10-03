/*
* ENUNCIADO: TAREA 7. ARBOLES BINARIO DE BUSQUEDA
* ASUNTO: Realizar un programa C++ que permita gestionar un Árbol Binario de Búsqueda. El programa
debe permitir insertar, buscar y eliminar un nodo; además de presentar (utilizando cualquiera
de los recorridos) el árbol de acuerdo a las reglas que existen para el árbol binario de búsqueda.
*
AUTORES: ANGEL MORENO ID:1104666
*        GLEIDY ESPINAL ID:1104225
*        ALLEN SILVERIO ID:1104220
*        CRISTIAN JIMÉNEZ ID:1106166
*        WILLIAM FERREIRA ID:1104228
* FECHA: 19/08/2022
*/


#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;


struct NodoT {
	int dato;
	NodoT* izq;
	NodoT* der;
};

NodoT* CrearNodo(int entrada) {
	NodoT* nuevoNodo = new NodoT();
	nuevoNodo->dato = entrada;
	nuevoNodo->der = NULL;
	nuevoNodo->izq = NULL;

	return nuevoNodo;
}

void InsertarEnArbol(NodoT*& arbol, int n) {
	
	if (arbol == NULL)
	{
		NodoT* nuevoNodo = CrearNodo(n);
		arbol = nuevoNodo;
	}
	else
	{
		int valorRaiz = arbol->dato;
		if (n < valorRaiz) {
			InsertarEnArbol(arbol->izq, n);
		}
		else
		{
			InsertarEnArbol(arbol->der, n);
		}
	}
}

void GoToXY(int x, int y)
{//La función coloca el cursor para imprimir en el lugar que queramos.
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hCon, dwPos);
}

int ContarDigitos(int n) {
	int digitos = 0;
	while (n>0)
	{
		n = n / 10;
		digitos++;
	}
	return digitos;
}

bool Buscar (NodoT* tree, int n) {
	if (tree == NULL) {
		return false;
	}
	else if (tree->dato == n) {
		return true;
	}
	else if (n < tree->dato) {
		return Buscar(tree->izq, n);
	}
	else {
		return Buscar(tree->der, n);
	}
}

void MostrarArbolHorz2(NodoT* arbol, int y, int x) {

	if (arbol == NULL) {
		return;
	}
	else{
		int digitos = ContarDigitos(arbol->dato);

		int digitosDer;
		(arbol->der != NULL) ? digitosDer = ContarDigitos(arbol->der->dato) : digitosDer = 0;
		int digitosIzq;
		(arbol->izq != NULL) ? digitosIzq = ContarDigitos(arbol->izq->dato) : digitosIzq = 0;
		
		MostrarArbolHorz2(arbol->der, y + 2, x+digitosDer*2);
		GoToXY(x, y);
		cout << arbol->dato << endl;
		
		if (arbol->der!=NULL){
			GoToXY(x + digitos, y + 1);
			cout << '\\' << endl;
		}

		if (arbol->izq != NULL) {
			GoToXY(x - 1, y + 1);
			cout << '/' << endl;
		}
		MostrarArbolHorz2(arbol->izq, y + 2, x-digitosIzq*2);
	}
}

void ContarNiveles(NodoT* arbol, int y, int &niveles) {
	
	if (y > niveles) niveles = y;
	if (arbol == NULL) {
		return;
	}
	else {
		ContarNiveles(arbol->der, y + 1, niveles);
		ContarNiveles(arbol->izq, y + 1, niveles);
	}
}


int main() {
	int niveles = 0;
	NodoT* arbol = NULL;
	InsertarEnArbol(arbol, 100);
	InsertarEnArbol(arbol, 200);
	InsertarEnArbol(arbol, 150);
	InsertarEnArbol(arbol, 160);
	InsertarEnArbol(arbol, 159);
	InsertarEnArbol(arbol, 158);
	InsertarEnArbol(arbol, 157);
	InsertarEnArbol(arbol, 156);
	InsertarEnArbol(arbol, 155);
	InsertarEnArbol(arbol, 154);
	InsertarEnArbol(arbol, 153);
	InsertarEnArbol(arbol, 152);
	InsertarEnArbol(arbol, 151);
	InsertarEnArbol(arbol, 9);
	InsertarEnArbol(arbol, 159001);
	InsertarEnArbol(arbol, 1);
	InsertarEnArbol(arbol, 201);
	ContarNiveles(arbol, 0, niveles);
	MostrarArbolHorz2(arbol, 0, (niveles*5));
	_getch();
	
	
	
}