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
* FECHA: 26/09/2022
*/

#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <string>
#include <locale.h>


using namespace std;

int numNiveles = 0; // variable global que almacene la cantidad de niveles del arbol

struct NodoT {  //estructura del nodo de un arbol
	int dato;
	NodoT* padre;
	NodoT* izq;
	NodoT* der;
};


NodoT* CrearNodo(int entrada, NodoT* father) { //se crea el nodo del arbol
	NodoT* nuevoNodo = new NodoT();
	nuevoNodo->dato = entrada;
	nuevoNodo->padre = father;
	nuevoNodo->der = NULL;
	nuevoNodo->izq = NULL;

	return nuevoNodo;
}

void InsertarEnArbol(NodoT*& arbol, int n, NodoT* father) { // se agrega el nodo al arbol

	if (arbol == NULL)
	{
		NodoT* nuevoNodo = CrearNodo(n, father);
		arbol = nuevoNodo;
	}
	else
	{
		int valorRaiz = arbol->dato;
		if (n < valorRaiz) {
			InsertarEnArbol(arbol->izq, n, arbol);
		}
		else
		{
			InsertarEnArbol(arbol->der, n, arbol);
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

int ContarDigitos(int n) { // Cuenta la cantidad de digitos de un dato de un nodo (se usa para diseño)
	int digitos = 0;
	while (n > 0)
	{
		n = n / 10;
		digitos++;
	}
	return digitos;
}

bool Buscar(NodoT*& tree, int n) { // Confirma si existe o no un nodo en el arbol
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

void BuscarNumNiveles(NodoT* root, int contador) //Cuenta la cantidad de niveles del arbol
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		if (contador > numNiveles)
		{
			numNiveles++;
		}
		if (root->izq) BuscarNumNiveles(root->izq, contador + 1);
		if (root->der) BuscarNumNiveles(root->der, contador + 1);
	}
}

void MostrarArbolHorz2(NodoT* arbol, int y, int x) { //Se imprime con este formato si el arbol tiene mas de 5 niveles

	if (arbol == NULL) {
		return;
	}
	else {
		int digitos = ContarDigitos(arbol->dato);

		int digitosDer;
		(arbol->der != NULL) ? digitosDer = ContarDigitos(arbol->der->dato) : digitosDer = 0;
		int digitosIzq;
		(arbol->izq != NULL) ? digitosIzq = ContarDigitos(arbol->izq->dato) : digitosIzq = 0;

		MostrarArbolHorz2(arbol->der, y + 2, x + digitosDer * 2);
		GoToXY(x, y);
		cout << arbol->dato << endl;

		if (arbol->der != NULL) {
			GoToXY(x + digitos, y + 1);
			cout << '\\' << endl;
		}

		if (arbol->izq != NULL) {
			GoToXY(x - 1, y + 1);
			cout << '/' << endl;
		}
		MostrarArbolHorz2(arbol->izq, y + 2, x - digitosIzq * 2);
	}
}

NodoT* minimo(NodoT* root, bool izquierdo) { // busca el nodo hijo mas bajo de un nodo padre
	if (root == NULL) { // si no existe el nodo retorna NULL
		return NULL;
	}
	if (izquierdo) {  // si tiene hijo izquierdo
		if (root->izq) {
			return minimo(root->izq, true); // sigue buscando el nodo hoja mas bajo por la izquierda
		}
		else {
			return root;
		}
	}
	else  // si tiene hijo derecho
	{
		if (root->der) {
			return minimo(root->der, false); // sigue buscando el nodo hoja mas bajo por la derecha
		}
		else {
			return root;
		}
	}
}

void eliminar(NodoT* eliminar) { // destruir el nodo
	eliminar->der = NULL;
	eliminar->izq = NULL;

	delete eliminar;
}

void sustituir(NodoT* nodoElim, NodoT* newNode) { //intercambiar nodos de lugar cuando se va a eliminar un nodo con un solo hijo
	bool izq = false;
	bool der = false;

	if (nodoElim->padre->izq) { // Se verifica que exista el hijo izquierdo del padre
		izq = true;
	}
	if (nodoElim->padre->der) {// Se verifica que exista el hijo derecho del padre
		der = true;
	}

	if (nodoElim->padre) { // Si el nodo a eliminar tiene padre
		if (izq && nodoElim->padre->izq->dato == nodoElim->dato) {								// si tiene hijo izq, y el dato del nodo que se va a eliminar 
																								// coincide con el dato del hijo izquierdo del padre del nodo a eliminar.
																								//(basicamente verificar que se esta eliminando el dato correcto)
			nodoElim->padre->izq = newNode; // se coloca el nuevo nodo como hijo izq del padre
		}
		else if (der && nodoElim->padre->der->dato == nodoElim->dato) {
			nodoElim->padre->der = newNode; // se coloca el nuevo nodo como hijo der del padre
		}
	}

	if (newNode) { // Si el nodo de reemplazo es distinto de NULL
		newNode->padre = nodoElim->padre; // Se asigna el padre del nodo a eliminar como padre del nuevo nodo
	}
}

void eliminarNodo(NodoT* nodoEliminar) { // revisa todos los posibles casos antes de destruir un nodo 
	
	if (nodoEliminar->der && nodoEliminar->izq) { // el nodo tiene dos hijos
		NodoT* menor = NULL;
		if (nodoEliminar->der->izq) {  //Verifico que el hijo derecho tenga un hijo izq
			menor = minimo(nodoEliminar->der, true); 
		}
		else if (nodoEliminar->izq->der) { //Verifico que el hijo izquierdo tenga un hijo derecho
			menor = minimo(nodoEliminar->izq, false);

		}
		else { //Si el nodo tiene hijo izquierdo pero ese hijo izq no tiene hijo derecho
			menor = nodoEliminar->izq;
		}
		nodoEliminar->dato = menor->dato;  //le asigno el dato del nodo menor al nodo a eliminar
		eliminarNodo(menor); // destruyo el nodo menor
	}
	else if (nodoEliminar->izq) { //Si solo tiene hijo izq
		sustituir(nodoEliminar, nodoEliminar->izq);
		eliminar(nodoEliminar);
	}
	else if (nodoEliminar->der) { //Si solo tiene hijo der
		sustituir(nodoEliminar, nodoEliminar->der);
		eliminar(nodoEliminar);
	}
	else {						// Si no tiene hijos
		sustituir(nodoEliminar, NULL);
		eliminar(nodoEliminar);
	}


}

bool BuscarNodoEliminar(NodoT*& tree, int n) { //Verifica si existe el nodo a eliminar
	if (tree == NULL) {
		return false;
	}
	else if (tree->dato == n) {
		eliminarNodo(tree); //Si lo encuentra lo envia a la funcion eliminarNodo
	}
	else if (n < tree->dato) { // Si el dato que se busca es menor, busca por el lado izq
		BuscarNodoEliminar(tree->izq, n);
	}
	else { // Si el dato que se busca es menor, busca por el lado der
		BuscarNodoEliminar(tree->der, n);
	}
}

void MostrarArbolVert(NodoT* root, int contador) //Mostrar el arbol en vertical
{
	if (root == NULL) // Si el nodo es nulo termina la funcion
	{
		return;
	}
	else
	{
		MostrarArbolVert(root->der, contador + 1); // busca el nodo mas a la derecha posible
		int i = 0;
		while (i < contador)
		{
			cout << "   ";   // imprime espacios dependiendo la profundidad del nodo
			i++;
		}
		cout << root->dato << endl; // imprime el dato del nodo
		MostrarArbolVert(root->izq, contador + 1); // busca el nodo mas a la izquierda posible
	}
}

void MostrarArbolHorz1(NodoT* root, int contador, int lineaX, int lineaY, int multiplier) // contador: nivel actual del arbol,  
																						//lineaX: posicion en X, lineaY: posicion en Y, multiplier: espacios entre los nodos
{
	if (root == NULL || (!root->der && !root->izq))
	{
		return;
	}
	else
	{
		if (root->padre == NULL)//Imprimir el nodo principal
		{
			string size = to_string(root->dato);
			cout << "                                                  *";
			for (int i = 0; i < ((multiplier - 2) - size.length()) / 2; i++) // -2 para obviar los asteriscos, size/2 para la mitad del numero
			{
				cout << "-";
			}
			cout << root->dato;
			for (int i = 0; i < ((multiplier - 2) - size.length()) / 2; i++)
			{
				cout << "-";
			}
			cout << "*";
		}

		switch (contador)
		{
		case 3:
			multiplier = multiplier / 3;
			lineaX = lineaX - ((multiplier / 2));
			break;
		case 4:
			multiplier = multiplier / 2;
			if (numNiveles == 5) {
				lineaX = lineaX - 5;
			}
			else
			{
				lineaX = lineaX - 3;
			}
			break;
		case 5:
			multiplier = multiplier / 2;
			lineaX = lineaX - 3;

			break;
		}

		for (int j = 0; j < numNiveles - 1; j++)
		{//Imprimir las barras
			if (j + 2 != numNiveles) {
				GoToXY((lineaX - j), lineaY + j);
				cout << "/";
				GoToXY((lineaX + (multiplier + 1) + 2 * j) - j, lineaY + j);
				cout << "\\";
			}
		}
		int j = numNiveles - 2;
		if (root->izq || root->der)
		{
			GoToXY(lineaX - j, lineaY + j);
			cout << "/";
			if (root->izq)
			{
				GoToXY(lineaX - j - ((to_string(root->izq->dato).length()) / 2), lineaY + j + 1);
				cout << root->izq->dato;
				MostrarArbolHorz1(root->izq, contador + 1, (lineaX - j - 1), lineaY + j + 2, multiplier);
			}
			else
			{
				GoToXY(lineaX - j - (4 / 2) - 1, lineaY + j + 1);
				cout << "NULL";
			}
			_getch();
			GoToXY((lineaX + (multiplier + 1) + 2 * j) - j, lineaY + j);
			cout << "\\";
			if (root->der)
			{
				GoToXY(((lineaX + (multiplier + 1) + 2 * j) - (to_string(root->der->dato).length()) / 2) - 2, lineaY + j + 1);
				cout << root->der->dato;
				MostrarArbolHorz1(root->der, contador + 1, (lineaX + (multiplier + 1) + 2 * j) - 3, lineaY + j + 2, multiplier);
			}
			else
			{
				GoToXY(((lineaX + (multiplier + 1) + 2 * j) - (4) / 2), lineaY + j + 1);
				cout << "NULL";
			}
		}
	}
}

void RecPreOrden(NodoT* arbol) //Primero raiz, luego subarbol izq y luego derecho
{
	if (arbol == NULL)
	{
		return;
	}
	else
	{
		cout << arbol->dato << "  -  ";
		RecPreOrden(arbol->izq);
		RecPreOrden(arbol->der);

	}
}

void RecInOrden(NodoT* arbol) //Primero sub arbol izq, luego raiz y por ultimo sub arbol derecho
{
	if (arbol == NULL)
	{
		return;
	}
	else
	{
		RecInOrden(arbol->izq);
		cout << arbol->dato << "  -  ";
		RecInOrden(arbol->der);

	}
}

void RecPostOrden(NodoT* arbol) //Primero subarbol izq, luego subarbol derecho y por ultimo la raiz
{
	if (arbol == NULL)
	{
		return;
	}
	else
	{
		RecPostOrden(arbol->izq);
		RecPostOrden(arbol->der);
		cout << arbol->dato << "  -  ";
	}
}

int main() {
	setlocale(LC_ALL, "spanish"); //idioma local
	SetConsoleCP(1252);           //Cambiar Code Page de la consola para mostrar caracteres en español		
	SetConsoleOutputCP(1252);
	int niveles = 0;
	NodoT* arbol = NULL;
	NodoT* father = NULL;
	int numeroEliminar;
	NodoT* NodoEliminar;
	bool confirmarnumero = true;

	string opcion;
	int contador = 0;
	bool salir = false;

	//Padre
	InsertarEnArbol(arbol, 125, father);
	//Segundo Nivel
	InsertarEnArbol(arbol, 23, father);
	InsertarEnArbol(arbol, 55, father);
	//Tercer Nivel
	//InsertarEnArbol(arbol, 13, father);
	//InsertarEnArbol(arbol, 22, father);
	//InsertarEnArbol(arbol, 43, father);
	//InsertarEnArbol(arbol, 58, father);
	//Cuarto Nivel
	// Caso especial
	InsertarEnArbol(arbol, 15, father);
	InsertarEnArbol(arbol, 13, father);
	InsertarEnArbol(arbol, 18, father);
	InsertarEnArbol(arbol, 7, father);
	InsertarEnArbol(arbol, 14, father);
	//InsertarEnArbol(arbol, 8, father);
	//InsertarEnArbol(arbol, 15, father);
	//InsertarEnArbol(arbol, 19, father);
	//InsertarEnArbol(arbol, 24, father);
	//InsertarEnArbol(arbol, 36, father);
	//InsertarEnArbol(arbol, 48, father);
	//InsertarEnArbol(arbol, 57, father);
	//InsertarEnArbol(arbol, 63, father);
	//Quinito Nivel
	//InsertarEnArbol(arbol, 6, father);
	//InsertarEnArbol(arbol, 9, father);
	//InsertarEnArbol(arbol, 14, father);
	//InsertarEnArbol(arbol, 17, father);
	//InsertarEnArbol(arbol, 23, father);
	//InsertarEnArbol(arbol, 56, father);
	//InsertarEnArbol(arbol, 62, father);
	//InsertarEnArbol(arbol, 72, father);
	//Sexto Nivel
	//InsertarEnArbol(arbol, 5, father);
	//InsertarEnArbol(arbol, 7, father);


	do {
		system("cls");
		cout << "Bienvenido al menú Árboles Binarios\n\nIngrese lo que desea Realizar: \n\n";
		cout << "1) Ingresar Elementos al Árbol Binario.\n";
		cout << "2) Mostrar el Árbol Binario.\n";
		cout << "3) Eliminar Elementos del Árbol Binario.\n";
		cout << "4) Recorrer el árbol en PreOrden. \n";
		cout << "5) Recorrer el árbol en InOrden. \n";
		cout << "6) Recorrer el árbol en PostOrden. \n";
		cout << "7) Mostrar árbol con diseño.\n";
		cout << "0) Salir del Programa.\n";
		cout << "\n Opcion Elegida: ";
		cin >> opcion;

		try
		{
			int num;
			num = stoi(opcion);
		}

		catch (const std::exception)
		{
			opcion = "-1";
		}

		switch (stoi(opcion)) {
		case 1:
			int numero;
			cout << "\nIngrese el numero a introducir: ";
			cin >> opcion;

			try {
				numero = stoi(opcion);
			}
			catch (const std::exception)
			{
				confirmarnumero = false;
			}
			if (confirmarnumero) {
				InsertarEnArbol(arbol, numero, father);
				cout << "\nNumero Introducido correctamente.";

			}
			else
			{
				cout << "\nIntroduzca un mumero válido";
			}
			_getch();
			break;

		case 2:
			cout << "\n\n";
			MostrarArbolVert(arbol, contador);
			_getch();
			break;

		case 3:
			cout << "\n\nIntroduzca el Numero a Eliminar: ";
			cin >> numeroEliminar;
			NodoEliminar = arbol;

			if (BuscarNodoEliminar(NodoEliminar, numeroEliminar))
			{
				cout << "\n\nElemento Eliminado";
			}
			else
			{
				cout << "\n\nElemento No encontrado";
			}

			_getch();
			break;
			break;
		case 4:
			cout << "\nEl recorrido del árbol en PreOrden es: \n";
			if (arbol != NULL)
				RecPreOrden(arbol);
			else cout << "Ninguno. El árbol está vacio, inserte elementos en la opcion 1 del menu.";
			_getch();
			break;
		case 5:
			cout << "\nEl recorrido del árbol en InOrden es: \n";
			if (arbol != NULL)
				RecInOrden(arbol);
			else cout << "Ninguno. El árbol está vacio, inserte elementos en la opcion 1 del menu.";
			_getch();
			break;
		case 6:
			cout << "\nEl recorrido del árbol en PreOrden es: \n";
			if (arbol != NULL)
				RecPreOrden(arbol);
			else cout << "Ninguno. El árbol está vacio, inserte elementos en la opcion 1 del menu.";
			_getch();
			break;
		case 7:
			system("cls");
			BuscarNumNiveles(arbol, 1);
			switch (numNiveles)
			{
			case 2:
				numNiveles = 3;
				MostrarArbolHorz1(arbol, 2, 49, 1, 6);
				break;
			case 3:
				MostrarArbolHorz1(arbol, 2, 49, 1, 6);
				break;
			case 4:
				MostrarArbolHorz1(arbol, 2, 49, 1, 24);
				break;
			case 5:
				MostrarArbolHorz1(arbol, 2, 49, 1, 66);
				break;
			default:
				MostrarArbolHorz2(arbol, 0, numNiveles * 5);
				break;
			}
			_getch();
			numNiveles = 0;
			break;

		case 0:
			cout << "\n\nSaliendo del Programa";
			salir = true;
			_getch();
			break;
		default:
			cout << "\n\nIngrese un numero valido. Presione cualquier letra para continuar.";
			_getch();
			break;
		}
	} while (salir == false);
	return 0;
}