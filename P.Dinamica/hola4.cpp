#include <functional>
#include <iostream>
using namespace std;
int sum(int a, int b) {
  int result = a + b;
  return result;
}

int main() {
  int a = 5;
  function<int(int, int)> f = sum;  // F guarda toda la funcion y cuando se necesite invoca sum

  int result = f(2, 3);  // se invoca f para usar la estructura de la funcion guardada
  cout << result << endl;

  f = [](int a, int b) {return a * b;};  // define la estructura de una funcion y lo que retorna
  int result2 = f(2, 3);
  cout << result2 << endl;

  int n = 10;
  auto sumarN = [n](int a) { return a + n; };
  cout << sumarN(20);

  return 0;
}