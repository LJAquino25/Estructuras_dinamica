#include <iostream>
using namespace std;

struct Nodo
{
    int data;
    Nodo *izq;
    Nodo *der;
};

Nodo *Crear_Nodo(int valor)
{
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->data = valor;
    nuevo_nodo->izq = nullptr;
    nuevo_nodo->der = nullptr;
    return nuevo_nodo;
}

Nodo *Insertar(Nodo *raiz, int valor)
{
    if (raiz == nullptr)
    {
        return Crear_Nodo(valor);
    }
    if (valor < raiz->data)
    {
        raiz->izq = Insertar(raiz->izq, valor);
    }
    else if (valor > raiz->data)
    {
        raiz->der = Insertar(raiz->der, valor);
    }
    return raiz;
}

void inorder(Nodo *raiz)
{
    if (raiz != nullptr)
    {
        inorder(raiz->izq);
        cout << raiz->data << " ";
        inorder(raiz->der);
    }
}

void preorder(Nodo *raiz)
{
    if (raiz != nullptr)
    {
        cout << raiz->data << " ";
        preorder(raiz->izq);
        preorder(raiz->der);
    }
}

void postorder(Nodo *raiz)
{
    if (raiz != nullptr)
    {
        postorder(raiz->izq);
        postorder(raiz->der);
        cout << raiz->data << " ";
    }
}

void liberar(Nodo *raiz)
{
    if (raiz != nullptr)
    {
        liberar(raiz->izq);
        liberar(raiz->der);
        delete raiz;
    }
}

int main()
{
    Nodo *arbol1 = nullptr;
    arbol1 = Insertar(arbol1, 10);
    arbol1 = Insertar(arbol1, 6);
    arbol1 = Insertar(arbol1, 15);
    arbol1 = Insertar(arbol1, 4);

    cout << "Inorder: ";
    inorder(arbol1);
    cout << endl;
    liberar(arbol1);
    return 0;
}