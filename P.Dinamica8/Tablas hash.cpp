#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>
using namespace std;

void Agregar(unordered_set<string> &tablaHash, const string &valor)
{
    auto resultado = tablaHash.insert(valor);
    if (resultado.second == true)
    {
        cout << "Si se agrego";
    }
    else
    {
        cout << "No se agrego";
    }
}

void Agregarmap(unordered_set<string> &tablaHash, const string &valor, int edad)
{
    auto resultado = tablaHash.insert({valor, edad});
    if (resultado.second == true)
    {
        cout << "Si se agrego";
    }
    else
    {
        cout << "No se agrego";
    }
}

void Eliminar(unordered_set<string> &tablaHash, const string &valor)
{
    if (tablaHash.erase(valor))
    {
        cout << "Se elimino";
    }
    else
    {
        cout << "No existe";
    }
}

void Buscar(unordered_set<string> &tablaHash, const string &valor)
{
    if (tablaHash.find(valor) != tablaHash.end())
    {
        cout << "Existe";
    }
    else
    {
        cout << "No existe";
    }
}

void Mostrar(unordered_set<string> &tablaHash)
{
    if (tablaHash.empty())
    {
        cout << "No hay datos" << endl;
        return;
    }

    for (const auto &n : tablaHash)
    {
        cout << n << endl;
    }
}

void Limpiar(unordered_set<string> &tablaHash)
{
    tablaHash.clear();
}

int main()
{
    /*
    unordered_set<string> nombres;

    Agregar(nombres, "Ana");
    Agregar(nombres, "Pepe");
    Agregar(nombres, "Luis");
    Agregar(nombres, "Ana");

    Mostrar(nombres);
    Buscar(nombres, "Luis");
    Eliminar(nombres, "Luis");

    cout << endl;
    Mostrar(nombres);

    Limpiar(nombres);
    */
   //map solo permite 2

    unordered_map<string, int> edades = {
                               {"Ana", 25},
                               {"Luis", 30},
                               {"Pepe", 20},
                           };

    cout << edades["Ana"] << endl;
    return 0;
}