
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
// #include "TextTable.h"

using namespace std;

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
	bool numDentro = false;

	for (int i = 0; i < 10; i++)
	{
		cout << "Intento #" << i + 1 << " de 10: \n\n";
		cout << "Ingrese el numero de 4 digitos: ";
		cin >> intento;

		

		switch (ValidarClave(intento))
		{
		case 0:
			//longitud erronea;
			cout << "Longitud erronea\n\n";
			i--;
			break;
		case 1:
			//repetidos
			cout << "Numeros repetidos\n\n";
			i--;
			break;
		case 2:
			//hay letras
			cout << "Por favor no pongas letras\n\n";
			i--;
			break;
		case 3: 
			//Numero menor que 1 o mayor que 6
			cout << "La clave no puede tener numeros menores que 1 o mayores que 6\n\n";
			break;
		default:
			cout << "Duro\n\n";
			for (int j = 0; j < 4; j++) // clave 6513           intento 6415
			{
				for (int k = 0; k < 4 && !numDentro; k++)
				{
					if (intento[j] == clave[k] && j == k)
					{
						pista += "C";
						numDentro = true;
					}
					else if (intento[j] == clave[k])
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
	return 0;
}

int main()
{
	srand(time(NULL));
	string numRand;
	bool salir = false;
	numRand = GenerarNumRand();
	cout << numRand;
	Jugar(numRand);
	
	//5a64
	do
	{

	} while (true);

	return 0;
}

