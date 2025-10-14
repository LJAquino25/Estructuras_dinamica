#include <iostream>
using namespace std;
int main() {
  // arreglo dinamico
  int n;
  do {
    cout << "De que tamaño: " << endl;
    cin >> n;
    // reservo memoria
    int *vector = new int[n];
    for (int i = 0; i < n; i++) {
      cout << "Ingrese el elemento #" << i << ": " << endl;
      cin >> vector[i];
    }

    cout << "Los elementos guardados: " << endl;
    for (int i = 0; i < n; i++) {
      cout << vector[i] << endl;
      ;
    }

    // libero memoria
    delete[] vector;
  } while (n != 0);

  return 0;
}