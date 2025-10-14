#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <windows.h>
using namespace std;

/*
1. Sistema de gestión de inventario
Crea un programa que maneje productos con un struct Producto que tenga:
id, nombre, precio, cantidad.
El programa debe:
    - Usar un arreglo dinámico de productos.
    - Permitir:
        - Agregar productos.
        - Buscar por id.
        - Actualizar la cantidad.
        - Calcular el valor total del inventario.
*/

struct Producto
{
    string id;
    string nombre;
    int precio;
    int cantidad;
};
Producto inventario[10];
int total = 0;
void agregar()
{
    if (total >= 10)
    {
        cout << "No se puede agregar mas";
    }
    cout << "ID: ";
    getline(cin >> ws, inventario[total].id);
    cout << "Nombre: ";
    getline(cin >> ws, inventario[total].nombre);
    cout << "Precio: ";
    cin >> inventario[total].nombre;
    cout << "Cantidad: ";
    cin >> inventario[total].cantidad;
    total++;
}

void buscar()
{
    string buscar;
    cout << "Producto a buscar: ";
    getline(cin >> ws, buscar);
    for (int i = 0; i < total; i++)
    {
        if (inventario[i].id == buscar)
        {
            cout << "Producto: " << endl;
            cout << "ID: " << inventario[i].id << endl;
            cout << "Nombre: " << inventario[i].nombre << endl;
        }
    }
}

void actualizar()
{
    
}

void calcular()
{
    int totalinv;
    for (int i = 0; i < total; i++)
    {
        total += inventario[i].precio * inventario[i].cantidad;
    }
    cout << "Total: " << total << endl;
}

int main()
{

    return 0;
}