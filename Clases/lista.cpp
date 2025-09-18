#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

void insert(node *&lista, int n)
{
    node *newnode = new node{n, lista};
    lista = newnode;
}

void print(node *lista)
{
    node *i = lista;
    while (i != nullptr)
    {
        cout << i->data <<" -> ";
        i = i->next;
    }
}

int main()
{
    node *lista = nullptr;
    /*
    insert(lista, 1);
    insert(lista, 2);
    insert(lista, 3);
    print(lista);
    */
   //todo arreglo es un puntero
    return 0;
}