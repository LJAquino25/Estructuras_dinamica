#include <iostream>
using namespace std;

int sum(int a, int b){
    int result = a+b;
    return result;
}

double sum(double a, double b){
    double result2 = a +b;
    return result2;
}


int main(){

    auto result = sum(2,5);
    auto result2 = sum(2.4,5.5);

    return 0;
}