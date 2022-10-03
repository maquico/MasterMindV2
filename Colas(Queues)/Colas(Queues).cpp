
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
struct NodeQ
{
    int data;
    NodeQ* next;
};

//Funcion para agregar un elemento a la cola.
void Enqueue(NodeQ*& front, NodeQ*& back, int n, int prioridad)
{
    bool hayPrioridad = true;
    int contador = 1;
    NodeQ* new_Node = new NodeQ();
    NodeQ* aux = new NodeQ();
    new_Node->data = n;
    new_Node->next = NULL;
    aux = front;

    //Evita que revise prioridad si la ingresada es mayor que 16
    (prioridad > 16 || prioridad < 0 ) ? hayPrioridad = false : hayPrioridad = true;

    //ENQUEUE con prioridad
    if (aux!=NULL && hayPrioridad)
    {
        while (contador<prioridad && aux->next!=NULL) //Movemos al auxiliar a la posicion que indique la prioridad
        {
            aux = aux->next;
            contador++;
        }
        /*Si aux->next es NULL es que nuestra prioridad es igual o mayor
       ` a la cantidad de elementos en la cola, entonces el nuevo elemento va al final*/
        if (contador == prioridad && aux->next != NULL) //Insertamos nuevo elemento a la derecha del auxiliar. 
        {
            new_Node->next = aux->next;
            aux->next = new_Node;
        }
        else if (prioridad == 0) //Insertamos nuevo elemento a la izquierda del auxiliar, al principio de la cola
        {
            new_Node->next = aux;
            front = new_Node;
        }
        else hayPrioridad = false;
    }
    //ENQUEUE normal
    if (aux==NULL)
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
void Dequeue(NodeQ*& front, NodeQ*& back, int& n)
{
    n = front->data;
    NodeQ* aux = front;

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
        if (entrada[0]!='-') (isdigit(entrada[i]) == false) ? hayLetras = true : false;
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
    NodeQ* front = NULL, *back = NULL;
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
        cout << "NOTA: Existe prioridad de 0 a 16, cualquier entero fuera de rango se tomara como prioridad nula\n\n";
        cout << "Opcion elegida: ";
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

                cout << "Ingrese el nivel de prioridad del elemento: ";
                cin >> priority;
                if (!BuscarLetras(data) && !BuscarLetras(priority))
                {
                    Enqueue(front, back, stoi(data), stoi(priority));
                    Alerta("El elemento ", " fue agregado con exito", stoi(data));
                }
                else Alerta("No introduzca letras");
                break;

            case 2:            //Dequeue
                if (front != NULL)
                {
                    Dequeue(front, back, papelera);
                    Alerta("El elemento ", " fue eliminado con exito", papelera);
                }
                else  Alerta("La cola esta vacia :(");
                break;
                
            case 3:             //Mostrar cola
                if (front!=NULL)
                {
                    while (front != NULL)
                    {
                        Dequeue(front, back, papelera);
                        (front!=NULL)? cout << papelera << " , " : cout << papelera << ".";
                    }
                    Alerta();
                }
                else Alerta("La cola esta vacia :(");
                break;
            default:
                Alerta("El numero ingresado no es parte del menu");
                break;
            }
        }
        else Alerta("No introduzca letras");  
    }
}
