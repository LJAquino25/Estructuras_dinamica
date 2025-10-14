#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int array[] = {5, 2, 9, 1, 5, 6, 3};
    int n = sizeof(array) / sizeof(array[0]);

    // ordenar array
    sort(array, array + n);
    // este algoritmo, si o si tiene que estar ordenado el arreglo

    int inicio = 0;
    int fin = n - 1;

    // Metodo facil con libreria
    // bool encontrado = binary_search(array, array+n, search);

    int search = 3;

    while (inicio <= inicio)
    {
        // elemento central de un arreglo
        int mitad = (inicio + fin) / 2;
        // no importa si es par o impar - Sigue funcionando

        if (array[mitad] == search)
        {
            cout << "Elemento encontrado";
            break;
        }
        else if (array[mitad] < search) // mitad derecha
        {
            inicio = mitad + 1;
        }
        else // mitad izquierda
        {
            fin = mitad - 1;
        }
    }

    return 0;
}