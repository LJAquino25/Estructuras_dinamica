#include <iostream>
using namespace std;
/*
Ejercicio Base
void functionA(int n);
void functionB(int n);

void functionA(int n)
{
    if (n > 0)
    {
        cout << n << " ";
        functionB(n - 2);
    }
}

void functionB(int n)
{
    if (n > 0)
    {
        cout << n << " ";
        functionA(n - 1);
    }
}

functionA(16);

*/
/*
Ejercicio modificado
void functionA(int n);
void functionB(int n);
void functionC(int n);

void functionA(int n)
{
    if (n > 0)
    {
        cout << n << " ";
        functionC(n - 2);//se cambia por la funcion C
    }
}

void functionB(int n)
{
    if (n > 0)
    {
        cout << n << " ";
        functionA(n - 1);
    }
}

void functionC(int n)
{
    if (n > 0)
    {
        cout << n << " ";
        functionA(n - 3);//se llama la funcion A
    }
}

functionA(16);
*/

void functionA(int n);
void functionB(int n);
void functionC(int n);

void functionA(int n)
{
    if (n > 0)
    {
        cout << n << " ";
        functionC(n - 2);//se cambia por la funcion C
    }
}

void functionB(int n)
{
    if (n > 0)
    {
        cout << n << " ";
        functionA(n - 1);
    }
}

void functionC(int n)
{
    if (n > 0)
    {
        cout << n << " ";
        functionA(n - 3);//se llama la funcion A
    }
}

int main()
{
functionA(16);
    return 0;
}