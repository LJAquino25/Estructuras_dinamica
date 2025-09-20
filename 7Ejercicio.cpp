#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <windows.h>
using namespace std;

/*7. Arreglo estático
    - Declara un arreglo estático de enteros de tamaño 10.
    - Llénalo con valores aleatorios entre 1 y 100.
    - Implementa funciones para:
        - Encontrar el máximo.
        - Encontrar el mínimo.
        - Calcular el promedio.
*/
int array[10];
void numaleatorio()
{
    srand(time(NULL));
    for (int i = 0; i < 20; i++)
    {

        array[i] = (rand() % 100) + 1;
    }
    for (int i = 0; i < 10; i++)
    {
        cout << array[i] << "  ";
    }
}

void maxmin()
{
    int max = array[0];
    int min = array[0];

    for (int i = 1; i < 10; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
        if (array[i] < min)
        {
            min = array[i];
        }
    }
    cout << "\n\nMaximo: " << max << endl;
    cout << "Minimo: " << min << endl;
}

void promedio()
{
    int sum;
    float promedio;
    for (int i = 0; i < 10; i++)
    {
        sum += array[i];
    }
    promedio = sum / 10.0;
    cout << "\n\nPromedio: " << promedio << endl;
}

int main()
{
    numaleatorio();
    maxmin();
    promedio();
    return 0;
}