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
#include <locale>
#include <Windows.h>

using namespace std;

struct NodoT {
    unsigned char dato;
    NodoT* siguiente;
};

void Insertar(NodoT*& lista, unsigned char caracter) {
    NodoT* aux1 = lista;
    NodoT* aux2 = new NodoT();
    NodoT* nuevoNodo = new NodoT();

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

void Mostrar(NodoT* lista) {
    NodoT* actual = new NodoT();
    actual = lista;
    while (actual != NULL)
    {
        if (actual->siguiente != NULL) cout << actual->dato << " , ";
        else cout << actual->dato << ".";
        actual = actual->siguiente;
    }
}


int ContarPalabras(string ruta)
{
    ifstream archivo(ruta.c_str());
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

bool acentos(unsigned char& letra)
{
    int asciiLetra = int(letra);
    switch (asciiLetra)
    {
    case 225:
        letra = 'a';
        return true;
        break;

    case 233:
        letra = 'e';
        return true;
        break;

    case 237:
        letra = 'i';
        return true;
        break;

    case 243:
        letra = 'o';
        return true;
        break;

    case 250:
        letra = 'u';
        return true;
        break;

    case 255:
        return false;
        break;

    default:
        return true;
        break;
    }
}


void recogerCaracteres(NodoT*& lista, string ruta, float& contadorEspacios)
{
    ifstream archivo(ruta.c_str());
    unsigned char caracter;
    bool valido = true;

    if (archivo.is_open())
    {
        while (archivo.good())
        {
            caracter = archivo.get();
            contadorEspacios++;
            if (isalpha(caracter))
            {
                caracter = tolower(caracter);
                valido = acentos(caracter);
                if (valido) Insertar(lista, caracter);
            }
        }
    }
    archivo.close();
}

void frecuenciaChars(NodoT* lista, string ruta, float espaciosTotales)
{
    NodoT* aux1 = new NodoT();
    NodoT* aux2 = new NodoT();
    aux1 = NULL;
    aux2 = lista;
    float repeticiones = 1;
    float porcentaje;
    bool finLista = false;

    while (aux2 != NULL && !finLista)
    {
        if (aux2->siguiente != NULL)
        {
            while (aux2->dato == aux2->siguiente->dato)
            {
                repeticiones++;
                aux2 = aux2->siguiente;
            }
        }
        porcentaje = ((repeticiones / espaciosTotales) * 100);
        cout << aux2->dato << ": (" << repeticiones << "/" << espaciosTotales << ") --> " << porcentaje << "%" << endl;

        repeticiones = 1;
        if (aux2->siguiente != NULL) {
            aux1 = aux2;
            aux2 = aux2->siguiente;
        }
        else finLista = true;
    }
}

int main()
{
    setlocale(LC_ALL, "spanish");
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);

    NodoT* lista = NULL;
    string ruta = "PruebaChar.txt";
    float espaciosTotales = 0;

    cout << "La cantidad de palabras en el archivo es: " << ContarPalabras(ruta) << endl;
    recogerCaracteres(lista, ruta, espaciosTotales);
    Mostrar(lista);
    cout << endl;
    frecuenciaChars(lista, ruta, espaciosTotales);
}


