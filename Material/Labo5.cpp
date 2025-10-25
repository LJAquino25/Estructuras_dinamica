#include <iostream>
#include <queue>
using namespace std;

struct Persona
{
    string nombre;
    int asiento;
    string categoria;
};

void mostrarCola(queue<Persona> cola)
{
    if (cola.empty())
    {
        cout << "No hay nadie haciendo cola." << endl;
    }
    else
    {
        cout << "\n--- Lista de personas en la cola ---\n";
        while (!cola.empty())
        {
            Persona p = cola.front();
            cout << "Nombre: " << p.nombre << endl;
            cout << "Asiento: " << p.asiento << endl;
            cout << "Categoria: " << p.categoria << endl;
            cout << "-----------------------------\n";
            cola.pop();
        }
    }
}

void iniciarViaje(queue<Persona> &cola)
{
    if (cola.empty())
    {
        cout << "No hay ninguna persona en la cola." << endl;
        return;
    }

    int n = 0;
    cout << "\n--- Iniciando viaje con las primeras 3 personas ---\n";
    while (!cola.empty() && n < 3)
    {
        Persona p = cola.front();
        cout << "Nombre: " << p.nombre << endl;
        cout << "Asiento: " << p.asiento << endl;
        cout << "Categoria: " << p.categoria << endl;
        cout << "-----------------------------\n";
        cola.pop();
        n++;
    }

    cout << "Personas restantes en la cola: " << cola.size() << endl;
}

void agregar(queue<Persona> &cola, int &cont)
{
    Persona nueva;
    cout << "Ingrese nombre: " << endl;
    cin >> nueva.nombre;

    cont++;
    nueva.asiento = cont;

    cout << "Categoria (nino o adulto): " << endl;
    cin >> nueva.categoria;

    cola.push(nueva);

    cout << "Persona agregada exitosamente con asiento #" << nueva.asiento << endl;
}

int main()
{
    int op;
    int cont = 0;
    queue<Persona> cola;

    do
    {
        cout << "\n--- MENU ---\n";
        cout << "1. Agregar persona" << endl;
        cout << "2. Mostrar cola" << endl;
        cout << "3. Iniciar viaje" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> op;

        switch (op)
        {
        case 1:
            agregar(cola, cont);
            break;
        case 2:
            mostrarCola(cola);
            break;
        case 3:
            iniciarViaje(cola);
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
