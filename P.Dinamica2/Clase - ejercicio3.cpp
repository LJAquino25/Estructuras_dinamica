#include <iostream>
using namespace std;

void mayor_menor(int *numero, int n, int *mayor, int *menor){
    *mayor = *numero;
    *menor = *numero;
    for (int i = 1; i < n; i++) {
        if (*(numero + i) > *mayor) {
            *mayor = *(numero + i);
        }
        if (*(numero + i) < *menor) {
            *menor = *(numero + i);
        }
    }
}


int main(){

    int n;
    cout <<"Elementos desea ingresar: ";
    cin>>n;

    int *numero = new int[n];
    for (int i = 0; i < n; i++) {
      cout << "Elemento " << i << ": ";
      cin >> numero[i];
    }

    int mayor, menor;
    mayor_menor(numero, n, &mayor, &menor);

    cout<<"El elemento mayor es: "<<mayor<<endl;
    cout<<"El elemento menor es: "<<menor<<endl;

    delete[] numero;
    return 0;
}