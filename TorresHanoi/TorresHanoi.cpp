
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
			cout << "\nCantidad de anillos no valida";
			cout << "\n\nPresione cualquier tecla para volver a insertar anillos\n";
			_getch();
			return false;
		}
}
								//1           //3       //2
void TorresHanoi(int anillos, int origen, int destino, int auxiliar, unsigned long long &cont) {

	if (anillos>0)
	{
		TorresHanoi(anillos - 1, origen, auxiliar, destino, cont);
		cout << "\nPaso #"<< cont << " Se movio el anillo " << anillos << " desde la torre " << origen << " hasta la torre " << destino;
		cont++;
		TorresHanoi(anillos - 1, auxiliar, destino, origen, cont);
	}
	return;
}

int main() {

	unsigned long long cont = 1;
	int anillos = 0;
	bool anillosValidos = false;
	bool salir = false;
	string sAnillos = "";
	string opcion = "";
	
	do
	{
		cont = 1;
		system("cls");
		cout << "---Bienvenido a las torres de Hanoi, que desea hacer?---";
		cout << "\n\n [1] Calcular pasos";
		cout << "\n\n [0] Salir del programa\n";
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
				system("cls");
				cout << "\nInserte el numero de anillos\n";
				cin >> sAnillos;
				anillos = ValidarEntrada(sAnillos);
				anillosValidos = ValidarAnillos(anillos);
			} while (!anillosValidos);

			TorresHanoi(anillos, 1, 3, 2, cont);
			cout << "\n\nEl numero de pasos fue: " << cont-1;

			cout << "\n\nPresione cualquier tecla para volver al menu\n";
			_getch();
			break;

		default:
			cout << "\nError. Opcion no valida";
			cout << "\n\nPresione cualquier tecla para volver al menu\n";
			_getch();
			break;
		}
	} while (!salir);
	
	return 0;
}
