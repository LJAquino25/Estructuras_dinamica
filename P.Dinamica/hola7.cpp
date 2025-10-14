#include <iostream>
using namespace std;

struct Alumno
{
    string nombre;
    double nota;
};

int main()
{

    Alumno alumnos[3] = {{"Juan", 8.5}, {"Pedro", 9.9}, {"Maria", 6.8}};

    cout << "Primer Alumno: " << alumnos[0].nombre << endl;
    cout << "Primer Alumno Nota: " << alumnos[0].nota << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << "Alumno:" << alumnos[i].nombre << endl;
        cout << "Nota: " << alumnos[i].nota << endl;
    }
    return 0;
}