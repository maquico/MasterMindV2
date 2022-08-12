
/*
* ENUNCIADO: TAREA 1. MASTERMIND BEGINNERS
* ASUNTO:
*
AUTORES: ANGEL MORENO ID:1104666
*        GLEIDY ESPINAL ID:1104225
*        ALLEN SILVERIO ID:1104220
*        CRISTIAN JIMÉNEZ ID:1106166
*        WILLIAM FERREIRA ID:1104228
* FECHA: 15/08/2022
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <Windows.h>
#include <conio.h>
// #include "TextTable.h"

using namespace std;

int ValidarClave(string intento, string claveActual, int i) {
	
	
	// 0 indica longitud erronea, 1 indica repetidos, 2 indica que hay letras, 3 indica que la clave tiene numeros diferentes de 1, 2, 3, 4, 5, 6
	bool hayLetras = false, wlongitud = false;
	
	bool limitenumeros = false;
	
	if (intento.length() != 1)
	{
		return 0;
	}
	else if (!isdigit(intento[0])) {
		return 2;
	}
	else if (stoi(intento) < 0 || stoi(intento) > 6)
	{
		return 3;
	}
	else if (i!=0 )
	{
		for (int j = 0; j <= i; j++)
		{
			if (claveActual[j]==intento[0])
			{
				return 1;
			}
		}
	}
			
}

void GoToXY(int x, int y)
{
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hCon, dwPos);
}
string GenerarNumRand() {

	int random;
	bool duplicado = false;
	string numActual, clave;
	for (int i = 0; i < 4; i++)
	{
		random = (rand() % 6) + 1; //genera numero random de 1 a 6
		numActual = to_string(random)[0];

		if (i != 0) // luego de que se genere el segundo numero
		{
			for (int j = 0; j < i; j++)
			{
				if (clave[j] == numActual[0]) //compara si un numero es igual a otro que ya este en la clave
				{
					duplicado = true;
				}
			}
			if (duplicado)
			{
				i--;
				duplicado = false;
			}
			else
			{
				clave += numActual;
			}
		}
		else
		{
			clave = numActual;
		}
	}
	return clave;
}



int Jugar(string clave) {

	string claveActual, pista, cIntento;
	
	bool numDentro = false;
	int tabla1x = 18;
	int tablay = 8;
	int tabla2x = 59;

	cout << "--------------------------Bienvenido a MasterMind--------------------------\n";
	cout << " Vaya introduciendo numero por numero, uno por uno. Luego de escribir un numero\n";
	cout << " de la clave de enter para introducir el otro hasta en introducir los 4 numeros\n";
	cout << " por intento. No introducir mas de 1 numero por columna.  Clave: " << clave << ".\n\n";
	cout << "|         |---Tabla Juego---|                   |---Tabla Pista---|             |\n";
	cout << "|-------------------------------------------------------------------------------|\n";
	cout << "| Calificacion |  A  |  B  |  C  |  D  |  || | Intentos |  A  |  B  |  C  |  D  |\n"; 

	for (int i = 10, m=9; i >0; i--, m-=2)
	{	
		if (i != 10 && i!=1) {
			cout << "|    0" << (i) << "        |     |     |     |     |  || |    0" << (i-m) << "    |     |     |     |     |\n";
			cout << "|--------------|-----|-----|-----|-----|  || |----------|-----|-----|-----|-----|\n";
		}
		
		else if(i==10)
		{
			cout << "|    " << (i) << "        |     |     |     |     |  || |    0" << (i-m) << "    |     |     |     |     |\n";
			cout << "|--------------|-----|-----|-----|-----|  || |----------|-----|-----|-----|-----|\n";
		}
		else if (i == 1) 
		{
			cout << "|    0" << (i) << "        |     |     |     |     |  || |    " << (i - m) << "    |     |     |     |     |\n";
			cout << "|--------------|-----|-----|-----|-----|  || |----------|-----|-----|-----|-----|\n";
		}
	}
	cout << "---------------------------------------------------------------------------------\n";

	for (int j = 0; j < 10; j++)
	{
		if (claveActual != clave)
		{
			claveActual = "";
			for (int z = 0; z < 4; z++)
			{
				GoToXY(0, 30);
				cout << "Numero a ingresar :                                                                ";
				GoToXY(20, 30);
				cin >> cIntento;
				switch (ValidarClave(cIntento, claveActual, z))
				{
				case 0:
					//longitud erronea;
					cout << "Longitud erronea\n";
					cout << "Presione cualquier tecla para continuar";
					_getch();
					GoToXY(0, 31);
					cout << "                \n";
					cout << "                                       ";
					z--;
					break;
				case 1:
					//repetidos
					cout << "Numeros repetidos\n";
					cout << "Presione cualquier tecla para continuar";
					_getch();
					GoToXY(0, 31);
					cout << "                 \n";
					cout << "                                       ";
					z--;
					break;
				case 2:
					//hay letras
					cout << "Por favor no pongas letras\n";
					cout << "Presione cualquier tecla para continuar";
					_getch();
					GoToXY(0, 31);
					cout << "                          \n";
					cout << "                                       ";
					z--;
					break;
				case 3:
					//Numero menor que 1 o mayor que 6
					cout << "La clave no puede tener numeros menores que 1 o mayores que 6\n";
					cout << "Presione cualquier tecla para continuar";
					_getch();
					GoToXY(0, 31);
					cout << "                                                              \n";
					cout << "                                                              ";
					z--;
					break;
				default:
					cout << "Duro\n\n";

					GoToXY(tabla1x, tablay);
					cout << cIntento;
					claveActual += cIntento;
					tabla1x += 6;
					break;
				}
			}
			for (int k = 0; k < 4; k++) // clave 6513           intento 6415
			{
				for (int l = 0; l < 4 && !numDentro; l++)
				{
					if (claveActual[k] == clave[l] && k == l)
					{
						pista += "C";
						numDentro = true;
					}
					else if (claveActual[k] == clave[l])
					{
						pista += "F";
						numDentro = true;
					}
				}
				if (!numDentro)
				{
					pista += "X";
				}
				else
				{
					numDentro = false;
				}
				GoToXY(tabla2x, tablay);
				cout << pista;
				pista = "";
				tabla2x += 6;
			}
			tabla1x = 18;
			tabla2x = 59;
			tablay += 2;
			
		}
		else
		{
			return 1;
		}

		}
		
	return 0;
}

int main()
{
	srand(time(NULL));
	string numRand;
	bool salir = false;
	numRand = GenerarNumRand();
	Jugar(numRand);
	
	//5a64
	do
	{

	} while (true);

	return 0;
}

