#include <iostream>
#include <string>
using namespace std;

struct Producto {
    int codigo;
    string nombre;
    float precio;
    int cantidad;
};

const int N = 5;
Producto productos[N];

void Inventario() {
    cout << "Ingrese los datos de los productos:\n";
    for (int i = 0; i < N; i++) {
        cout << "Producto #" << (i + 1) << endl;
        cout << "Codigo: ";
        cin >> productos[i].codigo;
        cout << "Nombre: ";
        getline(cin >> ws , productos[i].nombre);
        cout << "Precio: ";
        cin >> productos[i].precio;
        cout << "Cantidad en stock: ";
        cin >> productos[i].cantidad;
        cout << "-------------------\n";
    }
}

void menu_inventario() {
    cout << "1.Mostrar todos los productos" << endl;
    cout << "2.Buscar producto por codigo" << endl;
    cout << "3.Calcular valor total del inventario" << endl;
    cout << "4.Salir" << endl;
}

void mostrarProducto(const Producto& p) {
    cout << "Codigo: " << p.codigo << endl;
    cout << "Nombre: " << p.nombre << endl;
    cout << "Precio: " << p.precio << endl;
    cout << "Cantidad en stock: " << p.cantidad << endl;
}

void mostrarTodos() {
    cout << "Inventario de productos:\n";
    for (int i = 0; i < N; i++) {
        mostrarProducto(productos[i]);
        cout << "-------------------\n";
    }
}

void buscarProducto() {
    int codigoBuscar;
    cout << "Ingrese el codigo del producto a buscar: ";
    cin >> codigoBuscar;
    bool encontrado = false;
    for (int i = 0; i < N; i++) {
        if (productos[i].codigo == codigoBuscar) {
            cout << "Producto encontrado:\n";
            mostrarProducto(productos[i]);
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "Producto no encontrado.\n";
    }
}

void valorInventario() {
    float total = 0;
    for (int i = 0; i < N; i++) {
        total += productos[i].precio * productos[i].cantidad;
    }
    cout << "Valor total del inventario: " << total << endl;
}

void ejecutarInventario() {
    int opcion;
    do {
        menu_inventario();
        cin >> opcion;
        switch (opcion) {
            case 1:
                mostrarTodos();
                break;
            case 2:
                buscarProducto();
                break;
            case 3:
                valorInventario();
                break;
            case 4:
                cout << "Saliendo..." << endl;
                break;
        }
    } while (opcion != 4);
}

int main() {
    Inventario();
    ejecutarInventario();
    return 0;
}