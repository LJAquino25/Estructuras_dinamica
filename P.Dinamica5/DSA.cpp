#include <iostream>
#include <stack>
#include <list>
#include <queue>
#include <algorithm>
#include <windows.h>
using namespace std;

struct tarea
{
    string nombre;
    int prioridad;
};

void agregar(list<struct tarea> &proceso)
{
    tarea nueva;
    cout << "Ingrese";
    cout << "\nNombre: ";
    cin >> nueva.nombre;
    cout << "\nPrioridad: ";
    cin >> nueva.prioridad;

    proceso.push_back(nueva);
}

void mostrar(list<struct tarea> &proceso)
{
    for (tarea i : proceso)
    {
        cout << "-------------------" << endl;
        cout << "Nombre: " << i.nombre << endl;
        cout << "Prioridad: " << i.prioridad << endl;
    }
    cout << endl;
}
void prioridad(list<tarea> &proceso, stack<tarea> &pila, queue<tarea> &cola)
{
    for (tarea i : proceso)
    {
        if (i.prioridad == 1)
        {
            pila.push(i);
        }
        else if (i.prioridad == 2 || i.prioridad == 3)
        {
            cola.push(i);
        }
    }
}
void mostrarPilaCola(stack<tarea> pila, queue<tarea> cola)
{
    cout << "\n--- (Prioridad Alta) ---\n";
    while (!pila.empty())
    {
        tarea t = pila.top();
        cout << "Nombre: " << t.nombre << ", Prioridad: " << t.prioridad << endl;
        pila.pop();
    }

    cout << "\n--- (Prioridad Baja/Media) ---\n";
    while (!cola.empty())
    {
        tarea t = cola.front();
        cout << "Nombre: " << t.nombre << ", Prioridad: " << t.prioridad << endl;
        cola.pop();
    }

    cout << endl;
}
void buscar(list<tarea> &proceso)
{
    string buscar;
    cout << "Ingrese tarea a buscar: " << endl;
    getline(cin >> ws, buscar);
    for (tarea i : proceso)
    {
        if (i.nombre == buscar)
        {
            cout << "Nombre: " << i.nombre << ", Prioridad: " << i.prioridad << endl;
        }
    }
}
int main()
{
    list<tarea> proceso;
    stack<tarea> pila;
    queue<tarea> cola;
    int op;
    do
    {
        cout << "\n--- MENU ---\n";
        cout << "1. Agregar persona" << endl;
        cout << "2. Mostrar " << endl;
        cout << "3. Buscar " << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> op;

        switch (op)
        {
        case 1:
            agregar(proceso);
            break;
        case 2:
            mostrar(proceso);
            prioridad(proceso, pila, cola);
            mostrarPilaCola(pila, cola);
            break;
        case 3:
            buscar(proceso);
            break;
        case 4:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opcion no valida." << endl;
        }
    } while (op != 4);
    return 0;
}