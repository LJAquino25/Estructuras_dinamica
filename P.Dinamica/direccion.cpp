#include <iostream>
using namespace std;

int main() {
  int n = 10;
  int* p = &n;

  //numero
  cout << "Valor de n: " << n << endl;
  //Direccion
  cout << "Direccion de n -- &n: " << &n << endl;
  cout << "Direccion guardada en p(valor de p): " << p << endl;
  //numero
  cout << "Lo que guarda p el mismo que n: " << *p << endl;


  *p = 11; //al modificar el valor de *p tambien se modifica n
  //modificacion por referencia 
  return 0;
}