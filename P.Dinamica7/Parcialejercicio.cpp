#include <iostream>
#include <algorithm>
#include <string>
#include <list>
#include <vector>
using namespace std;

struct Libro
{
    string Titulo;
    int Ano_Publicacion;
};

struct Biblioteca
{
    string Nombre;
    string Horario_Apertura;
    vector<Libro> coleccion;
};

void Solicitar_Informacion(list<Biblioteca> &biblioteca)
{
    Biblioteca nueva;
    cout << "Ingrese los datos de la Biblioteca:" << endl;
    cout << "Nombre: ";
    getline(cin >> ws, nueva.Nombre);
    cout << "Horario de apertura: ";
    getline(cin >> ws, nueva.Horario_Apertura);

    char cont = 's';

    cout << "Ingrese los libros: ";

    while (cont == 's' || cont == 'S')
    {
        Libro nuevo;
        cout << "Titulo: ";
        getline(cin >> ws, nuevo.Titulo);
        cout << "Ano de publicacion: ";
        cin >> nuevo.Ano_Publicacion;

        nueva.coleccion.push_back(nuevo);

        cout << "Continuar? (S/s o N/n)";
        cin >> cont;
    }
    biblioteca.push_back(nueva);
    cout << "Biblioteca registrada" << endl;
}

void Mostrar(list<Biblioteca> &biblioteca)
{
    for (Biblioteca &nueva : biblioteca)
    {
        cout << "-------------------" << endl;
        cout << "Nombre: " << nueva.Nombre << endl;
        cout << "Horario: " << nueva.Horario_Apertura << endl;
        cout << "Libros:\n";
        for (Libro nuevo : nueva.coleccion)
        {
            cout << "-------------------" << endl;
            cout << "Titulo: " << nuevo.Titulo << endl;
            cout << "Ano de publicacion: " << nuevo.Ano_Publicacion << endl;
        }
        cout << endl;
    }
    cout << endl;
}

void ordenar(list<Biblioteca> &biblioteca)
{
    /* Se ordenan por nombre de biblioteca se usa esta estructura al ser una lista

    biblioteca.sort([](const Biblioteca &nuevo, const Biblioteca &nueva)
                    { return nuevo.Nombre < nueva.Nombre; });
    cout << "Biblioteca ordenada" << endl;
    */

    // se ordenan los libros por año de publicacion
    for (auto &biblio : biblioteca)
    {                                                          //aca se declaran las variables
        sort(biblio.coleccion.begin(), biblio.coleccion.end(),[](const Libro &a, const Libro &b)

             { return a.Ano_Publicacion < b.Ano_Publicacion; });
    }
    cout << "Libros ordenados por año de publicación en cada biblioteca" << endl;
}

void Buscar(const list<Biblioteca> &biblioteca)
{
    string busqueda;
    cout << "Ingrese el nombre de la biblioteca: " << endl;
    getline(cin >> ws, busqueda);

    // Busquedad binario por texto
    auto Encontrada = find_if(
        biblioteca.begin(),
        biblioteca.end(),
        [&](const Biblioteca &nueva)
        { return nueva.Nombre == busqueda; });

    if (Encontrada != biblioteca.end())
    {
        cout << "\nBiblioteca encontrada:\n";
        cout << "-------------------" << endl;
        cout << "Nombre: " << Encontrada->Nombre << endl;
        cout << "Ubicacion: " << Encontrada->Horario_Apertura << endl;
        cout << "Libros:\n";
        for (const auto &nuevo : Encontrada->coleccion)
        {
            cout << "-------------------" << endl;
            cout << "Titulo: " << nuevo.Titulo << endl;
            cout << "Ano de publicacion: " << nuevo.Ano_Publicacion << endl;
        }
    }
    else
    {
        cout << "\nNo se encontro una biblioteca con ese nombre.\n";
    }
}

int main()
{
    list<Biblioteca> biblioteca;
    vector<Libro> coleccion;
    int op;
    do
    {
        cout << "Menu" << endl;
        cout << "1.Solicitar informacion" << endl;
        cout << "2.Mostrar informacion" << endl;
        cout << "3.Ordenar informacion" << endl;
        cout << "4.Buscar informacion" << endl;
        cout << "5.Salir" << endl;
        cin >> op;
        switch (op)
        {
        case 1:
            Solicitar_Informacion(biblioteca);
            break;
        case 2:
            Mostrar(biblioteca);
            break;
        case 3:
            ordenar(biblioteca);
            break;
        case 4:
            Buscar(biblioteca);
            break;
        default:
            break;
        }
    } while (op != 5);

    return 0;
}