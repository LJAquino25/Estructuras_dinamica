#include <iostream>
using namespace std;
void swap(int *a, int* b){
    int temp = *a;//guardar lo que contiene a 
    *a= *b;
    *b = temp;
}

int main() {
  int x=5, y=6;
  cout <<"antes del swap: "<<endl;
  cout <<"x: " <<x<<endl;
  cout <<"y: " <<y<<endl;

  swap(&x, &y);
  cout <<"Despues del swap: "<<endl;
  cout <<"x: " <<x<<endl;
  cout <<"y: " <<y<<endl;
  return 0;
}