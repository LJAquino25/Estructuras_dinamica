#include <iostream>
using namespace std;

void SimularOperacionValor(int xp, int puntos_simulacion, char op)
{

    if (op == 'S')
    {
        cout << "El resultado de la suma es: " << xp + puntos_simulacion << endl;
    }
    else if (op == 'R')
    {
        cout << "El resultado de la resta es: " << xp - puntos_simulacion << endl;
    }
    else
    {
        cout << "Opcion no valida. \n";
    }
}

void sumar(int &xp, int pts)
{
    cout << "Puntos actuales: " << xp << endl;
    cout << "Cuantos puntos desea sumar: ";
    cin >> pts;
    xp += pts;
    cout << "\nPuntos de xp: " << xp;
}

void restar(int *xp, int pts)
{
    cout << "cuantos puntos deseas restar: " << endl;
    cin >> pts;

    *xp -= pts;
    cout << "el total de xp es : " << *xp << endl;
}

int main()
{
    int xp = 50;
    int pts = 0;
    int op;
    char opcion;
    int puntos_simulacion;

    do
    {

        cout << "\n1.Sumar" << endl;
        cout << "2.Restar" << endl;
        cout << "3.Simular" << endl;
        cout << "0.Salir" << endl;
        cin >> op;

        switch (op)
        {
        case 1:
            sumar(xp, pts);
            break;
        case 2:
            cout << "puntos actuales: " << xp << endl;
            restar(&xp, pts);
            break;
        case 3:
            cout << "SIMULADOR \n";
            cout << "Con cuantos puntos quiere hacer la simulacion: \n";
            cin >> puntos_simulacion;
            cout << "Ingrese la opcion del simulador: \n";
            cout << "S. Para ver la suma. \n";
            cout << "R. Para ver la resta. \n";
            cin >> opcion;
            SimularOperacionValor(xp, puntos_simulacion, opcion);
            break;
        }
    } while (op != 0);
    return 0;
}
