
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

//Un Clock (Ciclo) en un procesador es un pulso sincronizado entre los transistores de un procesador, cambiando de abirtos a cerrados.
//La cantidad de veces que un procesador cambia de estado (clocks por segundo) se expreza en GigaHercios (Mil Millones de Veces por Segundo)

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <ctime>//Para el manejo del tiempo
using namespace std;

HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);//Obtenemos la salida estandar (CONSOLA)

unsigned t0, t1;//Variables sin signo para calcular el tiempo de ejecucion del programa mas adelantes 

int ValidarEntrada(string &entrada) {//Valida las entradas para que no sean letras sino numeros.
	
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

bool ValidarAnillos(int &anillos) {//Valida que la cantidad de anillos sea positiva y mayor que 0.

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

void DeterminarTorreColores(int Torre)//Cambia el Texto de las Torres de Numeros a Letras Y Le Asigna Colores
{
	switch (Torre)
	{
	case 1:
		SetConsoleTextAttribute(hconsole, 4);
		cout << "Torre A";
		SetConsoleTextAttribute(hconsole, 7);
		break;
	case 2:
		SetConsoleTextAttribute(hconsole, 2);
		cout << "Torre B";
		SetConsoleTextAttribute(hconsole, 7);
		break;
	case 3:
		SetConsoleTextAttribute(hconsole, 6);
		cout << "Torre C";
		SetConsoleTextAttribute(hconsole, 7);
		break;
	}
}
	
void ImpresionColores(int origen, int destino, int anillo, int cont) //Imprime el Texto de las Torres y los Anillos con Colores
{
	cout << "\nPaso #" << cont << " Se movio el anillo ";
	
	SetConsoleTextAttribute(hconsole, 12);
	cout << anillo;
	SetConsoleTextAttribute(hconsole, 7);
	cout << " desde la ";
	DeterminarTorreColores(origen);
	cout << " hasta la ";
	DeterminarTorreColores(destino);
}

string DeterminarTorreEficiente(int Torre)//Cambia SOLO el Numero de las Torres a Letras (Mas Eficiente)
{
	switch (Torre)
	{
	case 1:
		return "Torre A";
		break;
	case 2:
		return "Torre B";
		break;
	case 3:
		return "Torre C";
		break;
	}
	return "";
}

void TorresHanoiEficiente(int anillos, int origen, int destino, int auxiliar, unsigned long long& cont) { //Algoritmo de Resolucion
																										  //Eficiencia sobre Belleza

	if (anillos > 0)
	{
		TorresHanoiEficiente(anillos - 1, origen, auxiliar, destino, cont);
		cout << "\nPaso #" << cont << " Se movio el anillo " << anillos << " desde la torre " << DeterminarTorreEficiente(origen) << " hasta la torre " << DeterminarTorreEficiente(destino);
		cont++;
		TorresHanoiEficiente(anillos - 1, auxiliar, destino, origen, cont);
	}
	return;
}

//1           //3       //2
void TorresHanoiColores(int anillos, int origen, int destino, int auxiliar, unsigned long long &cont) {//Algoritmo de Resolucion
																									   //Belleza sobre Eficiencia
	if (anillos>0)
	{
		TorresHanoiColores(anillos - 1, origen, auxiliar, destino, cont);
		ImpresionColores(origen, destino, anillos, cont);
		cont++;
		TorresHanoiColores(anillos - 1, auxiliar, destino, origen, cont);
	}
	return;
}

int main() {
	setlocale(LC_ALL, "spanish"); //idioma local
	SetConsoleCP(1252);           //Cambiar Code Page de la consola para mostrar caracteres en español		
	SetConsoleOutputCP(1252);
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
		cout << "\n\n [1] Calcular Pasos (Funcion con Colores)";
		cout << "\n\n [2] Calcular Pasos (Funcion Más Eficiente)";
		cout << "\n\n [0] Salir del programa\n";
		cout << "\nOpcion Elegida: ";
		cin >> opcion;
		int nOpcion = ValidarEntrada(opcion);
		int minutos;
		int segundos;

		switch (nOpcion)
		{

		case 0:
			salir = true;
			break;

		case 1:
			do
			{
				system("cls");
				cout << "\nInserte el numero de anillos: ";
				cin >> sAnillos;
				anillos = ValidarEntrada(sAnillos);
				anillosValidos = ValidarAnillos(anillos);
			} while (!anillosValidos);
			t0 = clock();
			TorresHanoiColores(anillos, 1, 3, 2, cont);
			t1 = clock();
			cout << "\n\nEl numero de pasos fue: " << cont-1;
			minutos = (double(t1 - t0) / CLOCKS_PER_SEC) / 60;
			segundos = int((double(t1 - t0) / CLOCKS_PER_SEC)) - minutos * 60;
			cout << "\n\nEl tiempo que duro fue de: " << minutos << " minutos y " << segundos << " segundos.";
			cout << "\n\nPresione cualquier tecla para volver al menu\n";
			_getch();
			break;
		case 2:
			do
			{
				system("cls");
				cout << "\nInserte el numero de anillos: ";
				cin >> sAnillos;
				anillos = ValidarEntrada(sAnillos);
				anillosValidos = ValidarAnillos(anillos);
			} while (!anillosValidos);
			t0 = clock();//Obtiene los ciclos con los que inicio el procesador a ejecutar el algoritmo
			TorresHanoiEficiente(anillos, 1, 3, 2, cont);
			t1 = clock();//Obtiene los ciclos con los que terminó el procesador a ejecutar el algoritmo
			cout << "\n\nEl numero de pasos fue: " << cont - 1;
		    minutos = (double(t1 - t0) / CLOCKS_PER_SEC) / 60;//Obtnemos la cantidad de minutos que tardó en ejecutar el algoritmo
			segundos = int((double(t1 - t0) / CLOCKS_PER_SEC)) - minutos * 60;//Obtnemos la cantidad de segundos que tardó en ejecutar el algoritmo
			cout << "\n\nEl tiempo que duro fue de: "<< minutos << " minutos y " << segundos << " segundos.";
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
