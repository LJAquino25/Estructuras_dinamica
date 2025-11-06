#include <iostream>
#include <set> //libreria para arbol
using namespace std;

int main()
{
    set<int> arbol;
    arbol.insert(10);
    arbol.insert(6);
    arbol.insert(15);
    arbol.insert(4);

    // solo usa inorder
    // recorrido
    for (int i : arbol)
    {
        cout << i << " ";
    }
    cout << endl << arbol.count(6);
    // devuleve o 1 o 0
    // si lo encuentra 1
    // no lo encuentra 0
    return 0;
}