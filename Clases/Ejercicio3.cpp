#include <iostream>
using namespace std;

void encontrarMayoromenor(int *vector, int n, int *mayor, int *menor){
    *mayor = *vector;
    *menor = *vector; //comparacion para encontrar el mayor y el menor, recorriendo el vector
    for (int i = 1; i < n; i++) {
        if (*(vector + i) > *mayor) {
            *mayor = *(vector + i);
        }
        if (*(vector + i) < *menor) {
            *menor = *(vector + i);
        }
    }
}


int main(){

    int n;
    cout <<"Cuantos numeros desea ingresar: "<<endl; 
    cin>>n;

    int *vector = new int[n]; //llena el vector con los elementos
    for (int i = 0; i < n; i++) {
      cout << "Ingrese el elemento #" << i << ": " << endl;
      cin >> vector[i];
    }

    int mayor, menor;
    encontrarMayoromenor(vector, n, &mayor, &menor); //funcion de encontrar el mayor y menor

    cout<<"El mayor es: "<<mayor<<endl;
    cout<<"El menor es: "<<menor<<endl;

    delete[] vector;
    return 0;
}