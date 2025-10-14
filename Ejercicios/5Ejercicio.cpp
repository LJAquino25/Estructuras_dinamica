#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <windows.h>
using namespace std;

/*
5. Structs básicos
Crea un struct Estudiante que almacene: nombre, edad y promedio.
    - Pide al usuario los datos de 3 estudiantes.
    - Imprime cuál tiene el mejor promedio.
*/

struct Estudiante
{
    string nombre;
    int edad;
    float promedio;
};

Estudiante datos[3];

void llenar(){
    for (int i = 0; i < 3; i++)
    {
        cout<<"\nIngrese los datos del estudiante "<<i+1<<" :"<<endl;
        cout<<"Nombre: "<<endl;
        getline(cin >> ws, datos[i].nombre);
        cout << "Edad: ";
        cin >> datos[i].edad;
        cout << "Promedio de notas: ";
        cin >> datos[i].promedio;
    }    
};

void mayor(){
    float mayor = datos[0].promedio;
    int indice =0;

    for (int i = 0; i < 3; i++)
    {
        if (datos[i].promedio > mayor)
        {
            mayor = datos[i].promedio;
            indice = i;
        }
    }
    cout<<"\n\nEstudiante con mejor promedio: "<<endl;
    cout<<"Nombre: "<<datos[indice].nombre<<endl;
    cout<<"Edad: "<<datos[indice].edad<<endl;
    cout<<"Promedio: "<<datos[indice].promedio<<endl;
    
};

int main() {
    llenar();
    mayor();
    return 0;
}