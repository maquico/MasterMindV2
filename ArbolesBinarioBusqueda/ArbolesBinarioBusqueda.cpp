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

using namespace std;

struct Nodo {
	int dato;
	Nodo* izq;
	Nodo* der;
};

