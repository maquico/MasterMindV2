// Pueba de colas.cpp 
//
/*
* ENUNCIADO: TAREA 3. PILAS (STACK)
* ASUNTO: ESTE PROGRAMA PERMITE HACER LAS OPERACIONES PUSH, POP Y DESPLEGAR PILA
AUTORES: ANGEL MORENO ID:1104666
*        GLEIDY ESPINAL ID:1104225
*        ALLEN SILVERIO ID:1104220
*        CRISTIAN JIMÉNEZ ID:1106166
*        WILLIAM FERREIRA ID:1104228
* FECHA: 22/08/2022
*/

#include <stdlib.h> // new, delete
#include <string>
#include <conio.h> // getch
#include <iostream>
using namespace std;


//Estructura de cada nodo de la cola
struct Node
{
    int data;
    Node* next;
};

//Funcion para determinar si la cola esta vacia.
bool Empty_Queue(Node* front)
{
    return(front == NULL) ? true : false;
}

//Funcion para agregar un elemento a la cola.
void Enqueue(Node*& front, Node*& back, int n)
{
    Node* new_Node = new Node();
    new_Node->data = n;
    new_Node->next = NULL;

    if (Empty_Queue(front))
    {
        front = new_Node;
    }
    else
    {
        back->next = new_Node;
    }

    back = new_Node;
    cout << "Elemento " << n << " agregado a la cola correctamente " << endl;
}

//Funcion para eliminar un elemento de la cola
void Dequeue(Node*& front, Node*& back, int& n)
{
    n = front->data;
    Node* aux = front;

    if (front == back)
    {
        front = NULL;
        back = NULL;
    }
    else
    {
        front = front->next;
    }
    delete aux;
}

bool BuscarLetras(string entrada) 
{
    bool hayLetras = false;
    for (int i = 0; i < entrada.length() && !hayLetras; i++)
    {
        (isdigit(entrada[i]) == false) ? hayLetras=true : false;
    }
    return hayLetras;
}


void Alerta(string mensaje) {
    cout << "\n" << mensaje;
    cout << "\nPresione cualquier tecla para continuar\n";
    _getch();
}

int main()
{
    Node* front = NULL, *back = NULL;
    int data;
    string op="", priority="";
    bool run = true, hayLetras = false;
    while (run)
    {
        cout << "Bienvenido al programa de Colas\n\n";
        cout << "1) Enqueue (Insertar en la cola)\n";
        cout << "2) Dequeue (Eliminar de la cola)\n";
        cout << "3) Mostrar Cola\n";
        cout << "0) Salir del programa\n";
        cin >> op;

        if (!BuscarLetras)
        {
            switch (stoi(op))
            {
                //Cerrar
            case 0:                                       
                break;

                //Enqueue
            case 1:
                cout << "Ingrese el numero para agregar a la pila: ";
                cin >> data;
                break;
                //Dequeue
            case 2:
                break;
                //Mostrar cola
            case 3:
                break;
            default:
                break;

            }
        }
        else
        {
            Alerta("No introduzca letras");
        }
    }
}
