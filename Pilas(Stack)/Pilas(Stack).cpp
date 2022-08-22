
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

#include <iostream>
#include <stdlib.h> // new, delete
#include <string>
#include <conio.h> // getch
using namespace std;

//Estructura de la pila

struct Node {
    int data; // recibe un dato
    Node *next; // puntero de tipo nodo que apunta al siguiente elemento
};

// Función para agregar un elemento a la pila

void Push(Node *&stack, int data) { // Se pasa por referencia porque la pila ira cambiando en la ejecución del progrma.
    Node *newNode = new Node(); // crear el espacio en memoria del nuevo nodo.
    newNode->data = data; // Rellenar el dato del nuevo nodo.
    newNode->next = stack; //Rellenar el puntero del nuevo nodo, apunta hacia el siguente elemento. 
    stack = newNode; // El puntero stack siempre apunta al elemento top, el nuevo nodo hara es el elemento top.
}


// Función para eliminar un elemento de la pila

void Pop(Node *&stack, int &data) { // Esta vez Pasamos el dato por referencia
    Node *aux = stack; // Crear variable auxiliar de tipo nodo e igualarlo a la pila para apuntar el elemento top de la pila.
    data = aux->data; // asignar el valor del dato del nodo "top" a la variable data. Guardamos el valor que se quiere eliminar
    stack = aux->next; // Apuntar la pila hacia el siguiente nodo 
    delete aux; //Borrar el nodo
}

// Crear una variable auxiliar para asignar los datos del nodo "top" a ella, 
// luego apuntar la pila hacia al nodo que le sigue a auxiliar (que hora sería el nuevo nodo "top") y eliminar el auxiliar.
// El aux sirve como un envase para guardar el nodo top. Sirve para tener una referencia hacia eso nodo en todo momento y poderlo eliminar.

void Alerta(string mensaje) {
    cout <<"\n" << mensaje;
    cout << "\nPresione cualquier tecla para continuar\n";
    _getch();
}

int main() {

    Node *stack = NULL; // Inicializar el puntero pila para indicar que esta vacía.
    bool run = true, hayLetra;
    string op;
    int data;
    string input;

    while(run) {
        system("cls");
        hayLetra = false;
        cout << "---CREACION Y MODIFICACION DE PILAS---\n\n";
        cout << "\n0. Salir del programa \n1. Hacer Push \n2. Hacer Pop \n3. Desplega la pila\n\nIngresar opcion: ";
        cin >> op;
        cout<< "\n";
        
        for (int i = 0; i < op.length() && !hayLetra; i++)
        {
            if (!isdigit(op[i]))
            {
                hayLetra = true;
            }
        }
        
        if (!hayLetra)
        {
            switch (stoi(op)) {
            case 1:
                cout << "Ingrese el numero para agregar a la pila: ";
                cin >> input;

                for (int i = 0; i < input.length() && !hayLetra; i++)
                {
                    if (!isdigit(input[i]))
                    {
                        hayLetra = true;
                        Alerta("No introduzca letras");
                    }
                }
                if (!hayLetra) 
                {
                    data = stoi(input);
                    Push(stack, data);
                    Alerta("Elemento agregado con exito");
                }
              
                break;

            case 2:
                if (stack != NULL) {
                    Pop(stack, data);
                    cout << "Elemento eliminado con exito";
                }
                else {
                    cout << "Pila vacia :(\n";
                }
                Alerta("");
                break;

            case 3:
                cout << "ELEMENTOS EN LA PILA:\n";
                if (stack != NULL)
                {
                    while (stack != NULL) {
                        Pop(stack, data);
                        if (stack != NULL) {
                            cout << data << ", ";
                        }
                        else {
                            cout << data << "." << endl;
                        }
                    }
                }
                else {
                    cout << "Pila vacia :(\n";
                }
                Alerta("");
                break;

            case 0:
                run = false;
                break;

            default:
                Alerta("Ese numero no forma parte del menu, elige uno del 0 al 3");
                break;
            }
        }
        else {
            Alerta("No introduzca letras");
        }
    }

    return 0;
}
