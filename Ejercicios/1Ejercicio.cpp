#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
using namespace std;
/*
1. Crea un programa que:
    - Genere un arreglo de 20 números aleatorios entre 1 y 100.
    - Implemente funciones para:
        - Contar cuántos son pares e impares.
        - Encontrar el segundo mayor y el segundo menor.
        - Invertir el arreglo (sin usar otro arreglo auxiliar).
*/

int numale[20];
void numaleatorio();
void parimpar();
void mayormenor();
void invertirArreglo();
void ejecutar();

int main()
{
    ejecutar();
    return 0;
}

void numaleatorio()
{
    srand(time(NULL));
    for (int i = 0; i < 20; i++) // numero aleatorio se guarda en el array
    {

        numale[i] = (rand() % 100) + 1;
    }
}

void parimpar()
{
    int conta1 = 0;
    int conta2 = 0;
    cout << "Numeros pares: " << endl;
    for (int i = 0; i < 20; i++) // para al dividir entre cero da cero
    {
        if (numale[i] % 2 == 0)
        {
            cout << numale[i] << " ";
            conta1++;
        }
    }
    cout << "\nNumeros impares: " << endl;
    for (int i = 0; i < 20; i++)
    {
        if (numale[i] % 2 != 0) // impares diferentes de cero la division
        {
            cout << numale[i] << " ";
            conta2++;
        }
    }
    cout << "\n----------------------------------" << endl;
    cout << "\nNumero de pares: " << conta1 << endl;
    cout << "Numero de impares: " << conta2 << endl;
}

void mayormenor()
{
    int mayor = numale[0], segmayor = -1;
    int menor = numale[0], segmenor = 101;

    for (int i = 1; i < 20; i++) // encontrar mayor y menor
    {
        if (numale[i] > mayor)
        {
            mayor = numale[i];
        }
        if (numale[i] < menor)
        {
            menor = numale[i];
        }
    }
    for (int i = 0; i < 20; i++) // encontrar mayor y menor segundo
    {
        if (numale[i] > segmayor && numale[i] < mayor)
            segmayor = numale[i];
        if (numale[i] < segmenor && numale[i] > menor)
            segmenor = numale[i];
    }

    cout << "Segundo mayor: " << segmayor << endl;
    cout << "Segundo menor: " << segmenor << endl;
}

void invertirArreglo()
{
    cout << "\n-------------------------------" << endl;
    cout << "Arreglo original: " << endl;
    for (int j = 0; j < 20; j++)
    {
        cout << numale[j] << "  ";
    }

    for (int i = 0; i < 10; i++) // intercambiar valores del arreglo sin array extra
    {
        int temp = numale[i];
        numale[i] = numale[19 - i];
        numale[19 - i] = temp;
    }
    cout << "\n-------------------------------" << endl;
    cout << "Arreglo invertido: " << endl;
    for (int j = 0; j < 20; j++)
    {
        cout << numale[j] << "  ";
    }
}

void ejecutar()
{
    numaleatorio();
    int op;
    do
    {
        cout << "\n-------------------------------" << endl;
        cout << "1.Contar pares e impares" << endl;
        cout << "2.Segundo mayo y Segundo menor" << endl;
        cout << "3.Invertir arreglo" << endl;
        cout << "0.salir" << endl;
        cin >> op;
        cout << "\n"
             << endl;
        switch (op)
        {
        case 1:
            parimpar();
            break;
        case 2:
            mayormenor();
            break;
        case 3:
            invertirArreglo();
            break;
        }
    } while (op != 0);
}