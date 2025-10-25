#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

struct Libro {
    string titulo;
    string autor;
    int anio_publicacion;
    int num_paginas;
};

struct Biblioteca {
    string nombre;
    int num_empleados;
    vector<Libro> libros;
};

void Add(list<Biblioteca> &bibliotecas);
void BuscarLibroPorTitulo(const list<Biblioteca> &bibliotecas);
bool CompararPorTitulo(const Libro &a, const Libro &b);
bool CompararPorAnio(const Libro &a, const Libro &b);
void OrdenarLibros(list<Biblioteca> &bibliotecas);
void MostrarLibros(const list<Biblioteca> &bibliotecas);
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    list<Biblioteca> bibliotecas;
    int opcion;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Aniadir bibliotecas y libros\n";
        cout << "2. Buscar libro por titulo\n";
        cout << "3. Ordenar libros dentro de una biblioteca\n";
        cout << "4. Mostrar libros de una biblioteca\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                Add(bibliotecas);
                break;
            case 2:
                BuscarLibroPorTitulo(bibliotecas);
                break;
            case 3:
                OrdenarLibros(bibliotecas);
                break;
            case 4:
                MostrarLibros(bibliotecas);
                break;
            case 5:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opcion no valida.\n";
        }
    } while (opcion != 5);
}

void Add(list<Biblioteca> &bibliotecas) {
    int continuar;
    do {
        Biblioteca b;
        cin.ignore();
        cout << "Ingrese los datos de la biblioteca:\n";
        cout << "Nombre: ";
        getline(cin, b.nombre);
        cout << "Numero de empleados: ";
        cin >> b.num_empleados;

        int agregarLibro;
        do {
            Libro l;
            cin.ignore();
            cout << "\nIngrese los datos del libro:\n";
            cout << "Titulo: ";
            getline(cin, l.titulo);
            cout << "Autor: ";
            getline(cin, l.autor);
            cout << "Anio de publicación: ";
            cin >> l.anio_publicacion;
            cout << "Numero de paginas: ";
            cin >> l.num_paginas;

            b.libros.push_back(l);

            cout << "¿Desea agregar otro libro? (1=Si / 0=No): ";
            cin >> agregarLibro;
        } while (agregarLibro == 1);

        bibliotecas.push_back(b);

        cout << "¿Desea agregar otra biblioteca? (1=Si / 0=No): ";
        cin >> continuar;

    } while (continuar == 1);
}

void BuscarLibroPorTitulo(const list<Biblioteca> &bibliotecas) {
    cin.ignore();
    string buscado;
    cout << "Ingrese el titulo del libro a buscar: ";
    getline(cin, buscado);

    bool encontrado = false;
    for (const auto &b : bibliotecas) {
        auto it = find_if(b.libros.begin(), b.libros.end(), [buscado](const Libro &l) {
            return l.titulo == buscado;
        });

        if (it != b.libros.end()) {
            cout << "\nLibro encontrado en la biblioteca: " << b.nombre << endl;
            cout << "Titulo: " << it->titulo
                 << "\nAutor: " << it->autor
                 << "\nAnio: " << it->anio_publicacion
                 << "\nPaginas: " << it->num_paginas << endl;
            encontrado = true;
        }
    }

    if (!encontrado)
        cout << "No se encontro ningun libro con ese titulo.\n";
}

bool CompararPorTitulo(const Libro &a, const Libro &b) {
    return a.titulo < b.titulo;
}

bool CompararPorAnio(const Libro &a, const Libro &b) {
    return a.anio_publicacion < b.anio_publicacion;
}

void OrdenarLibros(list<Biblioteca> &bibliotecas) {
    cin.ignore();
    string nombreBiblio;
    cout << "Ingrese el nombre de la biblioteca donde desea ordenar: ";
    getline(cin, nombreBiblio);

    for (auto &b : bibliotecas) {
        if (b.nombre == nombreBiblio) {
            int opcion;
            cout << "¿Como desea ordenar los libros?\n1. Por titulo\n2. Por anio\n> ";
            cin >> opcion;

            if (opcion == 1)
                sort(b.libros.begin(), b.libros.end(), CompararPorTitulo);
            else if (opcion == 2)
                sort(b.libros.begin(), b.libros.end(), CompararPorAnio);
            else
                cout << "Opcion no valida.\n";

            cout << "Libros ordenados correctamente.\n";
            return;
        }
    }

    cout << "No se encontro la biblioteca con ese nombre.\n";
}

void MostrarLibros(const list<Biblioteca> &bibliotecas) {
    cin.ignore();
    string nombreBiblio;
    cout << "Ingrese el nombre de la biblioteca a mostrar: ";
    getline(cin, nombreBiblio);

    for (const auto &b : bibliotecas) {
        if (b.nombre == nombreBiblio) {
            cout << "\nBiblioteca: " << b.nombre
                 << "\nEmpleados: " << b.num_empleados
                 << "\n--- Libros ---\n";

            for (const auto &l : b.libros) {
                cout << "Titulo: " << l.titulo
                     << "\nAutor: " << l.autor
                     << "\nAnio: " << l.anio_publicacion
                     << "\nPaginas: " << l.num_paginas
                     << "\n----------------------\n";
            }
            return;
        }
    }

    cout << "No se encontro la biblioteca con ese nombre.\n";
}