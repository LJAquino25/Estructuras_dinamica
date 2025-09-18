#include <iostream>
#include <windows.h>
#include <string>
using namespace std;
/*
Crea un programa con un struct Producto con:
● Código (int)
● Nombre
● Precio
● Cantidad en stock
El programa debe:
1. Llenar un array de productos.
2. Implementar una función que busque un producto por código y muestre sus datos.
3. Implementar otra función que calcule el valor total del inventario.
*/

struct producto
{
    int codigo;
    string nombre;
    int precio;
    int cantidad;
};
producto inventario[10];
int totalinventario = 0;

void llenar()
{
    if (totalinventario >= 10)
    {
        cout << "Inventario lleno";
    }
    else
    {
        cout << "Codigo: ";
        cin >> inventario[totalinventario].codigo;
        cout << "Nombre: ";
        getline(cin >> ws, inventario[totalinventario].nombre);
        cout << "Precio: ";
        cin >> inventario[totalinventario].precio;
        cout << "Cantidad de producto: ";
        cin >> inventario[totalinventario].cantidad;
        totalinventario++;
    }
}

void buscar()
{
    int codigoabuscar;
    cout << "Ingrese el codigo del producto: ";
    cin >> codigoabuscar;
    for (int i = 0; i < totalinventario; i++)
    {
        if (inventario[i].codigo == codigoabuscar)
        {
            cout << "Producto: " << inventario[i].nombre;
            Sleep(1000);
            return;
        }
    }
    cout << "Producto no encontrado." << endl;
    Sleep(1000);
}

void mostrar()
{
    for (int i = 0; i < totalinventario; i++)
    {
        cout << "------------------"<<endl;
        cout << "Codigo: " << inventario[i].codigo << endl;
        cout << "Nombre: " << inventario[i].nombre << endl;
        cout << "Precio: " << inventario[i].precio << endl;
        cout << "Cantidad: " << inventario[i].cantidad << endl;
        cout << "------------------"<<endl;
        Sleep(1000);
    }
}

void calcular()
{
    int total = 0;
    for (int i = 0; i < totalinventario; i++)
    {
        total += inventario[i].precio * inventario[i].cantidad;
    }
    cout << "Valor total del inventario: $" << total << endl;
    Sleep(1000);
}

void menu()
{
    cout << "1.LLenar inventario" << endl;
    cout << "2.Buscar en el inventario" << endl;
    cout << "3.Mostrar inventario" << endl;
    cout << "4.Calcular inventario" << endl;
    cout << "0.salir" << endl;
}

void ejecutar()
{
    int op;
    do
    {
        system("cls");
        menu();
        cin >> op;
        switch (op)
        {
        case 1:
            llenar();
            break;
        case 2:
            buscar();
            break;
        case 3:
            mostrar();
            break;
        case 4:
            calcular();
            break;
        }
    } while (op != 0);
}

int main()
{
    ejecutar();
    return 0;
}