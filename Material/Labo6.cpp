#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

struct hotel
{
    int numerohabitacion;
    string tipohabitacion;
    int precio;
    int capacidad;
    string estado;
};

void OrdenarPorPrecio(list<hotel> &hotel1)
{
    hotel1.sort([](const hotel &h, const hotel &H)
                { return h.precio < H.precio; });
    cout << "Habitaciones ordenadas por precio" << endl;
}

void agregar_habitacion(list<struct hotel> &habitaciones)
{
    hotel habitacion;
    cout << "agregue el numero de la habitacion" << endl;
    cin >> habitacion.numerohabitacion;
    cout << "agregue el tipo de habitacion" << endl;
    cin >> habitacion.tipohabitacion;
    cout << "agregue el precio de la habitacion" << endl;
    cin >> habitacion.precio;
    cout << "agregue la capacidad que tiene la habitacion" << endl;
    cin >> habitacion.capacidad;
    cout << "¿esta disponible?" << endl;
    cin >> habitacion.estado;

    habitaciones.push_back(habitacion);
}

void buscarPorNumero(list<hotel> &habitaciones)
{
    auto cmp = [](const hotel &a, const hotel &b)
    {
        return a.numerohabitacion < b.numerohabitacion;
    };
    habitaciones.sort(cmp);

    hotel clave{};
    int numeroBuscado;
    cout << "Ingrese numero de habitacion por buscar: ";
    cin >> numeroBuscado;
    clave.numerohabitacion = numeroBuscado;

    auto it = lower_bound(habitaciones.begin(), habitaciones.end(), clave, cmp);

    if (it != habitaciones.end() && it->numerohabitacion == numeroBuscado)
    {
        cout << "Coincidencias encontradas para habitacion \"" << numeroBuscado << "\":\n";
        for (auto jt = it; jt != habitaciones.end() && jt->numerohabitacion == numeroBuscado; ++jt)
        {
            cout << " - Numero de habitacion: " << jt->numerohabitacion;
        }
        cout << endl;
    }
    else
    {
        cout << "No se encontró la habitacion \"" << numeroBuscado << "\".\n\n";
    }
}

void Mostrar(const list<hotel> &habitaciones)
{
    cout << "--------------------------------\n";
    for (const auto &e : habitaciones)
    {
        cout << "Habitacion: " << e.numerohabitacion << endl;
        cout << "Tipo: " << e.tipohabitacion << endl;
        cout << "Estado: " << e.estado << endl;
        cout << "Precio: " << e.precio << endl;
    }
    cout << "--------------------------------\n\n";
}

int main()
{
    list<struct hotel> habitaciones;
    hotel habitacion;
    int opcion;
    do
    {
        cout << "seleccione una opcion" << endl;
        cout << "1. agregar habitacion" << endl;
        cout << "2. ordenar por precio" << endl;
        cout << "3. buscar habitacion" << endl;
        cout << "4. mostrar habitaciones" << endl;
        cout << "5. salir" << endl;
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            agregar_habitacion(habitaciones);
            break;
        case 2:
            OrdenarPorPrecio(habitaciones);
            break;
        case 3:
            buscarPorNumero(habitaciones);
            break;
        case 4:
            Mostrar(habitaciones);
            break;
        case 5:
            cout << "saliendo..." << endl;
            break;
        }
    } while (opcion != 5);

    return 0;
}
