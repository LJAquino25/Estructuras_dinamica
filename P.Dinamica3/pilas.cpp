#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack<int>numbers;

    numbers.push(1);
    numbers.push(2);
    numbers.push(3);

    //elemento top, solo muestra
    cout<<numbers.top()<<endl;

    //desapilar
    numbers.pop();
    cout<<numbers.top()<<endl;
    return 0;
}