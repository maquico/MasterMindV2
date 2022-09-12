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
#include <locale> //setlocale
#include <Windows.h> //setConsoleCP

using namespace std;

struct Nodo {
    unsigned char dato;
    int repeticiones=1;
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


    while (lista != NULL) //Mientras el nodo actual sea diferente de nulo (no sea el que le sigue al ultimo nodo de la lista) 
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

    case 255:    //el caracter es el terminador de archivo, no se ingresará a la lista
        return false;
        break;

    default:
        return true;
        break;
    }
}

void recogerCaracteres(Nodo*& lista, string ruta, float& contadorEspacios, float& contadorLetras)
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
            	contadorLetras++;
                caracter = tolower(caracter);
                valido = acentos(caracter);
                Nodo* NuevoNodo = lista;
                BuscarElemento(NuevoNodo, caracter);
                    if (valido && NuevoNodo == NULL) //No encontró el caracter, lo agrega a la lista
                    {
                        Insertar(lista, caracter);
                    }
                    else if(NuevoNodo != NULL) //Encontró el caracter en la lista, le aumenta 1 al atributo repeticiones
                    {
                        NuevoNodo->repeticiones++;
                    }
            }
        }
    }
    contadorEspacios--;
    contadorLetras--;
    archivo.close();
}

void frecuenciaChars(Nodo* lista, string ruta, float espaciosTotales, float letrasTotales)
{
    Nodo* aux1 = new Nodo();
    aux1 = lista;
    float repeticiones = 1;
    float porcentaje1, porcentaje2;
    bool finLista = false;

    while (aux1 != NULL)
    {
        porcentaje1 = ((aux1->repeticiones / espaciosTotales) * 100);
        porcentaje2 = ((aux1->repeticiones / letrasTotales) * 100);
        cout << aux1->dato << ": % TOTAL: (" << aux1->repeticiones << "/" << espaciosTotales << ") -->  " << porcentaje1 << "%";
        cout << " | % LETRAS: (" << aux1->repeticiones << "/" << letrasTotales << ") -->  " << porcentaje2 << "%" << endl;

            aux1 = aux1->siguiente;
        }
    }

int main()
{
    setlocale(LC_ALL, "spanish"); //idioma local
    SetConsoleCP(1252);           //Cambiar Code Page de la consola para mostrar caracteres en español		
    SetConsoleOutputCP(1252);

    Nodo* lista = NULL;
    string ruta = "PruebaChar2.txt";
    float espaciosTotales = 0;
    float letrasTotales = 0;

    cout << "La cantidad de palabras en el archivo es: " << ContarPalabras(ruta) << endl;
    recogerCaracteres(lista, ruta, espaciosTotales, letrasTotales);
    Mostrar(lista);
    cout << endl;
    frecuenciaChars(lista, ruta, espaciosTotales, letrasTotales);
}
