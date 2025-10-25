#include <iostream>
using namespace std;
// Ejercicio calcular la potencia de un numero con recursividad

int sumaN(int n)
{
    if (n == 0)
        return 0;
    return n + sumaN(n - 1);
}

int factorial(int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

int contarDigitos(int n)
{
    if (n < 10)
        return 1;
    return 1 + contarDigitos(n / 10);
}

int fibonacci(int n)
{
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n = 3;
    // int n =  1234;
    // int n= 5;
    // cout << sumaN(n);
    // cout << factorial(n);
    // cout << contarDigitos(n);
    // cout << fibonacci(n);

    return 0;
}