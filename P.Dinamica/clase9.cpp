#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void insert(Node *&head, int value)
{
    Node *newNode = new Node{value, head};
    head = newNode;
}

void insertatEnd(Node *&head, int value)
{
    Node *newNode = new Node{value, head};
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    Node *current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    current->next = newNode;
}

void print(Node *head)
{
    Node *i = head;
    while (i != nullptr)
    {
        cout << i->data << " -> ";
        i = i->next;
    }
}

void free(Node *&head)
{
    while (head != nullptr)
    {
        
    }
}

int main()
{
    Node *lista1 = nullptr;
    int opc = 0;

    do
    {
        cout << endl;
        cout << "1. Insertar" << endl;
        cout << "2. Imprimir" << endl;
        cout << "3.Agregar al final" << endl;
        cout << "4.Vaciar memoria" << endl;
        cout << "0. Salir" << endl;
        cin >> opc;
        switch (opc)
        {
        case 1:
            int value;
            cout << "Ingrese un valor: ";
            cin >> value;
            insert(lista1, value);
            break;
        case 2:
            print(lista1);
            break;
        case 3:
            int val;
            cout << "Ingrese un valor";
            cin >> val;
            insertatEnd(lista1, val);
            break;
        default:
            break;
        }
    } while (opc != 0);

    return 0;
}
