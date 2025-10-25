#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Streaming
{
    string titulo;
    string genero;
    int horas;
    int pago;
    int ingresos;
};

void mostrarseries() // mostrar todas las series ingresadas
{
    Streaming serie[5];
    cout << "Lista de series" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "titulo: " << serie[i].titulo << endl;
        cout << "Genero: " << serie[i].genero << endl;
        cout << "horas: " << serie[i].horas << endl;
        cout << "Pago: " << serie[i].pago << endl;
        cout << "Ingresos" << serie[i].ingresos << endl;
        cout << "------------------------------------------" << endl;
    }
}

void menu() // menu dinamico
{
    cout << "1.Agregar serie" << endl;
    cout << "2.Mostrar series" << endl;
    cout << "3. salir" << endl;
}

void ejecutarmenu() // menu dinamico
{
    int opcion;
    do
    {
        menu();
        cin >> opcion;
        system("cls");
        switch (opcion)
        {
        case 1:
            solicitarDatos();
            break;
        case 2:
            mostrarseries();
            break;
        case 3:
            cout << "saliendo..." << endl;
            break;
        }
    } while (opcion != 3);
}

// funcion que solicita al usuario los datos de la serie y la almacena en un arreglo dentro del struct.
int solicitarDatos()
{
    Streaming serie[5];
    for (int i = 0; i < 5; i++)
    {
        cout << "ingrese el titulo de la serie" << endl;
        getline(cin >> ws, serie[i].titulo);
        cout << "ingrese el Genero de la serie" << endl;
        getline(cin >> ws, serie[i].genero);
        cout << "ingrese las Horas que a visto la serie" << endl;
        cin >> serie[i].horas;
        cout << "ingrese el pago por hora" << endl;
        cin >> serie[i].pago;
        cout << "ingrese los ingresos generados" << endl;
        serie[i].ingresos = (serie[i].pago * serie[i].horas);
        cin >> serie[i].ingresos;

        return 0;
    }
}

int main()
{
    ejecutarmenu();
    return 0;
}