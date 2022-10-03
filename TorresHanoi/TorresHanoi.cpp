
/*
* ENUNCIADO: TAREA 8. TORRES DE HANOI
* ASUNTO: ESTE PROGRAMA CALCULA LOS PASOS NECESARIOS PARA EL JUEGO DE LA TORRE DE HANOI CON N ANILLOS
*
AUTORES: ANGEL MORENO ID:1104666
*        GLEIDY ESPINAL ID:1104225
*        ALLEN SILVERIO ID:1104220
*        CRISTIAN JIMÉNEZ ID:1106166
*        WILLIAM FERREIRA ID:1104228
* FECHA: 3/10/2022
*/

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>

using namespace std;

int ValidarEntrada(string &entrada) {
	
	int num;
	try
	{
		num = stoi(entrada);
	}
	catch (const std::exception)
	{
		entrada = "-1";
	}

	num = stoi(entrada);
	return num;
}

bool ValidarAnillos(int &anillos) {

		if (anillos > 0)
		{
			return true;
		}
		else
		{
			cout << "Cantidad de anillos no válida";
			return false;
		}
}
								//1     //3     //2
void TorresHanoi(int anillos, int origen, int destino, int auxiliar, long double &cont) {

	if (anillos>0)
	{
		TorresHanoi(anillos - 1, origen, auxiliar, destino, cont);
		cout << "\nSe movio el anillo " << anillos << " desde la torre " << origen << " hasta la torre " << destino;
		cont++;

		TorresHanoi(anillos - 1, auxiliar, destino, origen, cont);
	}
	return;
}

int main() {

	long double cont = 0;
	int anillos = 0;
	bool anillosValidos = false;
	bool salir = false;
	string sAnillos = "";
	string opcion = "";
	
	do
	{
		cout << "\nBienvenido a las torres de Hanoi, que desea hacer?: ";
		cin >> opcion;
		int nOpcion = ValidarEntrada(opcion);

		switch (nOpcion)
		{

		case 0:
			salir = true;
			break;

		case 1:
			
			do
			{
				cout << "\nInserte el numero de anillos: ";
				cin >> sAnillos;
				anillos = ValidarEntrada(sAnillos);
				anillosValidos = ValidarAnillos(anillos);
			} while (!anillosValidos);

			TorresHanoi(anillos, 1, 3, 2, cont);
			cout << "\n\nEl numero de pasos fue: " << cont;
			break;

		default:
			cout << "Error. Opcion no válida";
			break;
		}
	} while (!salir);
	
	return 0;
}
