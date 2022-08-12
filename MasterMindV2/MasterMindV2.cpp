
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
// #include "TextTable.h"

using namespace std;

int ValidarClave(string intento) {
	
	
	// 0 indica longitud erronea, 1 indica repetidos, 2 indica que hay letras, 3 indica que la clave tiene numeros diferentes de 1, 2, 3, 4, 5, 6
	bool hayLetras = false;
	bool limitenumeros = false;
	
		for (int i = 0; i < 4; i++)
		{
			if (!isdigit(intento[i]))
			{
				
				hayLetras = true;
			}
			char numero[1] = { intento[i] };
			if (atoi(numero) < 0 || atoi(numero) > 6)
			{
				limitenumeros = true;
			}
		}
	
		if (hayLetras)
		{
			return 2;
		}
		else if (limitenumeros) 
		{
			return 3;
		}
	else if (intento.length() == 4) 
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = i + 1; j < 4; j++)
			{
				if (intento[i] == intento[j])
				{
					return 1;
					

				}
			}
		}
	}
	else
	{
		return 0;
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


int ValidarClave(string intento) {


	// 0 indica longitud erronea, 1 indica repetidos, 2 indica que hay letras, 3 indica que la clave tiene numeros diferentes de 1, 2, 3, 4, 5, 6
	bool hayLetras = false;
	bool limitenumeros = false;

	for (int i = 0; i < 4; i++)
	{
		if (!isdigit(intento[i]))
		{

			hayLetras = true;
		}
		char numero[1] = { intento[i] };
		if (atoi(numero) < 0 || atoi(numero) > 6)
		{
			limitenumeros = true;
		}
	}

	if (hayLetras)
	{
		return 2;
	}
	else if (limitenumeros)
	{
		return 3;
	}
	else if (intento.length() == 4)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = i + 1; j < 4; j++)
			{
				if (intento[i] == intento[j])
				{
					return 1;


				}
			}
		}
	}
	else
	{
		return 0;
	}

}

int Jugar(string clave) {

	string intento, pista;
	char cIntento;
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
		if (intento != clave)
		{
			
			GoToXY(0, 30); 
			cout << "Numero a ingresar :                                                                ";
			GoToXY(20, 30);
			cin >> intento;
			switch (ValidarClave(intento))
			{
			case 0:
				//longitud erronea;
				cout << "Longitud erronea\n\n";
				j--;
				break;
			case 1:
				//repetidos
				cout << "Numeros repetidos\n\n";
				j--;
				break;
			case 2:
				//hay letras
				cout << "Por favor no pongas letras\n\n";
				j--;
				break;
			case 3:
				//Numero menor que 1 o mayor que 6
				cout << "La clave no puede tener numeros menores que 1 o mayores que 6\n\n";
				break;
			default:
				cout << "Duro\n\n";
				intento += cIntento;
				GoToXY(tabla1x, tablay);
				cout << cIntento;
				for (int k = 0; k < 4; k++) // clave 6513           intento 6415
				{
					for (int l = 0; l < 4 && !numDentro; l++)
					{
						if (intento[k] == clave[l] && k == l)
						{
							pista += "C";
							numDentro = true;
						}
						else if (intento[k] == clave[l])
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
				}
				cout << pista;
				pista = "";
				break;
			}
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

