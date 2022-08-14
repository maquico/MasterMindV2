
/*
* ENUNCIADO: TAREA 2. CUBOS NARCICISTAS
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

using namespace std;

int ValidarNum(string numero)
{
	bool numValido;
	if (numero.length() != 3)
	{
		return 0;
	}
	else
	{
		for (int i = 0; i < 3; i++)
		{
			if (!isdigit(numero[i]))
			{
				return 1;
			}
		}
	}
	return 2;
}

bool DeterminarNumNarcicista(string numero) 
{
	bool esNarcicista;


	return esNarcicista;
}

int main()
{
	cout << ValidarNum("123");
	cout << ValidarNum("1234");
	cout << ValidarNum("12");
	cout << ValidarNum("12a3");
	cout << ValidarNum("a12");
	cout << ValidarNum("aaa");
	cout << ValidarNum("1a2");
	

}
