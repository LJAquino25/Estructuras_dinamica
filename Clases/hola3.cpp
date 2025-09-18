#include <iostream>
using namespace std;
// template function
template <typename T, typename U>  // se puede seguir agregando mas
auto max_number(T a, U b) -> decltype(a > b ? a : b)
{
  return a > b ? a : b;
}

// para que pueda usar cualquier tipo de dato sin limitarnos a una

int main() {
  auto result = max_number(2, 3.99);
  auto result2 = max_number(2.4, 2.5);

  cout << result << endl;
  cout << result2 << endl;

  return 0;
}