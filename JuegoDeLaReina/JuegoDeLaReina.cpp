#include <iostream>
#include <string>
#include <Windows.h>
#include <cstdlib>
#include <conio.h>


using namespace std;

//Variables Globales
HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
#define TECLA_ARRRIBA 72
#define TECLA_ABAJO 80
#define ENTER 13


//Prototipado de Funciones
void TituloMenu();
int FuncionMenu();
void GoToXY(int, int);
int main() 
{

	switch (FuncionMenu()) 
	{
	case 1:
		break;
	case 2: 
		break;
	case 3:
		return 0;
		break;
	}

}

int FuncionMenu() {
	int tecla, yflecha = 13, opcionSeleccionada = 1;
	bool repetir = true;
	do {
		system("cls");
		TituloMenu();
		GoToXY(33, 11);
		cout << "Elija la Opcion que desea realizar:";
		GoToXY(36, 13);
		cout << "\t1)Ir al Juego.";
		GoToXY(36, 14);
		cout << "\t2)Explicacion.";
		GoToXY(36, 15);
		cout << "\t3)Salir.\n";
		GoToXY(36, yflecha);
		cout << "==>";
		do 
		{
			tecla = _getch();
		}
		 while (tecla != TECLA_ARRRIBA && tecla != TECLA_ABAJO && tecla != ENTER);

		switch (tecla) 
		{
		case TECLA_ARRRIBA:
			if (yflecha>13) 
			{
				yflecha--;
				opcionSeleccionada--;
			}
			break;
		case TECLA_ABAJO:
			if (yflecha<15) 
			{
				yflecha++;
				opcionSeleccionada++;
			}
			break;
		case ENTER:
			repetir = false;
			return opcionSeleccionada;
			break;
		}

	} while (repetir);
}

void TituloMenu() 
{
	GoToXY(26,8);
	cout<< " -------------------------------------------------";
	GoToXY(26, 9);
	cout << "|  Bienvenido al Juego de la "; 
	SetConsoleTextAttribute(hconsole, 2);
	cout << "Reina";
	SetConsoleTextAttribute(hconsole, 7);
	cout << " vs ";
	SetConsoleTextAttribute(hconsole, 4);
	cout << "Las Torres  ";
	SetConsoleTextAttribute(hconsole, 7);
	cout << "|";
	GoToXY(26, 10);
	cout << " ------------------------------------------------ - ";
}

void GoToXY(int x, int y)
{
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hconsole, dwPos);
}