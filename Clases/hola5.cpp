#include <iostream>
#include <cstdarg>
using namespace std;
int suma(int count, ...) {
  // con args capturo los argumentos 1, 2 y 3
  va_list args;  // lista de todos los argumentos... en si es un arreglo
  va_start(args, count);  // Se ubica en el primer elemento con va_start

  int total = 0;
  for (int i = 0; i < count; i++) {
    total += va_arg(args, int); //por cada iteracion pasa automaticamente 
  }

  va_end(args);
  return total;
}
int main() {
  cout << suma(3, 1, 2, 3)<<endl;  // el primer numero significa cuantos numero tiene y
                     // cuantos tiene que hacer el proceso
  return 0;
}