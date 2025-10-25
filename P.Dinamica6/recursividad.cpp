#include <iostream>
using namespace std;
// Forma iterativa - con for, while, etc
// Forma recursiva
void contarHastRecursivo(int n) // primera llamada
{
    if (n == 0) // pare y se ejecuten los cout pendientes
        return; // if : caso basico
    contarHastRecursivo(n - 1); // segunda llamada.......asi sucesivamente hasta sexta llamada = 0; //caso recursivo
    cout << n;                  // se ejecutan al revez
}

int main()
{
    int n = 5;
    contarHastRecursivo(n);

    return 0;
}