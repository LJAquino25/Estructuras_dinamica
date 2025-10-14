#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <windows.h>
using namespace std;

/*
3. Matrices y funciones
    - Trabaja con una matriz estática de 5x5.
    - Implementa funciones que:
        - Llenen la matriz con números aleatorios.
        - Calculen la suma de cada fila y de cada columna.
        - Encuentren la fila con la mayor suma.
        - Trasponer la matriz.
*/

int matrix[5][5];

void numale()
{
    srand(time(NULL));
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matrix[i][j] = (rand() % 100) + 1;
        }
    };

    cout << "Matriz generada: \n";
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout <<endl;
    }
}

void sumfila(){
    for (int i = 0; i < 5; i++)
    {
        int sum = 0;
        for (int j = 0; j < 5; j++)
        {
            sum += matrix[i][j];
        }
        cout << "Suma de la fila " << i + 1 << ": " << sum << endl;
    }

}

void sumacolum(){
    for (int j = 0; j < 5; j++)
    {
        int suma = 0;
        for (int i = 0; i < 5; i++)
        {
            suma += matrix[i][j];
        }
        cout << "Suma de la columna " << j + 1 << ": " << suma << endl;
    }
}

void filaMayorSuma() {
    int maxSum = 0;
    int filaMax = 0;

    for (int i = 0; i < 5; i++) {
        int sum = 0;
        for (int j = 0; j < 5; j++) {
            sum += matrix[i][j];
        }
        if (sum > maxSum) {
            maxSum = sum;
            filaMax = i;
        }
    }
    cout << "La fila con la mayor suma es la fila " << (filaMax + 1)
         << " con una suma de " << maxSum << "." << endl;
}

void columnaMayorSuma() {
    int maxSuma = 0;
    int columnaMax = 0;

    for (int j = 0; j < 5; j++) {
        int suma = 0;
        for (int i = 0; i < 5; i++) {
            suma += matrix[i][j];
        }
        if (suma > maxSuma) {
            maxSuma = suma;
            columnaMax = j;
        }
    }
    cout << "La columna con la mayor suma es la columna " << (columnaMax + 1)
         << " con una suma de " << maxSuma << "." << endl;
}

void transponer() {
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    cout << "Matriz transpuesta:\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    numale();
    sumfila();
    sumacolum();
    filaMayorSuma();
    columnaMayorSuma();
    transponer();

    return 0;
}