#include <iostream>
using namespace std;

struct facultad
{
    int facultad;
    string carrera;
    int numero;
};

const int cantidad_facultades = 5;
struct universidad // struct anidado
{
    string nombre;
    string direccion;
    facultad facultades[cantidad_facultades];
};

universidad solcitar_datos() // struct anidado funcionando
{
    universidad u;
    cout << "Ingrese el nombre de universidad: " << endl;
    getline(cin >> ws, u.nombre);
    cout << "Ingrese la direccion de la universidad" << endl;
    getline(cin >> ws, u.direccion);

    for (int i = 0; i < cantidad_facultades; i++)
    {
        cout << "Ingrese el numero de facultad: " << endl;
        cin >> u.facultades[i].facultad;
        cout << "Ingrese la carrera principal de la facultad " << endl;
        getline(cin >> ws, u.facultades[i].carrera);
        cout << "Ingrese el numero de estudiantes de la facultad: " << endl;
        cin >> u.facultades[i].numero;
        cin.ignore();
    }

    return u;
};

void mostrar(const universidad &u)
{
    cout << "Universidad: " << u.nombre << endl;
    cout << "Direccion: " << u.direccion << endl;
    for (int i = 0; i < cantidad_facultades; i++)
    {
        cout << "Facultad #" << i << " " << u.facultades[i].facultad << endl;
        cout << "Carrera: " << u.facultades[i].carrera << endl;
        cout << "Numero de estudiantes: " << u.facultades[i].numero << endl;
    }
}

void buscar(const universidad &u)
{
    string buscar;
    bool verificar = false;
    cout << "Escriba la carrera que quiere buscar" << endl;
    getline(cin >> ws, buscar);
    for (int i = 0; i < cantidad_facultades; i++)
    {
        if (u.facultades[i].carrera == buscar)
        {
            verificar = true;
            break;
        }
    }
    if (verificar == true)
    {
        cout << "Si existe la carrera" << endl;
    }
    else
    {
        cout << "No existe, digite nombre valido" << endl;
    }

    return;
}

int calcular(const universidad &u)
{
    int total = 0;
    for (int i = 0; i < cantidad_facultades; i++)
    {
        total += u.facultades[i].numero;
    }
    return total;
}

void menu()
{
    cout << "1.Solicitar datos" << endl;
    cout << "2.Mostrar datos" << endl;
    cout << "3.Calcular total" << endl;
    cout << "4.Buscar carrera" << endl;
    cout << "0.Salir" << endl;
}

void ejecutar()
{
    int op;
    universidad u;
    do
    {
        menu();
        cin >> op;
        switch (op)
        {
        case 1:
            u = solcitar_datos();
            break;
        case 2:
            mostrar(u);
            break;
        case 3:
            calcular(u);
            break;
        case 4:
            buscar(u);
            break;
        }
    } while (op != 0);
}

int main()
{
    ejecutar();
    return 0;
}