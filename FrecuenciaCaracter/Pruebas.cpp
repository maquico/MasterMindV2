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

struct Nodo {
    unsigned char dato;
    int repeticiones = 1;
    Nodo* siguiente;
};

void Insertar(Nodo*& lista, unsigned char caracter) {
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

void BuscarElemento(Nodo*& lista, int entrada) { //Se le pasa el nodo lista de tipo puntero (que representa el primer elemento de la lista) y se le pasa el dato buscar.


    while (lista != NULL) //Mientras el nodo actual sea diferente de nulo (no sea el que le sigue al ultimo nodo de la lista) y el dato del nodo actual sea menor o igual que el dato a buscar
    {
        if (lista->dato == entrada) //Se verifica si el dato del nodo actual es igual al dato a buscar
        {
            break;//El elemento existe asi que se sale del bucle
        }
        lista = lista->siguiente;
    }
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
            cout << palabra << ", ";
            contador++;
        }
    }
    cout << "\n\n";
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


void recogerCaracteres(Nodo*& lista, string ruta, float& contadorEspacios)
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
                Nodo* NuevoNodo = lista;
                BuscarElemento(NuevoNodo, caracter);
                    if (valido && NuevoNodo == NULL)
                    {
                        Insertar(lista, caracter);
                    }
                    else if(NuevoNodo != NULL)
                    {
                        NuevoNodo->repeticiones++;
                    }
            }
        }
    }
    contadorEspacios--;
    archivo.close();
}

void frecuenciaChars(Nodo* lista, string ruta, float espaciosTotales)
{
    Nodo* aux1 = new Nodo();
    aux1 = lista;
    float repeticiones = 1;
    float porcentaje;
    bool finLista = false;

    while (aux1 != NULL)
    {
        porcentaje = ((aux1->repeticiones / espaciosTotales) * 100);
        cout << aux1->dato << ": (" << aux1->repeticiones << "/" << espaciosTotales << ") --> " << porcentaje << "%" << endl;

            aux1 = aux1->siguiente;
        }
    }

int main()
{
    setlocale(LC_ALL, "spanish");
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);

    Nodo* lista = NULL;
    string ruta = "PruebaChar2.txt";
    float espaciosTotales = 0;

    cout << "La cantidad de palabras en el archivo es: " << ContarPalabras(ruta) << endl;
    recogerCaracteres(lista, ruta, espaciosTotales);
    Mostrar(lista);
    cout << endl;
    frecuenciaChars(lista, ruta, espaciosTotales);
}
