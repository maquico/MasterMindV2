
/*
* ENUNCIADO: TAREA 2. CUBOS NARCICISTAS
* ASUNTO: ESTE PROGRAMA ENCUENTRA LOS NUMEROS NARCICISTAS COMPRENDIDOS ENTRE EL 100 Y EL 999
AUTORES: ANGEL MORENO ID:1104666
*        GLEIDY ESPINAL ID:1104225
*        ALLEN SILVERIO ID:1104220
*        CRISTIAN JIMÉNEZ ID:1106166
*        WILLIAM FERREIRA ID:1104228
* FECHA: 15/08/2022
*/

#include <iostream>
#include <string>
#include <conio.h>
#include <stdio.h>

using namespace std;

int main()
{

	bool close = false, hayLetra=false;
	do {
		char numero[256];
		string opcion;
		system("cls");
		printf("Bienvenido al programa que le dira los numeros narcisistas entre 100 y 999.\n\n");
		printf("Elija una de las siguientes opciones:\n\n");
		printf("1) Que son los numeros narcisistas?\n");
		printf("2) Mostrar los numeros narcisistas entre 100 y 999.\n");
		printf("0) Cerrar programa.\n\n");
		printf("Opcion elejida: ");
		cin >> opcion;
		
		for ( int i = 0;  i < opcion.length();  i++)
		{
			if (!isdigit(opcion[i]))
			{
				hayLetra = true;
			}
			else
			{
				hayLetra = false;
			}
		}
		
		if (hayLetra)
		{
			cout << "\n\nNo coloque letras. Elija una de las opciones disponibles";
			_getch();
			system("cls");
		}
		else
		{
			switch (stoi(opcion))
			{
			case 0:
				system("cls");
				close = true;
				break;
			case 1:
				system("cls");
				cout << "Son cubos narcisistas aquellos numeros positivos que son \nexactamente iguales a la suma de sus digitos elevados al cubo.\n";
				cout << "Es decir, 370 y 371 son ambos cubos narcisistas, ya que:\n";
				cout << "	370 = 33 + 73 + 03\n";
				cout << "	371 = 33 + 73 + 13\n";
				cout << "Sin embargo, 483 no es igual 4^3 + 8^3 + 3^3";

				_getch();
				break;
			case 2:
				system("cls");
				cout << "Los numeros narcisistas entre el 100 y el 99 son: \n\n";
				for (int i = 100; i < 1000; i++)
				{
					string numero = to_string(i);
					int suma = 0;

					for (int j = 0; j < 3; j++)
					{
						char digito[1] = { numero[j] };
						suma += pow(atoi(digito), 3);
					}
					if (suma == i)
					{
						cout << i << "\n\n";
					}
				}
				_getch();
				break;
			default:
				cout << "\n\nLa opcion no es parte del menu. Elija una de las opciones disponibles";
				_getch();
				system("cls");
				break;
			}
		}	
	} while (!close);
	return 0;

}
