#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <windows.h>
using namespace std;

/*
6. Funciones con structs
Modifica el ejercicio anterior:
    -Implementa una función leerEstudiante() que devuelva un Estudiante.
    -Implementa una función mejorPromedio() que reciba un arreglo de estudiantes y retorne el índice del mejor.
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

void leer(){
    string buscar;
    cout<<"\n\nIngrese estudiante por buscar: ";
    getline(cin >> ws, buscar);
    for (int i = 0; i < 3; i++)
    {
        if(datos[i].nombre == buscar){
            cout<<"Estudiante si estudia aca";
        }

    }
    
}

int main() {
    llenar();
    mayor();
    leer();
    return 0;
}