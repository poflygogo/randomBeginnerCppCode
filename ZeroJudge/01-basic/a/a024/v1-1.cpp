#include <iostream>
using namespace std;

// 遞迴 + 三元運算子
int Gcd(int a, int b) {
  return !b ? a : Gcd(b, a % b);
}

int main() {
  int a, b;
  cin >> a >> b;
  cout << Gcd(a, b) << endl;
}