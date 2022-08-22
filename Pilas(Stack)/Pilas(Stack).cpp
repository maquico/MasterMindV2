#include <iostream>
#include <stdlib.h> // new, delete
#include <string>
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

    cout << "\nElemento AGREGADO con éxito." << endl;
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


int main() {

    Node *stack = NULL; // Inicializar el puntero pila para indicar que esta vacía.
    bool run = true;
    int op;
    int data;

    while(run) {

        cout << "\n0. Salir del programa \n1. Hacer Push \n2. Hacer Pop \n3. Desplega la pila\n\nIngresar opción: ";
        cin >> op;
        cout<< "\n";
        
        switch(int(op)) {
            case 1:
            cout <<"Ingrese el número para agregar a la pila: ";
            cin >> data;
            Push(stack, data);
            break;

            case 2:
            if (stack !=NULL) {
                Pop(stack,data);
                cout << "Elemento eliminado con éxito" << endl;
            } else {
                cout << "Empty Stack \n";
            }
            break;

            case 3:

            while(stack!=NULL) {
                Pop(stack,data);
                if(stack != NULL) {
                     cout << data << ", ";
                } else {
                    cout << data << "." << endl;
                }
            }

            break;

            case 0:
            run = false;
            break;
 
        }

    }

    return 0;
}
