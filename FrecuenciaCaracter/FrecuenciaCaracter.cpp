/*
* ENUNCIADO: TAREA 6. FRECUENCIAS CARACTER
* ASUNTO: Determinar la frecuencia de una letra del alfabeto español en
términos porcentuales. De igual manera el programa debe contrar la cantidad de palabras que
contiene el archivo de texto.
AUTORES: ANGEL MORENO ID:1104666
*        GLEIDY ESPINAL ID:1104225
*        ALLEN SILVERIO ID:1104220
*        CRISTIAN JIMÉNEZ ID:1106166
*        WILLIAM FERREIRA ID:1104228
* FECHA: 12/09/2022
*/


#include <iostream>
#include <fstream> //manejo de archivos
#include <conio.h> //getch


using namespace std;

struct Nodo {
    char dato;
    Nodo* siguiente;
};

void Insertar(Nodo*& lista, char caracter) {
    Nodo* aux1 = lista;
    Nodo* aux2 = new Nodo();
    Nodo* nuevoNodo = new Nodo();

    while (aux1 != NULL && aux1->dato < caracter)
    {
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }
    if (lista == aux1)//Coloca el nuevo nodo al inicio de la lista
    {
        lista = nuevoNodo;
    }
    else//Coloca el nuevo nodo a la derecha del auxiliar 2
    {
        aux2->siguiente = nuevoNodo;
    }
    nuevoNodo->siguiente = aux1;
    nuevoNodo->dato = caracter;
}

void Mostrar(Nodo* lista) {
    Nodo* actual = new Nodo();
    actual = lista;
    while (actual != NULL)
    {
        if (actual->siguiente != NULL) cout << actual->dato << " , ";
        else cout << actual->dato << ".";
        actual = actual->siguiente;
    }
    _getch();
}

int ContarPalabras(string ruta) 
{
    ifstream archivo(ruta);
    string palabra;
    int contador = 0;

    if (archivo.is_open())
    {
        while (archivo.good())
        {
            archivo >> palabra;
            cout << palabra << endl;
            contador++;
        }
    }
    archivo.close();
    return contador;
}

void recogerCaracteres(Nodo *&lista, string ruta)
{
    ifstream archivo(ruta);
    char caracter;

    if (archivo.is_open())
    {
        while (archivo.good())
        {
            caracter = archivo.get();
            Insertar(lista, caracter);
        }
    }
    archivo.close();
}


int main()
{
    Nodo* lista = NULL;
    string ruta = "PruebaChar.txt";
   
    cout << "La cantidad de palabras en el archivo es: " << ContarPalabras(ruta) << endl;
    recogerCaracteres(lista, ruta);
    Mostrar(lista);
   
    
}

