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
    Node *next;
};

//Funcion para determinar si la cola esta vacia.
bool Empty_Queue(Node *front)
{
    return(front == NULL) ? true : false;
}


//Funcion para agregar un elemento a la cola.
void Enqueue(Node *&front, Node *&back, int n)
{
    Node *new_Node = new Node();
    new_Node -> data = n;
    new_Node -> next = NULL;
    
    if (Empty_Queue(front)) 
    {
        front = new_Node;
    }
    else 
    {
        back->next= new_Node;
    }
    
    back = new_Node;
    cout << "Elemento " << n << " agregado a la cola correctamente "<<endl;
}

//Funcion para eliminar un elemento de la cola
void Dequeue(Node*& front, Node*& back, int& n)
{
    n = front->data;
    Node *aux = front;

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

int main()
{
    Node *front = NULL;
    Node *back = NULL;
    Node* priority = NULL;
    int data; 
    //string op, priority = "";
    bool run = true, hayLetras = false;
    


    


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
