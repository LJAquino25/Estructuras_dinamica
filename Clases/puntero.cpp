#include <iostream>
using namespace std;

void referencia(int& a){ 
    a=30;
}


void point(int*& a){
    a = nullptr;
}

int main(){
    int a=10;
    int *ptr = &a;

    //referencia(a);
    point(ptr);
    

    cout <<"A= "<<a<<endl;

    return 0;
}