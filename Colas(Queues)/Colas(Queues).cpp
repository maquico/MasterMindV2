
/*
* ENUNCIADO: TAREA 4. COLAS (QUEUES)
* ASUNTO: ESTE PROGRAMA PERMITE HACER LAS OPERACIONES ENQUEUE, DEQUEUE, ENQUEUE CON PRIORIDAD Y MOSTRAR COLA.
AUTORES: ANGEL MORENO ID:1104666
*        GLEIDY ESPINAL ID:1104225
*        ALLEN SILVERIO ID:1104220
*        CRISTIAN JIMÉNEZ ID:1106166
*        WILLIAM FERREIRA ID:1104228
* FECHA: 29/08/2022
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
void Enqueue(Node*& front, Node*& back, int n, int prioridad)
{
    bool hayPrioridad = false;
    int contador = 1;
    Node* new_Node = new Node();
    Node* aux = new Node();
    new_Node->data = n;
    new_Node->next = NULL;
    aux = front;

    //Evita que entre a la operacion de prioridad
    if (prioridad > 16 )aux = NULL;
      
    //ENQUEUE con prioridad
    if (aux!=NULL)
    {
        while (contador<prioridad && aux->next!=NULL) //Movemos al auxiliar a la posicion que indique la prioridad
        {
            aux = aux->next;
            contador++;
        }
        /*Si aux->next es NULL es que nuestra prioridad es igual o mayor
       ` a la cantidad de elementos en la cola, entonces el nuevo elemento va al final*/
        if (contador == prioridad && aux->next !=NULL) //Insertamos nuevo elemento a la derecha del auxiliar. 
        {                                              
            new_Node->next = aux->next;
            aux->next = new_Node;
            hayPrioridad = true;
        }
        else if (prioridad == 0) //Insertamos nuevo elemento a la izquierda del auxiliar, al principio de la cola
        {
            new_Node->next = aux;
            front = new_Node;
            hayPrioridad = true;
        }
    }
    //ENQUEUE normal
    if (Empty_Queue(front)) //Si la cola esta vacia tanto el frente como el final apuntan al nuevo nodo
    {
        front = new_Node;
        back = new_Node;
    }
    else if (!hayPrioridad) //Si la cola no esta vacia y no hay prioridad, se coloca al final de la cola
    {
        back->next = new_Node;
        back = new_Node;
    }
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

void Alerta(string iniMensaje= "", string finMensaje = "", int variable = NULL) {
    cout << "\n" << iniMensaje;
    if (variable!=NULL)
    {
        cout << variable << finMensaje;
    }
    cout << "\nPresione cualquier tecla para continuar\n";
    _getch();
}

int main()
{
    Node* front = NULL, *back = NULL;
    string data;
    int papelera=0;
    string op="", priority="";
    bool run = true, hayLetras = false;
    while (run)
    {
        system("cls");
        cout << "Bienvenido al programa de Colas\n\n";
        cout << "1) Enqueue (Insertar en la cola)\n";
        cout << "2) Dequeue (Eliminar de la cola)\n";
        cout << "3) Mostrar Cola\n";
        cout << "0) Salir del programa\n\n";
        cin >> op;

        if (!BuscarLetras(op))
        {
            switch (stoi(op))
            {
                
            case 0:          //Cerrar                             
                run = false;
                break;

                
            case 1:          //Enqueue
                cout << "\nIngrese el numero para agregar a la cola: ";
                cin >> data;
                cout << "Ingrese el nivel de prioridad del elemento ";
                cin >> priority;
                if (!BuscarLetras(data) && !BuscarLetras(priority))
                {
                    Enqueue(front, back, stoi(data), stoi(priority));
                    Alerta("El elemento ", " fue agregado con exito", stoi(data));
                }
                else
                {
                    Alerta("No introduzca letras, la cola solo contiene valores enteros");
                }
                break;

                
            case 2:            //Dequeue
                if (front != NULL)
                {
                    Dequeue(front, back, papelera);
                    Alerta("El elemento ", " fue eliminado con exito", papelera);
                }
                else 
                {
                    Alerta("La cola esta vacia :(");
                }
                break;
                
            case 3:             //Mostrar cola
                if (front!=NULL)
                {
                    while (front != NULL)
                    {
                        Dequeue(front, back, papelera);
                        if (front!=NULL)
                        {
                            cout << papelera << " , ";
                        }
                        else
                        {
                            cout << papelera << ".";
                        }
                    }
                    Alerta();
                }
                else
                {
                    Alerta("La cola esta vacia :(");
                }
                break;
            default:
                Alerta("El numero ingresado no es parte del menu");
                break;
            }
        }
        else
        {
            Alerta("No introduzca letras");
        }
    }
}
