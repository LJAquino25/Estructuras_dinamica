#include <iostream>
using namespace std;

struct Node
{
    int ID;
    char tipo;
    int monto;
    int saldo;
    Node *next;
    Node *prev;
};

void eliminarMovimiento(Node *&head, int ID)
{
    Node *current = head;

    while (current != nullptr && current->ID != ID)
    {
        current = current->next;
    }

    if (current == nullptr)
        return;
    if (current->prev != nullptr)
    {
        current->prev->next = current->next;
    }

    else
    {
        head = current->next;
    }

    if (current->next != nullptr)
    {
        current->next->prev = current->prev;
    }

    delete current;
}

void recalcularSaldo(Node *head)
{
    float saldo = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->tipo == 'D')
        {
            saldo += temp->monto;
        }
        else if (temp->tipo == 'R')
        {
            saldo -= temp->monto;
        }
        temp->saldo = saldo;
        temp = temp->next;
    }
}

void agregarMovimiento(Node *&head, int ID, int monto, char tipo)
{
    Node *nuevo = new Node();
    nuevo->ID = ID;
    nuevo->monto = monto;
    nuevo->tipo = tipo;
    nuevo->saldo = 0;

    nuevo->next = head;
    nuevo->prev = nullptr;

    if (head != nullptr)
    {
        head->prev = nuevo;
    }
    head = nuevo;

    recalcularSaldo(head);
}

void Mostrar(Node *head)
{
    if (head == nullptr)
    {
        cout << "La lista está vacía" << endl;
        return;
    }
    Node *current = head;
    while (current != nullptr)
    {
        cout << "ID: " << current->ID << ", Tipo: " << current->tipo << ", Monto: " << current->monto << ", Saldo: " << current->saldo << endl;
        current = current->next;
    }
    cout << "Lista completa" << endl;
}

int main()
{
    Node *head = nullptr;
    int opcion;
    do
    {
        cout << "1. Depositar\n2. Retirar\n3. Mostrar movimientos\n4. Salir\n";
        cin >> opcion;
        if (opcion == 1 || opcion == 2)
        {
            int ID, monto;
            cout << "Ingrese ID: ";
            cin >> ID;
            cout << "Monto: ";
            cin >> monto;
            char tipo = (opcion == 1) ? 'D' : 'R';
            agregarMovimiento(head, ID, monto, tipo);
        }
        else if (opcion == 3)
        {
            Mostrar(head);
        }
    } while (opcion != 4);

    Node *current = head;
    while (current != nullptr)
    {
        Node *temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}