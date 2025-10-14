#include <iostream>
using namespace std;
struct Contacto
{
  string nombre;
  string telefono;
  string email;
};

const int max_contactos = 100;
Contacto agenda[max_contactos];
int totalContactos = 0;

void mostrarAgenda(Contacto agenda[], int n)
{
  cout << "Agenda de contactos" << endl;
  if (n == 0)
  {
    cout << "La lista esta vacia" << endl;
    return;
  }

  for (int i = 0; i < n; i++)
  {
    cout << "Nombre: " << agenda[i].nombre << endl;
    cout << "Telefono: " << agenda[i].telefono << endl;
    cout << "E-mail: " << agenda[i].email << endl;
  }
}

int agregarContacto(Contacto agenda[], int n)
{
  if (n >= max_contactos)
  {
    cout << "La agenda esta llena" << endl;
    return n;
  }

  Contacto nuevo_contacto;

  cout << "Nombre: " << endl;
  getline(cin >> ws, nuevo_contacto.nombre);

  cout << "Telefono: " << endl;
  getline(cin, nuevo_contacto.telefono);

  cout << "E-mail: " << endl;
  getline(cin, nuevo_contacto.email);

  agenda[n] = nuevo_contacto;
  cout << "Contacto agregado exitosamente" << endl;
  return n + 1;
}

int buscarContacto(Contacto agenda[], int n, string nombre)
{
  for (int i = 0; i < n; i++)
  {
    if (agenda[i].nombre == nombre)
    {
      return i;
    }
    // El for termino y no encontro el elemento
    return -1;
  };
}

void editarContacto(Contacto agenda[], int n)
{
  string nombre;
  cout << "Nombre del contacto que desea editar: " << endl;
  getline(cin >> ws,
          nombre); // ws sirve para ignorar espacio que dejo el usuario

  int pos = buscarContacto(agenda, n, nombre);

  if (pos == -1)
  {
    cout << "No se ha encontrado el contacto" << endl;

    return;
  }

  cout << "Editando el contacto: " << agenda[pos].nombre << endl;
  cout << "Nuevo telefono: " << endl;
  getline(cin >> ws, agenda[pos].telefono);

  cout << "Nuevo e-mail: " << endl;
  getline(cin >> ws, agenda[pos].email);
}

int eliminarContacto(Contacto agenda[], int n)
{
  string nombre;
  cout << "Nombre del contacto que desea eliminar: " << endl;
  getline(cin >> ws, nombre);

  int pos = buscarContacto(agenda, n, nombre);

  if (pos == -1)
  {
    cout << "No se ha encontrado el contacto o ya fue eliminado" << endl;

    return n;
  }

  for (int i = pos; i < n - 1; i++)
  {
    agenda[i] = agenda[i - 1];
  }

  cout << "Contacto eliminado" << endl;
  return n - 1;
}

void mostrarEncontrado(Contacto agenda[], int n)
{
  string nombre;
  cout << "Nombre del contacto que desea mostrar: " << endl;
  getline(cin >> ws, nombre);
  int pos = buscarContacto(agenda, n, nombre);
  if (pos == -1)
  {
    cout << "No se encontro el contacto" << endl;
    return;
  }

  cout << "Contacto encontrado en la posicion: " << endl;
  cout << "Nombre: " << agenda[pos].nombre << endl;
  cout << "Telefono: " << agenda[pos].telefono << endl;
  cout << "Email: " << agenda[pos].email << endl;
}

void mostrarmenu()
{
  cout << "1.Mostrar agenda completa" << endl;
  cout << "2.Agregar contacto nuevo" << endl;
  cout << "3.Mostrar contactos" << endl;
  cout << "4.Editar contacto" << endl;
  cout << "5.Eliminar contacto" << endl;
  cout << "6. salir" << endl;
}

void ejecutarAgenda()
{
  int opcion;
  do
  {
    mostrarmenu();
    cin >> opcion;
    system("cls");
    switch (opcion)
    {
    case 1:
      mostrarAgenda(agenda, totalContactos);
      break;
    case 2:
      totalContactos = agregarContacto(agenda, totalContactos);
      break;
    case 3:
      mostrarEncontrado(agenda, totalContactos);
      break;
    case 4:
      editarContacto(agenda, totalContactos);
      break;
    case 5:
      totalContactos = eliminarContacto(agenda, totalContactos);
      break;
    case 6:
      cout << "saliendo..." << endl;
      break;
    }
  } while (opcion != 6);
}

int main()
{
  ejecutarAgenda();
  return 0;
}