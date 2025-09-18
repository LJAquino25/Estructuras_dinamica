#include <iostream>
using namespace std;

struct biblioteca //struct basica de un libro
{
    string titulo;
    string autor;
    int ano;
    string estado;
};

biblioteca libros[10]; //maximo de libros que se pueden ingresar
int totalibros = 0; // numero de libros al iniciar

void agregarlibro() //agregar libros 
{
    if (totalibros >= 10)
    {
        cout << "No se pueden agregar mas libros" << endl;
        return;
    }
    cout << "Titulo: ";
    getline(cin >> ws, libros[totalibros].titulo);
    cout << "Autor: ";
    getline(cin >> ws, libros[totalibros].autor);
    cout << "Año: ";
    cin >> libros[totalibros].ano;
    libros[totalibros].estado = "disponible";
    totalibros++;
}

void mostrarlibros() //muestra libros
{
    for (int i = 0; i < totalibros; i++)
    {
        cout << "----------------------------" <<endl;
        cout << "titulo: " << libros[i].titulo << endl;
        cout << "autor: " << libros[i].autor << endl;
        cout << "año: " << libros[i].ano << endl;
        cout << "Estado: " << libros[i].estado << endl;
        cout << "----------------------------" <<endl;
    }
}

void mostrardisponibles()//disponible o prestado el libro
{
    cout << "Libros disponibles:" << endl;
    for (int i = 0; i < totalibros; i++)
    {
        if (libros[i].estado == "disponible")
        {
            cout <<"-------------------------" <<endl;
            cout << "Titulo: " << libros[i].titulo << endl;
            cout << "Autor: " << libros[i].autor << endl;
            cout << "Año: " << libros[i].ano << endl;
            cout << "------------------------" << endl;
        }
    }
}

void prestarLibro()//prestar libro
{
    string tituloBuscar;
    cout << "Ingrese el titulo del libro a prestar: ";
    getline(cin >>ws, tituloBuscar);
    for (int i = 0; i < totalibros; i++)
    {
        if (libros[i].titulo == tituloBuscar && libros[i].estado == "disponible")
        {
            libros[i].estado = "prestado";
            cout << "Libro prestado correctamente." << endl;
            return;
        }
    }
    cout << "Libro no disponible o no encontrado." << endl;
}

void menu() //menu dinamico
{
    cout << "1.Agregar libro" << endl;
    cout << "2.Prestar libro" << endl;
    cout << "3.Mostrar libros disponibles" << endl;
    cout << "4.Mostrar todos los libros" << endl;
    cout << "5.Salir" << endl;
}

void ejecutarbiblio() //recopilacion de todo
{
    int opcion;
    do
    {
        menu();
        cin >> opcion;
        system("cls");
        switch (opcion)
        {
        case 1:
            agregarlibro();
            break;
        case 2:
            prestarLibro();
            break;
        case 3:
            mostrardisponibles();
            break;
        case 4:
            mostrarlibros();
            break;
        case 5:
            cout << "Saliendo..." << endl;
            break;
        }
    } while (opcion != 5);
}

int main()
{
    ejecutarbiblio();
    return 0;
}