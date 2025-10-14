#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<string> numbers;
    numbers.push("ana");
    numbers.push("manuel");
    numbers.push("carlos");

    // elemento front, solo muestra
    cout << numbers.front() << endl;

    // desancolar
    numbers.pop();
    cout << numbers.front() << endl;
    return 0;
}
