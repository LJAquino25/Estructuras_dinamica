#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
    int op;
    queue<string> players;
    do
    {
        cout << "1.Registrar" << endl;
        cout << "2.Mostrar" << endl;
        cout << "3.Siguiente turno" << endl;
        cout << "4.salir" << endl;
        cin >> op;

        switch (op)
        {
        case 1:
        {
            string player;
            cout << "ingrese nombre: ";
            cin >> player;
            players.push(player);
            break;
        }
        case 2:
        {
            if (players.empty())
            {
                cout << "No hay jugadores" << endl;
            }
            queue<string> temp = players;
            while (!temp.empty())
            {
                cout << temp.front() << endl;
                temp.pop();
                if (!temp.empty())
                {
                    cout << " -> ";
                }
                cout << endl;
            }
            break;
        }
        case 3:
        {
            if (players.empty())
            {
                cout << "No hay jugadores" << endl;
            }
            string actual = players.front();
            players.pop();
            players.push(actual);
            cout << "Siguiente turno: " << actual << endl;
            break;
        }
        default:

            break;
        }
    } while (op != 4);
    return 0;
}