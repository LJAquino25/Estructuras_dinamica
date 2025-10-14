#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

void insert(Node *&head, int value)
{
    Node *newNode = new Node{value, head, nullptr};
    /*
    if (head != nullptr)
    {
        head->prev = newNode;
    }
    */
    if (head == nullptr)
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
        return;
    }
    Node *tail = head->prev;

    // Conexiones centrales
    newNode->next = head;
    newNode->prev = tail;

    // Conexiones a los extremos
    tail->next = newNode;
    head->prev = newNode;

    head = newNode;
}

void insertatEnd(Node *&head, int value)
{
    Node *newNode = new Node{value, nullptr, nullptr};
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
    newNode->prev = current;
}

void printlist(Node *head)
{
    if (head == nullptr)
    {
        return;
    }
    Node *i = head;
    do
    {
        cout << i->data << " -> ";
        i = i->next;
    } while (i != head);

    /* ya no :p
    Node *i = head;
    while (i->next != nullptr)
    {
        cout << i->data << " -> ";
        i = i->next;
    }
    while (i != nullptr)
    {
        cout << i->data << " -> ";
        i = i->prev;
    }
    */
}

void free(Node *&head)
{
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
    Node *lista1 = nullptr;
    int opc = 0;
    do
    {
        cout << endl;
        cout << "1. Insertar al inicio" << endl;
        cout << "2. Insertar al final" << endl;
        cout << "3. Imprimir lista" << endl;
        cout << "4. liberar memoria" << endl;
        cout << "0. Salir" << endl;
        cout << "Elige una opcion: ";
        cin >> opc;

        switch (opc)
        {
        case 1:
            int val;
            cout << "Valor a insertar al inicio: ";
            cin >> val;
            insert(lista1, val);
            break;

        case 2:
            int val2;
            cout << "Valor a insertar al final: ";
            cin >> val2;
            insertatEnd(lista1, val);
            break;

        case 3:
            cout << "Lista actual: " << endl;
            printlist(lista1);
            break;
        case 4:
            free(lista1);
            break;
        case 0:
            cout << "Saliendo" << endl;
            break;
        }
    } while (opc != 0);
    return 0;
}
