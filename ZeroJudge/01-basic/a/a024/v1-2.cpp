#include <iostream>
using namespace std;

int Gcd(int a, int b) {
  while (b) {
    int tmp = a;
    a = b;
    b = tmp % b;
  }
  return a;
}

int main() {
  int a, b;
  cin >> a >> b;
  cout << Gcd(a, b) << endl;
}