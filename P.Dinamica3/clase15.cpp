#include <iostream>
#include <list>//lista con libreria (mas sencillo)
using namespace std;

int main()
{
    list<int> numbers;
    // al final de la lista
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);
    // al frente de la lista
    numbers.push_front(40);

    for (int i : numbers)
    { // for abreviado, recorre por cada elemento
        cout << i << " -> ";
    }
    cout << endl;

    // eliminar datos
    numbers.pop_back();  // elimina el 40
    numbers.pop_front(); // elimina el 30

    for (int i : numbers)
    { // for abreviado, recorre por cada elemento
        cout << i << " -> ";
    }
    cout << endl;
    // toma mas recurrsos, solo en listas pequeñas

    return 0;
}